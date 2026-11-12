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
#line 29 "D:/projects/a2llib/src/a2lparser.y"
    #include "a2l/a2lstructs.h"
    #include <sstream>
    #include "a2lscanner.h"
    #include "a2l/a2lfile.h"
    #include "a2l/a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.a2llex

#line 59 "D:/projects/a2llib/src/a2lparser.cpp"


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
#line 133 "D:/projects/a2llib/src/a2lparser.cpp"

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
#line 2849 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 437 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_uint: INT
#line 438 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < int64_t > () < 0 ? 0 : static_cast<uint64_t>(yystack_[0].value.as < int64_t > ()); }
#line 2861 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: INT
#line 440 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: UINT
#line 441 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2873 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_int: HEX
#line 442 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: FLOAT
#line 444 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2885 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: INT
#line 445 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: UINT
#line 446 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // any_float: HEX
#line 447 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: %empty
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2909 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // int_list: int_list any_int
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                     {yystack_[1].value.as < std::deque<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); yylhs.value.as < std::deque<int64_t> > () = std::move(yystack_[1].value.as < std::deque<int64_t> > ());  }
#line 2915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: %empty
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2921 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // uint_list: uint_list any_uint
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                       {yystack_[1].value.as < std::deque<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[1].value.as < std::deque<uint64_t> > ());  }
#line 2927 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: %empty
#line 455 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2933 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_list: float_list any_float
#line 456 "D:/projects/a2llib/src/a2lparser.y"
                               {yystack_[1].value.as < std::deque<double> > ().emplace_back(yystack_[0].value.as < double > ()); yylhs.value.as < std::deque<double> > () = std::move(yystack_[1].value.as < std::deque<double> > ());  }
#line 2939 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: %empty
#line 458 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_pair_list: float_pair_list any_float any_float
#line 459 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	  yylhs.value.as < std::map<double, double> > () = std::move(yystack_[2].value.as < std::map<double, double> > ());
	  yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ());
	}
#line 2954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: %empty
#line 464 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_string_list: float_string_list any_float STRING
#line 465 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	  yylhs.value.as < std::map<double, std::string> > () = std::move(yystack_[2].value.as < std::map<double, std::string> > ());
	  yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ());
	}
#line 2969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: %empty
#line 470 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2975 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // float_range_list: float_range_list any_float any_float STRING
#line 471 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = std::move(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ());
        }
#line 2984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: %empty
#line 476 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2990 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // string_list: string_list STRING
#line 477 "D:/projects/a2llib/src/a2lparser.y"
                             {
	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
	}
#line 2999 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_or_keyword: IDENT
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // ident_or_keyword: A2L_VERSION
#line 483 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = "VERSION";}
#line 3011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // ident_or_keyword: BLOB
#line 484 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = "BLOB";}
#line 3017 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 29: // ident_or_keyword: CHARACTERISTIC
#line 485 "D:/projects/a2llib/src/a2lparser.y"
                         {yylhs.value.as < std::string > () = "CHARACTERISTIC";}
#line 3023 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 30: // ident_or_keyword: CONVERSION
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::string > () = "CONVERSION";}
#line 3029 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 31: // ident_or_keyword: CUSTOMER
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < std::string > () = "CUSTOMER";}
#line 3035 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 32: // ident_or_keyword: MEASUREMENT
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = "MEASUREMENT";}
#line 3041 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // ident_list: %empty
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 3047 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // ident_list: ident_list ident_or_keyword
#line 492 "D:/projects/a2llib/src/a2lparser.y"
                                      {
       	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
       	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
       	}
#line 3056 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // key_value_list: %empty
#line 497 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 3062 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // key_value_list: key_value_list IDENT IDENT
#line 498 "D:/projects/a2llib/src/a2lparser.y"
                                     {
       	  yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ());
       	  yylhs.value.as < std::map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ());
       }
#line 3071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 509 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = std::move(yystack_[2].value.as < A2lAnnotation > ());}
#line 3077 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // annotation_attributes: %empty
#line 510 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 3083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 43: // annotation_attributes: annotation_attributes annotation_label
#line 511 "D:/projects/a2llib/src/a2lparser.y"
                                              { yystack_[1].value.as < A2lAnnotation > ().Label = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3089 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 44: // annotation_attributes: annotation_attributes annotation_origin
#line 512 "D:/projects/a2llib/src/a2lparser.y"
                                               { yystack_[1].value.as < A2lAnnotation > ().Origin = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3095 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // annotation_attributes: annotation_attributes annotation_text
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                                             { yystack_[1].value.as < A2lAnnotation > ().Text = std::move(yystack_[0].value.as < std::deque<std::string> > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ());}
#line 3101 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3107 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 517 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3117 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // ar_component_attribute: %empty
#line 522 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3123 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // ar_component_attribute: ar_prototype_of
#line 523 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3129 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3143 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: annotation
#line 539 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3149 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: axis_pts_ref
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3155 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: byte_order
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3161 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: curve_axis_ref
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3167 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: deposit
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3173 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: extended_limits
#line 544 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3179 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: fix_axis_par
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3185 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_descr_attribute: fix_axis_par_dist
#line 546 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3191 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 61: // axis_descr_attribute: fix_axis_par_list
#line 547 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::deque<double> > ()); }
#line 3197 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 62: // axis_descr_attribute: format
#line 548 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3203 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_descr_attribute: max_grad
#line 549 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3209 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_descr_attribute: monotony
#line 550 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3215 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_descr_attribute: phys_unit
#line 551 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_descr_attribute: read_only
#line 552 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_descr_attribute: step_size
#line 553 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3233 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3251 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: annotation
#line 571 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3257 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: byte_order
#line 572 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3263 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: calibration_access
#line 573 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: deposit
#line 574 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: display_identifier
#line 575 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: ecu_address_extension
#line 576 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: extended_limits
#line 577 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: format
#line 578 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: function_list
#line 579 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: guard_rails
#line 580 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: if_data
#line 581 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 82: // axis_pts_attribute: max_refresh
#line 582 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 83: // axis_pts_attribute: model_link
#line 583 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 84: // axis_pts_attribute: monotony
#line 584 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // axis_pts_attribute: phys_unit
#line 585 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3341 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // axis_pts_attribute: read_only
#line 586 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3347 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // axis_pts_attribute: ref_memory_segment
#line 587 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3353 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // axis_pts_attribute: step_size
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3359 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 89: // axis_pts_attribute: symbol_link
#line 589 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3365 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 90: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 591 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3375 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // bit_operation_attribute: left_shift
#line 598 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3381 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // bit_operation_attribute: right_shift
#line 599 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3387 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // bit_operation_attribute: sign_extend
#line 600 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3393 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: address_type
#line 611 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3411 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // blob_attribute: annotation
#line 612 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3417 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // blob_attribute: calibration_access
#line 613 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3423 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // blob_attribute: display_identifier
#line 614 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3429 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // blob_attribute: ecu_address_extension
#line 615 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3435 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // blob_attribute: if_data
#line 616 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3441 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // blob_attribute: max_refresh
#line 617 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3447 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // blob_attribute: model_link
#line 618 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3453 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 107: // blob_attribute: symbol_link
#line 619 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3459 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 108: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 621 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lCalibrationHandle > ().Comment = std::move(yystack_[2].value.as < std::string > ());
}
#line 3468 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // calibration_handle_attribute: %empty
#line 625 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // calibration_handle_attribute: calibration_handle_text
#line 626 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3480 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = std::move(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = std::move(yystack_[2].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3490 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // calibration_method_attributes: %empty
#line 634 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3496 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 635 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
		yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
		yylhs.value.as < std::deque<A2lCalibrationHandle> > () = std::move(yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3505 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3522 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: annotation
#line 655 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3528 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: axis_descr
#line 656 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: bit_mask
#line 659 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3542 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: byte_order
#line 660 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3548 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: calibration_access
#line 661 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: comparison_quantity
#line 662 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: dependent_characteristic
#line 663 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3566 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: discrete
#line 664 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3572 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: display_identifier
#line 665 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3578 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: ecu_address_extension
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3584 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: encoding
#line 667 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3590 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: extended_limits
#line 668 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3596 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: format
#line 669 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: function_list
#line 670 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: guard_rails
#line 671 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3614 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: if_data
#line 672 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3620 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: map_list
#line 673 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: matrix_dim
#line 674 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 3632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: max_refresh
#line 675 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3638 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 136: // characteristic_attribute: model_link
#line 676 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3644 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 137: // characteristic_attribute: number
#line 677 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3650 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 138: // characteristic_attribute: phys_unit
#line 678 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3656 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // characteristic_attribute: read_only
#line 679 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3662 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // characteristic_attribute: ref_memory_segment
#line 680 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3668 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // characteristic_attribute: step_size
#line 681 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3674 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // characteristic_attribute: symbol_link
#line 682 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3680 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // characteristic_attribute: virtual_characteristic
#line 683 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3686 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3699 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 147: // compu_method_attribute: coeffs
#line 696 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::deque<double> > ()); }
#line 3705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_method_attribute: coeffs_linear
#line 697 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::deque<double> > ()); }
#line 3711 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_method_attribute: compu_tab_ref
#line 698 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3717 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 150: // compu_method_attribute: formula
#line 699 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.FormulaInv(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3727 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 151: // compu_method_attribute: ref_unit
#line 704 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3733 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 152: // compu_method_attribute: status_string_ref
#line 705 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3739 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3752 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 156: // compu_tab_attribute: default_value
#line 719 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3758 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // compu_tab_attribute: default_value_numeric
#line 720 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3764 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3777 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // compu_vtab_attribute: default_value
#line 733 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3783 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3795 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 165: // compu_vtab_range_attribute: default_value
#line 745 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtabRange().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3801 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 170: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 762 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 3823 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // def_characteristic: DEF_CHARACTERISTIC ident_list
#line 765 "D:/projects/a2llib/src/a2lparser.y"
                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 3831 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 172: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 770 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 3837 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 772 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::deque<double> > () = std::move(yystack_[2].value.as < std::deque<double> > ()); }
#line 3843 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 774 "D:/projects/a2llib/src/a2lparser.y"
                                                                    {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()};
    }
#line 3851 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // formula: FORMULA STRING formula_attribute
#line 777 "D:/projects/a2llib/src/a2lparser.y"
                                       {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};
    }
