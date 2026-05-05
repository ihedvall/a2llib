/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "testamltemplate.h"

#include <chrono>
#include <filesystem>
#include <vector>
#include <map>
#include <ranges>
#include <string>


#include "a2l/a2lfile.h"
#include "a2l/amlsection.h"
#include "a2l/comparexcptemplates.h"
#include "a2l/compareccptemplates.h"

using namespace std::filesystem;
using namespace std::chrono_literals;

struct AmlTemplate {
  std::string name;
  std::string path;
  a2l::AmlSection aml_section;
  AmlTemplate(std::string aml_name, std::string aml_path)
  : name(std::move(aml_name)), path(std::move(aml_path)) {
    aml_section.ParseFile(path);
  }
};

using TemplateList = std::map<std::string, std::string>;
using OrderList = std::vector<AmlTemplate>;
namespace {

constexpr std::string_view kTemplateDir = "k:/test/aml/template";
constexpr std::string_view kA2lSourceDir = "k:/test/a2l";
TemplateList kTemplateList;
TemplateList kA2lList;

std::string GetTemplateFile(const std::string &name) {
  const auto itr = kTemplateList.find(name);
  return itr == kTemplateList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {
void TestAmlTemplate::SetUpTestSuite() {
  kTemplateList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kTemplateDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() &&
        (p.extension().string() == ".aml" || p.extension().string() == ".AML") ) {
        kTemplateList.emplace(p.stem().string(), p.string());
      }
    }

    // Create list of A2L files.
    kA2lList.clear();
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

    std::cout << "Template: " << kTemplateList.size() << " files found." << std::endl;
    std::cout << "A2L: " << kA2lList.size() << " files found." << std::endl;

  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the Template/A2L test files. Error: "
                << error.what();
  }
}

void TestAmlTemplate::TearDownTestSuite() {
}

TEST_F(TestAmlTemplate, ListDefinition) {
  for (const auto& [name, template_file] : kTemplateList ) {
    AmlSection aml_section;
    aml_section.ParseFile(template_file);
    EXPECT_TRUE(aml_section.IsOk());
    std::cout << "AML: " << name <<
      (aml_section.IsOk() ? " : OK" : " :FAIL") << std::endl;
    const AmlDefinition* definition = aml_section.GetDefinitionByTag("IF_DATA");
    ASSERT_TRUE(definition != nullptr);
    EXPECT_GT(definition->MemberList().size(), 0);
    for (const AmlMember& member : definition->MemberList()) {
      std::cout << "  Member: " << member.Tag()
        << ", Members: " << member.AsString(0) << std::endl;
    }
    std::cout << std::endl;
  }
}

TEST_F(TestAmlTemplate, TestCcpTemplate) {
  if (kA2lList.empty() ) {
    GTEST_SKIP_("No A2L files available for testing");
  }

  CompareCcpTemplates compare;
  compare.AddTemplateFile("CCP_206_ADDRESS_MAPPING", GetTemplateFile("CCP_206_ADDRESS_MAPPING"));
  compare.AddTemplateFile("CCP_206", GetTemplateFile("CCP_206"));
  compare.AddTemplateFile("CCP_205_ADDRESS_MAPPING", GetTemplateFile("CCP_205_ADDRESS_MAPPING"));
  compare.AddTemplateFile("CCP_205", GetTemplateFile("CCP_205"));
  compare.AddTemplateFile("CCP_204", GetTemplateFile("CCP_204"));
  compare.AddTemplateFile("CCP_202", GetTemplateFile("CCP_202"));

  for (const auto& [a2l_name, a2l_path] : kA2lList) {
    A2lFile a2l_file;
    a2l_file.Filename(a2l_path);
    if (const bool a2l_ok = a2l_file.ParseFile();!a2l_ok) {
      // Some A2L files are actually include files.
      continue;
    }

    const A2lProject& project = a2l_file.Project();
    const auto& module_list = project.Modules();
    for (const auto& [module_name, module] :
          module_list) {
      const std::string& aml_string = module->A2ml();
      if (aml_string.empty()) {
        continue;
      }
      compare.SetSourceText(aml_string);
      compare.Run();
      if (!compare.GetResult()) {
        continue;
      }
      const auto& template_index = compare.GetTemplateIndex();
      if (!template_index.has_value()) {
        continue;
      }
      const AmlSection* selected = compare.GetTemplate();
      ASSERT_TRUE(selected != nullptr);

      std::cout << "A2L: " << a2l_name << " : " << module_name << " : OK" << std::endl;
      std::cout << "  Template: " << selected->Name() << " : OK" << std::endl;
     }
  }
}

TEST_F(TestAmlTemplate, TestXcpTemplate) {
  if (kA2lList.empty() ) {
    GTEST_SKIP_("No A2L files available for testing");
  }
  CompareXcpTemplates compare;
  compare.AddTemplateFile("XCP_103", GetTemplateFile("XCP_103"));
  compare.AddTemplateFile("XCP_102", GetTemplateFile("XCP_102"));
  compare.AddTemplateFile("XCP_101", GetTemplateFile("XCP_101"));
  compare.AddTemplateFile("XCP_100", GetTemplateFile("XCP_100"));


  for (const auto& [a2l_name, a2l_path] : kA2lList) {
    A2lFile a2l_file;
    a2l_file.Filename(a2l_path);
    if (const bool a2l_ok = a2l_file.ParseFile();!a2l_ok) {
      // Some A2L files are actually include files.
      continue;
    }

    const A2lProject& project = a2l_file.Project();
    const auto& module_list = project.Modules();
    for (const auto& [module_name, module] :
          module_list) {
      const std::string& aml_string = module->A2ml();
      if (aml_string.empty()) {
        continue;
      }
      compare.SetSourceText(aml_string);
      compare.Run();
      if (!compare.GetResult()) {
        continue;
      }
      const auto& template_index = compare.GetTemplateIndex();
      if (!template_index.has_value()) {
        continue;
      }
      const auto& selected = compare.GetTemplate();
      ASSERT_TRUE(selected != nullptr);

      std::cout << "A2L: " << a2l_name << " : " << module_name << " : OK" << std::endl;
      std::cout << "  Template: " << selected->Name() << " : OK" << std::endl;
    }
  }
}

}