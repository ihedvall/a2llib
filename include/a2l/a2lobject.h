/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once
#include <string>
#include <map>
#include "a2l/a2lenums.h"
#include "a2l/a2lstructs.h"
namespace a2l {

/** \brief if_data strings sorted in protocol order */
using IfDataList = std::map<std::string, std::string>;

class A2lObject {
 public:
  virtual ~A2lObject() = default;
  void Name(const std::string& name) { name_ = name; }
  [[nodiscard]] const std::string& Name() const { return name_; }


  void ByteOrder(A2lByteOrder order) { byte_order_ = order; }
  [[nodiscard]] A2lByteOrder ByteOrder() const { return byte_order_; }

  void CalibrationAccess(A2lCalibrationAccess access) {
    calibration_access_ = access;
  }
  [[nodiscard]] A2lCalibrationAccess CalibrationAccess() const {
    return calibration_access_;
  }

  void Description(const std::string& description) {
    description_ = description;
  }
  [[nodiscard]] const std::string& Description() const { return description_; }

  void Discrete(bool discrete) { discrete_ = discrete; }
  [[nodiscard]] bool Discrete() const { return discrete_; }

  void DisplayIdentifier(const std::string& name) {
    display_identifier_ = name;
  }
  [[nodiscard]] const std::string& DisplayIdentifier() const {
    return display_identifier_;
  }

  void EcuAddressExtension(int64_t ext) {
    ecu_address_extension_ = ext;
  }
  [[nodiscard]] int64_t EcuAddressExtension() const {
    return ecu_address_extension_;
  }

  void  ExtendedLimits(const A2lExtendedLimits& limits) {
    extended_limits_ = limits;
  }
  [[nodiscard]] const A2lExtendedLimits& ExtendedLimits() const {
    return extended_limits_;
  }

  void Format(const std::string& format) {format_ = format; }
  [[nodiscard]] const std::string& Format() const { return format_; }

  void FunctionList(const std::vector<std::string>& list) {
    function_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& FunctionList() const {
    return function_list_;
  }

  void GuardRails(bool guard_rails) { guard_rails_ = guard_rails; }
  [[nodiscard]] bool GuardRails() const { return guard_rails_; };

  void MatrixDim(const std::vector<uint64_t>& list) { matrix_dim_ = list; }
  [[nodiscard]] const std::vector<uint64_t>& MatrixDim() const {
    return matrix_dim_;
  }

  void MaxRefresh(const A2lMaxRefresh& rate) { max_refresh_ = rate; }
  [[nodiscard]] const A2lMaxRefresh& MaxRefresh() const { return max_refresh_; };

  void ModelLink(const std::string& link) { model_link_ = link; }
  [[nodiscard]] const std::string& ModelLink() const { return model_link_; }

  void PhysUnit(const std::string& unit) { phys_unit_ = unit; }
  [[nodiscard]] const std::string& PhysUnit() const { return phys_unit_; }

  void ReadOnly(bool read_only) { read_only_ = read_only; }
  [[nodiscard]] bool ReadOnly() const { return read_only_; }

  void RefMemorySegment(const std::string& segment) {
    ref_memory_segment_ = segment;
  }
  [[nodiscard]] const std::string& RefMemorySegment() const {
    return ref_memory_segment_;
  }
  void StepSize(double step_size) { step_size_ = step_size; }
  [[nodiscard]] double StepSize() const { return step_size_; }

  void SymbolLink(const A2lSymbolLink& symbol) { symbol_link_ = symbol; }
  [[nodiscard]] const A2lSymbolLink& SymbolLink() const { return symbol_link_; }

  void AddAnnotation(const A2lAnnotation& annotation);
  [[nodiscard]] AnnotationList& Annotations() {
    return annotation_list_;
  }
  [[nodiscard]] const AnnotationList& Annotations() const {
    return annotation_list_;
  }

  void AddIfData(const std::string& input);
  [[nodiscard]] const IfDataList& IfDatas() const { return if_data_list_;}
  [[nodiscard]] bool HaveIfData() const { return !if_data_list_.empty();}
  [[nodiscard]] bool HaveIfData(const std::string_view& protocol) const;
 private:
  std::string name_;
  std::string description_;
  A2lByteOrder byte_order_ = A2lByteOrder::UNKNOWN;
  A2lCalibrationAccess calibration_access_ = A2lCalibrationAccess::UNKNOWN;

  bool discrete_ = false;
  std::string display_identifier_;
  int64_t ecu_address_extension_ = 0;
  A2lExtendedLimits extended_limits_ = {};
  std::string format_;
  std::vector<std::string> function_list_;
  bool guard_rails_ = false;
  std::vector<uint64_t> matrix_dim_;
  A2lMaxRefresh max_refresh_;
  std::string model_link_;
  std::string phys_unit_;
  bool read_only_ = false;
  std::string ref_memory_segment_;
  double step_size_ = 0.0;
  A2lSymbolLink symbol_link_;

  IfDataList  if_data_list_;
  AnnotationList annotation_list_;

};

} // end namespace
