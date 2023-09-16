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
#line 26 "D:/projects/a2llib/src/a2lparser.y"
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.copy< std::vector<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.copy< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::vector<int64_t> > (YY_MOVE (that.value));
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
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (YY_MOVE (that.value));
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::vector<A2lCalibrationHandle> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::vector<double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (YY_MOVE (s.value));
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
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (s.value));
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.YY_MOVE_OR_COPY< std::vector<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.YY_MOVE_OR_COPY< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.YY_MOVE_OR_COPY< std::vector<int64_t> > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.YY_MOVE_OR_COPY< std::vector<uint64_t> > (YY_MOVE (that.value));
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::vector<A2lCalibrationHandle> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (YY_MOVE (that.value));
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
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (that.value));
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.copy< std::vector<A2lCalibrationHandle> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.copy< std::vector<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::vector<int64_t> > (that.value);
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
        value.copy< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (that.value);
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::vector<A2lCalibrationHandle> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::vector<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (that.value);
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
        value.move< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (that.value);
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
      case symbol_kind::S_limits: // limits
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
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
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

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        yylhs.value.emplace< std::vector<A2lCalibrationHandle> > ();
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        yylhs.value.emplace< std::vector<double> > ();
        break;

      case symbol_kind::S_int_list: // int_list
        yylhs.value.emplace< std::vector<int64_t> > ();
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
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        yylhs.value.emplace< std::vector<uint64_t> > ();
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
#line 432 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2801 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 433 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2807 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_int: INT
#line 435 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2813 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: UINT
#line 436 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2819 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: HEX
#line 437 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2825 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_float: FLOAT
#line 439 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2831 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: INT
#line 440 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2837 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: UINT
#line 441 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2843 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: HEX
#line 442 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2849 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // int_list: %empty
#line 444 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: int_list any_int
#line 445 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::vector<int64_t> > () = yystack_[1].value.as < std::vector<int64_t> > (); yylhs.value.as < std::vector<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); }
#line 2861 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // uint_list: %empty
#line 447 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: uint_list any_uint
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                       {yylhs.value.as < std::vector<uint64_t> > () = yystack_[1].value.as < std::vector<uint64_t> > (); yylhs.value.as < std::vector<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 2873 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // float_list: %empty
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: float_list any_float
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < std::vector<double> > () = yystack_[1].value.as < std::vector<double> > (); yylhs.value.as < std::vector<double> > ().emplace_back(yystack_[0].value.as < double > ()); }
#line 2885 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_pair_list: %empty
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: float_pair_list any_float any_float
#line 454 "D:/projects/a2llib/src/a2lparser.y"
                                              {yylhs.value.as < std::map<double, double> > () = yystack_[2].value.as < std::map<double, double> > (); yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 2897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_string_list: %empty
#line 456 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: float_string_list any_float STRING
#line 457 "D:/projects/a2llib/src/a2lparser.y"
                                             {yylhs.value.as < std::map<double, std::string> > () = yystack_[2].value.as < std::map<double, std::string> > (); yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); }
#line 2909 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_range_list: %empty
#line 459 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: float_range_list any_float any_float STRING
#line 460 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ();
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ()); }
#line 2923 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // string_list: %empty
#line 464 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2929 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: string_list STRING
#line 465 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); }
#line 2935 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // ident_list: %empty
#line 467 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2941 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: ident_list IDENT
#line 468 "D:/projects/a2llib/src/a2lparser.y"
                           {yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); }
#line 2947 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // key_value_list: %empty
#line 470 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 2953 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: key_value_list IDENT IDENT
#line 471 "D:/projects/a2llib/src/a2lparser.y"
                                     {yylhs.value.as < std::map<std::string, std::string> > () = yystack_[2].value.as < std::map<std::string, std::string> > (); yylhs.value.as < std::map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); }
#line 2959 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 32: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 478 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = yystack_[2].value.as < A2lAnnotation > ();}
#line 2965 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // annotation_attributes: %empty
#line 479 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 2971 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation_attributes: annotation_attributes annotation_label
#line 480 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Label = yystack_[0].value.as < std::string > ();}
#line 2977 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: annotation_attributes annotation_origin
#line 481 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Origin = yystack_[0].value.as < std::string > ();}
#line 2983 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_text
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Text = yystack_[0].value.as < std::vector<std::string> > ();}
#line 2989 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 484 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2995 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 38: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 39: // ar_component_attribute: %empty
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 40: // ar_component_attribute: ar_prototype_of
#line 492 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3017 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 495 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3031 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 44: // axis_descr_attribute: annotation
#line 506 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3037 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // axis_descr_attribute: axis_pts_ref
#line 507 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3043 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: byte_order
#line 508 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3049 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: curve_axis_ref
#line 509 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3055 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: deposit
#line 510 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3061 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: extended_limits
#line 511 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3067 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: fix_axis_par
#line 512 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3073 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: fix_axis_par_dist
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3079 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par_list
#line 514 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::vector<double> > ()); }
#line 3085 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: format
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: max_grad
#line 516 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: monotony
#line 517 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: phys_unit
#line 518 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: read_only
#line 519 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: step_size
#line 520 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 523 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 62: // axis_pts_attribute: annotation
#line 538 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_pts_attribute: byte_order
#line 539 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: calibration_access
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3157 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: deposit
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3163 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: display_identifier
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: ecu_address_extension
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3175 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: extended_limits
#line 544 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3181 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: format
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3187 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: function_list
#line 546 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: guard_rails
#line 547 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: if_data
#line 548 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: max_refresh
#line 549 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3211 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: model_link
#line 550 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3217 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: monotony
#line 551 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3223 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: phys_unit
#line 552 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3229 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: read_only
#line 553 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3235 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: ref_memory_segment
#line 554 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3241 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: step_size
#line 555 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3247 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: symbol_link
#line 556 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3253 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 558 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3263 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 84: // bit_operation_attribute: left_shift
#line 565 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // bit_operation_attribute: right_shift
#line 566 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // bit_operation_attribute: sign_extend
#line 567 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 569 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 3293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 90: // blob_attribute: address_type
#line 578 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 91: // blob_attribute: annotation
#line 579 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: calibration_access
#line 580 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: display_identifier
#line 581 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: ecu_address_extension
#line 582 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: if_data
#line 583 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: max_refresh
#line 584 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: model_link
#line 585 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3341 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: symbol_link
#line 586 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3347 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = yystack_[3].value.as < std::vector<int64_t> > ();
	yylhs.value.as < A2lCalibrationHandle > ().Comment = yystack_[2].value.as < std::string > ();
}
#line 3356 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // calibration_handle_attribute: %empty
#line 592 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // calibration_handle_attribute: calibration_handle_text
#line 593 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 596 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = yystack_[4].value.as < std::string > ();
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = yystack_[2].value.as < std::vector<A2lCalibrationHandle> > ();
	}
#line 3378 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // calibration_method_attributes: %empty
#line 601 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3384 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 602 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
	yylhs.value.as < std::vector<A2lCalibrationHandle> > () = yystack_[1].value.as < std::vector<A2lCalibrationHandle> > ();
	yylhs.value.as < std::vector<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
	}
#line 3393 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 608 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3410 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 108: // characteristic_attribute: annotation
#line 622 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3416 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // characteristic_attribute: axis_descr
#line 623 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3424 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: bit_mask
#line 626 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3430 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: byte_order
#line 627 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3436 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: calibration_access
#line 628 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3442 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: comparison_quantity
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: dependent_characteristic
#line 630 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3454 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: discrete
#line 631 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3460 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: display_identifier
#line 632 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3466 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: ecu_address_extension
#line 633 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3472 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: encoding
#line 634 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3478 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: extended_limits
#line 635 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3484 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: format
#line 636 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3490 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: function_list
#line 637 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3496 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: guard_rails
#line 638 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3502 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: if_data
#line 639 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3508 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: map_list
#line 640 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3514 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: matrix_dim
#line 641 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 3520 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: max_refresh
#line 642 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3526 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: model_link
#line 643 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3532 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: number
#line 644 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3538 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: phys_unit
#line 645 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3544 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: read_only
#line 646 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3550 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: ref_memory_segment
#line 647 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3556 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: step_size
#line 648 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3562 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: symbol_link
#line 649 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3568 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: virtual_characteristic
#line 650 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3574 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 652 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 3587 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 138: // compu_method_attribute: coeffs
#line 663 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::vector<double> > ()); }
#line 3593 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // compu_method_attribute: coeffs_linear
#line 664 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::vector<double> > ()); }
#line 3599 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // compu_method_attribute: compu_tab_ref
#line 665 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3605 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // compu_method_attribute: formula
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // compu_method_attribute: ref_unit
#line 671 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // compu_method_attribute: status_string_ref
#line 672 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 675 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, double> > ());
	}
#line 3640 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 147: // compu_tab_attribute: default_value
#line 685 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3646 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_tab_attribute: default_value_numeric
#line 686 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3652 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 689 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, std::string> > ());
	}
#line 3665 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 152: // compu_vtab_attribute: default_value
#line 699 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3671 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 153: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 702 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 3683 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 156: // compu_vtab_range_attribute: default_value
#line 711 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3689 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 713 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3695 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 158: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 716 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 3701 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 159: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 718 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::vector<double> > () = yystack_[2].value.as < std::vector<double> > (); }
#line 3707 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 160: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 720 "D:/projects/a2llib/src/a2lparser.y"
                                                                    { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()}; }
