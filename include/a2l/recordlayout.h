/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include "a2l/a2lobject.h"
#include <map>
#include <memory>

namespace a2l {

class RecordLayout : public A2lObject {
 public:
  void AlignmentByte(uint64_t alignment) { alignment_byte_ = alignment; }
  [[nodiscard]] uint64_t AlignmentByte() const { return alignment_byte_; }

  void AlignmentWord(uint64_t alignment) { alignment_word_ = alignment; }
  [[nodiscard]] uint64_t AlignmentWord() const { return alignment_word_; }

  void AlignmentLong(uint64_t alignment) { alignment_long_ = alignment; }
  [[nodiscard]] uint64_t AlignmentLong() const { return alignment_long_; }

  void AlignmentInt64(uint64_t alignment) { alignment_int64_ = alignment; }
  [[nodiscard]] uint64_t AlignmentInt64() const { return alignment_int64_; }

  void AlignmentFloat16(uint64_t alignment) { alignment_float16_ = alignment; }
  [[nodiscard]] uint64_t AlignmentFloat16() const { return alignment_float16_; }

  void AlignmentFloat32(uint64_t alignment) { alignment_float32_ = alignment; }
  [[nodiscard]] uint64_t AlignmentFloat32() const { return alignment_float32_; }

  void AlignmentFloat64(uint64_t alignment) { alignment_float64_ = alignment; }
  [[nodiscard]] uint64_t AlignmentFloat64() const { return alignment_float64_; }

  void AxisPtsX(const A2lAxisPts& pts) { axis_pts_x_ = pts; }
  [[nodiscard]] const A2lAxisPts& AxisPtsX() const { return axis_pts_x_; }

  void AxisPtsY(const A2lAxisPts& pts) { axis_pts_y_ = pts; }
  [[nodiscard]] const A2lAxisPts& AxisPtsY() const { return axis_pts_y_; }

  void AxisPtsZ(const A2lAxisPts& pts) { axis_pts_z_ = pts; }
  [[nodiscard]] const A2lAxisPts& AxisPtsZ() const { return axis_pts_z_; }

  void AxisPts4(const A2lAxisPts& pts) { axis_pts_4_ = pts; }
  [[nodiscard]] const A2lAxisPts& AxisPts4() const { return axis_pts_4_; }

  void AxisPts5(const A2lAxisPts& pts) { axis_pts_5_ = pts; }
  [[nodiscard]] const A2lAxisPts& AxisPts5() const { return axis_pts_5_; }

  void AxisRescaleX(const A2lAxisRescale& scale) { axis_rescale_x_ = scale; }
  [[nodiscard]] const A2lAxisRescale& AxisRescaleX() const {
    return axis_rescale_x_;
  }

  void DistOpX(const A2lDistOp& dist) { dist_op_x_ = dist; }
  [[nodiscard]] const A2lDistOp& DistOpX() const { return dist_op_x_; }

  void DistOpY(const A2lDistOp& dist) { dist_op_y_ = dist; }
  [[nodiscard]] const A2lDistOp& DistOpY() const { return dist_op_y_; }

  void DistOpZ(const A2lDistOp& dist) { dist_op_z_ = dist; }
  [[nodiscard]] const A2lDistOp& DistOpZ() const { return dist_op_z_; }

  void DistOp4(const A2lDistOp& dist) { dist_op_4_ = dist; }
  [[nodiscard]] const A2lDistOp& DistOp4() const { return dist_op_4_; }

  void DistOp5(const A2lDistOp& dist) { dist_op_5_ = dist; }
  [[nodiscard]] const A2lDistOp& DistOp5() const { return dist_op_5_; }

  void FixNoAxisPtsX(uint64_t pts) { fix_no_axis_pts_x_ = pts; }
  [[nodiscard]] uint64_t FixNoAxisPtsX() const { return fix_no_axis_pts_x_; }

  void FixNoAxisPtsY(uint64_t pts) { fix_no_axis_pts_y_ = pts; }
  [[nodiscard]] uint64_t FixNoAxisPtsY() const { return fix_no_axis_pts_y_; }

  void FixNoAxisPtsZ(uint64_t pts) { fix_no_axis_pts_z_ = pts; }
  [[nodiscard]] uint64_t FixNoAxisPtsZ() const { return fix_no_axis_pts_z_; }

  void FixNoAxisPts4(uint64_t pts) { fix_no_axis_pts_4_ = pts; }
  [[nodiscard]] uint64_t FixNoAxisPts4() const { return fix_no_axis_pts_4_; }

