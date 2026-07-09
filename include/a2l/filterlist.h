/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <string>

#include "a2l/a2lobject.h"

namespace a2l {

class FilterList {
public:
  FilterList() = default;
  FilterList(const FilterList& filter);
  FilterList& operator = (const FilterList& filter);
  explicit FilterList(std::string name_filter);

  void SetNameFilter(const std::string& name_filter);
  [[nodiscard]] const std::string& GetNameFilter() const {
    return name_filter_;
  }

  void SetUnitFilter(const std::string& unit_filter);
  [[nodiscard]] const std::string& GetUnitFilter() const {
    return unit_filter_;
  }

  void SetIfDataFilter(const std::string& if_data_filter);
  ;
  [[nodiscard]] const std::string& GetIfDataFilter() const {
    return if_data_filter_;
  }

  [[nodiscard]] bool IsEmpty() const;
  [[nodiscard]] bool IsModified() const { return modified_; }
  void Reset();
  void ResetModified() const { modified_ = false; }
  [[nodiscard]] bool IsMatchingFilter( const A2lObject& item ) const;

private:
  mutable bool modified_ = true;
  std::string name_filter_;
  std::string unit_filter_;
  std::string if_data_filter_;

  [[nodiscard]] bool WildcardMatch(const std::string& text) const;
};



}  // namespace a2l

