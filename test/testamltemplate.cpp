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
  OrderList ccp_list;
  ccp_list.emplace_back("CCP_206_FLAT", GetTemplateFile("CCP_206_FLAT"));
  ccp_list.emplace_back("CCP_206_ADDRESS_MAPPING", GetTemplateFile("CCP_206_ADDRESS_MAPPING"));
  ccp_list.emplace_back("CCP_206", GetTemplateFile("CCP_206"));

  ccp_list.emplace_back("CCP_205_FLAT", GetTemplateFile("CCP_205_FLAT"));
  ccp_list.emplace_back("CCP_205_ADDRESS_MAPPING", GetTemplateFile("CCP_205_ADDRESS_MAPPING"));
  ccp_list.emplace_back("CCP_205", GetTemplateFile("CCP_205"));

  ccp_list.emplace_back("CCP_204_FLAT", GetTemplateFile("CCP_204_FLAT"));
  ccp_list.emplace_back("CCP_204", GetTemplateFile("CCP_204"));

  ccp_list.emplace_back("CCP_202_FLAT", GetTemplateFile("CCP_202_FLAT"));
  ccp_list.emplace_back("CCP_202", GetTemplateFile("CCP_202"));

  OrderList xcp_list;
  xcp_list.emplace_back("XCP_103", GetTemplateFile("XCP_103"));
  xcp_list.emplace_back("XCP_102", GetTemplateFile("XCP_102"));
  xcp_list.emplace_back("XCP_101", GetTemplateFile("XCP_101"));
  xcp_list.emplace_back("XCP_100", GetTemplateFile("XCP_100"));

  for (const auto& aml_template : ccp_list) {
    EXPECT_TRUE(aml_template.aml_section.IsOk()) << aml_template.name;
  }
  for (const auto& aml_template : xcp_list) {
    EXPECT_TRUE(aml_template.aml_section.IsOk()) << aml_template.name;
  }

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
      AmlSection aml_section(aml_string);
      if (const bool a2l_ok = aml_section.IsOk(); !a2l_ok) {
        continue;;
      }

      const AmlDefinition* if_data = aml_section.GetDefinitionByTag("IF_DATA");
      const AmlDefinition* protocol_layer = aml_section.GetDefinitionByIdentity("Protocol_Layer");
      if (if_data == nullptr) {
        continue;
      }

      const AmlMember* ccp_struct = if_data->GetMemberByTag("ASAP1B_CCP");
      const AmlMember* xcp_struct = if_data->GetMemberByTag("XCP");
      if (ccp_struct == nullptr && xcp_struct == nullptr) {
        continue;
      }

      std::cout << "A2L: " << a2l_name << " : " << module_name << " : OK" << std::endl;
      const std::string ccp_string = ccp_struct != nullptr ?
          ccp_struct->AsString(0) : std::string();
      const std::string xcp_string = protocol_layer != nullptr ?
          protocol_layer->AsString(0) : std::string();

      for (const AmlTemplate& templ : ccp_list) {
        const AmlDefinition* if_data_templ = templ.aml_section.GetDefinitionByTag("IF_DATA");
        if (if_data_templ == nullptr ) {
          continue;
        }
        const AmlMember* templ_struct = if_data_templ->GetMemberByTag("ASAP1B_CCP");
        if (templ_struct == nullptr || ccp_string.empty()) {
          continue;
        }
        const std::string template_string = templ_struct->AsString(0);
        if (template_string == ccp_string) {
          std::cout << "  Template: " << templ.name << " : OK" << std::endl;
        }
      }

      for (const AmlTemplate& templ : xcp_list) {
        const AmlDefinition* templ_layer =
          templ.aml_section.GetDefinitionByIdentity("Protocol_Layer");
        if (templ_layer == nullptr || xcp_string.empty()) {
          continue;
        }
        const std::string template_string = templ_layer->AsString(0);
        if (template_string == xcp_string) {
          std::cout << "  Template: " << templ.name << " : OK" << std::endl;
        }
      }
    }
  }
/*
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
  */
}
}