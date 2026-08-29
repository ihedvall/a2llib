/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/selectionlist.h"

#include <filesystem>
#include <fstream>
#include <ranges>

#include <boost/algorithm/string.hpp>

#include "a2l/a2lfile.h"
#include "a2l/a2llogstream.h"
#include "labelscanner.h"
#include "labelparser.hpp"

using namespace std::filesystem;
using namespace boost::algorithm;
using namespace a2l::ccp;
namespace {

constexpr std::array<std::string_view,4> kVersions = {
  "", "V1.1", "V1.2", "V1.3"
};

}
namespace a2l {

void SelectionList::SetVersionAsString(const std::string& version) {
  for (size_t index = 0; index < kVersions.size(); ++index) {
    const std::string_view& version_string = kVersions[index];
    if (version == version_string) {
      label_version_ = static_cast<LabelVersion>(index);
      return;
    }
  }
  label_version_ = LabelVersion::V10;
}

std::string_view SelectionList::GetVersionAsString() const {
  const auto index = static_cast<size_t>(label_version_);
  return index < kVersions.size() ? kVersions[index] : kVersions[0];
}

void SelectionList::SetFileName(std::wstring filename) {
  filename_ = std::move(filename);
  std::string fname; // Hoping that the fullname is OK.
  try {
    const path fullname(filename_);
    fname = fullname.string();
    const path stem = fullname.stem();
    if (name_.empty()) {
      name_ = stem.string();
    }
  } catch (std::exception& err) {
    A2L_ERROR() << "Filename path error. File Name: " << fname
                << ", Error: " << err.what();
  }
}

void SelectionList::AddObject(SelectionObject object) {
  // Check if the item already exist
  for (const SelectionObject& existing_object : object_list_) {
    if (iequals(existing_object.GetName(),object.GetName())
        && existing_object.GetObjectType() == object.GetObjectType()
        && iequals(existing_object.GetDevice(),object.GetDevice())) {
      A2L_ERROR() << "Selection object already exist. Name: "
                  << object.GetName()
                  << "/" << existing_object.GetName();
      return;
    }
  }

  for (const std::string& raster : object.GetRasterList()) {
    if (!raster.empty()) {
      AddRaster(raster);
    }
  }
  object_list_.emplace_back(std::move(object));
  std::ranges::sort(object_list_, [](const SelectionObject& a,
    const SelectionObject& b) -> bool {
    return ilexicographical_compare(a.GetName(), b.GetName());
  });
}

const SelectionObject* SelectionList::GetObject(size_t index) const {
  return index < object_list_.size() ? &object_list_[index] : nullptr;
}

void SelectionList::RemoveObject(std::string name) {
  std::erase_if(object_list_, [name](const auto& object) -> bool {
    return iequals(object.GetName(), name);
  });
}

SortedObjectList SelectionList::GetSortedList(ObjectType type) const {
  SortedObjectList list;
  for (const SelectionObject& object: object_list_) {
    if (object.GetObjectType() == type) {
      list.emplace(object.GetName(), object);
    }
  }
  return list;
}


bool SelectionList::SaveLabFile() {
  std::string fname; // Used by error message
  try {
    if (filename_.empty()) {
      // Not set the file name. This is an error
      A2L_ERROR() << "The file name is missing (empty).";
      return false;
    }
    const path fullname(filename_);
    fname = fullname.string();
    const path parent_path = fullname.parent_path();
    if (!parent_path.empty()) {
      create_directories(parent_path);
    }
    SetLabelVersion(LabelVersion::V13);
    std::fstream file(fullname, std::ios_base::out | std::ios_base::trunc);
    file << "\xEF\xBB\xBF"; // Writing UTF-8 BOM code
    WriteSettingSection(file);
    WriteRamcellSection(file);
    WriteLabelSection(file);
    WriteFunctionSection(file);
    WriteGroupSection(file);
    file.close();
  } catch (std::exception& err) {
    A2L_ERROR() << "Failed to save the label file. File: " << fname
                << " ,Error" << err.what();
    return false;
  }
  return true;
}

bool SelectionList::ReadLabFile() {
  std::string fname;
  try {
    path fullname(filename_);
    fname = fullname.string();
    if (!exists(fullname)) {
      A2L_ERROR() << "Failed to read the label file. File: " << fname
                  << " ,Error: File does not exist";
      return false;
    }
    std::ifstream file(fullname, std::ios::in);
    if (!file.is_open()) {
      A2L_ERROR() << "Failed to open the label file. File: " << fname;
      return false;
    }
    LabelScanner scanner(file, *this);
    LabelParser parser(scanner,*this);

    const int result = parser.parse();
    file.close();
    if (result != 0) {
      A2L_ERROR() << "Parser error. File: " << fname
                  << ", Error: " << scanner.LastError();
      return false;
    }
  } catch (std::exception& err) {
    A2L_ERROR() << "Failed to read the label file. File: " << fname
                << " ,Error" << err.what();
    return false;
  }
  return true;
}

void SelectionList::ResetAttachments() {
  for (SelectionObject& object : object_list_) {
    object.SetUserObject(nullptr);
  }
}

void SelectionList::AddRaster(const std::string& raster) {
  if (raster.empty()) {
    A2L_ERROR() << "Raster display name is empty";
    return;
  }
  Raster raster_obj;
  raster_obj.SetActive(true);
  raster_obj.SetName(raster);
  raster_obj.SetShortName(raster);
  AddRaster(raster_obj);
}

void SelectionList::AddRaster(const Raster& raster) {
  Raster raster_obj = raster;
  if (raster_obj.GetName().empty() && raster_obj.GetShortName().empty()) {
    A2L_ERROR() << "Raster display name and name are empty";
    return;
  }
  if (raster_obj.GetName().empty()) {
    raster_obj.SetName(raster_obj.GetShortName());
  } else if (raster_obj.GetShortName().empty()) {
    raster_obj.SetShortName(raster_obj.GetName());
  }

  if (const bool exist = ExistRaster(raster_obj); exist) {
    // Not an error
    return;
  }

  raster_list_.emplace_back(std::move(raster_obj));
  std::ranges::sort(raster_list_,
    [](const auto& raster1, const auto& raster2)->bool {
    return ilexicographical_compare(raster1.GetShortName(),
                                    raster2.GetShortName());
  });
}

std::string SelectionList::GetActiveRaster(size_t index) const {
  size_t count = 0;
  for (const Raster& raster : raster_list_) {
    if (raster.IsActive()) {
      if (count == index) {
        return raster.GetShortName();
      }
      ++count;
    }
  }
  return {};
}

Raster* SelectionList::GetRaster(size_t index) {
  return index < raster_list_.size() ? &raster_list_[index] : nullptr;
}

void SelectionList::DeleteRaster(std::string raster) {
  std::erase_if(raster_list_, [raster](const auto& raster_obj) {
    return iequals(raster_obj.GetShortName(), raster);
  });
}

bool SelectionList::ExistRaster(const ccp::Raster& raster) const {
  return std::ranges::any_of( raster_list_,
    [raster] (const auto& raster_obj) -> bool {
    return iequals(raster_obj.GetName(),raster.GetName()) ||
           iequals(raster_obj.GetShortName(),raster.GetShortName());
  });
}

void SelectionList::WriteSettingSection(std::fstream& file) const {
  file << "[SETTINGS]" << std::endl;
  file << "Version;" << GetVersionAsString() << std::endl;
  file << "MultirasterSeparator;" << GetRasterSeparator() << std::endl;
  file << std::endl;
}

void SelectionList::WriteRamcellSection(std::fstream& file) const {
  // First check number of ramcells and if not empty, write the section
  SortedObjectList list = GetSortedList(ObjectType::RAMCELL);
  if (list.empty()) {
    return;
  }

  file << "[RAMCELL]" << std::endl;
  for (const auto& object : list | std::views::values) {
    WriteObject(file, object);
  }
  file << std::endl;
}

void SelectionList::WriteLabelSection(std::fstream& file) const {
  // First check number of ramcells and if not empty, write the section
  SortedObjectList list = GetSortedList(ObjectType::LABEL);
  if (list.empty()) {
    return;
  }

  file << "[LABEL]" << std::endl;
  for (const auto& object : list | std::views::values) {
    WriteObject(file, object);
  }
  file << std::endl;
}

void SelectionList::WriteFunctionSection(std::fstream& file) const {
  // First check number of ramcells and if not empty, write the section
  SortedObjectList list = GetSortedList(ObjectType::FUNCTION);
  if (list.empty()) {
    return;
  }

  file << "[FUNCTION]" << std::endl;
  for (const auto& object : list | std::views::values) {
    WriteObject(file, object);
  }
  file << std::endl;
}

void SelectionList::WriteGroupSection(std::fstream& file) const {
  // First check number of ramcells and if not empty, write the section
  SortedObjectList list = GetSortedList(ObjectType::GROUP);
  if (list.empty()) {
    return;
  }

  file << "[GROUP]" << std::endl;
  for (const auto& object : list | std::views::values) {
    WriteObject(file, object);
  }
  file << std::endl;
}

void SelectionList::WriteObject(std::fstream& file,
                                const SelectionObject& object) const {
  file << object.GetName();
  const int64_t order = object.GetOrder();
  const RasterList& raster_list = object.GetRasterList();

  const bool print_comment = !object.GetComment().empty();
  const bool print_device = !object.GetDevice().empty() || print_comment;
  const bool print_order = order >= 0 || print_device;
  const bool print_display = !object.GetDisplayTypeAsString().empty() || print_order;

  if (const bool print_raster = !raster_list.empty() || print_display;
    print_raster) {
    WriteRasterList(file, raster_list);
  }
  if (print_display) {
    file << ";" << object.GetDisplayTypeAsString();
  }
  if (print_order) {
    file << ";" << (order < 0 ? std::string() : std::to_string(order));
  }
  if (print_device) {
    file << ";" << object.GetDevice();
  }
  if (print_comment) {
    file << ";" << object.GetComment();
  }
  file << std::endl;
}

void SelectionList::WriteRasterList(std::fstream& file,
                                    const RasterList& list) const {
  file << ";";
  for (size_t index = 0; index < list.size(); ++index) {
    if (index == 0) {
      file << list[index];
    } else {
      file << GetRasterSeparator() << list[index];
    }
  }
}

} // a2l