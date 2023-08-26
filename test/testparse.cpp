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
using A2lList = std::map<std::string, std::string>;

namespace {
constexpr std::string_view kSourceDir = "k:/test/a2l";
constexpr std::string_view kDemoFile = "k:/test/a2l/asap2_demo_v171.a2l";

bool kDemoFileExist = false;
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
    kDemoFileExist = exists(kDemoFile);

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

TEST_F(TestParse, ParseDemoFile)
{
  if (!kDemoFileExist) {
    GTEST_SKIP();
  }

  a2l::A2lFile file;
  file.Filename(kDemoFile.data());
  const auto parse = file.ParseFile();
  EXPECT_TRUE(parse) << file.LastError() << " : " << kDemoFile;
  std::cout << file.Name() << (parse ? " : OK" : " : FAIL") << std::endl;

  EXPECT_EQ(file.A2lVersion().VersionNo, 1);
  EXPECT_EQ(file.A2lVersion().UpgradeNo, 71);

  const auto& project = file.Project();

  const auto& header = project.Header();
  EXPECT_FALSE(header.Comment.empty());
  EXPECT_FALSE(header.ProjectNo.empty());
  EXPECT_FALSE(header.VersionNo.empty());

  const auto& module_list = project.Modules();
  ASSERT_EQ(module_list.size(), 1);

  const auto& module = module_list.cbegin()->second;
  ASSERT_TRUE(module);

  EXPECT_STREQ(module->Name().c_str(), "Example");
  EXPECT_FALSE(module->A2ml().empty());

  const auto& axis_list = module->AxisPtss();
  EXPECT_GT(axis_list.size(), 1);
  std::cout << "\t\tAXIS PTS" << std::endl;
  for (const auto& [pts_name, pts] : axis_list) {
    std::cout << pts_name << std::endl;
  }
  std::cout << std::endl;

  const auto& blob_list = module->Blobs();
  EXPECT_GT(blob_list.size(), 0);
  std::cout << "\t\tBLOB" << std::endl;
  for (const auto& [blob_name, blob] : blob_list) {
    std::cout << blob_name << " " << blob->Address() << std::endl;
  }
  std::cout << std::endl;

  const auto& characteristic_list = module->Characteristics();
  EXPECT_GT(characteristic_list.size(), 0);
  std::cout << "\t\tCHARACTERISTIC" << std::endl;
  for (const auto& [char_name, characteristic] : characteristic_list) {
    std::cout << char_name << " " << characteristic->Description() << std::endl;
  }
  std::cout << std::endl;

}

TEST_F(TestParse, ParseAllFiles)
{
  if (kA2lList.empty() ) {
    GTEST_SKIP();
  }

  for (const auto &itr : kA2lList) {
    a2l::A2lFile file;
    file.Filename(itr.second);
    const auto parse = file.ParseFile();
    EXPECT_TRUE(parse) << file.LastError() << " : " << itr.first;
    std::cout << file.Name() << (parse ? " : OK" : " : FAIL") << std::endl;
  }
}


}  // namespace a2l::test
