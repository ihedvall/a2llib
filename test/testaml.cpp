/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "testaml.h"

#include <chrono>
#include <filesystem>
#include <map>
#include <ranges>
#include <string>
#include <fstream>
#include <array>

#include "a2l/a2lfile.h"
#include "a2l/amlsection.h"


using namespace std::filesystem;
using namespace std::chrono_literals;

using AmlList = std::map<std::string, std::string>;
namespace {

constexpr std::string_view kSourceDir = "k:/test/aml";
constexpr std::string_view kA2lSourceDir = "k:/test/a2l";
AmlList kAmlList;

std::string GetAmlFile(const std::string &name) {
  const auto itr = kAmlList.find(name);
  return itr == kAmlList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {
void TestAml::SetUpTestSuite() {
  kAmlList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() &&
        (p.extension().string() == ".aml" || p.extension().string() == ".AML") ) {
        kAmlList.emplace(p.stem().string(), p.string());
        }
    }

    // Create AML files from the A2L files but check if already exists.
    AmlList a2l_list;
    for (const auto &entry : recursive_directory_iterator(kA2lSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() &&
        (p.extension().string() == ".a2l" || p.extension().string() == ".A2L") ) {
        a2l_list.emplace(p.stem().string(), p.string());
      }
    }
    for (const auto & [name, a2l_file] : a2l_list ) {
      if (name == "VRC4003B") {
        continue;
      }
      const std::string existing_aml = GetAmlFile(name);
      if (!existing_aml.empty() ) {
        continue;
      }
      A2lFile a2l;
      a2l.Filename(a2l_file);
      const bool parse = a2l.ParseFile();
      if (!parse) {
        std::cout << "A2L: " << a2l_file << " : FAIL" << std::endl;
        continue;
      }
      const A2lProject& project = a2l.Project();
      const auto& module_list = project.Modules();
      if (module_list.empty()) {
        continue;
      }
      const auto& module = module_list.cbegin()->second;
      if (!module) {
        continue;
      }
      const std::string& aml_string = module->A2ml();
      if (aml_string.empty()) {
        continue;
      }
      path aml_file = kSourceDir;
      aml_file.append(name + ".aml");
      if (exists(aml_file)) {
        continue;
      }
      std::ofstream aml_stream(aml_file);
      aml_stream << aml_string;

      kAmlList.emplace(name, aml_file.string());
      std::cout << "AML: " << aml_file << " : Created" << std::endl;
    }

    std::cout << "AML: " << kAmlList.size() << " files found." << std::endl;


  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the AML test files. Error: "
                << error.what();
  }
}

void TestAml::TearDownTestSuite() {
}

TEST_F(TestAml, TestDemoFile) {
  constexpr std::array<std::string_view, 2> demo_files = {
    "ASAP2_Demo_V161",
    "ASAP2_Demo_V171",
  };
  for (const auto& name : demo_files ) {
    const std::string aml_file = GetAmlFile(std::string(name));
    if (aml_file.empty() ) {
      continue;
    }
    AmlSection aml_section;
    aml_section.ParseFile(aml_file);
    ASSERT_TRUE(aml_section.IsOk()) << "AML: " << name << ", Error: "
      << aml_section.LastError();

    std::cout << "AML: " << name << " : OK" << std::endl;
    for (const auto& definition : aml_section.DefinitionList()) {
      std::cout << definition.AsString(0) << std::endl;
    }
    std::cout << std::endl;

  }
}

TEST_F(TestAml, TestParse) {
  if (kAmlList.empty() ) {
    GTEST_SKIP_("No AML files found.");
  }
  for (const auto& [name, test_file] : kAmlList ) {
    AmlSection aml_section;
    aml_section.ParseFile(test_file);
    EXPECT_TRUE(aml_section.IsOk());
    std::cout << "AML: " << name <<
      (aml_section.IsOk() ? " : OK" : " :FAIL") << std::endl;
  }
}

TEST_F(TestAml, TestFailParse) {
  constexpr std::array<std::string_view, 5> failed_files = {
    "etk",
    "03G906021KE_9970_501409_P447_HAXN_EDC16U34_3.41",
    "310B621d",
    "4520D30S",
  };
  for (const auto& name : failed_files ) {
    AmlSection aml_section;
    const std::string aml_file = GetAmlFile(std::string(name));
    if (aml_file.empty() ) {
      continue;
    }
    aml_section.ParseFile(aml_file);
    ASSERT_TRUE(aml_section.IsOk()) << "AML: " << name << " : FAIL, Error: "
      << aml_section.LastError();
    std::cout << "AML: " << name << " : OK" << std::endl;

  }
}

}