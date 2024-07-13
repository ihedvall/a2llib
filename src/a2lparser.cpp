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
#line 433 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2822 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 434 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2828 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_int: INT
#line 436 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2834 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: UINT
#line 437 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2840 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: HEX
#line 438 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2846 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_float: FLOAT
#line 440 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2852 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: INT
#line 441 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 2858 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: UINT
#line 442 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2864 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: HEX
#line 443 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 2870 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // int_list: %empty
#line 445 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 2876 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: int_list any_int
#line 446 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::vector<int64_t> > () = yystack_[1].value.as < std::vector<int64_t> > (); yylhs.value.as < std::vector<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); }
#line 2882 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // uint_list: %empty
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 2888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: uint_list any_uint
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                       {yylhs.value.as < std::vector<uint64_t> > () = yystack_[1].value.as < std::vector<uint64_t> > (); yylhs.value.as < std::vector<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 2894 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // float_list: %empty
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2900 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: float_list any_float
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < std::vector<double> > () = yystack_[1].value.as < std::vector<double> > (); yylhs.value.as < std::vector<double> > ().emplace_back(yystack_[0].value.as < double > ()); }
#line 2906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_pair_list: %empty
#line 454 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 2912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: float_pair_list any_float any_float
#line 455 "D:/projects/a2llib/src/a2lparser.y"
                                              {yylhs.value.as < std::map<double, double> > () = yystack_[2].value.as < std::map<double, double> > (); yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 2918 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_string_list: %empty
#line 457 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: float_string_list any_float STRING
#line 458 "D:/projects/a2llib/src/a2lparser.y"
                                             {yylhs.value.as < std::map<double, std::string> > () = yystack_[2].value.as < std::map<double, std::string> > (); yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); }
#line 2930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_range_list: %empty
#line 460 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 2936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: float_range_list any_float any_float STRING
#line 461 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ();
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ()); }
#line 2944 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // string_list: %empty
#line 465 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 2950 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: string_list STRING
#line 466 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); }
#line 2956 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // ident_list: %empty
#line 468 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 2962 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: ident_list IDENT
#line 469 "D:/projects/a2llib/src/a2lparser.y"
                           {yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); }
#line 2968 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // key_value_list: %empty
#line 471 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 2974 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: key_value_list IDENT IDENT
#line 472 "D:/projects/a2llib/src/a2lparser.y"
                                     {yylhs.value.as < std::map<std::string, std::string> > () = yystack_[2].value.as < std::map<std::string, std::string> > (); yylhs.value.as < std::map<std::string, std::string> > ().emplace(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); }
#line 2980 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 480 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = yystack_[2].value.as < A2lAnnotation > ();}
#line 2986 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation_attributes: %empty
#line 481 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 2992 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: annotation_attributes annotation_label
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Label = yystack_[0].value.as < std::string > ();}
#line 2998 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_origin
#line 483 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Origin = yystack_[0].value.as < std::string > ();}
#line 3004 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_attributes: annotation_attributes annotation_text
#line 484 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Text = yystack_[0].value.as < std::vector<std::string> > ();}
#line 3010 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 38: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 3016 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 39: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 3026 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 40: // ar_component_attribute: %empty
#line 493 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 3032 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // ar_component_attribute: ar_prototype_of
#line 494 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3038 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 497 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 3052 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // axis_descr_attribute: annotation
#line 508 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3058 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: axis_pts_ref
#line 509 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 3064 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: byte_order
#line 510 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3070 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: curve_axis_ref
#line 511 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 3076 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: deposit
#line 512 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3082 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: extended_limits
#line 513 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3088 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: fix_axis_par
#line 514 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 3094 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par_dist
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 3100 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: fix_axis_par_list
#line 516 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::vector<double> > ()); }
#line 3106 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: format
#line 517 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 3112 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: max_grad
#line 518 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 3118 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: monotony
#line 519 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3124 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: phys_unit
#line 520 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3130 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: read_only
#line 521 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 3136 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: step_size
#line 522 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 3142 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 525 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3160 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_pts_attribute: annotation
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3166 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: byte_order
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3172 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: calibration_access
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: deposit
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 3184 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: display_identifier
#line 544 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3190 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: ecu_address_extension
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3196 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: extended_limits
#line 546 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3202 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: format
#line 547 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 3208 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: function_list
#line 548 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3214 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: guard_rails
#line 549 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 3220 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: if_data
#line 550 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3226 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: max_refresh
#line 551 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3232 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: model_link
#line 552 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3238 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: monotony
#line 553 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3244 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: phys_unit
#line 554 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: read_only
#line 555 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 3256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: ref_memory_segment
#line 556 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: step_size
#line 557 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 3268 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: symbol_link
#line 558 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3274 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 82: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 560 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 3284 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // bit_operation_attribute: left_shift
#line 567 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 3290 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // bit_operation_attribute: right_shift
#line 568 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 3296 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // bit_operation_attribute: sign_extend
#line 569 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 3302 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 571 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 3314 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 91: // blob_attribute: address_type
#line 580 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3320 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: annotation
#line 581 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3326 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: calibration_access
#line 582 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3332 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: display_identifier
#line 583 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3338 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: ecu_address_extension
#line 584 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3344 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: if_data
#line 585 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3350 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: max_refresh
#line 586 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3356 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: model_link
#line 587 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: symbol_link
#line 588 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3368 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 100: // calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE
#line 590 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                  {
	yylhs.value.as < A2lCalibrationHandle > ().HandleList = yystack_[3].value.as < std::vector<int64_t> > ();
	yylhs.value.as < A2lCalibrationHandle > ().Comment = yystack_[2].value.as < std::string > ();
}
#line 3377 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 101: // calibration_handle_attribute: %empty
#line 594 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 3383 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 102: // calibration_handle_attribute: calibration_handle_text
#line 595 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 103: // calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint calibration_method_attributes A2L_END CALIBRATION_METHOD
#line 598 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	yylhs.value.as < A2lCalibrationMethod > ().Method = yystack_[4].value.as < std::string > ();
	yylhs.value.as < A2lCalibrationMethod > ().Version = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lCalibrationMethod > ().CalibrationHandleList = yystack_[2].value.as < std::vector<A2lCalibrationHandle> > ();
	}
#line 3399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 104: // calibration_method_attributes: %empty
#line 603 "D:/projects/a2llib/src/a2lparser.y"
                                      {}
#line 3405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // calibration_method_attributes: calibration_method_attributes calibration_handle
#line 604 "D:/projects/a2llib/src/a2lparser.y"
                                                           {
	yylhs.value.as < std::vector<A2lCalibrationHandle> > () = yystack_[1].value.as < std::vector<A2lCalibrationHandle> > ();
	yylhs.value.as < std::vector<A2lCalibrationHandle> > ().emplace_back(yystack_[0].value.as < A2lCalibrationHandle > ());
	}
#line 3414 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 610 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // characteristic_attribute: annotation
#line 624 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3437 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: axis_descr
#line 625 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 3445 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: bit_mask
#line 628 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3451 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: byte_order
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3457 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: calibration_access
#line 630 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3463 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: comparison_quantity
#line 631 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 3469 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: dependent_characteristic
#line 632 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3475 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: discrete
#line 633 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 3481 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: display_identifier
#line 634 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3487 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: ecu_address_extension
#line 635 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3493 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: encoding
#line 636 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 3499 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: extended_limits
#line 637 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3505 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: format
#line 638 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 3511 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: function_list
#line 639 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3517 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: guard_rails
#line 640 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 3523 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: if_data
#line 641 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3529 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: map_list
#line 642 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3535 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: matrix_dim
#line 643 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 3541 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: max_refresh
#line 644 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3547 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: model_link
#line 645 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3553 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: number
#line 646 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 3559 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: phys_unit
#line 647 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3565 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: read_only
#line 648 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 3571 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: ref_memory_segment
#line 649 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3577 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: step_size
#line 650 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 3583 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: symbol_link
#line 651 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3589 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: virtual_characteristic
#line 652 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 3595 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 136: // compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 654 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 3608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // compu_method_attribute: coeffs
#line 665 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::vector<double> > ()); }
#line 3614 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // compu_method_attribute: coeffs_linear
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::vector<double> > ()); }
#line 3620 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // compu_method_attribute: compu_tab_ref
#line 667 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 3626 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // compu_method_attribute: formula
#line 668 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 3636 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // compu_method_attribute: ref_unit
#line 673 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 3642 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_method_attribute: status_string_ref
#line 674 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 3648 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 145: // compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 677 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, double> > ());
	}
#line 3661 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_tab_attribute: default_value
#line 687 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3667 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_tab_attribute: default_value_numeric
#line 688 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 3673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 150: // compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 691 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, std::string> > ());
	}
#line 3686 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 153: // compu_vtab_attribute: default_value
#line 701 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3692 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 154: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 704 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 3704 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // compu_vtab_range_attribute: default_value
#line 713 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtabRange().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 3710 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // controller_address: any_uint IDENT any_uint any_uint
#line 720 "D:/projects/a2llib/src/a2lparser.y"
                                                     {
    A2lControllerAddress address;
    address.Index = yystack_[3].value.as < uint64_t > ();
    address.ByteOrder = StringToByteOrder(yystack_[2].value.as < std::string > ());
    address.StartAddress = yystack_[1].value.as < uint64_t > ();
    address.Length = yystack_[0].value.as < uint64_t > ();
    auto& module = scanner.CurrentModule();
    module.AddControllerAddress(address);
    }
#line 3724 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 730 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3730 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 163: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 733 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 3736 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 164: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 735 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::vector<double> > () = yystack_[2].value.as < std::vector<double> > (); }
#line 3742 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 165: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 737 "D:/projects/a2llib/src/a2lparser.y"
                                                                    { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()}; }
