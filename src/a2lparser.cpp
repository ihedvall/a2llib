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
#line 435 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2843 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 436 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2849 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_uint: INT
#line 437 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < int64_t > () < 0 ? 0 : static_cast<uint64_t>(yystack_[0].value.as < int64_t > ()); }
#line 2855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: INT
#line 439 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2861 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: UINT
#line 440 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_int: HEX
#line 441 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2873 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: FLOAT
#line 443 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: INT
#line 444 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2885 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: UINT
#line 445 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // any_float: HEX
#line 446 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: %empty
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // int_list: int_list any_int
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                     {yystack_[1].value.as < std::deque<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); yylhs.value.as < std::deque<int64_t> > () = std::move(yystack_[1].value.as < std::deque<int64_t> > ());  }
#line 2909 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: %empty
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // uint_list: uint_list any_uint
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                       {yystack_[1].value.as < std::deque<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[1].value.as < std::deque<uint64_t> > ());  }
#line 2921 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: %empty
#line 454 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2927 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_list: float_list any_float
#line 455 "D:/projects/a2llib/src/a2lparser.y"
                               {yystack_[1].value.as < std::deque<double> > ().emplace_back(yystack_[0].value.as < double > ()); yylhs.value.as < std::deque<double> > () = std::move(yystack_[1].value.as < std::deque<double> > ());  }
#line 2933 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: %empty
#line 457 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2939 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_pair_list: float_pair_list any_float any_float
#line 458 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	  yylhs.value.as < std::map<double, double> > () = std::move(yystack_[2].value.as < std::map<double, double> > ());
	  yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ());
	}
#line 2948 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: %empty
#line 463 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_string_list: float_string_list any_float STRING
#line 464 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	  yylhs.value.as < std::map<double, std::string> > () = std::move(yystack_[2].value.as < std::map<double, std::string> > ());
	  yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ());
	}
#line 2963 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: %empty
#line 469 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // float_range_list: float_range_list any_float any_float STRING
#line 470 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = std::move(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
	  yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ());
        }
#line 2978 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: %empty
#line 475 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // string_list: string_list STRING
#line 476 "D:/projects/a2llib/src/a2lparser.y"
                             {
	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
	}
#line 2993 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: %empty
#line 481 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2999 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // ident_list: ident_list IDENT
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                           {
       	  yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[1].value.as < std::deque<std::string> > ());
       	  yylhs.value.as < std::deque<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ());
       	}
#line 3008 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: %empty
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 3014 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 29: // key_value_list: key_value_list IDENT IDENT
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                                     {
       	  yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ());
       	  yylhs.value.as < std::map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ());
       }
#line 3023 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 499 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = std::move(yystack_[2].value.as < A2lAnnotation > ());}
#line 3029 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: %empty
#line 500 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 3035 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_label
#line 501 "D:/projects/a2llib/src/a2lparser.y"
                                              { yystack_[1].value.as < A2lAnnotation > ().Label = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3041 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_attributes: annotation_attributes annotation_origin
#line 502 "D:/projects/a2llib/src/a2lparser.y"
                                               { yystack_[1].value.as < A2lAnnotation > ().Origin = std::move(yystack_[0].value.as < std::string > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ()); }
#line 3047 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 38: // annotation_attributes: annotation_attributes annotation_text
#line 503 "D:/projects/a2llib/src/a2lparser.y"
                                             { yystack_[1].value.as < A2lAnnotation > ().Text = std::move(yystack_[0].value.as < std::deque<std::string> > ()); yylhs.value.as < A2lAnnotation > () = std::move(yystack_[1].value.as < A2lAnnotation > ());}
#line 3053 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 39: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 505 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 40: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 507 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3069 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // ar_component_attribute: %empty
#line 512 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3075 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // ar_component_attribute: ar_prototype_of
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3081 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 43: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 516 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3095 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: annotation
#line 529 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3101 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: axis_pts_ref
#line 530 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3107 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: byte_order
#line 531 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3113 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: curve_axis_ref
#line 532 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3119 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: deposit
#line 533 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3125 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: extended_limits
#line 534 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3131 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par
#line 535 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3137 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: fix_axis_par_dist
#line 536 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3143 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: fix_axis_par_list
#line 537 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::deque<double> > ()); }
#line 3149 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: format
#line 538 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3155 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: max_grad
#line 539 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3161 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: monotony
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3167 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: phys_unit
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3173 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: read_only
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3179 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_descr_attribute: step_size
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3185 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 61: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 546 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3203 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: annotation
#line 561 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3209 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: byte_order
#line 562 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3215 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: calibration_access
#line 563 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: deposit
#line 564 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: display_identifier
#line 565 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3233 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: ecu_address_extension
#line 566 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3239 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: extended_limits
#line 567 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3245 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: format
#line 568 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3251 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: function_list
#line 569 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3257 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: guard_rails
#line 570 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3263 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: if_data
#line 571 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: max_refresh
#line 572 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: model_link
#line 573 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: monotony
#line 574 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: phys_unit
#line 575 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: read_only
#line 576 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: ref_memory_segment
#line 577 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: step_size
#line 578 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 82: // axis_pts_attribute: symbol_link
#line 579 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 83: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 581 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3327 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // bit_operation_attribute: left_shift
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3333 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // bit_operation_attribute: right_shift
#line 589 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3339 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // bit_operation_attribute: sign_extend
#line 590 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3345 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 89: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 592 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 3357 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: address_type
#line 601 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3363 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: annotation
#line 602 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3369 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: calibration_access
#line 603 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3375 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: display_identifier
#line 604 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3381 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: ecu_address_extension
#line 605 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3387 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: if_data
#line 606 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3393 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: max_refresh
#line 607 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: model_link
#line 608 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // blob_attribute: symbol_link
#line 609 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3411 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 611 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lCalibrationHandle > ().Comment = std::move(yystack_[2].value.as < std::string > ());
}
#line 3420 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // calibration_handle_attribute: %empty
#line 615 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // calibration_handle_attribute: calibration_handle_text
#line 616 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 3432 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 619 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = std::move(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = std::move(yystack_[2].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3442 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // calibration_method_attributes: %empty
#line 624 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 625 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
		yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
		yylhs.value.as < std::deque<A2lCalibrationHandle> > () = std::move(yystack_[1].value.as < std::deque<A2lCalibrationHandle> > ());
	}
#line 3457 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 107: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 631 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: annotation
#line 645 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3480 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: axis_descr
#line 646 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: bit_mask
#line 649 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: byte_order
#line 650 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: calibration_access
#line 651 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: comparison_quantity
#line 652 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3512 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: dependent_characteristic
#line 653 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: discrete
#line 654 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3524 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: display_identifier
#line 655 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3530 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: ecu_address_extension
#line 656 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: encoding
#line 657 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3542 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: extended_limits
#line 658 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3548 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: format
#line 659 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: function_list
#line 660 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: guard_rails
#line 661 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3566 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: if_data
#line 662 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3572 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: map_list
#line 663 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3578 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: matrix_dim
#line 664 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 3584 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: max_refresh
#line 665 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3590 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: model_link
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3596 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: number
#line 667 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: phys_unit
#line 668 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: read_only
#line 669 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3614 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: ref_memory_segment
#line 670 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3620 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: step_size
#line 671 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: symbol_link
#line 672 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 136: // characteristic_attribute: virtual_characteristic
#line 673 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3638 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 137: // compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 675 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 3651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // compu_method_attribute: coeffs
#line 686 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::deque<double> > ()); }
#line 3657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // compu_method_attribute: coeffs_linear
#line 687 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::deque<double> > ()); }
#line 3663 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // compu_method_attribute: compu_tab_ref
#line 688 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3669 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // compu_method_attribute: formula
#line 689 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3679 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_method_attribute: ref_unit
#line 694 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3685 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 145: // compu_method_attribute: status_string_ref
#line 695 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3691 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 146: // compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 698 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, double> > ());
	}
#line 3704 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_tab_attribute: default_value
#line 709 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3710 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 150: // compu_tab_attribute: default_value_numeric
#line 710 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3716 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 151: // compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 713 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, std::string> > ());
	}
#line 3729 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 154: // compu_vtab_attribute: default_value
#line 723 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3735 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 155: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 726 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 3747 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 158: // compu_vtab_range_attribute: default_value
#line 735 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtabRange().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // controller_address: any_uint IDENT any_uint any_uint
#line 742 "D:/projects/a2llib/src/a2lparser.y"
                                                     {
    A2lControllerAddress address;
    address.Index = yystack_[3].value.as < uint64_t > ();
    address.ByteOrder = StringToByteOrder(yystack_[2].value.as < std::string > ());
    address.StartAddress = yystack_[1].value.as < uint64_t > ();
    address.Length = yystack_[0].value.as < uint64_t > ();
    auto& module = scanner.CurrentModule();
    module.AddControllerAddress(address);
    }
#line 3767 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 163: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 752 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 3775 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 164: // def_characteristic: DEF_CHARACTERISTIC ident_list
#line 755 "D:/projects/a2llib/src/a2lparser.y"
                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 3783 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 165: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 760 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 3789 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 166: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 762 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::deque<double> > () = std::move(yystack_[2].value.as < std::deque<double> > ()); }
#line 3795 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 167: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 764 "D:/projects/a2llib/src/a2lparser.y"
                                                                    {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()};
    }
#line 3803 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 168: // formula: FORMULA STRING formula_attribute
#line 767 "D:/projects/a2llib/src/a2lparser.y"
                                       {
        yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};
    }
