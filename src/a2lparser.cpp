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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.copy< std::map<std::string, std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::map<double, double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::map<double, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::map<std::string, std::string> > (YY_MOVE (s.value));
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.YY_MOVE_OR_COPY< std::map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.YY_MOVE_OR_COPY< std::map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.YY_MOVE_OR_COPY< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.YY_MOVE_OR_COPY< std::map<std::string, std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::map<double, double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::map<double, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::map<std::string, std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::map<double, double> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::map<double, std::string> > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::map<std::pair<double, double>, std::string> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.copy< std::map<std::string, std::string> > (that.value);
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::map<double, double> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::map<double, std::string> > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::map<std::string, std::string> > (that.value);
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_float_pair_list: // float_pair_list
        yylhs.value.emplace< std::map<double, double> > ();
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        yylhs.value.emplace< std::map<double, std::string> > ();
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        yylhs.value.emplace< std::map<std::pair<double, double>, std::string> > ();
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        yylhs.value.emplace< std::map<std::string, std::string> > ();
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
      case symbol_kind::S_ident_or_keyword: // ident_or_keyword
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

      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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
#line 436 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2850 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 437 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2856 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_uint: INT
#line 438 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < int64_t > () < 0 ? 0 : static_cast<uint64_t>(yystack_[0].value.as < int64_t > ()); }
#line 2862 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: INT
#line 440 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2868 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: UINT
#line 441 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2874 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_int: HEX
#line 442 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2880 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: FLOAT
#line 444 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2886 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: INT
#line 445 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2892 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: UINT
#line 446 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2898 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // any_float: HEX
#line 447 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2904 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: %empty
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2910 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // int_list: int_list any_int
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                     {yystack_[1].value.as < std::deque<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); yylhs.value.as < std::deque<int64_t> > () = std::move(yystack_[1].value.as < std::deque<int64_t> > ());  }
#line 2916 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: %empty
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2922 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // uint_list: uint_list any_uint
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                       {yystack_[1].value.as < std::deque<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[1].value.as < std::deque<uint64_t> > ());  }
#line 2928 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: %empty
#line 455 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2934 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_list: float_list any_float
#line 456 "D:/projects/a2llib/src/a2lparser.y"
                               {yystack_[1].value.as < std::deque<double> > ().emplace_back(yystack_[0].value.as < double > ()); yylhs.value.as < std::deque<double> > () = std::move(yystack_[1].value.as < std::deque<double> > ());  }
#line 2940 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: %empty
#line 458 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2946 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_pair_list: float_pair_list any_float any_float
#line 459 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	  yylhs.value.as < std::map<double, double> > () = std::move(yystack_[2].value.as < std::map<double, double> > ());
	  yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ());
	}
#line 2955 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: %empty
#line 464 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2961 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_string_list: float_string_list any_float STRING
#line 465 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	  yylhs.value.as < std::map<double, std::string> > () = std::move(yystack_[2].value.as < std::map<double, std::string> > ());
	  yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ());
	}
#line 2970 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: %empty
#line 470 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2976 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // float_range_list: float_range_list any_float any_float STRING
#line 471 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = std::move(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ());
        }
#line 2985 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: %empty
#line 476 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2991 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // string_list: string_list STRING
#line 477 "D:/projects/a2llib/src/a2lparser.y"
                             {
	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
	}
#line 3000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_or_keyword: IDENT
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3006 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // ident_or_keyword: A2L_VERSION
#line 483 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = "VERSION";}
#line 3012 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // ident_or_keyword: BLOB
#line 484 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = "BLOB";}
#line 3018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 29: // ident_or_keyword: CHARACTERISTIC
#line 485 "D:/projects/a2llib/src/a2lparser.y"
                         {yylhs.value.as < std::string > () = "CHARACTERISTIC";}
#line 3024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 30: // ident_or_keyword: CONVERSION
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::string > () = "CONVERSION";}
#line 3030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 31: // ident_or_keyword: CUSTOMER
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < std::string > () = "CUSTOMER";}
#line 3036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 32: // ident_or_keyword: MEASUREMENT
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = "MEASUREMENT";}
#line 3042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // ident_list: %empty
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 3048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // ident_list: ident_list ident_or_keyword
#line 492 "D:/projects/a2llib/src/a2lparser.y"
                                      {
       	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
       	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
       	}
#line 3057 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // key_value_list: %empty
#line 497 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 3063 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // key_value_list: key_value_list IDENT IDENT
#line 498 "D:/projects/a2llib/src/a2lparser.y"
                                     {
       	  yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ());
       	  yylhs.value.as < std::map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ());
       }
#line 3072 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 509 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = std::move(yystack_[2].value.as < A2lAnnotation > ());}
#line 3078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // annotation_attributes: %empty
#line 510 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 3084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 43: // annotation_attributes: annotation_attributes annotation_label
#line 511 "D:/projects/a2llib/src/a2lparser.y"
                                              { yystack_[1].value.as < A2lAnnotation > ().Label = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 44: // annotation_attributes: annotation_attributes annotation_origin
#line 512 "D:/projects/a2llib/src/a2lparser.y"
                                               { yystack_[1].value.as < A2lAnnotation > ().Origin = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // annotation_attributes: annotation_attributes annotation_text
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                                             { yystack_[1].value.as < A2lAnnotation > ().Text = std::move(yystack_[0].value.as < std::deque<std::string> > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ());}
#line 3102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3108 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 517 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3118 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // ar_component_attribute: %empty
#line 522 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3124 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // ar_component_attribute: ar_prototype_of
#line 523 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3130 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 526 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3144 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: annotation
#line 539 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3150 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: axis_pts_ref
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3156 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: byte_order
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3162 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: curve_axis_ref
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3168 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: deposit
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3174 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: extended_limits
#line 544 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3180 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: fix_axis_par
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3186 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_descr_attribute: fix_axis_par_dist
#line 546 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3192 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 61: // axis_descr_attribute: fix_axis_par_list
#line 547 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::deque<double> > ()); }
#line 3198 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 62: // axis_descr_attribute: format
#line 548 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3204 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_descr_attribute: max_grad
#line 549 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3210 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_descr_attribute: monotony
#line 550 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3216 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_descr_attribute: phys_unit
#line 551 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3222 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_descr_attribute: read_only
#line 552 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3228 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_descr_attribute: step_size
#line 553 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3234 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts: A2L_BEGIN AXIS_PTS ident_or_keyword STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 556 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3252 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: annotation
#line 571 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3258 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: byte_order
#line 572 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3264 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: calibration_access
#line 573 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3270 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: deposit
#line 574 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3276 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: display_identifier
#line 575 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3282 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: ecu_address_extension
#line 576 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3288 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: extended_limits
#line 577 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3294 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: format
#line 578 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3300 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: function_list
#line 579 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3306 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: guard_rails
#line 580 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3312 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: if_data
#line 581 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3318 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 82: // axis_pts_attribute: max_refresh
#line 582 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3324 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 83: // axis_pts_attribute: model_link
#line 583 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3330 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 84: // axis_pts_attribute: monotony
#line 584 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3336 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // axis_pts_attribute: phys_unit
#line 585 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3342 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // axis_pts_attribute: read_only
#line 586 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3348 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // axis_pts_attribute: ref_memory_segment
#line 587 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3354 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // axis_pts_attribute: step_size
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3360 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 89: // axis_pts_attribute: symbol_link
#line 589 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3366 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 90: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 591 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3376 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // bit_operation_attribute: left_shift
#line 598 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3382 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // bit_operation_attribute: right_shift
#line 599 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3388 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // bit_operation_attribute: sign_extend
#line 600 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3394 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob: A2L_BEGIN BLOB ident_or_keyword STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 602 "D:/projects/a2llib/src/a2lparser.y"
                                                                                            {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 3406 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: address_type
#line 611 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3412 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // blob_attribute: annotation
#line 612 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3418 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // blob_attribute: calibration_access
#line 613 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3424 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // blob_attribute: display_identifier
#line 614 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3430 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // blob_attribute: ecu_address_extension
#line 615 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3436 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // blob_attribute: if_data
#line 616 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3442 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // blob_attribute: max_refresh
#line 617 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // blob_attribute: model_link
#line 618 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3454 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 107: // blob_attribute: symbol_link
#line 619 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3460 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 108: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 621 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lCalibrationHandle > ().Comment = std::move(yystack_[2].value.as < std::string > ());
}
#line 3469 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // calibration_handle_attribute: %empty
#line 625 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3475 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // calibration_handle_attribute: calibration_handle_text
#line 626 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3481 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = std::move(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = std::move(yystack_[2].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // calibration_method_attributes: %empty
#line 634 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3497 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 635 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
		yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
		yylhs.value.as < std::deque<A2lCalibrationHandle> > () = std::move(yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic: A2L_BEGIN CHARACTERISTIC ident_or_keyword STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 641 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3523 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: annotation
#line 655 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3529 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: axis_descr
#line 656 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3537 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: bit_mask
#line 659 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: byte_order
#line 660 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3549 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: calibration_access
#line 661 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: comparison_quantity
#line 662 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: dependent_characteristic
#line 663 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: discrete
#line 664 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: display_identifier
#line 665 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: ecu_address_extension
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: encoding
#line 667 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: extended_limits
#line 668 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: format
#line 669 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: function_list
#line 670 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: guard_rails
#line 671 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: if_data
#line 672 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: map_list
#line 673 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: matrix_dim
#line 674 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 3633 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: max_refresh
#line 675 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3639 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 136: // characteristic_attribute: model_link
#line 676 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3645 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 137: // characteristic_attribute: number
#line 677 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 138: // characteristic_attribute: phys_unit
#line 678 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // characteristic_attribute: read_only
#line 679 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3663 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // characteristic_attribute: ref_memory_segment
#line 680 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3669 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // characteristic_attribute: step_size
#line 681 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // characteristic_attribute: symbol_link
#line 682 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3681 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // characteristic_attribute: virtual_characteristic
#line 683 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3687 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_method: A2L_BEGIN COMPU_METHOD ident_or_keyword STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 685 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                              {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 3700 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 147: // compu_method_attribute: coeffs
#line 696 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::deque<double> > ()); }
#line 3706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_method_attribute: coeffs_linear
#line 697 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::deque<double> > ()); }
#line 3712 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_method_attribute: compu_tab_ref
#line 698 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3718 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 150: // compu_method_attribute: formula
#line 699 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3728 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 151: // compu_method_attribute: ref_unit
#line 704 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3734 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 152: // compu_method_attribute: status_string_ref
#line 705 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3740 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 153: // compu_tab: A2L_BEGIN COMPU_TAB ident_or_keyword STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 708 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, double> > ());
	}
#line 3753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 156: // compu_tab_attribute: default_value
#line 719 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3759 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // compu_tab_attribute: default_value_numeric
#line 720 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3765 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 158: // compu_vtab: A2L_BEGIN COMPU_VTAB ident_or_keyword STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 723 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, std::string> > ());
	}
#line 3778 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // compu_vtab_attribute: default_value
#line 733 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE ident_or_keyword STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 736 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 3796 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 165: // compu_vtab_range_attribute: default_value
#line 745 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtabRange().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3802 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 169: // controller_address: any_uint IDENT any_uint any_uint
#line 752 "D:/projects/a2llib/src/a2lparser.y"
                                                     {
    A2lControllerAddress address;
    address.Index = yystack_[3].value.as < uint64_t > ();
    address.ByteOrder = StringToByteOrder(yystack_[2].value.as < std::string > ());
    address.StartAddress = yystack_[1].value.as < uint64_t > ();
    address.Length = yystack_[0].value.as < uint64_t > ();
    auto& module = scanner.CurrentModule();
    module.AddControllerAddress(address);
    }
#line 3816 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 170: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 762 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 3824 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // def_characteristic: DEF_CHARACTERISTIC ident_list
#line 765 "D:/projects/a2llib/src/a2lparser.y"
                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 3832 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 172: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 770 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 3838 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 772 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::deque<double> > () = std::move(yystack_[2].value.as < std::deque<double> > ()); }