  void FixNoAxisPts5(uint64_t pts) { fix_no_axis_pts_5_ = pts; }
  [[nodiscard]] uint64_t FixNoAxisPts5() const { return fix_no_axis_pts_5_; }

  void FncValues(const A2lFncValue& fnc ) { fnc_values_ = fnc; }
  [[nodiscard]] const A2lFncValue& FncValues() const { return fnc_values_; }

  void Identification(const A2lIdentification& ident ) {
    identification_ = ident;
  }
  [[nodiscard]] const A2lIdentification& Identification() const {
    return identification_;
  }

  void NoAxisPtsX(const A2lDistOp& pts) { no_axis_pts_x_ = pts; }
  [[nodiscard]] const A2lDistOp& NoAxisPtsX() const { return no_axis_pts_x_; }

  void NoAxisPtsY(const A2lDistOp& pts) { no_axis_pts_y_ = pts; }
  [[nodiscard]] const A2lDistOp& NoAxisPtsY() const { return no_axis_pts_y_; }

  void NoAxisPtsZ(const A2lDistOp& pts) { no_axis_pts_z_ = pts; }
  [[nodiscard]] const A2lDistOp& NoAxisPtsZ() const { return no_axis_pts_z_; }

  void NoAxisPts4(const A2lDistOp& pts) { no_axis_pts_4_ = pts; }
  [[nodiscard]] const A2lDistOp& NoAxisPts4() const { return no_axis_pts_4_; }

  void NoAxisPts5(const A2lDistOp& pts) { no_axis_pts_5_ = pts; }
  [[nodiscard]] const A2lDistOp& NoAxisPts5() const { return no_axis_pts_5_; }

  void NoRescaleX(const A2lDistOp& pts) { no_rescale_x_ = pts; }
  [[nodiscard]] const A2lDistOp& NoRescaleX() const { return no_rescale_x_; }

  void OffsetX(const A2lDistOp& offset) { offset_x_ = offset; }
  [[nodiscard]] const A2lDistOp& OffsetX() const { return offset_x_; }

  void OffsetY(const A2lDistOp& offset) { offset_y_ = offset; }
  [[nodiscard]] const A2lDistOp& OffsetY() const { return offset_y_; }

  void OffsetZ(const A2lDistOp& offset) { offset_z_ = offset; }
  [[nodiscard]] const A2lDistOp& OffsetZ() const { return offset_z_; }

  void Offset4(const A2lDistOp& offset) { offset_4_ = offset; }
  [[nodiscard]] const A2lDistOp& Offset4() const { return offset_4_; }

  void Offset5(const A2lDistOp& offset) { offset_5_ = offset; }
  [[nodiscard]] const A2lDistOp& Offset5() const { return offset_5_; }

  void AddReserved(const A2lDistOp& reserved);
  [[nodiscard]] const std::vector<A2lDistOp>& ReservedList() const {
    return reserved_list_;
  }