#line 3811 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 169: // formula_attribute: %empty
#line 770 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3817 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 170: // formula_attribute: formula_inv
#line 771 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 3823 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 773 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 3835 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // frame_attribute: frame_measurement
#line 782 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // frame_attribute: if_data
#line 783 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 785 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 179: // function_attribute: annotation
#line 792 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3863 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // function_attribute: def_characteristic
#line 794 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3869 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // function_attribute: function_version
#line 795 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3875 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function_attribute: if_data
#line 796 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3881 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 184: // function_attribute: in_measurement
#line 797 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3887 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 185: // function_attribute: loc_measurement
#line 798 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3893 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // function_attribute: out_measurement
#line 799 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3899 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 187: // function_attribute: ref_characteristic
#line 800 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3905 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // function_attribute: sub_function
#line 801 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::deque<std::string> > ());}
#line 3911 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 803 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 3917 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // function_list: FUNCTION_LIST ident_list
#line 804 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3933 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 194: // group_attribute: annotation
#line 814 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3939 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // group_attribute: function_list
#line 815 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // group_attribute: if_data
#line 816 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3951 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // group_attribute: ref_characteristic
#line 817 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3957 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // group_attribute: ref_measurement
#line 818 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3963 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 199: // group_attribute: root
#line 819 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 3969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 200: // group_attribute: sub_group
#line 820 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 3975 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 201: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 822 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 3984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // header_attribute: project_no
#line 830 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 3993 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // header_attribute: version
#line 833 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 4002 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 838 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
    yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
}
#line 4010 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // in_measurement: IN_MEASUREMENT ident_list
#line 841 "D:/projects/a2llib/src/a2lparser.y"
                            {
      yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
}
#line 4018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 845 "D:/projects/a2llib/src/a2lparser.y"
                                                                                              {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 4030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // instance_attribute: address_type
#line 854 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // instance_attribute: annotation
#line 855 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // instance_attribute: calibration_access
#line 856 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 4048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // instance_attribute: display_identifier
#line 857 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4054 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // instance_attribute: ecu_address_extension
#line 858 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4060 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 216: // instance_attribute: if_data
#line 859 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4066 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // instance_attribute: layout
#line 860 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4072 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // instance_attribute: matrix_dim
#line 861 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 219: // instance_attribute: max_refresh
#line 862 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // instance_attribute: model_link
#line 863 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // instance_attribute: overwrite
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 4097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // instance_attribute: read_write
#line 866 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 4103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // instance_attribute: symbol_link
#line 867 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 869 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4117 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // loc_measurement: LOC_MEASUREMENT ident_list
#line 872 "D:/projects/a2llib/src/a2lparser.y"
                                 {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4125 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 876 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());}
#line 4131 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 879 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4147 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // measurement_attribute: address_type
#line 892 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4153 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // measurement_attribute: annotation
#line 893 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4159 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // measurement_attribute: array_size
#line 894 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4165 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // measurement_attribute: bit_mask
#line 895 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4171 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement_attribute: bit_operation
#line 896 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4177 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 235: // measurement_attribute: byte_order
#line 897 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4183 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 236: // measurement_attribute: discrete
#line 898 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4189 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: display_identifier
#line 899 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4195 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: ecu_address
#line 900 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4201 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: ecu_address_extension
#line 901 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: error_mask
#line 902 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: format
#line 903 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: function_list
#line 904 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // measurement_attribute: if_data
#line 905 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4231 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // measurement_attribute: layout
#line 906 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4237 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // measurement_attribute: matrix_dim
#line 907 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 4243 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // measurement_attribute: max_refresh
#line 908 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4249 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // measurement_attribute: model_link
#line 909 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4255 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // measurement_attribute: phys_unit
#line 910 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4261 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // measurement_attribute: read_write
#line 911 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4267 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // measurement_attribute: ref_memory_segment
#line 912 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4273 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // measurement_attribute: symbol_link
#line 913 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4279 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 252: // measurement_attribute: virtual
#line 914 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 4285 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 253: // memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes A2L_END MEMORY_LAYOUT
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                                                       {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[3].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[2].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4297 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // memory_layout: MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes
#line 924 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[4].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = std::move(yystack_[1].value.as < std::deque<int64_t> > ());
	yylhs.value.as < A2lMemoryLayout > ().IfDataList = std::move(yystack_[0].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4309 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // memory_layout_attributes: %empty
#line 932 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4315 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // memory_layout_attributes: memory_layout_attributes if_data
#line 933 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
        }
#line 4324 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 257: // prg_type: RESERVED
#line 938 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4330 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 258: // prg_type: IDENT
#line 939 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4336 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes A2L_END MEMORY_SEGMENT
#line 942 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4352 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 260: // memory_segment: MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes
#line 953 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 261: // memory_segment_attributes: %empty
#line 964 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4374 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // memory_segment_attributes: memory_segment_attributes if_data
#line 965 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	    yystack_[1].value.as < std::unordered_map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	    yylhs.value.as < std::unordered_map<std::string, std::string> > () = std::move(yystack_[1].value.as < std::unordered_map<std::string, std::string> > ());
	}
#line 4383 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 263: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 969 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = std::move(yystack_[3].value.as < std::string > ());
}
#line 4392 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 266: // mod_common_attribute: alignment_byte
#line 976 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4398 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 267: // mod_common_attribute: alignment_float16_ieee
#line 977 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4404 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // mod_common_attribute: alignment_float32_ieee
#line 978 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4410 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 269: // mod_common_attribute: alignment_float64_ieee
#line 979 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4416 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_common_attribute: alignment_int64
#line 980 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4422 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 271: // mod_common_attribute: alignment_long
#line 981 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4428 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 272: // mod_common_attribute: alignment_word
#line 982 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4434 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_common_attribute: byte_order
#line 983 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4440 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_common_attribute: data_size
#line 984 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4446 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 275: // mod_common_attribute: deposit
#line 985 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 277: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 988 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = std::move(yystack_[3].value.as < std::string > ());
	if (scanner.GetParseModuleInformationOnly()) {
	  YYACCEPT;
	}
}
#line 4464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_par_attribute: addr_epk
#line 998 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_par_attribute: calibration_method
#line 999 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4476 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_par_attribute: cpu_type
#line 1000 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 283: // mod_par_attribute: customer
#line 1001 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // mod_par_attribute: customer_no
#line 1002 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 285: // mod_par_attribute: ecu
#line 1003 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 286: // mod_par_attribute: ecu_calibration_offset
#line 1004 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // mod_par_attribute: epk
#line 1005 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4512 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // mod_par_attribute: memory_layout
#line 1006 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // mod_par_attribute: memory_segment
#line 1007 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4524 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // mod_par_attribute: no_of_interfaces
#line 1008 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4530 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // mod_par_attribute: phone_no
#line 1009 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // mod_par_attribute: supplier
#line 1010 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4542 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // mod_par_attribute: system_constant
#line 1011 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4548 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // mod_par_attribute: user
#line 1012 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // mod_par_attribute: version
#line 1013 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // module: A2L_BEGIN MODULE module_name module_comment module_attributes A2L_END MODULE
#line 1015 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	//auto& module = scanner.CurrentModule();
	//module.Name($3);
	//module.Description($4);
}
#line 4570 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // module_name: IDENT
#line 1021 "D:/projects/a2llib/src/a2lparser.y"
                   {
	auto& module = scanner.CurrentModule();
	module.Name(std::move(yystack_[0].value.as < std::string > ()));
}
#line 4579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // module_comment: STRING
#line 1026 "D:/projects/a2llib/src/a2lparser.y"
                       {
	auto& module = scanner.CurrentModule();
	module.Description(std::move(yystack_[0].value.as < std::string > ()));
}
#line 4588 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 301: // module_attribute: a2ml
#line 1033 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4594 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 302: // module_attribute: axis_pts
#line 1034 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 4602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module_attribute: blob
#line 1037 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 4610 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_attribute: characteristic
#line 1040 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 4618 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_attribute: compu_method
#line 1043 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 4626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 306: // module_attribute: compu_tab
#line 1046 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 4634 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 307: // module_attribute: compu_vtab
#line 1049 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 4642 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 308: // module_attribute: compu_vtab_range
#line 1052 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 4650 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: controller_addresses
#line 1055 "D:/projects/a2llib/src/a2lparser.y"
                               {}
