/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/compareccptemplates.h"

#include <sstream>

namespace a2l {

void CompareCcpTemplates::AddTemplateFile(std::string name, const std::string& file_name) {
  try {
    AmlSection section;
    section.Name(std::move(name));
    section.ParseFile(file_name);
    template_list_.emplace_back(std::move(section));
  } catch (std::exception& err) {
    std::ostringstream oss;
    oss << "Failed to add template file: " << err.what() <<", File: " << file_name;
    SetErrorMessage(oss.str());
  }
}

void CompareCcpTemplates::Run() {
  Reset();
  try {
    const std::string& aml_string = GetSourceText();
    if (aml_string.empty()) {
      throw std::runtime_error("The AML string is empty");
    }

    if (template_list_.empty()) {
      throw std::runtime_error("There are templates defined");
    }

    AmlSection aml(GetSourceText() );
    if (!aml.IsOk()) {
      throw std::runtime_error("Failed to parse AML");
    }
    const AmlDefinition* if_data = aml.GetDefinitionByTag("IF_DATA");
    if (if_data == nullptr) {
      throw std::runtime_error("IF_DATA not found");
    }
    const AmlMember* asap1b_ccp = if_data->GetMemberByTag("ASAP1B_CCP");
    if (asap1b_ccp == nullptr) {
      throw std::runtime_error("ASAP1B_CCP not found");
    }

    for ( size_t index = 0; index < template_list_.size(); ++index) {
      const AmlSection& templ = template_list_[index];
      const AmlDefinition* templ_if_data = templ.GetDefinitionByTag("IF_DATA");
      if (templ_if_data == nullptr) {
        throw std::runtime_error("IF_DATA not found");
      }
      const AmlMember* templ_asap1b_ccp = templ_if_data->GetMemberByTag("ASAP1B_CCP");
      if (templ_asap1b_ccp == nullptr) {
        throw std::runtime_error("ASAP1B_CCP not found");
      }

      const auto& member_list = templ_asap1b_ccp->MemberList();
      size_t count = 0;
      for (const auto& member : member_list) {
        const std::string& def = member.Tag();
        if (def.empty()) {
          continue;
        }
        const AmlMember* found = asap1b_ccp->GetFlatMemberByTag(def);
        if (found == nullptr) {
          count = 0;
          break;
        }
        if (found->TypeName() != member.TypeName() ) {
          count = 0;
          break;
        }
        if (found->DefinitionType() != member.DefinitionType() ) {
          count = 0;
          break;
        }
        ++count;
      }
      if (count == 0) {
        continue;
      }
      template_index_ = index;
      SetResult(true);
      return;
    }
    template_index_.reset();
    SetResult(false);

  } catch (std::exception& err) {
    std::ostringstream oss;
    oss << "Failed to compare templates. Error: " << err.what();
    SetErrorMessage(oss.str());
  }

}

void CompareCcpTemplates::Reset() {
  A2lTask::Reset();
  template_index_.reset();
}

const AmlSection* CompareCcpTemplates::GetTemplate() const {
  if (template_index_.has_value()) {
    return &template_list_[template_index_.value()];
  }
  return nullptr;
}

} // a2l