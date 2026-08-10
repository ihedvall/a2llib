/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "filterlist.h"
#include <boost/algorithm/string.hpp>

namespace {

bool WildcardMatch(const std::string &text, const std::string &wildcard,
                   bool ignore_case) {
  // Fast return in normal filter cases
  if (wildcard.empty() || wildcard == "*s") {
    return true;
  }

  const char *star = strchr(wildcard.c_str(), '*');
  const char *amper = strchr(wildcard.c_str(), '?');
  if (star == nullptr && amper == nullptr) {
    return ignore_case ? boost::algorithm::iequals(text, wildcard)
        : boost::algorithm::equals(text, wildcard);
  }
  const auto *text_ptr = text.c_str();
  const auto *wild_ptr = wildcard.c_str();
  while (*text_ptr != '\0' && *wild_ptr != '*') {
    if (ignore_case) {
      if (tolower(*wild_ptr) != tolower(*text_ptr) && *wild_ptr != '?') {
        return false;
      }
    } else {
      if (*wild_ptr != *text_ptr && *wild_ptr != '?') {
        return false;
      }
    }
    ++wild_ptr;
    ++text_ptr;
  }
  const char *text_temp = nullptr;
  const char *wild_temp = nullptr;

  while (*text_ptr != '\0') {
    if (*wild_ptr == '*') {
      if (!*++wild_ptr) {
        return true;
      }
      wild_temp = wild_ptr;
      text_temp = text_ptr + 1;
    } else if (ignore_case && (tolower(*wild_ptr) == tolower(*text_ptr) ||
               *wild_ptr == '?')) {
      ++wild_ptr;
      ++text_ptr;
    } else if (!ignore_case && (*wild_ptr == *text_ptr || *wild_ptr == '?')) {
      ++wild_ptr;
      ++text_ptr;
    } else {
      wild_ptr = wild_temp;
      text_ptr = text_temp++;
    }
  }

  while (*wild_ptr == '*') {
    ++wild_ptr;
  }
  return *wild_ptr == '\0';
}

}
namespace a2l {

FilterList::FilterList(const FilterList& filter) {
  SetNameFilter(filter.GetNameFilter());
  SetUnitFilter(filter.GetUnitFilter());
  SetIfDataFilter(filter.GetIfDataFilter());
}

FilterList& FilterList::operator=(const FilterList& filter) {
  if (&filter != this) {
    SetNameFilter(filter.GetNameFilter());
    SetUnitFilter(filter.GetUnitFilter());
    SetIfDataFilter(filter.GetIfDataFilter());
  }
  return *this;
}

FilterList::FilterList(std::string name_filter)
  : name_filter_(std::move(name_filter)) {

}
void FilterList::SetNameFilter(const std::string& name_filter) {
  if (name_filter != name_filter_) {
    modified_ = true;
    name_filter_ = name_filter;
  }
}
void FilterList::SetUnitFilter(const std::string& unit_filter) {
  if (unit_filter != unit_filter_) {
    modified_ = true;
    unit_filter_ = unit_filter;
  }
}
void FilterList::SetIfDataFilter(const std::string& if_data_filter) {
  if (if_data_filter != if_data_filter_) {
    modified_ = true;
    if_data_filter_ = if_data_filter;
  }
}

bool FilterList::IsEmpty() const {
  return name_filter_.empty() &&
         unit_filter_.empty() &&
         if_data_filter_.empty();
}

void FilterList::Reset() {
  modified_ = true;
  name_filter_.clear();
  unit_filter_.clear();
  if_data_filter_.clear();
}

bool FilterList::IsMatchingFilter(const A2lObject& item) const {
  if (!name_filter_.empty()) {
    const std::string& name = item.Name();
    if (const bool match = WildcardMatch(name); !match) {
      return false;
    }
  }
  if (!unit_filter_.empty()) {
    const std::string& unit = item.PhysUnit();
    if (unit != unit_filter_) {
      return false;
    }
  }
  if (!if_data_filter_.empty()) {
    if (!item.HaveIfData(if_data_filter_)) {
      return false;
    }
  }
  return true;
}
bool FilterList::WildcardMatch(const std::string& text) const {
  return ::WildcardMatch(text, name_filter_, true);
}
/*
bool FilterList::WildcardMatch(const std::string& text) const {
  size_t text_index = 0;
  size_t pattern_index = 0;
  size_t star_index = std::string::npos;
  size_t match_index = 0;

  while (text_index < text.size()) {
    if (pattern_index < name_filter_.size() &&
        (name_filter_[pattern_index] == '?' ||
         name_filter_[pattern_index] == text[text_index])) {
      ++text_index;
      ++pattern_index;
         } else if (pattern_index < name_filter_.size() && name_filter_[pattern_index] == '*') {
           star_index = pattern_index++;
           match_index = text_index;
         } else if (star_index != std::string_view::npos) {
           pattern_index = star_index + 1;
           text_index = ++match_index;
         } else {
           return false;
         }
  }

  while (pattern_index < name_filter_.size() && name_filter_[pattern_index] == '*') {
    ++pattern_index;
  }
  return pattern_index == name_filter_.size();
}
*/


} // a2l