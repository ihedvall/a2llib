/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
#include <vector>
#include <optional>

#include "a2l/a2ltask.h"
#include "a2l/amlsection.h"

namespace a2l {

class CompareXcpTemplates : public A2lTask {
public:
  void AddTemplateFile(std::string name, const std::string& file_name);
  void Run() override;
  void Reset() override;

  [[nodiscard]] const std::vector<AmlSection>& TemplateList() const {
    return template_list_;
  }
  [[nodiscard]] const std::optional<size_t>& GetTemplateIndex() {
    return template_index_;
  }
  [[nodiscard]] const AmlSection* GetTemplate() const;
private:
  std::vector<AmlSection> template_list_;
  std::optional<size_t> template_index_;
};

}  // namespace a2l


