/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <deque>
#include <string>

#include "a2l/selectionobject.h"

namespace a2l {

using SelectionObjectList = std::deque<SelectionObject>;

class SelectionList {
public:
  [[nodiscard]] std::string Name() const;
  
  void SetVersion(std::string version) {version_ = std::move(version);}
  [[nodiscard]] const std::string& GetVersion() const {return version_;}

  void SetRasterSeparator(char separator) {raster_separator_ = separator;}
  [[nodiscard]] char GetRasterSeparator() const {return raster_separator_;}

  void SetFileName(std::wstring filename) {filename_ = std::move(filename);}
  [[nodiscard]] const std::wstring& GetFileName() const {return filename_;}
private:
  std::string version_ = "V1.3";
  char raster_separator_ = '&';
  std::wstring filename_;


  SelectionObjectList object_list_;
};

}  // namespace a2l