#line 4656 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: frame
#line 1056 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 4664 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: function
#line 1059 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 4672 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 312: // module_attribute: group
#line 1062 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 4680 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // module_attribute: if_data
#line 1065 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4688 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // module_attribute: instance
#line 1068 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 4696 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 315: // module_attribute: measurement
#line 1071 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 4704 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // module_attribute: record_layout
#line 1076 "D:/projects/a2llib/src/a2lparser.y"
                        {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
#line 4712 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // module_attribute: transformer
#line 1079 "D:/projects/a2llib/src/a2lparser.y"
                      {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
#line 4720 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // module_attribute: typedef_axis
#line 1082 "D:/projects/a2llib/src/a2lparser.y"
                       {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
#line 4728 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // module_attribute: typedef_blob
#line 1085 "D:/projects/a2llib/src/a2lparser.y"
                       {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
#line 4736 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // module_attribute: typedef_characteristic
#line 1088 "D:/projects/a2llib/src/a2lparser.y"
                                 {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
#line 4744 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // module_attribute: typedef_measurement
#line 1091 "D:/projects/a2llib/src/a2lparser.y"
                              {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
#line 4752 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 324: // module_attribute: typedef_structure
#line 1094 "D:/projects/a2llib/src/a2lparser.y"
                            {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
#line 4760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 325: // module_attribute: unit
#line 1097 "D:/projects/a2llib/src/a2lparser.y"
               {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
#line 4768 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 326: // module_attribute: user_rights
#line 1100 "D:/projects/a2llib/src/a2lparser.y"
                      {
          auto& module = scanner.CurrentModule();
          module.AddUserRights(scanner.ReleaseUserRights()); }
#line 4776 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1105 "D:/projects/a2llib/src/a2lparser.y"
                                                                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 4784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 329: // out_measurement: OUT_MEASUREMENT ident_list
#line 1108 "D:/projects/a2llib/src/a2lparser.y"
                                 {
       yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 4792 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 330: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1112 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4802 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 333: // overwrite_attribute: conversion
#line 1119 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4808 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 334: // overwrite_attribute: extended_limits
#line 1120 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4814 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 335: // overwrite_attribute: format
#line 1121 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4820 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 336: // overwrite_attribute: input_quantity
#line 1122 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4826 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 337: // overwrite_attribute: limits
#line 1123 "D:/projects/a2llib/src/a2lparser.y"
                 {
	    scanner.CurrentOverwrite().LowerLimit(yystack_[0].value.as < A2lLimits > ().LowerLimit);
	    scanner.CurrentOverwrite().UpperLimit(yystack_[0].value.as < A2lLimits > ().UpperLimit);
	    }
#line 4835 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 338: // overwrite_attribute: monotony
#line 1127 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 339: // overwrite_attribute: phys_unit
#line 1128 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 340: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1130 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 344: // project_attribute: module
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 4866 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT
#line 1145 "D:/projects/a2llib/src/a2lparser.y"
                                                                                            {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 4875 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 348: // record_layout_attribute: alignment_byte
#line 1151 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 4881 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 349: // record_layout_attribute: alignment_float16_ieee
#line 1152 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 4887 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 350: // record_layout_attribute: alignment_float32_ieee
#line 1153 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 4893 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 351: // record_layout_attribute: alignment_float64_ieee
#line 1154 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 4899 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // record_layout_attribute: alignment_int64
#line 1155 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 4905 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 353: // record_layout_attribute: alignment_long
#line 1156 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 4911 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 354: // record_layout_attribute: alignment_word
#line 1157 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 4917 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 355: // record_layout_attribute: axis_pts_x
#line 1158 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: axis_pts_y
#line 1159 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4929 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: axis_pts_z
#line 1160 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4935 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: axis_pts_4
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4941 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: axis_pts_5
#line 1162 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4947 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: axis_rescale_x
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 4953 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: dist_op_x
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4959 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: dist_op_y
#line 1165 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4965 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: dist_op_z
#line 1166 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4971 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: dist_op_4
#line 1167 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4977 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: dist_op_5
#line 1168 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4983 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: fix_no_axis_pts_x
#line 1169 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 4989 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: fix_no_axis_pts_y
#line 1170 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 4995 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: fix_no_axis_pts_z
#line 1171 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 5001 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: fix_no_axis_pts_4
#line 1172 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 5007 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: fix_no_axis_pts_5
#line 1173 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 5013 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: fnc_values
#line 1174 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 5019 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: identification
#line 1175 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 5025 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: no_axis_pts_x
#line 1176 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5031 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: no_axis_pts_y
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5037 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: no_axis_pts_z
#line 1178 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5043 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: no_axis_pts_4
#line 1179 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5049 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: no_axis_pts_5
#line 1180 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5055 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: no_rescale_x
#line 1181 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5061 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: offset_x
#line 1182 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5067 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: offset_y
#line 1183 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5073 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: offset_z
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5079 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: offset_4
#line 1185 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5085 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: offset_5
#line 1186 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: reserved
#line 1187 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 5097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: rip_addr_w
#line 1188 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 5103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: rip_addr_x
#line 1189 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // record_layout_attribute: rip_addr_y
#line 1190 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // record_layout_attribute: rip_addr_z
#line 1191 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // record_layout_attribute: rip_addr_4
#line 1192 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5127 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // record_layout_attribute: rip_addr_5
#line 1193 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5133 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 391: // record_layout_attribute: src_addr_x
#line 1194 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 392: // record_layout_attribute: src_addr_y
#line 1195 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // record_layout_attribute: src_addr_z
#line 1196 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // record_layout_attribute: src_addr_4
#line 1197 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5157 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // record_layout_attribute: src_addr_5
#line 1198 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5163 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // record_layout_attribute: shift_op_x
#line 1199 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // record_layout_attribute: shift_op_y
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5175 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // record_layout_attribute: shift_op_z
#line 1201 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5181 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // record_layout_attribute: shift_op_4
#line 1202 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5187 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 400: // record_layout_attribute: shift_op_5
#line 1203 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 401: // record_layout_attribute: static_address_offsets
#line 1204 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // record_layout_attribute: static_record_layout
#line 1205 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1207 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // ref_characteristic: REF_CHARACTERISTIC ident_list
#line 1210 "D:/projects/a2llib/src/a2lparser.y"
                                    {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 405: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1213 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 406: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1214 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5233 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 407: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1217 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = std::move(yystack_[5].value.as < std::string > ());
        structure.Typedef = yystack_[4].value.as < std::string > ();
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5244 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // structure_component_attribute: address_type
#line 1225 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // structure_component_attribute: layout
#line 1226 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // structure_component_attribute: matrix_dim
#line 1227 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 413: // structure_component_attribute: symbol_type_link
#line 1228 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5268 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 414: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1230 "D:/projects/a2llib/src/a2lparser.y"
                                                                     {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5276 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 415: // sub_function: SUB_FUNCTION ident_list
#line 1233 "D:/projects/a2llib/src/a2lparser.y"
                              {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5284 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 416: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1237 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5290 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 417: // transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1240 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // transformer_attribute: transformer_in_objects
#line 1252 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 421: // transformer_attribute: transformer_out_objects
#line 1253 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 422: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1255 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 423: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1256 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ()); }
#line 5329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 424: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1259 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5346 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 427: // typedef_axis_attribute: byte_order
#line 1273 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5352 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 428: // typedef_axis_attribute: deposit
#line 1274 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5358 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // typedef_axis_attribute: extended_limits
#line 1275 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5364 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // typedef_axis_attribute: format
#line 1276 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5370 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // typedef_axis_attribute: monotony
#line 1277 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5376 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 432: // typedef_axis_attribute: phys_unit
#line 1278 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5382 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 433: // typedef_axis_attribute: step_size
#line 1279 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5388 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 434: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1281 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                        {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 437: // typedef_blob_attribute: address_type
#line 1289 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1292 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5421 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 441: // typedef_characteristic_attribute: axis_descr
#line 1305 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5430 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 442: // typedef_characteristic_attribute: bit_mask
#line 1309 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5436 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 443: // typedef_characteristic_attribute: byte_order
#line 1310 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5442 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 444: // typedef_characteristic_attribute: discrete
#line 1311 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_characteristic_attribute: encoding
#line 1312 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5454 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 446: // typedef_characteristic_attribute: extended_limits
#line 1313 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5460 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 447: // typedef_characteristic_attribute: format
#line 1314 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5466 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 448: // typedef_characteristic_attribute: matrix_dim
#line 1315 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5472 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 449: // typedef_characteristic_attribute: number
#line 1316 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5478 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 450: // typedef_characteristic_attribute: phys_unit
#line 1317 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5484 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 451: // typedef_characteristic_attribute: step_size
#line 1318 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5490 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1321 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 455: // typedef_measurement_attribute: address_type
#line 1334 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5512 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 456: // typedef_measurement_attribute: bit_mask
#line 1335 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // typedef_measurement_attribute: bit_operation
#line 1336 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5524 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // typedef_measurement_attribute: byte_order
#line 1337 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5530 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // typedef_measurement_attribute: discrete
#line 1338 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 460: // typedef_measurement_attribute: error_mask
#line 1339 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5542 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 461: // typedef_measurement_attribute: format
#line 1340 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5548 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 462: // typedef_measurement_attribute: layout
#line 1341 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 463: // typedef_measurement_attribute: matrix_dim
#line 1342 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 464: // typedef_measurement_attribute: phys_unit
#line 1343 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5566 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING any_uint typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1346 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5577 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 468: // typedef_structure_attribute: address_type
#line 1354 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5583 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // typedef_structure_attribute: consistent_exchange
#line 1355 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5589 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 470: // typedef_structure_attribute: structure_component
#line 1356 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 471: // typedef_structure_attribute: symbol_type_link
#line 1359 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1361 "D:/projects/a2llib/src/a2lparser.y"
                                                                            {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 475: // unit_attribute: ref_unit
#line 1370 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 476: // unit_attribute: si_exponents
#line 1371 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 477: // unit_attribute: unit_conversion
#line 1372 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5636 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1377 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_rights = scanner.CurrentUserRights();
       user_rights.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5645 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 481: // user_rights_attribute: read_only
#line 1383 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRights().ReadOnly = true; }
#line 5651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 482: // user_rights_attribute: ref_group
#line 1384 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRights().RefGroupList.emplace_back(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 5657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1386 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5665 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // var_address: VAR_ADDRESS uint_list
#line 1389 "D:/projects/a2llib/src/a2lparser.y"
                            {
        yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ());
    }
#line 5673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1394 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = std::move(yystack_[3].value.as < std::deque<std::string> > ());
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = std::move(yystack_[2].value.as < std::deque<uint64_t> > ());
    }
#line 5683 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // var_characteristic_attribute: %empty
#line 1399 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5689 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 487: // var_characteristic_attribute: var_address
#line 1400 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 5695 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1402 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = std::move(yystack_[4].value.as < std::string > ());
    yylhs.value.as < A2lVarCriterion > ().Description = std::move(yystack_[3].value.as < std::string > ());
}
#line 5706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 491: // var_criterion_attribute: var_measurement
#line 1411 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = std::move(yystack_[0].value.as < std::string > ()); }
#line 5712 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // var_criterion_attribute: var_selection_characteristic
#line 1412 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = std::move(yystack_[0].value.as < std::string > ()); }
#line 5718 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 493: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1414 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::map<std::string, std::string> > () = std::move(yystack_[2].value.as < std::map<std::string, std::string> > ()); }
#line 5724 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 497: // variant_coding_attribute: var_characteristic
#line 1419 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5733 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // variant_coding_attribute: var_criterion
#line 1423 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5742 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // variant_coding_attribute: var_forbidden_comb
#line 1427 "D:/projects/a2llib/src/a2lparser.y"
                             {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(std::move(yystack_[0].value.as < std::map<std::string, std::string> > ()));
       }
#line 5751 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // variant_coding_attribute: var_naming
#line 1431 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = std::move(yystack_[0].value.as < std::string > ());
       }
#line 5760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // variant_coding_attribute: var_separator
#line 1435 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = std::move(yystack_[0].value.as < std::string > ());
      }
#line 5769 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 502: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1440 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[2].value.as < std::deque<std::string> > ());
    }
#line 5777 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 503: // virtual: VIRTUAL ident_list
#line 1443 "D:/projects/a2llib/src/a2lparser.y"
                         {
        yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ());
    }
#line 5785 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1447 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::deque<std::string> > ()}; }
#line 5791 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // a2ml: A2ML
#line 1450 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5797 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1451 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5806 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1456 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // asap2_version: ASAP2_VERSION STRING
#line 1459 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5823 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // addr_epk: ADDR_EPK any_uint
#line 1463 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5829 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // address_type: ADDRESS_TYPE IDENT
#line 1464 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5835 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1465 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1466 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1467 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5853 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1468 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5859 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1469 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5865 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // alignment_long: ALIGNMENT_LONG any_uint
#line 1470 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5871 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // alignment_word: ALIGNMENT_WORD any_uint
#line 1471 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5877 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // annotation_label: ANNOTATION_LABEL STRING
#line 1472 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5883 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1473 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5889 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // array_size: ARRAY_SIZE any_uint
#line 1474 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5895 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1475 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 5901 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1476 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5907 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 523: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1477 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5918 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1483 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5929 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1489 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5940 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1495 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5951 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 527: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1501 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5962 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1507 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // bit_mask: BIT_MASK any_uint
#line 1514 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // byte_order: A2L_BYTE_ORDER IDENT
#line 1515 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 5986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1516 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 5992 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1517 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 5998 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 533: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1518 "D:/projects/a2llib/src/a2lparser.y"
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
#line 6013 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 534: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1528 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::deque<double> list;
	list.emplace_back(yystack_[1].value.as < double > ());
	list.emplace_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::deque<double> > () = std::move(list);
       }
#line 6024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1534 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1535 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // conversion: CONVERSION IDENT
#line 1537 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // cpu_type: CPU_TYPE STRING
#line 1538 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1539 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6054 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // customer: CUSTOMER STRING
#line 1540 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6060 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // customer_no: CUSTOMER_NO STRING
#line 1541 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6066 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // data_size: DATA_SIZE any_uint
#line 1542 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6072 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // default_value: DEFAULT_VALUE STRING
#line 1543 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1544 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // deposit: DEPOSIT IDENT
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 6090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1547 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1548 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());}
#line 6102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1549 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6111 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1553 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6120 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1557 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6129 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1561 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6138 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1565 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6147 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 555: // ecu: ECU STRING
#line 1569 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6153 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // ecu_address: ECU_ADDRESS any_uint
#line 1570 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6159 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1571 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6165 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1572 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 6171 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // encoding: ENCODING IDENT
#line 1573 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 6177 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // epk: EPK STRING
#line 1574 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6183 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // error_mask: ERROR_MASK any_uint
#line 1575 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6189 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1576 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 6195 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1577 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6201 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1578 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1579 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1580 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1581 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1582 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6231 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1583 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6237 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1584 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // format: FORMAT STRING
#line 1590 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6254 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 572: // formula_inv: FORMULA_INV STRING
#line 1591 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6260 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1592 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::deque<std::string> > () = std::move(yystack_[0].value.as < std::deque<std::string> > ()); }
#line 6266 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // function_version: FUNCTION_VERSION STRING
#line 1593 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6272 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // identification: IDENTIFICATION any_uint IDENT
#line 1595 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // if_data: IF_DATA
#line 1599 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // input_quantity: INPUT_QUANTITY IDENT
#line 1600 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // layout: LAYOUT IDENT
#line 1601 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // left_shift: LEFT_SHIFT any_uint
#line 1602 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // limits: LIMITS any_float any_float
#line 1603 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < A2lLimits > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()}; }
#line 6311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // matrix_dim: MATRIX_DIM uint_list
#line 1604 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::deque<uint64_t> > () = std::move(yystack_[0].value.as < std::deque<uint64_t> > ()); }
#line 6317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // max_grad: MAX_GRAD any_float
#line 1605 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1606 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // model_link: MODEL_LINK STRING
#line 1607 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // monotony: MONOTONY IDENT
#line 1608 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6341 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1609 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6350 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1613 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6359 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1617 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1621 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6377 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 591: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1625 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6386 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 592: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1629 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6392 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1630 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // number: NUMBER any_uint
#line 1634 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // offset_x: OFFSET_X any_uint IDENT
#line 1635 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6416 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // offset_y: OFFSET_Y any_uint IDENT
#line 1639 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6425 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 597: // offset_z: OFFSET_Z any_uint IDENT
#line 1643 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6434 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 598: // offset_4: OFFSET_4 any_uint IDENT
#line 1647 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6443 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // offset_5: OFFSET_5 any_uint IDENT
#line 1651 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // phone_no: PHONE_NO STRING
#line 1655 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // phys_unit: PHYS_UNIT STRING
#line 1656 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 602: // proj_no: IDENT
#line 1657 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 603: // proj_no: any_uint
#line 1658 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6476 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 604: // project_no: PROJECT_NO proj_no
#line 1659 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1663 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // ref_unit: REF_UNIT IDENT
#line 1664 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // reserved: RESERVED any_uint IDENT
#line 1665 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
    yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    }
#line 6503 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 610: // right_shift: RIGHT_SHIFT any_uint
#line 1669 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 611: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1670 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 612: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1674 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6527 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 613: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1678 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6536 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 614: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1682 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6545 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 615: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1686 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1690 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6563 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1696 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6572 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1700 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6581 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 621: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1704 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6590 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1708 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6599 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1712 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 625: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1717 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6622 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 626: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1726 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6631 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1730 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6640 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 628: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1734 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 629: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1738 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6658 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 630: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1742 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6667 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 633: // status_string_ref: STATUS_STRING_REF IDENT
#line 1748 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 634: // step_size: STEP_SIZE any_float
#line 1749 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6679 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 635: // supplier: SUPPLIER STRING
#line 1750 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6685 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 636: // symbol_link: SYMBOL_LINK STRING any_int
#line 1751 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6691 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 637: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1752 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6697 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 638: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1753 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6703 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 639: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1754 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6709 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 640: // user: USER STRING
#line 1755 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6715 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 641: // var_measurement: VAR_MEASUREMENT IDENT
#line 1756 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6721 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 642: // var_naming: VAR_NAMING IDENT
#line 1757 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6727 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 643: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1758 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6733 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 644: // var_separator: VAR_SEPARATOR STRING
#line 1759 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 6739 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 645: // version: A2L_VERSION STRING
#line 1760 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());}
#line 6745 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6749 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -926;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
      71,   473,    91,   159,  -926,  -926,  -926,  -926,  -926,   308,
    -926,   -38,   308,  -926,  -926,  -926,   120,   308,   136,  -926,
     144,   -27,  -926,  -926,   299,  -926,   150,   158,    26,  -926,
    -926,  -926,   167,  -926,    54,  -926,  -926,   113,   215,   408,
    -926,  -926,  -926,    85,  -926,  -926,  -926,  -926,  -926,   914,
     111,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   293,   301,   304,   321,   342,   366,   373,  -926,   377,
     385,   388,   389,   400,   281,   315,   419,   424,   436,   442,
     451,   452,   456,   470,   484,  -926,  -926,   412,   459,   487,
     491,   507,   508,   511,   393,   515,   524,   529,   532,   540,
    -926,  -926,  -926,   561,   562,   570,   572,   573,   574,   578,
    -926,    15,   308,   308,   485,   520,   526,   537,   308,   348,
     549,  -926,   308,  -926,  -926,   553,   581,   552,   525,  1059,
     583,   585,   308,   586,   587,   308,   588,    62,   175,   360,
     591,   593,  -926,  -926,  -926,  -926,  -926,  -926,   592,   308,
     308,   594,   308,   308,  -926,  -926,   308,   308,   370,   197,
     308,   596,   482,   308,   308,   308,   308,   308,   308,   308,
     601,   308,   603,   605,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,    46,   488,   308,   609,
     611,   612,   616,   503,   619,   621,   622,   308,   623,   629,
     630,   633,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   481,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,   635,   637,  -926,   638,   641,  -926,
     642,   499,   455,  -926,  -926,  -926,  -926,   644,   648,  -926,
    -926,  -926,  -926,   649,  -926,   650,   651,  -926,  -926,   494,
     308,  -926,   413,   559,  -926,   654,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,    45,   563,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,   308,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   661,   663,
     664,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,   308,   666,  -926,  -926,  -926,   670,  -926,  -926,
     665,   672,   673,   674,   676,   677,   682,   684,   685,   686,
     688,  -926,  -926,  -926,  -926,  -926,   689,   691,   693,   694,
     696,   697,   706,   711,   712,   714,   718,   719,   721,   722,
     723,   724,   727,   728,   729,   730,   732,   733,   734,   735,
     737,   738,   740,   742,   743,   744,   308,   494,   101,   494,
     308,    38,  -926,  -926,  -926,  -926,   702,   129,   494,   381,
     494,  -926,   494,   494,  -926,  -926,  -926,  -926,   494,    93,
    -926,    49,  -926,   745,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   747,  -926,   747,   747,   747,   747,   747,  -926,  -926,
    -926,  -926,   747,   316,   494,   308,   308,   749,   308,    23,
    -926,   748,   751,   752,   754,   755,   308,  -926,  -926,  -926,
    -926,  -926,   757,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,   760,   761,   577,   763,  -926,  -926,   765,   494,
     571,   584,  -926,   767,  -926,  -926,  -926,  -926,  -926,   141,
     174,    37,  -926,   575,   769,   773,    56,   739,   774,   775,
     503,   308,   776,   777,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,   780,    53,   494,    43,   784,   130,
     785,   736,   788,  -926,  -926,   698,  -926,  -926,  -926,  -926,
     282,   756,   198,   285,   319,   345,   350,   376,  -926,   383,
     418,   431,    20,   690,   793,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   494,  -926,   308,    23,  -926,  -926,  -926,   795,   796,
     798,   799,   802,   805,   807,   808,   809,   308,  -926,  -926,
     494,   494,   810,  -926,  -926,   614,   811,   503,   494,  -926,
    -926,  -926,  -926,   668,   620,  -926,  -926,   817,    32,  -926,
    -926,   308,   816,  -926,  -926,  -926,  -926,   308,  -926,   503,
     494,   731,   770,   494,   494,   818,   819,   822,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,   771,   494,  -926,  -926,
    -926,  -926,   781,  -926,  -926,  -926,  -926,  -926,  -926,   747,
     804,   813,   823,   826,  -926,  -926,  -926,   830,   837,  -926,
     779,   750,   741,   713,   707,   662,   758,   701,   675,   836,
    -926,  -926,   308,   494,   327,  -926,   854,   503,   855,  -926,
    -926,  -926,  -926,  -926,   856,  -926,  -926,   494,   494,   494,
     857,  -926,  -926,   503,   494,  -926,  -926,   308,   667,   669,
     858,   859,  -926,  -926,  -926,   494,   862,  -926,  -926,   494,
     861,  -926,   494,   494,  -926,   772,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,   841,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,   308,  -926,  -926,   831,   824,
    -926,   503,   872,  -926,   778,   308,  -926,   332,   494,  -926,
    -926,   308,   503,  -926,   460,  -926,  -926,  -926,  -926,   494,
     812,  -926,   772,   494,  -926,   873,  -926,  -926,   213,  -926,
    -926,   349,  -926,  -926,    16,   308,  -926,   308,   151,   692,
    -926,  -926,  -926,  -926,   660,   297,  -926,   503,   687,  -926,
    -926,   580,   883,   494,  -926,   863,  -926,   435,    21,   786,
     308,   308,  -926,   308,   308,   882,   885,   884,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,    77,   789,   308,  -926,  -926,  -926,  -926,
      55,   864,   705,   887,   494,   308,   494,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   852,
     715,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,    47,   503,  -926,   803,    29,   846,   900,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   815,   494,
    -926,   782,   906,   907,   494,   908,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,   747,   909,   911,  -926,  -926,  -926,
     503,   469,   519,   746,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,   912,  -926,  -926,   494,  -926,  -926,  -926,   753,
    -926,  -926,  -926,  -926,  -926,   503,    35,   886,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,   910,  -926,
     915,  -926,  -926,  -926,   494,  -926,  -926,  -926,   494,  -926,
      40,   536,  -926,   879,   503,   778,   762,   759,  -926,   920,
    -926,  -926,   503,  -926,  -926,   548,  -926,  -926,  -926,   888,
     308,   308,  -926,  -926,  -926,  -926,  -926,   764,  -926,    58,
    -926,  -926,  -926,   921,  -926,   554,   825,   560,  -926,  -926,
    -926,  -926,   820,   308,   868,  -926,   783,  -926,   494,  -926,
    -926,   494,  -926,   703,   117,   899,   926,   932,   494,   494,
     494,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,   494,   494,  -926,   401,   308,   308,   851,  -926,  -926,
    -926,  -926
  };

  const short
  A2lParser::yydefact_[] =
  {
      31,     0,     0,     0,    32,   508,     4,     2,     3,     0,
       1,     0,     0,    30,    33,   507,     0,     0,     0,   506,
       0,     0,   343,   344,     0,   341,     0,     0,     0,   342,
     202,   297,     0,   340,     0,   298,   299,     0,     0,     0,
     203,   204,   205,     0,   201,   645,   602,   603,   604,     0,
       0,   505,   577,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   314,   315,   316,   317,   300,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   301,
     313,     0,     0,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   278,   346,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,   177,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   497,   498,   499,   496,   500,   501,     0,     0,
       0,     0,     0,     0,    22,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   288,   289,   279,   280,   282,   283,   284,
     285,   286,   287,   290,   291,   292,   293,   294,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   631,   632,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   396,   397,   398,   399,   400,   391,   392,   393,
     394,   395,   401,   402,     0,     0,   435,     0,     0,   466,
       0,     0,     0,   605,   482,   480,   481,     0,     0,    28,
     494,   642,   644,     0,    90,     0,     0,    18,    20,   156,
       0,   172,     0,     0,    26,     0,    26,    26,    26,    26,
      26,   179,   180,   181,   178,   184,   185,   186,   187,   188,
     182,   183,     0,     0,    26,   617,   194,   195,   193,   197,
     198,   200,   196,   199,   209,     0,   263,   511,   512,   513,
     514,   515,   516,   517,   530,   543,   546,   618,     0,     0,
       0,   277,   509,   539,   541,   542,   555,     5,     6,     7,
     558,   560,     0,     0,   592,   600,   635,     0,   640,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   565,   566,   567,   568,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,    26,   478,    26,     0,     0,     0,     0,
       0,   138,   147,   152,     9,    10,    11,     8,     0,     0,
     162,     0,    35,     0,    26,    26,    26,    26,    26,    26,
     176,   164,   574,   207,   225,   329,   404,   415,    26,    26,
      26,   191,   190,     0,     0,     0,     0,     0,     0,     0,
     638,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,     0,   576,   587,   588,   589,   590,   591,   593,
     595,   596,   597,   598,   599,   609,   611,   612,   613,   614,
     615,   616,   619,   620,   621,   622,   623,   626,   627,   628,
     629,   630,     0,     0,     0,     0,   436,   437,     0,     0,
       0,     0,   537,     0,   470,   467,   468,   469,   471,     0,
       0,   486,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    91,    92,    94,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,     0,    26,   173,   174,   175,
       0,    41,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    14,   606,   212,   210,   221,
     211,   213,   214,   215,   216,   217,   218,   219,   220,   222,
     223,     0,   105,     0,     0,    12,   258,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,   510,
       0,     0,     0,   465,   637,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,    14,   487,     0,     0,   493,
      29,     0,     0,    89,   531,   548,   557,     0,   585,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   143,
     140,   141,   142,   144,   145,    19,     0,     0,   148,   149,
     150,    21,     0,   153,   154,    23,   155,   544,   171,   573,
       0,     0,     0,     0,    38,    36,    37,     0,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,   579,   582,     0,     0,    12,     0,   255,     0,   523,
     524,   525,   526,   527,     0,   570,   418,     0,     0,     0,
       0,   472,   608,     0,     0,   405,    14,   484,     0,     0,
       0,     0,   490,   491,   492,     0,     0,   584,   636,     0,
       0,   137,     0,     0,   536,   169,   633,   146,   545,   151,
      24,    34,   518,   519,   521,     0,   163,   206,   224,   328,
     403,   414,   189,   406,   416,     0,    15,   228,     0,     0,
     106,   255,     0,    13,   254,     0,   528,     0,     0,   439,
     453,     0,     0,   639,     0,   485,   488,   641,   643,     0,
       0,   108,   169,     0,   534,     0,   168,   170,     0,    40,
     331,     0,    12,   104,     0,     0,   256,     0,     0,     0,
     419,   420,   421,   425,     0,     0,   408,     0,     0,    62,
     549,     0,     0,     0,   572,     0,    25,     0,     0,     0,
       0,     0,   547,     0,     0,     0,     0,     0,    26,   231,
     234,   242,   229,   252,   230,   232,   233,   235,   236,   237,
     238,   239,   240,   241,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   102,     0,     0,    12,    26,    26,   417,
       0,     0,     0,     0,     0,     0,     0,   441,   440,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,     0,
       0,   457,   454,   455,   456,   458,   459,   460,   461,   462,
     463,   464,     0,     0,   483,     0,     0,     0,     0,   575,
     110,   111,   109,   116,   123,   126,   136,   112,   113,   114,
     115,   117,   118,   119,   120,   121,   122,   124,   125,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
      39,     0,     0,     0,     0,     0,   332,   333,   334,   335,
     336,   337,   338,   339,    84,    26,   227,   520,   529,   556,
     561,   571,   601,   607,   503,     0,     0,   103,   253,    12,
     261,     0,     0,     0,   426,   427,   428,   429,   430,   431,
     432,   433,     0,   438,   559,     0,   594,   634,   452,     0,
     409,   410,   411,   412,   413,     0,     0,     0,    64,    63,
      72,    65,    66,    67,    68,    69,    70,    71,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,    26,
       0,   107,   535,   167,     0,   330,   538,   578,     0,   586,
       0,     0,   532,     0,   261,   260,     0,     0,   424,     0,
     562,   407,     0,    61,    26,     0,    26,   533,   581,     0,
       0,     0,   624,    85,    86,    87,    88,     0,   101,     0,
     262,   422,   423,     0,   625,     0,     0,     0,    83,   580,
     610,   502,     0,     0,     0,   226,     0,   259,     0,   165,
     504,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    45,    54,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    60,    16,    43,   522,
     540,     0,     0,   583,     0,     0,     0,     0,    17,   563,
     564,   166
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -926,    -1,  -211,  -174,  -743,  -637,  -926,  -926,  -926,  -926,
    -926,  -304,  -926,  -926,  -926,  -178,  -926,  -926,  -926,  -926,
      51,  -926,  -926,  -926,  -926,  -926,    60,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,    81,  -926,
    -926,  -926,  -926,  -926,  -926,  -822,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,   110,   278,  -926,  -151,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,   930,  -926,  -926,  -926,   787,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -485,   827,   829,
     832,   834,   839,   840,   842,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -764,  -861,  -520,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -120,  -926,  -925,  -579,  -529,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -528,  -926,    65,  -926,    73,  -860,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -863,  -926,  -926,
    -926,   -16,  -926,   -40,  -926,  -769,  -926,  -926,  -527,  -926,
    -526,  -524,  -923,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
      69,  -926,  -926,  -926,  -926,  -926,  -926,  -858,  -926,  -926,
    -866,    90,  -820,   337,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
    -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -926,  -856,
    -926,  -521,    -8,  -926,  -926,  -926,  -926,  -926,  -926,  -926,
     821
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   836,   843,   508,   777,   772,  1184,   502,   503,   369,
     868,   521,   497,     2,     3,   381,   640,   754,   382,   758,
     947,  1153,  1162,    53,   975,  1069,   910,  1100,  1123,    54,
     499,   615,   840,  1036,   222,   774,    55,   891,   982,    56,
     625,   728,    57,   627,   738,    58,   629,   743,    59,   509,
     633,    60,   114,   141,   383,   983,  1163,   729,   866,    61,
     511,   637,    62,   178,   384,   397,    63,   179,   398,    22,
      34,    40,   385,    64,   533,   658,   386,   985,    65,   871,
     912,   223,   844,   678,   224,  1105,    66,   147,   194,    67,
     148,   225,    23,    32,    36,    43,    68,   387,   659,   897,
    1016,    13,    24,    25,    69,   149,   288,   388,   354,   400,
     594,   972,  1060,   389,   401,    70,   847,   880,   881,   882,
      71,   940,  1044,    72,   488,   586,    73,   884,   948,    74,
     885,   962,    75,   491,   595,    76,   599,   699,    77,   157,
     355,   706,   162,   707,   163,   708,   802,   164,    78,   131,
     165,   913,   986,    79,    14,     4,   226,   587,   195,   196,
     197,   198,   199,   200,   201,   755,   756,   915,   759,  1164,
     296,   297,   298,   299,   300,   301,   916,   202,   617,  1037,
     730,   731,   990,   732,   597,  1017,   227,  1166,   228,   229,
     203,   634,   740,   204,   918,   618,   302,   303,   304,   305,
     306,   230,   920,   619,   231,   952,   232,   922,   953,  1169,
    1170,   307,   308,   309,   310,   311,   312,   923,   867,   638,
     390,   997,   313,   876,  1020,   665,  1124,  1021,   666,  1172,
     621,   622,  1022,   314,   315,   316,   317,   318,   233,   319,
     956,   320,   321,   322,   323,   324,   234,   929,    48,    41,
     356,   669,   931,   700,   325,  1125,   326,   327,   328,   329,
     330,   331,   403,   205,   332,   333,   334,   335,   336,  1126,
     701,   337,   338,   339,   340,   341,   342,   343,   734,   958,
     235,   623,   598,   236,   702,   237,   803,   166,   804,   167,
      42
  };

  const short
  A2lParser::yytable_[] =
  {
       9,   396,   430,    80,   662,   663,   596,   667,    15,   668,
     917,    17,   670,   661,   616,  1046,    19,  1049,   158,   159,
     934,   954,   968,   950,   965,  1004,   957,   971,   996,   676,
     988,   995,   841,  1003,  1019,  1006,   799,  1018,    47,  1023,
     704,   590,   591,   648,  1119,   512,   512,   736,   660,   911,
    1073,  1059,  1082,   635,   512,   585,   721,   722,    37,  1043,
     512,  1052,  1142,  1024,   585,   351,   352,    38,   797,   984,
     512,  1005,   523,   524,   525,   526,   527,  1048,    26,  1045,
    1047,   512,  1050,     1,  1051,   427,   428,   429,    49,    50,
     532,    10,   712,   712,   418,    27,   592,   631,  1088,   190,
      51,   712,   925,   723,   724,   584,    16,   712,   725,  1084,
     632,   737,  1077,   140,  1071,  1076,   969,  1083,   585,  1086,
     949,   964,   528,    52,  1035,   192,    18,   987,   712,   933,
     528,   168,   169,   603,   742,   604,   528,   174,   391,   402,
     944,   177,   512,    20,  1089,   695,   528,    21,   636,   726,
     905,   346,  1120,  1070,   349,  1085,    52,    30,   654,   854,
     632,   769,    11,   655,    31,    52,   419,   420,   364,   365,
      33,   367,   368,    12,    35,   370,   371,   677,   703,   404,
     648,  1015,   407,   408,   409,   410,   411,   412,   413,   600,
     415,   601,    52,  1040,   518,  1121,   529,   632,   906,    39,
     392,   393,   760,  1062,   648,  1177,   696,   422,   353,  1122,
     642,   643,   644,   645,   646,   647,   434,   895,    44,   160,
     896,   161,    45,   593,   649,   650,   651,   530,  1167,  1025,
    1173,   727,   593,   106,   946,   800,   705,   801,  1090,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   750,   751,  1175,   120,   761,
    1171,   648,  1165,  1168,   696,  1174,  1104,  1176,   394,   107,
     959,   960,    21,    28,    52,   951,   966,   108,   752,   753,
     109,   697,   991,   583,   585,   588,     6,     7,     8,   652,
     653,   614,   121,   762,   605,   648,   624,   110,   626,   628,
     838,   839,   749,   585,   630,   878,   879,   698,   901,   937,
     938,   190,   919,   921,   926,   927,   379,   928,   111,   763,
     932,   648,   898,   899,   764,   657,   648,   955,   970,   395,
     671,   608,   992,   993,   999,  1000,   585,  1001,   902,   510,
    1007,   989,   112,   372,   373,   357,   358,   359,   900,   113,
     765,   904,   648,   115,   606,   607,   914,   766,   609,   648,
     901,   116,   905,   190,   117,   118,   610,   139,   585,   716,
     963,     6,     7,     8,   534,  1187,   119,   175,   654,   504,
     505,   506,   507,   655,    46,   691,     6,     7,     8,   132,
     902,   609,   767,    52,   648,   122,   608,   654,   903,   610,
     123,   538,   655,   904,   611,   768,   374,   648,   512,  1011,
     906,   612,   124,   513,   905,  1063,  1074,  1075,   125,  1080,
     394,  1081,   735,   609,  1087,  1072,    52,   126,   127,   620,
     654,   610,   128,   656,   888,   655,   133,   611,     6,     7,
       8,   639,   375,  1106,   612,   648,   129,    52,   376,   514,
       5,     6,     7,     8,   377,   582,   793,  1061,    52,   589,
     130,   170,   906,   664,   134,  1012,   656,   773,   135,   611,
     613,   907,   504,   505,   506,   507,   612,   739,   808,   744,
     378,   427,   428,   429,   136,   137,   788,   789,   138,   379,
     944,   515,   142,  1107,   794,   648,   171,   516,   206,   207,
     905,   143,   172,   613,   672,   673,   144,   675,    38,   145,
    1127,   208,   648,   173,  1013,   684,   809,   146,  1014,   812,
     813,   380,  1136,   517,   648,   176,   182,   908,  1144,   180,
     648,  1015,   518,   818,  1146,   613,   648,   360,   150,   151,
     183,   184,   185,   186,   187,   188,   189,   152,   906,   153,
     154,   155,   852,   976,   977,   156,   209,   181,   210,   211,
     344,   345,   347,   348,   519,   350,   190,   361,   363,   837,
     362,   366,   405,   212,  1034,   406,   213,   414,   214,   416,
     717,   417,   421,   848,   849,   850,   423,   191,   424,   425,
     853,   901,   192,   426,   190,   608,   431,   432,   433,   439,
     435,   859,   978,  1041,  1042,   861,   436,   437,   863,   864,
     438,   887,   486,   487,   489,   215,   216,   490,   492,   493,
     495,   902,   609,   494,   496,   498,   500,   217,   501,   520,
     610,   522,   943,   941,   942,   944,   531,   218,   535,   536,
     537,   541,   775,   539,   883,   905,   973,   540,   542,   543,
     544,   394,   545,   546,   979,   889,   787,    52,   547,   893,
     548,   549,   550,   909,   551,   552,   655,   553,   611,   554,
     555,   901,   556,   557,   190,   612,  1154,  1155,   219,   602,
     805,   220,   558,   980,   945,   193,   807,   559,   560,  1009,
     561,  1101,   221,   906,   562,   563,   353,   564,   565,   566,
     567,   902,   907,   568,   569,   570,   571,  1156,   572,   573,
     574,   575,   943,   576,   577,   944,   578,   190,   579,   580,
     581,   692,   641,   648,   679,   905,   674,   680,   681,   946,
     682,   683,  1065,   685,   613,  1157,   686,   687,   688,   689,
    1055,   690,  1057,   192,   694,   710,   655,   709,   693,   711,
     714,   715,   713,   718,   719,  1115,   720,   757,   944,  1158,
    1159,   741,   745,   746,   945,   747,   748,  1068,   905,   771,
     770,   778,   779,   906,   780,   781,  1066,  1067,   782,   791,
    1135,   783,  1137,   784,   785,   786,   790,   792,   795,   796,
    1160,   798,   806,   811,   814,   817,   815,   810,   816,  1015,
     822,   924,   820,   823,   870,  1094,   824,   819,   821,   946,
    1098,   825,   835,   831,   877,   826,   906,   190,   608,   353,
     886,   998,   833,   829,  1112,   828,   830,   834,   827,   832,
     842,   845,   846,   851,   857,   858,   860,   855,   862,   865,
     856,   869,   873,   192,   935,   609,   936,   872,   875,   939,
     894,  1110,   946,   610,   890,    52,   974,  1008,   944,  1031,
    1033,  1010,  1032,  1054,  1024,  1091,  1052,  1053,   905,  1027,
    1028,  1134,  1029,  1030,   394,  1026,  1092,   979,  1058,  1038,
      52,  1093,  1096,  1097,  1099,  1103,  1102,  1114,  1109,  1113,
    1117,   611,  1116,  1095,  1118,  1128,  1133,  1143,   612,  1015,
    1138,  1178,  1179,  1111,  1039,  1079,  1108,  1149,  1180,  1191,
    1145,  1147,   981,   892,  1056,   961,   906,    81,  1132,   353,
    1131,   874,   776,  1129,    29,   907,   994,    82,   967,  1078,
    1002,   930,   733,    83,  1064,     0,   399,    84,    85,   238,
      86,    87,  1141,    88,  1151,  1161,   289,  1152,   290,     0,
       0,   291,   946,   292,  1181,  1182,  1183,   613,   293,   294,
       0,   295,  1150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1185,  1186,     0,
    1188,     0,    89,     0,    90,     0,     0,    91,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,   239,     0,  1130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,     0,     0,  1130,
       0,     0,     0,     0,   240,   241,   242,   243,   244,   245,
       0,    97,     0,     0,    98,    99,   100,   101,   102,   103,
       0,     0,   104,     0,     0,     0,     0,     0,     0,  1139,
    1140,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,  1148,     0,     0,     0,     0,     0,   251,   252,
     253,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1189,  1190,   258,   259,   260,   261,
     262,     0,   263,     0,   264,   265,   266,   267,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,   270,   271,   272,   273,   274,
     275,     0,     0,   276,   277,   278,   279,   280,     0,     0,
     281,   282,   283,   284,   285,   286,   287
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,   179,   213,    43,   533,   533,   491,   533,     9,   533,
     871,    12,   533,   533,   499,   940,    17,   940,     3,     4,
       4,   884,   885,   884,   885,   891,   884,   885,   891,     6,
     891,   891,   775,   891,   897,   891,     4,   897,    39,   897,
       3,     3,     4,     6,     4,    25,    25,     4,   533,   871,
     975,     4,   975,     4,    25,    17,     3,     4,     4,     4,
      25,    32,     4,    42,    17,     3,     4,    13,   705,   891,
      25,   891,   376,   377,   378,   379,   380,   940,   105,   940,
     940,    25,   940,    12,   940,     8,     9,    10,     3,     4,
     394,     0,    72,    72,    48,   122,    58,     4,    69,    44,
      15,    72,   871,    50,    51,     4,   144,    72,    55,   975,
      67,    68,   975,   114,   975,   975,   885,   975,    17,   975,
     884,   885,   101,   107,    47,    70,     6,   891,    72,   872,
     101,   132,   133,     4,     4,     6,   101,   138,   178,   179,
      85,   142,    25,     7,   115,     4,   101,     3,    99,    96,
      95,   152,   112,   975,   155,   975,   107,     7,   111,   796,
      67,   141,     3,   116,     6,   107,   120,   121,   169,   170,
     144,   172,   173,    14,     7,   176,   177,   154,     4,   180,
       6,   126,   183,   184,   185,   186,   187,   188,   189,   493,
     191,   495,   107,   936,   149,   155,   151,    67,   143,   145,
       3,     4,     4,   972,     6,    88,   153,   208,   146,   169,
     514,   515,   516,   517,   518,   519,   217,     4,   105,   204,
       7,   206,     7,   185,   528,   529,   530,   182,  1153,   208,
    1153,   178,   185,   122,   179,   203,   199,   205,   209,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     3,     4,  1153,     7,     4,
    1153,     6,  1153,  1153,   153,  1153,  1039,  1153,   101,     6,
       3,     4,     3,     4,   107,   884,   885,     6,    26,    27,
       6,   170,   891,   487,    17,   489,     8,     9,    10,     3,
       4,   499,     7,     4,   498,     6,   500,     6,   502,   503,
       3,     4,   636,    17,   508,     3,     4,   196,    41,   188,
     189,    44,   871,   871,   871,   871,   149,   871,     6,     4,
     871,     6,     3,     4,     4,   533,     6,   884,   885,   162,
     534,    45,   891,   891,   891,   891,    17,   891,    71,   370,
     891,   891,     6,     3,     4,   200,   201,   202,    29,     6,
       4,    84,     6,     6,     3,     4,   871,     4,    72,     6,
      41,     6,    95,    44,     6,     6,    80,     4,    17,   610,
     885,     8,     9,    10,   405,     4,     6,    59,   111,     8,
       9,    10,    11,   116,     6,   589,     8,     9,    10,     7,
      71,    72,     4,   107,     6,     6,    45,   111,    79,    80,
       6,   432,   116,    84,   118,     4,    66,     6,    25,     4,
     143,   125,     6,    30,    95,   972,   975,   975,     6,   975,
     101,   975,   626,    72,   975,   975,   107,     6,     6,   499,
     111,    80,     6,   147,     4,   116,     7,   118,     8,     9,
      10,   511,   102,     4,   125,     6,     6,   107,   108,    66,
       7,     8,     9,    10,   114,   486,   697,   972,   107,   490,
       6,     6,   143,   533,     7,    60,   147,   671,     7,   118,
     184,   152,     8,     9,    10,    11,   125,   627,   719,   629,
     140,     8,     9,    10,     7,     7,   690,   691,     7,   149,
      85,   108,     7,     4,   698,     6,     6,   114,     3,     4,
      95,     7,     6,   184,   535,   536,     7,   538,    13,     7,
       4,    16,     6,     6,   109,   546,   720,     7,   113,   723,
     724,   181,     4,   140,     6,     6,     4,   208,     4,     6,
       6,   126,   149,   737,     4,   184,     6,   207,     7,     7,
      18,    19,    20,    21,    22,    23,    24,     7,   143,     7,
       7,     7,   793,     3,     4,     7,    61,     6,    63,    64,
       7,     6,     6,     6,   181,     7,    44,     6,     6,   773,
       7,     7,     6,    78,   908,   123,    81,     6,    83,     6,
     611,     6,   124,   787,   788,   789,     7,    65,     7,     7,
     794,    41,    70,     7,    44,    45,     7,     6,     6,   148,
       7,   805,    52,   937,   938,   809,     7,     7,   812,   813,
       7,   852,     7,     6,     6,   120,   121,     6,     6,   150,
       6,    71,    72,   198,     6,     6,     6,   132,     7,   100,
      80,     7,    82,     3,     4,    85,   103,   142,     7,     6,
       6,     6,   673,     7,   848,    95,   887,     7,     6,     6,
       6,   101,     6,     6,   104,   859,   687,   107,     6,   863,
       6,     6,     6,   871,     6,     6,   116,     6,   118,     6,
       6,    41,     6,     6,    44,   125,     3,     4,   183,     7,
     711,   186,     6,   891,   134,   163,   717,     6,     6,   893,
       6,  1025,   197,   143,     6,     6,   146,     6,     6,     6,
       6,    71,   152,     6,     6,     6,     6,    34,     6,     6,
       6,     6,    82,     6,     6,    85,     6,    44,     6,     6,
       6,   180,     7,     6,     6,    95,     7,     6,     6,   179,
       6,     6,   973,     6,   184,    62,     6,     6,   191,     6,
     944,     6,   946,    70,     7,     6,   116,   202,   194,     6,
       6,     6,    43,     7,     7,  1089,     6,    31,    85,    86,
      87,     7,     7,    57,   134,     7,    98,   975,    95,     6,
     110,     6,     6,   143,     6,     6,     3,     4,     6,   195,
    1114,     6,  1116,     6,     6,     6,     6,     6,   150,   199,
     117,     4,     6,    53,     6,    54,     7,    96,     6,   126,
       7,   871,    28,     7,   835,  1009,     6,    56,    25,   179,
    1014,     4,     6,   181,   845,    66,   143,    44,    45,   146,
     851,   891,   151,   140,  1065,   114,   149,   182,   108,   101,
       6,     6,     6,     6,     6,     6,     4,   200,     7,    97,
     201,    30,    48,    70,   875,    72,   877,    46,     6,   187,
       7,  1055,   179,    80,    72,   107,   199,     4,    85,     7,
       6,    28,     7,     6,    42,    49,    32,   192,    95,   900,
     901,  1112,   903,   904,   101,   119,     6,   104,   193,   120,
     107,    96,     6,     6,     6,     4,     7,     7,     6,    33,
    1094,   118,     7,   141,  1098,    46,     6,     6,   125,   126,
      42,    32,     6,   180,   935,   975,   190,    69,     6,    88,
     115,   121,   891,   862,   945,   885,   143,    33,   189,   146,
     188,   841,   674,  1104,    24,   152,   891,    43,   885,   975,
     891,   871,   625,    49,   972,    -1,   179,    53,    54,   148,
      56,    57,   208,    59,  1148,  1153,   149,  1151,   149,    -1,
      -1,   149,   179,   149,  1158,  1159,  1160,   184,   149,   149,
      -1,   149,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1181,  1182,    -1,
    1184,    -1,    98,    -1,   100,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,     4,    -1,  1105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,  1129,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,   187,    -1,    -1,   190,   191,   192,   193,   194,   195,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,  1120,
    1121,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,  1143,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1185,  1186,   127,   128,   129,   130,
     131,    -1,   133,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,   157,   158,   159,   160,
     161,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,   172,   173,   174,   175,   176,   177
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   223,   224,   365,     7,     8,     9,    10,   211,
       0,     3,    14,   311,   364,   211,   144,   211,     6,   211,
       7,     3,   279,   302,   312,   313,   105,   122,     4,   313,
       7,     6,   303,   144,   280,     7,   304,     4,    13,   145,
     281,   459,   500,   305,   105,     7,     6,   211,   458,     3,
       4,    15,   107,   233,   239,   246,   249,   252,   255,   258,
     261,   269,   272,   276,   283,   288,   296,   299,   306,   314,
     325,   330,   333,   336,   339,   342,   345,   348,   358,   363,
     433,    33,    43,    49,    53,    54,    56,    57,    59,    98,
     100,   103,   110,   119,   123,   124,   148,   187,   190,   191,
     192,   193,   194,   195,   198,   207,   122,     6,     6,     6,
       6,     6,     6,     6,   262,     6,     6,     6,     6,     6,
       7,     7,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   359,     7,     7,     7,     7,     7,     7,     7,     4,
     211,   263,     7,     7,     7,     7,     7,   297,   300,   315,
       7,     7,     7,     7,     7,     7,     7,   349,     3,     4,
     204,   206,   352,   354,   357,   360,   497,   499,   211,   211,
       6,     6,     6,     6,   211,    59,     6,   211,   273,   277,
       6,     6,     4,    18,    19,    20,    21,    22,    23,    24,
      44,    65,    70,   163,   298,   368,   369,   370,   371,   372,
     373,   374,   387,   400,   403,   473,     3,     4,    16,    61,
      63,    64,    78,    81,    83,   120,   121,   132,   142,   183,
     186,   197,   244,   291,   294,   301,   366,   396,   398,   399,
     411,   414,   416,   448,   456,   490,   493,   495,   500,     4,
      35,    36,    37,    38,    39,    40,    73,    74,    75,    76,
      77,    89,    90,    91,    92,    93,    94,   106,   127,   128,
     129,   130,   131,   133,   135,   136,   137,   138,   139,   154,
     156,   157,   158,   159,   160,   161,   164,   165,   166,   167,
     168,   171,   172,   173,   174,   175,   176,   177,   316,   368,
     369,   370,   371,   372,   373,   374,   380,   381,   382,   383,
     384,   385,   406,   407,   408,   409,   410,   421,   422,   423,
     424,   425,   426,   432,   443,   444,   445,   446,   447,   449,
     451,   452,   453,   454,   455,   464,   466,   467,   468,   469,
     470,   471,   474,   475,   476,   477,   478,   481,   482,   483,
     484,   485,   486,   487,     7,     6,   211,     6,     6,   211,
       7,     3,     4,   146,   318,   350,   460,   200,   201,   202,
     207,     6,     7,     6,   211,   211,     7,   211,   211,   219,
     211,   211,     3,     4,    66,   102,   108,   114,   140,   149,
     181,   225,   228,   264,   274,   282,   286,   307,   317,   323,
     430,   433,     3,     4,   101,   162,   225,   275,   278,   317,
     319,   324,   433,   472,   211,     6,   123,   211,   211,   211,
     211,   211,   211,   211,     6,   211,     6,     6,    48,   120,
     121,   124,   211,     7,     7,     7,     7,     8,     9,    10,
     212,     7,     6,     6,   211,     7,     7,     7,     7,   148,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,     7,     6,   334,     6,
       6,   343,     6,   150,   198,     6,     6,   222,     6,   240,
       6,     7,   217,   218,     8,     9,    10,    11,   213,   259,
     211,   270,    25,    30,    66,   108,   114,   140,   149,   181,
     100,   221,     7,   221,   221,   221,   221,   221,   101,   151,
     182,   103,   221,   284,   211,     7,     6,     6,   211,     7,
       7,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,   211,   213,     4,    17,   335,   367,   213,   211,
       3,     4,    58,   185,   320,   344,   367,   394,   492,   346,
     221,   221,     7,     4,     6,   213,     3,     4,    45,    72,
      80,   118,   125,   184,   225,   241,   367,   388,   405,   413,
     433,   440,   441,   491,   213,   250,   213,   253,   213,   256,
     213,     4,    67,   260,   401,     4,    99,   271,   429,   433,
     226,     7,   221,   221,   221,   221,   221,   221,     6,   221,
     221,   221,     3,     4,   111,   116,   147,   225,   285,   308,
     367,   388,   405,   413,   433,   435,   438,   440,   441,   461,
     491,   213,   211,   211,     7,   211,     6,   154,   293,     6,
       6,     6,     6,     6,   211,     6,     6,     6,   191,     6,
       6,   213,   180,   194,     7,     4,   153,   170,   196,   347,
     463,   480,   494,     4,     3,   199,   351,   353,   355,   202,
       6,     6,    72,    43,     6,     6,   212,   211,     7,     7,
       6,     3,     4,    50,    51,    55,    96,   178,   251,   267,
     390,   391,   393,   463,   488,   213,     4,    68,   254,   401,
     402,     7,     4,   257,   401,     7,    57,     7,    98,   221,
       3,     4,    26,    27,   227,   375,   376,    31,   229,   378,
       4,     4,     4,     4,     4,     4,     4,     4,     4,   141,
     110,     6,   215,   213,   245,   211,   293,   214,     6,     6,
       6,     6,     6,     6,     6,     6,     6,   211,   213,   213,
       6,   195,     6,   212,   213,   150,   199,   215,     4,     4,
     203,   205,   356,   496,   498,   211,     6,   211,   212,   213,
      96,    53,   213,   213,     6,     7,     6,    54,   213,    56,
      28,    25,     7,     7,     6,     4,    66,   108,   114,   140,
     149,   181,   101,   151,   182,     6,   211,   213,     3,     4,
     242,   214,     6,   212,   292,     6,     6,   326,   213,   213,
     213,     6,   212,   213,   215,   200,   201,     6,     6,   213,
       4,   213,     7,   213,   213,    97,   268,   428,   220,    30,
     211,   289,    46,    48,   292,     6,   433,   211,     3,     4,
     327,   328,   329,   213,   337,   340,   211,   212,     4,   213,
      72,   247,   268,   213,     7,     4,     7,   309,     3,     4,
      29,    41,    71,    79,    84,    95,   143,   152,   208,   225,
     236,   275,   290,   361,   367,   377,   386,   387,   404,   405,
     412,   413,   417,   427,   433,   435,   438,   440,   441,   457,
     461,   462,   491,   214,     4,   211,   211,   188,   189,   187,
     331,     3,     4,    82,    85,   134,   179,   230,   338,   386,
     387,   404,   415,   418,   427,   438,   450,   457,   489,     3,
       4,   236,   341,   367,   386,   387,   404,   417,   427,   435,
     438,   457,   321,   212,   199,   234,     3,     4,    52,   104,
     225,   230,   248,   265,   275,   287,   362,   386,   387,   388,
     392,   404,   405,   413,   415,   418,   427,   431,   433,   438,
     440,   441,   450,   457,   460,   462,   489,   491,     4,   213,
      28,     4,    60,   109,   113,   126,   310,   395,   418,   427,
     434,   437,   442,   457,    42,   208,   119,   211,   211,   211,
     211,     7,     7,     6,   221,    47,   243,   389,   120,   211,
     214,   221,   221,     4,   332,   387,   403,   418,   427,   442,
     457,   489,    32,   192,     6,   213,   211,   213,   193,     4,
     322,   367,   435,   438,   492,   212,     3,     4,   225,   235,
     275,   387,   388,   403,   405,   413,   418,   427,   431,   433,
     440,   441,   442,   457,   460,   462,   489,   491,    69,   115,
     209,    49,     6,    96,   213,   141,     6,     6,   213,     6,
     237,   221,     7,     4,   214,   295,     4,     4,   190,     6,
     213,   180,   212,    33,     7,   221,     7,   213,   213,     4,
     112,   155,   169,   238,   436,   465,   479,     4,    46,   295,
     433,   188,   189,     6,   212,   221,     4,   221,    42,   211,
     211,   208,     4,     6,     4,   115,     4,   121,   211,    69,
     209,   213,   213,   231,     3,     4,    34,    62,    86,    87,
     117,   225,   232,   266,   379,   387,   397,   403,   418,   419,
     420,   427,   439,   442,   457,   460,   489,    88,    32,     6,
       6,   213,   213,   213,   216,   213,   213,     4,   213,   211,
     211,    88
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   210,   211,   211,   211,   212,   212,   212,   213,   213,
     213,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   224,   224,   224,   225,   226,   226,   226,   226,   227,
     228,   229,   229,   230,   231,   231,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   233,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   236,   237,   237,   238,   238,   238,   239,
     240,   240,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   242,   243,   243,   244,   245,   245,   246,   247,   247,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   252,   253,   253,   254,
     254,   255,   256,   256,   257,   258,   259,   259,   260,   261,
     262,   262,   263,   264,   264,   265,   266,   267,   267,   268,
     268,   269,   270,   270,   271,   271,   272,   273,   273,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   275,
     275,   276,   277,   277,   278,   278,   278,   278,   278,   278,
     278,   279,   280,   280,   281,   281,   282,   282,   283,   284,
     284,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   286,   286,   287,   288,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   296,   297,   297,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   299,   300,   300,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   302,   303,   304,   305,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
     308,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     311,   312,   312,   313,   313,   314,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   317,   317,   318,   319,   320,   321,   321,
     322,   322,   322,   322,   323,   323,   324,   325,   326,   326,
     327,   327,   328,   329,   330,   331,   331,   332,   332,   332,
     332,   332,   332,   332,   333,   334,   334,   335,   336,   337,
     337,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   339,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   342,   343,   343,   344,   344,
     344,   344,   345,   346,   346,   347,   347,   347,   348,   349,
     349,   350,   350,   351,   351,   352,   353,   353,   354,   355,
     355,   356,   356,   357,   358,   359,   359,   360,   360,   360,
     360,   360,   361,   361,   362,   363,   364,   365,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     2,     0,     2,     0,     3,
       0,     3,     0,     4,     0,     2,     0,     2,     0,     3,
       2,     0,     1,     2,     5,     0,     2,     2,     2,     5,
       6,     0,     1,    11,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    15,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     0,     2,     1,     1,     1,     9,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     0,     1,     7,     0,     2,    14,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,    10,     0,     2,
       1,     1,     1,     1,     1,     1,    10,     0,     2,     1,
       1,    10,     0,     2,     1,     9,     0,     2,     1,     5,
       0,     2,     4,     5,     2,     6,     5,     6,     3,     0,
       1,     9,     0,     2,     1,     1,     7,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       2,     7,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     6,     0,     2,     1,     1,     5,     2,     9,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     2,     5,    13,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,     6,     0,     2,     1,     1,    13,
      10,     0,     2,     6,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       7,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       7,     1,     2,     1,     1,     6,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     5,     5,     8,     0,     2,
       1,     1,     1,     1,     5,     2,     5,    12,     0,     2,
       1,     1,     5,     5,    14,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     8,     0,     2,     1,    13,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    13,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     0,     2,     1,     1,
       1,     1,     9,     0,     2,     1,     1,     1,     6,     0,
       2,     1,     1,     5,     2,     7,     0,     1,     7,     0,
       2,     1,     1,     5,     5,     0,     2,     1,     1,     1,
       1,     1,     5,     2,     6,     1,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     5,     5,     5,     5,     5,     6,     2,
       2,     2,     2,     7,     3,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     5,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     3,     4,     4,     2,     2,     2,     2,     2,
       5,     2,     2,     2,     2,     1,     3,     1,     2,     2,
       2,     3,     2,     2,     3,     2,     2,     3,     3,     3,
       3,     3,     2,     3,     2,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     2,     1,     1,     2,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     1,     2,     3,
       3,     3,     3,     3,     1,     8,     3,     3,     3,     3,
       3,     1,     1,     2,     2,     2,     3,     2,     3,     3,
       2,     2,     2,     2,     2,     2
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
       0,   435,   435,   436,   437,   439,   440,   441,   443,   444,
     445,   446,   448,   449,   451,   452,   454,   455,   457,   458,
     463,   464,   469,   470,   475,   476,   481,   482,   487,   488,
     493,   495,   496,   497,   499,   500,   501,   502,   503,   505,
     507,   512,   513,   515,   526,   527,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   545,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   581,   586,   587,   588,   589,   590,   592,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   611,   615,   616,   618,   624,   625,   630,   643,   644,
     645,   646,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   675,   684,   685,
     686,   687,   688,   689,   694,   695,   697,   706,   707,   709,
     710,   712,   721,   722,   723,   725,   733,   734,   735,   737,
     739,   740,   742,   752,   755,   759,   762,   764,   767,   770,
     771,   773,   780,   781,   782,   783,   785,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   803,
     804,   806,   812,   813,   814,   815,   816,   817,   818,   819,
     820,   822,   827,   828,   830,   833,   838,   841,   845,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   866,   867,   869,   872,   876,   878,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   916,   924,   932,   933,   938,   939,   941,
     953,   964,   965,   969,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   988,   996,   997,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1015,  1021,  1026,  1031,
    1032,  1033,  1034,  1037,  1040,  1043,  1046,  1049,  1052,  1055,
    1056,  1059,  1062,  1065,  1068,  1071,  1074,  1075,  1076,  1079,
    1082,  1085,  1088,  1091,  1094,  1097,  1100,  1103,  1105,  1108,
    1112,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1127,  1128,
    1130,  1136,  1137,  1139,  1140,  1145,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1207,  1210,  1213,  1214,  1216,  1223,  1224,
    1225,  1226,  1227,  1228,  1230,  1233,  1237,  1239,  1250,  1251,
    1252,  1253,  1255,  1256,  1258,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1281,  1287,  1288,  1289,  1291,  1303,
    1304,  1305,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1320,  1332,  1333,  1334,  1335,  1336,  1337,  1338,
    1339,  1340,  1341,  1342,  1343,  1345,  1352,  1353,  1354,  1355,
    1356,  1359,  1361,  1368,  1369,  1370,  1371,  1372,  1377,  1381,
    1382,  1383,  1384,  1386,  1389,  1393,  1399,  1400,  1402,  1409,
    1410,  1411,  1412,  1414,  1416,  1417,  1418,  1419,  1423,  1427,
    1431,  1435,  1440,  1443,  1446,  1450,  1451,  1456,  1459,  1463,
    1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,
    1474,  1475,  1476,  1477,  1483,  1489,  1495,  1501,  1507,  1514,
    1515,  1516,  1517,  1518,  1528,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1553,  1557,  1561,  1565,  1569,  1570,  1571,  1572,  1573,
    1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1590,  1591,  1592,  1593,  1594,  1595,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1613,  1617,
    1621,  1625,  1629,  1630,  1634,  1635,  1639,  1643,  1647,  1651,
    1655,  1656,  1657,  1658,  1659,  1661,  1662,  1663,  1664,  1665,
    1669,  1670,  1674,  1678,  1682,  1686,  1690,  1694,  1695,  1696,
    1700,  1704,  1708,  1712,  1716,  1717,  1726,  1730,  1734,  1738,
    1742,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,
    1755,  1756,  1757,  1758,  1759,  1760
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
#line 8098 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1762 "D:/projects/a2llib/src/a2lparser.y"


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
