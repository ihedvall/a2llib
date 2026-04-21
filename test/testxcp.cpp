/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "testxcp.h"

#include <array>
#include <filesystem>
#include <map>
#include <string>
#include <string_view>
#include <sstream>

#include "a2l/a2lfile.h"
#include "a2l/xcp/datablock.h"

using namespace a2l::xcp;
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
void TestXcp::SetUpTestSuite() {
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

void TestXcp::TearDownTestSuite() {
}

TEST_F(TestXcp, TestDataBlock) {
  std::ostringstream if_data;
  if_data << "/begin IF_DATA XCPplus 11" << std::endl;
  if_data << "  /begin DAQ" << std::endl;
  if_data << "STATIC 0x3 0x2 0x0 OPTIMISATION_TYPE_DEFAULT ADDRESS_EXTENSION_DAQ";
  if_data << " IDENTIFICATION_FIELD_TYPE_ABSOLUTE GRANULARITY_ODT_ENTRY_SIZE_DAQ_BYTE";
  if_data << " 0x4 OVERLOAD_INDICATION_EVENT";
  if_data << "  /end DAQ" << std::endl;

  if_data << "/end IF_DATA";

  DataBlock block(if_data.str());
  EXPECT_TRUE(block.IsOk());
  if (!block.IsOk()) {
    std::cout << block.LastError() << std::endl;
  }

}

TEST_F(TestXcp, TestDemoFile) {
  constexpr std::array<std::string_view, 2> demo_files = {
    "ASAP2_Demo_V161",
    "ASAP2_Demo_V171",
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
      for (const auto& [protocol, if_data] : module->IfDatas()) {
        if (protocol == "XCP" || protocol == "XCPplus") {
          DataBlock block(if_data);
          const bool xcp_parse = block.IsOk();
          if (!xcp_parse) {
            std::cout << a2l_file << ": Error: " << block.LastError() << std::endl;
            std::cout << if_data << std::endl;
          }
          std::cout << "XCP: " << a2l_file << "/" << module_name
            << (xcp_parse ? " OK" : " FAIL") << std::endl;

        }
      }
    }
  }
}

TEST_F(TestXcp, TestModules) {
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
        if (protocol == "XCP" || protocol == "XCPplus") {
          DataBlock block(if_data);
          const bool xcp_parse = block.IsOk();
          if (!xcp_parse) {
            std::cout << name << ": Error: " << block.LastError() << std::endl;
            std::cout << if_data << std::endl;
          }
          std::cout << "XCP: " << name << "/" << module_name
            << (xcp_parse ? " OK" : " FAIL") << std::endl;
          EXPECT_TRUE(xcp_parse) << name << "/" << module_name << " XCP parsing failed";
        }
      }
    }
  }
}

}