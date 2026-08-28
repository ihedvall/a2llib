/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <deque>
#include <map>
#include <vector>
#include <string>
#include <functional>

#include "a2l/selectionobject.h"
#include "a2l/ccp/raster.h" // Reusing the CCP raster object

namespace a2l {

class SelectionList;

enum class LabelVersion : int {
  V10 = 0,
  V11 = 1,
  V12 = 2,
  V13 = 3,
};

using OnScanDb = std::function<void(SelectionList&, void*)>;
using SelectionObjectList = std::deque<SelectionObject>;
using SortedObjectList = std::multimap<std::string, const SelectionObject&>;

class SelectionList {
public:
  SelectionList() = default;
  virtual ~SelectionList() = default;

  void SetName(std::string name) {name_ = std::move(name);}
  [[nodiscard]] const std::string& GetName() const { return name_; };

  [[nodiscard]] LabelVersion GetLabelVersion() const { return label_version_; }
  void SetVersionAsString(const std::string& version);
  [[nodiscard]] std::string_view GetVersionAsString() const;

  void SetRasterSeparator(char separator) {raster_separator_ = separator;}
  [[nodiscard]] char GetRasterSeparator() const {return raster_separator_;}

  void SetFileName(std::wstring filename);
  [[nodiscard]] const std::wstring& GetFileName() const {return filename_;}

  void AddObject(SelectionObject object);
  [[nodiscard]] const SelectionObject* GetObject(size_t index) const;
  void RemoveObject(std::string name);

  [[nodiscard]] SelectionObjectList& GetObjectList() {
    return object_list_;
  }
  [[nodiscard]] const SelectionObjectList& GetObjectList() const {
    return object_list_;
  }

  [[nodiscard]] SortedObjectList GetSortedList(ObjectType type) const;

  bool SaveLabFile();
  bool ReadLabFile();

  void SetUtf8(bool utf8) {utf8_ = utf8;}
  [[nodiscard]] bool IsUtf8() const {return utf8_;}

  void ResetAttachments();
  [[nodiscard]] size_t GetSize() const {return object_list_.size();}

  void AddRaster(const std::string& raster);
  void AddRaster(const ccp::Raster& raster);
  [[nodiscard]] std::string GetActiveRaster(size_t index) const;
  [[nodiscard]] ccp::Raster* GetRaster(size_t index);
  [[nodiscard]] const std::vector<ccp::Raster>& GetRasters() const {
    return raster_list_;
  }
  void DeleteRaster(std::string raster);


protected:
  SelectionObjectList object_list_;
  void SetLabelVersion(LabelVersion version) {label_version_ = version;}
private:
  std::string name_;
  LabelVersion label_version_ = LabelVersion::V13;
  char raster_separator_ = '&';
  std::wstring filename_;
  bool utf8_ = false;
  std::vector<ccp::Raster> raster_list_;

  [[nodiscard]] bool ExistRaster(const ccp::Raster& raster) const;
  void WriteSettingSection(std::fstream& file) const;
  void WriteRamcellSection(std::fstream& file) const;
  void WriteLabelSection(std::fstream& file) const;
  void WriteFunctionSection(std::fstream& file) const;
  void WriteGroupSection(std::fstream& file) const;
  void WriteObject(std::fstream& file, const SelectionObject& object) const;
  void WriteRasterList(std::fstream& file, const RasterList& list) const;
};

}  // namespace a2l