#line 3748 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 166: // formula_attribute: %empty
#line 738 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 3754 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 167: // formula_attribute: formula_inv
#line 739 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3760 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 168: // frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 741 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 3772 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // frame_attribute: frame_measurement
#line 750 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3778 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 172: // frame_attribute: if_data
#line 751 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3784 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 753 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 3794 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // function_attribute: annotation
#line 760 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 3800 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 178: // function_attribute: def_characteristic
#line 762 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3806 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 179: // function_attribute: function_version
#line 763 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 3812 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 180: // function_attribute: if_data
#line 764 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 3818 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // function_attribute: in_measurement
#line 765 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3824 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // function_attribute: loc_measurement
#line 766 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3830 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function_attribute: out_measurement
#line 767 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3836 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 184: // function_attribute: ref_characteristic
#line 768 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3842 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 185: // function_attribute: sub_function
#line 769 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::vector<std::string> > ());}
#line 3848 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 771 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 3854 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 187: // function_list: FUNCTION_LIST ident_list
#line 772 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 3860 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 774 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 3870 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // group_attribute: annotation
#line 782 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3876 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 192: // group_attribute: function_list
#line 783 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3882 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // group_attribute: if_data
#line 784 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 194: // group_attribute: ref_characteristic
#line 785 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3894 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // group_attribute: ref_measurement
#line 786 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3900 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // group_attribute: root
#line 787 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 3906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // group_attribute: sub_group
#line 788 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 790 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = yystack_[3].value.as < std::string > ();
}
#line 3921 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 201: // header_attribute: project_no
#line 798 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 3930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 202: // header_attribute: version
#line 801 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 3939 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 806 "D:/projects/a2llib/src/a2lparser.y"
                                                                           { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 808 "D:/projects/a2llib/src/a2lparser.y"
                                                                                              {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 3957 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // instance_attribute: address_type
#line 817 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3963 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // instance_attribute: annotation
#line 818 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 209: // instance_attribute: calibration_access
#line 819 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 3975 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 210: // instance_attribute: display_identifier
#line 820 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3981 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // instance_attribute: ecu_address_extension
#line 821 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3987 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // instance_attribute: if_data
#line 822 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3993 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // instance_attribute: layout
#line 823 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 3999 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // instance_attribute: matrix_dim
#line 824 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 4005 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // instance_attribute: max_refresh
#line 825 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4011 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 216: // instance_attribute: model_link
#line 826 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4017 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // instance_attribute: overwrite
#line 827 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 4024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // instance_attribute: read_write
#line 829 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 4030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 219: // instance_attribute: symbol_link
#line 830 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 832 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 4042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 834 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 4048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 837 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4064 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // measurement_attribute: address_type
#line 850 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 4070 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // measurement_attribute: annotation
#line 851 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 4076 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // measurement_attribute: array_size
#line 852 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 4082 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 228: // measurement_attribute: bit_mask
#line 853 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 4088 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // measurement_attribute: bit_operation
#line 854 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 4094 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // measurement_attribute: byte_order
#line 855 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 4100 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // measurement_attribute: discrete
#line 856 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 4106 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // measurement_attribute: display_identifier
#line 857 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 4112 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // measurement_attribute: ecu_address
#line 858 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 4118 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement_attribute: ecu_address_extension
#line 859 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 4124 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 235: // measurement_attribute: error_mask
#line 860 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 4130 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 236: // measurement_attribute: format
#line 861 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 4136 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: function_list
#line 862 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 4142 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: if_data
#line 863 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4148 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: layout
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 4154 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: matrix_dim
#line 865 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 4160 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: max_refresh
#line 866 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 4166 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: model_link
#line 867 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 4172 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 243: // measurement_attribute: phys_unit
#line 868 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 244: // measurement_attribute: read_write
#line 869 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 4184 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 245: // measurement_attribute: ref_memory_segment
#line 870 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 4190 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 246: // measurement_attribute: symbol_link
#line 871 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 4196 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 247: // measurement_attribute: virtual
#line 872 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 4202 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 248: // memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list memory_layout_attributes A2L_END MEMORY_LAYOUT
#line 875 "D:/projects/a2llib/src/a2lparser.y"
                                                       {
	yylhs.value.as < A2lMemoryLayout > ().Type = StringToPrgType(yystack_[6].value.as < std::string > ());
	yylhs.value.as < A2lMemoryLayout > ().Address = yystack_[5].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().Size = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lMemoryLayout > ().OffsetList = yystack_[3].value.as < std::vector<int64_t> > ();
	}
#line 4213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 249: // memory_layout_attributes: %empty
#line 881 "D:/projects/a2llib/src/a2lparser.y"
                                 {}
#line 4219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 250: // memory_layout_attributes: memory_layout_attributes if_data
#line 882 "D:/projects/a2llib/src/a2lparser.y"
                                           {
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[1].value.as < std::map<std::string, std::string> > ();
        yylhs.value.as < std::map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
        }
#line 4228 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 251: // prg_type: RESERVED
#line 887 "D:/projects/a2llib/src/a2lparser.y"
                   {yylhs.value.as < A2lSegmentType > () = A2lSegmentType::RESERVED; }
#line 4234 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 252: // prg_type: IDENT
#line 888 "D:/projects/a2llib/src/a2lparser.y"
                {yylhs.value.as < A2lSegmentType > () = StringToSegmentType(yystack_[0].value.as < std::string > ()); }
#line 4240 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 253: // memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list memory_segment_attributes A2L_END MEMORY_SEGMENT
#line 891 "D:/projects/a2llib/src/a2lparser.y"
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
#line 4256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 254: // memory_segment_attributes: %empty
#line 902 "D:/projects/a2llib/src/a2lparser.y"
                                  {}
#line 4262 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 255: // memory_segment_attributes: memory_segment_attributes if_data
#line 903 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < std::map<std::string, std::string> > () = yystack_[1].value.as < std::map<std::string, std::string> > ();
	yylhs.value.as < std::map<std::string, std::string> > ().emplace(A2lHelper::ParseIfDataProtocol(yystack_[0].value.as < std::string > ()), yystack_[0].value.as < std::string > ());
	}
#line 4271 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 256: // mod_common: A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON
#line 907 "D:/projects/a2llib/src/a2lparser.y"
                                                                                  {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = yystack_[3].value.as < std::string > ();
}
#line 4280 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 259: // mod_common_attribute: alignment_byte
#line 914 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentModule().ModCommon().AlignmentByte = yystack_[0].value.as < uint64_t > (); }
#line 4286 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 260: // mod_common_attribute: alignment_float16_ieee
#line 915 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat16 = yystack_[0].value.as < uint64_t > (); }
#line 4292 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 261: // mod_common_attribute: alignment_float32_ieee
#line 916 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat32 = yystack_[0].value.as < uint64_t > (); }
#line 4298 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 262: // mod_common_attribute: alignment_float64_ieee
#line 917 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModCommon().AlignmentFloat64 = yystack_[0].value.as < uint64_t > (); }
#line 4304 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 263: // mod_common_attribute: alignment_int64
#line 918 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModCommon().AlignmentInt64 = yystack_[0].value.as < uint64_t > (); }
#line 4310 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 264: // mod_common_attribute: alignment_long
#line 919 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentLong = yystack_[0].value.as < uint64_t > (); }
#line 4316 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 265: // mod_common_attribute: alignment_word
#line 920 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModCommon().AlignmentWord = yystack_[0].value.as < uint64_t > (); }
#line 4322 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 266: // mod_common_attribute: byte_order
#line 921 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentModule().ModCommon().ByteOrder = yystack_[0].value.as < A2lByteOrder > (); }
#line 4328 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 267: // mod_common_attribute: data_size
#line 922 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentModule().ModCommon().DataSize = yystack_[0].value.as < uint64_t > (); }
#line 4334 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 268: // mod_common_attribute: deposit
#line 923 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModCommon().Deposit = yystack_[0].value.as < A2lDeposit > (); }
#line 4340 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 270: // mod_par: A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR
#line 926 "D:/projects/a2llib/src/a2lparser.y"
                                                                      {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = yystack_[3].value.as < std::string > ();
}
#line 4349 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 273: // mod_par_attribute: addr_epk
#line 932 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 4355 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 274: // mod_par_attribute: calibration_method
#line 933 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back(yystack_[0].value.as < A2lCalibrationMethod > ()); }
#line 4361 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 275: // mod_par_attribute: cpu_type
#line 934 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().CpuType = yystack_[0].value.as < std::string > (); }
#line 4367 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 276: // mod_par_attribute: customer
#line 935 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Customer = yystack_[0].value.as < std::string > (); }
#line 4373 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 277: // mod_par_attribute: customer_no
#line 936 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentModule().ModPar().CustomerNo = yystack_[0].value.as < std::string > (); }
#line 4379 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 278: // mod_par_attribute: ecu
#line 937 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Ecu = yystack_[0].value.as < std::string > (); }
#line 4385 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 279: // mod_par_attribute: ecu_calibration_offset
#line 938 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentModule().ModPar().EcuCalibrationOffset = yystack_[0].value.as < int64_t > (); }
#line 4391 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 280: // mod_par_attribute: epk
#line 939 "D:/projects/a2llib/src/a2lparser.y"
              { scanner.CurrentModule().ModPar().Epk = yystack_[0].value.as < std::string > (); }
#line 4397 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 281: // mod_par_attribute: memory_layout
#line 940 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back(yystack_[0].value.as < A2lMemoryLayout > ()); }
#line 4403 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 282: // mod_par_attribute: memory_segment
#line 941 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back(yystack_[0].value.as < A2lMemorySegment > ()); }
#line 4409 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 283: // mod_par_attribute: no_of_interfaces
#line 942 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentModule().ModPar().NoOfInterfaces = yystack_[0].value.as < uint64_t > (); }
#line 4415 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // mod_par_attribute: phone_no
#line 943 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().PhoneNo = yystack_[0].value.as < std::string > (); }
#line 4421 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 285: // mod_par_attribute: supplier
#line 944 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentModule().ModPar().Supplier = yystack_[0].value.as < std::string > (); }
#line 4427 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 286: // mod_par_attribute: system_constant
#line 945 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentModule().ModPar().SystemConstantList.emplace(yystack_[0].value.as < std::pair<std::string,std::string> > ().first, yystack_[0].value.as < std::pair<std::string,std::string> > ().second); }
#line 4433 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // mod_par_attribute: user
#line 946 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentModule().ModPar().User = yystack_[0].value.as < std::string > (); }
#line 4439 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // mod_par_attribute: version
#line 947 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentModule().ModPar().Version = yystack_[0].value.as < std::string > (); }
#line 4445 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE
#line 949 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
	auto& module = scanner.CurrentModule();
	module.Name(yystack_[4].value.as < std::string > ());
	module.Description(yystack_[3].value.as < std::string > ());
}
#line 4455 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // module_attribute: a2ml
#line 957 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 4461 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // module_attribute: axis_pts
#line 958 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 4469 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // module_attribute: blob
#line 961 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 4477 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // module_attribute: characteristic
#line 964 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 4485 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // module_attribute: compu_method
#line 967 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 4493 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // module_attribute: compu_tab
#line 970 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 4501 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // module_attribute: compu_vtab
#line 973 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 4509 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // module_attribute: compu_vtab_range
#line 976 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 4517 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // module_attribute: controller_addresses
#line 979 "D:/projects/a2llib/src/a2lparser.y"
                               {}
