// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   a2llex



#include "a2lparser.hpp"


// Unqualified %code blocks.
#line 28 "D:/projects/a2llib/src/a2lparser.y"
    #include "a2l/a2lstructs.h"
    #include <sstream>
    #include "a2lscanner.h"
    #include "a2l/a2lfile.h"
    #include "a2lhelper.h"
    #include <limits>


    #undef yylex
    #define yylex scanner.a2llex

#line 60 "D:/projects/a2llib/src/a2lparser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if A2LDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !A2LDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !A2LDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "D:/projects/a2llib/src/a2lparser.y"
namespace a2l {
#line 134 "D:/projects/a2llib/src/a2lparser.cpp"

  /// Build a parser object.
  A2lParser::A2lParser (a2l::A2lScanner &scanner_yyarg, a2l::A2lFile &file_yyarg)
#if A2LDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      file (file_yyarg)
  {}

  A2lParser::~A2lParser ()
  {}

  A2lParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  A2lParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.copy< A2lAddressType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.copy< A2lAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.copy< A2lAxisPts > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.copy< A2lAxisRescale > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.copy< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.copy< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.copy< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.copy< A2lCalibrationHandle > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.copy< A2lCalibrationMethod > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.copy< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.copy< A2lDeposit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.copy< A2lDistOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_encoding: // encoding
        value.copy< A2lEncoding > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.copy< A2lExtendedLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.copy< A2lFixAxisPar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.copy< A2lFixAxisParDist > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.copy< A2lFncValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identification: // identification
        value.copy< A2lIdentification > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_layout: // layout
        value.copy< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_limits: // limits
        value.copy< A2lLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.copy< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.copy< A2lMemoryLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.copy< A2lMemorySegment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.copy< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.copy< A2lSegmentType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.copy< A2lSiExponents > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.copy< A2lSymbolLink > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.copy< A2lVarCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.copy< A2lVarCriterion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.copy< std::deque<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.copy< std::deque<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::deque<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.copy< std::deque<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::deque<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.copy< std::pair<double,double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.copy< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::unordered_map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::unordered_map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.copy< std::unordered_map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.copy< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  A2lParser::symbol_kind_type
  A2lParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  A2lParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  A2lParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.move< A2lAddressType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.move< A2lAnnotation > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.move< A2lAxisPts > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.move< A2lAxisRescale > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.move< A2lCalibrationHandle > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.move< A2lCalibrationMethod > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.move< A2lDistOp > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_encoding: // encoding
        value.move< A2lEncoding > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.move< A2lExtendedLimits > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.move< A2lFixAxisPar > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.move< A2lFixAxisParDist > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.move< A2lFncValue > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identification: // identification
        value.move< A2lIdentification > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_limits: // limits
        value.move< A2lLimits > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.move< A2lMemoryLayout > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.move< A2lMemorySegment > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.move< A2lSegmentType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.move< A2lSiExponents > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.move< A2lVarCharacteristic > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.move< A2lVarCriterion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::deque<A2lCalibrationHandle> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::deque<double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::deque<int64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::deque<std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::deque<uint64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.move< std::pair<double,double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.move< std::pair<std::string,std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::unordered_map<double, double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::unordered_map<double, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::unordered_map<std::string, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.move< uint64_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  A2lParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  A2lParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  A2lParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  A2lParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  A2lParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  A2lParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  A2lParser::symbol_kind_type
  A2lParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  A2lParser::symbol_kind_type
  A2lParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  A2lParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  A2lParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  A2lParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  A2lParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  A2lParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  A2lParser::symbol_kind_type
  A2lParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  A2lParser::stack_symbol_type::stack_symbol_type ()
  {}

  A2lParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.YY_MOVE_OR_COPY< A2lAddressType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.YY_MOVE_OR_COPY< A2lAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.YY_MOVE_OR_COPY< A2lAxisPts > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.YY_MOVE_OR_COPY< A2lAxisRescale > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.YY_MOVE_OR_COPY< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.YY_MOVE_OR_COPY< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.YY_MOVE_OR_COPY< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.YY_MOVE_OR_COPY< A2lCalibrationHandle > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.YY_MOVE_OR_COPY< A2lCalibrationMethod > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.YY_MOVE_OR_COPY< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.YY_MOVE_OR_COPY< A2lDeposit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.YY_MOVE_OR_COPY< A2lDistOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_encoding: // encoding
        value.YY_MOVE_OR_COPY< A2lEncoding > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.YY_MOVE_OR_COPY< A2lExtendedLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.YY_MOVE_OR_COPY< A2lFixAxisPar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.YY_MOVE_OR_COPY< A2lFixAxisParDist > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.YY_MOVE_OR_COPY< A2lFncValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identification: // identification
        value.YY_MOVE_OR_COPY< A2lIdentification > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_layout: // layout
        value.YY_MOVE_OR_COPY< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_limits: // limits
        value.YY_MOVE_OR_COPY< A2lLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.YY_MOVE_OR_COPY< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.YY_MOVE_OR_COPY< A2lMemoryLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.YY_MOVE_OR_COPY< A2lMemorySegment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.YY_MOVE_OR_COPY< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.YY_MOVE_OR_COPY< A2lSegmentType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.YY_MOVE_OR_COPY< A2lSiExponents > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.YY_MOVE_OR_COPY< A2lSymbolLink > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.YY_MOVE_OR_COPY< A2lVarCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.YY_MOVE_OR_COPY< A2lVarCriterion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.YY_MOVE_OR_COPY< std::deque<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.YY_MOVE_OR_COPY< std::deque<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.YY_MOVE_OR_COPY< std::deque<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.YY_MOVE_OR_COPY< std::deque<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.YY_MOVE_OR_COPY< std::deque<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.YY_MOVE_OR_COPY< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.YY_MOVE_OR_COPY< std::pair<double,double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.YY_MOVE_OR_COPY< std::unordered_map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.YY_MOVE_OR_COPY< std::unordered_map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.YY_MOVE_OR_COPY< std::unordered_map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.YY_MOVE_OR_COPY< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  A2lParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.move< A2lAddressType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.move< A2lAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.move< A2lAxisPts > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.move< A2lAxisRescale > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.move< A2lCalibrationHandle > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.move< A2lCalibrationMethod > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.move< A2lDistOp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_encoding: // encoding
        value.move< A2lEncoding > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.move< A2lExtendedLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.move< A2lFixAxisPar > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.move< A2lFixAxisParDist > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.move< A2lFncValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identification: // identification
        value.move< A2lIdentification > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_limits: // limits
        value.move< A2lLimits > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.move< A2lMemoryLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.move< A2lMemorySegment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.move< A2lSegmentType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.move< A2lSiExponents > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.move< A2lVarCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.move< A2lVarCriterion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::deque<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::deque<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::deque<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::deque<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::deque<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.move< std::pair<double,double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.move< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::unordered_map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::unordered_map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::unordered_map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.move< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  A2lParser::stack_symbol_type&
  A2lParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.copy< A2lAddressType > (that.value);
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.copy< A2lAnnotation > (that.value);
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.copy< A2lAxisPts > (that.value);
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.copy< A2lAxisRescale > (that.value);
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.copy< A2lBitOperation > (that.value);
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.copy< A2lByteOrder > (that.value);
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.copy< A2lCalibrationAccess > (that.value);
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.copy< A2lCalibrationHandle > (that.value);
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.copy< A2lCalibrationMethod > (that.value);
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.copy< A2lDependentCharacteristic > (that.value);
        break;

      case symbol_kind::S_deposit: // deposit
        value.copy< A2lDeposit > (that.value);
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.copy< A2lDistOp > (that.value);
        break;

      case symbol_kind::S_encoding: // encoding
        value.copy< A2lEncoding > (that.value);
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.copy< A2lExtendedLimits > (that.value);
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.copy< A2lFixAxisPar > (that.value);
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.copy< A2lFixAxisParDist > (that.value);
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.copy< A2lFncValue > (that.value);
        break;

      case symbol_kind::S_identification: // identification
        value.copy< A2lIdentification > (that.value);
        break;

      case symbol_kind::S_layout: // layout
        value.copy< A2lLayout > (that.value);
        break;

      case symbol_kind::S_limits: // limits
        value.copy< A2lLimits > (that.value);
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.copy< A2lMaxRefresh > (that.value);
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.copy< A2lMemoryLayout > (that.value);
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.copy< A2lMemorySegment > (that.value);
        break;

      case symbol_kind::S_monotony: // monotony
        value.copy< A2lMonotony > (that.value);
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.copy< A2lSegmentType > (that.value);
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.copy< A2lSiExponents > (that.value);
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.copy< A2lSymbolLink > (that.value);
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.copy< A2lVarCharacteristic > (that.value);
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.copy< A2lVarCriterion > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.copy< std::deque<A2lCalibrationHandle> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.copy< std::deque<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::deque<int64_t> > (that.value);
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.copy< std::deque<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::deque<uint64_t> > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::map<std::pair<double, double>, std::string> > (that.value);
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.copy< std::pair<double,double> > (that.value);
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.copy< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::unordered_map<double, double> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::unordered_map<double, std::string> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.copy< std::unordered_map<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.copy< uint64_t > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  A2lParser::stack_symbol_type&
  A2lParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_address_type: // address_type
        value.move< A2lAddressType > (that.value);
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.move< A2lAnnotation > (that.value);
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.move< A2lAxisPts > (that.value);
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.move< A2lAxisRescale > (that.value);
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (that.value);
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (that.value);
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (that.value);
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.move< A2lCalibrationHandle > (that.value);
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.move< A2lCalibrationMethod > (that.value);
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (that.value);
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (that.value);
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.move< A2lDistOp > (that.value);
        break;

      case symbol_kind::S_encoding: // encoding
        value.move< A2lEncoding > (that.value);
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.move< A2lExtendedLimits > (that.value);
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.move< A2lFixAxisPar > (that.value);
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.move< A2lFixAxisParDist > (that.value);
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.move< A2lFncValue > (that.value);
        break;

      case symbol_kind::S_identification: // identification
        value.move< A2lIdentification > (that.value);
        break;

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (that.value);
        break;

      case symbol_kind::S_limits: // limits
        value.move< A2lLimits > (that.value);
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (that.value);
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.move< A2lMemoryLayout > (that.value);
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.move< A2lMemorySegment > (that.value);
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (that.value);
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.move< A2lSegmentType > (that.value);
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.move< A2lSiExponents > (that.value);
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (that.value);
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.move< A2lVarCharacteristic > (that.value);
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.move< A2lVarCriterion > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::deque<A2lCalibrationHandle> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::deque<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::deque<int64_t> > (that.value);
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::deque<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::deque<uint64_t> > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (that.value);
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.move< std::pair<double,double> > (that.value);
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.move< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::unordered_map<double, double> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::unordered_map<double, std::string> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::unordered_map<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.move< uint64_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  A2lParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if A2LDEBUG
  template <typename Base>
  void
  A2lParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  A2lParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  A2lParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  A2lParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if A2LDEBUG
  std::ostream&
  A2lParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  A2lParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  A2lParser::debug_level_type
  A2lParser::debug_level () const
  {
    return yydebug_;
  }

  void
  A2lParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // A2LDEBUG

  A2lParser::state_type
  A2lParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  A2lParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  A2lParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  A2lParser::operator() ()
  {
    return parse ();
  }

  int
  A2lParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_address_type: // address_type
        yylhs.value.emplace< A2lAddressType > ();
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        yylhs.value.emplace< A2lAnnotation > ();
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        yylhs.value.emplace< A2lAxisPts > ();
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        yylhs.value.emplace< A2lAxisRescale > ();
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        yylhs.value.emplace< A2lBitOperation > ();
        break;

      case symbol_kind::S_byte_order: // byte_order
        yylhs.value.emplace< A2lByteOrder > ();
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        yylhs.value.emplace< A2lCalibrationAccess > ();
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        yylhs.value.emplace< A2lCalibrationHandle > ();
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        yylhs.value.emplace< A2lCalibrationMethod > ();
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        yylhs.value.emplace< A2lDependentCharacteristic > ();
        break;

      case symbol_kind::S_deposit: // deposit
        yylhs.value.emplace< A2lDeposit > ();
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        yylhs.value.emplace< A2lDistOp > ();
        break;

      case symbol_kind::S_encoding: // encoding
        yylhs.value.emplace< A2lEncoding > ();
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        yylhs.value.emplace< A2lExtendedLimits > ();
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        yylhs.value.emplace< A2lFixAxisPar > ();
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        yylhs.value.emplace< A2lFixAxisParDist > ();
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        yylhs.value.emplace< A2lFncValue > ();
        break;

      case symbol_kind::S_identification: // identification
        yylhs.value.emplace< A2lIdentification > ();
        break;

      case symbol_kind::S_layout: // layout
        yylhs.value.emplace< A2lLayout > ();
        break;

      case symbol_kind::S_limits: // limits
        yylhs.value.emplace< A2lLimits > ();
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        yylhs.value.emplace< A2lMaxRefresh > ();
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        yylhs.value.emplace< A2lMemoryLayout > ();
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        yylhs.value.emplace< A2lMemorySegment > ();
        break;

      case symbol_kind::S_monotony: // monotony
        yylhs.value.emplace< A2lMonotony > ();
        break;

      case symbol_kind::S_prg_type: // prg_type
        yylhs.value.emplace< A2lSegmentType > ();
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        yylhs.value.emplace< A2lSiExponents > ();
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        yylhs.value.emplace< A2lSymbolLink > ();
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        yylhs.value.emplace< A2lVarCharacteristic > ();
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        yylhs.value.emplace< A2lVarCriterion > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        yylhs.value.emplace< std::deque<A2lCalibrationHandle> > ();
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        yylhs.value.emplace< std::deque<double> > ();
        break;