#line 3859 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // formula_attribute: %empty
#line 780 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3865 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 177: // formula_attribute: formula_inv
#line 781 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 3871 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 3883 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // frame_attribute: frame_measurement
#line 792 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3889 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // frame_attribute: if_data
#line 793 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3895 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 795 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3905 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // function_attribute: annotation
#line 802 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3911 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // function_attribute: def_characteristic
#line 804 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3917 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // function_attribute: function_version
#line 805 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // function_attribute: if_data
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3929 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // function_attribute: in_measurement
#line 807 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3935 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 192: // function_attribute: loc_measurement
#line 808 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3941 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // function_attribute: out_measurement
#line 809 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3947 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 194: // function_attribute: ref_characteristic
#line 810 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3953 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // function_attribute: sub_function
#line 811 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3959 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 813 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3965 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // function_list: FUNCTION_LIST ident_list
#line 814 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3971 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 816 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3981 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 201: // group_attribute: annotation
#line 824 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3987 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 202: // group_attribute: function_list
#line 825 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3993 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // group_attribute: if_data
#line 826 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3999 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // group_attribute: ref_characteristic
#line 827 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // group_attribute: ref_measurement
#line 828 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // group_attribute: root
#line 829 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 4017 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // group_attribute: sub_group
#line 830 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4023 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 832 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4032 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // header_attribute: project_no
#line 840 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 4041 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // header_attribute: version
#line 843 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 4050 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 848 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
    yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
}
#line 4058 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // in_measurement: IN_MEASUREMENT ident_list
#line 851 "D:/projects/a2llib/src/a2lparser.y"
                            {
      yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
}
#line 4066 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // instance_attribute: address_type
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 219: // instance_attribute: annotation
#line 865 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // instance_attribute: calibration_access
#line 866 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 4096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // instance_attribute: display_identifier
#line 867 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // instance_attribute: ecu_address_extension
#line 868 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4108 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // instance_attribute: if_data
#line 869 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4114 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // instance_attribute: layout
#line 870 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4120 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // instance_attribute: matrix_dim
#line 871 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4126 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // instance_attribute: max_refresh
#line 872 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4132 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // instance_attribute: model_link
#line 873 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4138 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 228: // instance_attribute: overwrite
#line 874 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 4145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // instance_attribute: read_write
#line 876 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 4151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // instance_attribute: symbol_link
#line 877 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4157 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 879 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4165 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // loc_measurement: LOC_MEASUREMENT ident_list
#line 882 "D:/projects/a2llib/src/a2lparser.y"
                                 {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4173 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 886 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 4179 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4195 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: address_type
#line 902 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4201 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: annotation
#line 903 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: array_size
#line 904 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: bit_mask
#line 905 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: bit_operation
#line 906 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: byte_order
#line 907 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4231 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // measurement_attribute: discrete
#line 908 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4237 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // measurement_attribute: display_identifier
#line 909 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4243 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // measurement_attribute: ecu_address
#line 910 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4249 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // measurement_attribute: ecu_address_extension
#line 911 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4255 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // measurement_attribute: error_mask
#line 912 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4261 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // measurement_attribute: format
#line 913 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4267 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // measurement_attribute: function_list
#line 914 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4273 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // measurement_attribute: if_data
#line 915 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4279 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // measurement_attribute: layout
#line 916 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4285 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 252: // measurement_attribute: matrix_dim
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4291 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 253: // measurement_attribute: max_refresh
#line 918 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4297 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // measurement_attribute: model_link
#line 919 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4303 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // measurement_attribute: phys_unit
#line 920 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4309 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // measurement_attribute: read_write
#line 921 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4315 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 257: // measurement_attribute: ref_memory_segment
#line 922 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4321 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 258: // measurement_attribute: symbol_link
#line 923 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4327 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // measurement_attribute: virtual
#line 924 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4333 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4345 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4357 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // memory_layout_attributes: %empty
#line 942 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4363 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 263: // memory_layout_attributes: memory_layout_attributes if_data
#line 943 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
        }
#line 4372 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 264: // prg_type: RESERVED
#line 948 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4378 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 265: // prg_type: IDENT
#line 949 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4384 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4400 "D:/projects/a2llib/src/a2lparser.cpp"
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
#line 4416 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // memory_segment_attributes: %empty
#line 974 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4422 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 269: // memory_segment_attributes: memory_segment_attributes if_data
#line 975 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	    yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	    yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 979 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4440 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_common_attribute: alignment_byte
#line 986 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4446 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_common_attribute: alignment_float16_ieee
#line 987 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 275: // mod_common_attribute: alignment_float32_ieee
#line 988 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 276: // mod_common_attribute: alignment_float64_ieee
#line 989 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 277: // mod_common_attribute: alignment_int64
#line 990 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 278: // mod_common_attribute: alignment_long
#line 991 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4476 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 279: // mod_common_attribute: alignment_word
#line 992 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_common_attribute: byte_order
#line 993 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_common_attribute: data_size
#line 994 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_common_attribute: deposit
#line 995 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 998 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = std::move(yystack_[3].value.as < std::string > ());

}
#line 4510 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // mod_par_attribute: addr_epk
#line 1006 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4516 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // mod_par_attribute: calibration_method
#line 1007 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4522 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // mod_par_attribute: cpu_type
#line 1008 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4528 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // mod_par_attribute: customer
#line 1009 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4534 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // mod_par_attribute: customer_no
#line 1010 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4540 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // mod_par_attribute: ecu
#line 1011 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4546 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // mod_par_attribute: ecu_calibration_offset
#line 1012 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4552 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // mod_par_attribute: epk
#line 1013 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4558 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // mod_par_attribute: memory_layout
#line 1014 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4564 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // mod_par_attribute: memory_segment
#line 1015 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4570 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // mod_par_attribute: no_of_interfaces
#line 1016 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4576 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // mod_par_attribute: phone_no
#line 1017 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4582 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // mod_par_attribute: supplier
#line 1018 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4588 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // mod_par_attribute: system_constant
#line 1019 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4594 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 301: // mod_par_attribute: user
#line 1020 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4600 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 302: // mod_par_attribute: version
#line 1021 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4606 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module: A2L_BEGIN MODULE module_name module_comment module_attributes A2L_END MODULE
#line 1023 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	//auto& module = scanner.CurrentModule();
	//module.Name($3);
	//module.Description($4);
}
#line 4616 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_name: IDENT
#line 1029 "D:/projects/a2llib/src/a2lparser.y"
                   {
	auto& module = scanner.CurrentModule();
	module.Name(std::move(yystack_[0].value.as < std::string > ()));
}
#line 4625 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_name: ECU
#line 1032 "D:/projects/a2llib/src/a2lparser.y"
        {
    auto& module = scanner.CurrentModule();
    module.Name("ECU");
}
#line 4634 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 306: // module_comment: STRING
#line 1037 "D:/projects/a2llib/src/a2lparser.y"
                       {
	auto& module = scanner.CurrentModule();
	module.Description(std::move(yystack_[0].value.as < std::string > ()));
 }
#line 4643 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: a2ml
#line 1044 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: axis_pts
#line 1045 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
    	}