  void RipAddrW(const A2lDistOp& rip) { rip_addr_w_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddrW() const { return rip_addr_w_; }

  void RipAddrX(const A2lDistOp& rip) { rip_addr_x_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddrX() const { return rip_addr_x_; }

  void RipAddrY(const A2lDistOp& rip) { rip_addr_y_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddrY() const { return rip_addr_y_; }

  void RipAddrZ(const A2lDistOp& rip) { rip_addr_z_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddrZ() const { return rip_addr_z_; }

  void RipAddr4(const A2lDistOp& rip) { rip_addr_4_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddr4() const { return rip_addr_4_; }

  void RipAddr5(const A2lDistOp& rip) { rip_addr_5_ = rip; }
  [[nodiscard]] const A2lDistOp& RipAddr5() const { return rip_addr_5_; }

  void SrcAddrX(const A2lDistOp& src) { src_addr_x_ = src; }
  [[nodiscard]] const A2lDistOp& SrcAddrX() const { return src_addr_x_; }

  void SrcAddrY(const A2lDistOp& src) { src_addr_y_ = src; }
  [[nodiscard]] const A2lDistOp& SrcAddrY() const { return src_addr_y_; }

  void SrcAddrZ(const A2lDistOp& src) { src_addr_z_ = src; }
  [[nodiscard]] const A2lDistOp& SrcAddrZ() const { return src_addr_z_; }

  void SrcAddr4(const A2lDistOp& src) { src_addr_4_ = src; }
  [[nodiscard]] const A2lDistOp& SrcAddr4() const { return src_addr_4_; }

  void SrcAddr5(const A2lDistOp& src) { src_addr_5_ = src; }
  [[nodiscard]] const A2lDistOp& SrcAddr5() const { return src_addr_5_; }

  void ShiftOpX(const A2lDistOp& shift) { shift_op_x_ = shift; }
  [[nodiscard]] const A2lDistOp& ShiftOpX() const { return shift_op_x_; }

  void ShiftOpY(const A2lDistOp& shift) { shift_op_y_ = shift; }
  [[nodiscard]] const A2lDistOp& ShiftOpY() const { return shift_op_y_; }

  void ShiftOpZ(const A2lDistOp& shift) { shift_op_z_ = shift; }
  [[nodiscard]] const A2lDistOp& ShiftOpZ() const { return shift_op_z_; }

  void ShiftOp4(const A2lDistOp& shift) { shift_op_4_ = shift; }
  [[nodiscard]] const A2lDistOp& ShiftOp4() const { return shift_op_4_; }

  void ShiftOp5(const A2lDistOp& shift) { shift_op_5_ = shift; }
  [[nodiscard]] const A2lDistOp& ShiftOp5() const { return shift_op_5_; }

  void StaticAddressOffsets(bool offset) { static_address_offsets_ = offset; }
  [[nodiscard]] bool StaticAddressOffsets() const {
    return static_address_offsets_;
  }
  void StaticRecordLayout(bool layout) { static_record_layout_ = layout; }
  [[nodiscard]] bool StaticRecordLayout() const {
    return static_record_layout_;
  }

 private:
  uint64_t alignment_byte_ = 0;
  uint64_t alignment_word_ = 0;
  uint64_t alignment_long_ = 0;
  uint64_t alignment_int64_ = 0;
  uint64_t alignment_float16_ = 0;
  uint64_t alignment_float32_ = 0;
  uint64_t alignment_float64_ = 0;

  A2lAxisPts axis_pts_x_ = {};
  A2lAxisPts axis_pts_y_ = {};
  A2lAxisPts axis_pts_z_ = {};
  A2lAxisPts axis_pts_4_ = {};
  A2lAxisPts axis_pts_5_ = {};

  A2lAxisRescale axis_rescale_x_ = {};

  A2lDistOp dist_op_x_ = {};
  A2lDistOp dist_op_y_ = {};
  A2lDistOp dist_op_z_ = {};
  A2lDistOp dist_op_4_ = {};
  A2lDistOp dist_op_5_ = {};

  uint64_t fix_no_axis_pts_x_ = 0;
  uint64_t fix_no_axis_pts_y_ = 0;
  uint64_t fix_no_axis_pts_z_ = 0;
  uint64_t fix_no_axis_pts_4_ = 0;
  uint64_t fix_no_axis_pts_5_ = 0;

  A2lFncValue fnc_values_ = {};
  A2lIdentification identification_ = {};

  A2lDistOp no_axis_pts_x_ = {};
  A2lDistOp no_axis_pts_y_ = {};
  A2lDistOp no_axis_pts_z_ = {};
  A2lDistOp no_axis_pts_4_ = {};
  A2lDistOp no_axis_pts_5_ = {};

  A2lDistOp no_rescale_x_ = {};

  A2lDistOp offset_x_ = {};
  A2lDistOp offset_y_ = {};
  A2lDistOp offset_z_ = {};
  A2lDistOp offset_4_ = {};
  A2lDistOp offset_5_ = {};

  std::vector<A2lDistOp> reserved_list_;

  A2lDistOp rip_addr_w_ = {};
  A2lDistOp rip_addr_x_ = {};
  A2lDistOp rip_addr_y_ = {};
  A2lDistOp rip_addr_z_ = {};
  A2lDistOp rip_addr_4_ = {};
  A2lDistOp rip_addr_5_ = {};

  A2lDistOp src_addr_x_ = {};
  A2lDistOp src_addr_y_ = {};
  A2lDistOp src_addr_z_ = {};
  A2lDistOp src_addr_4_ = {};
  A2lDistOp src_addr_5_ = {};

  A2lDistOp shift_op_x_ = {};
  A2lDistOp shift_op_y_ = {};
  A2lDistOp shift_op_z_ = {};
  A2lDistOp shift_op_4_ = {};
  A2lDistOp shift_op_5_ = {};

  bool static_address_offsets_ = false;
  bool static_record_layout_ = false;
};

using RecordLayoutList = std::map<std::string, std::unique_ptr<RecordLayout>>;

} // end namespace a2l