      case symbol_kind::S_int_list: // int_list
        yylhs.value.emplace< std::deque<int64_t> > ();
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        yylhs.value.emplace< std::deque<std::string> > ();
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        yylhs.value.emplace< std::deque<uint64_t> > ();
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        yylhs.value.emplace< std::map<std::pair<double, double>, std::string> > ();
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        yylhs.value.emplace< std::pair<double,double> > ();
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        yylhs.value.emplace< std::pair<std::string,std::string> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        yylhs.value.emplace< std::unordered_map<double, double> > ();
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        yylhs.value.emplace< std::unordered_map<double, std::string> > ();
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        yylhs.value.emplace< std::unordered_map<std::string, std::string> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        yylhs.value.emplace< uint64_t > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // any_uint: UINT
#line 435 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2822 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 436 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2828 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_int: INT
#line 438 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2834 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: UINT
#line 439 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2840 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: HEX
#line 440 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2846 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_float: FLOAT
#line 442 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2852 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: INT
#line 443 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2858 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: UINT
#line 444 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2864 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: HEX
#line 445 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2870 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // int_list: %empty
#line 447 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2876 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: int_list any_int
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                     {yystack_[1].value.as < std::deque<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); yylhs.value.as < std::deque<int64_t> > () = std::move(yystack_[1].value.as < std::deque<int64_t> > ());  }
#line 2882 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // uint_list: %empty
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: uint_list any_uint
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                       {yystack_[1].value.as < std::deque<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[1].value.as < std::deque<uint64_t> > ());  }
#line 2894 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // float_list: %empty
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2900 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: float_list any_float
#line 454 "D:/projects/a2llib/src/a2lparser.y"
                               {yystack_[1].value.as < std::deque<double> > ().emplace_back(yystack_[0].value.as < double > ()); yylhs.value.as < std::deque<double> > () = std::move(yystack_[1].value.as < std::deque<double> > ());  }
#line 2906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_pair_list: %empty
#line 456 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: float_pair_list any_float any_float
#line 457 "D:/projects/a2llib/src/a2lparser.y"
                                              {yystack_[2].value.as < std::unordered_map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); yylhs.value.as < std::unordered_map<double, double> > () = std::move(yystack_[2].value.as < std::unordered_map<double, double> > ());  }
#line 2918 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_string_list: %empty
#line 459 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: float_string_list any_float STRING
#line 460 "D:/projects/a2llib/src/a2lparser.y"
                                             {yystack_[2].value.as < std::unordered_map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); yylhs.value.as < std::unordered_map<double, std::string> > () = std::move(yystack_[2].value.as < std::unordered_map<double, std::string> > ());  }
#line 2930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_range_list: %empty
#line 462 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: float_range_list any_float any_float STRING
#line 463 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ());
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = std::move(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
	 }
#line 2945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // string_list: %empty
#line 468 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2951 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: string_list STRING
#line 469 "D:/projects/a2llib/src/a2lparser.y"
                             {yystack_[1].value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());}
#line 2957 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // ident_list: %empty
#line 471 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2963 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: ident_list IDENT
#line 472 "D:/projects/a2llib/src/a2lparser.y"
                           {yystack_[1].value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());  }
#line 2969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // key_value_list: %empty
#line 474 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 2975 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: key_value_list IDENT IDENT
#line 475 "D:/projects/a2llib/src/a2lparser.y"
                                     {yystack_[2].value.as < std::unordered_map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ());  }
#line 2981 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 483 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = std::move(yystack_[2].value.as < A2lAnnotation > ());}
#line 2987 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation_attributes: %empty
#line 484 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 2993 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: annotation_attributes annotation_label
#line 485 "D:/projects/a2llib/src/a2lparser.y"
                                              { yystack_[1].value.as < A2lAnnotation > ().Label = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 2999 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_origin
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                                               { yystack_[1].value.as < A2lAnnotation > ().Origin = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_attributes: annotation_attributes annotation_text
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                                             { yystack_[1].value.as < A2lAnnotation > ().Text = std::move(yystack_[0].value.as < std::deque<std::string> > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ());}
#line 3011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 38: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 489 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3017 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 39: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3027 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 40: // ar_component_attribute: %empty
#line 496 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3033 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // ar_component_attribute: ar_prototype_of
#line 497 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3039 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 500 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3053 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // axis_descr_attribute: annotation
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: axis_pts_ref
#line 514 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3065 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: byte_order
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: curve_axis_ref
#line 516 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3077 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: deposit
#line 517 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: extended_limits
#line 518 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3089 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: fix_axis_par
#line 519 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3095 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par_dist
#line 520 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3101 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: fix_axis_par_list
#line 521 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::deque<double> > ()); }
#line 3107 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: format
#line 522 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3113 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: max_grad
#line 523 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3119 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: monotony
#line 524 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3125 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: phys_unit
#line 525 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3131 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: read_only
#line 526 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3137 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: step_size
#line 527 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3143 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 530 "D:/projects/a2llib/src/a2lparser.y"
                                             {
		auto& pts = scanner.CurrentAxisPts();
		pts.Name(yystack_[12].value.as < std::string > ());
		pts.Description(yystack_[11].value.as < std::string > ());
		pts.Address(yystack_[10].value.as < uint64_t > ());
		pts.InputQuantity(yystack_[9].value.as < std::string > ());
		pts.RefRecord(yystack_[8].value.as < std::string > ());
		pts.MaxDiff(yystack_[7].value.as < double > ());
		pts.Conversion(yystack_[6].value.as < std::string > ());
		pts.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
		pts.LowerLimit(yystack_[4].value.as < double > ());
		pts.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3161 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_pts_attribute: annotation
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3167 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: byte_order
#line 546 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3173 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: calibration_access
#line 547 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3179 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: deposit
#line 548 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3185 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: display_identifier
#line 549 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3191 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: ecu_address_extension
#line 550 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3197 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: extended_limits
#line 551 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3203 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: format
#line 552 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3209 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: function_list
#line 553 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3215 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: guard_rails
#line 554 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: if_data
#line 555 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: max_refresh
#line 556 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3233 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: model_link
#line 557 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3239 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: monotony
#line 558 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3245 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: phys_unit
#line 559 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3251 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: read_only
#line 560 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3257 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: ref_memory_segment
#line 561 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3263 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: step_size
#line 562 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: symbol_link
#line 563 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 82: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 565 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3285 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // bit_operation_attribute: left_shift
#line 572 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3291 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // bit_operation_attribute: right_shift
#line 573 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3297 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // bit_operation_attribute: sign_extend
#line 574 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3303 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 576 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 3315 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 91: // blob_attribute: address_type
#line 585 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3321 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: annotation
#line 586 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3327 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: calibration_access
#line 587 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3333 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: display_identifier
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3339 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: ecu_address_extension
#line 589 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3345 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: if_data
#line 590 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3351 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: max_refresh
#line 591 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3357 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: model_link
#line 592 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3363 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: symbol_link
#line 593 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3369 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 595 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lCalibrationHandle > ().Comment = std::move(yystack_[2].value.as < std::string > ());
}
#line 3378 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // calibration_handle_attribute: %empty
#line 599 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3384 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // calibration_handle_attribute: calibration_handle_text
#line 600 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3390 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 603 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = std::move(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = std::move(yystack_[2].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3400 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // calibration_method_attributes: %empty
#line 608 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3406 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 609 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
		yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
		yylhs.value.as < std::deque<A2lCalibrationHandle> > () = std::move(yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3415 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 615 "D:/projects/a2llib/src/a2lparser.y"
                                                         {
	auto& object = scanner.CurrentCharacteristic();
	object.Name(yystack_[11].value.as < std::string > ());
	object.Description(yystack_[10].value.as < std::string > ());
	object.Type(StringToCharacteristicType(yystack_[9].value.as < std::string > ()));
	object.Address(yystack_[8].value.as < uint64_t > ());
	object.Deposit(yystack_[7].value.as < std::string > ());
	object.MaxDiff(yystack_[6].value.as < double > ());
	object.Conversion(yystack_[5].value.as < std::string > ());
	object.LowerLimit(yystack_[4].value.as < double > ());
	object.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3432 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // characteristic_attribute: annotation
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3438 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: axis_descr
#line 630 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3446 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: bit_mask
#line 633 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: byte_order
#line 634 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: calibration_access
#line 635 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: comparison_quantity
#line 636 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: dependent_characteristic
#line 637 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3476 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: discrete
#line 638 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: display_identifier
#line 639 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: ecu_address_extension
#line 640 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: encoding
#line 641 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: extended_limits
#line 642 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: format
#line 643 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3512 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: function_list
#line 644 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: guard_rails
#line 645 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3524 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: if_data
#line 646 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3530 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: map_list
#line 647 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: matrix_dim
#line 648 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 3542 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: max_refresh
#line 649 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3548 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: model_link
#line 650 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: number
#line 651 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: phys_unit
#line 652 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3566 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: read_only
#line 653 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3572 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: ref_memory_segment
#line 654 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3578 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: step_size
#line 655 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3584 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: symbol_link
#line 656 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3590 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: virtual_characteristic
#line 657 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3596 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 136: // compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 659 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 3609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // compu_method_attribute: coeffs
#line 670 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::deque<double> > ()); }
#line 3615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // compu_method_attribute: coeffs_linear
#line 671 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::deque<double> > ()); }
#line 3621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // compu_method_attribute: compu_tab_ref
#line 672 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // compu_method_attribute: formula
#line 673 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3637 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // compu_method_attribute: ref_unit
#line 678 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3643 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_method_attribute: status_string_ref
#line 679 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 145: // compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 682 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::unordered_map<double, double> > ());
	}
#line 3662 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_tab_attribute: default_value
#line 693 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3668 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_tab_attribute: default_value_numeric
#line 694 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3674 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 150: // compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 697 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::unordered_map<double, std::string> > ());
	}
#line 3687 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 153: // compu_vtab_attribute: default_value
#line 707 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3693 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 154: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 710 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 3705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // compu_vtab_range_attribute: default_value
#line 719 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtabRange().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3711 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // controller_address: any_uint IDENT any_uint any_uint
#line 726 "D:/projects/a2llib/src/a2lparser.y"
                                                     {
    A2lControllerAddress address;
    address.Index = yystack_[3].value.as < uint64_t > ();
    address.ByteOrder = StringToByteOrder(yystack_[2].value.as < std::string > ());
    address.StartAddress = yystack_[1].value.as < uint64_t > ();
    address.Length = yystack_[0].value.as < uint64_t > ();
    auto& module = scanner.CurrentModule();
    module.AddControllerAddress(address);
    }
#line 3725 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 736 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 3733 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 163: // def_characteristic: DEF_CHARACTERISTIC ident_list
#line 739 "D:/projects/a2llib/src/a2lparser.y"
                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 3741 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 164: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 744 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 3747 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 165: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 746 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::deque<double> > () = std::move(yystack_[2].value.as < std::deque<double> > ()); }
#line 3753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 166: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 748 "D:/projects/a2llib/src/a2lparser.y"
                                                                    {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()};
    }
#line 3761 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 167: // formula: FORMULA STRING formula_attribute
#line 751 "D:/projects/a2llib/src/a2lparser.y"
                                       {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};
    }