#line 3844 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 774 "D:/projects/a2llib/src/a2lparser.y"
                                                                    {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()};
    }
#line 3852 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // formula: FORMULA STRING formula_attribute
#line 777 "D:/projects/a2llib/src/a2lparser.y"
                                       {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};
    }
#line 3860 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // formula_attribute: %empty
#line 780 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3866 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 177: // formula_attribute: formula_inv
#line 781 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 3872 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 178: // frame: A2L_BEGIN FRAME ident_or_keyword STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 783 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 3884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // frame_attribute: frame_measurement
#line 792 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3890 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // frame_attribute: if_data
#line 793 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3896 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 795 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // function_attribute: annotation
#line 802 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // function_attribute: def_characteristic
#line 804 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3918 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // function_attribute: function_version
#line 805 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // function_attribute: if_data
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // function_attribute: in_measurement
#line 807 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 192: // function_attribute: loc_measurement
#line 808 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3942 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // function_attribute: out_measurement
#line 809 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3948 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 194: // function_attribute: ref_characteristic
#line 810 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // function_attribute: sub_function
#line 811 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 813 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3966 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // function_list: FUNCTION_LIST ident_list
#line 814 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3972 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 816 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3982 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 201: // group_attribute: annotation
#line 824 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3988 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 202: // group_attribute: function_list
#line 825 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3994 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // group_attribute: if_data
#line 826 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // group_attribute: ref_characteristic
#line 827 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4006 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // group_attribute: ref_measurement
#line 828 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4012 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // group_attribute: root
#line 829 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 4018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // group_attribute: sub_group
#line 830 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 832 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4033 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // header_attribute: project_no
#line 840 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 4042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // header_attribute: version
#line 843 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 4051 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 848 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
    yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
}
#line 4059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // in_measurement: IN_MEASUREMENT ident_list
#line 851 "D:/projects/a2llib/src/a2lparser.y"
                            {
      yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
}
#line 4067 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // instance: A2L_BEGIN INSTANCE ident_or_keyword STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 855 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                         {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 4079 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // instance_attribute: address_type
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4085 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 219: // instance_attribute: annotation
#line 865 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // instance_attribute: calibration_access
#line 866 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 4097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // instance_attribute: display_identifier
#line 867 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // instance_attribute: ecu_address_extension
#line 868 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // instance_attribute: if_data
#line 869 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // instance_attribute: layout
#line 870 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // instance_attribute: matrix_dim
#line 871 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4127 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // instance_attribute: max_refresh
#line 872 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4133 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // instance_attribute: model_link
#line 873 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 228: // instance_attribute: overwrite
#line 874 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 4146 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // instance_attribute: read_write
#line 876 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 4152 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // instance_attribute: symbol_link
#line 877 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4158 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 879 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4166 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // loc_measurement: LOC_MEASUREMENT ident_list
#line 882 "D:/projects/a2llib/src/a2lparser.y"
                                 {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4174 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 886 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 4180 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement: A2L_BEGIN MEASUREMENT ident_or_keyword STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 889 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4196 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: address_type
#line 902 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4202 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: annotation
#line 903 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4208 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: array_size
#line 904 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4214 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: bit_mask
#line 905 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4220 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: bit_operation
#line 906 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4226 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: byte_order
#line 907 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4232 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // measurement_attribute: discrete
#line 908 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4238 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // measurement_attribute: display_identifier
#line 909 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4244 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // measurement_attribute: ecu_address
#line 910 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // measurement_attribute: ecu_address_extension
#line 911 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // measurement_attribute: error_mask
#line 912 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // measurement_attribute: format
#line 913 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4268 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // measurement_attribute: function_list
#line 914 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4274 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // measurement_attribute: if_data
#line 915 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4280 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // measurement_attribute: layout
#line 916 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4286 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 252: // measurement_attribute: matrix_dim
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4292 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 253: // measurement_attribute: max_refresh
#line 918 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4298 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // measurement_attribute: model_link
#line 919 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4304 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // measurement_attribute: phys_unit
#line 920 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4310 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // measurement_attribute: read_write
#line 921 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4316 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 257: // measurement_attribute: ref_memory_segment
#line 922 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4322 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 258: // measurement_attribute: symbol_link
#line 923 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4328 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // measurement_attribute: virtual
#line 924 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4334 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 260: // memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes A2L_END MEMORY_LAYOUT
#line 927 "D:/projects/a2llib/src/a2lparser.y"
                                                       {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4346 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 261: // memory_layout: MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes
#line 934 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[1].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[0].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4358 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // memory_layout_attributes: %empty
#line 942 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4364 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 263: // memory_layout_attributes: memory_layout_attributes if_data
#line 943 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
        }
#line 4373 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 264: // prg_type: RESERVED
#line 948 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4379 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 265: // prg_type: IDENT
#line 949 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4385 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 266: // memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes A2L_END MEMORY_SEGMENT
#line 952 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 267: // memory_segment: MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes
#line 963 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4417 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // memory_segment_attributes: %empty
#line 974 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4423 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 269: // memory_segment_attributes: memory_segment_attributes if_data
#line 975 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	    yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	    yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4432 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 979 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4441 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_common_attribute: alignment_byte
#line 986 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4447 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_common_attribute: alignment_float16_ieee
#line 987 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4453 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 275: // mod_common_attribute: alignment_float32_ieee
#line 988 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4459 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 276: // mod_common_attribute: alignment_float64_ieee
#line 989 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4465 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 277: // mod_common_attribute: alignment_int64
#line 990 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4471 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 278: // mod_common_attribute: alignment_long
#line 991 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4477 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 279: // mod_common_attribute: alignment_word
#line 992 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4483 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_common_attribute: byte_order
#line 993 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4489 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_common_attribute: data_size
#line 994 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4495 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_common_attribute: deposit
#line 995 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4501 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 998 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = std::move(yystack_[3].value.as < std::string > ());
	if (scanner.GetParseModuleInformationOnly()) {
	  YYACCEPT;
	}
}
#line 4513 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // mod_par_attribute: addr_epk
#line 1008 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4519 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // mod_par_attribute: calibration_method
#line 1009 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // mod_par_attribute: cpu_type
#line 1010 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // mod_par_attribute: customer
#line 1011 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4537 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // mod_par_attribute: customer_no
#line 1012 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // mod_par_attribute: ecu
#line 1013 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4549 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // mod_par_attribute: ecu_calibration_offset
#line 1014 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // mod_par_attribute: epk
#line 1015 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // mod_par_attribute: memory_layout
#line 1016 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // mod_par_attribute: memory_segment
#line 1017 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // mod_par_attribute: no_of_interfaces
#line 1018 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // mod_par_attribute: phone_no
#line 1019 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // mod_par_attribute: supplier
#line 1020 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // mod_par_attribute: system_constant
#line 1021 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 301: // mod_par_attribute: user
#line 1022 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 302: // mod_par_attribute: version
#line 1023 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module: A2L_BEGIN MODULE module_name module_comment module_attributes A2L_END MODULE
#line 1025 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	//auto& module = scanner.CurrentModule();
	//module.Name($3);
	//module.Description($4);
}
#line 4619 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_name: IDENT
#line 1031 "D:/projects/a2llib/src/a2lparser.y"
                   {
	auto& module = scanner.CurrentModule();
	module.Name(std::move(yystack_[0].value.as < std::string > ()));
}
#line 4628 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_comment: STRING
#line 1036 "D:/projects/a2llib/src/a2lparser.y"
                       {
	auto& module = scanner.CurrentModule();
	module.Description(std::move(yystack_[0].value.as < std::string > ()));
}
#line 4637 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 308: // module_attribute: a2ml
#line 1043 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4643 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: axis_pts
#line 1044 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 4651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: blob
#line 1047 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 4659 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: characteristic
#line 1050 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 4667 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 312: // module_attribute: compu_method
#line 1053 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 4675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // module_attribute: compu_tab
#line 1056 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 4683 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // module_attribute: compu_vtab
#line 1059 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 4691 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 315: // module_attribute: compu_vtab_range
#line 1062 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 4699 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 316: // module_attribute: controller_addresses
#line 1065 "D:/projects/a2llib/src/a2lparser.y"
                               {}