#line 4661 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: blob
#line 1052 "D:/projects/a2llib/src/a2lparser.y"
               {
            auto& module = scanner.CurrentModule();
            module.AddBlob(scanner.ReleaseBlob());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 312: // module_attribute: characteristic
#line 1059 "D:/projects/a2llib/src/a2lparser.y"
                         {
            auto& module = scanner.CurrentModule();
            module.AddCharacteristic(scanner.ReleaseCharacteristic());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4685 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // module_attribute: compu_method
#line 1066 "D:/projects/a2llib/src/a2lparser.y"
                       {
            auto& module = scanner.CurrentModule();
            module.AddCompuMethod(scanner.ReleaseCompuMethod());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4697 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // module_attribute: compu_tab
#line 1073 "D:/projects/a2llib/src/a2lparser.y"
                    {
            auto& module = scanner.CurrentModule();
            module.AddCompuTab(scanner.ReleaseCompuTab());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4709 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 315: // module_attribute: compu_vtab
#line 1080 "D:/projects/a2llib/src/a2lparser.y"
                     {
            auto& module = scanner.CurrentModule();
            module.AddCompuVtab(scanner.ReleaseCompuVtab());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4721 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 316: // module_attribute: compu_vtab_range
#line 1087 "D:/projects/a2llib/src/a2lparser.y"
                           {
            auto& module = scanner.CurrentModule();
            module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4733 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // module_attribute: controller_addresses
#line 1094 "D:/projects/a2llib/src/a2lparser.y"
                               {}
#line 4739 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // module_attribute: frame
#line 1095 "D:/projects/a2llib/src/a2lparser.y"
                {
            auto& module = scanner.CurrentModule();
            module.AddFrame(scanner.ReleaseFrame());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4751 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // module_attribute: function
#line 1102 "D:/projects/a2llib/src/a2lparser.y"
                   {
            auto& module = scanner.CurrentModule();
            module.AddFunction(scanner.ReleaseFunction());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4763 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // module_attribute: group
#line 1109 "D:/projects/a2llib/src/a2lparser.y"
                {
            auto& module = scanner.CurrentModule();
            module.AddGroup(scanner.ReleaseGroup());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4775 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // module_attribute: if_data
#line 1116 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4783 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // module_attribute: instance
#line 1119 "D:/projects/a2llib/src/a2lparser.y"
                   {
            auto& module = scanner.CurrentModule();
            module.AddInstance(scanner.ReleaseInstance());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4795 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // module_attribute: measurement
#line 1126 "D:/projects/a2llib/src/a2lparser.y"
                      {
            auto& module = scanner.CurrentModule();
            module.AddMeasurement(scanner.ReleaseMeasurement());
            if (scanner.GetParseModuleInformationOnly()) {
              YYACCEPT;
            }
        }
#line 4807 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 326: // module_attribute: record_layout
#line 1135 "D:/projects/a2llib/src/a2lparser.y"
                        {
       auto& module = scanner.CurrentModule();
       module.AddRecordLayout(scanner.ReleaseRecordLayout());
       if (scanner.GetParseModuleInformationOnly()) {
         YYACCEPT;
       }
	}
#line 4819 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 327: // module_attribute: transformer
#line 1142 "D:/projects/a2llib/src/a2lparser.y"
                      {
       auto& module = scanner.CurrentModule();
       module.AddTransformer(scanner.ReleaseTransformer());
       if (scanner.GetParseModuleInformationOnly()) {
         YYACCEPT;
       }
	}
#line 4831 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // module_attribute: typedef_axis
#line 1149 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& module = scanner.CurrentModule();
       module.AddTypedefAxis(scanner.ReleaseTypedefAxis());
       if (scanner.GetParseModuleInformationOnly()) {
         YYACCEPT;
       }
	}
#line 4843 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 329: // module_attribute: typedef_blob
#line 1156 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& module = scanner.CurrentModule();
       module.AddTypedefBlob(scanner.ReleaseTypedefBlob());
       if (scanner.GetParseModuleInformationOnly()) {
        YYACCEPT;
       }
    }
#line 4855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 330: // module_attribute: typedef_characteristic
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                                 {
       auto& module = scanner.CurrentModule();
       module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic());
       if (scanner.GetParseModuleInformationOnly()) {
        YYACCEPT;
       }
    }
#line 4867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 331: // module_attribute: typedef_measurement
#line 1170 "D:/projects/a2llib/src/a2lparser.y"
                              {
        auto& module = scanner.CurrentModule();
        module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement());
        if (scanner.GetParseModuleInformationOnly()) {
          YYACCEPT;
        }
    }
#line 4879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 332: // module_attribute: typedef_structure
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
                            {
       auto& module = scanner.CurrentModule();
       module.AddTypedefStructure(scanner.ReleaseTypedefStructure());
       if (scanner.GetParseModuleInformationOnly()) {
         YYACCEPT;
       }
    }
#line 4891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 333: // module_attribute: unit
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
               {
       auto& module = scanner.CurrentModule();
       module.AddUnit(scanner.ReleaseUnit());
       if (scanner.GetParseModuleInformationOnly()) {
         YYACCEPT;
       }
    }
#line 4903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 334: // module_attribute: user_rights
#line 1191 "D:/projects/a2llib/src/a2lparser.y"
                      {
      auto& module = scanner.CurrentModule();
      module.AddUserRights(scanner.ReleaseUserRights());
      if (scanner.GetParseModuleInformationOnly()) {
        YYACCEPT;
      }
    }
#line 4915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 336: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 337: // out_measurement: OUT_MEASUREMENT ident_list
#line 1203 "D:/projects/a2llib/src/a2lparser.y"
                                 {
       yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4931 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 338: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1207 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4941 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 341: // overwrite_attribute: conversion
#line 1214 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4947 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 342: // overwrite_attribute: extended_limits
#line 1215 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4953 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 343: // overwrite_attribute: format
#line 1216 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4959 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 344: // overwrite_attribute: input_quantity
#line 1217 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4965 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // overwrite_attribute: limits
#line 1218 "D:/projects/a2llib/src/a2lparser.y"
                 {
	    scanner.CurrentOverwrite().LowerLimit(yystack_[0].value.as < A2lLimits > ().LowerLimit);
	    scanner.CurrentOverwrite().UpperLimit(yystack_[0].value.as < A2lLimits > ().UpperLimit);
	    }
#line 4974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 346: // overwrite_attribute: monotony
#line 1222 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 347: // overwrite_attribute: phys_unit
#line 1223 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 348: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1225 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4996 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // project_attribute: module
#line 1235 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 5005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 353: // record_layout: A2L_BEGIN RECORD_LAYOUT ident_or_keyword record_layout_attributes A2L_END RECORD_LAYOUT
#line 1240 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                       {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 5014 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: alignment_byte
#line 1246 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 5020 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: alignment_float16_ieee
#line 1247 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 5026 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: alignment_float32_ieee
#line 1248 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 5032 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: alignment_float64_ieee
#line 1249 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 5038 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: alignment_int64
#line 1250 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 5044 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: alignment_long
#line 1251 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 5050 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: alignment_word
#line 1252 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 5056 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: axis_pts_x
#line 1253 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 5062 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: axis_pts_y
#line 1254 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 5068 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: axis_pts_z
#line 1255 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 5074 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: axis_pts_4
#line 1256 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 5080 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: axis_pts_5
#line 1257 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 5086 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: axis_rescale_x
#line 1258 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 5092 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: dist_op_x
#line 1259 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5098 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: dist_op_y
#line 1260 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5104 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: dist_op_z
#line 1261 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5110 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: dist_op_4
#line 1262 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5116 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: dist_op_5
#line 1263 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5122 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: fix_no_axis_pts_x
#line 1264 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 5128 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: fix_no_axis_pts_y
#line 1265 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 5134 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: fix_no_axis_pts_z
#line 1266 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 5140 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: fix_no_axis_pts_4
#line 1267 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 5146 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: fix_no_axis_pts_5
#line 1268 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 5152 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: fnc_values
#line 1269 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 5158 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: identification
#line 1270 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 5164 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: no_axis_pts_x
#line 1271 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5170 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: no_axis_pts_y
#line 1272 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5176 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: no_axis_pts_z
#line 1273 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5182 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: no_axis_pts_4
#line 1274 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5188 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: no_axis_pts_5
#line 1275 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5194 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: no_rescale_x
#line 1276 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5200 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // record_layout_attribute: offset_x
#line 1277 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5206 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // record_layout_attribute: offset_y
#line 1278 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5212 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // record_layout_attribute: offset_z
#line 1279 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5218 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // record_layout_attribute: offset_4
#line 1280 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5224 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 391: // record_layout_attribute: offset_5
#line 1281 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5230 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 392: // record_layout_attribute: reserved
#line 1282 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 5236 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // record_layout_attribute: rip_addr_w
#line 1283 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 5242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // record_layout_attribute: rip_addr_x
#line 1284 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // record_layout_attribute: rip_addr_y
#line 1285 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5254 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // record_layout_attribute: rip_addr_z
#line 1286 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5260 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // record_layout_attribute: rip_addr_4
#line 1287 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5266 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // record_layout_attribute: rip_addr_5
#line 1288 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5272 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // record_layout_attribute: src_addr_x
#line 1289 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5278 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 400: // record_layout_attribute: src_addr_y
#line 1290 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5284 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 401: // record_layout_attribute: src_addr_z
#line 1291 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5290 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // record_layout_attribute: src_addr_4
#line 1292 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5296 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // record_layout_attribute: src_addr_5
#line 1293 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5302 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // record_layout_attribute: shift_op_x
#line 1294 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5308 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 405: // record_layout_attribute: shift_op_y
#line 1295 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5314 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 406: // record_layout_attribute: shift_op_z
#line 1296 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5320 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 407: // record_layout_attribute: shift_op_4
#line 1297 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5326 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 408: // record_layout_attribute: shift_op_5
#line 1298 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5332 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 409: // record_layout_attribute: static_address_offsets
#line 1299 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5338 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // record_layout_attribute: static_record_layout
#line 1300 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5344 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1302 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5352 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // ref_characteristic: REF_CHARACTERISTIC ident_list
#line 1305 "D:/projects/a2llib/src/a2lparser.y"
                                    {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5360 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 413: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1308 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5366 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 414: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1309 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5372 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 415: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1312 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = std::move(yystack_[5].value.as < std::string > ());
        structure.Typedef = yystack_[4].value.as < std::string > ();
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5383 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 418: // structure_component_attribute: address_type
#line 1320 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 419: // structure_component_attribute: layout
#line 1321 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // structure_component_attribute: matrix_dim
#line 1322 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 421: // structure_component_attribute: symbol_type_link
#line 1323 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 422: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1325 "D:/projects/a2llib/src/a2lparser.y"
                                                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5415 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 423: // sub_function: SUB_FUNCTION ident_list
#line 1328 "D:/projects/a2llib/src/a2lparser.y"
                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5423 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 424: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1332 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5429 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 425: // transformer: A2L_BEGIN TRANSFORMER ident_or_keyword STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1335 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5444 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 428: // transformer_attribute: transformer_in_objects
#line 1347 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // transformer_attribute: transformer_out_objects
#line 1348 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5456 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1350 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5462 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1351 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5468 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 432: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS ident_or_keyword STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1354 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5485 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 435: // typedef_axis_attribute: byte_order
#line 1368 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5491 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 436: // typedef_axis_attribute: deposit
#line 1369 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5497 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 437: // typedef_axis_attribute: extended_limits
#line 1370 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5503 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_axis_attribute: format
#line 1371 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 439: // typedef_axis_attribute: monotony
#line 1372 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5515 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 440: // typedef_axis_attribute: phys_unit
#line 1373 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5521 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 441: // typedef_axis_attribute: step_size
#line 1374 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5527 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 442: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB ident_or_keyword STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1376 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5538 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_blob_attribute: address_type
#line 1384 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5544 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 446: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC ident_or_keyword STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1387 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 449: // typedef_characteristic_attribute: axis_descr
#line 1400 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5569 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 450: // typedef_characteristic_attribute: bit_mask
#line 1404 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5575 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 451: // typedef_characteristic_attribute: byte_order
#line 1405 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5581 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_characteristic_attribute: discrete
#line 1406 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5587 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 453: // typedef_characteristic_attribute: encoding
#line 1407 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5593 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 454: // typedef_characteristic_attribute: extended_limits
#line 1408 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5599 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 455: // typedef_characteristic_attribute: format
#line 1409 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5605 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 456: // typedef_characteristic_attribute: matrix_dim
#line 1410 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5611 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // typedef_characteristic_attribute: number
#line 1411 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5617 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // typedef_characteristic_attribute: phys_unit
#line 1412 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5623 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // typedef_characteristic_attribute: step_size
#line 1413 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5629 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 460: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT ident_or_keyword STRING IDENT IDENT any_uint any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1416 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5645 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 463: // typedef_measurement_attribute: address_type
#line 1429 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 464: // typedef_measurement_attribute: bit_mask
#line 1430 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // typedef_measurement_attribute: bit_operation
#line 1431 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5663 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 466: // typedef_measurement_attribute: byte_order
#line 1432 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5669 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 467: // typedef_measurement_attribute: discrete
#line 1433 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 468: // typedef_measurement_attribute: error_mask
#line 1434 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5681 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // typedef_measurement_attribute: format
#line 1435 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5687 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 470: // typedef_measurement_attribute: layout
#line 1436 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5693 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 471: // typedef_measurement_attribute: matrix_dim
#line 1437 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5699 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // typedef_measurement_attribute: phys_unit
#line 1438 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 473: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE ident_or_keyword STRING any_uint typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1441 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5716 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 476: // typedef_structure_attribute: address_type
#line 1449 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5722 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 477: // typedef_structure_attribute: consistent_exchange
#line 1450 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5728 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // typedef_structure_attribute: structure_component
#line 1451 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5736 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 479: // typedef_structure_attribute: symbol_type_link
#line 1454 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5742 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 480: // unit: A2L_BEGIN UNIT ident_or_keyword STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1456 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5754 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // unit_attribute: ref_unit
#line 1465 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // unit_attribute: si_exponents
#line 1466 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5766 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // unit_attribute: unit_conversion
#line 1467 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5775 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1472 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_rights = scanner.CurrentUserRights();
       user_rights.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // user_rights_attribute: read_only
#line 1478 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRights().ReadOnly = true; }
#line 5790 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // user_rights_attribute: ref_group
#line 1479 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRights().RefGroupList.emplace_back(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5796 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 491: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1481 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5804 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // var_address: VAR_ADDRESS uint_list
#line 1484 "D:/projects/a2llib/src/a2lparser.y"
                            {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ());
    }
#line 5812 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 493: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1489 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = std::move(yystack_[3].value.as < std::deque<std::string> > ());
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5822 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 494: // var_characteristic_attribute: %empty
#line 1494 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5828 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 495: // var_characteristic_attribute: var_address
#line 1495 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5834 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 496: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1497 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCriterion > ().Description = std::move(yystack_[3].value.as < std::string > ());
}
#line 5845 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // var_criterion_attribute: var_measurement
#line 1506 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = std::move(yystack_[0].value.as < std::string > ()); }
#line 5851 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // var_criterion_attribute: var_selection_characteristic
#line 1507 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = std::move(yystack_[0].value.as < std::string > ()); }
#line 5857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1509 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ()); }
#line 5863 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // variant_coding_attribute: var_characteristic
#line 1514 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5872 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // variant_coding_attribute: var_criterion
#line 1518 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5881 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // variant_coding_attribute: var_forbidden_comb
#line 1522 "D:/projects/a2llib/src/a2lparser.y"
                             {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(std::move(yystack_[0].value.as < std::map<std::string, std::string> > ()));
       }
#line 5890 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // variant_coding_attribute: var_naming
#line 1526 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = std::move(yystack_[0].value.as < std::string > ());
       }
#line 5899 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // variant_coding_attribute: var_separator
#line 1530 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = std::move(yystack_[0].value.as < std::string > ());
      }
#line 5908 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1535 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5916 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // virtual: VIRTUAL ident_list
#line 1538 "D:/projects/a2llib/src/a2lparser.y"
                         {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1542 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 5930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // a2ml: A2ML
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1546 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1551 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // asap2_version: ASAP2_VERSION STRING
#line 1554 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5962 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // addr_epk: ADDR_EPK any_uint
#line 1558 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5968 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // address_type: ADDRESS_TYPE IDENT
#line 1559 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1560 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1561 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1562 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5992 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1563 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5998 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 523: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1564 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6004 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // alignment_long: ALIGNMENT_LONG any_uint
#line 1565 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6010 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // alignment_word: ALIGNMENT_WORD any_uint
#line 1566 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6016 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // annotation_label: ANNOTATION_LABEL STRING
#line 1567 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6022 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 527: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1568 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6028 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // array_size: ARRAY_SIZE any_uint
#line 1569 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6034 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1570 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6040 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1571 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6046 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1572 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6057 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1578 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6068 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 533: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1584 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6079 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 534: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1590 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1596 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6101 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1602 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 6113 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // bit_mask: BIT_MASK any_uint
#line 1609 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6119 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // byte_order: A2L_BYTE_ORDER IDENT
#line 1610 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 6125 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1611 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 6131 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1612 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6137 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1613 "D:/projects/a2llib/src/a2lparser.y"
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
#line 6152 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1623 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::deque<double> list;
	list.emplace_back(yystack_[1].value.as < double > ());
	list.emplace_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::deque<double> > () = std::move(list);
       }
#line 6163 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1629 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1630 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6175 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // conversion: CONVERSION IDENT
#line 1632 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6181 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 547: // cpu_type: CPU_TYPE STRING
#line 1633 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6187 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1634 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // customer: CUSTOMER STRING
#line 1635 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // customer_no: CUSTOMER_NO STRING
#line 1636 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // data_size: DATA_SIZE any_uint
#line 1637 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6211 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // default_value: DEFAULT_VALUE STRING
#line 1638 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6217 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1639 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6223 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // deposit: DEPOSIT IDENT
#line 1640 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 6229 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1642 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6235 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1643 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());}
#line 6241 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1644 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1648 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6259 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1652 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6268 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1656 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6277 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1660 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6286 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // ecu: ECU STRING
#line 1664 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6292 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // ecu_address: ECU_ADDRESS any_uint
#line 1665 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6298 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1666 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6304 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1667 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6310 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // encoding: ENCODING IDENT
#line 1668 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 6316 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // epk: EPK STRING
#line 1669 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6322 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // error_mask: ERROR_MASK any_uint
#line 1670 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6328 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1671 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 6334 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1672 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6340 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 572: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1673 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6346 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1674 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6352 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1675 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6358 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 575: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1676 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6364 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1677 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6370 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1678 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6376 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1679 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6387 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // format: FORMAT STRING
#line 1685 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6393 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // formula_inv: FORMULA_INV STRING
#line 1686 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1687 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 6405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // function_version: FUNCTION_VERSION STRING
#line 1688 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6411 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // identification: IDENTIFICATION any_uint IDENT
#line 1690 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6420 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // if_data: IF_DATA
#line 1694 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // input_quantity: INPUT_QUANTITY IDENT
#line 1695 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6432 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // layout: LAYOUT IDENT
#line 1696 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6438 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // left_shift: LEFT_SHIFT any_uint
#line 1697 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6444 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // limits: LIMITS any_float any_float
#line 1698 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < A2lLimits > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()}; }
#line 6450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // matrix_dim: MATRIX_DIM uint_list
#line 1699 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 6456 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 591: // max_grad: MAX_GRAD any_float
#line 1700 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6462 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 592: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1701 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6468 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // model_link: MODEL_LINK STRING
#line 1702 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // monotony: MONOTONY IDENT
#line 1703 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6480 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1704 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6489 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1708 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6498 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 597: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1712 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6507 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 598: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1716 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6516 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1720 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1724 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1725 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6540 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 602: // number: NUMBER any_uint
#line 1729 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6546 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 603: // offset_x: OFFSET_X any_uint IDENT
#line 1730 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 604: // offset_y: OFFSET_Y any_uint IDENT
#line 1734 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6564 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 605: // offset_z: OFFSET_Z any_uint IDENT
#line 1738 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 606: // offset_4: OFFSET_4 any_uint IDENT
#line 1742 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6582 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // offset_5: OFFSET_5 any_uint IDENT
#line 1746 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // phone_no: PHONE_NO STRING
#line 1750 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // phys_unit: PHYS_UNIT STRING
#line 1751 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 610: // proj_no: IDENT
#line 1752 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 611: // proj_no: any_uint
#line 1753 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 612: // project_no: PROJECT_NO proj_no
#line 1754 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 615: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1758 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // ref_unit: REF_UNIT IDENT
#line 1759 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6633 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 617: // reserved: RESERVED any_uint IDENT
#line 1760 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
    yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    }
#line 6642 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 618: // right_shift: RIGHT_SHIFT any_uint
#line 1764 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6648 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1765 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1769 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6666 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 621: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1773 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1777 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6684 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1781 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6693 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 624: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1785 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6702 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1791 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6711 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 628: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1795 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6720 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 629: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1799 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6729 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 630: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1803 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6738 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 631: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1807 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6747 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 633: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1812 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6761 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 634: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1821 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6770 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 635: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1825 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6779 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 636: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1829 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6788 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 637: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1833 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6797 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 638: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1837 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6806 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 641: // status_string_ref: STATUS_STRING_REF IDENT
#line 1843 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6812 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 642: // step_size: STEP_SIZE any_float
#line 1844 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6818 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 643: // supplier: SUPPLIER STRING
#line 1845 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6824 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 644: // symbol_link: SYMBOL_LINK STRING any_int
#line 1846 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6830 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 645: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1847 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6836 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 646: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1848 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6842 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 647: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1849 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6848 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 648: // user: USER STRING
#line 1850 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6854 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 649: // var_measurement: VAR_MEASUREMENT IDENT
#line 1851 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6860 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 650: // var_naming: VAR_NAMING IDENT
#line 1852 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6866 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 651: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1853 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6872 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 652: // var_separator: VAR_SEPARATOR STRING
#line 1854 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6878 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 653: // version: A2L_VERSION STRING
#line 1855 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6888 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -931;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
      64,   413,   100,   106,  -931,  -931,  -931,  -931,  -931,   204,
    -931,   -22,   204,  -931,  -931,  -931,   128,   204,   135,  -931,
     152,   -11,  -931,  -931,   109,  -931,   179,    79,    45,  -931,
    -931,  -931,  -931,   190,  -931,    58,  -931,  -931,    97,   200,
     301,  -931,  -931,  -931,    44,  -931,  -931,  -931,  -931,  -931,
     846,   116,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,   874,   874,   874,   874,   874,   874,   874,  -931,
     874,   240,   295,   874,   874,   297,   305,   874,   874,   874,
     874,   874,   874,   874,   874,   315,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,   318,   324,   328,   333,   335,
     339,   343,   406,   347,   349,   351,   352,   357,  -931,  -931,
    -931,   362,   373,   376,   382,   390,   394,   395,  -931,    17,
     204,   204,   316,   330,   364,   399,   204,   359,   405,  -931,
     204,  -931,  -931,   419,   427,   909,   363,  1041,   431,   428,
     204,   434,   436,   204,   438,    26,   192,   243,   445,   446,
    -931,  -931,  -931,  -931,  -931,  -931,   456,   204,   204,   458,
     204,   204,  -931,  -931,   204,   204,   329,   299,   204,   457,
     345,   204,   204,   204,   204,   204,   204,   204,   467,   204,
     469,   473,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,    99,   385,   204,   474,   475,   507,
     509,   494,   510,   512,   513,   204,   514,   515,   516,   517,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,   372,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,   522,   524,  -931,   527,   528,  -931,   532,   391,
     346,  -931,  -931,  -931,  -931,   542,   545,  -931,  -931,  -931,
    -931,   546,  -931,   548,   550,  -931,  -931,   481,   204,  -931,
     366,   463,  -931,   551,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     -19,   464,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,   204,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,   559,   563,   564,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     204,   565,  -931,  -931,  -931,   567,  -931,  -931,   569,   570,
     575,   579,   581,   582,   584,   585,   586,   587,   588,  -931,
    -931,  -931,  -931,  -931,   590,   593,   596,   597,   598,   599,
     600,   602,   604,   605,   606,   607,   609,   610,   611,   614,
     616,   617,   619,   620,   625,   626,   630,   631,   632,   634,
     636,   639,   641,   649,   204,   481,    91,   481,   204,    48,
    -931,  -931,  -931,  -931,   650,   230,   481,   310,   481,  -931,
     481,   481,  -931,  -931,  -931,  -931,   481,    62,  -931,    51,
    -931,   654,  -931,  -931,  -931,  -931,  -931,  -931,  -931,   874,
    -931,   874,   874,   874,   874,   874,  -931,  -931,  -931,  -931,
     874,    53,   481,   204,   204,   655,   204,    16,  -931,   660,
     661,   663,   664,   665,   204,  -931,  -931,  -931,  -931,  -931,
     667,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     668,   671,   465,   672,  -931,  -931,   673,   481,   503,   392,
    -931,   681,  -931,  -931,  -931,  -931,  -931,    46,   659,   125,
    -931,   488,   686,   687,    42,   658,   691,   697,   494,   204,
     699,   700,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,   703,   358,   481,    56,   704,    69,   706,   657,
     710,  -931,  -931,   623,  -931,  -931,  -931,  -931,    75,   695,
     747,   828,   912,   954,   967,   972,  -931,  1044,  1062,  1178,
      24,   618,   723,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,   481,
    -931,   204,    16,  -931,  -931,  -931,   731,   734,   736,   737,
     739,   740,   742,   743,   744,   204,  -931,  -931,   481,   481,
     746,  -931,  -931,   538,   748,   494,   481,  -931,  -931,  -931,
    -931,   613,   556,  -931,  -931,   752,     5,  -931,  -931,   204,
     751,  -931,  -931,  -931,  -931,   204,  -931,   494,   481,   674,
     714,   481,   481,   753,   761,   763,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,   718,   481,  -931,  -931,  -931,  -931,
     717,  -931,  -931,  -931,  -931,  -931,  -931,   874,   749,   750,
     767,   773,  -931,  -931,  -931,   775,   778,  -931,   725,   676,
     679,   662,   645,   622,   694,   647,   627,   795,  -931,  -931,
     204,   481,   163,  -931,   798,   494,   799,  -931,  -931,  -931,
    -931,  -931,   802,  -931,  -931,   481,   481,   481,   805,  -931,
    -931,   494,   481,  -931,  -931,   204,   615,   628,   810,   812,
    -931,  -931,  -931,   481,   817,  -931,  -931,   481,   816,  -931,
     481,   481,  -931,   729,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,   801,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,   204,  -931,  -931,   782,   785,  -931,   494,
     829,  -931,   730,   204,  -931,   214,   481,  -931,  -931,   204,
     494,  -931,   462,  -931,  -931,  -931,  -931,   481,   766,  -931,
     729,   481,  -931,   832,  -931,  -931,   149,  -931,  -931,   580,
    -931,  -931,    41,   204,  -931,   204,   127,   653,  -931,  -931,
    -931,  -931,   735,   484,  -931,   494,   644,  -931,  -931,   455,
     841,   481,  -931,   818,  -931,   573,   110,   728,   204,   204,
    -931,   204,   204,   842,   850,   853,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,   290,   741,   204,  -931,  -931,  -931,  -931,   334,   830,
     656,   854,   481,   204,   481,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,   821,   675,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     218,   494,  -931,   640,    -8,   815,   859,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,   771,   481,  -931,   733,
     866,   869,   481,   870,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,   874,   876,   877,  -931,  -931,  -931,   494,  1183,
    1216,   696,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     879,  -931,  -931,   481,  -931,  -931,  -931,   712,  -931,  -931,
    -931,  -931,  -931,   494,    74,   857,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,   886,  -931,   887,  -931,
    -931,  -931,   481,  -931,  -931,  -931,   481,  -931,   205,  1224,
    -931,   851,   494,   730,   716,   709,  -931,   903,  -931,  -931,
     494,  -931,  -931,  1229,  -931,  -931,  -931,   873,   204,   204,
    -931,  -931,  -931,  -931,  -931,   711,  -931,    54,  -931,  -931,
    -931,   906,  -931,  1245,   806,  1250,  -931,  -931,  -931,  -931,
     803,   204,   867,  -931,   713,  -931,   481,  -931,  -931,   481,
    -931,   727,    49,   888,   920,   932,   481,   481,   481,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,   481,
     481,  -931,   377,   204,   204,   855,  -931,  -931,  -931,  -931
  };

  const short
  A2lParser::yydefact_[] =
  {
      38,     0,     0,     0,    39,   516,     4,     2,     3,     0,
       1,     0,     0,    37,    40,   515,     0,     0,     0,   514,
       0,     0,   351,   352,     0,   349,     0,     0,     0,   350,
     209,   304,   305,     0,   348,     0,   306,   307,     0,     0,
       0,   210,   211,   212,     0,   208,   653,   610,   611,   612,
       0,     0,   513,   585,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   322,   323,   324,   325,   308,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     309,   321,     0,     0,     0,     0,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   503,   303,    26,    27,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   285,
     354,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
       0,   184,   199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,   506,   507,   504,   508,   509,     0,     0,     0,     0,
       0,     0,    22,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   295,   296,   286,   287,   289,   290,   291,   292,   293,
     294,   297,   298,   299,   300,   301,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,   640,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     404,   405,   406,   407,   408,   399,   400,   401,   402,   403,
     409,   410,     0,     0,   443,     0,     0,   474,     0,     0,
       0,   613,   490,   488,   489,     0,     0,    35,   502,   650,
     652,     0,    97,     0,     0,    18,    20,   163,     0,   179,
       0,     0,    33,     0,    33,    33,    33,    33,    33,   186,
     187,   188,   185,   191,   192,   193,   194,   195,   189,   190,
       0,     0,    33,   625,   201,   202,   200,   204,   205,   207,
     203,   206,   216,     0,   270,   519,   520,   521,   522,   523,
     524,   525,   538,   551,   554,   626,     0,     0,     0,   284,
     517,   547,   549,   550,   563,     5,     6,     7,   566,   568,
       0,     0,   600,   608,   643,     0,   648,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
     574,   575,   576,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,    33,   486,    33,     0,     0,     0,     0,     0,   145,
     154,   159,     9,    10,    11,     8,     0,     0,   169,     0,
      42,     0,    33,    33,    33,    33,    33,    33,   183,   171,
     582,   214,   232,   337,   412,   423,    33,    33,    33,   198,
     197,     0,     0,     0,     0,     0,     0,     0,   646,     0,
       0,     0,     0,     0,     0,   558,   559,   560,   561,   562,
       0,   584,   595,   596,   597,   598,   599,   601,   603,   604,
     605,   606,   607,   617,   619,   620,   621,   622,   623,   624,
     627,   628,   629,   630,   631,   634,   635,   636,   637,   638,
       0,     0,     0,     0,   444,   445,     0,     0,     0,     0,
     545,     0,   478,   475,   476,   477,   479,     0,     0,   494,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,    98,    99,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,     0,    33,   180,   181,   182,     0,    48,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    14,   614,   219,   217,   228,   218,   220,
     221,   222,   223,   224,   225,   226,   227,   229,   230,     0,
     112,     0,     0,    12,   265,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   442,   518,     0,     0,
       0,   473,   645,     0,     0,     0,     0,   482,   483,   484,
     485,     0,     0,    14,   495,     0,     0,   501,    36,     0,
       0,    96,   539,   556,   565,     0,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   150,   147,   148,
     149,   151,   152,    19,     0,     0,   155,   156,   157,    21,
       0,   160,   161,    23,   162,   552,   178,   581,     0,     0,
       0,     0,    45,    43,    44,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,   587,
     590,     0,     0,    12,     0,   262,     0,   531,   532,   533,
     534,   535,     0,   578,   426,     0,     0,     0,     0,   480,
     616,     0,     0,   413,    14,   492,     0,     0,     0,     0,
     498,   499,   500,     0,     0,   592,   644,     0,     0,   144,
       0,     0,   544,   176,   641,   153,   553,   158,    24,    41,
     526,   527,   529,     0,   170,   213,   231,   336,   411,   422,
     196,   414,   424,     0,    15,   235,     0,     0,   113,   262,
       0,    13,   261,     0,   536,     0,     0,   447,   461,     0,
       0,   647,     0,   493,   496,   649,   651,     0,     0,   115,
     176,     0,   542,     0,   175,   177,     0,    47,   339,     0,
      12,   111,     0,     0,   263,     0,     0,     0,   427,   428,
     429,   433,     0,     0,   416,     0,     0,    69,   557,     0,
       0,     0,   580,     0,    25,     0,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,    33,   238,   241,   249,
     236,   259,   237,   239,   240,   242,   243,   244,   245,   246,
     247,   248,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   109,     0,     0,    12,    33,    33,   425,     0,     0,
       0,     0,     0,     0,     0,   449,   448,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     0,     0,   465,
     462,   463,   464,   466,   467,   468,   469,   470,   471,   472,
       0,     0,   491,     0,     0,     0,     0,   583,   117,   118,
     116,   123,   130,   133,   143,   119,   120,   121,   122,   124,
     125,   126,   127,   128,   129,   131,   132,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,    46,     0,
       0,     0,     0,     0,   340,   341,   342,   343,   344,   345,
     346,   347,    91,    33,   234,   528,   537,   564,   569,   579,
     609,   615,   511,     0,     0,   110,   260,    12,   268,     0,
       0,     0,   434,   435,   436,   437,   438,   439,   440,   441,
       0,   446,   567,     0,   602,   642,   460,     0,   417,   418,
     419,   420,   421,     0,     0,     0,    71,    70,    79,    72,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,    33,     0,   114,
     543,   174,     0,   338,   546,   586,     0,   594,     0,     0,
     540,     0,   268,   267,     0,     0,   432,     0,   570,   415,
       0,    68,    33,     0,    33,   541,   589,     0,     0,     0,
     632,    92,    93,    94,    95,     0,   108,     0,   269,   430,
     431,     0,   633,     0,     0,     0,    90,   588,   618,   510,
       0,     0,     0,   233,     0,   266,     0,   172,   512,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      52,    61,    54,    55,    56,    57,    58,    59,    60,    62,
      63,    64,    65,    66,    67,    16,    50,   530,   548,     0,
       0,   591,     0,     0,     0,     0,    17,   571,   572,   173
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -931,    -1,  -219,  -167,  -739,  -650,  -931,  -931,  -931,  -931,
    -931,  1055,  -297,  -931,  -931,  -931,  -184,  -931,  -931,  -931,
    -931,    52,  -931,  -931,  -931,  -931,  -931,    55,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,    71,
    -931,  -931,  -931,  -931,  -931,  -931,  -802,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,    96,   268,  -931,  -158,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,   933,  -931,  -931,  -931,   772,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -495,   807,
     809,   811,   824,   825,   826,   827,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -824,  -856,  -536,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -392,  -931,  -930,  -789,  -534,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -531,  -931,    63,  -931,    70,  -864,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -867,  -931,
    -931,  -931,     3,  -931,   -43,  -931,  -807,  -931,  -931,  -573,
    -931,  -528,  -527,  -929,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,    88,  -931,  -931,  -931,  -931,  -931,  -931,  -865,  -931,
    -931,  -866,   111,  -857,   355,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -868,  -931,  -526,    11,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,   839
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   844,   851,   516,   785,   780,  1192,   510,   511,   377,
     876,   656,   529,   505,     2,     3,   389,   648,   762,   390,
     766,   955,  1161,  1170,    54,   983,  1077,   918,  1108,  1131,
      55,   507,   623,   848,  1044,   230,   782,    56,   899,   990,
      57,   633,   736,    58,   635,   746,    59,   637,   751,    60,
     517,   641,    61,   122,   149,   391,   991,  1171,   737,   874,
      62,   519,   645,    63,   186,   392,   405,    64,   187,   406,
      22,    35,    41,   393,    65,   541,   666,   394,   993,    66,
     879,   920,   231,   852,   686,   232,  1113,    67,   155,   202,
      68,   156,   233,    23,    33,    37,    44,    69,   395,   667,
     905,  1024,    13,    24,    25,    70,   157,   296,   396,   362,
     408,   602,   980,  1068,   397,   409,    71,   855,   888,   889,
     890,    72,   948,  1052,    73,   496,   594,    74,   892,   956,
      75,   893,   970,    76,   499,   603,    77,   607,   707,    78,
     165,   363,   714,   170,   715,   171,   716,   810,   172,    79,
     139,   173,   921,   994,    80,    14,     4,   234,   595,   203,
     204,   205,   206,   207,   208,   209,   763,   764,   923,   767,
    1172,   304,   305,   306,   307,   308,   309,   924,   210,   625,
    1045,   738,   739,   998,   740,   605,  1025,   235,  1174,   236,
     237,   211,   642,   748,   212,   926,   626,   310,   311,   312,
     313,   314,   238,   928,   627,   239,   960,   240,   930,   961,
    1177,  1178,   315,   316,   317,   318,   319,   320,   931,   875,
     646,   398,  1005,   321,   884,  1028,   673,  1132,  1029,   674,
    1180,   629,   630,  1030,   322,   323,   324,   325,   326,   241,
     327,   964,   328,   329,   330,   331,   332,   242,   937,    49,
      42,   364,   677,   939,   708,   333,  1133,   334,   335,   336,
     337,   338,   339,   411,   213,   340,   341,   342,   343,   344,
    1134,   709,   345,   346,   347,   348,   349,   350,   351,   742,
     966,   243,   631,   606,   244,   710,   245,   811,   174,   812,
     175,    43
  };

  const short
  A2lParser::yytable_[] =
  {
       9,    81,   438,   404,   604,   669,   520,   670,    15,   807,
     671,    17,   624,   675,   676,   678,    19,   520,  1054,  1057,
     166,   167,   684,   925,  1060,   962,   976,   965,   979,   359,
     360,  1014,  1004,  1012,  1011,  1003,   958,   973,  1027,    48,
    1031,  1026,  1013,   996,   849,   942,   668,    50,    51,   520,
     703,   598,   599,  1081,  1090,   643,   660,   661,  1150,    52,
     744,  1096,    38,   805,   720,   593,   639,   520,   957,   972,
     593,    39,   933,   750,   520,   995,     1,   919,   758,   759,
    1059,  1056,   536,  1058,  1055,    31,   977,   531,   532,   533,
     534,   535,  1053,   536,    26,   592,   720,   992,   616,   520,
      10,   760,   761,   959,   974,   540,   600,  1097,   593,    11,
     999,    27,    21,    28,   720,  1094,  1085,  1092,  1091,  1084,
      12,   148,    16,   640,   745,   617,  1093,  1079,   712,   640,
     526,   108,   537,   618,    18,   520,   640,  1185,   109,   176,
     177,   941,    20,   399,   410,   182,   720,   426,    53,   185,
     644,    53,  1032,   903,   862,    21,   904,    32,    53,   354,
      53,    53,   357,   538,   662,   777,   846,   847,   110,   663,
     685,   619,   361,  1070,   111,   536,   372,   373,   620,   375,
     376,  1078,   720,   378,   379,   112,    30,   412,   113,    34,
     415,   416,   417,   418,   419,   420,   421,    36,   423,   704,
     664,  1098,    45,    40,   608,  1048,   609,    46,   808,  1127,
     809,   536,     6,     7,     8,   430,   705,   886,   887,   427,
     428,   168,  1067,   169,   442,   650,   651,   652,   653,   654,
     655,  1175,  1181,   601,   611,   593,   612,   621,   107,   657,
     658,   659,   706,   747,   114,   752,   124,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,  1184,  1179,  1183,  1182,  1176,   435,   436,
     437,   125,   400,   401,   128,  1173,   934,    47,  1112,     6,
       7,     8,   129,   614,   615,   945,   946,  1128,  1033,   963,
     978,   138,   178,   622,   713,   140,  1007,   593,   591,   662,
     596,   141,   380,   381,   663,   142,   179,  1043,  1051,   613,
     143,   632,   144,   634,   636,   927,   145,   757,   929,   638,
     146,   935,   936,   940,   150,   616,   151,   665,   152,   153,
    1129,   729,   730,   997,   154,  1000,   214,   215,  1001,   158,
     180,  1008,  1009,  1015,  1130,   679,    39,   518,   198,   216,
     159,  1195,   617,   160,   922,   512,   513,   514,   515,   161,
     618,   520,   365,   366,   367,   382,   521,   162,   971,   724,
     402,   163,   164,   601,   200,   181,    53,  1071,   731,   732,
     147,   184,   542,   733,     6,     7,     8,    53,   183,   952,
       5,     6,     7,     8,   217,   188,   218,   219,   619,   913,
     699,   383,   522,   189,   353,   620,    53,   384,   352,   546,
     355,   220,   356,   385,   221,   358,   222,  1080,   387,  1082,
     368,   369,  1083,   370,   734,  1088,  1089,  1095,   984,   985,
    1023,   403,   371,   413,   628,   374,   896,   743,   414,   386,
       6,     7,     8,   422,   523,   424,   647,   914,   387,   425,
     524,   431,   432,   223,   224,  1069,   801,   967,   968,   512,
     513,   514,   515,   590,   621,   225,   909,   597,   672,   198,
     616,   593,   435,   436,   437,   226,   525,   986,   816,   429,
     388,   704,   781,   954,   433,   526,   434,   439,   440,   441,
     447,   443,   444,   445,   446,   909,   910,   617,   198,   494,
     495,   796,   797,   497,   498,   618,   735,   951,   500,   802,
     952,   501,   680,   681,   502,   683,   227,   527,   503,   228,
     913,   504,   506,   692,   508,   910,   402,   509,   530,   987,
     229,   817,    53,   528,   820,   821,   543,   539,   912,   544,
     545,   663,   547,   619,   548,   549,   550,  1019,   826,   913,
     620,   551,   860,   906,   907,   552,   701,   553,   554,   953,
     555,   556,   557,   558,   559,   662,   560,   593,   914,   561,
     663,   361,   562,   563,   564,   565,   566,   915,   567,   908,
     568,   569,   570,   571,   845,   572,   573,   574,   725,  1042,
     575,   909,   576,   577,   198,   578,   579,   914,   856,   857,
     858,   580,   581,  1020,   954,   861,   582,   583,   584,   621,
     585,   895,   586,  1074,  1075,   587,   867,   588,  1049,  1050,
     869,   910,   617,   871,   872,   589,   696,   610,   952,   911,
     618,   649,   682,   711,   912,   108,   687,   688,   913,   689,
     690,   691,   109,   693,   694,   913,   981,   695,   697,   698,
     783,   402,  1021,   700,   198,   616,  1022,    53,   702,   891,
     717,   662,   718,   719,   795,   917,   663,   722,   619,  1023,
     897,   721,   110,   723,   901,   620,   726,   727,   111,   728,
     200,   749,   617,   753,   754,   988,   914,   755,   813,   112,
     618,   756,   113,   914,   815,   952,   765,   664,   778,   779,
    1162,  1163,   915,   799,  1017,   913,  1109,   786,   949,   950,
     787,   402,   788,   789,   987,   790,   791,    53,   792,   793,
     794,   768,   798,   108,   800,   804,   806,   814,   619,   822,
     109,  1164,  1073,   803,   621,   620,  1023,   819,   823,   824,
     818,   198,   825,   827,   830,   829,   909,   828,   114,   198,
     831,   832,   833,   914,   835,  1063,   361,  1065,   916,  1165,
     110,   834,   915,   836,   838,   840,   111,   200,   841,  1076,
    1123,   843,   837,   839,   850,   853,   910,   112,   854,   842,
     113,   859,   952,  1166,  1167,   863,   865,   951,   866,   954,
     952,   868,   913,   870,   621,  1143,   873,  1145,   880,   864,
     913,   877,   769,   881,   108,   883,   932,    53,   898,   902,
     947,   109,   878,   982,  1168,  1016,  1018,  1034,  1061,  1039,
    1102,   663,   885,  1023,  1120,  1106,  1006,  1040,   894,  1041,
    1062,  1046,  1060,  1032,  1099,  1100,   114,  1101,  1066,   953,
     914,   110,  1104,   361,  1103,  1105,  1107,   111,   914,    82,
     108,  1111,   943,  1110,   944,  1117,  1116,   109,   112,    83,
    1121,   113,  1119,  1122,  1124,    84,  1118,  1136,  1140,    85,
      86,  1142,    87,    88,  1139,    89,   954,  1035,  1036,  1141,
    1037,  1038,  1151,   190,   954,  1146,   770,   110,   108,  1149,
    1186,  1153,  1158,   111,  1155,   109,  1187,   191,   192,   193,
     194,   195,   196,   197,   112,  1125,  1157,   113,  1188,  1126,
    1087,   900,  1047,  1199,    90,   882,    91,   114,   969,    92,
     784,   989,  1064,   198,  1137,   110,    93,    29,   771,   407,
     108,   111,  1002,   975,   297,    94,   298,   109,   299,    95,
      96,   772,   112,   108,   199,   113,   773,  1169,   108,   200,
     109,   300,   301,   302,   303,   109,  1086,  1010,   741,  1159,
     938,  1072,  1160,   114,    97,   246,     0,   110,     0,  1189,
    1190,  1191,     0,   111,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,   112,   110,   111,   113,     0,     0,
       0,   111,  1193,  1194,     0,  1196,     0,   112,     0,     0,
     113,   114,   112,    98,     0,   113,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   247,     0,     0,   774,     0,
     108,     0,     0,   106,     0,     0,     0,   109,     0,   191,
     192,   193,   194,   195,   196,   197,   775,     0,   108,     0,
    1138,     0,   201,   114,     0,   109,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,   114,   110,     0,     0,
       0,   114,     0,   111,  1138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   110,     0,   113,     0,     0,
       0,   111,     0,     0,   254,   255,   256,   257,   258,     0,
       0,     0,   112,     0,     0,   113,     0,  1147,  1148,     0,
     259,   260,   261,   262,   263,   264,     0,   115,   116,   117,
     118,   119,   120,   121,     0,   123,     0,   265,   126,   127,
    1156,     0,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,   114,     0,     0,     0,     0,   266,   267,
     268,   269,   270,     0,   271,     0,   272,   273,   274,   275,
     276,   114,   776,     0,   108,     0,     0,  1114,     0,   108,
       0,   109,  1197,  1198,     0,   277,   109,   278,   279,   280,
     281,   282,   283,     0,     0,   284,   285,   286,   287,   288,
       0,     0,   289,   290,   291,   292,   293,   294,   295,     0,
    1115,   110,   108,     0,     0,     0,   110,   111,  1135,   109,
     108,     0,   111,  1144,     0,   108,     0,   109,   112,     0,
       0,   113,   109,   112,     0,     0,   113,     0,     0,  1152,
       0,   108,     0,     0,  1154,     0,   108,     0,   109,   110,
       0,     0,     0,   109,     0,   111,     0,   110,     0,     0,
       0,     0,   110,   111,     0,     0,   112,     0,   111,   113,
       0,     0,     0,     0,   112,     0,     0,   113,   110,   112,
       0,     0,   113,   110,   111,     0,     0,   114,     0,   111,
       0,     0,   114,     0,     0,   112,     0,     0,   113,     0,
     112,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   114,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     0,     0,   114
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,    44,   221,   187,   499,   541,    25,   541,     9,     4,
     541,    12,   507,   541,   541,   541,    17,    25,   948,   948,
       3,     4,     6,   879,    32,   892,   893,   892,   893,     3,
       4,   899,   899,   899,   899,   899,   892,   893,   905,    40,
     905,   905,   899,   899,   783,     4,   541,     3,     4,    25,
       4,     3,     4,   983,   983,     4,     3,     4,     4,    15,
       4,    69,     4,   713,    72,    17,     4,    25,   892,   893,
      17,    13,   879,     4,    25,   899,    12,   879,     3,     4,
     948,   948,   101,   948,   948,     6,   893,   384,   385,   386,
     387,   388,   948,   101,   105,     4,    72,   899,    45,    25,
       0,    26,    27,   892,   893,   402,    58,   115,    17,     3,
     899,   122,     3,     4,    72,   983,   983,   983,   983,   983,
      14,   122,   144,    67,    68,    72,   983,   983,     3,    67,
     149,     6,   151,    80,     6,    25,    67,    88,    13,   140,
     141,   880,     7,   186,   187,   146,    72,    48,   107,   150,
      99,   107,    42,     4,   804,     3,     7,    78,   107,   160,
     107,   107,   163,   182,   111,   141,     3,     4,    43,   116,
     154,   118,   146,   980,    49,   101,   177,   178,   125,   180,
     181,   983,    72,   184,   185,    60,     7,   188,    63,   144,
     191,   192,   193,   194,   195,   196,   197,     7,   199,   153,
     147,   209,   105,   145,   501,   944,   503,     7,   203,     4,
     205,   101,     8,     9,    10,   216,   170,     3,     4,   120,
     121,   204,     4,   206,   225,   522,   523,   524,   525,   526,
     527,  1161,  1161,   185,     4,    17,     6,   184,   122,   536,
     537,   538,   196,   635,   119,   637,     6,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,  1161,  1161,  1161,  1161,  1161,     8,     9,
      10,     6,     3,     4,     7,  1161,   879,     6,  1047,     8,
       9,    10,     7,     3,     4,   188,   189,   112,   208,   892,
     893,     6,     6,   507,   199,     7,   899,    17,   495,   111,
     497,     7,     3,     4,   116,     7,     6,    47,     4,   506,
       7,   508,     7,   510,   511,   879,     7,   644,   879,   516,
       7,   879,   879,   879,     7,    45,     7,   541,     7,     7,
     155,     3,     4,   899,     7,   899,     3,     4,   899,     7,
       6,   899,   899,   899,   169,   542,    13,   378,    44,    16,
       7,     4,    72,     7,   879,     8,     9,    10,    11,     7,
      80,    25,   200,   201,   202,    66,    30,     7,   893,   618,
     101,     7,     7,   185,    70,     6,   107,   980,    50,    51,
       4,     6,   413,    55,     8,     9,    10,   107,    59,    85,
       7,     8,     9,    10,    61,     6,    63,    64,   118,    95,
     597,   102,    66,     6,     6,   125,   107,   108,     7,   440,
       6,    78,     6,   114,    81,     7,    83,   983,   149,   983,
     207,     6,   983,     7,    96,   983,   983,   983,     3,     4,
     126,   162,     6,     6,   507,     7,     4,   634,   123,   140,
       8,     9,    10,     6,   108,     6,   519,   143,   149,     6,
     114,     7,     7,   120,   121,   980,   705,     3,     4,     8,
       9,    10,    11,   494,   184,   132,    41,   498,   541,    44,
      45,    17,     8,     9,    10,   142,   140,    52,   727,   124,
     181,   153,   679,   179,     7,   149,     7,     7,     6,     6,
     148,     7,     7,     7,     7,    41,    71,    72,    44,     7,
       6,   698,   699,     6,     6,    80,   178,    82,     6,   706,
      85,   150,   543,   544,   198,   546,   183,   181,     6,   186,
      95,     6,     6,   554,     6,    71,   101,     7,     7,   104,
     197,   728,   107,   100,   731,   732,     7,   103,    84,     6,
       6,   116,     7,   118,     7,     6,     6,     4,   745,    95,
     125,     6,   801,     3,     4,     6,   194,     6,     6,   134,
       6,     6,     6,     6,     6,   111,     6,    17,   143,     6,
     116,   146,     6,     6,     6,     6,     6,   152,     6,    29,
       6,     6,     6,     6,   781,     6,     6,     6,   619,   916,
       6,    41,     6,     6,    44,     6,     6,   143,   795,   796,
     797,     6,     6,    60,   179,   802,     6,     6,     6,   184,
       6,   860,     6,     3,     4,     6,   813,     6,   945,   946,
     817,    71,    72,   820,   821,     6,   191,     7,    85,    79,
      80,     7,     7,     4,    84,     6,     6,     6,    95,     6,
       6,     6,    13,     6,     6,    95,   895,     6,     6,     6,
     681,   101,   109,   180,    44,    45,   113,   107,     7,   856,
     202,   111,     6,     6,   695,   879,   116,     6,   118,   126,
     867,    43,    43,     6,   871,   125,     7,     7,    49,     6,
      70,     7,    72,     7,    57,   899,   143,     7,   719,    60,
      80,    98,    63,   143,   725,    85,    31,   147,   110,     6,
       3,     4,   152,   195,   901,    95,  1033,     6,     3,     4,
       6,   101,     6,     6,   104,     6,     6,   107,     6,     6,
       6,     4,     6,     6,     6,   199,     4,     6,   118,     6,
      13,    34,   981,   150,   184,   125,   126,    53,     7,     6,
      96,    44,    54,    56,     7,    25,    41,    28,   119,    44,
       7,     6,     4,   143,   108,   952,   146,   954,   208,    62,
      43,    66,   152,   114,   149,   101,    49,    70,   151,   983,
    1097,     6,   140,   181,     6,     6,    71,    60,     6,   182,
      63,     6,    85,    86,    87,   200,     6,    82,     6,   179,
      85,     4,    95,     7,   184,  1122,    97,  1124,    46,   201,
      95,    30,     4,    48,     6,     6,   879,   107,    72,     7,
     187,    13,   843,   199,   117,     4,    28,   119,   192,     7,
    1017,   116,   853,   126,  1073,  1022,   899,     7,   859,     6,
       6,   120,    32,    42,    49,     6,   119,    96,   193,   134,
     143,    43,     6,   146,   141,     6,     6,    49,   143,    33,
       6,     4,   883,     7,   885,     6,   190,    13,    60,    43,
      33,    63,   180,     7,     7,    49,  1063,    46,   189,    53,
      54,  1120,    56,    57,   188,    59,   179,   908,   909,     6,
     911,   912,     6,     4,   179,    42,     4,    43,     6,   208,
      32,   115,   209,    49,   121,    13,     6,    18,    19,    20,
      21,    22,    23,    24,    60,  1102,    69,    63,     6,  1106,
     983,   870,   943,    88,    98,   849,   100,   119,   893,   103,
     682,   899,   953,    44,  1112,    43,   110,    24,     4,   187,
       6,    49,   899,   893,   157,   119,   157,    13,   157,   123,
     124,     4,    60,     6,    65,    63,     4,  1161,     6,    70,
      13,   157,   157,   157,   157,    13,   983,   899,   633,  1156,
     879,   980,  1159,   119,   148,   156,    -1,    43,    -1,  1166,
    1167,  1168,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    60,    43,    49,    63,    -1,    -1,
      -1,    49,  1189,  1190,    -1,  1192,    -1,    60,    -1,    -1,
      63,   119,    60,   187,    -1,    63,   190,   191,   192,   193,
     194,   195,    -1,    -1,   198,     4,    -1,    -1,     4,    -1,
       6,    -1,    -1,   207,    -1,    -1,    -1,    13,    -1,    18,
      19,    20,    21,    22,    23,    24,     4,    -1,     6,    -1,
    1113,    -1,   163,   119,    -1,    13,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,   119,    43,    -1,    -1,
      -1,   119,    -1,    49,  1137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    43,    -1,    63,    -1,    -1,
      -1,    49,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    60,    -1,    -1,    63,    -1,  1128,  1129,    -1,
      89,    90,    91,    92,    93,    94,    -1,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,   106,    93,    94,
    1151,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,   133,    -1,   135,   136,   137,   138,
     139,   119,     4,    -1,     6,    -1,    -1,     4,    -1,     6,
      -1,    13,  1193,  1194,    -1,   154,    13,   156,   157,   158,
     159,   160,   161,    -1,    -1,   164,   165,   166,   167,   168,
      -1,    -1,   171,   172,   173,   174,   175,   176,   177,    -1,
       4,    43,     6,    -1,    -1,    -1,    43,    49,     4,    13,
       6,    -1,    49,     4,    -1,     6,    -1,    13,    60,    -1,
      -1,    63,    13,    60,    -1,    -1,    63,    -1,    -1,     4,
      -1,     6,    -1,    -1,     4,    -1,     6,    -1,    13,    43,
      -1,    -1,    -1,    13,    -1,    49,    -1,    43,    -1,    -1,
      -1,    -1,    43,    49,    -1,    -1,    60,    -1,    49,    63,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    43,    60,
      -1,    -1,    63,    43,    49,    -1,    -1,   119,    -1,    49,
      -1,    -1,   119,    -1,    -1,    60,    -1,    -1,    63,    -1,
      60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   119
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   224,   225,   366,     7,     8,     9,    10,   211,
       0,     3,    14,   312,   365,   211,   144,   211,     6,   211,
       7,     3,   280,   303,   313,   314,   105,   122,     4,   314,
       7,     6,    78,   304,   144,   281,     7,   305,     4,    13,
     145,   282,   460,   501,   306,   105,     7,     6,   211,   459,
       3,     4,    15,   107,   234,   240,   247,   250,   253,   256,
     259,   262,   270,   273,   277,   284,   289,   297,   300,   307,
     315,   326,   331,   334,   337,   340,   343,   346,   349,   359,
     364,   434,    33,    43,    49,    53,    54,    56,    57,    59,
      98,   100,   103,   110,   119,   123,   124,   148,   187,   190,
     191,   192,   193,   194,   195,   198,   207,   122,     6,    13,
      43,    49,    60,    63,   119,   221,   221,   221,   221,   221,
     221,   221,   263,   221,     6,     6,   221,   221,     7,     7,
     221,   221,   221,   221,   221,   221,   221,   221,     6,   360,
       7,     7,     7,     7,     7,     7,     7,     4,   211,   264,
       7,     7,     7,     7,     7,   298,   301,   316,     7,     7,
       7,     7,     7,     7,     7,   350,     3,     4,   204,   206,
     353,   355,   358,   361,   498,   500,   211,   211,     6,     6,
       6,     6,   211,    59,     6,   211,   274,   278,     6,     6,
       4,    18,    19,    20,    21,    22,    23,    24,    44,    65,
      70,   163,   299,   369,   370,   371,   372,   373,   374,   375,
     388,   401,   404,   474,     3,     4,    16,    61,    63,    64,
      78,    81,    83,   120,   121,   132,   142,   183,   186,   197,
     245,   292,   295,   302,   367,   397,   399,   400,   412,   415,
     417,   449,   457,   491,   494,   496,   501,     4,    35,    36,
      37,    38,    39,    40,    73,    74,    75,    76,    77,    89,
      90,    91,    92,    93,    94,   106,   127,   128,   129,   130,
     131,   133,   135,   136,   137,   138,   139,   154,   156,   157,
     158,   159,   160,   161,   164,   165,   166,   167,   168,   171,
     172,   173,   174,   175,   176,   177,   317,   369,   370,   371,
     372,   373,   374,   375,   381,   382,   383,   384,   385,   386,
     407,   408,   409,   410,   411,   422,   423,   424,   425,   426,
     427,   433,   444,   445,   446,   447,   448,   450,   452,   453,
     454,   455,   456,   465,   467,   468,   469,   470,   471,   472,
     475,   476,   477,   478,   479,   482,   483,   484,   485,   486,
     487,   488,     7,     6,   211,     6,     6,   211,     7,     3,
       4,   146,   319,   351,   461,   200,   201,   202,   207,     6,
       7,     6,   211,   211,     7,   211,   211,   219,   211,   211,
       3,     4,    66,   102,   108,   114,   140,   149,   181,   226,
     229,   265,   275,   283,   287,   308,   318,   324,   431,   434,
       3,     4,   101,   162,   226,   276,   279,   318,   320,   325,
     434,   473,   211,     6,   123,   211,   211,   211,   211,   211,
     211,   211,     6,   211,     6,     6,    48,   120,   121,   124,
     211,     7,     7,     7,     7,     8,     9,    10,   212,     7,
       6,     6,   211,     7,     7,     7,     7,   148,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,     7,     6,   335,     6,     6,   344,
       6,   150,   198,     6,     6,   223,     6,   241,     6,     7,
     217,   218,     8,     9,    10,    11,   213,   260,   211,   271,
      25,    30,    66,   108,   114,   140,   149,   181,   100,   222,
       7,   222,   222,   222,   222,   222,   101,   151,   182,   103,
     222,   285,   211,     7,     6,     6,   211,     7,     7,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     211,   213,     4,    17,   336,   368,   213,   211,     3,     4,
      58,   185,   321,   345,   368,   395,   493,   347,   222,   222,
       7,     4,     6,   213,     3,     4,    45,    72,    80,   118,
     125,   184,   226,   242,   368,   389,   406,   414,   434,   441,
     442,   492,   213,   251,   213,   254,   213,   257,   213,     4,
      67,   261,   402,     4,    99,   272,   430,   434,   227,     7,
     222,   222,   222,   222,   222,   222,   221,   222,   222,   222,
       3,     4,   111,   116,   147,   226,   286,   309,   368,   389,
     406,   414,   434,   436,   439,   441,   442,   462,   492,   213,
     211,   211,     7,   211,     6,   154,   294,     6,     6,     6,
       6,     6,   211,     6,     6,     6,   191,     6,     6,   213,
     180,   194,     7,     4,   153,   170,   196,   348,   464,   481,
     495,     4,     3,   199,   352,   354,   356,   202,     6,     6,
      72,    43,     6,     6,   212,   211,     7,     7,     6,     3,
       4,    50,    51,    55,    96,   178,   252,   268,   391,   392,
     394,   464,   489,   213,     4,    68,   255,   402,   403,     7,
       4,   258,   402,     7,    57,     7,    98,   222,     3,     4,
      26,    27,   228,   376,   377,    31,   230,   379,     4,     4,
       4,     4,     4,     4,     4,     4,     4,   141,   110,     6,
     215,   213,   246,   211,   294,   214,     6,     6,     6,     6,
       6,     6,     6,     6,     6,   211,   213,   213,     6,   195,
       6,   212,   213,   150,   199,   215,     4,     4,   203,   205,
     357,   497,   499,   211,     6,   211,   212,   213,    96,    53,
     213,   213,     6,     7,     6,    54,   213,    56,    28,    25,
       7,     7,     6,     4,    66,   108,   114,   140,   149,   181,
     101,   151,   182,     6,   211,   213,     3,     4,   243,   214,
       6,   212,   293,     6,     6,   327,   213,   213,   213,     6,
     212,   213,   215,   200,   201,     6,     6,   213,     4,   213,
       7,   213,   213,    97,   269,   429,   220,    30,   211,   290,
      46,    48,   293,     6,   434,   211,     3,     4,   328,   329,
     330,   213,   338,   341,   211,   212,     4,   213,    72,   248,
     269,   213,     7,     4,     7,   310,     3,     4,    29,    41,
      71,    79,    84,    95,   143,   152,   208,   226,   237,   276,
     291,   362,   368,   378,   387,   388,   405,   406,   413,   414,
     418,   428,   434,   436,   439,   441,   442,   458,   462,   463,
     492,   214,     4,   211,   211,   188,   189,   187,   332,     3,
       4,    82,    85,   134,   179,   231,   339,   387,   388,   405,
     416,   419,   428,   439,   451,   458,   490,     3,     4,   237,
     342,   368,   387,   388,   405,   418,   428,   436,   439,   458,
     322,   212,   199,   235,     3,     4,    52,   104,   226,   231,
     249,   266,   276,   288,   363,   387,   388,   389,   393,   405,
     406,   414,   416,   419,   428,   432,   434,   439,   441,   442,
     451,   458,   461,   463,   490,   492,     4,   213,    28,     4,
      60,   109,   113,   126,   311,   396,   419,   428,   435,   438,
     443,   458,    42,   208,   119,   211,   211,   211,   211,     7,
       7,     6,   222,    47,   244,   390,   120,   211,   214,   222,
     222,     4,   333,   388,   404,   419,   428,   443,   458,   490,
      32,   192,     6,   213,   211,   213,   193,     4,   323,   368,
     436,   439,   493,   212,     3,     4,   226,   236,   276,   388,
     389,   404,   406,   414,   419,   428,   432,   434,   441,   442,
     443,   458,   461,   463,   490,   492,    69,   115,   209,    49,
       6,    96,   213,   141,     6,     6,   213,     6,   238,   222,
       7,     4,   214,   296,     4,     4,   190,     6,   213,   180,
     212,    33,     7,   222,     7,   213,   213,     4,   112,   155,
     169,   239,   437,   466,   480,     4,    46,   296,   434,   188,
     189,     6,   212,   222,     4,   222,    42,   211,   211,   208,
       4,     6,     4,   115,     4,   121,   211,    69,   209,   213,
     213,   232,     3,     4,    34,    62,    86,    87,   117,   226,
     233,   267,   380,   388,   398,   404,   419,   420,   421,   428,
     440,   443,   458,   461,   490,    88,    32,     6,     6,   213,
     213,   213,   216,   213,   213,     4,   213,   211,   211,    88
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
     302,   302,   302,   303,   304,   304,   305,   306,   306,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   309,   310,
     310,   311,   311,   311,   311,   311,   311,   311,   312,   313,
     313,   314,   314,   315,   316,   316,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   318,   318,   319,   320,   321,   322,   322,   323,   323,
     323,   323,   324,   324,   325,   326,   327,   327,   328,   328,
     329,   330,   331,   332,   332,   333,   333,   333,   333,   333,
     333,   333,   334,   335,   335,   336,   337,   338,   338,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     340,   341,   341,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   343,   344,   344,   345,   345,   345,   345,
     346,   347,   347,   348,   348,   348,   349,   350,   350,   351,
     351,   352,   352,   353,   354,   354,   355,   356,   356,   357,
     357,   358,   359,   360,   360,   361,   361,   361,   361,   361,
     362,   362,   363,   364,   365,   366,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501
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
       1,     1,     1,     7,     1,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     7,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     7,     1,
       2,     1,     1,     6,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     2,     5,     5,     8,     0,     2,     1,     1,
       1,     1,     5,     2,     5,    12,     0,     2,     1,     1,
       5,     5,    14,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     8,     0,     2,     1,    13,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      13,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     8,     0,     2,     1,     1,     1,     1,
       9,     0,     2,     1,     1,     1,     6,     0,     2,     1,
       1,     5,     2,     7,     0,     1,     7,     0,     2,     1,
       1,     5,     5,     0,     2,     1,     1,     1,     1,     1,
       5,     2,     6,     1,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     5,     5,     5,     5,     6,     2,     2,     2,
       2,     7,     3,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     5,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     4,     2,     2,     2,     2,     2,     5,     2,
       2,     2,     2,     1,     3,     1,     2,     2,     2,     3,
       2,     2,     3,     2,     2,     3,     3,     3,     3,     3,
       2,     3,     2,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     2,     1,     1,     2,     2,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     3,     3,
       3,     3,     1,     8,     3,     3,     3,     3,     3,     1,
       1,     2,     2,     2,     3,     2,     3,     3,     2,     2,
       2,     2,     2,     2
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
     993,   994,   995,   996,   998,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1023,  1029,  1032,  1037,  1042,  1043,  1044,
    1045,  1052,  1059,  1066,  1073,  1080,  1087,  1094,  1095,  1102,
    1109,  1116,  1119,  1126,  1133,  1134,  1135,  1142,  1149,  1156,
    1163,  1170,  1177,  1184,  1191,  1198,  1200,  1203,  1207,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1222,  1223,  1225,  1231,
    1232,  1234,  1235,  1240,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1302,  1305,  1308,  1309,  1311,  1318,  1319,  1320,  1321,
    1322,  1323,  1325,  1328,  1332,  1334,  1345,  1346,  1347,  1348,
    1350,  1351,  1353,  1366,  1367,  1368,  1369,  1370,  1371,  1372,
    1373,  1374,  1376,  1382,  1383,  1384,  1386,  1398,  1399,  1400,
    1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,
    1415,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1440,  1447,  1448,  1449,  1450,  1451,  1454,
    1456,  1463,  1464,  1465,  1466,  1467,  1472,  1476,  1477,  1478,
    1479,  1481,  1484,  1488,  1494,  1495,  1497,  1504,  1505,  1506,
    1507,  1509,  1511,  1512,  1513,  1514,  1518,  1522,  1526,  1530,
    1535,  1538,  1541,  1545,  1546,  1551,  1554,  1558,  1559,  1560,
    1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,  1570,
    1571,  1572,  1578,  1584,  1590,  1596,  1602,  1609,  1610,  1611,
    1612,  1613,  1623,  1629,  1630,  1631,  1632,  1633,  1634,  1635,
    1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1648,
    1652,  1656,  1660,  1664,  1665,  1666,  1667,  1668,  1669,  1670,
    1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,  1685,
    1686,  1687,  1688,  1689,  1690,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1708,  1712,  1716,  1720,
    1724,  1725,  1729,  1730,  1734,  1738,  1742,  1746,  1750,  1751,
    1752,  1753,  1754,  1756,  1757,  1758,  1759,  1760,  1764,  1765,
    1769,  1773,  1777,  1781,  1785,  1789,  1790,  1791,  1795,  1799,
    1803,  1807,  1811,  1812,  1821,  1825,  1829,  1833,  1837,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855
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
#line 8267 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1857 "D:/projects/a2llib/src/a2lparser.y"


void a2l::A2lParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err << std::endl;
    error << "Line: " << line << std::endl;
    error << "Near: " << near << std::endl;;
    scanner.LastError(error.str());
}
