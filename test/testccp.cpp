/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "testccp.h"

#include <array>
#include <filesystem>
#include <map>
#include <sstream>
#include <string>
#include <string_view>

#include "a2l/a2lfile.h"
#include "a2l/ccp/ccpdatablock.h"

using namespace a2l;
using namespace a2l::ccp;
using A2lList = std::map<std::string, std::string>;
using namespace std::filesystem;

namespace {
constexpr std::string_view kA2lSourceDir = "k:/test/a2l";
A2lList kA2lList;

std::string GetA2lFile(const std::string &name) {
  const auto itr = kA2lList.find(name);
  return itr == kA2lList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {
void TestCcp::SetUpTestSuite() {
  kA2lList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kA2lSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() &&
        (p.extension().string() == ".a2l" || p.extension().string() == ".A2L") ) {
        kA2lList.emplace(p.stem().string(), p.string());
        }
    }
    std::cout << "A2L: " << kA2lList.size() << " files found." << std::endl;
  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the AML test files. Error: "
                << error.what();
  }
}

void TestCcp::TearDownTestSuite() {
}

TEST_F(TestCcp, TestDemoFile) {
  constexpr std::array<std::string_view, 1> demo_files = {
    "IFData_test",
  };
  for (const auto& name : demo_files ) {
    const std::string a2l_file = GetA2lFile(std::string(name));
    if (a2l_file.empty() ) {
      continue;
    }
    A2lFile file;
    file.Filename(a2l_file);
    const bool parse = file.ParseFile();
    if (!parse) {
      continue;
    }
    const A2lProject& project = file.Project();
    for (const auto& [module_name, module] :
      project.Modules()) {
      if (!module) {
        continue;
      }
      size_t test_count = 0;
      for (const auto& [protocol, if_data] : module->IfDatas()) {
        if (protocol != "ASAP1B_CCP") {
          continue;
        }

        CcpDataBlock block(if_data);
        const bool ccp_parse = block.IsOk();
        ASSERT_TRUE(ccp_parse) << a2l_file << ": Error: " << block.LastError() << std::endl;
        std::cout << "CCP: " << a2l_file << "/" << module_name
          << (ccp_parse ? " OK" : " FAIL") << std::endl;


        ++test_count;
      }

      EXPECT_EQ(test_count, 1);
    }
  }
}

TEST_F(TestCcp, TestModules) {
  for (const auto& [name, path] : kA2lList ) {

    A2lFile file;
    file.Filename(path);
    const bool parse = file.ParseFile();
    if (!parse) {
      continue;
    }
    const A2lProject& project = file.Project();
    for (const auto& [module_name, module] :
      project.Modules()) {
      if (!module) {
        continue;
      }
      for (const auto& [protocol, if_data] : module->IfDatas()) {
        if (protocol == "ASAP1B_CCP" ) {
          CcpDataBlock block(if_data);
          const bool ccp_parse = block.IsOk();
          if (!ccp_parse) {
            std::cout << name << ": Error: " << block.LastError() << std::endl;
            std::cout << if_data << std::endl;
          }
          std::cout << "CCP: " << name << "/" << module_name
            << (ccp_parse ? " OK" : " FAIL") << std::endl;
          EXPECT_TRUE(ccp_parse) << name << "/" << module_name << " CCP parsing failed";
        }
      }
    }
  }
}

}