#line 4705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // module_attribute: frame
#line 1066 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 4713 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // module_attribute: function
#line 1069 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 4721 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // module_attribute: group
#line 1072 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 4729 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // module_attribute: if_data
#line 1075 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4737 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // module_attribute: instance
#line 1078 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 4745 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // module_attribute: measurement
#line 1081 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 4753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 325: // module_attribute: record_layout
#line 1086 "D:/projects/a2llib/src/a2lparser.y"
                        {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
#line 4761 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 326: // module_attribute: transformer
#line 1089 "D:/projects/a2llib/src/a2lparser.y"
                      {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
#line 4769 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 327: // module_attribute: typedef_axis
#line 1092 "D:/projects/a2llib/src/a2lparser.y"
                       {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
#line 4777 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // module_attribute: typedef_blob
#line 1095 "D:/projects/a2llib/src/a2lparser.y"
                       {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
#line 4785 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 329: // module_attribute: typedef_characteristic
#line 1098 "D:/projects/a2llib/src/a2lparser.y"
                                 {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
#line 4793 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 330: // module_attribute: typedef_measurement
#line 1101 "D:/projects/a2llib/src/a2lparser.y"
                              {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
#line 4801 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 331: // module_attribute: typedef_structure
#line 1104 "D:/projects/a2llib/src/a2lparser.y"
                            {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
#line 4809 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 332: // module_attribute: unit
#line 1107 "D:/projects/a2llib/src/a2lparser.y"
               {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
#line 4817 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 333: // module_attribute: user_rights
#line 1110 "D:/projects/a2llib/src/a2lparser.y"
                      {
          auto& module = scanner.CurrentModule();
          module.AddUserRights(scanner.ReleaseUserRights()); }
#line 4825 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 335: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1115 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4833 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 336: // out_measurement: OUT_MEASUREMENT ident_list
#line 1118 "D:/projects/a2llib/src/a2lparser.y"
                                 {
       yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 337: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1122 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4851 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 340: // overwrite_attribute: conversion
#line 1129 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 341: // overwrite_attribute: extended_limits
#line 1130 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4863 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 342: // overwrite_attribute: format
#line 1131 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4869 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 343: // overwrite_attribute: input_quantity
#line 1132 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4875 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 344: // overwrite_attribute: limits
#line 1133 "D:/projects/a2llib/src/a2lparser.y"
                 {
	    scanner.CurrentOverwrite().LowerLimit(yystack_[0].value.as < A2lLimits > ().LowerLimit);
	    scanner.CurrentOverwrite().UpperLimit(yystack_[0].value.as < A2lLimits > ().UpperLimit);
	    }
#line 4884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // overwrite_attribute: monotony
#line 1137 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4890 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 346: // overwrite_attribute: phys_unit
#line 1138 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4896 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 347: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 351: // project_attribute: module
#line 1150 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 4915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // record_layout: A2L_BEGIN RECORD_LAYOUT ident_or_keyword record_layout_attributes A2L_END RECORD_LAYOUT
#line 1155 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                       {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 4924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 355: // record_layout_attribute: alignment_byte
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 4930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: alignment_float16_ieee
#line 1162 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 4936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: alignment_float32_ieee
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 4942 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: alignment_float64_ieee
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 4948 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: alignment_int64
#line 1165 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 4954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: alignment_long
#line 1166 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 4960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: alignment_word
#line 1167 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 4966 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: axis_pts_x
#line 1168 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4972 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: axis_pts_y
#line 1169 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4978 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: axis_pts_z
#line 1170 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: axis_pts_4
#line 1171 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4990 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: axis_pts_5
#line 1172 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4996 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: axis_rescale_x
#line 1173 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 5002 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: dist_op_x
#line 1174 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5008 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: dist_op_y
#line 1175 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5014 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: dist_op_z
#line 1176 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5020 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: dist_op_4
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5026 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: dist_op_5
#line 1178 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5032 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: fix_no_axis_pts_x
#line 1179 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 5038 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: fix_no_axis_pts_y
#line 1180 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 5044 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: fix_no_axis_pts_z
#line 1181 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 5050 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: fix_no_axis_pts_4
#line 1182 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 5056 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: fix_no_axis_pts_5
#line 1183 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 5062 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: fnc_values
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 5068 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: identification
#line 1185 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 5074 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: no_axis_pts_x
#line 1186 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5080 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: no_axis_pts_y
#line 1187 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5086 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: no_axis_pts_z
#line 1188 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5092 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: no_axis_pts_4
#line 1189 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5098 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: no_axis_pts_5
#line 1190 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5104 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: no_rescale_x
#line 1191 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5110 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: offset_x
#line 1192 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5116 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // record_layout_attribute: offset_y
#line 1193 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5122 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // record_layout_attribute: offset_z
#line 1194 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5128 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // record_layout_attribute: offset_4
#line 1195 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5134 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // record_layout_attribute: offset_5
#line 1196 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5140 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 391: // record_layout_attribute: reserved
#line 1197 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 5146 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 392: // record_layout_attribute: rip_addr_w
#line 1198 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 5152 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // record_layout_attribute: rip_addr_x
#line 1199 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5158 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // record_layout_attribute: rip_addr_y
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5164 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // record_layout_attribute: rip_addr_z
#line 1201 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5170 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // record_layout_attribute: rip_addr_4
#line 1202 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5176 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // record_layout_attribute: rip_addr_5
#line 1203 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5182 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // record_layout_attribute: src_addr_x
#line 1204 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5188 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // record_layout_attribute: src_addr_y
#line 1205 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5194 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 400: // record_layout_attribute: src_addr_z
#line 1206 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5200 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 401: // record_layout_attribute: src_addr_4
#line 1207 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5206 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // record_layout_attribute: src_addr_5
#line 1208 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5212 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // record_layout_attribute: shift_op_x
#line 1209 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5218 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // record_layout_attribute: shift_op_y
#line 1210 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5224 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 405: // record_layout_attribute: shift_op_z
#line 1211 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5230 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 406: // record_layout_attribute: shift_op_4
#line 1212 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5236 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 407: // record_layout_attribute: shift_op_5
#line 1213 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 408: // record_layout_attribute: static_address_offsets
#line 1214 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 409: // record_layout_attribute: static_record_layout
#line 1215 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5254 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1217 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // ref_characteristic: REF_CHARACTERISTIC ident_list
#line 1220 "D:/projects/a2llib/src/a2lparser.y"
                                    {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5270 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1223 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5276 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 413: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1224 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5282 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 414: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1227 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = std::move(yystack_[5].value.as < std::string > ());
        structure.Typedef = yystack_[4].value.as < std::string > ();
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 417: // structure_component_attribute: address_type
#line 1235 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 418: // structure_component_attribute: layout
#line 1236 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 419: // structure_component_attribute: matrix_dim
#line 1237 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // structure_component_attribute: symbol_type_link
#line 1238 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 421: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1240 "D:/projects/a2llib/src/a2lparser.y"
                                                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5325 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 422: // sub_function: SUB_FUNCTION ident_list
#line 1243 "D:/projects/a2llib/src/a2lparser.y"
                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5333 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 423: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1247 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5339 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 424: // transformer: A2L_BEGIN TRANSFORMER ident_or_keyword STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1250 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5354 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 427: // transformer_attribute: transformer_in_objects
#line 1262 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5360 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 428: // transformer_attribute: transformer_out_objects
#line 1263 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5366 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1265 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5372 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1266 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5378 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS ident_or_keyword STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1269 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 434: // typedef_axis_attribute: byte_order
#line 1283 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 435: // typedef_axis_attribute: deposit
#line 1284 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 436: // typedef_axis_attribute: extended_limits
#line 1285 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5413 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 437: // typedef_axis_attribute: format
#line 1286 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5419 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_axis_attribute: monotony
#line 1287 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5425 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 439: // typedef_axis_attribute: phys_unit
#line 1288 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 440: // typedef_axis_attribute: step_size
#line 1289 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5437 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 441: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB ident_or_keyword STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1291 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 444: // typedef_blob_attribute: address_type
#line 1299 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5454 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC ident_or_keyword STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1302 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 448: // typedef_characteristic_attribute: axis_descr
#line 1315 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5479 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 449: // typedef_characteristic_attribute: bit_mask
#line 1319 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5485 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 450: // typedef_characteristic_attribute: byte_order
#line 1320 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 451: // typedef_characteristic_attribute: discrete
#line 1321 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5497 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_characteristic_attribute: encoding
#line 1322 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5503 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 453: // typedef_characteristic_attribute: extended_limits
#line 1323 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 454: // typedef_characteristic_attribute: format
#line 1324 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5515 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 455: // typedef_characteristic_attribute: matrix_dim
#line 1325 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5521 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 456: // typedef_characteristic_attribute: number
#line 1326 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5527 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // typedef_characteristic_attribute: phys_unit
#line 1327 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5533 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // typedef_characteristic_attribute: step_size
#line 1328 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5539 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT ident_or_keyword STRING IDENT IDENT any_uint any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1331 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 462: // typedef_measurement_attribute: address_type
#line 1344 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 463: // typedef_measurement_attribute: bit_mask
#line 1345 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 464: // typedef_measurement_attribute: bit_operation
#line 1346 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // typedef_measurement_attribute: byte_order
#line 1347 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 466: // typedef_measurement_attribute: discrete
#line 1348 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 467: // typedef_measurement_attribute: error_mask
#line 1349 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 468: // typedef_measurement_attribute: format
#line 1350 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // typedef_measurement_attribute: layout
#line 1351 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 470: // typedef_measurement_attribute: matrix_dim
#line 1352 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 471: // typedef_measurement_attribute: phys_unit
#line 1353 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE ident_or_keyword STRING any_uint typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1356 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 475: // typedef_structure_attribute: address_type
#line 1364 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 476: // typedef_structure_attribute: consistent_exchange
#line 1365 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5638 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 477: // typedef_structure_attribute: structure_component
#line 1366 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5646 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // typedef_structure_attribute: symbol_type_link
#line 1369 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5652 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 479: // unit: A2L_BEGIN UNIT ident_or_keyword STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1371 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5664 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 482: // unit_attribute: ref_unit
#line 1380 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5670 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // unit_attribute: si_exponents
#line 1381 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5676 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // unit_attribute: unit_conversion
#line 1382 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5685 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1387 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_rights = scanner.CurrentUserRights();
       user_rights.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5694 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // user_rights_attribute: read_only
#line 1393 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRights().ReadOnly = true; }
#line 5700 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // user_rights_attribute: ref_group
#line 1394 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRights().RefGroupList.emplace_back(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1396 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5714 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 491: // var_address: VAR_ADDRESS uint_list
#line 1399 "D:/projects/a2llib/src/a2lparser.y"
                            {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ());
    }
#line 5722 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1404 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = std::move(yystack_[3].value.as < std::deque<std::string> > ());
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5732 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 493: // var_characteristic_attribute: %empty
#line 1409 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5738 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 494: // var_characteristic_attribute: var_address
#line 1410 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5744 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 495: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1412 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCriterion > ().Description = std::move(yystack_[3].value.as < std::string > ());
}
#line 5755 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // var_criterion_attribute: var_measurement
#line 1421 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = std::move(yystack_[0].value.as < std::string > ()); }
#line 5761 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // var_criterion_attribute: var_selection_characteristic
#line 1422 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = std::move(yystack_[0].value.as < std::string > ()); }
#line 5767 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1424 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ()); }
#line 5773 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // variant_coding_attribute: var_characteristic
#line 1429 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5782 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // variant_coding_attribute: var_criterion
#line 1433 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5791 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // variant_coding_attribute: var_forbidden_comb
#line 1437 "D:/projects/a2llib/src/a2lparser.y"
                             {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(std::move(yystack_[0].value.as < std::map<std::string, std::string> > ()));
       }
#line 5800 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // variant_coding_attribute: var_naming
#line 1441 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = std::move(yystack_[0].value.as < std::string > ());
       }
#line 5809 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // variant_coding_attribute: var_separator
#line 1445 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = std::move(yystack_[0].value.as < std::string > ());
      }
#line 5818 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1450 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5826 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // virtual: VIRTUAL ident_list
#line 1453 "D:/projects/a2llib/src/a2lparser.y"
                         {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5834 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1457 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 5840 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // a2ml: A2ML
#line 1460 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5846 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1461 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1466 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5864 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // asap2_version: ASAP2_VERSION STRING
#line 1469 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5872 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // addr_epk: ADDR_EPK any_uint
#line 1473 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5878 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // address_type: ADDRESS_TYPE IDENT
#line 1474 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1475 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5890 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1476 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5896 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1477 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5902 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1478 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5908 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1479 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5914 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 523: // alignment_long: ALIGNMENT_LONG any_uint
#line 1480 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5920 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // alignment_word: ALIGNMENT_WORD any_uint
#line 1481 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5926 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // annotation_label: ANNOTATION_LABEL STRING
#line 1482 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5932 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1483 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5938 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 527: // array_size: ARRAY_SIZE any_uint
#line 1484 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5944 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1485 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 5950 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1486 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5956 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1487 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5967 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1493 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5978 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1499 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5989 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 533: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1505 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 534: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1511 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1517 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6023 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // bit_mask: BIT_MASK any_uint
#line 1524 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6029 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // byte_order: A2L_BYTE_ORDER IDENT
#line 1525 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 6035 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1526 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 6041 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1527 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6047 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1528 "D:/projects/a2llib/src/a2lparser.y"
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
#line 6062 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1538 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::deque<double> list;
	list.emplace_back(yystack_[1].value.as < double > ());
	list.emplace_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::deque<double> > () = std::move(list);
       }
#line 6073 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1544 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6079 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6085 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // conversion: CONVERSION IDENT
#line 1547 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // cpu_type: CPU_TYPE STRING
#line 1548 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 547: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1549 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // customer: CUSTOMER STRING
#line 1550 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // customer_no: CUSTOMER_NO STRING
#line 1551 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // data_size: DATA_SIZE any_uint
#line 1552 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // default_value: DEFAULT_VALUE STRING
#line 1553 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6127 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1554 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6133 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // deposit: DEPOSIT IDENT
#line 1555 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 6139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 555: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1557 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1558 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());}
#line 6151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1559 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6160 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1563 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1567 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1571 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6187 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1575 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6196 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // ecu: ECU STRING
#line 1579 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6202 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // ecu_address: ECU_ADDRESS any_uint
#line 1580 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6208 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1581 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6214 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1582 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6220 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // encoding: ENCODING IDENT
#line 1583 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 6226 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // epk: EPK STRING
#line 1584 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6232 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // error_mask: ERROR_MASK any_uint
#line 1585 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6238 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1586 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 6244 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1587 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1588 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 572: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1589 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1590 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6268 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1591 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6274 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 575: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1592 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6280 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1593 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6286 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1594 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6297 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // format: FORMAT STRING
#line 1600 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6303 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // formula_inv: FORMULA_INV STRING
#line 1601 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6309 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1602 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 6315 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // function_version: FUNCTION_VERSION STRING
#line 1603 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6321 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // identification: IDENTIFICATION any_uint IDENT
#line 1605 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6330 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // if_data: IF_DATA
#line 1609 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6336 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // input_quantity: INPUT_QUANTITY IDENT
#line 1610 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6342 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // layout: LAYOUT IDENT
#line 1611 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6348 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // left_shift: LEFT_SHIFT any_uint
#line 1612 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6354 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // limits: LIMITS any_float any_float
#line 1613 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < A2lLimits > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()}; }
#line 6360 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // matrix_dim: MATRIX_DIM uint_list
#line 1614 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 6366 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // max_grad: MAX_GRAD any_float
#line 1615 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6372 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 591: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1616 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6378 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 592: // model_link: MODEL_LINK STRING
#line 1617 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6384 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // monotony: MONOTONY IDENT
#line 1618 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6390 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1619 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1623 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6408 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1627 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6417 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 597: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1631 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 598: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1635 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6435 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1639 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6441 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1640 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // number: NUMBER any_uint
#line 1644 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6456 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 602: // offset_x: OFFSET_X any_uint IDENT
#line 1645 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6465 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 603: // offset_y: OFFSET_Y any_uint IDENT
#line 1649 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 604: // offset_z: OFFSET_Z any_uint IDENT
#line 1653 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6483 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 605: // offset_4: OFFSET_4 any_uint IDENT
#line 1657 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6492 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 606: // offset_5: OFFSET_5 any_uint IDENT
#line 1661 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6501 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // phone_no: PHONE_NO STRING
#line 1665 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6507 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // phys_unit: PHYS_UNIT STRING
#line 1666 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6513 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // proj_no: IDENT
#line 1667 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6519 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 610: // proj_no: any_uint
#line 1668 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 611: // project_no: PROJECT_NO proj_no
#line 1669 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 614: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1673 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6537 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 615: // ref_unit: REF_UNIT IDENT
#line 1674 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // reserved: RESERVED any_uint IDENT
#line 1675 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
    yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    }
#line 6552 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 617: // right_shift: RIGHT_SHIFT any_uint
#line 1679 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6558 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 618: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1680 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1684 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6576 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1688 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 621: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1692 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6594 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1696 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1700 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6612 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 626: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1706 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1710 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6630 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 628: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1714 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6639 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 629: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1718 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6648 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 630: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1722 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 632: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1727 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6671 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 633: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1736 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6680 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 634: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1740 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6689 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 635: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1744 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6698 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 636: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1748 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6707 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 637: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1752 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6716 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 640: // status_string_ref: STATUS_STRING_REF IDENT
#line 1758 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6722 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 641: // step_size: STEP_SIZE any_float
#line 1759 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6728 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 642: // supplier: SUPPLIER STRING
#line 1760 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6734 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 643: // symbol_link: SYMBOL_LINK STRING any_int
#line 1761 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6740 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 644: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1762 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6746 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 645: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1763 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6752 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 646: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1764 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6758 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 647: // user: USER STRING
#line 1765 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6764 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 648: // var_measurement: VAR_MEASUREMENT IDENT
#line 1766 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6770 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 649: // var_naming: VAR_NAMING IDENT
#line 1767 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6776 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 650: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1768 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6782 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 651: // var_separator: VAR_SEPARATOR STRING
#line 1769 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6788 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 652: // version: A2L_VERSION STRING
#line 1770 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6794 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6798 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -930;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
     122,   393,   119,   133,  -930,  -930,  -930,  -930,  -930,   297,
    -930,  -119,   297,  -930,  -930,  -930,    72,   297,   135,  -930,
     146,   -14,  -930,  -930,   306,  -930,   165,   147,    33,  -930,
    -930,  -930,   173,  -930,    59,  -930,  -930,    79,   206,   211,
    -930,  -930,  -930,    61,  -930,  -930,  -930,  -930,  -930,   821,
     100,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,   541,   541,   541,   541,   541,   541,   541,  -930,   541,
     231,   239,   541,   541,   291,   316,   541,   541,   541,   541,
     541,   541,   541,   541,   294,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,   322,   328,   331,   333,   348,   351,
     352,   374,   359,   366,   372,   380,   389,  -930,  -930,  -930,
     390,   397,   401,   402,   406,   407,   414,  -930,    38,   297,
     297,   307,   375,   404,   416,   297,   278,   418,  -930,   297,
    -930,  -930,   420,   421,   961,   308,  1029,   424,   428,   297,
     429,   431,   297,   434,    41,   131,   235,   439,   448,  -930,
    -930,  -930,  -930,  -930,  -930,   451,   297,   297,   454,   297,
     297,  -930,  -930,   297,   297,   357,    53,   297,   452,   340,
     297,   297,   297,   297,   297,   297,   297,   462,   297,   463,
     474,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,    36,   360,   297,   481,   483,   488,   492,
     343,   494,   475,   496,   297,   501,   504,   509,   513,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,   355,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,   515,   517,  -930,   518,   519,  -930,   521,   383,   332,
    -930,  -930,  -930,  -930,   528,   529,  -930,  -930,  -930,  -930,
     530,  -930,   531,   533,  -930,  -930,   408,   297,  -930,   537,
     449,  -930,   544,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   311,
     445,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,   297,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,   549,   551,   553,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   297,
     556,  -930,  -930,  -930,   559,  -930,  -930,   554,   563,   564,
     565,   566,   567,   569,   570,   573,   580,   582,  -930,  -930,
    -930,  -930,  -930,   583,   586,   587,   590,   594,   596,   599,
     600,   601,   603,   604,   606,   609,   614,   615,   616,   618,
     620,   621,   625,   626,   627,   628,   631,   632,   633,   638,
     649,   652,   653,   297,   408,   120,   408,   297,    45,  -930,
    -930,  -930,  -930,   660,   195,   408,   591,   408,  -930,   408,
     408,  -930,  -930,  -930,  -930,   408,   107,  -930,    66,  -930,
     661,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   541,  -930,
     541,   541,   541,   541,   541,  -930,  -930,  -930,  -930,   541,
     639,   408,   297,   297,   662,   297,    15,  -930,   664,   666,
     667,   670,   672,   297,  -930,  -930,  -930,  -930,  -930,   674,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   675,
     676,   500,   677,  -930,  -930,   679,   408,   417,   493,  -930,
     685,  -930,  -930,  -930,  -930,  -930,    11,   466,   314,  -930,
     499,   689,   700,    71,   665,   701,   706,   343,   297,   708,
     713,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,   707,    55,   408,    73,   714,   121,   717,   669,   721,
    -930,  -930,   634,  -930,  -930,  -930,  -930,   208,   705,   684,
     776,   944,  1028,  1032,  1165,  -930,  1166,  1206,  1207,    25,
     629,   725,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   408,  -930,
     297,    15,  -930,  -930,  -930,   731,   735,   736,   739,   742,
     743,   745,   746,   748,   297,  -930,  -930,   408,   408,   750,
    -930,  -930,   568,   754,   343,   408,  -930,  -930,  -930,  -930,
     617,   571,  -930,  -930,   762,    13,  -930,  -930,   297,   763,
    -930,  -930,  -930,  -930,   297,  -930,   343,   408,   683,   715,
     408,   408,   765,   766,   775,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,   718,   408,  -930,  -930,  -930,  -930,   728,
    -930,  -930,  -930,  -930,  -930,  -930,   541,   760,   768,   783,
     784,  -930,  -930,  -930,   788,   791,  -930,   730,   692,   688,
     657,   656,   630,   711,   655,   635,   801,  -930,  -930,   297,
     408,   312,  -930,   802,   343,   803,  -930,  -930,  -930,  -930,
    -930,   807,  -930,  -930,   408,   408,   408,   808,  -930,  -930,
     343,   408,  -930,  -930,   297,   622,   619,   810,   815,  -930,
    -930,  -930,   408,   823,  -930,  -930,   408,   822,  -930,   408,
     408,  -930,   737,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,   798,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,   297,  -930,  -930,   786,   785,  -930,   343,   829,
    -930,   733,   297,  -930,   315,   408,  -930,  -930,   297,   343,
    -930,   384,  -930,  -930,  -930,  -930,   408,   771,  -930,   737,
     408,  -930,   839,  -930,  -930,    78,  -930,  -930,   403,  -930,
    -930,    56,   297,  -930,   297,   137,   673,  -930,  -930,  -930,
    -930,   774,   827,  -930,   343,   648,  -930,  -930,   658,   844,
     408,  -930,   824,  -930,   330,     1,   744,   297,   297,  -930,
     297,   297,   842,   854,   856,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
      84,   747,   297,  -930,  -930,  -930,  -930,   310,   833,   680,
     860,   408,   297,   408,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,   831,   686,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,    51,
     343,  -930,   473,    -3,   835,   870,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,   789,   408,  -930,   741,   880,
     881,   408,   882,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,   541,   884,   885,  -930,  -930,  -930,   343,  1228,  1229,
     702,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   887,
    -930,  -930,   408,  -930,  -930,  -930,   719,  -930,  -930,  -930,
    -930,  -930,   343,    49,   861,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,   890,  -930,   894,  -930,  -930,
    -930,   408,  -930,  -930,  -930,   408,  -930,    16,  1233,  -930,
     857,   343,   733,   716,   723,  -930,   896,  -930,  -930,   343,
    -930,  -930,  1255,  -930,  -930,  -930,   863,   297,   297,  -930,
    -930,  -930,  -930,  -930,   710,  -930,    63,  -930,  -930,  -930,
     907,  -930,  1293,   799,  1297,  -930,  -930,  -930,  -930,   794,
     297,   847,  -930,   720,  -930,   408,  -930,  -930,   408,  -930,
     579,   110,   888,   917,   919,   408,   408,   408,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,   408,   408,
    -930,   293,   297,   297,   838,  -930,  -930,  -930,  -930
  };

  const short
  A2lParser::yydefact_[] =
  {
      38,     0,     0,     0,    39,   515,     4,     2,     3,     0,
       1,     0,     0,    37,    40,   514,     0,     0,     0,   513,
       0,     0,   350,   351,     0,   348,     0,     0,     0,   349,
     209,   304,     0,   347,     0,   305,   306,     0,     0,     0,
     210,   211,   212,     0,   208,   652,   609,   610,   611,     0,
       0,   512,   584,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   321,   322,   323,   324,   307,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   308,
     320,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   502,   303,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   285,   353,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,     0,
     184,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
     505,   506,   503,   507,   508,     0,     0,     0,     0,     0,
       0,    22,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     295,   296,   286,   287,   289,   290,   291,   292,   293,   294,
     297,   298,   299,   300,   301,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,   639,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   403,
     404,   405,   406,   407,   398,   399,   400,   401,   402,   408,
     409,     0,     0,   442,     0,     0,   473,     0,     0,     0,
     612,   489,   487,   488,     0,     0,    35,   501,   649,   651,
       0,    97,     0,     0,    18,    20,   163,     0,   179,     0,
       0,    33,     0,    33,    33,    33,    33,    33,   186,   187,
     188,   185,   191,   192,   193,   194,   195,   189,   190,     0,
       0,    33,   624,   201,   202,   200,   204,   205,   207,   203,
     206,   216,     0,   270,   518,   519,   520,   521,   522,   523,
     524,   537,   550,   553,   625,     0,     0,     0,   284,   516,
     546,   548,   549,   562,     5,     6,     7,   565,   567,     0,
       0,   599,   607,   642,     0,   647,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,   576,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
      33,   485,    33,     0,     0,     0,     0,     0,   145,   154,
     159,     9,    10,    11,     8,     0,     0,   169,     0,    42,
       0,    33,    33,    33,    33,    33,    33,   183,   171,   581,
     214,   232,   336,   411,   422,    33,    33,    33,   198,   197,
       0,     0,     0,     0,     0,     0,     0,   645,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,   561,     0,
     583,   594,   595,   596,   597,   598,   600,   602,   603,   604,
     605,   606,   616,   618,   619,   620,   621,   622,   623,   626,
     627,   628,   629,   630,   633,   634,   635,   636,   637,     0,
       0,     0,     0,   443,   444,     0,     0,     0,     0,   544,
       0,   477,   474,   475,   476,   478,     0,     0,   493,   496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,    98,    99,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,     0,    33,   180,   181,   182,     0,    48,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    14,   613,   219,   217,   228,   218,   220,   221,
     222,   223,   224,   225,   226,   227,   229,   230,     0,   112,
       0,     0,    12,   265,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   441,   517,     0,     0,     0,
     472,   644,     0,     0,     0,     0,   481,   482,   483,   484,
       0,     0,    14,   494,     0,     0,   500,    36,     0,     0,
      96,   538,   555,   564,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   150,   147,   148,   149,
     151,   152,    19,     0,     0,   155,   156,   157,    21,     0,
     160,   161,    23,   162,   551,   178,   580,     0,     0,     0,
       0,    45,    43,    44,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   586,   589,
       0,     0,    12,     0,   262,     0,   530,   531,   532,   533,
     534,     0,   577,   425,     0,     0,     0,     0,   479,   615,
       0,     0,   412,    14,   491,     0,     0,     0,     0,   497,
     498,   499,     0,     0,   591,   643,     0,     0,   144,     0,
       0,   543,   176,   640,   153,   552,   158,    24,    41,   525,
     526,   528,     0,   170,   213,   231,   335,   410,   421,   196,
     413,   423,     0,    15,   235,     0,     0,   113,   262,     0,
      13,   261,     0,   535,     0,     0,   446,   460,     0,     0,
     646,     0,   492,   495,   648,   650,     0,     0,   115,   176,
       0,   541,     0,   175,   177,     0,    47,   338,     0,    12,
     111,     0,     0,   263,     0,     0,     0,   426,   427,   428,
     432,     0,     0,   415,     0,     0,    69,   556,     0,     0,
       0,   579,     0,    25,     0,     0,     0,     0,     0,   554,
       0,     0,     0,     0,     0,    33,   238,   241,   249,   236,
     259,   237,   239,   240,   242,   243,   244,   245,   246,   247,
     248,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     109,     0,     0,    12,    33,    33,   424,     0,     0,     0,
       0,     0,     0,     0,   448,   447,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,     0,     0,   464,   461,
     462,   463,   465,   466,   467,   468,   469,   470,   471,     0,
       0,   490,     0,     0,     0,     0,   582,   117,   118,   116,
     123,   130,   133,   143,   119,   120,   121,   122,   124,   125,
     126,   127,   128,   129,   131,   132,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,    46,     0,     0,
       0,     0,     0,   339,   340,   341,   342,   343,   344,   345,
     346,    91,    33,   234,   527,   536,   563,   568,   578,   608,
     614,   510,     0,     0,   110,   260,    12,   268,     0,     0,
       0,   433,   434,   435,   436,   437,   438,   439,   440,     0,
     445,   566,     0,   601,   641,   459,     0,   416,   417,   418,
     419,   420,     0,     0,     0,    71,    70,    79,    72,    73,
      74,    75,    76,    77,    78,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    33,     0,   114,   542,
     174,     0,   337,   545,   585,     0,   593,     0,     0,   539,
       0,   268,   267,     0,     0,   431,     0,   569,   414,     0,
      68,    33,     0,    33,   540,   588,     0,     0,     0,   631,
      92,    93,    94,    95,     0,   108,     0,   269,   429,   430,
       0,   632,     0,     0,     0,    90,   587,   617,   509,     0,
       0,     0,   233,     0,   266,     0,   172,   511,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    52,
      61,    54,    55,    56,    57,    58,    59,    60,    62,    63,
      64,    65,    66,    67,    16,    50,   529,   547,     0,     0,
     590,     0,     0,     0,     0,    17,   570,   571,   173
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -930,    -1,  -219,  -166,  -747,  -651,  -930,  -930,  -930,  -930,
    -930,  1280,  -297,  -930,  -930,  -930,  -184,  -930,  -930,  -930,
    -930,    29,  -930,  -930,  -930,  -930,  -930,    40,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,    64,
    -930,  -930,  -930,  -930,  -930,  -930,  -827,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,    80,   249,  -930,  -177,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,   912,  -930,  -930,  -930,   751,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -493,   790,
     793,   796,   800,   804,   805,   806,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -791,  -864,  -534,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -393,  -930,  -929,  -765,  -536,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -533,  -930,    57,  -930,    62,  -867,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -868,  -930,
    -930,  -930,   -35,  -930,   -40,  -930,  -779,  -930,  -930,  -769,
    -930,  -531,  -530,  -928,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,    60,  -930,  -930,  -930,  -930,  -930,  -930,  -852,  -930,
    -930,  -865,    81,  -823,   334,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,  -930,
    -866,  -930,  -528,   -16,  -930,  -930,  -930,  -930,  -930,  -930,
    -930,   809
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   843,   850,   515,   784,   779,  1191,   509,   510,   376,
     875,   655,   528,   504,     2,     3,   388,   647,   761,   389,
     765,   954,  1160,  1169,    53,   982,  1076,   917,  1107,  1130,
      54,   506,   622,   847,  1043,   229,   781,    55,   898,   989,
      56,   632,   735,    57,   634,   745,    58,   636,   750,    59,
     516,   640,    60,   121,   148,   390,   990,  1170,   736,   873,
      61,   518,   644,    62,   185,   391,   404,    63,   186,   405,
      22,    34,    40,   392,    64,   540,   665,   393,   992,    65,
     878,   919,   230,   851,   685,   231,  1112,    66,   154,   201,
      67,   155,   232,    23,    32,    36,    43,    68,   394,   666,
     904,  1023,    13,    24,    25,    69,   156,   295,   395,   361,
     407,   601,   979,  1067,   396,   408,    70,   854,   887,   888,
     889,    71,   947,  1051,    72,   495,   593,    73,   891,   955,
      74,   892,   969,    75,   498,   602,    76,   606,   706,    77,
     164,   362,   713,   169,   714,   170,   715,   809,   171,    78,
     138,   172,   920,   993,    79,    14,     4,   233,   594,   202,
     203,   204,   205,   206,   207,   208,   762,   763,   922,   766,
    1171,   303,   304,   305,   306,   307,   308,   923,   209,   624,
    1044,   737,   738,   997,   739,   604,  1024,   234,  1173,   235,
     236,   210,   641,   747,   211,   925,   625,   309,   310,   311,
     312,   313,   237,   927,   626,   238,   959,   239,   929,   960,
    1176,  1177,   314,   315,   316,   317,   318,   319,   930,   874,
     645,   397,  1004,   320,   883,  1027,   672,  1131,  1028,   673,
    1179,   628,   629,  1029,   321,   322,   323,   324,   325,   240,
     326,   963,   327,   328,   329,   330,   331,   241,   936,    48,
      41,   363,   676,   938,   707,   332,  1132,   333,   334,   335,
     336,   337,   338,   410,   212,   339,   340,   341,   342,   343,
    1133,   708,   344,   345,   346,   347,   348,   349,   350,   741,
     965,   242,   630,   605,   243,   709,   244,   810,   173,   811,
     174,    42
  };

  const short
  A2lParser::yytable_[] =
  {
       9,   437,   403,    80,   669,   603,   668,   670,    15,   674,
     675,    17,   677,   623,   924,   702,    19,   806,  1053,  1056,
    1126,   683,   519,   961,   975,    16,   519,   957,   972,  1059,
    1003,  1002,  1013,  1011,   995,   848,  1026,  1025,    47,   964,
     978,   165,   166,  1031,   358,   359,  1010,   667,   597,   598,
     519,   918,  1030,  1080,  1089,  1066,   399,   400,   728,   729,
     941,   804,   592,    37,    49,    50,  1095,  1149,   592,   719,
     642,   991,    38,   719,   519,  1012,    51,   743,    18,  1055,
    1054,  1058,   902,  1052,   425,   903,   530,   531,   532,   533,
     534,    26,   434,   435,   436,  1057,   519,   719,   535,   932,
     956,   971,   535,   599,   539,   730,   731,   994,    27,   933,
     732,   638,  1096,   976,  1084,  1083,  1093,  1091,  1078,    10,
     147,   719,   962,   977,   591,   749,   958,   973,  1127,  1006,
    1090,  1042,   940,   998,     1,   519,    11,   592,   175,   176,
     639,   744,    20,   719,   181,   398,   409,    12,   184,    21,
     535,   733,   861,    31,   401,  1077,   426,   427,   353,  1092,
      52,   356,   661,    52,   703,   643,   776,   662,    52,   684,
      52,  1128,    30,    52,   639,   371,   372,    33,   374,   375,
      35,   704,   377,   378,    44,  1129,   411,   360,   639,   414,
     415,   416,   417,   418,   419,   420,  1047,   422,  1184,   610,
    1069,   611,   386,   607,    39,   608,  1097,   705,   703,  1032,
    1070,   757,   758,    45,   429,   402,   807,    46,   808,     6,
       7,     8,   106,   441,   649,   650,   651,   652,   653,   654,
     600,  1174,  1180,   734,   759,   760,   600,   123,   656,   657,
     658,   746,   167,   751,   168,   124,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,  1178,  1175,  1183,  1182,  1172,  1194,   127,  1111,
     137,   511,   512,   513,   514,     6,     7,     8,  1181,    21,
      28,   213,   214,   177,  1050,   845,   846,   711,   885,   886,
     107,    38,   621,   128,   215,   944,   945,   108,   590,   139,
     595,   364,   365,   366,  1018,   140,   519,   182,   141,   612,
     142,   631,   926,   633,   635,   928,   756,   934,   935,   637,
     939,   434,   435,   436,   197,   143,   664,   109,   144,   145,
     379,   380,   999,   110,   996,  1000,   149,  1007,  1008,   216,
    1014,   217,   218,   150,   111,   678,   517,   112,   146,   151,
     199,   178,     6,     7,     8,   921,   219,   152,   895,   220,
    1019,   221,     6,     7,     8,   951,   153,   157,   723,   970,
       5,     6,     7,     8,   158,   912,   905,   906,   159,   160,
     179,   541,   535,   161,   162,   951,   511,   512,   513,   514,
     592,   163,   180,   381,   183,   912,   187,   188,   222,   223,
     698,   351,   907,   113,   352,   354,  1022,   355,   545,  1020,
     224,   357,   367,  1021,   908,   368,  1081,   197,  1079,  1082,
     225,  1087,  1088,   913,  1094,   369,  1022,   370,   412,   382,
     525,   373,   536,   413,    52,   383,   627,   742,   421,   423,
     710,   384,   107,   913,   909,   616,  1073,  1074,   646,   108,
     424,   439,   910,   617,   428,   800,  1068,   911,   430,   953,
     431,   226,   589,   537,   227,   432,   596,   385,   912,   433,
     671,   438,   440,   446,   401,   228,   386,   815,   442,   109,
      52,   443,   780,   712,   661,   110,   444,   197,   615,   662,
     445,   618,   493,   494,   496,   497,   111,   499,   619,   112,
     501,   795,   796,   500,   502,   503,   505,   507,   387,   801,
     508,   679,   680,   199,   682,   616,   913,   107,   538,   527,
     663,   529,   691,   617,   108,   914,   542,   543,   951,   544,
     548,   816,   519,   546,   819,   820,   547,   520,   912,   549,
     550,   551,   552,   553,   401,   554,   555,   986,   825,   556,
      52,   859,  1161,  1162,   109,   113,   557,   620,   558,   559,
     110,   618,   560,   561,   613,   614,   562,   699,   619,  1022,
     563,   111,   564,   521,   112,   565,   566,   567,   592,   568,
     569,   915,   570,  1163,   844,   571,   913,   724,  1041,   360,
     572,   573,   574,   197,   575,   914,   576,   577,   855,   856,
     857,   578,   579,   580,   581,   860,   615,   582,   583,   584,
     894,  1164,   659,   660,   585,   522,   866,  1048,  1049,   199,
     868,   523,   953,   870,   871,   586,   592,   620,   587,   588,
     113,   983,   984,   616,   951,  1165,  1166,   609,   648,   681,
     686,   617,   687,   688,   912,   980,   689,   524,   690,   782,
     692,   693,   694,   696,   615,   697,   525,   700,   767,   890,
     107,   695,   701,   794,   916,   717,  1167,   108,    52,   908,
     896,   716,   197,   615,   900,  1022,   718,   721,   720,   618,
     985,   616,   722,   727,   987,   725,   619,   812,   526,   617,
     726,   748,   913,   814,   752,   360,   753,   109,   754,   909,
     616,   778,   755,   110,  1016,  1108,   764,   785,   617,   777,
     950,   786,   787,   951,   111,   788,    52,   112,   789,   790,
     661,   791,   792,   912,   793,   662,   797,   618,   953,   401,
     799,  1072,   986,   798,   619,    52,   805,   802,   818,   813,
     803,   821,   824,   822,   662,   620,   618,   948,   949,   817,
     768,   823,   107,   619,   826,  1062,   663,  1064,   827,   108,
     829,   830,   952,   828,   831,   832,   833,   836,  1075,  1122,
     834,   913,   835,   113,   360,   837,   840,   842,   849,   852,
     914,   838,   839,   853,   858,   908,   864,   841,   197,   109,
     863,   865,   862,   620,  1142,   110,  1144,   867,   876,   869,
     966,   967,   879,   880,   872,   882,   111,   953,   931,   112,
      52,   877,   620,   897,   592,   909,   901,   981,  1015,  1038,
    1101,   884,  1017,  1119,    81,  1105,   950,   893,  1005,   951,
     946,  1039,  1040,  1033,    82,  1059,  1061,  1045,   908,   912,
      83,   197,  1060,  1031,    84,    85,  1099,    86,    87,  1065,
      88,   942,  1102,   943,  1098,  1100,  1103,  1104,  1106,  1110,
     662,  1109,  1115,  1116,  1120,   113,  1117,  1121,   909,  1118,
    1141,  1123,  1140,  1135,  1138,  1145,  1034,  1035,   952,  1036,
    1037,   911,  1139,  1150,  1152,  1154,  1156,   913,  1148,    89,
    1185,    90,   912,  1186,    91,  1187,  1198,   988,   881,  1157,
     783,    92,   968,   899,  1136,  1124,    29,   406,   661,  1125,
      93,  1046,  1086,   662,    94,    95,   296,  1085,   769,   297,
     107,  1063,   298,   953,   974,  1001,   299,   108,  1009,   937,
     300,   301,   302,  1071,   245,   189,   740,     0,     0,    96,
     913,     0,     0,     0,     0,     0,  1168,     0,     0,   190,
     191,   192,   193,   194,   195,   196,     0,   109,     0,  1158,
       0,     0,  1159,   110,     0,     0,     0,     0,     0,  1188,
    1189,  1190,     0,     0,   111,   197,     0,   112,    97,     0,
       0,    98,    99,   100,   101,   102,   103,     0,     0,   104,
       0,     0,  1192,  1193,     0,  1195,   198,     0,   105,     0,
       0,   199,   770,   246,   107,     0,   771,     0,   107,     0,
       0,   108,     0,     0,     0,   108,     0,   190,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   247,   248,   249,   250,   251,   252,
       0,   109,  1137,     0,     0,   109,     0,   110,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,   111,     0,
       0,   112,   111,     0,     0,   112,  1137,     0,     0,     0,
       0,     0,   253,   254,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
     260,   261,   262,   263,   200,     0,  1146,  1147,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,  1155,
       0,   113,     0,     0,     0,     0,   265,   266,   267,   268,
     269,     0,   270,     0,   271,   272,   273,   274,   275,   772,
     773,   107,   107,     0,     0,     0,     0,     0,   108,   108,
       0,     0,     0,   276,     0,   277,   278,   279,   280,   281,
     282,  1196,  1197,   283,   284,   285,   286,   287,     0,     0,
     288,   289,   290,   291,   292,   293,   294,     0,   109,   109,
     774,   775,   107,   107,   110,   110,     0,     0,     0,   108,
     108,     0,     0,     0,     0,   111,   111,     0,   112,   112,
       0,     0,  1113,  1114,   107,   107,     0,  1134,     0,   107,
       0,   108,   108,     0,     0,     0,   108,     0,     0,   109,
     109,     0,     0,     0,     0,   110,   110,     0,     0,  1143,
       0,   107,     0,     0,     0,     0,   111,   111,   108,   112,
     112,   109,   109,     0,     0,     0,   109,   110,   110,     0,
       0,     0,   110,     0,   113,   113,     0,     0,   111,   111,
       0,   112,   112,   111,     0,     0,   112,  1151,   109,   107,
       0,  1153,     0,   107,   110,     0,   108,     0,     0,     0,
     108,     0,     0,     0,     0,   111,     0,     0,   112,     0,
       0,     0,     0,     0,     0,   113,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
     109,     0,   110,     0,     0,     0,   110,   113,   113,     0,
       0,     0,   113,   111,     0,     0,   112,   111,     0,     0,
     112,   114,   115,   116,   117,   118,   119,   120,     0,   122,
       0,     0,   125,   126,   113,     0,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,   113
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,   220,   186,    43,   540,   498,   540,   540,     9,   540,
     540,    12,   540,   506,   878,     4,    17,     4,   947,   947,
       4,     6,    25,   891,   892,   144,    25,   891,   892,    32,
     898,   898,   898,   898,   898,   782,   904,   904,    39,   891,
     892,     3,     4,    42,     3,     4,   898,   540,     3,     4,
      25,   878,   904,   982,   982,     4,     3,     4,     3,     4,
       4,   712,    17,     4,     3,     4,    69,     4,    17,    72,
       4,   898,    13,    72,    25,   898,    15,     4,     6,   947,
     947,   947,     4,   947,    48,     7,   383,   384,   385,   386,
     387,   105,     8,     9,    10,   947,    25,    72,   101,   878,
     891,   892,   101,    58,   401,    50,    51,   898,   122,   878,
      55,     4,   115,   892,   982,   982,   982,   982,   982,     0,
     121,    72,   891,   892,     4,     4,   891,   892,   112,   898,
     982,    47,   879,   898,    12,    25,     3,    17,   139,   140,
      67,    68,     7,    72,   145,   185,   186,    14,   149,     3,
     101,    96,   803,     6,   101,   982,   120,   121,   159,   982,
     107,   162,   111,   107,   153,    99,   141,   116,   107,   154,
     107,   155,     7,   107,    67,   176,   177,   144,   179,   180,
       7,   170,   183,   184,   105,   169,   187,   146,    67,   190,
     191,   192,   193,   194,   195,   196,   943,   198,    88,     4,
     979,     6,   149,   500,   145,   502,   209,   196,   153,   208,
     979,     3,     4,     7,   215,   162,   203,     6,   205,     8,
       9,    10,   122,   224,   521,   522,   523,   524,   525,   526,
     185,  1160,  1160,   178,    26,    27,   185,     6,   535,   536,
     537,   634,   204,   636,   206,     6,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,  1160,  1160,  1160,  1160,  1160,     4,     7,  1046,
       6,     8,     9,    10,    11,     8,     9,    10,  1160,     3,
       4,     3,     4,     6,     4,     3,     4,     3,     3,     4,
       6,    13,   506,     7,    16,   188,   189,    13,   494,     7,
     496,   200,   201,   202,     4,     7,    25,    59,     7,   505,
       7,   507,   878,   509,   510,   878,   643,   878,   878,   515,
     878,     8,     9,    10,    44,     7,   540,    43,     7,     7,
       3,     4,   898,    49,   898,   898,     7,   898,   898,    61,
     898,    63,    64,     7,    60,   541,   377,    63,     4,     7,
      70,     6,     8,     9,    10,   878,    78,     7,     4,    81,
      60,    83,     8,     9,    10,    85,     7,     7,   617,   892,
       7,     8,     9,    10,     7,    95,     3,     4,     7,     7,
       6,   412,   101,     7,     7,    85,     8,     9,    10,    11,
      17,     7,     6,    66,     6,    95,     6,     6,   120,   121,
     596,     7,    29,   119,     6,     6,   126,     6,   439,   109,
     132,     7,   207,   113,    41,     6,   982,    44,   982,   982,
     142,   982,   982,   143,   982,     7,   126,     6,     6,   102,
     149,     7,   151,   123,   107,   108,   506,   633,     6,     6,
       4,   114,     6,   143,    71,    72,     3,     4,   518,    13,
       6,     6,    79,    80,   124,   704,   979,    84,     7,   179,
       7,   183,   493,   182,   186,     7,   497,   140,    95,     7,
     540,     7,     6,   148,   101,   197,   149,   726,     7,    43,
     107,     7,   678,   199,   111,    49,     7,    44,    45,   116,
       7,   118,     7,     6,     6,     6,    60,     6,   125,    63,
     198,   697,   698,   150,     6,     6,     6,     6,   181,   705,
       7,   542,   543,    70,   545,    72,   143,     6,   103,   100,
     147,     7,   553,    80,    13,   152,     7,     6,    85,     6,
       6,   727,    25,     7,   730,   731,     7,    30,    95,     6,
       6,     6,     6,     6,   101,     6,     6,   104,   744,     6,
     107,   800,     3,     4,    43,   119,     6,   184,     6,     6,
      49,   118,     6,     6,     3,     4,     6,   180,   125,   126,
       6,    60,     6,    66,    63,     6,     6,     6,    17,     6,
       6,   208,     6,    34,   780,     6,   143,   618,   915,   146,
       6,     6,     6,    44,     6,   152,     6,     6,   794,   795,
     796,     6,     6,     6,     6,   801,    45,     6,     6,     6,
     859,    62,     3,     4,     6,   108,   812,   944,   945,    70,
     816,   114,   179,   819,   820,     6,    17,   184,     6,     6,
     119,     3,     4,    72,    85,    86,    87,     7,     7,     7,
       6,    80,     6,     6,    95,   894,     6,   140,     6,   680,
       6,     6,     6,     6,    45,     6,   149,   194,     4,   855,
       6,   191,     7,   694,   878,     6,   117,    13,   107,    41,
     866,   202,    44,    45,   870,   126,     6,     6,    43,   118,
      52,    72,     6,     6,   898,     7,   125,   718,   181,    80,
       7,     7,   143,   724,     7,   146,    57,    43,     7,    71,
      72,     6,    98,    49,   900,  1032,    31,     6,    80,   110,
      82,     6,     6,    85,    60,     6,   107,    63,     6,     6,
     111,     6,     6,    95,     6,   116,     6,   118,   179,   101,
       6,   980,   104,   195,   125,   107,     4,   150,    53,     6,
     199,     6,    54,     7,   116,   184,   118,     3,     4,    96,
       4,     6,     6,   125,    56,   951,   147,   953,    28,    13,
       7,     7,   134,    25,     6,     4,    66,   140,   982,  1096,
     108,   143,   114,   119,   146,   149,   151,     6,     6,     6,
     152,   181,   101,     6,     6,    41,     6,   182,    44,    43,
     201,     6,   200,   184,  1121,    49,  1123,     4,    30,     7,
       3,     4,    46,    48,    97,     6,    60,   179,   878,    63,
     107,   842,   184,    72,    17,    71,     7,   199,     4,     7,
    1016,   852,    28,  1072,    33,  1021,    82,   858,   898,    85,
     187,     7,     6,   119,    43,    32,     6,   120,    41,    95,
      49,    44,   192,    42,    53,    54,     6,    56,    57,   193,
      59,   882,   141,   884,    49,    96,     6,     6,     6,     4,
     116,     7,   190,     6,    33,   119,  1062,     7,    71,   180,
    1119,     7,     6,    46,   188,    42,   907,   908,   134,   910,
     911,    84,   189,     6,   115,   121,    69,   143,   208,    98,
      32,   100,    95,     6,   103,     6,    88,   898,   848,   209,
     681,   110,   892,   869,  1111,  1101,    24,   186,   111,  1105,
     119,   942,   982,   116,   123,   124,   156,   982,     4,   156,
       6,   952,   156,   179,   892,   898,   156,    13,   898,   878,
     156,   156,   156,   979,   155,     4,   632,    -1,    -1,   148,
     143,    -1,    -1,    -1,    -1,    -1,  1160,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    43,    -1,  1155,
      -1,    -1,  1158,    49,    -1,    -1,    -1,    -1,    -1,  1165,
    1166,  1167,    -1,    -1,    60,    44,    -1,    63,   187,    -1,
      -1,   190,   191,   192,   193,   194,   195,    -1,    -1,   198,
      -1,    -1,  1188,  1189,    -1,  1191,    65,    -1,   207,    -1,
      -1,    70,     4,     4,     6,    -1,     4,    -1,     6,    -1,
      -1,    13,    -1,    -1,    -1,    13,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    35,    36,    37,    38,    39,    40,
      -1,    43,  1112,    -1,    -1,    43,    -1,    49,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    63,    60,    -1,    -1,    63,  1136,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,   163,    -1,  1127,  1128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,  1150,
      -1,   119,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,   133,    -1,   135,   136,   137,   138,   139,     4,
       4,     6,     6,    -1,    -1,    -1,    -1,    -1,    13,    13,
      -1,    -1,    -1,   154,    -1,   156,   157,   158,   159,   160,
     161,  1192,  1193,   164,   165,   166,   167,   168,    -1,    -1,
     171,   172,   173,   174,   175,   176,   177,    -1,    43,    43,
       4,     4,     6,     6,    49,    49,    -1,    -1,    -1,    13,
      13,    -1,    -1,    -1,    -1,    60,    60,    -1,    63,    63,
      -1,    -1,     4,     4,     6,     6,    -1,     4,    -1,     6,
      -1,    13,    13,    -1,    -1,    -1,    13,    -1,    -1,    43,
      43,    -1,    -1,    -1,    -1,    49,    49,    -1,    -1,     4,
      -1,     6,    -1,    -1,    -1,    -1,    60,    60,    13,    63,
      63,    43,    43,    -1,    -1,    -1,    43,    49,    49,    -1,
      -1,    -1,    49,    -1,   119,   119,    -1,    -1,    60,    60,
      -1,    63,    63,    60,    -1,    -1,    63,     4,    43,     6,
      -1,     4,    -1,     6,    49,    -1,    13,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      43,    -1,    49,    -1,    -1,    -1,    49,   119,   119,    -1,
      -1,    -1,   119,    60,    -1,    -1,    63,    60,    -1,    -1,
      63,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,    -1,    92,    93,   119,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,   119
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   224,   225,   366,     7,     8,     9,    10,   211,
       0,     3,    14,   312,   365,   211,   144,   211,     6,   211,
       7,     3,   280,   303,   313,   314,   105,   122,     4,   314,
       7,     6,   304,   144,   281,     7,   305,     4,    13,   145,
     282,   460,   501,   306,   105,     7,     6,   211,   459,     3,
       4,    15,   107,   234,   240,   247,   250,   253,   256,   259,
     262,   270,   273,   277,   284,   289,   297,   300,   307,   315,
     326,   331,   334,   337,   340,   343,   346,   349,   359,   364,
     434,    33,    43,    49,    53,    54,    56,    57,    59,    98,
     100,   103,   110,   119,   123,   124,   148,   187,   190,   191,
     192,   193,   194,   195,   198,   207,   122,     6,    13,    43,
      49,    60,    63,   119,   221,   221,   221,   221,   221,   221,
     221,   263,   221,     6,     6,   221,   221,     7,     7,   221,
     221,   221,   221,   221,   221,   221,   221,     6,   360,     7,
       7,     7,     7,     7,     7,     7,     4,   211,   264,     7,
       7,     7,     7,     7,   298,   301,   316,     7,     7,     7,
       7,     7,     7,     7,   350,     3,     4,   204,   206,   353,
     355,   358,   361,   498,   500,   211,   211,     6,     6,     6,
       6,   211,    59,     6,   211,   274,   278,     6,     6,     4,
      18,    19,    20,    21,    22,    23,    24,    44,    65,    70,
     163,   299,   369,   370,   371,   372,   373,   374,   375,   388,
     401,   404,   474,     3,     4,    16,    61,    63,    64,    78,
      81,    83,   120,   121,   132,   142,   183,   186,   197,   245,
     292,   295,   302,   367,   397,   399,   400,   412,   415,   417,
     449,   457,   491,   494,   496,   501,     4,    35,    36,    37,
      38,    39,    40,    73,    74,    75,    76,    77,    89,    90,
      91,    92,    93,    94,   106,   127,   128,   129,   130,   131,
     133,   135,   136,   137,   138,   139,   154,   156,   157,   158,
     159,   160,   161,   164,   165,   166,   167,   168,   171,   172,
     173,   174,   175,   176,   177,   317,   369,   370,   371,   372,
     373,   374,   375,   381,   382,   383,   384,   385,   386,   407,
     408,   409,   410,   411,   422,   423,   424,   425,   426,   427,
     433,   444,   445,   446,   447,   448,   450,   452,   453,   454,
     455,   456,   465,   467,   468,   469,   470,   471,   472,   475,
     476,   477,   478,   479,   482,   483,   484,   485,   486,   487,
     488,     7,     6,   211,     6,     6,   211,     7,     3,     4,
     146,   319,   351,   461,   200,   201,   202,   207,     6,     7,
       6,   211,   211,     7,   211,   211,   219,   211,   211,     3,
       4,    66,   102,   108,   114,   140,   149,   181,   226,   229,
     265,   275,   283,   287,   308,   318,   324,   431,   434,     3,
       4,   101,   162,   226,   276,   279,   318,   320,   325,   434,
     473,   211,     6,   123,   211,   211,   211,   211,   211,   211,
     211,     6,   211,     6,     6,    48,   120,   121,   124,   211,
       7,     7,     7,     7,     8,     9,    10,   212,     7,     6,
       6,   211,     7,     7,     7,     7,   148,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,     7,     6,   335,     6,     6,   344,     6,
     150,   198,     6,     6,   223,     6,   241,     6,     7,   217,
     218,     8,     9,    10,    11,   213,   260,   211,   271,    25,
      30,    66,   108,   114,   140,   149,   181,   100,   222,     7,
     222,   222,   222,   222,   222,   101,   151,   182,   103,   222,
     285,   211,     7,     6,     6,   211,     7,     7,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,   211,
     213,     4,    17,   336,   368,   213,   211,     3,     4,    58,
     185,   321,   345,   368,   395,   493,   347,   222,   222,     7,
       4,     6,   213,     3,     4,    45,    72,    80,   118,   125,
     184,   226,   242,   368,   389,   406,   414,   434,   441,   442,
     492,   213,   251,   213,   254,   213,   257,   213,     4,    67,
     261,   402,     4,    99,   272,   430,   434,   227,     7,   222,
     222,   222,   222,   222,   222,   221,   222,   222,   222,     3,
       4,   111,   116,   147,   226,   286,   309,   368,   389,   406,
     414,   434,   436,   439,   441,   442,   462,   492,   213,   211,
     211,     7,   211,     6,   154,   294,     6,     6,     6,     6,
       6,   211,     6,     6,     6,   191,     6,     6,   213,   180,
     194,     7,     4,   153,   170,   196,   348,   464,   481,   495,
       4,     3,   199,   352,   354,   356,   202,     6,     6,    72,
      43,     6,     6,   212,   211,     7,     7,     6,     3,     4,
      50,    51,    55,    96,   178,   252,   268,   391,   392,   394,
     464,   489,   213,     4,    68,   255,   402,   403,     7,     4,
     258,   402,     7,    57,     7,    98,   222,     3,     4,    26,
      27,   228,   376,   377,    31,   230,   379,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   141,   110,     6,   215,
     213,   246,   211,   294,   214,     6,     6,     6,     6,     6,
       6,     6,     6,     6,   211,   213,   213,     6,   195,     6,
     212,   213,   150,   199,   215,     4,     4,   203,   205,   357,
     497,   499,   211,     6,   211,   212,   213,    96,    53,   213,
     213,     6,     7,     6,    54,   213,    56,    28,    25,     7,
       7,     6,     4,    66,   108,   114,   140,   149,   181,   101,
     151,   182,     6,   211,   213,     3,     4,   243,   214,     6,
     212,   293,     6,     6,   327,   213,   213,   213,     6,   212,
     213,   215,   200,   201,     6,     6,   213,     4,   213,     7,
     213,   213,    97,   269,   429,   220,    30,   211,   290,    46,
      48,   293,     6,   434,   211,     3,     4,   328,   329,   330,
     213,   338,   341,   211,   212,     4,   213,    72,   248,   269,
     213,     7,     4,     7,   310,     3,     4,    29,    41,    71,
      79,    84,    95,   143,   152,   208,   226,   237,   276,   291,
     362,   368,   378,   387,   388,   405,   406,   413,   414,   418,
     428,   434,   436,   439,   441,   442,   458,   462,   463,   492,
     214,     4,   211,   211,   188,   189,   187,   332,     3,     4,
      82,    85,   134,   179,   231,   339,   387,   388,   405,   416,
     419,   428,   439,   451,   458,   490,     3,     4,   237,   342,
     368,   387,   388,   405,   418,   428,   436,   439,   458,   322,
     212,   199,   235,     3,     4,    52,   104,   226,   231,   249,
     266,   276,   288,   363,   387,   388,   389,   393,   405,   406,
     414,   416,   419,   428,   432,   434,   439,   441,   442,   451,
     458,   461,   463,   490,   492,     4,   213,    28,     4,    60,
     109,   113,   126,   311,   396,   419,   428,   435,   438,   443,
     458,    42,   208,   119,   211,   211,   211,   211,     7,     7,
       6,   222,    47,   244,   390,   120,   211,   214,   222,   222,
       4,   333,   388,   404,   419,   428,   443,   458,   490,    32,
     192,     6,   213,   211,   213,   193,     4,   323,   368,   436,
     439,   493,   212,     3,     4,   226,   236,   276,   388,   389,
     404,   406,   414,   419,   428,   432,   434,   441,   442,   443,
     458,   461,   463,   490,   492,    69,   115,   209,    49,     6,
      96,   213,   141,     6,     6,   213,     6,   238,   222,     7,
       4,   214,   296,     4,     4,   190,     6,   213,   180,   212,
      33,     7,   222,     7,   213,   213,     4,   112,   155,   169,
     239,   437,   466,   480,     4,    46,   296,   434,   188,   189,
       6,   212,   222,     4,   222,    42,   211,   211,   208,     4,
       6,     4,   115,     4,   121,   211,    69,   209,   213,   213,
     232,     3,     4,    34,    62,    86,    87,   117,   226,   233,
     267,   380,   388,   398,   404,   419,   420,   421,   428,   440,
     443,   458,   461,   490,    88,    32,     6,     6,   213,   213,
     213,   216,   213,   213,     4,   213,   211,   211,    88
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   210,   211,   211,   211,   212,   212,   212,   213,   213,
     213,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   221,   221,
     221,   221,   221,   222,   222,   223,   223,   224,   225,   225,
     225,   226,   227,   227,   227,   227,   228,   229,   230,   230,
     231,   232,   232,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   235,
     235,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     237,   238,   238,   239,   239,   239,   240,   241,   241,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   244,
     244,   245,   246,   246,   247,   248,   248,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   250,   251,   251,   252,   252,   252,
     252,   252,   252,   253,   254,   254,   255,   255,   256,   257,
     257,   258,   259,   260,   260,   261,   262,   263,   263,   264,
     265,   265,   266,   267,   268,   268,   269,   269,   270,   271,
     271,   272,   272,   273,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   277,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   280,   281,
     281,   282,   282,   283,   283,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   287,   287,   288,   289,   290,   290,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   295,   296,   296,
     297,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   303,   304,   305,   306,   306,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   308,   308,   309,   310,   310,
     311,   311,   311,   311,   311,   311,   311,   312,   313,   313,
     314,   314,   315,   316,   316,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   320,   321,   322,   322,   323,   323,   323,
     323,   324,   324,   325,   326,   327,   327,   328,   328,   329,
     330,   331,   332,   332,   333,   333,   333,   333,   333,   333,
     333,   334,   335,   335,   336,   337,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     341,   341,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   350,   350,   351,   351,
     352,   352,   353,   354,   354,   355,   356,   356,   357,   357,
     358,   359,   360,   360,   361,   361,   361,   361,   361,   362,
     362,   363,   364,   365,   366,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     2,     0,     2,     0,     3,
       0,     3,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     3,     2,     0,     1,
       2,     5,     0,     2,     2,     2,     5,     6,     0,     1,
      11,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    15,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     2,     1,     1,     1,     9,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     0,
       1,     7,     0,     2,    14,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    10,     0,     2,     1,     1,     1,
       1,     1,     1,    10,     0,     2,     1,     1,    10,     0,
       2,     1,     9,     0,     2,     1,     5,     0,     2,     4,
       5,     2,     6,     5,     6,     3,     0,     1,     9,     0,
       2,     1,     1,     7,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     7,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     6,     0,
       2,     1,     1,     5,     2,     9,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     2,     5,    13,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       9,     6,     0,     2,     1,     1,    13,    10,     0,     2,
       6,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     1,     1,     0,     2,     1,     1,
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
  "float_string_list", "float_range_list", "string_list",
  "ident_or_keyword", "ident_list", "key_value_list", "a2l_file",
  "file_version", "annotation", "annotation_attributes", "annotation_text",
  "ar_component", "ar_component_attribute", "axis_descr",
  "axis_descr_attributes", "axis_descr_attribute", "axis_pts",
  "axis_pts_attributes", "axis_pts_attribute", "bit_operation",
  "bit_operation_attributes", "bit_operation_attribute", "blob",
  "blob_attributes", "blob_attribute", "calibration_handle",
  "calibration_handle_attribute", "calibration_method",
  "calibration_method_attributes", "characteristic",
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
  "mod_par_attribute", "module", "module_name", "module_comment",
  "module_attributes", "module_attribute", "out_measurement", "overwrite",
  "overwrite_attributes", "overwrite_attribute", "project",
  "project_attributes", "project_attribute", "record_layout",
  "record_layout_attributes", "record_layout_attribute",
  "ref_characteristic", "ref_group", "ref_measurement",
  "structure_component", "structure_component_attributes",
  "structure_component_attribute", "sub_function", "sub_group",
  "transformer", "transformer_attributes", "transformer_attribute",
  "transformer_in_objects", "transformer_out_objects", "typedef_axis",
  "typedef_axis_attributes", "typedef_axis_attribute", "typedef_blob",
  "typedef_blob_attributes", "typedef_blob_attribute",
  "typedef_characteristic", "typedef_characteristic_attributes",
  "typedef_characteristic_attribute", "typedef_measurement",
  "typedef_measurement_attributes", "typedef_measurement_attribute",
  "typedef_structure", "typedef_structure_attributes",
  "typedef_structure_attribute", "unit", "unit_attributes",
  "unit_attribute", "user_rights", "user_rights_attributes",
  "user_rights_attribute", "var_address", "var_characteristic",
  "var_characteristic_attribute", "var_criterion",
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
       0,   436,   436,   437,   438,   440,   441,   442,   444,   445,
     446,   447,   449,   450,   452,   453,   455,   456,   458,   459,
     464,   465,   470,   471,   476,   477,   482,   483,   484,   485,
     486,   487,   488,   491,   492,   497,   498,   503,   505,   506,
     507,   509,   510,   511,   512,   513,   515,   517,   522,   523,
     525,   536,   537,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   555,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     591,   596,   597,   598,   599,   600,   602,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   621,   625,
     626,   628,   634,   635,   640,   653,   654,   655,   656,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   685,   694,   695,   696,   697,   698,
     699,   704,   705,   707,   716,   717,   719,   720,   722,   731,
     732,   733,   735,   743,   744,   745,   747,   749,   750,   752,
     762,   765,   769,   772,   774,   777,   780,   781,   783,   790,
     791,   792,   793,   795,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   813,   814,   816,   822,
     823,   824,   825,   826,   827,   828,   829,   830,   832,   837,
     838,   840,   843,   848,   851,   855,   862,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,   873,   874,   876,
     877,   879,   882,   886,   888,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     926,   934,   942,   943,   948,   949,   951,   963,   974,   975,
     979,   984,   985,   986,   987,   988,   989,   990,   991,   992,
     993,   994,   995,   996,   998,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1025,  1031,  1036,  1041,  1042,  1043,  1044,
    1047,  1050,  1053,  1056,  1059,  1062,  1065,  1066,  1069,  1072,
    1075,  1078,  1081,  1084,  1085,  1086,  1089,  1092,  1095,  1098,
    1101,  1104,  1107,  1110,  1113,  1115,  1118,  1122,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1137,  1138,  1140,  1146,  1147,
    1149,  1150,  1155,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1217,  1220,  1223,  1224,  1226,  1233,  1234,  1235,  1236,  1237,
    1238,  1240,  1243,  1247,  1249,  1260,  1261,  1262,  1263,  1265,
    1266,  1268,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1291,  1297,  1298,  1299,  1301,  1313,  1314,  1315,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1330,
    1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1355,  1362,  1363,  1364,  1365,  1366,  1369,  1371,
    1378,  1379,  1380,  1381,  1382,  1387,  1391,  1392,  1393,  1394,
    1396,  1399,  1403,  1409,  1410,  1412,  1419,  1420,  1421,  1422,
    1424,  1426,  1427,  1428,  1429,  1433,  1437,  1441,  1445,  1450,
    1453,  1456,  1460,  1461,  1466,  1469,  1473,  1474,  1475,  1476,
    1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,
    1487,  1493,  1499,  1505,  1511,  1517,  1524,  1525,  1526,  1527,
    1528,  1538,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,
    1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1563,  1567,
    1571,  1575,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1600,  1601,
    1602,  1603,  1604,  1605,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1623,  1627,  1631,  1635,  1639,
    1640,  1644,  1645,  1649,  1653,  1657,  1661,  1665,  1666,  1667,
    1668,  1669,  1671,  1672,  1673,  1674,  1675,  1679,  1680,  1684,
    1688,  1692,  1696,  1700,  1704,  1705,  1706,  1710,  1714,  1718,
    1722,  1726,  1727,  1736,  1740,  1744,  1748,  1752,  1756,  1757,
    1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,
    1768,  1769,  1770
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
#line 8187 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1772 "D:/projects/a2llib/src/a2lparser.y"


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
