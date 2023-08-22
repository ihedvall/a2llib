/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "testparse.h"

#include <chrono>
#include <filesystem>
#include <map>
#include <string>

#include "a2l/a2lfile.h"

using namespace std::filesystem;
using namespace std::chrono_literals;

namespace {
constexpr std::string_view kSourceDir = "k:/test/a2l";
using A2lList = std::map<std::string, std::string>;
A2lList kA2lList;

std::string GetA2lFile(const std::string &name) {
  const auto itr = kA2lList.find(name);
  return itr == kA2lList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {

void TestParse::SetUpTestSuite() {
  kA2lList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() && (p.extension().string() == ".a2l" || p.extension().string() == ".A2L") ) {
        kA2lList.emplace(p.stem().string(), p.string());

      }
    }
  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the A2l test files. Error: "
                << error.what();
  }
}

void TestParse::TearDownTestSuite() {
}

TEST_F(TestParse, CheckParser)  // NOLINT
{
  if (kA2lList.empty() ) {
    GTEST_SKIP();
  }

  for (const auto &itr : kA2lList) {
    a2l::A2lFile file;
    file.Filename(itr.second);
    const auto parse = file.ParseFile();
    EXPECT_TRUE(parse) << file.LastError() << " : " << itr.first;
   //  std::cout << file.Content() << std::endl;
    std::cout << file.Name() << (parse ? " : OK" : " : FAIL") << std::endl;
  }
}


}  // namespace a2l::test