#line 3769 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 168: // formula_attribute: %empty
#line 754 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3775 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 169: // formula_attribute: formula_inv
#line 755 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 3781 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 170: // frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 757 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 3793 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // frame_attribute: frame_measurement
#line 766 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3799 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // frame_attribute: if_data
#line 767 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3805 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 769 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 178: // function_attribute: annotation
#line 776 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3821 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 180: // function_attribute: def_characteristic
#line 778 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3827 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // function_attribute: function_version
#line 779 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3833 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // function_attribute: if_data
#line 780 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3839 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function_attribute: in_measurement
#line 781 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3845 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 184: // function_attribute: loc_measurement
#line 782 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3851 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 185: // function_attribute: out_measurement
#line 783 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // function_attribute: ref_characteristic
#line 784 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3863 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 187: // function_attribute: sub_function
#line 785 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3869 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 787 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3875 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // function_list: FUNCTION_LIST ident_list
#line 788 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3881 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 790 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // group_attribute: annotation
#line 798 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 194: // group_attribute: function_list
#line 799 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // group_attribute: if_data
#line 800 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3909 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // group_attribute: ref_characteristic
#line 801 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // group_attribute: ref_measurement
#line 802 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3921 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // group_attribute: root
#line 803 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 3927 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 199: // group_attribute: sub_group
#line 804 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3933 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 200: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 3942 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // header_attribute: project_no
#line 814 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 3951 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // header_attribute: version
#line 817 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 3960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 822 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
    yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
}
#line 3968 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // in_measurement: IN_MEASUREMENT ident_list
#line 825 "D:/projects/a2llib/src/a2lparser.y"
                            {
      yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
}
#line 3976 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 829 "D:/projects/a2llib/src/a2lparser.y"
                                                                                              {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 3988 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 210: // instance_attribute: address_type
#line 838 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3994 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // instance_attribute: annotation
#line 839 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // instance_attribute: calibration_access
#line 840 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 4006 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // instance_attribute: display_identifier
#line 841 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4012 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // instance_attribute: ecu_address_extension
#line 842 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // instance_attribute: if_data
#line 843 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 216: // instance_attribute: layout
#line 844 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // instance_attribute: matrix_dim
#line 845 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // instance_attribute: max_refresh
#line 846 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 219: // instance_attribute: model_link
#line 847 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // instance_attribute: overwrite
#line 848 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 4055 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // instance_attribute: read_write
#line 850 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 4061 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // instance_attribute: symbol_link
#line 851 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4067 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 853 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4075 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // loc_measurement: LOC_MEASUREMENT ident_list
#line 856 "D:/projects/a2llib/src/a2lparser.y"
                                 {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 860 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 4089 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 863 "D:/projects/a2llib/src/a2lparser.y"
                                                   {
	auto& meas = scanner.CurrentMeasurement();
	meas.Name(yystack_[10].value.as < std::string > ());
	meas.Description(yystack_[9].value.as < std::string > ());
	meas.DataType(StringToDataType(yystack_[8].value.as < std::string > ()));
	meas.Conversion(yystack_[7].value.as < std::string > ());
	meas.Resolution(yystack_[6].value.as < uint64_t > ());
	meas.Accuracy(yystack_[5].value.as < double > ());
	meas.LowerLimit(yystack_[4].value.as < double > ());
	meas.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 4105 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // measurement_attribute: address_type
#line 876 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4111 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // measurement_attribute: annotation
#line 877 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4117 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // measurement_attribute: array_size
#line 878 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4123 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // measurement_attribute: bit_mask
#line 879 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4129 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // measurement_attribute: bit_operation
#line 880 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4135 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement_attribute: byte_order
#line 881 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4141 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 235: // measurement_attribute: discrete
#line 882 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4147 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 236: // measurement_attribute: display_identifier
#line 883 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4153 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: ecu_address
#line 884 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4159 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: ecu_address_extension
#line 885 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4165 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: error_mask
#line 886 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4171 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: format
#line 887 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4177 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: function_list
#line 888 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4183 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: if_data
#line 889 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4189 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // measurement_attribute: layout
#line 890 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4195 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // measurement_attribute: matrix_dim
#line 891 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4201 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // measurement_attribute: max_refresh
#line 892 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // measurement_attribute: model_link
#line 893 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // measurement_attribute: phys_unit
#line 894 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // measurement_attribute: read_write
#line 895 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // measurement_attribute: ref_memory_segment
#line 896 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4231 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // measurement_attribute: symbol_link
#line 897 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4237 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // measurement_attribute: virtual
#line 898 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4243 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 252: // memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes A2L_END MEMORY_LAYOUT
#line 901 "D:/projects/a2llib/src/a2lparser.y"
                                                       {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4255 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 253: // memory_layout: MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes
#line 908 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[1].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[0].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4267 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // memory_layout_attributes: %empty
#line 916 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4273 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // memory_layout_attributes: memory_layout_attributes if_data
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
        }
#line 4282 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // prg_type: RESERVED
#line 922 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4288 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 257: // prg_type: IDENT
#line 923 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4294 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 258: // memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes A2L_END MEMORY_SEGMENT
#line 926 "D:/projects/a2llib/src/a2lparser.y"
                                                         {
	yylhs.value.as < A2lMemorySegment > ().Name = yystack_[10].value.as < std::string > ();
	yylhs.value.as < A2lMemorySegment > ().Description = yystack_[9].value.as < std::string > ();
	yylhs.value.as < A2lMemorySegment > ().SegmentType = yystack_[8].value.as < A2lSegmentType > ();
	yylhs.value.as < A2lMemorySegment > ().MemoryType = StringToMemoryType(yystack_[7].value.as < std::string > ());
	yylhs.value.as < A2lMemorySegment > ().Attribute = StringToMemoryAttribute(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemorySegment > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemorySegment > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemorySegment > ().OffsetList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemorySegment > ().IfDataList = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4310 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // memory_segment: MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes
#line 937 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                {
		yylhs.value.as < A2lMemorySegment > ().Name = yystack_[8].value.as < std::string > ();
    	yylhs.value.as < A2lMemorySegment > ().Description = yystack_[7].value.as < std::string > ();
    	yylhs.value.as < A2lMemorySegment > ().SegmentType = yystack_[6].value.as < A2lSegmentType > ();
    	yylhs.value.as < A2lMemorySegment > ().MemoryType = StringToMemoryType(yystack_[5].value.as < std::string > ());
    	yylhs.value.as < A2lMemorySegment > ().Attribute = StringToMemoryAttribute(yystack_[4].value.as < std::string > ());
    	yylhs.value.as < A2lMemorySegment > ().Address = yystack_[3].value.as < uint64_t > ();
    	yylhs.value.as < A2lMemorySegment > ().Size = yystack_[2].value.as < uint64_t > ();
    	yylhs.value.as < A2lMemorySegment > ().OffsetList = std::move(yystack_[1].value.as < std::deque<int64_t> > ());
    	yylhs.value.as < A2lMemorySegment > ().IfDataList = std::move(yystack_[0].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4326 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 260: // memory_segment_attributes: %empty
#line 948 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4332 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 261: // memory_segment_attributes: memory_segment_attributes if_data
#line 949 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	    yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	    yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4341 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 953 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4350 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 265: // mod_common_attribute: alignment_byte
#line 960 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4356 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 266: // mod_common_attribute: alignment_float16_ieee
#line 961 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 267: // mod_common_attribute: alignment_float32_ieee
#line 962 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // mod_common_attribute: alignment_float64_ieee
#line 963 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4374 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 269: // mod_common_attribute: alignment_int64
#line 964 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4380 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_common_attribute: alignment_long
#line 965 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4386 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 271: // mod_common_attribute: alignment_word
#line 966 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4392 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 272: // mod_common_attribute: byte_order
#line 967 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4398 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_common_attribute: data_size
#line 968 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4404 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_common_attribute: deposit
#line 969 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4410 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 276: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 972 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4419 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 279: // mod_par_attribute: addr_epk
#line 978 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4425 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_par_attribute: calibration_method
#line 979 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_par_attribute: cpu_type
#line 980 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4437 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_par_attribute: customer
#line 981 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4443 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 283: // mod_par_attribute: customer_no
#line 982 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4449 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // mod_par_attribute: ecu
#line 983 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4455 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 285: // mod_par_attribute: ecu_calibration_offset
#line 984 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4461 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 286: // mod_par_attribute: epk
#line 985 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4467 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // mod_par_attribute: memory_layout
#line 986 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4473 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // mod_par_attribute: memory_segment
#line 987 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4479 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // mod_par_attribute: no_of_interfaces
#line 988 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4485 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // mod_par_attribute: phone_no
#line 989 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // mod_par_attribute: supplier
#line 990 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4497 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // mod_par_attribute: system_constant
#line 991 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4503 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // mod_par_attribute: user
#line 992 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // mod_par_attribute: version
#line 993 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4515 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE
#line 995 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
	auto& module = scanner.CurrentModule();
	module.Name(yystack_[4].value.as < std::string > ());
	module.Description(yystack_[3].value.as < std::string > ());
}
#line 4525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // module_attribute: a2ml
#line 1003 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // module_attribute: axis_pts
#line 1004 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 4539 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // module_attribute: blob
#line 1007 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 4547 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 301: // module_attribute: characteristic
#line 1010 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 4555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 302: // module_attribute: compu_method
#line 1013 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 4563 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module_attribute: compu_tab
#line 1016 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 4571 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_attribute: compu_vtab
#line 1019 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 4579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_attribute: compu_vtab_range
#line 1022 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 4587 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 306: // module_attribute: controller_addresses
#line 1025 "D:/projects/a2llib/src/a2lparser.y"
                               {}
#line 4593 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 307: // module_attribute: frame
#line 1026 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 4601 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 308: // module_attribute: function
#line 1029 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 4609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: group
#line 1032 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 4617 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: if_data
#line 1035 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4625 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: instance
#line 1038 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 4633 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 312: // module_attribute: measurement
#line 1041 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 4641 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 315: // module_attribute: record_layout
#line 1046 "D:/projects/a2llib/src/a2lparser.y"
                        {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
#line 4649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 316: // module_attribute: transformer
#line 1049 "D:/projects/a2llib/src/a2lparser.y"
                      {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
#line 4657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // module_attribute: typedef_axis
#line 1052 "D:/projects/a2llib/src/a2lparser.y"
                       {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
#line 4665 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // module_attribute: typedef_blob
#line 1055 "D:/projects/a2llib/src/a2lparser.y"
                       {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
#line 4673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // module_attribute: typedef_characteristic
#line 1058 "D:/projects/a2llib/src/a2lparser.y"
                                 {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
#line 4681 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // module_attribute: typedef_measurement
#line 1061 "D:/projects/a2llib/src/a2lparser.y"
                              {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
#line 4689 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // module_attribute: typedef_structure
#line 1064 "D:/projects/a2llib/src/a2lparser.y"
                            {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
#line 4697 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // module_attribute: unit
#line 1067 "D:/projects/a2llib/src/a2lparser.y"
               {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
#line 4705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // module_attribute: user_rights
#line 1070 "D:/projects/a2llib/src/a2lparser.y"
                      {
          auto& module = scanner.CurrentModule();
          module.AddUserRights(scanner.ReleaseUserRights()); }
#line 4713 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 325: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1075 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4721 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 326: // out_measurement: OUT_MEASUREMENT ident_list
#line 1078 "D:/projects/a2llib/src/a2lparser.y"
                                 {
       yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4729 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 327: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1082 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4739 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 330: // overwrite_attribute: conversion
#line 1089 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4745 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 331: // overwrite_attribute: extended_limits
#line 1090 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4751 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 332: // overwrite_attribute: format
#line 1091 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4757 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 333: // overwrite_attribute: input_quantity
#line 1092 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4763 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 334: // overwrite_attribute: limits
#line 1093 "D:/projects/a2llib/src/a2lparser.y"
                 {
	    scanner.CurrentOverwrite().LowerLimit(yystack_[0].value.as < A2lLimits > ().LowerLimit);
	    scanner.CurrentOverwrite().UpperLimit(yystack_[0].value.as < A2lLimits > ().UpperLimit);
	    }
#line 4772 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 335: // overwrite_attribute: monotony
#line 1097 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4778 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 336: // overwrite_attribute: phys_unit
#line 1098 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 337: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1100 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4794 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 341: // project_attribute: module
#line 1110 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 4803 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 342: // record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT
#line 1115 "D:/projects/a2llib/src/a2lparser.y"
                                                                                            {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 4812 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // record_layout_attribute: alignment_byte
#line 1121 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 4818 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 346: // record_layout_attribute: alignment_float16_ieee
#line 1122 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 4824 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 347: // record_layout_attribute: alignment_float32_ieee
#line 1123 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 4830 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 348: // record_layout_attribute: alignment_float64_ieee
#line 1124 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 4836 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 349: // record_layout_attribute: alignment_int64
#line 1125 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 4842 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 350: // record_layout_attribute: alignment_long
#line 1126 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 4848 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 351: // record_layout_attribute: alignment_word
#line 1127 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 4854 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // record_layout_attribute: axis_pts_x
#line 1128 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4860 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 353: // record_layout_attribute: axis_pts_y
#line 1129 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4866 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 354: // record_layout_attribute: axis_pts_z
#line 1130 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4872 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 355: // record_layout_attribute: axis_pts_4
#line 1131 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4878 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: axis_pts_5
#line 1132 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: axis_rescale_x
#line 1133 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 4890 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: dist_op_x
#line 1134 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4896 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: dist_op_y
#line 1135 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4902 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: dist_op_z
#line 1136 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4908 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: dist_op_4
#line 1137 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4914 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: dist_op_5
#line 1138 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4920 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: fix_no_axis_pts_x
#line 1139 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 4926 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: fix_no_axis_pts_y
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 4932 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: fix_no_axis_pts_z
#line 1141 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 4938 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: fix_no_axis_pts_4
#line 1142 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 4944 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: fix_no_axis_pts_5
#line 1143 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 4950 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: fnc_values
#line 1144 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 4956 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: identification
#line 1145 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 4962 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: no_axis_pts_x
#line 1146 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4968 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: no_axis_pts_y
#line 1147 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: no_axis_pts_z
#line 1148 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: no_axis_pts_4
#line 1149 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: no_axis_pts_5
#line 1150 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4992 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: no_rescale_x
#line 1151 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4998 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: offset_x
#line 1152 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5004 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: offset_y
#line 1153 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5010 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: offset_z
#line 1154 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5016 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: offset_4
#line 1155 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5022 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: offset_5
#line 1156 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5028 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: reserved
#line 1157 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 5034 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: rip_addr_w
#line 1158 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 5040 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: rip_addr_x
#line 1159 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5046 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: rip_addr_y
#line 1160 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5052 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: rip_addr_z
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5058 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: rip_addr_4
#line 1162 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5064 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // record_layout_attribute: rip_addr_5
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5070 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // record_layout_attribute: src_addr_x
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5076 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // record_layout_attribute: src_addr_y
#line 1165 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5082 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // record_layout_attribute: src_addr_z
#line 1166 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5088 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 391: // record_layout_attribute: src_addr_4
#line 1167 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5094 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 392: // record_layout_attribute: src_addr_5
#line 1168 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5100 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // record_layout_attribute: shift_op_x
#line 1169 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5106 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // record_layout_attribute: shift_op_y
#line 1170 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5112 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // record_layout_attribute: shift_op_z
#line 1171 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5118 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // record_layout_attribute: shift_op_4
#line 1172 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5124 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // record_layout_attribute: shift_op_5
#line 1173 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5130 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // record_layout_attribute: static_address_offsets
#line 1174 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5136 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // record_layout_attribute: static_record_layout
#line 1175 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5142 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 400: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5150 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 401: // ref_characteristic: REF_CHARACTERISTIC ident_list
#line 1180 "D:/projects/a2llib/src/a2lparser.y"
                                    {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5158 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1183 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5164 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5170 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1187 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = std::move(yystack_[5].value.as < std::string > ());
        structure.Typedef = yystack_[4].value.as < std::string > ();
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5181 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 407: // structure_component_attribute: address_type
#line 1195 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5187 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 408: // structure_component_attribute: layout
#line 1196 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 409: // structure_component_attribute: matrix_dim
#line 1197 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // structure_component_attribute: symbol_type_link
#line 1198 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
                                                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // sub_function: SUB_FUNCTION ident_list
#line 1203 "D:/projects/a2llib/src/a2lparser.y"
                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 413: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1207 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 414: // transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1210 "D:/projects/a2llib/src/a2lparser.y"
                                                   {
	auto& transformer = scanner.CurrentTransformer();
	transformer.Name(yystack_[9].value.as < std::string > ());
	transformer.Version(yystack_[8].value.as < std::string > ());
	transformer.Executable32(yystack_[7].value.as < std::string > ());
	transformer.Executable64(yystack_[6].value.as < std::string > ());
	transformer.Timeout(yystack_[5].value.as < uint64_t > ());
	transformer.Trigger(StringToTrigger(yystack_[4].value.as < std::string > ()));
	transformer.InverseTransformer(yystack_[3].value.as < std::string > ());
	}
#line 5242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 417: // transformer_attribute: transformer_in_objects
#line 1222 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 418: // transformer_attribute: transformer_out_objects
#line 1223 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5254 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 419: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1225 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5260 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1226 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5266 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 421: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1229 "D:/projects/a2llib/src/a2lparser.y"
                                                     {
		auto& pts = scanner.CurrentTypedefAxis();
		pts.Name(yystack_[11].value.as < std::string > ());
		pts.Description(yystack_[10].value.as < std::string > ());
		pts.InputQuantity(yystack_[9].value.as < std::string > ());
		pts.RefRecord(yystack_[8].value.as < std::string > ());
		pts.MaxDiff(yystack_[7].value.as < double > ());
		pts.Conversion(yystack_[6].value.as < std::string > ());
		pts.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
		pts.LowerLimit(yystack_[4].value.as < double > ());
		pts.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 5283 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 424: // typedef_axis_attribute: byte_order
#line 1243 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5289 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 425: // typedef_axis_attribute: deposit
#line 1244 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5295 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 426: // typedef_axis_attribute: extended_limits
#line 1245 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5301 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 427: // typedef_axis_attribute: format
#line 1246 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5307 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 428: // typedef_axis_attribute: monotony
#line 1247 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5313 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // typedef_axis_attribute: phys_unit
#line 1248 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5319 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // typedef_axis_attribute: step_size
#line 1249 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5325 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1251 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                        {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5336 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 434: // typedef_blob_attribute: address_type
#line 1259 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5342 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 435: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1262 "D:/projects/a2llib/src/a2lparser.y"
                                                                         {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.Name(yystack_[10].value.as < std::string > ());
        object.Description(yystack_[9].value.as < std::string > ());
        object.Type(StringToCharacteristicType(yystack_[8].value.as < std::string > ()));
        object.Deposit(yystack_[7].value.as < std::string > ());
        object.MaxDiff(yystack_[6].value.as < double > ());
        object.Conversion(yystack_[5].value.as < std::string > ());
        object.LowerLimit(yystack_[4].value.as < double > ());
        object.UpperLimit(yystack_[3].value.as < double > ());
        }
#line 5358 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_characteristic_attribute: axis_descr
#line 1275 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5367 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 439: // typedef_characteristic_attribute: bit_mask
#line 1279 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5373 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 440: // typedef_characteristic_attribute: byte_order
#line 1280 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5379 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 441: // typedef_characteristic_attribute: discrete
#line 1281 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5385 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 442: // typedef_characteristic_attribute: encoding
#line 1282 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5391 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 443: // typedef_characteristic_attribute: extended_limits
#line 1283 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5397 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 444: // typedef_characteristic_attribute: format
#line 1284 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5403 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_characteristic_attribute: matrix_dim
#line 1285 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5409 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 446: // typedef_characteristic_attribute: number
#line 1286 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5415 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 447: // typedef_characteristic_attribute: phys_unit
#line 1287 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5421 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 448: // typedef_characteristic_attribute: step_size
#line 1288 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5427 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 449: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT UINT any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1291 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    auto& meas = scanner.CurrentTypedefMeasurement();
    meas.Name(yystack_[10].value.as < std::string > ());
    meas.Description(yystack_[9].value.as < std::string > ());
    meas.DataType(StringToDataType(yystack_[8].value.as < std::string > ()));
    meas.Conversion(yystack_[7].value.as < std::string > ());
    meas.Resolution(yystack_[6].value.as < uint64_t > ());
    meas.Accuracy(yystack_[5].value.as < double > ());
    meas.LowerLimit(yystack_[4].value.as < double > ());
    meas.UpperLimit(yystack_[3].value.as < double > ());
    }
#line 5443 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_measurement_attribute: address_type
#line 1304 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5449 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 453: // typedef_measurement_attribute: bit_mask
#line 1305 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5455 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 454: // typedef_measurement_attribute: bit_operation
#line 1306 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5461 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 455: // typedef_measurement_attribute: byte_order
#line 1307 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5467 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 456: // typedef_measurement_attribute: discrete
#line 1308 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5473 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // typedef_measurement_attribute: error_mask
#line 1309 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5479 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // typedef_measurement_attribute: format
#line 1310 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5485 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // typedef_measurement_attribute: layout
#line 1311 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 460: // typedef_measurement_attribute: matrix_dim
#line 1312 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5497 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 461: // typedef_measurement_attribute: phys_unit
#line 1313 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5503 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 462: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING UINT typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1316 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5514 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // typedef_structure_attribute: address_type
#line 1324 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5520 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 466: // typedef_structure_attribute: consistent_exchange
#line 1325 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5526 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 467: // typedef_structure_attribute: structure_component
#line 1326 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5534 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 468: // typedef_structure_attribute: symbol_type_link
#line 1329 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5540 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1331 "D:/projects/a2llib/src/a2lparser.y"
                                                                            {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5552 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // unit_attribute: ref_unit
#line 1340 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5558 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 473: // unit_attribute: si_exponents
#line 1341 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5564 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 474: // unit_attribute: unit_conversion
#line 1342 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 475: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1347 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_rights = scanner.CurrentUserRights();
       user_rights.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5582 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // user_rights_attribute: read_only
#line 1353 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRights().ReadOnly = true; }
#line 5588 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 479: // user_rights_attribute: ref_group
#line 1354 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRights().RefGroupList.emplace_back(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5594 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 480: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1356 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 481: // var_address: VAR_ADDRESS uint_list
#line 1359 "D:/projects/a2llib/src/a2lparser.y"
                            {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ());
    }
#line 5610 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 482: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1364 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = std::move(yystack_[3].value.as < std::deque<std::string> > ());
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5620 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // var_characteristic_attribute: %empty
#line 1369 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // var_characteristic_attribute: var_address
#line 1370 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1372 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCriterion > ().Description = std::move(yystack_[3].value.as < std::string > ());
}
#line 5643 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // var_criterion_attribute: var_measurement
#line 1381 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = std::move(yystack_[0].value.as < std::string > ()); }
#line 5649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // var_criterion_attribute: var_selection_characteristic
#line 1382 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = std::move(yystack_[0].value.as < std::string > ()); }
#line 5655 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1384 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ()); }
#line 5661 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 494: // variant_coding_attribute: var_characteristic
#line 1389 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5670 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 495: // variant_coding_attribute: var_criterion
#line 1393 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5679 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 496: // variant_coding_attribute: var_forbidden_comb
#line 1397 "D:/projects/a2llib/src/a2lparser.y"
                             {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(yystack_[0].value.as < std::unordered_map<std::string, std::string> > ());
       }
#line 5688 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 497: // variant_coding_attribute: var_naming
#line 1401 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = std::move(yystack_[0].value.as < std::string > ());
       }
#line 5697 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // variant_coding_attribute: var_separator
#line 1405 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = std::move(yystack_[0].value.as < std::string > ());
      }
#line 5706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1410 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5714 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // virtual: VIRTUAL ident_list
#line 1413 "D:/projects/a2llib/src/a2lparser.y"
                         {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5722 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1417 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 5728 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 502: // a2ml: A2ML
#line 1420 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5734 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 503: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1421 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5743 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1426 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5752 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // asap2_version: ASAP2_VERSION STRING
#line 1429 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // addr_epk: ADDR_EPK any_uint
#line 1433 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5766 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // address_type: ADDRESS_TYPE IDENT
#line 1434 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5772 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1435 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5778 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1436 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1437 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5790 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1438 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5796 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1439 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5802 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // alignment_long: ALIGNMENT_LONG any_uint
#line 1440 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5808 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // alignment_word: ALIGNMENT_WORD any_uint
#line 1441 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5814 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // annotation_label: ANNOTATION_LABEL STRING
#line 1442 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5820 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1443 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5826 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // array_size: ARRAY_SIZE any_uint
#line 1444 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5832 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1445 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 5838 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1446 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5844 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1447 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1453 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5866 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1459 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5877 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 523: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1465 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1471 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5899 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1477 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5911 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // bit_mask: BIT_MASK any_uint
#line 1484 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5917 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 527: // byte_order: A2L_BYTE_ORDER IDENT
#line 1485 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 5923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1486 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 5929 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1487 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5935 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1488 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	std::deque<double> list;
	list.emplace_back(yystack_[5].value.as < double > ());
	list.emplace_back(yystack_[4].value.as < double > ());
	list.emplace_back(yystack_[3].value.as < double > ());
	list.emplace_back(yystack_[2].value.as < double > ());
    list.emplace_back(yystack_[1].value.as < double > ());
    list.emplace_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::deque<double> > () = std::move(list);
}
#line 5950 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1498 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::deque<double> list;
	list.emplace_back(yystack_[1].value.as < double > ());
	list.emplace_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::deque<double> > () = std::move(list);
       }
#line 5961 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1504 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5967 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 533: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1505 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5973 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // conversion: CONVERSION IDENT
#line 1507 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5979 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // cpu_type: CPU_TYPE STRING
#line 1508 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5985 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1509 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5991 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // customer: CUSTOMER STRING
#line 1510 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5997 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // customer_no: CUSTOMER_NO STRING
#line 1511 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6003 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // data_size: DATA_SIZE any_uint
#line 1512 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6009 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // default_value: DEFAULT_VALUE STRING
#line 1513 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6015 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1514 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6021 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // deposit: DEPOSIT IDENT
#line 1515 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 6027 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1517 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6033 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1518 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());}
#line 6039 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 547: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1519 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1523 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6057 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1527 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6066 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1531 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6075 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1535 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // ecu: ECU STRING
#line 1539 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // ecu_address: ECU_ADDRESS any_uint
#line 1540 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1541 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 555: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1542 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6108 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // encoding: ENCODING IDENT
#line 1543 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 6114 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // epk: EPK STRING
#line 1544 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6120 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // error_mask: ERROR_MASK any_uint
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6126 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1546 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 6132 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1547 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6138 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1548 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6144 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1549 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6150 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1550 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6156 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1551 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6162 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1552 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6168 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1553 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6174 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1554 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6185 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // format: FORMAT STRING
#line 1560 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6191 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // formula_inv: FORMULA_INV STRING
#line 1561 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6197 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1562 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 6203 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // function_version: FUNCTION_VERSION STRING
#line 1563 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6209 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // identification: IDENTIFICATION any_uint IDENT
#line 1565 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6218 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // if_data: IF_DATA
#line 1569 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6224 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 575: // input_quantity: INPUT_QUANTITY IDENT
#line 1570 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6230 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // layout: LAYOUT IDENT
#line 1571 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6236 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // left_shift: LEFT_SHIFT any_uint
#line 1572 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // limits: LIMITS any_float any_float
#line 1573 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < A2lLimits > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()}; }
#line 6248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // matrix_dim: MATRIX_DIM uint_list
#line 1574 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 6254 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // max_grad: MAX_GRAD any_float
#line 1575 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6260 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1576 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6266 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // model_link: MODEL_LINK STRING
#line 1577 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6272 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // monotony: MONOTONY IDENT
#line 1578 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6278 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1579 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1583 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6296 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1587 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1591 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6314 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1595 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1599 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1600 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6338 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 591: // number: NUMBER any_uint
#line 1604 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6344 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 592: // offset_x: OFFSET_X any_uint IDENT
#line 1605 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6353 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // offset_y: OFFSET_Y any_uint IDENT
#line 1609 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // offset_z: OFFSET_Z any_uint IDENT
#line 1613 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6371 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // offset_4: OFFSET_4 any_uint IDENT
#line 1617 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6380 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // offset_5: OFFSET_5 any_uint IDENT
#line 1621 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 597: // phone_no: PHONE_NO STRING
#line 1625 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 598: // phys_unit: PHYS_UNIT STRING
#line 1626 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // proj_no: IDENT
#line 1627 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // proj_no: UINT
#line 1628 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6413 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // project_no: PROJECT_NO proj_no
#line 1629 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6419 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 604: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1633 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6425 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 605: // ref_unit: REF_UNIT IDENT
#line 1634 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 606: // reserved: RESERVED any_uint IDENT
#line 1635 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
    yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    }
#line 6440 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // right_shift: RIGHT_SHIFT any_uint
#line 1639 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6446 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1640 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6455 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1644 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 610: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1648 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6473 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 611: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1652 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 612: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1656 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 613: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1660 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1666 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 617: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1670 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 618: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1674 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6527 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1678 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1682 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6545 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1687 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6559 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1696 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6568 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 624: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1700 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6577 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 625: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1704 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6586 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 626: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1708 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6595 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1712 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6604 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 630: // status_string_ref: STATUS_STRING_REF IDENT
#line 1718 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6610 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 631: // step_size: STEP_SIZE any_float
#line 1719 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6616 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 632: // supplier: SUPPLIER STRING
#line 1720 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6622 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 633: // symbol_link: SYMBOL_LINK STRING any_int
#line 1721 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6628 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 634: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1722 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6634 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 635: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1723 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6640 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 636: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1724 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6646 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 637: // user: USER STRING
#line 1725 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6652 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 638: // var_measurement: VAR_MEASUREMENT IDENT
#line 1726 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6658 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 639: // var_naming: VAR_NAMING IDENT
#line 1727 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6664 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 640: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1728 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6670 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 641: // var_separator: VAR_SEPARATOR STRING
#line 1729 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6676 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 642: // version: A2L_VERSION STRING
#line 1730 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6682 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6686 "D:/projects/a2llib/src/a2lparser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  A2lParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if A2LDEBUG || 0
  const char *
  A2lParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if A2LDEBUG || 0









  const short A2lParser::yypact_ninf_ = -925;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
     103,   207,   130,   128,  -925,  -925,  -925,  -925,   299,  -925,
       1,   299,  -925,  -925,  -925,   196,   299,   208,  -925,   216,
      -2,  -925,  -925,    62,  -925,   223,   276,   144,  -925,  -925,
     284,  -925,    49,  -925,   210,   288,   165,  -925,  -925,  -925,
      60,  -925,  -925,  -925,  -925,  -925,   834,   212,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   333,   339,
     347,   354,   359,   371,   393,  -925,   396,   404,   416,   418,
     420,   407,   427,   421,   429,   430,   433,   435,   437,   438,
     439,   440,  -925,  -925,   443,   445,   448,   449,   453,   456,
     457,   294,   458,   461,   464,   465,   466,  -925,  -925,  -925,
     467,   472,   476,   479,   482,   485,   486,  -925,    79,   299,
     299,   488,   490,   491,   492,   299,   411,   493,  -925,   299,
    -925,  -925,   494,   495,   901,   298,  1030,   496,   498,   299,
     499,   500,   501,   504,    47,   116,   300,   506,   509,  -925,
    -925,  -925,  -925,  -925,  -925,   507,   299,   299,   511,   299,
     299,  -925,  -925,   299,   299,   463,    56,   299,   515,   400,
     299,   299,   299,   299,   299,   299,   299,   516,   299,   519,
     522,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,    19,   406,   299,   529,   530,   531,   534,
     311,   536,   540,   542,   299,   543,   544,   547,   549,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,   401,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   551,   553,  -925,   555,   556,  -925,   557,   414,   377,
    -925,  -925,  -925,  -925,   560,   570,  -925,  -925,  -925,  -925,
     572,  -925,   573,   574,  -925,  -925,   190,   299,  -925,   280,
     487,  -925,   575,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   272,
     497,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   299,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,   578,   582,   584,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   299,
     587,  -925,  -925,  -925,   588,  -925,  -925,   590,   591,   593,
     596,   598,   599,   600,   605,   607,   613,   615,  -925,  -925,
    -925,  -925,  -925,   617,   618,   620,   621,   623,   626,   627,
     628,   629,   633,   635,   639,   640,   645,   647,   650,   653,
     654,   657,   658,   659,   661,   664,   665,   666,   667,   668,
     669,   672,   673,   299,   190,   115,   190,   608,    39,  -925,
    -925,  -925,  -925,   677,    89,   190,   324,   190,  -925,   190,
     190,  -925,  -925,  -925,  -925,   190,    87,  -925,    51,  -925,
     679,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   674,  -925,
     674,   674,   674,   674,   674,  -925,  -925,  -925,  -925,   674,
     408,   190,   299,   299,   680,   299,    41,  -925,   684,   692,
     697,   698,   699,   299,  -925,  -925,  -925,  -925,  -925,   703,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   704,
     711,   528,   714,  -925,  -925,   715,   190,   545,   537,  -925,
     721,  -925,  -925,  -925,  -925,  -925,     7,   319,    32,  -925,
     532,   724,   727,    55,   693,   729,   731,   311,   299,   736,
     737,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   732,   382,   190,   129,   739,    92,   740,   700,   743,
    -925,  -925,   655,  -925,  -925,  -925,  -925,    96,   725,   320,
     326,   327,   331,   336,   344,  -925,   364,   376,   383,    14,
     648,   749,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   190,  -925,
     299,    41,  -925,  -925,  -925,   753,   755,   758,   759,   764,
     765,   768,   771,   773,   299,  -925,  -925,   190,   190,   774,
    -925,  -925,   580,   777,   311,   190,  -925,  -925,  -925,  -925,
     634,   589,  -925,  -925,   782,    81,  -925,  -925,   299,   783,
    -925,  -925,  -925,  -925,   299,  -925,   311,   190,   705,   741,
     190,   190,   793,   797,   799,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,   752,   190,  -925,  -925,  -925,  -925,   756,
    -925,  -925,  -925,  -925,  -925,  -925,   674,   780,   786,   808,
     810,  -925,  -925,  -925,   812,   815,  -925,   760,   716,   713,
     685,   681,   651,   733,   686,   656,   829,  -925,  -925,   299,
     190,   121,  -925,   830,   311,   837,  -925,  -925,  -925,  -925,
    -925,   838,  -925,  -925,   190,   190,   190,   839,  -925,  -925,
     311,   190,  -925,  -925,   299,   646,   652,   846,   850,  -925,
    -925,  -925,   190,   853,  -925,  -925,   190,   852,  -925,   190,
     190,  -925,   763,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   831,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   299,  -925,  -925,   816,   817,  -925,   311,   860,
    -925,   761,   299,  -925,   368,   190,  -925,  -925,   299,   311,
    -925,   303,  -925,  -925,  -925,  -925,   190,   798,  -925,   763,
     190,  -925,   862,  -925,  -925,   171,  -925,  -925,   473,  -925,
    -925,    36,   299,  -925,   299,   228,   687,  -925,  -925,  -925,
    -925,   769,   611,  -925,   311,   682,  -925,  -925,   644,   868,
     190,  -925,   848,  -925,   707,    12,   767,   299,   299,  -925,
     299,   299,   871,   872,   876,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
      97,   772,   299,  -925,  -925,  -925,  -925,   523,   857,   702,
     878,   190,   299,   190,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,   856,   708,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,    40,
     311,  -925,   696,    20,   858,   889,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,   813,   190,  -925,   770,   900,
     902,   190,   904,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   674,   906,   910,  -925,  -925,  -925,   311,   386,   387,
     726,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   909,
    -925,  -925,   190,  -925,  -925,  -925,   738,  -925,  -925,  -925,
    -925,  -925,   311,    69,   884,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,   919,  -925,   920,  -925,  -925,
    -925,   190,  -925,  -925,  -925,   190,  -925,    37,   391,  -925,
     882,   311,   761,   742,   746,  -925,   923,  -925,  -925,   311,
    -925,  -925,   399,  -925,  -925,  -925,   894,   299,   299,  -925,
    -925,  -925,  -925,  -925,   730,  -925,    57,  -925,  -925,  -925,
     933,  -925,   402,   825,   403,  -925,  -925,  -925,  -925,   821,
     299,   877,  -925,   745,  -925,   190,  -925,  -925,   190,  -925,
     606,    73,   917,   944,   945,   190,   190,   190,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   190,   190,
    -925,   224,   299,   299,   864,  -925,  -925,  -925,  -925
  };

  const short
  A2lParser::yydefact_[] =
  {
      30,     0,     0,     0,    31,   505,     2,     3,     0,     1,
       0,     0,    29,    32,   504,     0,     0,     0,   503,     0,
       0,   340,   341,     0,   338,     0,     0,     0,   339,   201,
       0,   337,     0,   296,     0,     0,     0,   202,   203,   204,
       0,   200,   642,   599,   600,   601,     0,     0,   502,   574,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   311,   312,   313,   314,   297,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   298,   310,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,   277,   343,
       0,     0,     0,     0,     0,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
     176,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
     495,   496,   493,   497,   498,     0,     0,     0,     0,     0,
       0,    21,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   280,
     287,   288,   278,   279,   281,   282,   283,   284,   285,   286,
     289,   290,   291,   292,   293,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   628,   629,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   393,
     394,   395,   396,   397,   388,   389,   390,   391,   392,   398,
     399,     0,     0,   432,     0,     0,   463,     0,     0,     0,
     602,   479,   477,   478,     0,     0,    27,   491,   639,   641,
       0,    89,     0,     0,    17,    19,   155,     0,   171,     0,
       0,    25,     0,    25,    25,    25,    25,    25,   178,   179,
     180,   177,   183,   184,   185,   186,   187,   181,   182,     0,
       0,    25,   614,   193,   194,   192,   196,   197,   199,   195,
     198,   208,     0,   262,   508,   509,   510,   511,   512,   513,
     514,   527,   540,   543,   615,     0,     0,     0,   276,   506,
     536,   538,   539,   552,     4,     5,     6,   555,   557,     0,
       0,   589,   597,   632,     0,   637,   342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   562,   563,
     564,   565,   566,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
      25,   475,    25,     0,     0,     0,     0,     0,   137,   146,
     151,     8,     9,    10,     7,     0,     0,   161,     0,    34,
       0,    25,    25,    25,    25,    25,    25,   175,   163,   571,
     206,   224,   326,   401,   412,    25,    25,    25,   190,   189,
       0,     0,     0,     0,     0,     0,     0,   635,     0,     0,
       0,     0,     0,     0,   547,   548,   549,   550,   551,     0,
     573,   584,   585,   586,   587,   588,   590,   592,   593,   594,
     595,   596,   606,   608,   609,   610,   611,   612,   613,   616,
     617,   618,   619,   620,   623,   624,   625,   626,   627,     0,
       0,     0,     0,   433,   434,     0,     0,     0,     0,   534,
       0,   467,   464,   465,   466,   468,     0,     0,   483,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    90,    91,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,     0,    25,   172,   173,   174,     0,    40,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,    13,   603,   211,   209,   220,   210,   212,   213,
     214,   215,   216,   217,   218,   219,   221,   222,     0,   104,
       0,     0,    11,   257,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,   507,     0,     0,     0,
     462,   634,     0,     0,     0,     0,   471,   472,   473,   474,
       0,     0,    13,   484,     0,     0,   490,    28,     0,     0,
      88,   528,   545,   554,     0,   582,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   142,   139,   140,   141,
     143,   144,    18,     0,     0,   147,   148,   149,    20,     0,
     152,   153,    22,   154,   541,   170,   570,     0,     0,     0,
       0,    37,    35,    36,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   207,   576,   579,
       0,     0,    11,     0,   254,     0,   520,   521,   522,   523,
     524,     0,   567,   415,     0,     0,     0,     0,   469,   605,
       0,     0,   402,    13,   481,     0,     0,     0,     0,   487,
     488,   489,     0,     0,   581,   633,     0,     0,   136,     0,
       0,   533,   168,   630,   145,   542,   150,    23,    33,   515,
     516,   518,     0,   162,   205,   223,   325,   400,   411,   188,
     403,   413,     0,    14,   227,     0,     0,   105,   254,     0,
      12,   253,     0,   525,     0,     0,   436,   450,     0,     0,
     636,     0,   482,   485,   638,   640,     0,     0,   107,   168,
       0,   531,     0,   167,   169,     0,    39,   328,     0,    11,
     103,     0,     0,   255,     0,     0,     0,   416,   417,   418,
     422,     0,     0,   405,     0,     0,    61,   546,     0,     0,
       0,   569,     0,    24,     0,     0,     0,     0,     0,   544,
       0,     0,     0,     0,     0,    25,   230,   233,   241,   228,
     251,   229,   231,   232,   234,   235,   236,   237,   238,   239,
     240,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     101,     0,     0,    11,    25,    25,   414,     0,     0,     0,
       0,     0,     0,     0,   438,   437,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,     0,     0,   454,   451,
     452,   453,   455,   456,   457,   458,   459,   460,   461,     0,
       0,   480,     0,     0,     0,     0,   572,   109,   110,   108,
     115,   122,   125,   135,   111,   112,   113,   114,   116,   117,
     118,   119,   120,   121,   123,   124,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,    38,     0,     0,
       0,     0,     0,   329,   330,   331,   332,   333,   334,   335,
     336,    83,    25,   226,   517,   526,   553,   558,   568,   598,
     604,   500,     0,     0,   102,   252,    11,   260,     0,     0,
       0,   423,   424,   425,   426,   427,   428,   429,   430,     0,
     435,   556,     0,   591,   631,   449,     0,   406,   407,   408,
     409,   410,     0,     0,     0,    63,    62,    71,    64,    65,
      66,    67,    68,    69,    70,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,    25,     0,   106,   532,
     166,     0,   327,   535,   575,     0,   583,     0,     0,   529,
       0,   260,   259,     0,     0,   421,     0,   559,   404,     0,
      60,    25,     0,    25,   530,   578,     0,     0,     0,   621,
      84,    85,    86,    87,     0,   100,     0,   261,   419,   420,
       0,   622,     0,     0,     0,    82,   577,   607,   499,     0,
       0,     0,   225,     0,   258,     0,   164,   501,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    44,
      53,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      56,    57,    58,    59,    15,    42,   519,   537,     0,     0,
     580,     0,     0,     0,     0,    16,   560,   561,   165
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -925,    -1,  -207,  -148,  -743,  -676,  -925,  -925,  -925,  -925,
    -925,  -304,  -925,  -925,  -925,  -174,  -925,  -925,  -925,  -925,
      67,  -925,  -925,  -925,  -925,  -925,    74,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   100,  -925,
    -925,  -925,  -925,  -925,  -925,  -810,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   122,   290,  -925,  -139,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   940,  -925,  -925,  -925,   788,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -484,   819,   822,   823,   824,
     826,   827,   828,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -735,  -860,  -521,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -211,
    -925,  -924,  -582,  -525,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -524,  -925,    90,  -925,    85,  -861,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -863,  -925,  -925,  -925,     3,
    -925,   -39,  -925,  -778,  -925,  -925,  -780,  -925,  -514,  -513,
    -923,  -925,  -925,  -925,  -925,  -925,  -925,  -925,    91,  -925,
    -925,  -925,  -925,  -925,  -925,  -858,  -925,  -925,  -854,   109,
    -820,   358,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -856,  -925,  -510,
      15,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   836
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   833,   840,   505,   774,   769,  1181,   499,   500,   366,
     865,   518,   494,     2,     3,   378,   637,   751,   379,   755,
     944,  1150,  1159,    50,   972,  1066,   907,  1097,  1120,    51,
     496,   612,   837,  1033,   219,   771,    52,   888,   979,    53,
     622,   725,    54,   624,   735,    55,   626,   740,    56,   506,
     630,    57,   111,   138,   380,   980,  1160,   726,   863,    58,
     508,   634,    59,   175,   381,   394,    60,   176,   395,    21,
      32,    37,   382,    61,   530,   655,   383,   982,    62,   868,
     909,   220,   841,   675,   221,  1102,    63,   144,   191,    64,
     145,   222,    22,    40,    65,   384,   656,   894,  1013,    12,
      23,    24,    66,   146,   285,   385,   351,   397,   591,   969,
    1057,   386,   398,    67,   844,   877,   878,   879,    68,   937,
    1041,    69,   485,   583,    70,   881,   945,    71,   882,   959,
      72,   488,   592,    73,   596,   696,    74,   154,   352,   703,
     159,   704,   160,   705,   799,   161,    75,   128,   162,   910,
     983,    76,    13,     4,   223,   584,   192,   193,   194,   195,
     196,   197,   198,   752,   753,   912,   756,  1161,   293,   294,
     295,   296,   297,   298,   913,   199,   614,  1034,   727,   728,
     987,   729,   594,  1014,   224,  1163,   225,   226,   200,   631,
     737,   201,   915,   615,   299,   300,   301,   302,   303,   227,
     917,   616,   228,   949,   229,   919,   950,  1166,  1167,   304,
     305,   306,   307,   308,   309,   920,   864,   635,   387,   994,
     310,   873,  1017,   662,  1121,  1018,   663,  1169,   618,   619,
    1019,   311,   312,   313,   314,   315,   230,   316,   953,   317,
     318,   319,   320,   321,   231,   926,    45,    38,   353,   666,
     928,   697,   322,  1122,   323,   324,   325,   326,   327,   328,
     400,   202,   329,   330,   331,   332,   333,  1123,   698,   334,
     335,   336,   337,   338,   339,   340,   731,   955,   232,   620,
     595,   233,   699,   234,   800,   163,   801,   164,    39
  };

  const short
  A2lParser::yytable_[] =
  {
       8,    77,   393,   427,   593,   659,   660,    14,   914,   658,
      16,   692,   613,  1043,  1046,    18,   664,   665,   951,   965,
     667,   947,   962,   954,   968,   993,   794,   992,   985,   838,
    1000,  1016,  1003,  1015,  1001,   701,  1020,   509,   645,   509,
     931,  1116,   587,   588,  1056,   509,   657,   673,  1070,  1079,
     348,   349,  1049,    34,  1021,   632,   582,   582,   908,   389,
     390,  1139,    35,    46,    47,    20,    27,   415,  1002,   520,
     521,   522,   523,   524,  1045,    48,  1044,  1042,   981,  1047,
     509,  1048,   155,   156,   709,   796,   709,   529,   923,  1085,
     922,   628,   709,   600,   509,   601,   739,   589,   509,   747,
     748,   952,   967,    25,   966,   424,   425,   426,   996,  1074,
     137,  1073,  1068,   525,  1080,     1,  1083,   851,  1081,   581,
      26,   525,   749,   750,   835,   836,   930,   709,   165,   166,
       9,    10,   582,   733,   171,  1086,   388,   399,   174,   416,
     417,   709,    11,    49,  1032,    15,   946,   961,   343,  1117,
     633,   651,  1082,   984,   629,   766,   652,   391,    49,   629,
     693,  1174,  1067,    49,    49,   361,   362,    49,   364,   365,
     525,    43,   367,   368,    44,   892,   401,   694,   893,   404,
     405,   406,   407,   408,   409,   410,   597,   412,   598,  1060,
    1037,  1059,  1118,   350,    36,   674,   629,   734,   501,   502,
     503,   504,    17,   695,   419,   376,  1119,   639,   640,   641,
     642,   643,   644,   431,     5,    19,     6,     7,   392,    20,
    1022,   646,   647,   648,   590,   590,  1164,  1170,  1184,  1087,
      29,   702,   501,   502,   503,   504,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,    30,   157,   797,   158,   798,  1168,    31,  1165,
    1162,    33,  1171,  1101,  1173,    42,  1172,   509,   136,   948,
     963,   203,   204,     6,     7,   509,   988,   885,     6,     7,
     510,    35,     6,     7,   205,    41,   354,   355,   356,   424,
     425,   426,   611,   700,   757,   645,   645,   603,   604,   746,
     758,   759,   645,   645,   103,   760,   580,   645,   585,   104,
     761,   582,   645,   916,   918,   105,   511,   602,   762,   621,
     645,   623,   625,   106,   924,   925,   654,   627,   929,   206,
     107,   207,   208,   989,   990,   108,   507,   986,   763,   605,
     645,   875,   876,   525,   997,   998,   209,   109,  1004,   210,
     764,   211,   645,   668,   911,   718,   719,   765,   512,   645,
    1103,  1104,   645,   645,   513,  1124,   606,   645,   960,   110,
     713,   531,   112,  1133,   607,   645,  1141,  1143,   645,   645,
     113,   649,   650,   736,   117,   741,   934,   935,   212,   213,
     514,   515,   114,   526,   115,   582,   116,   119,   535,   515,
     214,    49,   720,   721,   118,   120,   121,   722,   688,   122,
     215,   123,   608,   124,   125,   126,   127,  1071,  1072,   609,
     129,  1069,   130,   605,   527,   131,   132,   617,  1077,  1078,
     133,   516,  1084,   134,   135,   139,   369,   370,   140,   636,
     172,   141,   142,   143,   147,   732,   895,   896,   723,   148,
     606,   216,   579,   149,   217,  1058,   150,   790,   607,   151,
     582,   661,   152,   153,   167,   218,   168,   169,   170,   173,
     177,   178,   897,   341,   342,   344,   345,   357,   610,   805,
     346,   347,   358,   360,   898,    49,   359,   187,   363,   651,
     770,   402,   411,   403,   652,   413,   608,  1040,   414,   371,
     418,   669,   670,   609,   672,   693,   420,   421,   422,   785,
     786,   423,   681,   428,   899,   606,   429,   791,   430,   436,
     432,   433,   900,   607,   434,   653,   435,   901,   483,   484,
     724,   486,   487,   489,   490,   372,   492,   187,   902,   806,
      49,   373,   809,   810,   391,   491,   493,   374,   495,   497,
      49,   498,   519,   849,   651,   532,   815,   517,   533,   652,
     534,   608,   610,   189,   536,   537,   538,   539,   609,   540,
     528,  1031,   541,   375,   542,   543,   544,   714,   941,  1151,
    1152,   545,   376,   546,   956,   957,   903,   586,   902,   547,
     653,   548,   834,   549,   550,   904,   551,   552,   582,   553,
    1038,  1039,   554,   555,   556,   557,   845,   846,   847,   558,
    1153,   559,   884,   850,   377,   560,   561,   973,   974,  1012,
     187,   562,   898,   563,   856,   187,   564,   610,   858,   565,
     566,   860,   861,   567,   568,   569,   903,   570,  1154,   772,
     571,   572,   573,   574,   575,   576,   189,   970,   577,   578,
     645,   905,   899,   784,   599,   898,   638,   671,   187,   605,
     676,   941,  1155,  1156,   906,   901,   975,   880,   677,  1063,
    1064,   902,   943,   678,   679,   680,   902,   802,   886,   682,
     683,  1008,   890,   804,   977,   899,   606,   684,  1098,   685,
     686,   687,   651,  1157,   607,   689,   940,   652,   691,   941,
     707,   690,  1012,   708,   706,   711,   710,   712,   717,   902,
     187,   605,  1006,   715,   716,   391,   738,   742,   976,   903,
     744,    49,   350,   745,   903,   768,   754,   743,   767,   775,
     652,   776,   608,  1062,   777,   778,   189,  1009,   606,   609,
     779,   780,   938,   939,   781,   788,   607,   782,   942,   783,
     787,   941,  1112,   789,   792,   943,   795,   903,   793,   803,
     350,   902,   941,  1052,   808,  1054,   904,   391,  1065,   811,
     976,   807,   902,    49,   812,   813,   814,  1132,   817,  1134,
     898,   818,   816,   187,   608,   819,  1010,   820,   821,   822,
    1011,   609,  1012,   943,   824,   826,   823,   825,   610,   921,
     827,   867,   828,  1012,   829,   832,   839,   830,   831,   903,
     899,   874,   350,   842,   843,   848,   852,   883,   904,   995,
     903,   940,   854,   853,   941,  1109,   855,   857,  1091,   859,
     862,   866,   869,  1095,   902,   870,   872,    78,    49,   891,
     887,   932,  1005,   933,   936,   943,  1007,    79,  1028,  1029,
     610,   971,  1030,    80,  1051,   652,  1023,    81,    82,  1049,
      83,    84,  1035,    85,  1050,  1089,  1024,  1025,  1021,  1026,
    1027,  1055,  1131,   942,  1107,   179,  1093,  1088,  1094,  1090,
    1096,  1092,   903,  1099,  1100,  1106,  1105,  1110,  1108,   180,
     181,   182,   183,   184,   185,   186,  1111,  1113,  1125,  1130,
    1128,  1036,    86,  1076,    87,  1129,  1135,    88,  1138,  1140,
    1142,  1053,  1144,  1114,    89,   187,  1146,  1115,   943,  1175,
    1176,  1177,  1188,    90,  1147,   978,   958,    91,    92,   889,
     871,   773,  1126,    28,   396,   286,   188,   964,   287,   288,
     289,   189,   290,   291,   292,  1075,  1158,   927,   991,   999,
     730,   235,    93,     0,  1061,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1148,     0,     0,
    1149,     0,     0,     0,     0,     0,     0,  1178,  1179,  1180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    95,    96,    97,    98,    99,   100,
    1182,  1183,   101,  1185,   236,     0,     0,     0,     0,     0,
       0,   102,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,     0,     0,  1127,   190,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,  1136,  1137,     0,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,     0,  1145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,   259,     0,   260,     0,   261,   262,   263,   264,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1186,  1187,     0,   266,     0,   267,   268,   269,   270,
     271,   272,     0,     0,   273,   274,   275,   276,   277,     0,
       0,   278,   279,   280,   281,   282,   283,   284
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,    40,   176,   210,   488,   530,   530,     8,   868,   530,
      11,     4,   496,   937,   937,    16,   530,   530,   881,   882,
     530,   881,   882,   881,   882,   888,   702,   888,   888,   772,
     888,   894,   888,   894,   888,     3,   894,    25,     6,    25,
       4,     4,     3,     4,     4,    25,   530,     6,   972,   972,
       3,     4,    32,     4,    42,     4,    17,    17,   868,     3,
       4,     4,    13,     3,     4,     3,     4,    48,   888,   373,
     374,   375,   376,   377,   937,    15,   937,   937,   888,   937,
      25,   937,     3,     4,    72,     4,    72,   391,   868,    69,
     868,     4,    72,     4,    25,     6,     4,    58,    25,     3,
       4,   881,   882,   105,   882,     8,     9,    10,   888,   972,
     111,   972,   972,   101,   972,    12,   972,   793,   972,     4,
     122,   101,    26,    27,     3,     4,   869,    72,   129,   130,
       0,     3,    17,     4,   135,   115,   175,   176,   139,   120,
     121,    72,    14,   107,    47,   144,   881,   882,   149,   112,
      99,   111,   972,   888,    67,   141,   116,   101,   107,    67,
     153,    88,   972,   107,   107,   166,   167,   107,   169,   170,
     101,     6,   173,   174,     9,     4,   177,   170,     7,   180,
     181,   182,   183,   184,   185,   186,   490,   188,   492,   969,
     933,   969,   155,   146,   145,   154,    67,    68,     8,     9,
      10,    11,     6,   196,   205,   149,   169,   511,   512,   513,
     514,   515,   516,   214,     7,     7,     9,    10,   162,     3,
     208,   525,   526,   527,   185,   185,  1150,  1150,     4,   209,
       7,   199,     8,     9,    10,    11,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,     6,   204,   203,   206,   205,  1150,   144,  1150,
    1150,     7,  1150,  1036,  1150,     7,  1150,    25,     4,   881,
     882,     3,     4,     9,    10,    25,   888,     4,     9,    10,
      30,    13,     9,    10,    16,   105,   200,   201,   202,     8,
       9,    10,   496,     4,     4,     6,     6,     3,     4,   633,
       4,     4,     6,     6,   122,     4,   484,     6,   486,     6,
       4,    17,     6,   868,   868,     6,    66,   495,     4,   497,
       6,   499,   500,     6,   868,   868,   530,   505,   868,    61,
       6,    63,    64,   888,   888,     6,   367,   888,     4,    45,
       6,     3,     4,   101,   888,   888,    78,     6,   888,    81,
       4,    83,     6,   531,   868,     3,     4,     4,   108,     6,
       4,     4,     6,     6,   114,     4,    72,     6,   882,     6,
     607,   402,     6,     4,    80,     6,     4,     4,     6,     6,
       6,     3,     4,   624,     7,   626,   188,   189,   120,   121,
     140,   149,     6,   151,     6,    17,     6,     6,   429,   149,
     132,   107,    50,    51,     7,     6,     6,    55,   586,     6,
     142,     6,   118,     6,     6,     6,     6,   972,   972,   125,
       7,   972,     7,    45,   182,     7,     7,   496,   972,   972,
       7,   181,   972,     7,     7,     7,     3,     4,     7,   508,
      59,     7,     7,     7,     7,   623,     3,     4,    96,     7,
      72,   183,   483,     7,   186,   969,     7,   694,    80,     7,
      17,   530,     7,     7,     6,   197,     6,     6,     6,     6,
       6,     6,    29,     7,     6,     6,     6,   207,   184,   716,
       9,     7,     6,     6,    41,   107,     7,    44,     7,   111,
     668,     6,     6,   123,   116,     6,   118,     4,     6,    66,
     124,   532,   533,   125,   535,   153,     7,     7,     7,   687,
     688,     7,   543,     7,    71,    72,     6,   695,     6,   148,
       7,     7,    79,    80,     7,   147,     7,    84,     7,     6,
     178,     6,     6,     6,   150,   102,     6,    44,    95,   717,
     107,   108,   720,   721,   101,   198,     6,   114,     6,     6,
     107,     7,     7,   790,   111,     7,   734,   100,     6,   116,
       6,   118,   184,    70,     7,     7,     6,     6,   125,     6,
     103,   905,     6,   140,     6,     6,     6,   608,    85,     3,
       4,     6,   149,     6,     3,     4,   143,     9,    95,     6,
     147,     6,   770,     6,     6,   152,     6,     6,    17,     6,
     934,   935,     6,     6,     6,     6,   784,   785,   786,     6,
      34,     6,   849,   791,   181,     6,     6,     3,     4,   126,
      44,     6,    41,     6,   802,    44,     6,   184,   806,     6,
       6,   809,   810,     6,     6,     6,   143,     6,    62,   670,
       6,     6,     6,     6,     6,     6,    70,   884,     6,     6,
       6,   208,    71,   684,     7,    41,     7,     7,    44,    45,
       6,    85,    86,    87,   868,    84,    52,   845,     6,     3,
       4,    95,   179,     6,     6,     6,    95,   708,   856,     6,
       6,     4,   860,   714,   888,    71,    72,     6,  1022,   191,
       6,     6,   111,   117,    80,   180,    82,   116,     7,    85,
       6,   194,   126,     6,   202,     6,    43,     6,     6,    95,
      44,    45,   890,     7,     7,   101,     7,     7,   104,   143,
       7,   107,   146,    98,   143,     6,    31,    57,   110,     6,
     116,     6,   118,   970,     6,     6,    70,    60,    72,   125,
       6,     6,     3,     4,     6,   195,    80,     6,   134,     6,
       6,    85,  1086,     6,   150,   179,     4,   143,   199,     6,
     146,    95,    85,   941,    53,   943,   152,   101,   972,     6,
     104,    96,    95,   107,     7,     6,    54,  1111,    28,  1113,
      41,    25,    56,    44,   118,     7,   109,     7,     6,     4,
     113,   125,   126,   179,   108,   140,    66,   114,   184,   868,
     149,   832,   181,   126,   101,     6,     6,   151,   182,   143,
      71,   842,   146,     6,     6,     6,   200,   848,   152,   888,
     143,    82,     6,   201,    85,  1062,     6,     4,  1006,     7,
      97,    30,    46,  1011,    95,    48,     6,    33,   107,     7,
      72,   872,     4,   874,   187,   179,    28,    43,     7,     7,
     184,   199,     6,    49,     6,   116,   119,    53,    54,    32,
      56,    57,   120,    59,   192,     6,   897,   898,    42,   900,
     901,   193,  1109,   134,  1052,     4,     6,    49,     6,    96,
       6,   141,   143,     7,     4,     6,   190,    33,   180,    18,
      19,    20,    21,    22,    23,    24,     7,     7,    46,     6,
     188,   932,    98,   972,   100,   189,    42,   103,   208,     6,
     115,   942,   121,  1091,   110,    44,    69,  1095,   179,    32,
       6,     6,    88,   119,   209,   888,   882,   123,   124,   859,
     838,   671,  1101,    23,   176,   146,    65,   882,   146,   146,
     146,    70,   146,   146,   146,   972,  1150,   868,   888,   888,
     622,   145,   148,    -1,   969,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,    -1,    -1,
    1148,    -1,    -1,    -1,    -1,    -1,    -1,  1155,  1156,  1157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,    -1,   190,   191,   192,   193,   194,   195,
    1178,  1179,   198,  1181,     4,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1102,   163,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1117,  1118,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,  1140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,   133,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1182,  1183,    -1,   154,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   172,   173,   174,   175,   176,   177
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   223,   224,   363,     7,     9,    10,   211,     0,
       3,    14,   309,   362,   211,   144,   211,     6,   211,     7,
       3,   279,   302,   310,   311,   105,   122,     4,   311,     7,
       6,   144,   280,     7,     4,    13,   145,   281,   457,   498,
     303,   105,     7,     6,     9,   456,     3,     4,    15,   107,
     233,   239,   246,   249,   252,   255,   258,   261,   269,   272,
     276,   283,   288,   296,   299,   304,   312,   323,   328,   331,
     334,   337,   340,   343,   346,   356,   361,   431,    33,    43,
      49,    53,    54,    56,    57,    59,    98,   100,   103,   110,
     119,   123,   124,   148,   187,   190,   191,   192,   193,   194,
     195,   198,   207,   122,     6,     6,     6,     6,     6,     6,
       6,   262,     6,     6,     6,     6,     6,     7,     7,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   357,     7,
       7,     7,     7,     7,     7,     7,     4,   211,   263,     7,
       7,     7,     7,     7,   297,   300,   313,     7,     7,     7,
       7,     7,     7,     7,   347,     3,     4,   204,   206,   350,
     352,   355,   358,   495,   497,   211,   211,     6,     6,     6,
       6,   211,    59,     6,   211,   273,   277,     6,     6,     4,
      18,    19,    20,    21,    22,    23,    24,    44,    65,    70,
     163,   298,   366,   367,   368,   369,   370,   371,   372,   385,
     398,   401,   471,     3,     4,    16,    61,    63,    64,    78,
      81,    83,   120,   121,   132,   142,   183,   186,   197,   244,
     291,   294,   301,   364,   394,   396,   397,   409,   412,   414,
     446,   454,   488,   491,   493,   498,     4,    35,    36,    37,
      38,    39,    40,    73,    74,    75,    76,    77,    89,    90,
      91,    92,    93,    94,   106,   127,   128,   129,   130,   131,
     133,   135,   136,   137,   138,   139,   154,   156,   157,   158,
     159,   160,   161,   164,   165,   166,   167,   168,   171,   172,
     173,   174,   175,   176,   177,   314,   366,   367,   368,   369,
     370,   371,   372,   378,   379,   380,   381,   382,   383,   404,
     405,   406,   407,   408,   419,   420,   421,   422,   423,   424,
     430,   441,   442,   443,   444,   445,   447,   449,   450,   451,
     452,   453,   462,   464,   465,   466,   467,   468,   469,   472,
     473,   474,   475,   476,   479,   480,   481,   482,   483,   484,
     485,     7,     6,   211,     6,     6,     9,     7,     3,     4,
     146,   316,   348,   458,   200,   201,   202,   207,     6,     7,
       6,   211,   211,     7,   211,   211,   219,   211,   211,     3,
       4,    66,   102,   108,   114,   140,   149,   181,   225,   228,
     264,   274,   282,   286,   305,   315,   321,   428,   431,     3,
       4,   101,   162,   225,   275,   278,   315,   317,   322,   431,
     470,   211,     6,   123,   211,   211,   211,   211,   211,   211,
     211,     6,   211,     6,     6,    48,   120,   121,   124,   211,
       7,     7,     7,     7,     8,     9,    10,   212,     7,     6,
       6,   211,     7,     7,     7,     7,   148,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,     7,     6,   332,     6,     6,   341,     6,
     150,   198,     6,     6,   222,     6,   240,     6,     7,   217,
     218,     8,     9,    10,    11,   213,   259,   211,   270,    25,
      30,    66,   108,   114,   140,   149,   181,   100,   221,     7,
     221,   221,   221,   221,   221,   101,   151,   182,   103,   221,
     284,   211,     7,     6,     6,   211,     7,     7,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,   211,
     213,     4,    17,   333,   365,   213,     9,     3,     4,    58,
     185,   318,   342,   365,   392,   490,   344,   221,   221,     7,
       4,     6,   213,     3,     4,    45,    72,    80,   118,   125,
     184,   225,   241,   365,   386,   403,   411,   431,   438,   439,
     489,   213,   250,   213,   253,   213,   256,   213,     4,    67,
     260,   399,     4,    99,   271,   427,   431,   226,     7,   221,
     221,   221,   221,   221,   221,     6,   221,   221,   221,     3,
       4,   111,   116,   147,   225,   285,   306,   365,   386,   403,
     411,   431,   433,   436,   438,   439,   459,   489,   213,   211,
     211,     7,   211,     6,   154,   293,     6,     6,     6,     6,
       6,   211,     6,     6,     6,   191,     6,     6,   213,   180,
     194,     7,     4,   153,   170,   196,   345,   461,   478,   492,
       4,     3,   199,   349,   351,   353,   202,     6,     6,    72,
      43,     6,     6,   212,   211,     7,     7,     6,     3,     4,
      50,    51,    55,    96,   178,   251,   267,   388,   389,   391,
     461,   486,   213,     4,    68,   254,   399,   400,     7,     4,
     257,   399,     7,    57,     7,    98,   221,     3,     4,    26,
      27,   227,   373,   374,    31,   229,   376,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   141,   110,     6,   215,
     213,   245,   211,   293,   214,     6,     6,     6,     6,     6,
       6,     6,     6,     6,   211,   213,   213,     6,   195,     6,
     212,   213,   150,   199,   215,     4,     4,   203,   205,   354,
     494,   496,   211,     6,   211,   212,   213,    96,    53,   213,
     213,     6,     7,     6,    54,   213,    56,    28,    25,     7,
       7,     6,     4,    66,   108,   114,   140,   149,   181,   101,
     151,   182,     6,   211,   213,     3,     4,   242,   214,     6,
     212,   292,     6,     6,   324,   213,   213,   213,     6,   212,
     213,   215,   200,   201,     6,     6,   213,     4,   213,     7,
     213,   213,    97,   268,   426,   220,    30,   211,   289,    46,
      48,   292,     6,   431,   211,     3,     4,   325,   326,   327,
     213,   335,   338,   211,   212,     4,   213,    72,   247,   268,
     213,     7,     4,     7,   307,     3,     4,    29,    41,    71,
      79,    84,    95,   143,   152,   208,   225,   236,   275,   290,
     359,   365,   375,   384,   385,   402,   403,   410,   411,   415,
     425,   431,   433,   436,   438,   439,   455,   459,   460,   489,
     214,     4,   211,   211,   188,   189,   187,   329,     3,     4,
      82,    85,   134,   179,   230,   336,   384,   385,   402,   413,
     416,   425,   436,   448,   455,   487,     3,     4,   236,   339,
     365,   384,   385,   402,   415,   425,   433,   436,   455,   319,
     212,   199,   234,     3,     4,    52,   104,   225,   230,   248,
     265,   275,   287,   360,   384,   385,   386,   390,   402,   403,
     411,   413,   416,   425,   429,   431,   436,   438,   439,   448,
     455,   458,   460,   487,   489,     4,   213,    28,     4,    60,
     109,   113,   126,   308,   393,   416,   425,   432,   435,   440,
     455,    42,   208,   119,   211,   211,   211,   211,     7,     7,
       6,   221,    47,   243,   387,   120,   211,   214,   221,   221,
       4,   330,   385,   401,   416,   425,   440,   455,   487,    32,
     192,     6,   213,   211,   213,   193,     4,   320,   365,   433,
     436,   490,   212,     3,     4,   225,   235,   275,   385,   386,
     401,   403,   411,   416,   425,   429,   431,   438,   439,   440,
     455,   458,   460,   487,   489,    69,   115,   209,    49,     6,
      96,   213,   141,     6,     6,   213,     6,   237,   221,     7,
       4,   214,   295,     4,     4,   190,     6,   213,   180,   212,
      33,     7,   221,     7,   213,   213,     4,   112,   155,   169,
     238,   434,   463,   477,     4,    46,   295,   431,   188,   189,
       6,   212,   221,     4,   221,    42,   211,   211,   208,     4,
       6,     4,   115,     4,   121,   211,    69,   209,   213,   213,
     231,     3,     4,    34,    62,    86,    87,   117,   225,   232,
     266,   377,   385,   395,   401,   416,   417,   418,   425,   437,
     440,   455,   458,   487,    88,    32,     6,     6,   213,   213,
     213,   216,   213,   213,     4,   213,   211,   211,    88
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   210,   211,   211,   212,   212,   212,   213,   213,   213,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     224,   224,   224,   225,   226,   226,   226,   226,   227,   228,
     229,   229,   230,   231,   231,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     233,   234,   234,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   236,   237,   237,   238,   238,   238,   239,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   243,   243,   244,   245,   245,   246,   247,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   250,   250,   251,
     251,   251,   251,   251,   251,   252,   253,   253,   254,   254,
     255,   256,   256,   257,   258,   259,   259,   260,   261,   262,
     262,   263,   264,   264,   265,   266,   267,   267,   268,   268,
     269,   270,   270,   271,   271,   272,   273,   273,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   275,   275,
     276,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     279,   280,   280,   281,   281,   282,   282,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   286,   286,   287,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   291,   291,   292,   292,   293,   293,   294,   294,
     295,   295,   296,   297,   297,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   299,   300,   300,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   302,   303,   303,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   305,   306,   307,   307,
     308,   308,   308,   308,   308,   308,   308,   309,   310,   310,
     311,   311,   312,   313,   313,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   316,   317,   318,   319,   319,   320,   320,   320,
     320,   321,   321,   322,   323,   324,   324,   325,   325,   326,
     327,   328,   329,   329,   330,   330,   330,   330,   330,   330,
     330,   331,   332,   332,   333,   334,   335,   335,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     338,   338,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   341,   341,   342,   342,   342,   342,   343,
     344,   344,   345,   345,   345,   346,   347,   347,   348,   348,
     349,   349,   350,   351,   351,   352,   353,   353,   354,   354,
     355,   356,   357,   357,   358,   358,   358,   358,   358,   359,
     359,   360,   361,   362,   363,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     0,     2,     0,     3,     0,
       3,     0,     4,     0,     2,     0,     2,     0,     3,     2,
       0,     1,     2,     5,     0,     2,     2,     2,     5,     6,
       0,     1,    11,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      15,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     0,     2,     1,     1,     1,     9,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     1,     7,     0,     2,    14,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,    10,     0,     2,     1,
       1,     1,     1,     1,     1,    10,     0,     2,     1,     1,
      10,     0,     2,     1,     9,     0,     2,     1,     5,     0,
       2,     4,     5,     2,     6,     5,     6,     3,     0,     1,
       9,     0,     2,     1,     1,     7,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       7,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     2,     1,     1,     5,     2,     9,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     5,    13,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     9,     6,     0,     2,     1,     1,    13,    10,
       0,     2,     6,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     7,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     7,     1,     2,
       1,     1,     6,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     5,     5,     8,     0,     2,     1,     1,     1,
       1,     5,     2,     5,    12,     0,     2,     1,     1,     5,
       5,    14,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     8,     0,     2,     1,    13,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    13,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     0,     2,     1,     1,     1,     1,     9,
       0,     2,     1,     1,     1,     6,     0,     2,     1,     1,
       5,     2,     7,     0,     1,     7,     0,     2,     1,     1,
       5,     5,     0,     2,     1,     1,     1,     1,     1,     5,
       2,     6,     1,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       5,     5,     5,     5,     5,     6,     2,     2,     2,     2,
       7,     3,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     5,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     3,
       4,     4,     2,     2,     2,     2,     2,     5,     2,     2,
       2,     2,     1,     3,     1,     2,     2,     2,     3,     2,
       2,     3,     2,     2,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     2,     1,     1,     2,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     3,     3,
       3,     1,     8,     3,     3,     3,     3,     3,     1,     1,
       2,     2,     2,     3,     2,     3,     3,     2,     2,     2,
       2,     2,     2
  };


#if A2LDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const A2lParser::yytname_[] =
  {
  "EOL", "error", "\"invalid token\"", "A2L_BEGIN", "A2L_END",
  "A2L_INCLUDE", "IDENT", "STRING", "INT", "UINT", "HEX", "FLOAT",
  "ASAP2_VERSION", "A2L_VERSION", "A2ML_VERSION", "A2ML", "ADDR_EPK",
  "ADDRESS_TYPE", "ALIGNMENT_BYTE", "ALIGNMENT_FLOAT16_IEEE",
  "ALIGNMENT_FLOAT32_IEEE", "ALIGNMENT_FLOAT64_IEEE", "ALIGNMENT_INT64",
  "ALIGNMENT_LONG", "ALIGNMENT_WORD", "ANNOTATION", "ANNOTATION_LABEL",
  "ANNOTATION_ORIGIN", "ANNOTATION_TEXT", "ARRAY_SIZE", "AR_COMPONENT",
  "AR_PROTOTYPE_OF", "AXIS_DESCR", "AXIS_PTS", "AXIS_PTS_REF",
  "AXIS_PTS_X", "AXIS_PTS_Y", "AXIS_PTS_Z", "AXIS_PTS_4", "AXIS_PTS_5",
  "AXIS_RESCALE_X", "BIT_MASK", "BIT_OPERATION", "BLOB", "A2L_BYTE_ORDER",
  "CALIBRATION_ACCESS", "CALIBRATION_HANDLE", "CALIBRATION_HANDLE_TEXT",
  "CALIBRATION_METHOD", "CHARACTERISTIC", "COEFFS", "COEFFS_LINEAR",
  "COMPARISON_QUANTITY", "COMPU_METHOD", "COMPU_TAB", "COMPU_TAB_REF",
  "COMPU_VTAB", "COMPU_VTAB_RANGE", "CONSISTENT_EXCHANGE",
  "CONTROLLER_ADDRESSES", "CONVERSION", "CPU_TYPE", "CURVE_AXIS_REF",
  "CUSTOMER", "CUSTOMER_NO", "DATA_SIZE", "DEF_CHARACTERISTIC",
  "DEFAULT_VALUE", "DEFAULT_VALUE_NUMERIC", "DEPENDENT_CHARACTERISTIC",
  "DEPOSIT", "DISCRETE", "DISPLAY_IDENTIFIER", "DIST_OP_X", "DIST_OP_Y",
  "DIST_OP_Z", "DIST_OP_4", "DIST_OP_5", "ECU", "ECU_ADDRESS",
  "ECU_ADDRESS_EXTENSION", "ECU_CALIBRATION_OFFSET", "ENCODING", "EPK",
  "ERROR_MASK", "EXTENDED_LIMITS", "FIX_AXIS_PAR", "FIX_AXIS_PAR_DIST",
  "FIX_AXIS_PAR_LIST", "FIX_NO_AXIS_PTS_X", "FIX_NO_AXIS_PTS_Y",
  "FIX_NO_AXIS_PTS_Z", "FIX_NO_AXIS_PTS_4", "FIX_NO_AXIS_PTS_5",
  "FNC_VALUES", "FORMAT", "FORMULA", "FORMULA_INV", "FRAME",
  "FRAME_MEASUREMENT", "FUNCTION", "FUNCTION_LIST", "FUNCTION_VERSION",
  "GROUP", "GUARD_RAILS", "HEADER", "IDENTIFICATION", "IF_DATA",
  "IN_MEASUREMENT", "INPUT_QUANTITY", "INSTANCE", "LAYOUT", "LEFT_SHIFT",
  "LIMITS", "LOC_MEASUREMENT", "MAP_LIST", "MATRIX_DIM", "MAX_GRAD",
  "MAX_REFRESH", "MEASUREMENT", "MEMORY_LAYOUT", "MEMORY_SEGMENT",
  "MODULE", "MOD_COMMON", "MOD_PAR", "MODEL_LINK", "MONOTONY",
  "NO_AXIS_PTS_X", "NO_AXIS_PTS_Y", "NO_AXIS_PTS_Z", "NO_AXIS_PTS_4",
  "NO_AXIS_PTS_5", "NO_OF_INTERFACES", "NO_RESCALE_X", "NUMBER",
  "OFFSET_X", "OFFSET_Y", "OFFSET_Z", "OFFSET_4", "OFFSET_5",
  "OUT_MEASUREMENT", "OVERWRITE", "PHONE_NO", "PHYS_UNIT", "PROJECT",
  "PROJECT_NO", "READ_ONLY", "READ_WRITE", "RECORD_LAYOUT",
  "REF_CHARACTERISTIC", "REF_GROUP", "REF_MEASUREMENT",
  "REF_MEMORY_SEGMENT", "REF_UNIT", "RESERVED", "RIGHT_SHIFT",
  "RIP_ADDR_W", "RIP_ADDR_X", "RIP_ADDR_Y", "RIP_ADDR_Z", "RIP_ADDR_4",
  "RIP_ADDR_5", "ROOT", "S_REC_LAYOUT", "SHIFT_OP_X", "SHIFT_OP_Y",
  "SHIFT_OP_Z", "SHIFT_OP_4", "SHIFT_OP_5", "SIGN_EXTEND", "SI_EXPONENTS",
  "SRC_ADDR_X", "SRC_ADDR_Y", "SRC_ADDR_Z", "SRC_ADDR_4", "SRC_ADDR_5",
  "STATIC_ADDRESS_OFFSETS", "STATIC_RECORD_LAYOUT", "STATUS_STRING_REF",
  "STEP_SIZE", "STRUCTURE_COMPONENT", "SUB_FUNCTION", "SUB_GROUP",
  "SUPPLIER", "SYMBOL_LINK", "SYMBOL_TYPE_LINK", "SYSTEM_CONSTANT",
  "TRANSFORMER", "TRANSFORMER_IN_OBJECTS", "TRANSFORMER_OUT_OBJECTS",
  "TYPEDEF_AXIS", "TYPEDEF_BLOB", "TYPEDEF_CHARACTERISTIC",
  "TYPEDEF_MEASUREMENT", "TYPEDEF_STRUCTURE", "UNIT", "UNIT_CONVERSION",
  "USER", "USER_RIGHTS", "VAR_ADDRESS", "VAR_CHARACTERISTIC",
  "VAR_CRITERION", "VAR_FORBIDDEN_COMB", "VAR_MEASUREMENT", "VAR_NAMING",
  "VAR_SELECTION_CHARACTERISTIC", "VAR_SEPARATOR", "VARIANT_CODING",
  "VIRTUAL", "VIRTUAL_CHARACTERISTIC", "$accept", "any_uint", "any_int",
  "any_float", "int_list", "uint_list", "float_list", "float_pair_list",
  "float_string_list", "float_range_list", "string_list", "ident_list",
  "key_value_list", "a2l_file", "file_version", "annotation",
  "annotation_attributes", "annotation_text", "ar_component",
  "ar_component_attribute", "axis_descr", "axis_descr_attributes",
  "axis_descr_attribute", "axis_pts", "axis_pts_attributes",
  "axis_pts_attribute", "bit_operation", "bit_operation_attributes",
  "bit_operation_attribute", "blob", "blob_attributes", "blob_attribute",
  "calibration_handle", "calibration_handle_attribute",
  "calibration_method", "calibration_method_attributes", "characteristic",
  "characteristic_attributes", "characteristic_attribute", "compu_method",
  "compu_method_attributes", "compu_method_attribute", "compu_tab",
  "compu_tab_attributes", "compu_tab_attribute", "compu_vtab",
  "compu_vtab_attributes", "compu_vtab_attribute", "compu_vtab_range",
  "compu_vtab_range_attributes", "compu_vtab_range_attribute",
  "controller_addresses", "controller_address_list", "controller_address",
  "def_characteristic", "dependent_characteristic", "fix_axis_par_list",
  "formula", "formula_attribute", "frame", "frame_attributes",
  "frame_attribute", "function", "function_attributes",
  "function_attribute", "function_list", "group", "group_attributes",
  "group_attribute", "header", "header_attributes", "header_attribute",
  "in_measurement", "instance", "instance_attributes",
  "instance_attribute", "loc_measurement", "map_list", "measurement",
  "measurement_attributes", "measurement_attribute", "memory_layout",
  "memory_layout_attributes", "prg_type", "memory_segment",
  "memory_segment_attributes", "mod_common", "mod_common_attributes",
  "mod_common_attribute", "mod_par", "mod_par_attributes",
  "mod_par_attribute", "module", "module_attributes", "module_attribute",
  "out_measurement", "overwrite", "overwrite_attributes",
  "overwrite_attribute", "project", "project_attributes",
  "project_attribute", "record_layout", "record_layout_attributes",
  "record_layout_attribute", "ref_characteristic", "ref_group",
  "ref_measurement", "structure_component",
  "structure_component_attributes", "structure_component_attribute",
  "sub_function", "sub_group", "transformer", "transformer_attributes",
  "transformer_attribute", "transformer_in_objects",
  "transformer_out_objects", "typedef_axis", "typedef_axis_attributes",
  "typedef_axis_attribute", "typedef_blob", "typedef_blob_attributes",
  "typedef_blob_attribute", "typedef_characteristic",
  "typedef_characteristic_attributes", "typedef_characteristic_attribute",
  "typedef_measurement", "typedef_measurement_attributes",
  "typedef_measurement_attribute", "typedef_structure",
  "typedef_structure_attributes", "typedef_structure_attribute", "unit",
  "unit_attributes", "unit_attribute", "user_rights",
  "user_rights_attributes", "user_rights_attribute", "var_address",
  "var_characteristic", "var_characteristic_attribute", "var_criterion",
  "var_criterion_attributes", "var_criterion_attribute",
  "var_forbidden_comb", "variant_coding", "variant_coding_attributes",
  "variant_coding_attribute", "virtual", "virtual_characteristic", "a2ml",
  "a2ml_version", "asap2_version", "addr_epk", "address_type",
  "alignment_byte", "alignment_float16_ieee", "alignment_float32_ieee",
  "alignment_float64_ieee", "alignment_int64", "alignment_long",
  "alignment_word", "annotation_label", "annotation_origin", "array_size",
  "ar_prototype_of", "axis_pts_ref", "axis_pts_x", "axis_pts_y",
  "axis_pts_z", "axis_pts_4", "axis_pts_5", "axis_rescale_x", "bit_mask",
  "byte_order", "calibration_access", "calibration_handle_text", "coeffs",
  "coeffs_linear", "comparison_quantity", "compu_tab_ref",
  "consistent_exchange", "conversion", "cpu_type", "curve_axis_ref",
  "customer", "customer_no", "data_size", "default_value",
  "default_value_numeric", "deposit", "discrete", "display_identifier",
  "dist_op_x", "dist_op_y", "dist_op_z", "dist_op_4", "dist_op_5", "ecu",
  "ecu_address", "ecu_address_extension", "ecu_calibration_offset",
  "encoding", "epk", "error_mask", "extended_limits", "fix_axis_par",
  "fix_axis_par_dist", "fix_no_axis_pts_x", "fix_no_axis_pts_y",
  "fix_no_axis_pts_z", "fix_no_axis_pts_4", "fix_no_axis_pts_5",
  "fnc_values", "format", "formula_inv", "frame_measurement",
  "function_version", "guard_rails", "identification", "if_data",
  "input_quantity", "layout", "left_shift", "limits", "matrix_dim",
  "max_grad", "max_refresh", "model_link", "monotony", "no_axis_pts_x",
  "no_axis_pts_y", "no_axis_pts_z", "no_axis_pts_4", "no_axis_pts_5",
  "no_of_interfaces", "no_rescale_x", "number", "offset_x", "offset_y",
  "offset_z", "offset_4", "offset_5", "phone_no", "phys_unit", "proj_no",
  "project_no", "read_only", "read_write", "ref_memory_segment",
  "ref_unit", "reserved", "right_shift", "rip_addr_w", "rip_addr_x",
  "rip_addr_y", "rip_addr_z", "rip_addr_4", "rip_addr_5", "root",
  "s_rec_layout", "shift_op_x", "shift_op_y", "shift_op_z", "shift_op_4",
  "shift_op_5", "sign_extend", "si_exponents", "src_addr_x", "src_addr_y",
  "src_addr_z", "src_addr_4", "src_addr_5", "static_address_offsets",
  "static_record_layout", "status_string_ref", "step_size", "supplier",
  "symbol_link", "symbol_type_link", "system_constant", "unit_conversion",
  "user", "var_measurement", "var_naming", "var_selection_characteristic",
  "var_separator", "version", YY_NULLPTR
  };
#endif


#if A2LDEBUG
  const short
  A2lParser::yyrline_[] =
  {
       0,   435,   435,   436,   438,   439,   440,   442,   443,   444,
     445,   447,   448,   450,   451,   453,   454,   456,   457,   459,
     460,   462,   463,   468,   469,   471,   472,   474,   475,   477,
     479,   480,   481,   483,   484,   485,   486,   487,   489,   491,
     496,   497,   499,   510,   511,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     529,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   565,   570,   571,   572,   573,   574,   576,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     595,   599,   600,   602,   608,   609,   614,   627,   628,   629,
     630,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   659,   668,   669,   670,
     671,   672,   673,   678,   679,   681,   690,   691,   693,   694,
     696,   705,   706,   707,   709,   717,   718,   719,   721,   723,
     724,   726,   736,   739,   743,   746,   748,   751,   754,   755,
     757,   764,   765,   766,   767,   769,   774,   775,   776,   777,
     778,   779,   780,   781,   782,   783,   784,   785,   787,   788,
     790,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     806,   811,   812,   814,   817,   822,   825,   829,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   850,   851,   853,   856,   860,   862,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
     897,   898,   900,   908,   916,   917,   922,   923,   925,   937,
     948,   949,   953,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,   969,   970,   972,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,   991,   992,   993,   995,  1001,  1002,  1003,  1004,
    1007,  1010,  1013,  1016,  1019,  1022,  1025,  1026,  1029,  1032,
    1035,  1038,  1041,  1044,  1045,  1046,  1049,  1052,  1055,  1058,
    1061,  1064,  1067,  1070,  1073,  1075,  1078,  1082,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1097,  1098,  1100,  1106,  1107,
    1109,  1110,  1115,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1177,  1180,  1183,  1184,  1186,  1193,  1194,  1195,  1196,  1197,
    1198,  1200,  1203,  1207,  1209,  1220,  1221,  1222,  1223,  1225,
    1226,  1228,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
    1249,  1251,  1257,  1258,  1259,  1261,  1273,  1274,  1275,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1290,
    1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1315,  1322,  1323,  1324,  1325,  1326,  1329,  1331,
    1338,  1339,  1340,  1341,  1342,  1347,  1351,  1352,  1353,  1354,
    1356,  1359,  1363,  1369,  1370,  1372,  1379,  1380,  1381,  1382,
    1384,  1386,  1387,  1388,  1389,  1393,  1397,  1401,  1405,  1410,
    1413,  1416,  1420,  1421,  1426,  1429,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1453,  1459,  1465,  1471,  1477,  1484,  1485,  1486,  1487,
    1488,  1498,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1523,  1527,
    1531,  1535,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1560,  1561,
    1562,  1563,  1564,  1565,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1583,  1587,  1591,  1595,  1599,
    1600,  1604,  1605,  1609,  1613,  1617,  1621,  1625,  1626,  1627,
    1628,  1629,  1631,  1632,  1633,  1634,  1635,  1639,  1640,  1644,
    1648,  1652,  1656,  1660,  1664,  1665,  1666,  1670,  1674,  1678,
    1682,  1686,  1687,  1696,  1700,  1704,  1708,  1712,  1716,  1717,
    1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730
  };

  void
  A2lParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  A2lParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // A2LDEBUG

  A2lParser::symbol_kind_type
  A2lParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const unsigned char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209
    };
    // Last valid token kind.
    const int code_max = 464;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "D:/projects/a2llib/src/a2lparser.y"
} // a2l
#line 8023 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1732 "D:/projects/a2llib/src/a2lparser.y"


void a2l::A2lParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