#line 3713 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // formula_attribute: %empty
#line 721 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3719 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // formula_attribute: formula_inv
#line 722 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3725 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 163: // frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 724 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 3737 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 166: // frame_attribute: frame_measurement
#line 733 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3743 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 167: // frame_attribute: if_data
#line 734 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3749 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 168: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 736 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3759 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // function_attribute: annotation
#line 743 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3765 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // function_attribute: def_characteristic
#line 745 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3771 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // function_attribute: function_version
#line 746 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3777 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // function_attribute: if_data
#line 747 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3783 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // function_attribute: in_measurement
#line 748 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3789 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 177: // function_attribute: loc_measurement
#line 749 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3795 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 178: // function_attribute: out_measurement
#line 750 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3801 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 179: // function_attribute: ref_characteristic
#line 751 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3807 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 180: // function_attribute: sub_function
#line 752 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3813 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 754 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 3819 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // function_list: FUNCTION_LIST ident_list
#line 755 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 3825 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 757 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3835 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // group_attribute: annotation
#line 765 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 187: // group_attribute: function_list
#line 766 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // group_attribute: if_data
#line 767 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3853 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // group_attribute: ref_characteristic
#line 768 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3859 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // group_attribute: ref_measurement
#line 769 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3865 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // group_attribute: root
#line 770 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 3871 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 192: // group_attribute: sub_group
#line 771 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3877 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 773 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = yystack_[3].value.as < std::string > ();
}
#line 3886 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // header_attribute: project_no
#line 781 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 3895 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // header_attribute: version
#line 784 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 3904 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 789 "D:/projects/a2llib/src/a2lparser.y"
                                                                           { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3910 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 199: // instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 791 "D:/projects/a2llib/src/a2lparser.y"
                                                                                              {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 3922 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 202: // instance_attribute: address_type
#line 800 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3928 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // instance_attribute: annotation
#line 801 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3934 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // instance_attribute: calibration_access
#line 802 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3940 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // instance_attribute: display_identifier
#line 803 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3946 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // instance_attribute: ecu_address_extension
#line 804 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3952 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // instance_attribute: if_data
#line 805 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3958 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // instance_attribute: layout
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 3964 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 209: // instance_attribute: matrix_dim
#line 807 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 3970 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 210: // instance_attribute: max_refresh
#line 808 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3976 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // instance_attribute: model_link
#line 809 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3982 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // instance_attribute: overwrite
#line 810 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 3989 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // instance_attribute: read_write
#line 812 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 3995 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // instance_attribute: symbol_link
#line 813 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4001 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 815 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 4007 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 216: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 817 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 4013 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 820 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4029 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // measurement_attribute: address_type
#line 833 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4035 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // measurement_attribute: annotation
#line 834 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4041 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // measurement_attribute: array_size
#line 835 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4047 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // measurement_attribute: bit_mask
#line 836 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4053 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // measurement_attribute: bit_operation
#line 837 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // measurement_attribute: byte_order
#line 838 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4065 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // measurement_attribute: discrete
#line 839 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // measurement_attribute: display_identifier
#line 840 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4077 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 228: // measurement_attribute: ecu_address
#line 841 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // measurement_attribute: ecu_address_extension
#line 842 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4089 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // measurement_attribute: error_mask
#line 843 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4095 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // measurement_attribute: format
#line 844 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4101 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // measurement_attribute: function_list
#line 845 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 4107 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // measurement_attribute: if_data
#line 846 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4113 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement_attribute: layout
#line 847 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4119 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 235: // measurement_attribute: matrix_dim
#line 848 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 4125 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 236: // measurement_attribute: max_refresh
#line 849 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4131 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: model_link
#line 850 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4137 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: phys_unit
#line 851 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4143 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: read_write
#line 852 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4149 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: ref_memory_segment
#line 853 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4155 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: symbol_link
#line 854 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4161 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: virtual
#line 855 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 4167 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes A2L_END MEMORY_LAYOUT
#line 858 "D:/projects/a2llib/src/a2lparser.y"
                                                       {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = yystack_[3].value.as < std::vector<int64_t> > ();
	}
#line 4178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // memory_layout_attributes: %empty
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4184 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // memory_layout_attributes: memory_layout_attributes if_data
#line 865 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[1].value.as < std::map<std::string, std::string> > ();
        yylhs.value.as < std::map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        }
#line 4193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // prg_type: RESERVED
#line 870 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // prg_type: IDENT
#line 871 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes A2L_END MEMORY_SEGMENT
#line 874 "D:/projects/a2llib/src/a2lparser.y"
                                                         {
	yylhs.value.as < A2lMemorySegment > ().Name = yystack_[10].value.as < std::string > ();
	yylhs.value.as < A2lMemorySegment > ().Description = yystack_[9].value.as < std::string > ();
	yylhs.value.as < A2lMemorySegment > ().SegmentType = yystack_[8].value.as < A2lSegmentType > ();
	yylhs.value.as < A2lMemorySegment > ().MemoryType = StringToMemoryType(yystack_[7].value.as < std::string > ());
	yylhs.value.as < A2lMemorySegment > ().Attribute = StringToMemoryAttribute(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemorySegment > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemorySegment > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemorySegment > ().OffsetList = yystack_[3].value.as < std::vector<int64_t> > ();
	yylhs.value.as < A2lMemorySegment > ().IfDataList =  yystack_[2].value.as < std::map<std::string, std::string> > ();
	}
#line 4221 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // memory_segment_attributes: %empty
#line 885 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4227 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // memory_segment_attributes: memory_segment_attributes if_data
#line 886 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < std::map<std::string, std::string> > () = yystack_[1].value.as < std::map<std::string, std::string> > ();
	yylhs.value.as < std::map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	}
#line 4236 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 890 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = yystack_[3].value.as < std::string > ();
}
#line 4245 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // mod_common_attribute: alignment_byte
#line 897 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4251 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // mod_common_attribute: alignment_float16_ieee
#line 898 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4257 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // mod_common_attribute: alignment_float32_ieee
#line 899 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4263 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 257: // mod_common_attribute: alignment_float64_ieee
#line 900 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 258: // mod_common_attribute: alignment_int64
#line 901 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // mod_common_attribute: alignment_long
#line 902 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 260: // mod_common_attribute: alignment_word
#line 903 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 261: // mod_common_attribute: byte_order
#line 904 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // mod_common_attribute: data_size
#line 905 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 263: // mod_common_attribute: deposit
#line 906 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 265: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 909 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = yystack_[3].value.as < std::string > ();
}
#line 4314 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // mod_par_attribute: addr_epk
#line 915 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4320 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 269: // mod_par_attribute: calibration_method
#line 916 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4326 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_par_attribute: cpu_type
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4332 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 271: // mod_par_attribute: customer
#line 918 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4338 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 272: // mod_par_attribute: customer_no
#line 919 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4344 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_par_attribute: ecu
#line 920 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4350 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_par_attribute: ecu_calibration_offset
#line 921 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4356 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 275: // mod_par_attribute: epk
#line 922 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 276: // mod_par_attribute: memory_layout
#line 923 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 277: // mod_par_attribute: memory_segment
#line 924 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4374 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 278: // mod_par_attribute: no_of_interfaces
#line 925 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4380 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 279: // mod_par_attribute: phone_no
#line 926 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4386 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_par_attribute: supplier
#line 927 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4392 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_par_attribute: system_constant
#line 928 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4398 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_par_attribute: user
#line 929 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4404 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 283: // mod_par_attribute: version
#line 930 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4410 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE
#line 932 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
	auto& module = scanner.CurrentModule();
	module.Name(yystack_[4].value.as < std::string > ());
	module.Description(yystack_[3].value.as < std::string > ());
}
#line 4420 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // module_attribute: a2ml
#line 940 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // module_attribute: axis_pts
#line 941 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 4434 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // module_attribute: blob
#line 944 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 4442 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // module_attribute: characteristic
#line 947 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 4450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // module_attribute: compu_method
#line 950 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 4458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // module_attribute: compu_tab
#line 953 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 4466 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // module_attribute: compu_vtab
#line 956 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 4474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // module_attribute: compu_vtab_range
#line 959 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 4482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // module_attribute: frame
#line 962 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 4490 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // module_attribute: function
#line 965 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 4498 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // module_attribute: group
#line 968 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 4506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // module_attribute: if_data
#line 971 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4514 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // module_attribute: instance
#line 974 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 4522 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // module_attribute: measurement
#line 977 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 4530 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module_attribute: record_layout
#line 982 "D:/projects/a2llib/src/a2lparser.y"
                        {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
#line 4538 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_attribute: transformer
#line 985 "D:/projects/a2llib/src/a2lparser.y"
                      {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
#line 4546 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_attribute: typedef_axis
#line 988 "D:/projects/a2llib/src/a2lparser.y"
                       {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
#line 4554 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 306: // module_attribute: typedef_blob
#line 991 "D:/projects/a2llib/src/a2lparser.y"
                       {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
#line 4562 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 307: // module_attribute: typedef_characteristic
#line 994 "D:/projects/a2llib/src/a2lparser.y"
                                 {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
#line 4570 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 308: // module_attribute: typedef_measurement
#line 997 "D:/projects/a2llib/src/a2lparser.y"
                              {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
#line 4578 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: typedef_structure
#line 1000 "D:/projects/a2llib/src/a2lparser.y"
                            {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
#line 4586 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: unit
#line 1003 "D:/projects/a2llib/src/a2lparser.y"
               {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
#line 4594 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: user_rights
#line 1006 "D:/projects/a2llib/src/a2lparser.y"
                      {
          auto& module = scanner.CurrentModule();
          module.AddUserRight(scanner.ReleaseUserRight()); }
#line 4602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1011 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 4608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1013 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4618 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // overwrite_attribute: conversion
#line 1020 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4624 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // overwrite_attribute: extended_limits
#line 1021 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4630 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // overwrite_attribute: format
#line 1022 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4636 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // overwrite_attribute: input_quantity
#line 1023 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4642 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // overwrite_attribute: limits
#line 1024 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Limits(yystack_[0].value.as < double > ()); }
#line 4648 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // overwrite_attribute: monotony
#line 1025 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4654 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // overwrite_attribute: phys_unit
#line 1026 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4660 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 324: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1028 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4670 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // project_attribute: module
#line 1036 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 4679 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 329: // record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT
#line 1041 "D:/projects/a2llib/src/a2lparser.y"
                                                                                            {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 4688 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 332: // record_layout_attribute: alignment_byte
#line 1047 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 4694 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 333: // record_layout_attribute: alignment_float16_ieee
#line 1048 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 4700 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 334: // record_layout_attribute: alignment_float32_ieee
#line 1049 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 4706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 335: // record_layout_attribute: alignment_float64_ieee
#line 1050 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 4712 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 336: // record_layout_attribute: alignment_int64
#line 1051 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 4718 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 337: // record_layout_attribute: alignment_long
#line 1052 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 4724 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 338: // record_layout_attribute: alignment_word
#line 1053 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 4730 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 339: // record_layout_attribute: axis_pts_x
#line 1054 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4736 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 340: // record_layout_attribute: axis_pts_y
#line 1055 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4742 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 341: // record_layout_attribute: axis_pts_z
#line 1056 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4748 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 342: // record_layout_attribute: axis_pts_4
#line 1057 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4754 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 343: // record_layout_attribute: axis_pts_5
#line 1058 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 344: // record_layout_attribute: axis_rescale_x
#line 1059 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 4766 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // record_layout_attribute: dist_op_x
#line 1060 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4772 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 346: // record_layout_attribute: dist_op_y
#line 1061 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4778 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 347: // record_layout_attribute: dist_op_z
#line 1062 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 348: // record_layout_attribute: dist_op_4
#line 1063 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4790 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 349: // record_layout_attribute: dist_op_5
#line 1064 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4796 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 350: // record_layout_attribute: fix_no_axis_pts_x
#line 1065 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 4802 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 351: // record_layout_attribute: fix_no_axis_pts_y
#line 1066 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 4808 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // record_layout_attribute: fix_no_axis_pts_z
#line 1067 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 4814 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 353: // record_layout_attribute: fix_no_axis_pts_4
#line 1068 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 4820 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 354: // record_layout_attribute: fix_no_axis_pts_5
#line 1069 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 4826 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 355: // record_layout_attribute: fnc_values
#line 1070 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 4832 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: identification
#line 1071 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 4838 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: no_axis_pts_x
#line 1072 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4844 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: no_axis_pts_y
#line 1073 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4850 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: no_axis_pts_z
#line 1074 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4856 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: no_axis_pts_4
#line 1075 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4862 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: no_axis_pts_5
#line 1076 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4868 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: no_rescale_x
#line 1077 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4874 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: offset_x
#line 1078 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4880 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: offset_y
#line 1079 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4886 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: offset_z
#line 1080 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4892 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: offset_4
#line 1081 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4898 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: offset_5
#line 1082 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4904 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: reserved
#line 1083 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 4910 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: rip_addr_w
#line 1084 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 4916 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: rip_addr_x
#line 1085 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4922 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: rip_addr_y
#line 1086 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4928 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: rip_addr_z
#line 1087 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4934 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: rip_addr_4
#line 1088 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4940 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: rip_addr_5
#line 1089 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4946 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: src_addr_x
#line 1090 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4952 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: src_addr_y
#line 1091 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4958 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: src_addr_z
#line 1092 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4964 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: src_addr_4
#line 1093 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4970 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: src_addr_5
#line 1094 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4976 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: shift_op_x
#line 1095 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4982 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: shift_op_y
#line 1096 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4988 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: shift_op_z
#line 1097 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4994 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: shift_op_4
#line 1098 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: shift_op_5
#line 1099 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5006 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: static_address_offsets
#line 1100 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5012 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: static_record_layout
#line 1101 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1103 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1104 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1105 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1108 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = yystack_[5].value.as < std::string > ();
        structure.Type = StringToTypedefType(yystack_[4].value.as < std::string > ());
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5047 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // structure_component_attribute: address_type
#line 1116 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5053 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // structure_component_attribute: layout
#line 1117 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // structure_component_attribute: matrix_dim
#line 1118 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 5065 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // structure_component_attribute: symbol_type_link
#line 1119 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1121 "D:/projects/a2llib/src/a2lparser.y"
                                                                     { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5077 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1122 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1125 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5098 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // transformer_attribute: transformer_in_objects
#line 1137 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5104 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // transformer_attribute: transformer_out_objects
#line 1138 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5110 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5116 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 405: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1141 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5122 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 406: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1144 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 409: // typedef_axis_attribute: byte_order
#line 1158 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // typedef_axis_attribute: deposit
#line 1159 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // typedef_axis_attribute: extended_limits
#line 1160 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5157 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // typedef_axis_attribute: format
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5163 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 413: // typedef_axis_attribute: monotony
#line 1162 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 414: // typedef_axis_attribute: phys_unit
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5175 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 415: // typedef_axis_attribute: step_size
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5181 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 416: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1166 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                        {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5192 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 419: // typedef_blob_attribute: address_type
#line 1174 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5198 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5214 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 423: // typedef_characteristic_attribute: axis_descr
#line 1190 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5223 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 424: // typedef_characteristic_attribute: bit_mask
#line 1194 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5229 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 425: // typedef_characteristic_attribute: byte_order
#line 1195 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5235 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 426: // typedef_characteristic_attribute: discrete
#line 1196 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5241 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 427: // typedef_characteristic_attribute: encoding
#line 1197 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5247 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 428: // typedef_characteristic_attribute: extended_limits
#line 1198 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5253 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // typedef_characteristic_attribute: format
#line 1199 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5259 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // typedef_characteristic_attribute: matrix_dim
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 5265 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // typedef_characteristic_attribute: number
#line 1201 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5271 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 432: // typedef_characteristic_attribute: phys_unit
#line 1202 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5277 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 433: // typedef_characteristic_attribute: step_size
#line 1203 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5283 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 434: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT UINT any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1206 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 437: // typedef_measurement_attribute: address_type
#line 1219 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_measurement_attribute: bit_mask
#line 1220 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 439: // typedef_measurement_attribute: bit_operation
#line 1221 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 440: // typedef_measurement_attribute: byte_order
#line 1222 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 441: // typedef_measurement_attribute: discrete
#line 1223 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 442: // typedef_measurement_attribute: error_mask
#line 1224 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 443: // typedef_measurement_attribute: format
#line 1225 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5341 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 444: // typedef_measurement_attribute: layout
#line 1226 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5347 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_measurement_attribute: matrix_dim
#line 1227 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 5353 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 446: // typedef_measurement_attribute: phys_unit
#line 1228 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5359 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 447: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING UINT typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1231 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5370 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 450: // typedef_structure_attribute: address_type
#line 1239 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5376 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 451: // typedef_structure_attribute: consistent_exchange
#line 1240 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5382 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_structure_attribute: structure_component
#line 1241 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5390 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 453: // typedef_structure_attribute: symbol_type_link
#line 1244 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5396 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 454: // unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1246 "D:/projects/a2llib/src/a2lparser.y"
                                                                            {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5408 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // unit_attribute: ref_unit
#line 1255 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5414 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // unit_attribute: si_exponents
#line 1256 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5420 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // unit_attribute: unit_conversion
#line 1257 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5429 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 460: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1262 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_right = scanner.CurrentUserRight();
       user_right.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5438 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 463: // user_rights_attribute: read_only
#line 1268 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRight().ReadOnly = true; }
#line 5444 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 464: // user_rights_attribute: ref_group
#line 1269 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRight().RefGroupList.emplace_back(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1271 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[2].value.as < std::vector<uint64_t> > (); }
#line 5456 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 466: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1274 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = yystack_[4].value.as < std::string > ();
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = yystack_[3].value.as < std::vector<std::string> > ();
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = yystack_[2].value.as < std::vector<uint64_t> > ();
    }
#line 5466 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 467: // var_characteristic_attribute: %empty
#line 1279 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5472 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 468: // var_characteristic_attribute: var_address
#line 1280 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 5478 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1282 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = yystack_[4].value.as < std::string > ();
    yylhs.value.as < A2lVarCriterion > ().Description = yystack_[3].value.as < std::string > ();
}
#line 5489 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // var_criterion_attribute: var_measurement
#line 1291 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = yystack_[0].value.as < std::string > (); }
#line 5495 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 473: // var_criterion_attribute: var_selection_characteristic
#line 1292 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = yystack_[0].value.as < std::string > (); }
#line 5501 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 474: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1294 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::map<std::string, std::string> > ()= yystack_[2].value.as < std::map<std::string, std::string> > (); }
#line 5507 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // variant_coding_attribute: var_characteristic
#line 1299 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5516 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 479: // variant_coding_attribute: var_criterion
#line 1303 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 480: // variant_coding_attribute: var_forbidden_comb
#line 1307 "D:/projects/a2llib/src/a2lparser.y"
                            {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(yystack_[0].value.as < std::map<std::string, std::string> > ());
       }
#line 5534 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 481: // variant_coding_attribute: var_naming
#line 1311 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = yystack_[0].value.as < std::string > ();
       }
#line 5543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 482: // variant_coding_attribute: var_separator
#line 1315 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = yystack_[0].value.as < std::string > ();
      }
#line 5552 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1320 "D:/projects/a2llib/src/a2lparser.y"
                                                      { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5558 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1322 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 5564 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // a2ml: A2ML
#line 1325 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5570 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1326 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 487: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1331 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5588 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // asap2_version: ASAP2_VERSION STRING
#line 1334 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5596 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // addr_epk: ADDR_EPK any_uint
#line 1338 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // address_type: ADDRESS_TYPE IDENT
#line 1339 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 491: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1340 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5614 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1341 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5620 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 493: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1342 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 494: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1343 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 495: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1344 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5638 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 496: // alignment_long: ALIGNMENT_LONG any_uint
#line 1345 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5644 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 497: // alignment_word: ALIGNMENT_WORD any_uint
#line 1346 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5650 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // annotation_label: ANNOTATION_LABEL STRING
#line 1347 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5656 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1348 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5662 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // array_size: ARRAY_SIZE any_uint
#line 1349 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5668 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1350 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 5674 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 502: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1351 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5680 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 503: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1352 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5691 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1358 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5702 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1364 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5713 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1370 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5724 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1376 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5735 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1382 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5747 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // bit_mask: BIT_MASK any_uint
#line 1389 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // byte_order: BYTE_ORDER IDENT
#line 1390 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 5759 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1391 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 5765 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1392 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5771 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1393 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	std::vector<double> list;
	list.push_back(yystack_[5].value.as < double > ());
	list.push_back(yystack_[4].value.as < double > ());
	list.push_back(yystack_[3].value.as < double > ());
	list.push_back(yystack_[2].value.as < double > ());
    list.push_back(yystack_[1].value.as < double > ());
    list.push_back(yystack_[0].value.as < double > ());
    yylhs.value.as < std::vector<double> > () = list;
}
#line 5786 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1403 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::vector<double> list;
	list.push_back(yystack_[1].value.as < double > ());
	list.push_back(yystack_[0].value.as < double > ());
        yylhs.value.as < std::vector<double> > () = list;
}
#line 5797 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1409 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5803 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1410 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5809 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // conversion: CONVERSION IDENT
#line 1412 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // cpu_type: CPU_TYPE STRING
#line 1413 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5821 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1414 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5827 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // customer: CUSTOMER STRING
#line 1415 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5833 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // customer_no: CUSTOMER_NO STRING
#line 1416 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5839 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 523: // data_size: DATA_SIZE any_uint
#line 1417 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5845 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // default_value: DEFAULT_VALUE STRING
#line 1418 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5851 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1419 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 5857 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // deposit: DEPOSIT IDENT
#line 1420 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 5863 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1422 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5869 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1423 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 5875 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1424 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5884 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1428 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5893 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1432 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5902 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 533: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1436 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5911 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 534: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1440 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5920 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // ecu: ECU STRING
#line 1444 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5926 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // ecu_address: ECU_ADDRESS any_uint
#line 1445 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5932 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1446 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 5938 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1447 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 5944 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // encoding: ENCODING IDENT
#line 1448 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 5950 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // epk: EPK STRING
#line 1449 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5956 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // error_mask: ERROR_MASK any_uint
#line 1450 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5962 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1451 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 5968 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1452 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 5974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1453 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 5980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1454 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1455 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5992 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 547: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1456 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5998 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1457 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6004 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1458 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6010 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1459 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6021 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // format: FORMAT STRING
#line 1465 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6027 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // formula_inv: FORMULA_INV STRING
#line 1466 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6033 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1467 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 6039 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // function_version: FUNCTION_VERSION STRING
#line 1468 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6045 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // identification: IDENTIFICATION any_uint IDENT
#line 1470 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6054 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // if_data: IF_DATA
#line 1474 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6060 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // input_quantity: INPUT_QUANTITY IDENT
#line 1475 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6066 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // layout: LAYOUT IDENT
#line 1476 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6072 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // left_shift: LEFT_SHIFT any_uint
#line 1477 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // limits: LIMITS FLOAT any_float
#line 1478 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < double > () = yystack_[1].value.as < double > ();}
#line 6084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // matrix_dim: MATRIX_DIM uint_list
#line 1479 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 6090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // max_grad: MAX_GRAD any_float
#line 1480 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1481 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // model_link: MODEL_LINK STRING
#line 1482 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6108 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // monotony: MONOTONY IDENT
#line 1483 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6114 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1484 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6123 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1488 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6132 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1492 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6141 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1496 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6150 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1500 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6159 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 572: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1504 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6165 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1505 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6174 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // number: NUMBER any_uint
#line 1509 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6180 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 575: // offset_x: OFFSET_X any_uint IDENT
#line 1510 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6189 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // offset_y: OFFSET_Y any_uint IDENT
#line 1514 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6198 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // offset_z: OFFSET_Z any_uint IDENT
#line 1518 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // offset_4: OFFSET_4 any_uint IDENT
#line 1522 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6216 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // offset_5: OFFSET_5 any_uint IDENT
#line 1526 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // phone_no: PHONE_NO STRING
#line 1530 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6231 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // phys_unit: PHYS_UNIT STRING
#line 1531 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6237 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // proj_no: IDENT
#line 1532 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6243 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // proj_no: UINT
#line 1533 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6249 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // project_no: PROJECT_NO proj_no
#line 1534 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6255 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1538 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6261 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // ref_unit: REF_UNIT IDENT
#line 1539 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6267 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // reserved: RESERVED any_uint IDENT
#line 1540 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
        yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
        }
#line 6276 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // right_shift: RIGHT_SHIFT any_uint
#line 1544 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6282 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 591: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6291 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 592: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1549 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6300 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1553 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6309 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1557 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6318 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1561 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6327 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1565 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6336 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1571 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6345 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1575 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6354 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1579 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6363 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 602: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1583 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6372 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 603: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1587 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6381 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 605: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1592 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 606: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1601 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6404 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1605 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6413 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1609 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6422 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1613 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 610: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1617 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6440 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 613: // status_string_ref: STATUS_STRING_REF IDENT
#line 1623 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6446 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 614: // step_size: STEP_SIZE any_float
#line 1624 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 615: // supplier: SUPPLIER STRING
#line 1625 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // symbol_link: SYMBOL_LINK STRING any_int
#line 1626 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 617: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1627 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6470 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 618: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1628 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6476 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1629 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // user: USER STRING
#line 1630 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 621: // var_measurement: VAR_MEASUREMENT IDENT
#line 1631 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // var_naming: VAR_NAMING IDENT
#line 1632 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1633 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6506 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 624: // var_separator: VAR_SEPARATOR STRING
#line 1634 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6512 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 625: // version: A2L_VERSION STRING
#line 1635 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6518 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6522 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -834;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
      59,   106,    85,   185,  -834,  -834,  -834,  -834,   215,  -834,
     -53,   215,  -834,  -834,  -834,   123,   215,   195,  -834,   205,
      45,  -834,  -834,   365,  -834,   267,   206,   147,  -834,  -834,
     310,  -834,    76,  -834,   217,   326,   270,  -834,  -834,  -834,
      89,  -834,  -834,  -834,  -834,  -834,   838,   220,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,   370,   388,   402,
     405,   413,   422,   429,   438,   444,   458,   462,   466,   381,
     468,   473,   475,   479,   482,   489,   490,   492,   495,   498,
    -834,  -834,   500,   502,   503,   504,   506,   509,   512,   519,
     520,   521,   522,   525,  -834,  -834,  -834,   527,   528,   530,
     531,   532,   534,   535,  -834,    16,   215,   215,   537,   538,
     539,   540,   215,   215,  -834,  -834,   541,   542,    55,   335,
     975,   543,   546,   215,   548,   550,   549,   553,    65,   -45,
     343,   551,   554,  -834,  -834,  -834,  -834,  -834,  -834,   556,
     215,   215,   561,   215,   215,  -834,   215,    83,    61,   215,
     557,   449,   215,   215,   215,   215,   215,   215,   215,   563,
     215,   567,   568,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,    -2,   452,   215,   569,   570,
     571,   576,   349,   578,   215,   580,   581,   584,   585,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,   446,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,   587,   589,  -834,   590,   591,  -834,   592,   450,   403,
    -834,  -834,  -834,  -834,   595,   596,  -834,  -834,  -834,  -834,
     597,  -834,   599,   600,  -834,  -834,   448,  -834,   341,   511,
     604,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,    30,   510,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,   215,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,   607,   609,
     610,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,   611,  -834,  -834,   613,   614,
     616,   617,   618,   619,   620,   621,   622,   623,   624,  -834,
    -834,  -834,  -834,  -834,   625,   627,   628,   629,   631,   632,
     633,   634,   636,   637,   639,   641,   642,   646,   647,   648,
     649,   650,   652,   654,   655,   657,   659,   661,   662,   663,
     664,   665,   666,   667,   215,   448,   110,   448,   668,    23,
    -834,  -834,  -834,  -834,   672,   135,   448,   301,   448,  -834,
     448,   448,  -834,  -834,  -834,  -834,   448,    68,    46,  -834,
     675,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,   677,   299,   448,   215,   215,   678,  -834,
     685,   686,   689,   691,   692,   215,  -834,  -834,  -834,  -834,
    -834,   694,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,   696,   697,   514,   700,  -834,  -834,   703,   448,   517,
     497,  -834,   705,  -834,  -834,  -834,  -834,  -834,    18,   194,
     309,  -834,   513,   704,   710,    35,   674,   712,   715,   349,
     215,   716,   717,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,   720,   142,   448,    84,   725,   116,   726,
     670,   728,  -834,  -834,   640,  -834,  -834,  -834,  -834,   281,
     708,   321,   325,   346,   358,   361,   371,   375,   379,   395,
    -834,    41,   635,   730,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
     448,  -834,   215,    51,   734,   735,   736,   737,   739,   740,
     742,   743,   215,  -834,  -834,   448,   448,   745,  -834,  -834,
     558,   747,   349,   448,  -834,  -834,  -834,  -834,   606,   559,
    -834,   754,    12,  -834,  -834,   215,   753,  -834,  -834,  -834,
    -834,   215,  -834,   349,   448,   669,   713,   448,   448,   757,
     764,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,   718,
     448,  -834,  -834,  -834,  -834,   719,  -834,  -834,  -834,  -834,
    -834,  -834,   677,   746,   751,   770,   773,  -834,  -834,  -834,
     765,   777,  -834,   721,   680,   676,   643,   644,   626,   693,
     651,   630,   779,  -834,  -834,   215,   448,   437,  -834,  -834,
    -834,   785,  -834,  -834,  -834,  -834,  -834,   791,  -834,  -834,
     448,   448,   448,   792,  -834,  -834,   349,   448,  -834,  -834,
     638,   612,   798,   803,  -834,  -834,  -834,   448,   806,  -834,
    -834,   448,   808,  -834,   448,   448,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,   783,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,   215,  -834,  -834,   771,
     768,  -834,   349,   812,  -834,   487,   448,  -834,  -834,   215,
     349,  -834,   288,  -834,  -834,  -834,  -834,   448,   748,  -834,
     724,   448,  -834,   338,  -834,  -834,   690,  -834,  -834,  -834,
      79,   215,   305,   645,  -834,  -834,  -834,  -834,   319,   684,
    -834,   349,   653,  -834,  -834,   605,   815,   820,  -834,   448,
     797,  -834,   428,    11,   709,   215,   215,  -834,   215,   215,
     821,   822,   827,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,   279,   723,  -834,
     215,  -834,  -834,  -834,   352,   802,   656,   829,   448,   215,
     448,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,   796,   658,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,    91,   349,  -834,   799,
      69,   790,   834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,   750,   448,  -834,   706,   842,   843,   841,
     847,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,   849,
     855,  -834,  -834,  -834,   398,   416,   671,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,   857,  -834,  -834,   448,  -834,
    -834,  -834,   682,  -834,  -834,  -834,  -834,  -834,   349,   261,
     831,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,   858,  -834,   862,  -834,  -834,  -834,   448,  -834,  -834,
    -834,   448,  -834,    37,   420,  -834,   826,   349,   687,   688,
    -834,   869,  -834,  -834,   349,  -834,  -834,   443,  -834,  -834,
    -834,   835,   215,   215,  -834,  -834,  -834,  -834,  -834,   673,
    -834,    80,  -834,  -834,   873,  -834,   447,   772,   456,  -834,
    -834,  -834,  -834,   762,  -834,   215,   816,  -834,   695,  -834,
     448,  -834,  -834,   448,  -834,   439,   128,   853,   882,   884,
     448,   448,   448,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,   448,   448,  -834,   382,   215,   215,   809,
    -834,  -834,  -834,  -834
  };

  const short
  A2lParser::yydefact_[] =
  {
       0,     0,     0,     0,    30,   488,     2,     3,     0,     1,
       0,     0,    29,    31,   487,     0,     0,     0,   486,     0,
       0,   327,   328,     0,   325,     0,     0,     0,   326,   194,
       0,   324,     0,   285,     0,     0,     0,   195,   196,   197,
       0,   193,   625,   582,   583,   584,     0,     0,   485,   557,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     299,   300,   301,   302,   286,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   287,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   266,   330,     0,     0,     0,
       0,     0,     0,     0,   461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   478,   479,   480,   477,   481,   482,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
     276,   277,   267,   268,   270,   271,   272,   273,   274,   275,
     278,   279,   280,   281,   282,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   611,   612,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   380,
     381,   382,   383,   384,   375,   376,   377,   378,   379,   385,
     386,     0,     0,   417,     0,     0,   448,     0,     0,     0,
     585,   464,   462,   463,     0,     0,    27,   475,   622,   624,
       0,    88,     0,     0,    17,    19,   154,   164,     0,     0,
       0,   171,   172,   173,   170,   176,   177,   178,   179,   180,
     174,   175,     0,     0,    25,   597,   186,   187,   185,   189,
     190,   192,   188,   191,   200,     0,   251,   491,   492,   493,
     494,   495,   496,   497,   510,   523,   526,   598,     0,     0,
       0,   265,   489,   519,   521,   522,   535,     4,     5,     6,
     538,   540,   572,   580,   615,     0,   620,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   545,
     546,   547,   548,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,    25,   460,    25,     0,     0,     0,     0,     0,   136,
     145,   150,     8,     9,    10,     7,     0,     0,     0,    33,
       0,    25,    25,    25,    25,    25,    25,   168,   554,    25,
      25,    25,   183,   182,     0,     0,     0,     0,     0,   618,
       0,     0,     0,     0,     0,     0,   530,   531,   532,   533,
     534,     0,   556,   567,   568,   569,   570,   571,   573,   575,
     576,   577,   578,   579,   589,   591,   592,   593,   594,   595,
     596,   599,   600,   601,   602,   603,   606,   607,   608,   609,
     610,     0,     0,     0,     0,   418,   419,     0,     0,     0,
       0,   517,     0,   452,   449,   450,   451,   453,     0,     0,
     467,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    89,    90,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,     0,    25,   165,   166,   167,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,    13,   586,   203,   201,   212,   202,
     204,   205,   206,   207,   208,   209,   210,   211,   213,   214,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   416,   490,     0,     0,     0,   447,   617,
       0,     0,     0,     0,   456,   457,   458,   459,     0,     0,
     468,     0,     0,   474,    28,     0,     0,    87,   511,   528,
     537,     0,   565,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   141,   138,   139,   140,   142,   143,    18,     0,
       0,   146,   147,   148,    20,     0,   151,   152,    22,   153,
     524,   163,   553,     0,     0,     0,     0,    36,    34,    35,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   559,   562,     0,     0,    11,   247,
     246,     0,   503,   504,   505,   506,   507,     0,   550,   400,
       0,     0,     0,     0,   454,   588,     0,     0,   388,    13,
       0,     0,     0,     0,   471,   472,   473,     0,     0,   564,
     616,     0,     0,   135,     0,     0,   516,   613,   144,   525,
     149,    23,    32,   498,   499,   501,     0,   157,   198,   215,
     313,   387,   397,   181,   389,   398,     0,    14,   218,     0,
       0,   104,   244,     0,   508,     0,     0,   421,   435,     0,
       0,   619,     0,   466,   469,   621,   623,     0,     0,   106,
     161,     0,   514,     0,    38,   315,     0,    11,   102,    12,
       0,     0,     0,     0,   401,   402,   403,   407,     0,     0,
     391,     0,     0,    60,   529,     0,     0,     0,   162,     0,
       0,    24,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,   221,   224,   232,   219,   242,   220,   222,
     223,   225,   226,   227,   228,   229,   230,   231,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   100,     0,   245,
       0,    25,    25,   399,     0,     0,     0,     0,     0,     0,
       0,   423,   422,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,   439,   436,   437,   438,   440,
     441,   442,   443,   444,   445,   446,     0,     0,   465,     0,
       0,     0,     0,   555,   108,   109,   107,   114,   121,   124,
     134,   110,   111,   112,   113,   115,   116,   117,   118,   119,
     120,   122,   123,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   552,     0,     0,    37,     0,     0,     0,     0,
       0,   316,   317,   318,   319,   320,   321,   322,   323,    82,
      25,   217,   500,   509,   536,   541,   551,   581,   587,     0,
       0,   101,   243,    11,     0,     0,     0,   408,   409,   410,
     411,   412,   413,   414,   415,     0,   420,   539,     0,   574,
     614,   434,     0,   392,   393,   394,   395,   396,     0,     0,
       0,    62,    61,    70,    63,    64,    65,    66,    67,    68,
      69,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,    25,     0,   105,   515,   160,     0,   314,   518,
     558,     0,   566,     0,     0,   512,     0,   249,     0,     0,
     406,     0,   542,   390,     0,    59,    25,     0,    25,   513,
     561,     0,     0,     0,   604,    83,    84,    85,    86,     0,
      99,     0,   404,   405,     0,   605,     0,     0,     0,    81,
     560,   590,   483,     0,   250,     0,     0,   216,     0,   248,
       0,   158,   484,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    43,    52,    45,    46,    47,    48,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    15,
      41,   502,   520,     0,     0,   563,     0,     0,     0,     0,
      16,   543,   544,   159
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -834,    -1,  -197,  -185,  -803,   138,  -834,  -834,  -834,  -834,
    -834,  -462,  -834,  -834,  -834,  -167,  -834,  -834,  -834,  -834,
      56,  -834,  -834,  -834,  -834,  -834,    67,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -735,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,   877,  -834,
    -834,  -834,   741,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -452,   767,   774,   780,   781,   782,   788,   789,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -681,  -791,  -502,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -129,  -834,  -833,  -539,
    -498,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -496,  -834,
      63,  -834,    71,  -824,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -796,  -834,  -834,  -834,   -25,  -834,  -164,  -834,
    -703,  -834,  -834,  -717,  -834,  -492,  -491,  -832,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,    66,  -834,  -834,  -834,  -834,
    -834,  -834,  -794,  -834,  -834,  -822,    86,  -782,   336,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,  -834,
    -834,  -834,  -834,  -834,  -827,  -834,  -490,   -13,  -834,  -834,
    -834,  -834,  -834,  -834,  -834,   793
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   797,   829,   486,   802,   735,  1136,   480,   481,   356,
     823,   503,   475,     2,     3,   361,   609,   717,   362,   721,
     901,  1105,  1114,    50,   929,  1022,   864,  1053,  1075,    51,
     477,   584,   801,   990,   209,   737,    52,   845,   936,    53,
     594,   691,    54,   596,   701,    55,   598,   706,    56,   487,
     602,   363,   937,  1115,   692,   847,    57,   488,   606,    58,
     167,   364,   377,    59,   168,   378,    21,    32,    37,   365,
      60,   504,   627,   366,   939,    61,   826,   866,   210,   830,
     741,   211,  1081,    62,   138,   183,    63,   139,   212,    22,
      40,    64,   367,   628,   852,   971,    12,    23,    24,    65,
     140,   275,   368,   341,   380,   563,   926,  1013,   369,   381,
      66,   805,   834,   835,   836,    67,   894,   997,    68,   466,
     555,    69,   838,   902,    70,   839,   916,    71,   469,   564,
      72,   568,   664,    73,   148,   342,   670,   153,   671,   154,
     672,   764,   155,    74,   125,   156,   867,   940,    75,    13,
       4,   213,   556,   184,   185,   186,   187,   188,   189,   190,
     718,   719,   869,   722,  1116,   283,   284,   285,   286,   287,
     288,   870,   191,   586,   991,   693,   694,   944,   695,   566,
     972,   214,  1118,   215,   216,   192,   603,   703,   193,   872,
     587,   289,   290,   291,   292,   293,   217,   874,   588,   218,
     906,   219,   876,   907,  1121,  1122,   294,   295,   296,   297,
     298,   299,   877,   848,   607,   370,   951,   300,    76,   975,
     634,  1076,   976,   635,  1124,   590,   591,   977,   301,   302,
     303,   304,   305,   220,   306,   910,   307,   308,   309,   310,
     311,   221,   883,    45,    38,   343,   638,   885,   665,   312,
    1077,   313,   314,   315,   316,   317,   318,   383,   194,   319,
     320,   321,   322,   323,  1078,   666,   324,   325,   326,   327,
     328,   329,   330,   697,   912,   222,   592,   567,   223,   667,
     224,   765,   157,   766,   158,    39
  };

  const short
  A2lParser::yytable_[] =
  {
       8,   376,   630,   371,   382,   410,   631,    14,   632,   569,
      16,   570,   636,   637,   639,    18,   761,   565,   960,   149,
     150,   949,   660,   958,   887,   585,   559,   560,   973,   611,
     612,   613,   614,   615,   616,   871,   489,   617,   618,   619,
     554,  1071,   908,   922,   911,   925,   398,   904,   919,   950,
     604,   957,   629,   979,   942,   489,   974,   739,   978,   171,
     489,   999,  1002,   959,   372,   373,   489,  1004,   338,   339,
    1000,     1,   600,   172,   173,   174,   175,   176,   177,   178,
      34,   561,   676,   888,  1093,     9,   358,   359,   699,    35,
      15,   865,    46,    47,   489,  1012,  1026,  1035,  1001,   179,
    1003,  1005,  1039,   998,    48,  1029,   676,  1037,   554,   880,
     938,   499,   676,     5,   553,     6,     7,   399,   400,   180,
     705,   909,   924,   879,   181,   159,   160,   554,   953,    17,
     499,   165,   166,  1030,   601,  1036,   923,  1041,  1024,   572,
     676,   573,   333,   712,   605,   685,   686,  1038,  1072,    25,
     601,   700,    49,   489,   344,   345,   346,   903,   918,   351,
     352,   374,   354,   355,   941,   357,    26,    49,   384,   499,
     661,   387,   388,   389,   390,   391,   392,   393,   495,   395,
     500,   732,   601,  1042,   360,    49,    49,   662,    10,    49,
    1057,  1073,   687,   688,  1023,    49,   402,   689,   668,    11,
     620,   623,    19,   412,   740,  1074,   624,   562,    20,  1016,
     340,   501,    30,   663,   762,  1129,   763,   182,   980,   151,
      36,   152,   375,  1015,     6,     7,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,  1119,  1125,    29,   562,    43,  1043,  1128,    44,
     552,  1120,   557,  1127,   713,   714,   489,   407,   408,   409,
      31,   574,   842,   593,   661,   595,   597,     6,     7,   905,
     920,   599,   621,   622,   575,   576,   945,   715,   716,  1123,
     583,  1126,   669,   589,  1117,   620,   554,    33,   554,   690,
     640,    41,   895,   896,   608,   723,   989,   620,   873,   724,
     875,   620,   676,    42,   881,   882,   886,   626,   195,   196,
     633,   101,   850,   943,   577,   851,   577,   946,    35,   947,
     725,   197,   620,   954,   955,   961,   996,   407,   408,   409,
     856,   499,   726,   179,   620,   727,   489,   620,    20,    27,
     578,   490,   578,   656,   868,   728,   102,   620,   579,   729,
     579,   620,   680,   730,   505,   620,  1139,   917,   114,   857,
     482,   483,   484,   485,   103,   198,   179,   199,   200,   731,
     897,   620,  1058,   898,   620,    49,   491,    49,   104,   623,
     698,   105,   201,   860,   624,   202,   580,   203,   580,   106,
    1059,   181,   620,   581,  1079,   581,   620,  1025,   107,   994,
     995,  1027,   966,  1028,   624,   108,   898,  1033,  1034,  1040,
     799,   800,  1106,  1107,   109,   625,   860,  1087,   492,   620,
     110,  1096,   899,   620,   493,   736,   482,   483,   484,   485,
    1098,   861,   620,   551,   111,   756,   204,   702,   112,   707,
     751,   752,   113,  1108,  1014,   115,   205,   970,   757,   116,
     494,   117,   582,   179,   582,   118,   770,   967,   119,   495,
     832,   833,   891,   892,   861,   120,   121,   900,   122,   771,
    1109,   123,   774,   775,   124,   641,   642,   126,   181,   127,
     128,   129,   898,   130,   649,   779,   131,   206,  1054,   132,
     207,   496,   860,   898,  1110,  1111,   133,   134,   135,   136,
     900,   208,   137,   860,   141,   142,   968,   143,   144,   145,
     969,   146,   147,   161,   162,   163,   164,   169,   170,   347,
     331,   798,   332,   970,   334,  1112,   335,   348,   336,   810,
     337,   349,   350,   385,   970,   806,   807,   808,   353,   394,
     861,   386,   811,   396,   397,   401,   403,   404,   405,   681,
    1067,   861,   817,   406,   340,   411,   819,   413,   414,   821,
     822,   415,   416,   417,   464,   465,   467,   468,   470,   471,
     472,   473,   474,   476,  1086,   478,  1088,   479,   930,   931,
     497,   498,   502,   841,   506,   507,   508,   900,   509,   510,
     511,   837,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   843,   522,   523,   524,   849,   525,   526,   527,
     528,   738,   529,   530,   927,   531,   856,   532,   533,   179,
     577,   750,   534,   535,   536,   537,   538,   932,   539,   863,
     540,   541,   878,   542,   964,   543,   889,   544,   545,   546,
     547,   548,   549,   550,   767,   857,   578,   558,   934,   571,
     769,   952,   610,   620,   579,   643,   897,   913,   914,   898,
     658,   644,   645,   853,   854,   646,   657,   647,   648,   860,
     650,   554,   651,   652,   653,   374,   654,   554,   933,   655,
     674,    49,   659,  1008,   673,  1010,   675,   677,   678,   855,
     624,   679,   580,   682,   683,   856,   684,   709,   179,   581,
    1018,   856,   704,   708,   179,   710,   734,   711,   899,   720,
     742,   743,   744,   745,   733,   746,   747,   861,   748,   749,
     340,   753,   754,   755,   857,   758,   862,   759,   760,   768,
     857,   578,  1021,   776,   772,  1032,   773,   859,   858,   579,
     777,   785,   778,   859,   781,   780,   782,   783,   860,  1047,
     784,   786,   790,   900,   860,   796,   787,   788,   582,   789,
     374,   803,   791,   793,   623,   825,    49,   804,   809,   624,
     623,   794,  1019,  1020,   815,   624,   792,   580,   840,   816,
     818,   795,   814,   824,   581,   820,   828,   827,   831,   844,
     846,  1064,   962,  1062,   963,   965,   861,   981,   986,   987,
     890,   893,   861,   988,  1005,  1007,   625,   813,   979,  1044,
    1045,   862,   992,   179,   577,  1046,  1048,  1006,  1049,  1050,
    1011,   928,  1051,  1052,   982,   983,  1055,   984,   985,  1056,
    1060,  1063,  1069,  1061,  1065,  1066,  1070,  1085,   181,  1068,
     578,    77,  1080,   582,  1082,  1084,  1083,  1089,   579,  1095,
    1092,    78,  1099,   898,  1101,  1130,  1097,    79,  1131,   993,
    1132,    80,    81,   860,    82,    83,  1143,   812,  1009,   374,
      28,   935,   933,  1102,  1031,    49,   915,   276,   948,   379,
     921,   956,   884,  1017,   277,  1103,   580,  1094,  1104,     0,
     278,   279,   280,   581,   970,  1133,  1134,  1135,   281,   282,
     696,     0,   225,     0,     0,    84,     0,    85,  1113,     0,
      86,   861,     0,     0,   340,     0,     0,    87,  1137,  1138,
     862,  1140,     0,     0,     0,     0,    88,     0,     0,     0,
      89,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   900,     0,   226,
       0,     0,   582,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,    93,    94,    95,
      96,    97,    98,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,   233,   234,   235,
     236,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,   242,   243,     0,
       0,  1090,  1091,     0,     0,     0,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
     257,   258,   259,   260,   261,   262,  1141,  1142,   263,   264,
     265,   266,   267,     0,     0,   268,   269,   270,   271,   272,
     273,   274
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,   168,   504,   167,   168,   202,   504,     8,   504,   471,
      11,   473,   504,   504,   504,    16,     4,   469,   845,     3,
       4,   845,     4,   845,   827,   477,     3,     4,   852,   491,
     492,   493,   494,   495,   496,   826,    25,   499,   500,   501,
      17,     4,   838,   839,   838,   839,    48,   838,   839,   845,
       4,   845,   504,    42,   845,    25,   852,     6,   852,     4,
      25,   894,   894,   845,     3,     4,    25,   894,     3,     4,
     894,    12,     4,    18,    19,    20,    21,    22,    23,    24,
       4,    58,    71,     4,     4,     0,     3,     4,     4,    13,
     143,   826,     3,     4,    25,     4,   929,   929,   894,    44,
     894,    32,   929,   894,    15,   929,    71,   929,    17,   826,
     845,   100,    71,     7,     4,     9,    10,   119,   120,    64,
       4,   838,   839,   826,    69,   126,   127,    17,   845,     6,
     100,   132,   133,   929,    66,   929,   839,    68,   929,     4,
      71,     6,   143,   605,    98,     3,     4,   929,   111,   104,
      66,    67,   106,    25,   199,   200,   201,   838,   839,   160,
     161,   100,   163,   164,   845,   166,   121,   106,   169,   100,
     152,   172,   173,   174,   175,   176,   177,   178,   148,   180,
     150,   140,    66,   114,   101,   106,   106,   169,     3,   106,
     993,   154,    50,    51,   929,   106,   197,    55,     4,    14,
       6,   110,     7,   204,   153,   168,   115,   184,     3,   926,
     145,   181,     6,   195,   202,    87,   204,   162,   207,   203,
     144,   205,   161,   926,     9,    10,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,  1105,  1105,     7,   184,     6,   208,  1105,     9,
     465,  1105,   467,  1105,     3,     4,    25,     8,     9,    10,
     143,   476,     4,   478,   152,   480,   481,     9,    10,   838,
     839,   486,     3,     4,     3,     4,   845,    26,    27,  1105,
     477,  1105,     3,   477,  1105,     6,    17,     7,    17,   177,
     505,   104,     3,     4,   488,     4,    47,     6,   826,     4,
     826,     6,    71,     7,   826,   826,   826,   504,     3,     4,
     504,   121,     4,   845,    45,     7,    45,   845,    13,   845,
       4,    16,     6,   845,   845,   845,     4,     8,     9,    10,
      41,   100,     4,    44,     6,     4,    25,     6,     3,     4,
      71,    30,    71,   558,   826,     4,     6,     6,    79,     4,
      79,     6,   579,     4,   385,     6,     4,   839,     7,    70,
       8,     9,    10,    11,     6,    60,    44,    62,    63,     4,
      81,     6,     4,    84,     6,   106,    65,   106,     6,   110,
     595,     6,    77,    94,   115,    80,   117,    82,   117,     6,
       4,    69,     6,   124,     4,   124,     6,   929,     6,   891,
     892,   929,     4,   929,   115,     6,    84,   929,   929,   929,
       3,     4,     3,     4,     6,   146,    94,     4,   107,     6,
       6,     4,   133,     6,   113,   640,     8,     9,    10,    11,
       4,   142,     6,   464,     6,   662,   131,   596,     6,   598,
     655,   656,     6,    34,   926,     7,   141,   125,   663,     6,
     139,     6,   183,    44,   183,     6,   683,    59,     6,   148,
       3,     4,   187,   188,   142,     6,     6,   178,     6,   684,
      61,     6,   687,   688,     6,   506,   507,     7,    69,     7,
       7,     7,    84,     7,   515,   700,     7,   182,   980,     7,
     185,   180,    94,    84,    85,    86,     7,     7,     7,     7,
     178,   196,     7,    94,     7,     7,   108,     7,     7,     7,
     112,     7,     7,     6,     6,     6,     6,     6,     6,   206,
       7,   736,     6,   125,     6,   116,     6,     6,     9,   756,
       7,     7,     6,     6,   125,   750,   751,   752,     7,     6,
     142,   122,   757,     6,     6,   123,     7,     7,     7,   580,
    1042,   142,   767,     7,   145,     7,   771,     7,     7,   774,
     775,     7,     7,   147,     7,     6,     6,     6,     6,   149,
     197,     6,     6,     6,  1066,     6,  1068,     7,     3,     4,
      99,     7,   102,   810,     7,     6,     6,   178,     7,     6,
       6,   806,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,   817,     6,     6,     6,   821,     6,     6,     6,
       6,   642,     6,     6,   841,     6,    41,     6,     6,    44,
      45,   652,     6,     6,     6,     6,     6,    52,     6,   826,
       6,     6,   826,     6,   849,     6,   830,     6,     6,     6,
       6,     6,     6,     6,   675,    70,    71,     9,   845,     7,
     681,   845,     7,     6,    79,     7,    81,     3,     4,    84,
     193,     6,     6,     3,     4,     6,   179,     6,     6,    94,
       6,    17,     6,     6,   190,   100,     6,    17,   103,     6,
       6,   106,     7,   898,   201,   900,     6,    43,     6,    29,
     115,     6,   117,     7,     7,    41,     6,    57,    44,   124,
     927,    41,     7,     7,    44,     7,     6,    97,   133,    31,
       6,     6,     6,     6,   109,     6,     6,   142,     6,     6,
     145,     6,   194,     6,    70,   149,   151,   198,     4,     6,
      70,    71,   929,     6,    95,   929,    53,    83,    78,    79,
       6,     6,    54,    83,    28,    56,    25,     7,    94,   964,
       7,     4,   139,   178,    94,     6,    65,   107,   183,   113,
     100,     6,   148,   100,   110,   796,   106,     6,     6,   115,
     110,   150,     3,     4,     6,   115,   180,   117,   809,     6,
       4,   181,   200,    30,   124,     7,    48,    46,     6,    71,
      96,  1018,     7,  1008,     4,    28,   142,   118,     7,     7,
     831,   186,   142,     6,    32,     6,   146,   199,    42,    49,
       6,   151,   119,    44,    45,    95,   140,   191,     6,     6,
     192,   198,    11,     6,   855,   856,     7,   858,   859,     4,
     189,   179,  1047,     6,    33,     7,  1051,  1064,    69,     7,
      71,    33,    46,   183,   187,     6,   188,    42,    79,     6,
     207,    43,   120,    84,    68,    32,   114,    49,     6,   890,
       6,    53,    54,    94,    56,    57,    87,   759,   899,   100,
      23,   845,   103,   208,   929,   106,   839,   140,   845,   168,
     839,   845,   826,   926,   140,  1100,   117,  1081,  1103,    -1,
     140,   140,   140,   124,   125,  1110,  1111,  1112,   140,   140,
     594,    -1,   139,    -1,    -1,    97,    -1,    99,  1105,    -1,
     102,   142,    -1,    -1,   145,    -1,    -1,   109,  1133,  1134,
     151,  1136,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,     4,
      -1,    -1,   183,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,    -1,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    -1,
      -1,  1072,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1095,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,
     155,   156,   157,   158,   159,   160,  1137,  1138,   163,   164,
     165,   166,   167,    -1,    -1,   170,   171,   172,   173,   174,
     175,   176
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   222,   223,   359,     7,     9,    10,   210,     0,
       3,    14,   305,   358,   210,   143,   210,     6,   210,     7,
       3,   275,   298,   306,   307,   104,   121,     4,   307,     7,
       6,   143,   276,     7,     4,    13,   144,   277,   453,   494,
     299,   104,     7,     6,     9,   452,     3,     4,    15,   106,
     232,   238,   245,   248,   251,   254,   257,   265,   268,   272,
     279,   284,   292,   295,   300,   308,   319,   324,   327,   330,
     333,   336,   339,   342,   352,   357,   427,    33,    43,    49,
      53,    54,    56,    57,    97,    99,   102,   109,   118,   122,
     123,   147,   186,   189,   190,   191,   192,   193,   194,   197,
     206,   121,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     7,     7,     6,     6,     6,     6,
       6,     6,     6,     6,     6,   353,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   293,   296,
     309,     7,     7,     7,     7,     7,     7,     7,   343,     3,
       4,   203,   205,   346,   348,   351,   354,   491,   493,   210,
     210,     6,     6,     6,     6,   210,   210,   269,   273,     6,
       6,     4,    18,    19,    20,    21,    22,    23,    24,    44,
      64,    69,   162,   294,   362,   363,   364,   365,   366,   367,
     368,   381,   394,   397,   467,     3,     4,    16,    60,    62,
      63,    77,    80,    82,   131,   141,   182,   185,   196,   243,
     287,   290,   297,   360,   390,   392,   393,   405,   408,   410,
     442,   450,   484,   487,   489,   494,     4,    35,    36,    37,
      38,    39,    40,    72,    73,    74,    75,    76,    88,    89,
      90,    91,    92,    93,   105,   126,   127,   128,   129,   130,
     132,   134,   135,   136,   137,   138,   153,   155,   156,   157,
     158,   159,   160,   163,   164,   165,   166,   167,   170,   171,
     172,   173,   174,   175,   176,   310,   362,   363,   364,   365,
     366,   367,   368,   374,   375,   376,   377,   378,   379,   400,
     401,   402,   403,   404,   415,   416,   417,   418,   419,   420,
     426,   437,   438,   439,   440,   441,   443,   445,   446,   447,
     448,   449,   458,   460,   461,   462,   463,   464,   465,   468,
     469,   470,   471,   472,   475,   476,   477,   478,   479,   480,
     481,     7,     6,   210,     6,     6,     9,     7,     3,     4,
     145,   312,   344,   454,   199,   200,   201,   206,     6,     7,
       6,   210,   210,     7,   210,   210,   218,   210,     3,     4,
     101,   224,   227,   260,   270,   278,   282,   301,   311,   317,
     424,   427,     3,     4,   100,   161,   224,   271,   274,   311,
     313,   318,   427,   466,   210,     6,   122,   210,   210,   210,
     210,   210,   210,   210,     6,   210,     6,     6,    48,   119,
     120,   123,   210,     7,     7,     7,     7,     8,     9,    10,
     211,     7,   210,     7,     7,     7,     7,   147,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,     7,     6,   328,     6,     6,   337,
       6,   149,   197,     6,     6,   221,     6,   239,     6,     7,
     216,   217,     8,     9,    10,    11,   212,   258,   266,    25,
      30,    65,   107,   113,   139,   148,   180,    99,     7,   100,
     150,   181,   102,   220,   280,   210,     7,     6,     6,     7,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   210,   212,     4,    17,   329,   361,   212,     9,     3,
       4,    58,   184,   314,   338,   361,   388,   486,   340,   220,
     220,     7,     4,     6,   212,     3,     4,    45,    71,    79,
     117,   124,   183,   224,   240,   361,   382,   399,   407,   427,
     434,   435,   485,   212,   249,   212,   252,   212,   255,   212,
       4,    66,   259,   395,     4,    98,   267,   423,   427,   225,
       7,   220,   220,   220,   220,   220,   220,   220,   220,   220,
       6,     3,     4,   110,   115,   146,   224,   281,   302,   361,
     382,   399,   407,   427,   429,   432,   434,   435,   455,   485,
     212,   210,   210,     7,     6,     6,     6,     6,     6,   210,
       6,     6,     6,   190,     6,     6,   212,   179,   193,     7,
       4,   152,   169,   195,   341,   457,   474,   488,     4,     3,
     345,   347,   349,   201,     6,     6,    71,    43,     6,     6,
     211,   210,     7,     7,     6,     3,     4,    50,    51,    55,
     177,   250,   263,   384,   385,   387,   457,   482,   212,     4,
      67,   253,   395,   396,     7,     4,   256,   395,     7,    57,
       7,    97,   220,     3,     4,    26,    27,   226,   369,   370,
      31,   228,   372,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   140,   109,     6,   214,   212,   244,   210,     6,
     153,   289,     6,     6,     6,     6,     6,     6,     6,     6,
     210,   212,   212,     6,   194,     6,   211,   212,   149,   198,
       4,     4,   202,   204,   350,   490,   492,   210,     6,   210,
     211,   212,    95,    53,   212,   212,     6,     6,    54,   212,
      56,    28,    25,     7,     7,     6,     4,    65,   107,   113,
     139,   148,   180,   100,   150,   181,     6,   210,   212,     3,
       4,   241,   213,     6,     6,   320,   212,   212,   212,     6,
     211,   212,   214,   199,   200,     6,     6,   212,     4,   212,
       7,   212,   212,   219,    30,   210,   285,    46,    48,   211,
     288,     6,     3,     4,   321,   322,   323,   212,   331,   334,
     210,   211,     4,   212,    71,   246,    96,   264,   422,   212,
       4,     7,   303,     3,     4,    29,    41,    70,    78,    83,
      94,   142,   151,   224,   235,   271,   286,   355,   361,   371,
     380,   381,   398,   399,   406,   407,   411,   421,   427,   429,
     432,   434,   435,   451,   455,   456,   485,   213,     4,   427,
     210,   187,   188,   186,   325,     3,     4,    81,    84,   133,
     178,   229,   332,   380,   381,   398,   409,   412,   421,   432,
     444,   451,   483,     3,     4,   235,   335,   361,   380,   381,
     398,   411,   421,   429,   432,   451,   315,   211,   198,   233,
       3,     4,    52,   103,   224,   229,   247,   261,   271,   283,
     356,   380,   381,   382,   386,   398,   399,   407,   409,   412,
     421,   425,   427,   432,   434,   435,   444,   451,   454,   456,
     483,   485,     7,     4,   212,    28,     4,    59,   108,   112,
     125,   304,   389,   412,   421,   428,   431,   436,   451,    42,
     207,   118,   210,   210,   210,   210,     7,     7,     6,    47,
     242,   383,   119,   210,   220,   220,     4,   326,   381,   397,
     412,   421,   436,   451,   483,    32,   191,     6,   212,   210,
     212,   192,     4,   316,   361,   429,   432,   486,   211,     3,
       4,   224,   234,   271,   381,   382,   397,   399,   407,   412,
     421,   425,   427,   434,   435,   436,   451,   454,   456,   483,
     485,    68,   114,   208,    49,     6,    95,   212,   140,     6,
       6,    11,     6,   236,   220,     7,     4,   213,     4,     4,
     189,     6,   212,   179,   211,    33,     7,   220,     7,   212,
     212,     4,   111,   154,   168,   237,   430,   459,   473,     4,
      46,   291,   187,   188,     6,   211,   220,     4,   220,    42,
     210,   210,   207,     4,   427,     6,     4,   114,     4,   120,
     210,    68,   208,   212,   212,   230,     3,     4,    34,    61,
      85,    86,   116,   224,   231,   262,   373,   381,   391,   397,
     412,   413,   414,   421,   433,   436,   451,   454,   483,    87,
      32,     6,     6,   212,   212,   212,   215,   212,   212,     4,
     212,   210,   210,    87
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   209,   210,   210,   211,   211,   211,   212,   212,   212,
     212,   213,   213,   214,   214,   215,   215,   216,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     223,   223,   224,   225,   225,   225,   225,   226,   227,   228,
     228,   229,   230,   230,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   232,
     233,   233,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   235,   236,   236,   237,   237,   237,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   241,
     242,   242,   243,   244,   244,   245,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   248,   249,   249,   250,   250,
     250,   250,   250,   250,   251,   252,   252,   253,   253,   254,
     255,   255,   256,   257,   258,   258,   259,   260,   261,   262,
     263,   264,   264,   265,   266,   266,   267,   267,   268,   269,
     269,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   272,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   275,   276,   276,   277,   277,   278,   279,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   282,   283,   284,   285,   285,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   288,   288,   289,   289,   290,   291,
     291,   292,   293,   293,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   298,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   301,   302,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   305,   306,   306,   307,   307,   308,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   312,   313,
     314,   315,   315,   316,   316,   316,   316,   317,   318,   319,
     320,   320,   321,   321,   322,   323,   324,   325,   325,   326,
     326,   326,   326,   326,   326,   326,   327,   328,   328,   329,
     330,   331,   331,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   333,   334,   334,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   336,   337,   337,
     338,   338,   338,   338,   339,   340,   340,   341,   341,   341,
     342,   343,   343,   344,   344,   345,   346,   347,   347,   348,
     349,   349,   350,   350,   351,   352,   353,   353,   354,   354,
     354,   354,   354,   355,   356,   357,   358,   359,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     0,     2,     0,     3,     0,
       3,     0,     4,     0,     2,     0,     2,     0,     3,     2,
       1,     2,     5,     0,     2,     2,     2,     5,     6,     0,
       1,    11,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    15,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     2,     1,     1,     1,     9,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       0,     1,     7,     0,     2,    14,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    10,     0,     2,     1,     1,
       1,     1,     1,     1,    10,     0,     2,     1,     1,    10,
       0,     2,     1,     9,     0,     2,     1,     5,     6,     5,
       6,     0,     1,     9,     0,     2,     1,     1,     7,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     2,     7,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     6,     0,     2,     1,     1,     5,     9,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,    13,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,     0,     2,     1,     1,    13,     0,
       2,     6,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     7,     1,     2,     1,     1,     6,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       8,     0,     2,     1,     1,     1,     1,     5,     5,    12,
       0,     2,     1,     1,     5,     5,    14,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     8,     0,     2,     1,
      13,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    13,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     8,     0,     2,
       1,     1,     1,     1,     9,     0,     2,     1,     1,     1,
       6,     0,     2,     1,     1,     5,     7,     0,     1,     7,
       0,     2,     1,     1,     5,     5,     0,     2,     1,     1,
       1,     1,     1,     5,     6,     1,     3,     3,     2,     2,
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
  "AXIS_RESCALE_X", "BIT_MASK", "BIT_OPERATION", "BLOB", "BYTE_ORDER",
  "CALIBRATION_ACCESS", "CALIBRATION_HANDLE", "CALIBRATION_HANDLE_TEXT",
  "CALIBRATION_METHOD", "CHARACTERISTIC", "COEFFS", "COEFFS_LINEAR",
  "COMPARISON_QUANTITY", "COMPU_METHOD", "COMPU_TAB", "COMPU_TAB_REF",
  "COMPU_VTAB", "COMPU_VTAB_RANGE", "CONSISTENT_EXCHANGE", "CONVERSION",
  "CPU_TYPE", "CURVE_AXIS_REF", "CUSTOMER", "CUSTOMER_NO", "DATA_SIZE",
  "DEF_CHARACTERISTIC", "DEFAULT_VALUE", "DEFAULT_VALUE_NUMERIC",
  "DEPENDENT_CHARACTERISTIC", "DEPOSIT", "DISCRETE", "DISPLAY_IDENTIFIER",
  "DIST_OP_X", "DIST_OP_Y", "DIST_OP_Z", "DIST_OP_4", "DIST_OP_5", "ECU",
  "ECU_ADDRESS", "ECU_ADDRESS_EXTENSION", "ECU_CALIBRATION_OFFSET",
  "ENCODING", "EPK", "ERROR_MASK", "EXTENDED_LIMITS", "FIX_AXIS_PAR",
  "FIX_AXIS_PAR_DIST", "FIX_AXIS_PAR_LIST", "FIX_NO_AXIS_PTS_X",
  "FIX_NO_AXIS_PTS_Y", "FIX_NO_AXIS_PTS_Z", "FIX_NO_AXIS_PTS_4",
  "FIX_NO_AXIS_PTS_5", "FNC_VALUES", "FORMAT", "FORMULA", "FORMULA_INV",
  "FRAME", "FRAME_MEASUREMENT", "FUNCTION", "FUNCTION_LIST",
  "FUNCTION_VERSION", "GROUP", "GUARD_RAILS", "HEADER", "IDENTIFICATION",
  "IF_DATA", "IN_MEASUREMENT", "INPUT_QUANTITY", "INSTANCE", "LAYOUT",
  "LEFT_SHIFT", "LIMITS", "LOC_MEASUREMENT", "MAP_LIST", "MATRIX_DIM",
  "MAX_GRAD", "MAX_REFRESH", "MEASUREMENT", "MEMORY_LAYOUT",
  "MEMORY_SEGMENT", "MODULE", "MOD_COMMON", "MOD_PAR", "MODEL_LINK",
  "MONOTONY", "NO_AXIS_PTS_X", "NO_AXIS_PTS_Y", "NO_AXIS_PTS_Z",
  "NO_AXIS_PTS_4", "NO_AXIS_PTS_5", "NO_OF_INTERFACES", "NO_RESCALE_X",
  "NUMBER", "OFFSET_X", "OFFSET_Y", "OFFSET_Z", "OFFSET_4", "OFFSET_5",
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
       0,   432,   432,   433,   435,   436,   437,   439,   440,   441,
     442,   444,   445,   447,   448,   450,   451,   453,   454,   456,
     457,   459,   460,   464,   465,   467,   468,   470,   471,   473,
     475,   476,   478,   479,   480,   481,   482,   484,   486,   491,
     492,   494,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   522,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   558,   563,   564,   565,   566,   567,   569,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   588,
     592,   593,   595,   601,   602,   607,   620,   621,   622,   623,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   652,   661,   662,   663,   664,
     665,   666,   671,   672,   674,   683,   684,   685,   686,   688,
     697,   698,   699,   701,   709,   710,   711,   713,   715,   718,
     720,   721,   722,   724,   731,   732,   733,   734,   736,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   754,   755,   757,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   773,   778,   779,   781,   784,   789,   791,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   812,   813,   815,   817,   819,   831,   832,
     833,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     853,   854,   855,   857,   864,   865,   870,   871,   873,   885,
     886,   890,   895,   896,   897,   898,   899,   900,   901,   902,
     903,   904,   905,   906,   907,   909,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   932,   938,   939,   940,   941,   944,
     947,   950,   953,   956,   959,   962,   965,   968,   971,   974,
     977,   980,   981,   982,   985,   988,   991,   994,   997,  1000,
    1003,  1006,  1009,  1011,  1013,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1028,  1033,  1034,  1035,  1036,  1041,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1103,  1104,  1105,
    1107,  1114,  1115,  1116,  1117,  1118,  1119,  1121,  1122,  1124,
    1135,  1136,  1137,  1138,  1140,  1141,  1143,  1156,  1157,  1158,
    1159,  1160,  1161,  1162,  1163,  1164,  1166,  1172,  1173,  1174,
    1176,  1188,  1189,  1190,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1205,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1224,  1225,  1226,  1227,  1228,  1230,  1237,  1238,
    1239,  1240,  1241,  1244,  1246,  1253,  1254,  1255,  1256,  1257,
    1262,  1266,  1267,  1268,  1269,  1271,  1273,  1279,  1280,  1282,
    1289,  1290,  1291,  1292,  1294,  1296,  1297,  1298,  1299,  1303,
    1307,  1311,  1315,  1320,  1321,  1325,  1326,  1331,  1334,  1338,
    1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,
    1349,  1350,  1351,  1352,  1358,  1364,  1370,  1376,  1382,  1389,
    1390,  1391,  1392,  1393,  1403,  1409,  1410,  1411,  1412,  1413,
    1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,  1428,  1432,  1436,  1440,  1444,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1465,  1466,  1467,  1468,  1469,  1470,  1474,  1475,  1476,
    1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1488,  1492,
    1496,  1500,  1504,  1505,  1509,  1510,  1514,  1518,  1522,  1526,
    1530,  1531,  1532,  1533,  1534,  1536,  1537,  1538,  1539,  1540,
    1544,  1545,  1549,  1553,  1557,  1561,  1565,  1569,  1570,  1571,
    1575,  1579,  1583,  1587,  1591,  1592,  1601,  1605,  1609,  1613,
    1617,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1631,  1632,  1633,  1634,  1635
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
     205,   206,   207,   208
    };
    // Last valid token kind.
    const int code_max = 463;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "D:/projects/a2llib/src/a2lparser.y"
} // a2l
#line 7829 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1637 "D:/projects/a2llib/src/a2lparser.y"


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
