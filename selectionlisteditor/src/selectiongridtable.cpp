/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "selectiongridtable.h"

#include <string_view>
#include <array>

#include "a2l/a2llogstream.h"

#include "selectionlistframe.h"

namespace {

constexpr std::array<std::string_view, 4> kObjectTypeList = {
  "Measurement", "Characteristic", "Function", "Group"
};
constexpr std::array<std::string_view, 5> kDisplayTypeList = {
  "",
  "Display",
  "Display Only",
  "Record Only",
  "Do Not Use",
};

}

namespace a2l {

SelectionGridTable::SelectionGridTable()
  : wxGridTableBase() {
}

int SelectionGridTable::GetNumberRows() {
  if (selection_list_ == nullptr) {
    return 0;
  }
  return static_cast<int>(selection_list_->GetSize());
}

int SelectionGridTable::GetNumberCols() {
  // NAME, TYPE, RASTER[], DISPLAY TYPE, COMMENT, DEVICE,
  // UNIT, DESC, LOW & HIGH LIMITs
  constexpr size_t cols = 9 + 5;
  return static_cast<int>(cols);
}

wxString SelectionGridTable::GetValue(int row, int col) {


 if (selection_list_ == nullptr) {
   return {};
 }
 const auto index = static_cast<size_t>(row);
 const auto& object_list = selection_list_->GetObjectList();
 if (index >= object_list.size()) {
   return {};
 }
 const auto& object = object_list[index];
 wxString value;
 switch (col) {
   case 0: // Name
     value = wxString::FromUTF8(object.GetName());
     break;

   case 1: // Object Type
     if (const auto type_index = static_cast<size_t>(object.GetObjectType());
         type_index < kObjectTypeList.size()) {
       value = kObjectTypeList[type_index];
     }
     break;

   case 2: // Boolean raster value
   case 3:
   case 4:
   case 5:
   case 6: {
     const size_t raster_index = col - 2;
     const std::string ref_raster = selection_list_->GetActiveRaster(raster_index);
     const bool have_raster = object.HaveRaster(ref_raster);
     value = have_raster ? "1" : "0";
     break;
   }

   case 7: // Display Type
     if (const auto type_index = static_cast<size_t>(object.GetDisplayType());
         type_index < kDisplayTypeList.size()) {
       value = wxString::FromUTF8(kDisplayTypeList[type_index]);
     }
     break;

   case 8: // Comment
     value = wxString::FromUTF8(object.GetComment());
     break;

   case 9: // Device
     value = wxString::FromUTF8(object.GetDevice());
     break;

   case 10: // Unit
     value = wxString::FromUTF8(object.GetUnit());
     break;

   case 11: // Description
     value = wxString::FromUTF8(object.GetDescription());
     break;

   case 12: // Low Limit
     if (object.GetLowerLimit() < object.GetUpperLimit()) {
       value = wxString::FromDouble(object.GetLowerLimit());
     }
     break;

   case 13: // High Limit
     if (object.GetLowerLimit() < object.GetUpperLimit()) {
       value = wxString::FromDouble(object.GetUpperLimit());
     }
     break;
     
   default:
      break;
 }

 return value;
}

void SelectionGridTable::SetValue(int row, int col, const wxString& value) {
  SelectionListDocument* doc = SelectionListFrame::GetDocument();
  if (selection_list_ == nullptr || doc == nullptr) {
    return;
  }

  const auto index = static_cast<size_t>(row);
  auto& object_list = selection_list_->GetObjectList();
  if (index >= object_list.size()) {
    return;
  }
  auto& object = object_list[index];

  switch (col) {
    case 2: // Boolean raster value
    case 3:
    case 4:
    case 5:
    case 6: {
      const size_t raster_index = col - 2;
      const std::string ref_raster = selection_list_->GetActiveRaster(raster_index);
      if (value == "1") {
        object.AddRaster(ref_raster);
      } else if (value == "0") {
        object.DeleteRaster(ref_raster);
      } else {
        A2L_ERROR() << "Invalid boolean raster value. Value:" << value;
      }
      doc->Modify(true);
      break;
    }

    case 7: { // Display Type
      const std::string type = value.utf8_string();
      for (size_t type_index = 0; type_index < kDisplayTypeList.size(); ++type_index) {
        if (type == kDisplayTypeList[type_index]) {
          object.SetDisplayType(static_cast<ObjectDisplayType>(type_index));
          doc->Modify(true);
          break;
        }
      }
      break;
    }

    case 8: // Comment
      object.SetComment(value.utf8_string());
      doc->Modify(true);
      break;

    case 9: // Device
      object.SetDevice(value.utf8_string());
      doc->Modify(true);
      break;

    case 0: // Name
    case 1: // Object type
    case 10: // Unit
    case 11: // Description
    case 12: // Low Limit
    case 13: // High Limit
    default:
      // Read-only properties
      break;
  }
}

wxString SelectionGridTable::GetRowLabelValue(int row) {
  return {};
}
wxString SelectionGridTable::GetColLabelValue(int col) {

  wxString label;
  switch (col) {
    case 0:
      label = "Name";
      break;

    case 1:
      label = "Type";
      break;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      if (selection_list_ != nullptr) {
        const size_t raster_index = col - 2;
        label = selection_list_->GetActiveRaster(raster_index);
      }
      break;

    case 7:
      label = "Display Type";
      break;

    case 8:
      label = "Comment";
      break;

    case 9:
      label = "Device";
      break;

    case 10:
      label = "Unit";
      break;

    case 11:
      label = "Description";
      break;

    case 12:
      label = "Low Limit";
      break;

    case 13:
      label = "High Limit";
      break;

    default:
      break;
  }

  return label;
}

void SelectionGridTable::SetSelectionList(SelectionList* selection_list) {
  selection_list_ = selection_list;
}

} // a2l