#line 4523 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 301: // module_attribute: frame
#line 980 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 4531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 302: // module_attribute: function
#line 983 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 4539 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 303: // module_attribute: group
#line 986 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 4547 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 304: // module_attribute: if_data
#line 989 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 4555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 305: // module_attribute: instance
#line 992 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 4563 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 306: // module_attribute: measurement
#line 995 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 4571 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 309: // module_attribute: record_layout
#line 1000 "D:/projects/a2llib/src/a2lparser.y"
                        {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
#line 4579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 310: // module_attribute: transformer
#line 1003 "D:/projects/a2llib/src/a2lparser.y"
                      {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
#line 4587 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 311: // module_attribute: typedef_axis
#line 1006 "D:/projects/a2llib/src/a2lparser.y"
                       {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
#line 4595 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 312: // module_attribute: typedef_blob
#line 1009 "D:/projects/a2llib/src/a2lparser.y"
                       {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
#line 4603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // module_attribute: typedef_characteristic
#line 1012 "D:/projects/a2llib/src/a2lparser.y"
                                 {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
#line 4611 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // module_attribute: typedef_measurement
#line 1015 "D:/projects/a2llib/src/a2lparser.y"
                              {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
#line 4619 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 315: // module_attribute: typedef_structure
#line 1018 "D:/projects/a2llib/src/a2lparser.y"
                            {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
#line 4627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 316: // module_attribute: unit
#line 1021 "D:/projects/a2llib/src/a2lparser.y"
               {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
#line 4635 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // module_attribute: user_rights
#line 1024 "D:/projects/a2llib/src/a2lparser.y"
                      {
          auto& module = scanner.CurrentModule();
          module.AddUserRight(scanner.ReleaseUserRight()); }
#line 4643 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 1029 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 4649 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 1031 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 4659 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // overwrite_attribute: conversion
#line 1038 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 4665 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 324: // overwrite_attribute: extended_limits
#line 1039 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 4671 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 325: // overwrite_attribute: format
#line 1040 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 4677 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 326: // overwrite_attribute: input_quantity
#line 1041 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 4683 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 327: // overwrite_attribute: limits
#line 1042 "D:/projects/a2llib/src/a2lparser.y"
                 {
	    scanner.CurrentOverwrite().LowerLimit(yystack_[0].value.as < A2lLimits > ().LowerLimit);
	    scanner.CurrentOverwrite().UpperLimit(yystack_[0].value.as < A2lLimits > ().UpperLimit);
	    }
#line 4692 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // overwrite_attribute: monotony
#line 1046 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 4698 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 329: // overwrite_attribute: phys_unit
#line 1047 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 4704 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 330: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 1049 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 4714 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 334: // project_attribute: module
#line 1059 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 4723 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 335: // record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT
#line 1064 "D:/projects/a2llib/src/a2lparser.y"
                                                                                            {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name(yystack_[3].value.as < std::string > ());
}
#line 4732 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 338: // record_layout_attribute: alignment_byte
#line 1070 "D:/projects/a2llib/src/a2lparser.y"
                                        { scanner.CurrentRecordLayout().AlignmentByte(yystack_[0].value.as < uint64_t > ()); }
#line 4738 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 339: // record_layout_attribute: alignment_float16_ieee
#line 1071 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat16(yystack_[0].value.as < uint64_t > ()); }
#line 4744 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 340: // record_layout_attribute: alignment_float32_ieee
#line 1072 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat32(yystack_[0].value.as < uint64_t > ()); }
#line 4750 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 341: // record_layout_attribute: alignment_float64_ieee
#line 1073 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().AlignmentFloat64(yystack_[0].value.as < uint64_t > ()); }
#line 4756 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 342: // record_layout_attribute: alignment_int64
#line 1074 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentRecordLayout().AlignmentInt64(yystack_[0].value.as < uint64_t > ()); }
#line 4762 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 343: // record_layout_attribute: alignment_long
#line 1075 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentLong(yystack_[0].value.as < uint64_t > ()); }
#line 4768 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 344: // record_layout_attribute: alignment_word
#line 1076 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AlignmentWord(yystack_[0].value.as < uint64_t > ()); }
#line 4774 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 345: // record_layout_attribute: axis_pts_x
#line 1077 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsX(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4780 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 346: // record_layout_attribute: axis_pts_y
#line 1078 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsY(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4786 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 347: // record_layout_attribute: axis_pts_z
#line 1079 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPtsZ(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4792 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 348: // record_layout_attribute: axis_pts_4
#line 1080 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts4(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4798 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 349: // record_layout_attribute: axis_pts_5
#line 1081 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().AxisPts5(yystack_[0].value.as < A2lAxisPts > ()); }
#line 4804 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 350: // record_layout_attribute: axis_rescale_x
#line 1082 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().AxisRescaleX(yystack_[0].value.as < A2lAxisRescale > ()); }
#line 4810 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 351: // record_layout_attribute: dist_op_x
#line 1083 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4816 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 352: // record_layout_attribute: dist_op_y
#line 1084 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4822 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 353: // record_layout_attribute: dist_op_z
#line 1085 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4828 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 354: // record_layout_attribute: dist_op_4
#line 1086 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4834 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 355: // record_layout_attribute: dist_op_5
#line 1087 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentRecordLayout().DistOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4840 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 356: // record_layout_attribute: fix_no_axis_pts_x
#line 1088 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsX(yystack_[0].value.as < uint64_t > ()); }
#line 4846 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 357: // record_layout_attribute: fix_no_axis_pts_y
#line 1089 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsY(yystack_[0].value.as < uint64_t > ()); }
#line 4852 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 358: // record_layout_attribute: fix_no_axis_pts_z
#line 1090 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPtsZ(yystack_[0].value.as < uint64_t > ()); }
#line 4858 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 359: // record_layout_attribute: fix_no_axis_pts_4
#line 1091 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts4(yystack_[0].value.as < uint64_t > ()); }
#line 4864 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 360: // record_layout_attribute: fix_no_axis_pts_5
#line 1092 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentRecordLayout().FixNoAxisPts5(yystack_[0].value.as < uint64_t > ()); }
#line 4870 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 361: // record_layout_attribute: fnc_values
#line 1093 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().FncValues(yystack_[0].value.as < A2lFncValue > ()); }
#line 4876 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 362: // record_layout_attribute: identification
#line 1094 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentRecordLayout().Identification(yystack_[0].value.as < A2lIdentification > ()); }
#line 4882 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 363: // record_layout_attribute: no_axis_pts_x
#line 1095 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 364: // record_layout_attribute: no_axis_pts_y
#line 1096 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4894 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 365: // record_layout_attribute: no_axis_pts_z
#line 1097 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPtsZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4900 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 366: // record_layout_attribute: no_axis_pts_4
#line 1098 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 367: // record_layout_attribute: no_axis_pts_5
#line 1099 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentRecordLayout().NoAxisPts5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 368: // record_layout_attribute: no_rescale_x
#line 1100 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentRecordLayout().NoRescaleX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4918 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 369: // record_layout_attribute: offset_x
#line 1101 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 370: // record_layout_attribute: offset_y
#line 1102 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 371: // record_layout_attribute: offset_z
#line 1103 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().OffsetZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 372: // record_layout_attribute: offset_4
#line 1104 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4942 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 373: // record_layout_attribute: offset_5
#line 1105 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().Offset5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4948 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 374: // record_layout_attribute: reserved
#line 1106 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentRecordLayout().AddReserved(yystack_[0].value.as < A2lDistOp > ()); }
#line 4954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 375: // record_layout_attribute: rip_addr_w
#line 1107 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrW(yystack_[0].value.as < A2lDistOp > ()); }
#line 4960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 376: // record_layout_attribute: rip_addr_x
#line 1108 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4966 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 377: // record_layout_attribute: rip_addr_y
#line 1109 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 4972 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 378: // record_layout_attribute: rip_addr_z
#line 1110 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 4978 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 379: // record_layout_attribute: rip_addr_4
#line 1111 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 4984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 380: // record_layout_attribute: rip_addr_5
#line 1112 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().RipAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 4990 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 381: // record_layout_attribute: src_addr_x
#line 1113 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrX(yystack_[0].value.as < A2lDistOp > ()); }
#line 4996 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 382: // record_layout_attribute: src_addr_y
#line 1114 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5002 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 383: // record_layout_attribute: src_addr_z
#line 1115 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddrZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5008 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 384: // record_layout_attribute: src_addr_4
#line 1116 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5014 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 385: // record_layout_attribute: src_addr_5
#line 1117 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().SrcAddr5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5020 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 386: // record_layout_attribute: shift_op_x
#line 1118 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpX(yystack_[0].value.as < A2lDistOp > ()); }
#line 5026 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // record_layout_attribute: shift_op_y
#line 1119 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpY(yystack_[0].value.as < A2lDistOp > ()); }
#line 5032 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // record_layout_attribute: shift_op_z
#line 1120 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOpZ(yystack_[0].value.as < A2lDistOp > ()); }
#line 5038 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // record_layout_attribute: shift_op_4
#line 1121 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp4(yystack_[0].value.as < A2lDistOp > ()); }
#line 5044 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 390: // record_layout_attribute: shift_op_5
#line 1122 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentRecordLayout().ShiftOp5(yystack_[0].value.as < A2lDistOp > ()); }
#line 5050 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 391: // record_layout_attribute: static_address_offsets
#line 1123 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
#line 5056 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 392: // record_layout_attribute: static_record_layout
#line 1124 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentRecordLayout().StaticRecordLayout(true); }
#line 5062 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 393: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 1126 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5068 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 394: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 1127 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5074 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 395: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 1128 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5080 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 396: // structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT
#line 1131 "D:/projects/a2llib/src/a2lparser.y"
                                                               {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = yystack_[5].value.as < std::string > ();
        structure.Typedef = yystack_[4].value.as < std::string > ();
        structure.AddressOffset = yystack_[3].value.as < uint64_t > ();
    }
#line 5091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 399: // structure_component_attribute: address_type
#line 1139 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentStructureComponent().AddressType = yystack_[0].value.as < A2lAddressType > (); }
#line 5097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 400: // structure_component_attribute: layout
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentStructureComponent().Layout = yystack_[0].value.as < A2lLayout > (); }
#line 5103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 401: // structure_component_attribute: matrix_dim
#line 1141 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentStructureComponent().MatrixDim = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 5109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 402: // structure_component_attribute: symbol_type_link
#line 1142 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentStructureComponent().SymbolTypeLink = yystack_[0].value.as < std::string > (); }
#line 5115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 403: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 1144 "D:/projects/a2llib/src/a2lparser.y"
                                                                     { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 404: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 1145 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5127 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 405: // transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER
#line 1148 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5142 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 408: // transformer_attribute: transformer_in_objects
#line 1160 "D:/projects/a2llib/src/a2lparser.y"
                                              { scanner.CurrentTransformer().TransformerInObjects(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5148 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 409: // transformer_attribute: transformer_out_objects
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                                  { scanner.CurrentTransformer().TransformerOutObjects(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5154 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 410: // transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5160 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 411: // transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                      { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5166 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 412: // typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS
#line 1167 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5183 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 415: // typedef_axis_attribute: byte_order
#line 1181 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentTypedefAxis().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5189 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 416: // typedef_axis_attribute: deposit
#line 1182 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentTypedefAxis().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 5195 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 417: // typedef_axis_attribute: extended_limits
#line 1183 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefAxis().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5201 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 418: // typedef_axis_attribute: format
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefAxis().Format(yystack_[0].value.as < std::string > ()); }
#line 5207 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 419: // typedef_axis_attribute: monotony
#line 1185 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefAxis().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 5213 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 420: // typedef_axis_attribute: phys_unit
#line 1186 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5219 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 421: // typedef_axis_attribute: step_size
#line 1187 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefAxis().StepSize(yystack_[0].value.as < double > ()); }
#line 5225 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 422: // typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB
#line 1189 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                        {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name(yystack_[5].value.as < std::string > ());
    blob.Description(yystack_[4].value.as < std::string > ());
    blob.Size(yystack_[3].value.as < uint64_t > ());
   }
#line 5236 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 425: // typedef_blob_attribute: address_type
#line 1197 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentTypedefBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 426: // typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC
#line 1200 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5258 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 429: // typedef_characteristic_attribute: axis_descr
#line 1213 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
#line 5267 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 430: // typedef_characteristic_attribute: bit_mask
#line 1217 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5273 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 431: // typedef_characteristic_attribute: byte_order
#line 1218 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5279 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 432: // typedef_characteristic_attribute: discrete
#line 1219 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Discrete(true); }
#line 5285 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 433: // typedef_characteristic_attribute: encoding
#line 1220 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 5291 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 434: // typedef_characteristic_attribute: extended_limits
#line 1221 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 5297 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 435: // typedef_characteristic_attribute: format
#line 1222 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 5303 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 436: // typedef_characteristic_attribute: matrix_dim
#line 1223 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 5309 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 437: // typedef_characteristic_attribute: number
#line 1224 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 5315 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 438: // typedef_characteristic_attribute: phys_unit
#line 1225 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5321 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 439: // typedef_characteristic_attribute: step_size
#line 1226 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 5327 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 440: // typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT UINT any_float any_float any_float typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT
#line 1229 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5343 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 443: // typedef_measurement_attribute: address_type
#line 1242 "D:/projects/a2llib/src/a2lparser.y"
                                            { scanner.CurrentTypedefMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5349 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 444: // typedef_measurement_attribute: bit_mask
#line 1243 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 5355 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 445: // typedef_measurement_attribute: bit_operation
#line 1244 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentTypedefMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 5361 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 446: // typedef_measurement_attribute: byte_order
#line 1245 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 5367 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 447: // typedef_measurement_attribute: discrete
#line 1246 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentTypedefMeasurement().Discrete(true); }
#line 5373 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 448: // typedef_measurement_attribute: error_mask
#line 1247 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 5379 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 449: // typedef_measurement_attribute: format
#line 1248 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 5385 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 450: // typedef_measurement_attribute: layout
#line 1249 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentTypedefMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 5391 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 451: // typedef_measurement_attribute: matrix_dim
#line 1250 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentTypedefMeasurement().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 5397 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 452: // typedef_measurement_attribute: phys_unit
#line 1251 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentTypedefMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 5403 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 453: // typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING UINT typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE
#line 1254 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name(yystack_[5].value.as < std::string > ());
		structure.Description(yystack_[4].value.as < std::string > ());
		structure.Size(yystack_[3].value.as < uint64_t > ());
		}
#line 5414 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 456: // typedef_structure_attribute: address_type
#line 1262 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentTypedefStructure().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 5420 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 457: // typedef_structure_attribute: consistent_exchange
#line 1263 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentTypedefStructure().ConsistentExchange(true); }
#line 5426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 458: // typedef_structure_attribute: structure_component
#line 1264 "D:/projects/a2llib/src/a2lparser.y"
                             {
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
#line 5434 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 459: // typedef_structure_attribute: symbol_type_link
#line 1267 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentTypedefStructure().SymbolTypeLink(yystack_[0].value.as < std::string > ()); }
#line 5440 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 460: // unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT
#line 1269 "D:/projects/a2llib/src/a2lparser.y"
                                                                            {
        auto& unit = scanner.CurrentUnit();
        unit.Name(yystack_[6].value.as < std::string > ());
        unit.Description(yystack_[5].value.as < std::string > ());
        unit.DisplayIdentifier(yystack_[4].value.as < std::string > ());
        unit.Type(StringToUnitType(yystack_[3].value.as < std::string > ()));
        }
#line 5452 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 463: // unit_attribute: ref_unit
#line 1278 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentUnit().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 5458 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 464: // unit_attribute: si_exponents
#line 1279 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentUnit().SiExponents(yystack_[0].value.as < A2lSiExponents > ()); }
#line 5464 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 465: // unit_attribute: unit_conversion
#line 1280 "D:/projects/a2llib/src/a2lparser.y"
                          {
	    scanner.CurrentUnit().Gradient(yystack_[0].value.as < std::pair<double,double> > ().first);
	    scanner.CurrentUnit().Offset(yystack_[0].value.as < std::pair<double,double> > ().second);
	    }
#line 5473 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 466: // user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS
#line 1285 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    {
       auto& user_right = scanner.CurrentUserRight();
       user_right.UserLevelId = yystack_[3].value.as < std::string > ();
       }
#line 5482 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 469: // user_rights_attribute: read_only
#line 1291 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentUserRight().ReadOnly = true; }
#line 5488 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 470: // user_rights_attribute: ref_group
#line 1292 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentUserRight().RefGroupList.emplace_back(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 5494 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 471: // var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS
#line 1294 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[2].value.as < std::vector<uint64_t> > (); }
#line 5500 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 472: // var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC
#line 1297 "D:/projects/a2llib/src/a2lparser.y"
                                                            {
    yylhs.value.as < A2lVarCharacteristic > ().Name = yystack_[4].value.as < std::string > ();
    yylhs.value.as < A2lVarCharacteristic > ().CriterionNameList = yystack_[3].value.as < std::vector<std::string> > ();
    yylhs.value.as < A2lVarCharacteristic > ().AddressList = yystack_[2].value.as < std::vector<uint64_t> > ();
    }
#line 5510 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 473: // var_characteristic_attribute: %empty
#line 1302 "D:/projects/a2llib/src/a2lparser.y"
                                     {}
#line 5516 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 474: // var_characteristic_attribute: var_address
#line 1303 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 5522 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 475: // var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION
#line 1305 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                   {
    yylhs.value.as < A2lVarCriterion > () = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    yylhs.value.as < A2lVarCriterion > ().Name = yystack_[4].value.as < std::string > ();
    yylhs.value.as < A2lVarCriterion > ().Description = yystack_[3].value.as < std::string > ();
}
#line 5533 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 478: // var_criterion_attribute: var_measurement
#line 1314 "D:/projects/a2llib/src/a2lparser.y"
                                         { scanner.VarCriterion().Measurement = yystack_[0].value.as < std::string > (); }
#line 5539 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 479: // var_criterion_attribute: var_selection_characteristic
#line 1315 "D:/projects/a2llib/src/a2lparser.y"
                                       { scanner.VarCriterion().SelectionCharacteristic = yystack_[0].value.as < std::string > (); }
#line 5545 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 480: // var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB
#line 1317 "D:/projects/a2llib/src/a2lparser.y"
                                                                                           { yylhs.value.as < std::map<std::string, std::string> > ()= yystack_[2].value.as < std::map<std::string, std::string> > (); }
#line 5551 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // variant_coding_attribute: var_characteristic
#line 1322 "D:/projects/a2llib/src/a2lparser.y"
                                             {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace(yystack_[0].value.as < A2lVarCharacteristic > ().Name, yystack_[0].value.as < A2lVarCharacteristic > ());
        }
#line 5560 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // variant_coding_attribute: var_criterion
#line 1326 "D:/projects/a2llib/src/a2lparser.y"
                       {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace(yystack_[0].value.as < A2lVarCriterion > ().Name, yystack_[0].value.as < A2lVarCriterion > ());
       }
#line 5569 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // variant_coding_attribute: var_forbidden_comb
#line 1330 "D:/projects/a2llib/src/a2lparser.y"
                            {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back(yystack_[0].value.as < std::map<std::string, std::string> > ());
       }
#line 5578 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 487: // variant_coding_attribute: var_naming
#line 1334 "D:/projects/a2llib/src/a2lparser.y"
                    {
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = yystack_[0].value.as < std::string > ();
       }
#line 5587 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // variant_coding_attribute: var_separator
#line 1338 "D:/projects/a2llib/src/a2lparser.y"
                       {
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = yystack_[0].value.as < std::string > ();
      }
#line 5596 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1343 "D:/projects/a2llib/src/a2lparser.y"
                                                      { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 5602 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1345 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 5608 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 491: // a2ml: A2ML
#line 1348 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5614 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1349 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 5623 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 493: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1354 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 5632 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 494: // asap2_version: ASAP2_VERSION STRING
#line 1357 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 5640 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 495: // addr_epk: ADDR_EPK any_uint
#line 1361 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5646 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 496: // address_type: ADDRESS_TYPE IDENT
#line 1362 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 5652 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 497: // alignment_byte: ALIGNMENT_BYTE any_uint
#line 1363 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5658 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint
#line 1364 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5664 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint
#line 1365 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5670 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint
#line 1366 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5676 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // alignment_int64: ALIGNMENT_INT64 any_uint
#line 1367 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5682 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 502: // alignment_long: ALIGNMENT_LONG any_uint
#line 1368 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5688 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 503: // alignment_word: ALIGNMENT_WORD any_uint
#line 1369 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5694 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // annotation_label: ANNOTATION_LABEL STRING
#line 1370 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5700 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 505: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1371 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5706 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 506: // array_size: ARRAY_SIZE any_uint
#line 1372 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5712 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 507: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1373 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 5718 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 508: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1374 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5724 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT
#line 1375 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5735 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT
#line 1381 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5746 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT
#line 1387 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5757 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT
#line 1393 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5768 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT
#line 1399 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lAxisPts > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisPts > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisPts > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5779 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT
#line 1405 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	yylhs.value.as < A2lAxisRescale > ().Position = yystack_[4].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().DataType = StringToDataType(yystack_[3].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().MaxNoRescalePairs = yystack_[2].value.as < uint64_t > ();
	yylhs.value.as < A2lAxisRescale > ().IndexOrder = StringToIndexOrder(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lAxisRescale > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
	}
#line 5791 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // bit_mask: BIT_MASK any_uint
#line 1412 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5797 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // byte_order: A2L_BYTE_ORDER IDENT
#line 1413 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 5803 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1414 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 5809 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING
#line 1415 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 519: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1416 "D:/projects/a2llib/src/a2lparser.y"
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
#line 5830 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1426 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::vector<double> list;
	list.push_back(yystack_[1].value.as < double > ());
	list.push_back(yystack_[0].value.as < double > ());
        yylhs.value.as < std::vector<double> > () = list;
}
#line 5841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 521: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1432 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1433 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5853 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // conversion: CONVERSION IDENT
#line 1435 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5859 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // cpu_type: CPU_TYPE STRING
#line 1436 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5865 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1437 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5871 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 527: // customer: CUSTOMER STRING
#line 1438 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5877 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // customer_no: CUSTOMER_NO STRING
#line 1439 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5883 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // data_size: DATA_SIZE any_uint
#line 1440 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5889 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // default_value: DEFAULT_VALUE STRING
#line 1441 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5895 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1442 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 5901 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 532: // deposit: DEPOSIT IDENT
#line 1443 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 5907 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 534: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1445 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5913 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 535: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1446 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 5919 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // dist_op_x: DIST_OP_X any_uint IDENT
#line 1447 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5928 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // dist_op_y: DIST_OP_Y any_uint IDENT
#line 1451 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5937 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 538: // dist_op_z: DIST_OP_Z any_uint IDENT
#line 1455 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5946 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // dist_op_4: DIST_OP_4 any_uint IDENT
#line 1459 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5955 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 540: // dist_op_5: DIST_OP_5 any_uint IDENT
#line 1463 "D:/projects/a2llib/src/a2lparser.y"
                                    {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 5964 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // ecu: ECU STRING
#line 1467 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 5970 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // ecu_address: ECU_ADDRESS any_uint
#line 1468 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 5976 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1469 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 5982 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int
#line 1470 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 5988 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // encoding: ENCODING IDENT
#line 1471 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 5994 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // epk: EPK STRING
#line 1472 "D:/projects/a2llib/src/a2lparser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6000 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 547: // error_mask: ERROR_MASK any_uint
#line 1473 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6006 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 548: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1474 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 6012 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 549: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1475 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6018 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 550: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1476 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 6024 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint
#line 1477 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint
#line 1478 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint
#line 1479 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint
#line 1480 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 555: // fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint
#line 1481 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6054 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 556: // fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT
#line 1482 "D:/projects/a2llib/src/a2lparser.y"
                                                  {
	yylhs.value.as < A2lFncValue > ().Position = yystack_[3].value.as < uint64_t > ();
	yylhs.value.as < A2lFncValue > ().DataType = StringToDataType(yystack_[2].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().IndexMode = StringToIndexMode(yystack_[1].value.as < std::string > ());
	yylhs.value.as < A2lFncValue > ().AddressType = StringToAddressType(yystack_[0].value.as < std::string > ());
}
#line 6065 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // format: FORMAT STRING
#line 1488 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // formula_inv: FORMULA_INV STRING
#line 1489 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6077 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1490 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 6083 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // function_version: FUNCTION_VERSION STRING
#line 1491 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6089 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // identification: IDENTIFICATION any_uint IDENT
#line 1493 "D:/projects/a2llib/src/a2lparser.y"
                                              {
	yylhs.value.as < A2lIdentification > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lIdentification > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
}
#line 6098 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // if_data: IF_DATA
#line 1497 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6104 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // input_quantity: INPUT_QUANTITY IDENT
#line 1498 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6110 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // layout: LAYOUT IDENT
#line 1499 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 6116 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // left_shift: LEFT_SHIFT any_uint
#line 1500 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6122 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // limits: LIMITS any_float any_float
#line 1501 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < A2lLimits > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()}; }
#line 6128 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // matrix_dim: MATRIX_DIM uint_list
#line 1502 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 6134 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 569: // max_grad: MAX_GRAD any_float
#line 1503 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6140 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 570: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1504 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 6146 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 571: // model_link: MODEL_LINK STRING
#line 1505 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6152 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 572: // monotony: MONOTONY IDENT
#line 1506 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 6158 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 573: // no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT
#line 1507 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6167 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT
#line 1511 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
   	}
#line 6176 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 575: // no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT
#line 1515 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6185 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT
#line 1519 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
    	}
#line 6194 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 577: // no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT
#line 1523 "D:/projects/a2llib/src/a2lparser.y"
                                            {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
      	}
#line 6203 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 578: // no_of_interfaces: NO_OF_INTERFACES any_uint
#line 1527 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6209 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 579: // no_rescale_x: NO_RESCALE_X any_uint IDENT
#line 1528 "D:/projects/a2llib/src/a2lparser.y"
                                          {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6218 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 580: // number: NUMBER any_uint
#line 1532 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6224 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // offset_x: OFFSET_X any_uint IDENT
#line 1533 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6233 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // offset_y: OFFSET_Y any_uint IDENT
#line 1537 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6242 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // offset_z: OFFSET_Z any_uint IDENT
#line 1541 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6251 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // offset_4: OFFSET_4 any_uint IDENT
#line 1545 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6260 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // offset_5: OFFSET_5 any_uint IDENT
#line 1549 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6269 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // phone_no: PHONE_NO STRING
#line 1553 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6275 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // phys_unit: PHYS_UNIT STRING
#line 1554 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6281 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // proj_no: IDENT
#line 1555 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6287 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // proj_no: UINT
#line 1556 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 6293 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // project_no: PROJECT_NO proj_no
#line 1557 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6299 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 593: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1561 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6305 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 594: // ref_unit: REF_UNIT IDENT
#line 1562 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6311 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 595: // reserved: RESERVED any_uint IDENT
#line 1563 "D:/projects/a2llib/src/a2lparser.y"
                                  {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
        yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
        }
#line 6320 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 596: // right_shift: RIGHT_SHIFT any_uint
#line 1567 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 6326 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 597: // rip_addr_w: RIP_ADDR_W any_uint IDENT
#line 1568 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 598: // rip_addr_x: RIP_ADDR_X any_uint IDENT
#line 1572 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6344 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 599: // rip_addr_y: RIP_ADDR_Y any_uint IDENT
#line 1576 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6353 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 600: // rip_addr_z: RIP_ADDR_Z any_uint IDENT
#line 1580 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6362 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 601: // rip_addr_4: RIP_ADDR_4 any_uint IDENT
#line 1584 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6371 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 602: // rip_addr_5: RIP_ADDR_5 any_uint IDENT
#line 1588 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6380 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 605: // shift_op_x: SHIFT_OP_X any_uint IDENT
#line 1594 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 606: // shift_op_y: SHIFT_OP_Y any_uint IDENT
#line 1598 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6398 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 607: // shift_op_z: SHIFT_OP_Z any_uint IDENT
#line 1602 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 608: // shift_op_4: SHIFT_OP_4 any_uint IDENT
#line 1606 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6416 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 609: // shift_op_5: SHIFT_OP_5 any_uint IDENT
#line 1610 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6425 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 611: // si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int
#line 1615 "D:/projects/a2llib/src/a2lparser.y"
                                                                                   {
    yylhs.value.as < A2lSiExponents > ().Length = yystack_[6].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Mass = yystack_[5].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Time = yystack_[4].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().ElectricCurrent = yystack_[3].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().Temperature = yystack_[2].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().AmountOfSubstance = yystack_[1].value.as < int64_t > ();
    yylhs.value.as < A2lSiExponents > ().LuminousIntensity = yystack_[0].value.as < int64_t > ();
}
#line 6439 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 612: // src_addr_x: SRC_ADDR_X any_uint IDENT
#line 1624 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6448 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 613: // src_addr_y: SRC_ADDR_Y any_uint IDENT
#line 1628 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6457 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 614: // src_addr_z: SRC_ADDR_Z any_uint IDENT
#line 1632 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6466 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 615: // src_addr_4: SRC_ADDR_4 any_uint IDENT
#line 1636 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6475 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // src_addr_5: SRC_ADDR_5 any_uint IDENT
#line 1640 "D:/projects/a2llib/src/a2lparser.y"
                                      {
	yylhs.value.as < A2lDistOp > ().Position = yystack_[1].value.as < uint64_t > ();
	yylhs.value.as < A2lDistOp > ().DataType = StringToDataType(yystack_[0].value.as < std::string > ());
	}
#line 6484 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 619: // status_string_ref: STATUS_STRING_REF IDENT
#line 1646 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6490 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 620: // step_size: STEP_SIZE any_float
#line 1647 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 6496 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 621: // supplier: SUPPLIER STRING
#line 1648 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6502 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 622: // symbol_link: SYMBOL_LINK STRING any_int
#line 1649 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 6508 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 623: // symbol_type_link: SYMBOL_TYPE_LINK STRING
#line 1650 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6514 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 624: // system_constant: SYSTEM_CONSTANT STRING STRING
#line 1651 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()};}
#line 6520 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 625: // unit_conversion: UNIT_CONVERSION any_float any_float
#line 1652 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < std::pair<double,double> > () = {yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()};}
#line 6526 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 626: // user: USER STRING
#line 1653 "D:/projects/a2llib/src/a2lparser.y"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6532 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // var_measurement: VAR_MEASUREMENT IDENT
#line 1654 "D:/projects/a2llib/src/a2lparser.y"
                                       { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6538 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 628: // var_naming: VAR_NAMING IDENT
#line 1655 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6544 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 629: // var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT
#line 1656 "D:/projects/a2llib/src/a2lparser.y"
                                                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6550 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 630: // var_separator: VAR_SEPARATOR STRING
#line 1657 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 6556 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 631: // version: A2L_VERSION STRING
#line 1658 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 6562 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 6566 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -899;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
      53,    78,   127,   156,  -899,  -899,  -899,  -899,   168,  -899,
     -31,   168,  -899,  -899,  -899,   125,   168,   133,  -899,   164,
      -7,  -899,  -899,   195,  -899,   205,   130,    74,  -899,  -899,
     218,  -899,    62,  -899,   126,   273,   151,  -899,  -899,  -899,
      79,  -899,  -899,  -899,  -899,  -899,   920,   179,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   280,   284,
     305,   345,   350,   351,   356,  -899,   367,   368,   371,   376,
     377,   311,   379,   385,   389,   397,   401,   408,   420,   423,
     426,   428,  -899,  -899,   433,   434,   445,   447,   449,   450,
     451,   223,   452,   453,   454,   457,   458,  -899,  -899,  -899,
     461,   463,   464,   468,   476,   477,   478,  -899,    22,   168,
     168,   474,   483,   492,   493,   168,   442,   496,  -899,   168,
    -899,  -899,   497,   499,   473,   372,  1101,   501,   500,   168,
     506,   516,   517,   518,    55,   129,   324,   526,   527,  -899,
    -899,  -899,  -899,  -899,  -899,   530,   168,   168,   533,   168,
     168,  -899,  -899,   168,   168,   108,   187,   168,   531,   410,
     168,   168,   168,   168,   168,   168,   168,   535,   168,   536,
     538,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,    30,   421,   168,   539,   540,   543,   544,
     335,   545,   168,   546,   549,   550,   553,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,   414,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   556,
     561,  -899,   564,   566,  -899,   570,   418,   381,  -899,  -899,
    -899,  -899,   571,   577,  -899,  -899,  -899,  -899,   579,  -899,
     581,   584,  -899,  -899,   313,   168,  -899,   505,   488,   585,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,   266,   490,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,   168,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,   592,   594,   595,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,   596,  -899,  -899,   598,   602,   603,
     604,   605,   608,   610,   611,   612,   614,   615,  -899,  -899,
    -899,  -899,  -899,   616,   617,   619,   620,   621,   622,   624,
     625,   629,   631,   632,   633,   635,   636,   637,   644,   646,
     647,   649,   650,   652,   653,   654,   657,   659,   660,   661,
     663,   664,   667,   168,   313,    99,   313,   593,    39,  -899,
    -899,  -899,  -899,   669,   113,   313,   344,   313,  -899,   313,
     313,  -899,  -899,  -899,  -899,   313,    65,  -899,    57,  -899,
     670,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,   672,   402,   313,   168,   168,   673,  -899,
     679,   681,   683,   685,   686,   168,  -899,  -899,  -899,  -899,
    -899,   687,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,   688,   689,   507,   690,  -899,  -899,   691,   313,   519,
     509,  -899,   693,  -899,  -899,  -899,  -899,  -899,    18,   301,
     203,  -899,   502,   700,   701,    61,   666,   705,   707,   335,
     168,   709,   710,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,   708,   142,   313,    58,   711,    80,   712,
     665,   713,  -899,  -899,   626,  -899,  -899,  -899,  -899,    96,
     695,   321,   346,   359,   364,   365,   374,   386,   390,   394,
    -899,    48,   618,   721,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
     313,  -899,   168,    21,   723,   724,   727,   729,   730,   732,
     733,   734,   168,  -899,  -899,   313,   313,   736,  -899,  -899,
     548,   738,   335,   313,  -899,  -899,  -899,  -899,   597,   551,
    -899,   741,    -3,  -899,  -899,   168,   743,  -899,  -899,  -899,
    -899,   168,  -899,   335,   313,   655,   699,   313,   313,   747,
     748,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   702,
     313,  -899,  -899,  -899,  -899,   704,  -899,  -899,  -899,  -899,
    -899,  -899,   672,   735,   737,   750,   754,  -899,  -899,  -899,
     760,   764,  -899,   703,   662,   671,   634,   628,   590,   674,
     627,   599,   773,  -899,  -899,   168,   313,   293,  -899,  -899,
    -899,   774,  -899,  -899,  -899,  -899,  -899,   777,  -899,  -899,
     313,   313,   313,   780,  -899,  -899,   335,   313,  -899,  -899,
     588,   589,   783,   785,  -899,  -899,  -899,   313,   789,  -899,
    -899,   313,   787,  -899,   313,   313,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,   765,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,   168,  -899,  -899,   751,
     752,  -899,   335,   792,  -899,   329,   313,  -899,  -899,   168,
     335,  -899,   300,  -899,  -899,  -899,  -899,   313,   731,  -899,
     714,   313,  -899,   312,  -899,  -899,   755,  -899,  -899,  -899,
      87,   168,   149,   623,  -899,  -899,  -899,  -899,   405,   921,
    -899,   335,   607,  -899,  -899,   630,   794,   798,  -899,   313,
     776,  -899,   469,    -5,   694,   168,   168,  -899,   168,   168,
     800,   801,   806,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,    71,   696,  -899,
     168,  -899,  -899,  -899,   302,   788,   638,   809,   313,   168,
     313,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,   775,   639,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,    97,   335,  -899,   842,
      20,   770,   815,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,   726,   313,  -899,   684,   818,   822,   313,
     823,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   826,
     832,  -899,  -899,  -899,   395,   398,   648,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,   831,  -899,  -899,   313,  -899,
    -899,  -899,   668,  -899,  -899,  -899,  -899,  -899,   335,    52,
     808,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,   835,  -899,   836,  -899,  -899,  -899,   313,  -899,  -899,
    -899,   313,  -899,    50,   406,  -899,   803,   335,   656,   658,
    -899,   845,  -899,  -899,   335,  -899,  -899,   407,  -899,  -899,
    -899,   810,   168,   168,  -899,  -899,  -899,  -899,  -899,   645,
    -899,    89,  -899,  -899,   848,  -899,   416,   740,   417,  -899,
    -899,  -899,  -899,   739,  -899,   168,   790,  -899,   675,  -899,
     313,  -899,  -899,   313,  -899,   562,    70,   825,   852,   855,
     313,   313,   313,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,   313,   313,  -899,   212,   168,   168,   784,
    -899,  -899,  -899,  -899
  };

  const short
  A2lParser::yydefact_[] =
  {
      30,     0,     0,     0,    31,   494,     2,     3,     0,     1,
       0,     0,    29,    32,   493,     0,     0,     0,   492,     0,
       0,   333,   334,     0,   331,     0,     0,     0,   332,   199,
       0,   330,     0,   290,     0,     0,     0,   200,   201,   202,
       0,   198,   631,   588,   589,   590,     0,     0,   491,   563,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   305,   306,   307,   308,   291,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   292,   304,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   271,   336,
       0,     0,     0,     0,     0,     0,     0,   467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
     174,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     485,   486,   483,   487,   488,     0,     0,     0,     0,     0,
       0,    21,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   274,   281,   282,
     272,   273,   275,   276,   277,   278,   279,   280,   283,   284,
     285,   286,   287,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   386,   387,   388,
     389,   390,   381,   382,   383,   384,   385,   391,   392,     0,
       0,   423,     0,     0,   454,     0,     0,     0,   591,   470,
     468,   469,     0,     0,    27,   481,   628,   630,     0,    89,
       0,     0,    17,    19,   155,     0,   169,     0,     0,     0,
     176,   177,   178,   175,   181,   182,   183,   184,   185,   179,
     180,     0,     0,    25,   603,   191,   192,   190,   194,   195,
     197,   193,   196,   205,     0,   256,   497,   498,   499,   500,
     501,   502,   503,   516,   529,   532,   604,     0,     0,     0,
     270,   495,   525,   527,   528,   541,     4,     5,     6,   544,
     546,   578,   586,   621,     0,   626,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   551,   552,
     553,   554,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
      25,   466,    25,     0,     0,     0,     0,     0,   137,   146,
     151,     8,     9,    10,     7,     0,     0,   161,     0,    34,
       0,    25,    25,    25,    25,    25,    25,   173,   560,    25,
      25,    25,   188,   187,     0,     0,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,   536,   537,   538,   539,
     540,     0,   562,   573,   574,   575,   576,   577,   579,   581,
     582,   583,   584,   585,   595,   597,   598,   599,   600,   601,
     602,   605,   606,   607,   608,   609,   612,   613,   614,   615,
     616,     0,     0,     0,     0,   424,   425,     0,     0,     0,
       0,   523,     0,   458,   455,   456,   457,   459,     0,     0,
     473,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    90,    91,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,    25,   170,   171,   172,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,    13,   592,   208,   206,   217,   207,
     209,   210,   211,   212,   213,   214,   215,   216,   218,   219,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,   496,     0,     0,     0,   453,   623,
       0,     0,     0,     0,   462,   463,   464,   465,     0,     0,
     474,     0,     0,   480,    28,     0,     0,    88,   517,   534,
     543,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   142,   139,   140,   141,   143,   144,    18,     0,
       0,   147,   148,   149,    20,     0,   152,   153,    22,   154,
     530,   168,   559,     0,     0,     0,     0,    37,    35,    36,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   565,   568,     0,     0,    11,   252,
     251,     0,   509,   510,   511,   512,   513,     0,   556,   406,
       0,     0,     0,     0,   460,   594,     0,     0,   394,    13,
       0,     0,     0,     0,   477,   478,   479,     0,     0,   570,
     622,     0,     0,   136,     0,     0,   522,   619,   145,   531,
     150,    23,    33,   504,   505,   507,     0,   162,   203,   220,
     319,   393,   403,   186,   395,   404,     0,    14,   223,     0,
       0,   105,   249,     0,   514,     0,     0,   427,   441,     0,
       0,   625,     0,   472,   475,   627,   629,     0,     0,   107,
     166,     0,   520,     0,    39,   321,     0,    11,   103,    12,
       0,     0,     0,     0,   407,   408,   409,   413,     0,     0,
     397,     0,     0,    61,   535,     0,     0,     0,   167,     0,
       0,    24,     0,     0,     0,     0,     0,   533,     0,     0,
       0,     0,     0,   226,   229,   237,   224,   247,   225,   227,
     228,   230,   231,   232,   233,   234,   235,   236,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   101,     0,   250,
       0,    25,    25,   405,     0,     0,     0,     0,     0,     0,
       0,   429,   428,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,     0,     0,   445,   442,   443,   444,   446,
     447,   448,   449,   450,   451,   452,     0,     0,   471,     0,
       0,     0,     0,   561,   109,   110,   108,   115,   122,   125,
     135,   111,   112,   113,   114,   116,   117,   118,   119,   120,
     121,   123,   124,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   558,     0,     0,    38,     0,     0,     0,     0,
       0,   322,   323,   324,   325,   326,   327,   328,   329,    83,
      25,   222,   506,   515,   542,   547,   557,   587,   593,     0,
       0,   102,   248,    11,     0,     0,     0,   414,   415,   416,
     417,   418,   419,   420,   421,     0,   426,   545,     0,   580,
     620,   440,     0,   398,   399,   400,   401,   402,     0,     0,
       0,    63,    62,    71,    64,    65,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,    25,     0,   106,   521,   165,     0,   320,   524,
     564,     0,   572,     0,     0,   518,     0,   254,     0,     0,
     412,     0,   548,   396,     0,    60,    25,     0,    25,   519,
     567,     0,     0,     0,   610,    84,    85,    86,    87,     0,
     100,     0,   410,   411,     0,   611,     0,     0,     0,    82,
     566,   596,   489,     0,   255,     0,     0,   221,     0,   253,
       0,   163,   490,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    44,    53,    46,    47,    48,    49,
      50,    51,    52,    54,    55,    56,    57,    58,    59,    15,
      42,   508,   526,     0,     0,   569,     0,     0,     0,     0,
      16,   549,   550,   164
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -899,    -1,  -205,  -187,  -808,    94,  -899,  -899,  -899,  -899,
    -899,  -471,  -899,  -899,  -899,  -174,  -899,  -899,  -899,  -899,
      23,  -899,  -899,  -899,  -899,  -899,    26,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -765,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,   853,  -899,  -899,  -899,   706,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -470,   742,   744,   745,   746,
     749,   757,   758,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -694,  -800,  -496,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -181,
    -899,  -898,  -556,  -502,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -501,  -899,    24,  -899,    28,  -834,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -802,  -899,  -899,  -899,   -58,
    -899,  -172,  -899,  -773,  -899,  -899,  -706,  -899,  -500,  -497,
    -830,  -899,  -899,  -899,  -899,  -899,  -899,  -899,    34,  -899,
    -899,  -899,  -899,  -899,  -899,  -798,  -899,  -899,  -831,    47,
    -787,   281,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -832,  -899,  -495,
     -43,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   756
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,   807,   839,   495,   812,   745,  1146,   489,   490,   364,
     833,   513,   484,     2,     3,   370,   619,   727,   371,   731,
     911,  1115,  1124,    50,   939,  1032,   874,  1063,  1085,    51,
     486,   594,   811,  1000,   217,   747,    52,   855,   946,    53,
     604,   701,    54,   606,   711,    55,   608,   716,    56,   496,
     612,    57,   111,   138,   372,   947,  1125,   702,   857,    58,
     498,   616,    59,   175,   373,   386,    60,   176,   387,    21,
      32,    37,   374,    61,   514,   637,   375,   949,    62,   836,
     876,   218,   840,   751,   219,  1091,    63,   144,   191,    64,
     145,   220,    22,    40,    65,   376,   638,   862,   981,    12,
      23,    24,    66,   146,   283,   377,   349,   389,   573,   936,
    1023,   378,   390,    67,   815,   844,   845,   846,    68,   904,
    1007,    69,   475,   565,    70,   848,   912,    71,   849,   926,
      72,   478,   574,    73,   578,   674,    74,   154,   350,   680,
     159,   681,   160,   682,   774,   161,    75,   128,   162,   877,
     950,    76,    13,     4,   221,   566,   192,   193,   194,   195,
     196,   197,   198,   728,   729,   879,   732,  1126,   291,   292,
     293,   294,   295,   296,   880,   199,   596,  1001,   703,   704,
     954,   705,   576,   982,   222,  1128,   223,   224,   200,   613,
     713,   201,   882,   597,   297,   298,   299,   300,   301,   225,
     884,   598,   226,   916,   227,   886,   917,  1131,  1132,   302,
     303,   304,   305,   306,   307,   887,   858,   617,   379,   961,
     308,    77,   985,   644,  1086,   986,   645,  1134,   600,   601,
     987,   309,   310,   311,   312,   313,   228,   314,   920,   315,
     316,   317,   318,   319,   229,   893,    45,    38,   351,   648,
     895,   675,   320,  1087,   321,   322,   323,   324,   325,   326,
     392,   202,   327,   328,   329,   330,   331,  1088,   676,   332,
     333,   334,   335,   336,   337,   338,   707,   922,   230,   602,
     577,   231,   677,   232,   775,   163,   776,   164,    39
  };

  const short
  A2lParser::yytable_[] =
  {
       8,   771,   385,   380,   391,   419,  1009,    14,   575,   579,
      16,   580,   641,   642,   646,    18,   595,   647,   640,   649,
     499,   959,   670,   970,   968,   155,   156,   749,   983,   897,
     621,   622,   623,   624,   625,   626,   881,   989,   627,   628,
     629,  1036,   569,   570,   639,   499,   918,   932,   914,   929,
     921,   935,  1015,   960,  1081,   952,   564,   967,   346,   347,
     984,   614,   709,   889,   988,     1,    34,   686,   969,   610,
    1010,   875,  1014,   499,  1012,    35,   933,   499,   407,   416,
     417,   418,    46,    47,   715,     5,   499,     6,     7,  1051,
     948,   898,   686,  1103,    48,   499,   509,   571,    25,   723,
     724,  1022,  1011,   563,  1008,  1039,  1013,  1049,  1047,  1045,
     137,   367,   368,    15,   564,    26,   564,   582,   999,   583,
     686,   509,   725,   726,   686,   611,   710,     9,   165,   166,
     890,    17,   611,   686,   171,  1052,    30,  1040,   174,  1034,
      19,  1046,   919,   934,   722,   695,   696,   611,   341,   963,
     408,   409,  1048,   509,   913,   928,   615,    43,  1139,    10,
      44,   951,  1082,  1025,    49,   359,   360,    20,   362,   363,
      11,   671,   365,   366,  1033,   750,   393,     6,     7,   396,
     397,   398,   399,   400,   401,   402,    49,   404,   672,   742,
     381,   382,   697,   698,    49,  1067,    49,   699,    20,    27,
     772,   348,   773,   990,   411,  1083,   679,    36,   633,   630,
     369,   421,    29,   634,   673,    49,  1149,  1129,    31,  1084,
     491,   492,   493,   494,   572,    33,   157,   136,   158,  1053,
    1026,    41,     6,     7,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
      42,  1130,   572,  1138,  1137,  1135,   104,   562,   383,   567,
     105,   499,   915,   930,    49,   671,   809,   810,   584,   955,
     603,   103,   605,   607,   852,   678,  1006,   630,   609,     6,
       7,   106,   593,  1133,   599,  1127,   860,  1136,   117,   861,
     700,   491,   492,   493,   494,   733,   618,   630,   650,   352,
     353,   354,   842,   843,   883,   885,   891,   901,   902,   892,
     636,   896,   643,   416,   417,   418,   187,   585,   586,   384,
     734,   107,   630,   956,   957,   964,   108,   109,   965,   953,
     971,   564,   110,   735,   497,   630,   878,   509,   736,   737,
     630,   630,   189,   112,   113,   203,   204,   114,   738,   927,
     630,   666,   115,   116,   690,    35,   118,   908,   205,   587,
     739,   119,   630,   515,   740,   120,   630,   870,   741,  1068,
     630,   630,  1069,   121,   630,   631,   632,   122,   905,   906,
    1089,  1097,   630,   630,   123,   505,   588,   510,   708,   564,
    1106,  1108,   630,   630,   589,   712,   124,   717,   980,   125,
    1004,  1005,   126,   206,   127,   207,   208,  1037,  1038,  1043,
     129,   130,  1044,  1035,  1050,   871,   866,   587,   511,   187,
     209,    49,   131,   210,   132,   211,   133,   134,   135,   139,
     140,   141,   590,   746,   142,   143,  1024,   766,   147,   591,
     148,   149,   561,   976,   588,   150,   867,   179,   761,   762,
     167,   910,   589,   151,   152,   153,   767,   907,   780,   168,
     908,   180,   181,   182,   183,   184,   185,   186,   169,   170,
     870,   172,   173,   177,   212,   178,   340,   781,   339,    49,
     784,   785,   342,   633,   213,   651,   652,   187,   634,  1064,
     590,   634,   343,   789,   659,   345,   344,   591,   592,   977,
     499,   355,   356,   395,   357,   500,   358,   394,   188,   909,
     361,   403,   405,   189,   406,   410,   412,   413,   871,   635,
     414,   415,   420,   422,   908,   214,   423,   424,   215,   808,
     425,   820,   426,   473,   870,  1116,  1117,   474,   480,   216,
     476,   501,   477,   816,   817,   818,   479,   482,   978,   481,
     821,  1077,   979,   483,   910,   485,   592,   487,   507,   691,
     827,   488,   508,   512,   829,   980,  1118,   831,   832,   516,
     517,   518,   568,   519,   520,  1096,   187,  1098,   521,   522,
     523,   524,   871,   502,   525,   851,   526,   527,   528,   503,
     529,   530,   531,   532,  1119,   533,   534,   535,   536,   847,
     537,   538,   189,   940,   941,   539,   190,   540,   541,   542,
     853,   543,   544,   545,   859,   504,   937,   908,  1120,  1121,
     546,   748,   547,   548,   505,   549,   550,   870,   551,   552,
     553,   760,   873,   554,   888,   555,   556,   557,   899,   558,
     559,   866,   974,   560,   187,   587,   581,   620,   630,  1122,
     653,   944,   942,   962,   777,   654,   506,   655,   980,   656,
     779,   657,   658,   660,   661,   662,   664,   665,   663,   667,
     669,   867,   588,   668,   683,   871,   684,   685,   348,   687,
     589,   688,   907,   689,   694,   908,   692,   693,   714,   718,
     720,  1018,   719,  1020,   721,   870,   730,   744,   743,   752,
     753,   383,  1028,   754,   943,   755,   756,    49,   757,   758,
     759,   910,   763,   764,   765,   770,   634,   768,   590,   778,
     769,   782,   783,   786,   787,   591,   788,   793,   863,   864,
     790,   794,   792,   791,   909,  1031,   795,  1042,   796,   797,
     798,   802,   564,   871,   800,   803,   348,   801,   804,   806,
     813,   805,   872,   814,   865,   799,   819,  1057,   823,   825,
     824,   826,  1061,   828,   830,   834,   866,   837,   841,   187,
     838,   972,   973,   854,   975,   835,   938,   996,   997,   910,
     903,   856,   998,   991,   592,  1017,  1002,   989,   850,  1054,
    1015,  1055,  1056,  1074,  1059,  1058,   867,   588,  1060,  1062,
    1016,  1072,  1021,  1065,   868,   589,  1066,  1071,  1070,   869,
     900,  1075,  1076,  1078,  1092,  1029,  1030,  1093,  1073,  1090,
     870,  1094,  1099,  1102,  1105,  1107,   383,  1140,  1141,  1111,
    1109,  1142,    49,   822,   992,   993,   633,   994,   995,  1095,
    1079,   634,  1153,   590,  1080,   925,    28,   931,   945,   958,
     591,  1041,   388,   894,  1112,   706,   187,   587,   284,   966,
     285,   286,   287,  1027,     0,   288,     0,     0,   871,  1003,
       0,   233,   635,   289,   290,     0,     0,   872,  1019,     0,
       0,     0,   189,     0,   588,     0,     0,     0,     0,  1104,
       0,     0,   589,  1113,   923,   924,  1114,   908,     0,     0,
       0,     0,     0,  1143,  1144,  1145,     0,   870,   564,   592,
       0,  1123,     0,   383,     0,     0,   943,     0,     0,    49,
       0,     0,     0,    78,     0,     0,  1147,  1148,     0,  1150,
     590,     0,   866,    79,     0,   187,     0,   591,   980,    80,
       0,     0,     0,    81,    82,     0,    83,    84,     0,    85,
       0,     0,     0,     0,     0,   871,     0,     0,   348,     0,
       0,     0,   867,     0,   872,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   869,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   870,     0,    86,     0,
      87,   910,     0,    88,     0,     0,   592,     0,     0,     0,
      89,     0,   633,     0,     0,     0,     0,   634,     0,    90,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   871,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,  1101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,   234,     0,    94,     0,     0,
      95,    96,    97,    98,    99,   100,     0,     0,   101,   180,
     181,   182,   183,   184,   185,   186,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,  1151,  1152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,   250,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,   257,     0,   258,     0,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,   265,   266,   267,
     268,   269,   270,     0,     0,   271,   272,   273,   274,   275,
       0,     0,   276,   277,   278,   279,   280,   281,   282
  };

  const short
  A2lParser::yycheck_[] =
  {
       1,     4,   176,   175,   176,   210,   904,     8,   478,   480,
      11,   482,   514,   514,   514,    16,   486,   514,   514,   514,
      25,   855,     4,   855,   855,     3,     4,     6,   862,   837,
     501,   502,   503,   504,   505,   506,   836,    42,   509,   510,
     511,   939,     3,     4,   514,    25,   848,   849,   848,   849,
     848,   849,    32,   855,     4,   855,    17,   855,     3,     4,
     862,     4,     4,   836,   862,    12,     4,    72,   855,     4,
     904,   836,   904,    25,   904,    13,   849,    25,    48,     8,
       9,    10,     3,     4,     4,     7,    25,     9,    10,    69,
     855,     4,    72,     4,    15,    25,   101,    58,   105,     3,
       4,     4,   904,     4,   904,   939,   904,   939,   939,   939,
     111,     3,     4,   144,    17,   122,    17,     4,    47,     6,
      72,   101,    26,    27,    72,    67,    68,     0,   129,   130,
     836,     6,    67,    72,   135,   115,     6,   939,   139,   939,
       7,   939,   848,   849,   615,     3,     4,    67,   149,   855,
     120,   121,   939,   101,   848,   849,    99,     6,    88,     3,
       9,   855,   112,   936,   107,   166,   167,     3,   169,   170,
      14,   153,   173,   174,   939,   154,   177,     9,    10,   180,
     181,   182,   183,   184,   185,   186,   107,   188,   170,   141,
       3,     4,    50,    51,   107,  1003,   107,    55,     3,     4,
     203,   146,   205,   208,   205,   155,     3,   145,   111,     6,
     102,   212,     7,   116,   196,   107,     4,  1115,   144,   169,
       8,     9,    10,    11,   185,     7,   204,     4,   206,   209,
     936,   105,     9,    10,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       7,  1115,   185,  1115,  1115,  1115,     6,   474,   101,   476,
       6,    25,   848,   849,   107,   153,     3,     4,   485,   855,
     487,   122,   489,   490,     4,     4,     4,     6,   495,     9,
      10,     6,   486,  1115,   486,  1115,     4,  1115,     7,     7,
     178,     8,     9,    10,    11,     4,   498,     6,   515,   200,
     201,   202,     3,     4,   836,   836,   836,   188,   189,   836,
     514,   836,   514,     8,     9,    10,    44,     3,     4,   162,
       4,     6,     6,   855,   855,   855,     6,     6,   855,   855,
     855,    17,     6,     4,   365,     6,   836,   101,     4,     4,
       6,     6,    70,     6,     6,     3,     4,     6,     4,   849,
       6,   568,     6,     6,   589,    13,     7,    85,    16,    45,
       4,     6,     6,   394,     4,     6,     6,    95,     4,     4,
       6,     6,     4,     6,     6,     3,     4,     6,     3,     4,
       4,     4,     6,     6,     6,   149,    72,   151,   605,    17,
       4,     4,     6,     6,    80,   606,     6,   608,   126,     6,
     901,   902,     6,    61,     6,    63,    64,   939,   939,   939,
       7,     7,   939,   939,   939,   143,    41,    45,   182,    44,
      78,   107,     7,    81,     7,    83,     7,     7,     7,     7,
       7,     7,   118,   650,     7,     7,   936,   672,     7,   125,
       7,     7,   473,     4,    72,     7,    71,     4,   665,   666,
       6,   179,    80,     7,     7,     7,   673,    82,   693,     6,
      85,    18,    19,    20,    21,    22,    23,    24,     6,     6,
      95,    59,     6,     6,   132,     6,     6,   694,     7,   107,
     697,   698,     6,   111,   142,   516,   517,    44,   116,   990,
     118,   116,     6,   710,   525,     7,     9,   125,   184,    60,
      25,   207,     6,   123,     7,    30,     6,     6,    65,   134,
       7,     6,     6,    70,     6,   124,     7,     7,   143,   147,
       7,     7,     7,     7,    85,   183,     7,     7,   186,   746,
       7,   766,   148,     7,    95,     3,     4,     6,   150,   197,
       6,    66,     6,   760,   761,   762,     6,     6,   109,   198,
     767,  1052,   113,     6,   179,     6,   184,     6,   100,   590,
     777,     7,     7,   103,   781,   126,    34,   784,   785,     7,
       6,     6,     9,     7,     6,  1076,    44,  1078,     6,     6,
       6,     6,   143,   108,     6,   820,     6,     6,     6,   114,
       6,     6,     6,     6,    62,     6,     6,     6,     6,   816,
       6,     6,    70,     3,     4,     6,   163,     6,     6,     6,
     827,     6,     6,     6,   831,   140,   851,    85,    86,    87,
       6,   652,     6,     6,   149,     6,     6,    95,     6,     6,
       6,   662,   836,     6,   836,     6,     6,     6,   840,     6,
       6,    41,   859,     6,    44,    45,     7,     7,     6,   117,
       7,   855,    52,   855,   685,     6,   181,     6,   126,     6,
     691,     6,     6,     6,     6,     6,     6,     6,   191,   180,
       7,    71,    72,   194,   202,   143,     6,     6,   146,    43,
      80,     6,    82,     6,     6,    85,     7,     7,     7,     7,
       7,   908,    57,   910,    98,    95,    31,     6,   110,     6,
       6,   101,   937,     6,   104,     6,     6,   107,     6,     6,
       6,   179,     6,   195,     6,     4,   116,   150,   118,     6,
     199,    96,    53,     6,     6,   125,    54,     7,     3,     4,
      56,     7,    25,    28,   134,   939,     6,   939,     4,    66,
     108,   181,    17,   143,   140,   101,   146,   149,   151,     6,
       6,   182,   152,     6,    29,   114,     6,   974,   200,     6,
     201,     6,   979,     4,     7,    30,    41,    46,     6,    44,
      48,     7,     4,    72,    28,   806,   199,     7,     7,   179,
     187,    97,     6,   119,   184,     6,   120,    42,   819,    49,
      32,     6,    96,  1028,     6,   141,    71,    72,     6,     6,
     192,  1018,   193,     7,    79,    80,     4,     6,   190,    84,
     841,    33,     7,     7,   188,     3,     4,   189,   180,    46,
      95,     6,    42,   208,     6,   115,   101,    32,     6,    69,
     121,     6,   107,   769,   865,   866,   111,   868,   869,  1074,
    1057,   116,    88,   118,  1061,   849,    23,   849,   855,   855,
     125,   939,   176,   836,   209,   604,    44,    45,   146,   855,
     146,   146,   146,   936,    -1,   146,    -1,    -1,   143,   900,
      -1,   145,   147,   146,   146,    -1,    -1,   152,   909,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,  1091,
      -1,    -1,    80,  1110,     3,     4,  1113,    85,    -1,    -1,
      -1,    -1,    -1,  1120,  1121,  1122,    -1,    95,    17,   184,
      -1,  1115,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,    -1,    -1,    33,    -1,    -1,  1143,  1144,    -1,  1146,
     118,    -1,    41,    43,    -1,    44,    -1,   125,   126,    49,
      -1,    -1,    -1,    53,    54,    -1,    56,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,   146,    -1,
      -1,    -1,    71,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    98,    -1,
     100,   179,    -1,   103,    -1,    -1,   184,    -1,    -1,    -1,
     110,    -1,   111,    -1,    -1,    -1,    -1,   116,    -1,   119,
      -1,    -1,    -1,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1082,  1083,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1105,     4,    -1,   187,    -1,    -1,
     190,   191,   192,   193,   194,   195,    -1,    -1,   198,    18,
      19,    20,    21,    22,    23,    24,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,  1147,  1148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,   133,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,   158,
     159,   160,   161,    -1,    -1,   164,   165,   166,   167,   168,
      -1,    -1,   171,   172,   173,   174,   175,   176,   177
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
      81,    83,   132,   142,   183,   186,   197,   244,   291,   294,
     301,   364,   394,   396,   397,   409,   412,   414,   446,   454,
     488,   491,   493,   498,     4,    35,    36,    37,    38,    39,
      40,    73,    74,    75,    76,    77,    89,    90,    91,    92,
      93,    94,   106,   127,   128,   129,   130,   131,   133,   135,
     136,   137,   138,   139,   154,   156,   157,   158,   159,   160,
     161,   164,   165,   166,   167,   168,   171,   172,   173,   174,
     175,   176,   177,   314,   366,   367,   368,   369,   370,   371,
     372,   378,   379,   380,   381,   382,   383,   404,   405,   406,
     407,   408,   419,   420,   421,   422,   423,   424,   430,   441,
     442,   443,   444,   445,   447,   449,   450,   451,   452,   453,
     462,   464,   465,   466,   467,   468,   469,   472,   473,   474,
     475,   476,   479,   480,   481,   482,   483,   484,   485,     7,
       6,   211,     6,     6,     9,     7,     3,     4,   146,   316,
     348,   458,   200,   201,   202,   207,     6,     7,     6,   211,
     211,     7,   211,   211,   219,   211,   211,     3,     4,   102,
     225,   228,   264,   274,   282,   286,   305,   315,   321,   428,
     431,     3,     4,   101,   162,   225,   275,   278,   315,   317,
     322,   431,   470,   211,     6,   123,   211,   211,   211,   211,
     211,   211,   211,     6,   211,     6,     6,    48,   120,   121,
     124,   211,     7,     7,     7,     7,     8,     9,    10,   212,
       7,   211,     7,     7,     7,     7,   148,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,     7,     6,   332,     6,     6,   341,     6,
     150,   198,     6,     6,   222,     6,   240,     6,     7,   217,
     218,     8,     9,    10,    11,   213,   259,   211,   270,    25,
      30,    66,   108,   114,   140,   149,   181,   100,     7,   101,
     151,   182,   103,   221,   284,   211,     7,     6,     6,     7,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   211,   213,     4,    17,   333,   365,   213,     9,     3,
       4,    58,   185,   318,   342,   365,   392,   490,   344,   221,
     221,     7,     4,     6,   213,     3,     4,    45,    72,    80,
     118,   125,   184,   225,   241,   365,   386,   403,   411,   431,
     438,   439,   489,   213,   250,   213,   253,   213,   256,   213,
       4,    67,   260,   399,     4,    99,   271,   427,   431,   226,
       7,   221,   221,   221,   221,   221,   221,   221,   221,   221,
       6,     3,     4,   111,   116,   147,   225,   285,   306,   365,
     386,   403,   411,   431,   433,   436,   438,   439,   459,   489,
     213,   211,   211,     7,     6,     6,     6,     6,     6,   211,
       6,     6,     6,   191,     6,     6,   213,   180,   194,     7,
       4,   153,   170,   196,   345,   461,   478,   492,     4,     3,
     349,   351,   353,   202,     6,     6,    72,    43,     6,     6,
     212,   211,     7,     7,     6,     3,     4,    50,    51,    55,
     178,   251,   267,   388,   389,   391,   461,   486,   213,     4,
      68,   254,   399,   400,     7,     4,   257,   399,     7,    57,
       7,    98,   221,     3,     4,    26,    27,   227,   373,   374,
      31,   229,   376,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   141,   110,     6,   215,   213,   245,   211,     6,
     154,   293,     6,     6,     6,     6,     6,     6,     6,     6,
     211,   213,   213,     6,   195,     6,   212,   213,   150,   199,
       4,     4,   203,   205,   354,   494,   496,   211,     6,   211,
     212,   213,    96,    53,   213,   213,     6,     6,    54,   213,
      56,    28,    25,     7,     7,     6,     4,    66,   108,   114,
     140,   149,   181,   101,   151,   182,     6,   211,   213,     3,
       4,   242,   214,     6,     6,   324,   213,   213,   213,     6,
     212,   213,   215,   200,   201,     6,     6,   213,     4,   213,
       7,   213,   213,   220,    30,   211,   289,    46,    48,   212,
     292,     6,     3,     4,   325,   326,   327,   213,   335,   338,
     211,   212,     4,   213,    72,   247,    97,   268,   426,   213,
       4,     7,   307,     3,     4,    29,    41,    71,    79,    84,
      95,   143,   152,   225,   236,   275,   290,   359,   365,   375,
     384,   385,   402,   403,   410,   411,   415,   425,   431,   433,
     436,   438,   439,   455,   459,   460,   489,   214,     4,   431,
     211,   188,   189,   187,   329,     3,     4,    82,    85,   134,
     179,   230,   336,   384,   385,   402,   413,   416,   425,   436,
     448,   455,   487,     3,     4,   236,   339,   365,   384,   385,
     402,   415,   425,   433,   436,   455,   319,   212,   199,   234,
       3,     4,    52,   104,   225,   230,   248,   265,   275,   287,
     360,   384,   385,   386,   390,   402,   403,   411,   413,   416,
     425,   429,   431,   436,   438,   439,   448,   455,   458,   460,
     487,   489,     7,     4,   213,    28,     4,    60,   109,   113,
     126,   308,   393,   416,   425,   432,   435,   440,   455,    42,
     208,   119,   211,   211,   211,   211,     7,     7,     6,    47,
     243,   387,   120,   211,   221,   221,     4,   330,   385,   401,
     416,   425,   440,   455,   487,    32,   192,     6,   213,   211,
     213,   193,     4,   320,   365,   433,   436,   490,   212,     3,
       4,   225,   235,   275,   385,   386,   401,   403,   411,   416,
     425,   429,   431,   438,   439,   440,   455,   458,   460,   487,
     489,    69,   115,   209,    49,     6,    96,   213,   141,     6,
       6,   213,     6,   237,   221,     7,     4,   214,     4,     4,
     190,     6,   213,   180,   212,    33,     7,   221,     7,   213,
     213,     4,   112,   155,   169,   238,   434,   463,   477,     4,
      46,   295,   188,   189,     6,   212,   221,     4,   221,    42,
     211,   211,   208,     4,   431,     6,     4,   115,     4,   121,
     211,    69,   209,   213,   213,   231,     3,     4,    34,    62,
      86,    87,   117,   225,   232,   266,   377,   385,   395,   401,
     416,   417,   418,   425,   437,   440,   455,   458,   487,    88,
      32,     6,     6,   213,   213,   213,   216,   213,   213,     4,
     213,   211,   211,    88
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
     262,   263,   264,   265,   266,   267,   268,   268,   269,   270,
     270,   271,   271,   272,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   275,   275,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   279,   280,
     280,   281,   281,   282,   283,   284,   284,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     286,   287,   288,   289,   289,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   291,   292,
     292,   293,   293,   294,   295,   295,   296,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     299,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   302,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   305,
     306,   307,   307,   308,   308,   308,   308,   308,   308,   308,
     309,   310,   310,   311,   311,   312,   313,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   315,   316,   317,   318,   319,   319,   320,
     320,   320,   320,   321,   322,   323,   324,   324,   325,   325,
     326,   327,   328,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   331,   332,   332,   333,   334,   335,   335,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     337,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   341,   341,   342,   342,   342,   342,
     343,   344,   344,   345,   345,   345,   346,   347,   347,   348,
     348,   349,   350,   351,   351,   352,   353,   353,   354,   354,
     355,   356,   357,   357,   358,   358,   358,   358,   358,   359,
     360,   361,   362,   363,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498
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
       2,     4,     5,     6,     5,     6,     0,     1,     9,     0,
       2,     1,     1,     7,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     7,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     6,     0,
       2,     1,     1,     5,     9,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,    13,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     9,     0,
       2,     1,     1,    13,     0,     2,     6,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       7,     1,     2,     1,     1,     6,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     8,     0,     2,     1,
       1,     1,     1,     5,     5,    12,     0,     2,     1,     1,
       5,     5,    14,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     8,     0,     2,     1,    13,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      13,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     8,     0,     2,     1,     1,     1,     1,
       9,     0,     2,     1,     1,     1,     6,     0,     2,     1,
       1,     5,     7,     0,     1,     7,     0,     2,     1,     1,
       5,     5,     0,     2,     1,     1,     1,     1,     1,     5,
       6,     1,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     5,
       5,     5,     5,     5,     6,     2,     2,     2,     2,     7,
       3,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     5,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     3,     4,
       4,     2,     2,     2,     2,     2,     5,     2,     2,     2,
       2,     1,     3,     1,     2,     2,     2,     3,     2,     2,
       3,     2,     2,     3,     3,     3,     3,     3,     2,     3,
       2,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       2,     1,     1,     2,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     3,     3,
       1,     8,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     3,     2,     3,     3,     2,     2,     2,     2,
       2,     2
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
       0,   433,   433,   434,   436,   437,   438,   440,   441,   442,
     443,   445,   446,   448,   449,   451,   452,   454,   455,   457,
     458,   460,   461,   465,   466,   468,   469,   471,   472,   474,
     476,   477,   478,   480,   481,   482,   483,   484,   486,   488,
     493,   494,   496,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     524,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   560,   565,   566,   567,   568,   569,   571,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     590,   594,   595,   597,   603,   604,   609,   622,   623,   624,
     625,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   654,   663,   664,   665,
     666,   667,   668,   673,   674,   676,   685,   686,   687,   688,
     690,   699,   700,   701,   703,   711,   712,   713,   715,   717,
     718,   720,   730,   732,   735,   737,   738,   739,   741,   748,
     749,   750,   751,   753,   758,   759,   760,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   771,   772,   774,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   790,   795,
     796,   798,   801,   806,   808,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   829,   830,
     832,   834,   836,   848,   849,   850,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   874,   881,
     882,   887,   888,   890,   902,   903,   907,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
     926,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   949,
     955,   956,   957,   958,   961,   964,   967,   970,   973,   976,
     979,   980,   983,   986,   989,   992,   995,   998,   999,  1000,
    1003,  1006,  1009,  1012,  1015,  1018,  1021,  1024,  1027,  1029,
    1031,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1046,  1047,
    1049,  1055,  1056,  1058,  1059,  1064,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1126,  1127,  1128,  1130,  1137,  1138,  1139,
    1140,  1141,  1142,  1144,  1145,  1147,  1158,  1159,  1160,  1161,
    1163,  1164,  1166,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1189,  1195,  1196,  1197,  1199,  1211,  1212,  1213,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1228,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
    1249,  1250,  1251,  1253,  1260,  1261,  1262,  1263,  1264,  1267,
    1269,  1276,  1277,  1278,  1279,  1280,  1285,  1289,  1290,  1291,
    1292,  1294,  1296,  1302,  1303,  1305,  1312,  1313,  1314,  1315,
    1317,  1319,  1320,  1321,  1322,  1326,  1330,  1334,  1338,  1343,
    1344,  1348,  1349,  1354,  1357,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1381,  1387,  1393,  1399,  1405,  1412,  1413,  1414,  1415,  1416,
    1426,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1451,  1455,  1459,
    1463,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1481,  1482,  1488,  1489,  1490,
    1491,  1492,  1493,  1497,  1498,  1499,  1500,  1501,  1502,  1503,
    1504,  1505,  1506,  1507,  1511,  1515,  1519,  1523,  1527,  1528,
    1532,  1533,  1537,  1541,  1545,  1549,  1553,  1554,  1555,  1556,
    1557,  1559,  1560,  1561,  1562,  1563,  1567,  1568,  1572,  1576,
    1580,  1584,  1588,  1592,  1593,  1594,  1598,  1602,  1606,  1610,
    1614,  1615,  1624,  1628,  1632,  1636,  1640,  1644,  1645,  1646,
    1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,  1656,
    1657,  1658
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
#line 7905 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1660 "D:/projects/a2llib/src/a2lparser.y"


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
