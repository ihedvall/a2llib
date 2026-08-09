/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "labelscanner.h"

#include <string>

#include "a2l/a2lhelper.h"
#include "a2l/a2llogstream.h"

namespace a2l {
LabelScanner::LabelScanner(std::istream& file, SelectionList& selection_list)
    : labelFlexLexer(&file),
      selection_list_(selection_list) {
  // Remove any BOM from the input file.
  const std::string data{std::istreambuf_iterator(file),
      std::istreambuf_iterator<char>()};

  if (data.starts_with("\xEF\xBB\xBF")) {
    file.seekg(3, std::ios::beg);
    selection_list_.SetUtf8(true);
  } else {
    selection_list_.SetUtf8(false);
  }
}

void LabelScanner::ParseLineText(const std::vector<std::string> &line_list) const {
  switch (GetLabelState()) {
    case LabelState::Settings:
      SetSettingsProperty(line_list);
      break;

    default:
      SetObjectProperty(line_list);
      break;
  }
}

void LabelScanner::SetSettingsProperty(const std::vector<std::string>&
                                property_list) const {
  if (property_list.size() < 2) {
    return;
  }
  const std::string& key = property_list[0];
  const std::string& value = property_list[1];
  if (key == "Version") {
    selection_list_.SetVersionAsString(value);
  } else if (key == "MultirasterSeparator") {
    selection_list_.SetRasterSeparator(value.empty() ? '&' : value[0]);
  }
}

void LabelScanner::SetObjectProperty(const std::vector<std::string>&
                                property_list) const {
  if (property_list.empty()) {
    return;
  }

  SelectionObject object;
  object.SetName(property_list[0]);
  switch (GetLabelState()) {
    case LabelState::Ramcell:
      object.SetObjectType(ObjectType::RAMCELL);
      break;

    case LabelState::Label:
      object.SetObjectType(ObjectType::LABEL);
      break;

    case LabelState::Function:
      object.SetObjectType(ObjectType::FUNCTION);
      break;

    case LabelState::Group:
      object.SetObjectType(ObjectType::GROUP);
      break;

    default:
      return;
  }
  switch (selection_list_.GetLabelVersion()) {
    case LabelVersion::V10:
      SetV10Property(object, property_list);
      break;
    case LabelVersion::V11:
      SetV11Property(object, property_list);
      break;
    case LabelVersion::V12:
      SetV12Property(object, property_list);
      break;
    case LabelVersion::V13:
      SetV13Property(object, property_list);
      break;

    default:
      break;
  }

  selection_list_.AddObject(object);
}

void LabelScanner::SetV10Property(SelectionObject& object,
    const std::vector<std::string>& property_list) {
  for (size_t index = 0; index < property_list.size(); ++index) {
    switch (index) {
      case 0: // Name
        object.SetName(property_list[0]);
        break;
      case 1: // Comment
        object.SetComment(property_list[1]);
        break;

      default:
        break;
    }
  }
}

void LabelScanner::SetV11Property(SelectionObject& object,
    const std::vector<std::string>& property_list) const {
  for (size_t index = 0; index < property_list.size(); ++index) {
    switch (index) {
      case 0: // Name
        object.SetName(property_list[0]);
        break;

      case 1: { // Raster
        const auto raster_list = A2lHelper::Split(property_list[1],
          selection_list_.GetRasterSeparator());
        for (const std::string& raster : raster_list) {
          object.AddRaster(raster);
        }
        break;
      }

      case 2: // Comment
        object.SetComment(property_list[2]);
        break;

      default:
        break;
    }
  }
}

void LabelScanner::SetV12Property(
    SelectionObject& object,
    const std::vector<std::string>& property_list) const {
  for (size_t index = 0; index < property_list.size(); ++index) {
    switch (index) {
      case 0: // Name
        object.SetName(property_list[0]);
        break;

      case 1: { // Raster
        const auto raster_list = A2lHelper::Split(property_list[1],
          selection_list_.GetRasterSeparator());
        for (const std::string& raster : raster_list) {
          object.AddRaster(raster);
        }
        break;
      }

      case 2: // Display Type
        object.SetDisplayTypeAsString(property_list[2]);
        break;

      case 3: // Order
        if (const std::string& prop_order = property_list[3];
            !prop_order.empty()) {
          try {
            object.SetOrder(std::stoll(prop_order));
          } catch (const std::exception&) {
            A2L_ERROR() << "Invalid order value: " << prop_order;
          }
            }
        break;

      case 4: // Comment
        object.SetComment(property_list[4]);
        break;

      default:
        break;
    }
  }
}

void LabelScanner::SetV13Property(SelectionObject& object,
    const std::vector<std::string>& property_list) const {
  for (size_t index = 0; index < property_list.size(); ++index) {
    switch (index) {
      case 0: // Name
        object.SetName(property_list[0]);
        break;

      case 1: { // Raster
        const auto raster_list = A2lHelper::Split(property_list[1],
          selection_list_.GetRasterSeparator());
        for (const std::string& raster : raster_list) {
          object.AddRaster(raster);
        }
        break;
      }

      case 2: // Display Type
        object.SetDisplayTypeAsString(property_list[2]);
        break;

      case 3: // Order
        if (const std::string& prop_order = property_list[3];
            !prop_order.empty()) {
          try {
            object.SetOrder(std::stoll(prop_order));
          } catch (const std::exception&) {
            A2L_ERROR() << "Invalid order value: " << prop_order;
          }
            }
        break;

      case 4: // Device
        object.SetDevice(property_list[4]);
        break;

      case 5: // Comment
        object.SetComment(property_list[5]);
        break;

      default:
        break;
    }
  }
}


} // a2l