/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/comparexcptemplates.h"

#include <sstream>

namespace a2l {

void CompareXcpTemplates::AddTemplateFile(std::string name, const std::string& file_name) {
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

void CompareXcpTemplates::Run() {
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
    const AmlDefinition* protocol_layer = aml.GetDefinitionByIdentity("Protocol_Layer");
    if (protocol_layer == nullptr) {
      throw std::runtime_error("Protocol_Layer not found");
    }
    const std::string xcp_string = protocol_layer->AsString(0);

    for ( size_t index = 0; index < template_list_.size(); ++index) {
      const AmlSection& templ = template_list_[index];
      const AmlDefinition* templ_layer =
        templ.GetDefinitionByIdentity("Protocol_Layer");
      if (templ_layer == nullptr) {
        continue;
      }
      const std::string template_string = templ_layer->AsString(0);
      if (template_string == xcp_string) {
        template_index_ = index;
        SetResult(true);
        return;
      }
    }
    template_index_.reset();
    SetResult(false);

  } catch (std::exception& err) {
    std::ostringstream oss;
    oss << "Failed to compare templates. Error: " << err.what();
    SetErrorMessage(oss.str());
  }

}

void CompareXcpTemplates::Reset() {
  A2lTask::Reset();
  template_index_.reset();
}

const AmlSection* CompareXcpTemplates::GetTemplate() const {
  if (template_index_.has_value()) {
    return &template_list_[template_index_.value()];
  }
  return nullptr;
}

} // a2l