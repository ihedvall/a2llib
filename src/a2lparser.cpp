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

      case symbol_kind::S_bit_operation: // bit_operation
        value.copy< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.copy< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.copy< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.copy< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.copy< A2lDeposit > (YY_MOVE (that.value));
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

      case symbol_kind::S_layout: // layout
        value.copy< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.copy< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.copy< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.copy< A2lSymbolLink > (YY_MOVE (that.value));
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

      case symbol_kind::S_formula: // formula
        value.copy< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.copy< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.copy< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (YY_MOVE (s.value));
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

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (YY_MOVE (s.value));
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

      case symbol_kind::S_formula: // formula
        value.move< std::pair<std::string,std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (s.value));
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (s.value));
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        value.YY_MOVE_OR_COPY< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.YY_MOVE_OR_COPY< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.YY_MOVE_OR_COPY< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.YY_MOVE_OR_COPY< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.YY_MOVE_OR_COPY< A2lDeposit > (YY_MOVE (that.value));
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

      case symbol_kind::S_layout: // layout
        value.YY_MOVE_OR_COPY< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.YY_MOVE_OR_COPY< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.YY_MOVE_OR_COPY< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.YY_MOVE_OR_COPY< A2lSymbolLink > (YY_MOVE (that.value));
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

      case symbol_kind::S_formula: // formula
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.YY_MOVE_OR_COPY< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (YY_MOVE (that.value));
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

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (YY_MOVE (that.value));
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

      case symbol_kind::S_formula: // formula
        value.move< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        value.copy< A2lBitOperation > (that.value);
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.copy< A2lByteOrder > (that.value);
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.copy< A2lCalibrationAccess > (that.value);
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.copy< A2lDependentCharacteristic > (that.value);
        break;

      case symbol_kind::S_deposit: // deposit
        value.copy< A2lDeposit > (that.value);
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

      case symbol_kind::S_layout: // layout
        value.copy< A2lLayout > (that.value);
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.copy< A2lMaxRefresh > (that.value);
        break;

      case symbol_kind::S_monotony: // monotony
        value.copy< A2lMonotony > (that.value);
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.copy< A2lSymbolLink > (that.value);
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

      case symbol_kind::S_formula: // formula
        value.copy< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.copy< std::string > (that.value);
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.copy< std::vector<std::pair<std::string, std::string>> > (that.value);
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.copy< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (that.value);
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (that.value);
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (that.value);
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (that.value);
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (that.value);
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

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (that.value);
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (that.value);
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (that.value);
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (that.value);
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

      case symbol_kind::S_formula: // formula
        value.move< std::pair<std::string,std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        value.move< std::string > (that.value);
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

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (that.value);
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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

      case symbol_kind::S_bit_operation: // bit_operation
        yylhs.value.emplace< A2lBitOperation > ();
        break;

      case symbol_kind::S_byte_order: // byte_order
        yylhs.value.emplace< A2lByteOrder > ();
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        yylhs.value.emplace< A2lCalibrationAccess > ();
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        yylhs.value.emplace< A2lDependentCharacteristic > ();
        break;

      case symbol_kind::S_deposit: // deposit
        yylhs.value.emplace< A2lDeposit > ();
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

      case symbol_kind::S_layout: // layout
        yylhs.value.emplace< A2lLayout > ();
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        yylhs.value.emplace< A2lMaxRefresh > ();
        break;

      case symbol_kind::S_monotony: // monotony
        yylhs.value.emplace< A2lMonotony > ();
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        yylhs.value.emplace< A2lSymbolLink > ();
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

      case symbol_kind::S_formula: // formula
        yylhs.value.emplace< std::pair<std::string,std::string> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_version: // version
        yylhs.value.emplace< std::string > ();
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

      case symbol_kind::S_key_value_list: // key_value_list
        yylhs.value.emplace< std::vector<std::pair<std::string, std::string>> > ();
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
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        yylhs.value.emplace< std::vector<uint64_t> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_left_shift: // left_shift
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
#line 341 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 1855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 342 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 1861 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_int: INT
#line 344 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 1867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: UINT
#line 345 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1873 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: HEX
#line 346 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_float: FLOAT
#line 348 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1885 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: INT
#line 349 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 1891 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: UINT
#line 350 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 1897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: HEX
#line 351 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 1903 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // int_list: %empty
#line 353 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 1909 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: int_list any_int
#line 354 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::vector<int64_t> > () = yystack_[1].value.as < std::vector<int64_t> > (); yylhs.value.as < std::vector<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); }
#line 1915 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // uint_list: %empty
#line 356 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 1921 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: uint_list any_uint
#line 357 "D:/projects/a2llib/src/a2lparser.y"
                       {yylhs.value.as < std::vector<uint64_t> > () = yystack_[1].value.as < std::vector<uint64_t> > (); yylhs.value.as < std::vector<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 1927 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // float_list: %empty
#line 359 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 1933 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: float_list any_float
#line 360 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < std::vector<double> > () = yystack_[1].value.as < std::vector<double> > (); yylhs.value.as < std::vector<double> > ().emplace_back(yystack_[0].value.as < double > ()); }
#line 1939 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_pair_list: %empty
#line 362 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 1945 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: float_pair_list any_float any_float
#line 363 "D:/projects/a2llib/src/a2lparser.y"
                                              {yylhs.value.as < std::map<double, double> > () = yystack_[2].value.as < std::map<double, double> > (); yylhs.value.as < std::map<double, double> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 1951 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_string_list: %empty
#line 365 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 1957 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: float_string_list any_float STRING
#line 366 "D:/projects/a2llib/src/a2lparser.y"
                                             {yylhs.value.as < std::map<double, std::string> > () = yystack_[2].value.as < std::map<double, std::string> > (); yylhs.value.as < std::map<double, std::string> > ().emplace(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); }
#line 1963 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_range_list: %empty
#line 368 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 1969 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: float_range_list any_float any_float STRING
#line 369 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > () = yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ();
	yylhs.value.as < std::map<std::pair<double, double>, std::string> > ().emplace(std::pair(yystack_[2].value.as < double > (),yystack_[1].value.as < double > ()),yystack_[0].value.as < std::string > ()); }
#line 1977 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // string_list: %empty
#line 373 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 1983 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: string_list STRING
#line 374 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); }
#line 1989 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // ident_list: %empty
#line 376 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 1995 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: ident_list IDENT
#line 377 "D:/projects/a2llib/src/a2lparser.y"
                           {yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); }
#line 2001 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // key_value_list: %empty
#line 379 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 2007 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: key_value_list IDENT IDENT
#line 380 "D:/projects/a2llib/src/a2lparser.y"
                                     {yylhs.value.as < std::vector<std::pair<std::string, std::string>> > () = yystack_[2].value.as < std::vector<std::pair<std::string, std::string>> > (); yylhs.value.as < std::vector<std::pair<std::string, std::string>> > ().emplace_back(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); }
#line 2013 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 32: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 387 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = yystack_[2].value.as < A2lAnnotation > ();}
#line 2019 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // annotation_attributes: %empty
#line 388 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 2025 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation_attributes: annotation_attributes annotation_label
#line 389 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Label = yystack_[0].value.as < std::string > ();}
#line 2031 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: annotation_attributes annotation_origin
#line 390 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Origin = yystack_[0].value.as < std::string > ();}
#line 2037 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_text
#line 391 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Text = yystack_[0].value.as < std::vector<std::string> > ();}
#line 2043 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 393 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2049 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 38: // ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT
#line 395 "D:/projects/a2llib/src/a2lparser.y"
                                                                                        {
	auto& func = scanner.CurrentFunction();
	func.ComponentType(yystack_[3].value.as < std::string > ());
	func.PrototypeOf(yystack_[2].value.as < std::string > ());
 }
#line 2059 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 39: // ar_component_attribute: %empty
#line 400 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = std::string(); }
#line 2065 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 40: // ar_component_attribute: ar_prototype_of
#line 401 "D:/projects/a2llib/src/a2lparser.y"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2071 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 41: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 404 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 2085 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 44: // axis_descr_attribute: annotation
#line 415 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2091 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // axis_descr_attribute: axis_pts_ref
#line 416 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 2097 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: byte_order
#line 417 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 2103 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: curve_axis_ref
#line 418 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 2109 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: deposit
#line 419 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 2115 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: extended_limits
#line 420 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 2121 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: fix_axis_par
#line 421 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 2127 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: fix_axis_par_dist
#line 422 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 2133 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par_list
#line 423 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::vector<double> > ()); }
#line 2139 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: format
#line 424 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 2145 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: max_grad
#line 425 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 2151 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: monotony
#line 426 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 2157 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: phys_unit
#line 427 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 2163 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: read_only
#line 428 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 2169 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: step_size
#line 429 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().StepSize(yystack_[0].value.as < double > ()); }
#line 2175 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 432 "D:/projects/a2llib/src/a2lparser.y"
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
#line 2193 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 62: // axis_pts_attribute: annotation
#line 447 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2199 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_pts_attribute: byte_order
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 2205 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: calibration_access
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2211 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: deposit
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 2217 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: display_identifier
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2223 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: ecu_address_extension
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2229 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: extended_limits
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 2235 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: format
#line 454 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 2241 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: function_list
#line 455 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2247 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: guard_rails
#line 456 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 2253 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: if_data
#line 457 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2259 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: max_refresh
#line 458 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2265 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: model_link
#line 459 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2271 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: monotony
#line 460 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 2277 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: phys_unit
#line 461 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 2283 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: read_only
#line 462 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 2289 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: ref_memory_segment
#line 463 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 2295 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: step_size
#line 464 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 2301 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: symbol_link
#line 465 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 2307 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION
#line 467 "D:/projects/a2llib/src/a2lparser.y"
                                                                                      {
	auto& operation = scanner.CurrentBitOperation();
	yylhs.value.as < A2lBitOperation > () = operation;
	operation = {};
}
#line 2317 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 84: // bit_operation_attribute: left_shift
#line 474 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentBitOperation().LeftShift = yystack_[0].value.as < uint64_t > (); }
#line 2323 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 85: // bit_operation_attribute: right_shift
#line 475 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().RightShift = yystack_[0].value.as < uint64_t > (); }
#line 2329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 86: // bit_operation_attribute: sign_extend
#line 476 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBitOperation().SignExtended = true; }
#line 2335 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 87: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 478 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 2347 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 90: // blob_attribute: address_type
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 2353 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 91: // blob_attribute: annotation
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2359 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: calibration_access
#line 489 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2365 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: display_identifier
#line 490 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2371 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: ecu_address_extension
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2377 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: if_data
#line 492 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2383 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: max_refresh
#line 493 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: model_link
#line 494 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: symbol_link
#line 495 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 2401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 105: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 507 "D:/projects/a2llib/src/a2lparser.y"
                                                         {
	auto& object = scanner.CurrentCharacteristic();
	object.Name(yystack_[11].value.as < std::string > ());
	object.Description(yystack_[10].value.as < std::string > ());
	object.Type(StringToCharacteristicType(yystack_[9].value.as < std::string > ()));
	}
#line 2412 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 108: // characteristic_attribute: annotation
#line 515 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2418 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // characteristic_attribute: axis_descr
#line 516 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 2426 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: bit_mask
#line 519 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 2432 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: byte_order
#line 520 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 2438 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: calibration_access
#line 521 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2444 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: comparison_quantity
#line 522 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 2450 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: dependent_characteristic
#line 523 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 2456 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: discrete
#line 524 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 2462 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: display_identifier
#line 525 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2468 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: ecu_address_extension
#line 526 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2474 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: encoding
#line 527 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 2480 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: extended_limits
#line 528 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 2486 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: format
#line 529 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 2492 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: function_list
#line 530 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2498 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: guard_rails
#line 531 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 2504 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: if_data
#line 532 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2510 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: map_list
#line 533 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2516 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: matrix_dim
#line 534 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 2522 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: max_refresh
#line 535 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2528 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: model_link
#line 536 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2534 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: number
#line 537 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 2540 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: phys_unit
#line 538 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 2546 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: read_only
#line 539 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 2552 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: ref_memory_segment
#line 540 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 2558 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: step_size
#line 541 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 2564 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: symbol_link
#line 542 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 2570 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: virtual_characteristic
#line 543 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 2576 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD
#line 545 "D:/projects/a2llib/src/a2lparser.y"
                                                                                                                   {
	auto& method = scanner.CurrentCompuMethod();
	method.Name(yystack_[7].value.as < std::string > ());
	method.Description(yystack_[6].value.as < std::string > ());
	method.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	method.Format(yystack_[4].value.as < std::string > ());
	method.PhysUnit(yystack_[3].value.as < std::string > ());
}
#line 2589 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 138: // compu_method_attribute: coeffs
#line 556 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentCompuMethod().Coeffs(yystack_[0].value.as < std::vector<double> > ()); }
#line 2595 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 139: // compu_method_attribute: coeffs_linear
#line 557 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CoeffsLinear(yystack_[0].value.as < std::vector<double> > ()); }
#line 2601 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 140: // compu_method_attribute: compu_tab_ref
#line 558 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCompuMethod().CompuTabRef(yystack_[0].value.as < std::string > ()); }
#line 2607 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 141: // compu_method_attribute: formula
#line 559 "D:/projects/a2llib/src/a2lparser.y"
                  {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().first);
		method.Formula(yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
	}
#line 2617 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 142: // compu_method_attribute: ref_unit
#line 564 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCompuMethod().RefUnit(yystack_[0].value.as < std::string > ()); }
#line 2623 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 143: // compu_method_attribute: status_string_ref
#line 565 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentCompuMethod().StatusStringRef(yystack_[0].value.as < std::string > ()); }
#line 2629 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 144: // compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB
#line 568 "D:/projects/a2llib/src/a2lparser.y"
                                       {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, double> > ());
	}
#line 2642 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 147: // compu_tab_attribute: default_value
#line 578 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCompuTab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 2648 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 148: // compu_tab_attribute: default_value_numeric
#line 579 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCompuTab().DefaultValueNumeric(yystack_[0].value.as < double > ()); }
#line 2654 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 149: // compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB
#line 582 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name(yystack_[7].value.as < std::string > ());
	tab.Description(yystack_[6].value.as < std::string > ());
	tab.Type(StringToConversionType(yystack_[5].value.as < std::string > ()));
	tab.Rows(yystack_[4].value.as < uint64_t > ());
	tab.KeyValueList(yystack_[3].value.as < std::map<double, std::string> > ());
	}
#line 2667 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 152: // compu_vtab_attribute: default_value
#line 592 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 2673 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 153: // compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE
#line 595 "D:/projects/a2llib/src/a2lparser.y"
                                                             {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name(yystack_[6].value.as < std::string > ());
       	tab.Description(yystack_[5].value.as < std::string > ());
       	tab.Rows(yystack_[4].value.as < uint64_t > ());
        tab.KeyValueList(yystack_[3].value.as < std::map<std::pair<double, double>, std::string> > ());
       	}
#line 2685 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 156: // compu_vtab_range_attribute: default_value
#line 604 "D:/projects/a2llib/src/a2lparser.y"
                                          { scanner.CurrentCompuVtab().DefaultValue(yystack_[0].value.as < std::string > ()); }
#line 2691 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 157: // def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC
#line 606 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 2697 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 158: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 609 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 2703 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 159: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 611 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::vector<double> > () = yystack_[2].value.as < std::vector<double> > (); }
#line 2709 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 160: // formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA
#line 613 "D:/projects/a2llib/src/a2lparser.y"
                                                                    { yylhs.value.as < std::pair<std::string,std::string> > () = {yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > ()}; }
#line 2715 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 161: // formula_attribute: %empty
#line 614 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 2721 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 162: // formula_attribute: formula_inv
#line 615 "D:/projects/a2llib/src/a2lparser.y"
                      {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 2727 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 163: // frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME
#line 617 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& frame = scanner.CurrentFrame();
	frame.Name(yystack_[6].value.as < std::string > ());
	frame.Description(yystack_[5].value.as < std::string > ());
	frame.ScalingUnit(yystack_[4].value.as < uint64_t > ());
	frame.Rate(yystack_[3].value.as < uint64_t > ());
}
#line 2739 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 166: // frame_attribute: frame_measurement
#line 626 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentFrame().FrameMeasurement(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2745 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 167: // frame_attribute: if_data
#line 627 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFrame().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2751 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 168: // function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION
#line 629 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {
	auto& func = scanner.CurrentFunction();
	func.Name(yystack_[4].value.as < std::string > ());
	func.Description(yystack_[3].value.as < std::string > ());
}
#line 2761 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 171: // function_attribute: annotation
#line 636 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentFunction().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ());}
#line 2767 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 173: // function_attribute: def_characteristic
#line 638 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().DefaultCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2773 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 174: // function_attribute: function_version
#line 639 "D:/projects/a2llib/src/a2lparser.y"
                           { scanner.CurrentFunction().Version(yystack_[0].value.as < std::string > ());}
#line 2779 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 175: // function_attribute: if_data
#line 640 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentFunction().AddIfData(yystack_[0].value.as < std::string > ());}
#line 2785 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 176: // function_attribute: in_measurement
#line 641 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentFunction().InMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2791 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 177: // function_attribute: loc_measurement
#line 642 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().LocMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2797 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 178: // function_attribute: out_measurement
#line 643 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentFunction().OutMeasurements(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2803 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 179: // function_attribute: ref_characteristic
#line 644 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentFunction().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2809 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 180: // function_attribute: sub_function
#line 645 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentFunction().SubFunctions(yystack_[0].value.as < std::vector<std::string> > ());}
#line 2815 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 181: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 647 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2821 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 182: // function_list: FUNCTION_LIST ident_list
#line 648 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 2827 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP
#line 650 "D:/projects/a2llib/src/a2lparser.y"
                                                                   {
	auto& group = scanner.CurrentGroup();
	group.Name(yystack_[4].value.as < std::string > ());
	group.Description(yystack_[3].value.as < std::string > ());
}
#line 2837 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 186: // group_attribute: annotation
#line 658 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentGroup().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2843 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 187: // group_attribute: function_list
#line 659 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentGroup().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2849 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 188: // group_attribute: if_data
#line 660 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentGroup().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2855 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 189: // group_attribute: ref_characteristic
#line 661 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentGroup().RefCharacteristics(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2861 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 190: // group_attribute: ref_measurement
#line 662 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentGroup().RefMeasurements(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2867 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 191: // group_attribute: root
#line 663 "D:/projects/a2llib/src/a2lparser.y"
               { scanner.CurrentGroup().Root(true); }
#line 2873 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 192: // group_attribute: sub_group
#line 664 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentGroup().SubGroups(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2879 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 193: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 666 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = yystack_[3].value.as < std::string > ();
}
#line 2888 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 196: // header_attribute: project_no
#line 674 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 2897 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 197: // header_attribute: version
#line 677 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 2906 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT
#line 682 "D:/projects/a2llib/src/a2lparser.y"
                                                                           { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 2912 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 199: // instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE
#line 684 "D:/projects/a2llib/src/a2lparser.y"
                                                                                              {
	auto& instance = scanner.CurrentInstance();
	instance.Name(yystack_[6].value.as < std::string > ());
	instance.Description(yystack_[5].value.as < std::string > ());
	instance.RefTypeDef(yystack_[4].value.as < std::string > ());
	instance.Address(yystack_[3].value.as < uint64_t > ());
}
#line 2924 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 202: // instance_attribute: address_type
#line 693 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentInstance().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 2930 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 203: // instance_attribute: annotation
#line 694 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2936 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 204: // instance_attribute: calibration_access
#line 695 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentInstance().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2942 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 205: // instance_attribute: display_identifier
#line 696 "D:/projects/a2llib/src/a2lparser.y"
                             {  scanner.CurrentInstance().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2948 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 206: // instance_attribute: ecu_address_extension
#line 697 "D:/projects/a2llib/src/a2lparser.y"
                                {  scanner.CurrentInstance().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2954 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 207: // instance_attribute: if_data
#line 698 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentInstance().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2960 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 208: // instance_attribute: layout
#line 699 "D:/projects/a2llib/src/a2lparser.y"
                 {  scanner.CurrentInstance().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 2966 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 209: // instance_attribute: matrix_dim
#line 700 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 2972 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 210: // instance_attribute: max_refresh
#line 701 "D:/projects/a2llib/src/a2lparser.y"
                      {  scanner.CurrentInstance().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2978 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 211: // instance_attribute: model_link
#line 702 "D:/projects/a2llib/src/a2lparser.y"
                     {  scanner.CurrentInstance().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2984 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 212: // instance_attribute: overwrite
#line 703 "D:/projects/a2llib/src/a2lparser.y"
                    { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
#line 2991 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 213: // instance_attribute: read_write
#line 705 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentInstance().ReadWrite(true); }
#line 2997 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 214: // instance_attribute: symbol_link
#line 706 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentInstance().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3003 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 215: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 708 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 3009 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 216: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 710 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 3015 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float measurement_attributes A2L_END MEASUREMENT
#line 713 "D:/projects/a2llib/src/a2lparser.y"
                                                   {
	auto& meas = scanner.CurrentMeasurement();
	meas.Name(yystack_[10].value.as < std::string > ());
	meas.Description(yystack_[9].value.as < std::string > ());
	meas.DataType(StringToDataType(yystack_[8].value.as < std::string > ()));
	meas.Conversion(yystack_[7].value.as < std::string > ());
	meas.ArraySize(yystack_[6].value.as < uint64_t > ());
	meas.LowerLimit(yystack_[5].value.as < double > ());
	meas.UpperLimit(yystack_[4].value.as < double > ());
	}
#line 3030 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 220: // measurement_attribute: address_type
#line 725 "D:/projects/a2llib/src/a2lparser.y"
                                    { scanner.CurrentMeasurement().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 3036 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 221: // measurement_attribute: annotation
#line 726 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 3042 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 222: // measurement_attribute: array_size
#line 727 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ArraySize(yystack_[0].value.as < uint64_t > ()); }
#line 3048 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 223: // measurement_attribute: bit_mask
#line 728 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 3054 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 224: // measurement_attribute: bit_operation
#line 729 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().BitOperation(yystack_[0].value.as < A2lBitOperation > ()); }
#line 3060 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 225: // measurement_attribute: byte_order
#line 730 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 3066 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 226: // measurement_attribute: discrete
#line 731 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentMeasurement().Discrete(true); }
#line 3072 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 227: // measurement_attribute: display_identifier
#line 732 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 3078 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 228: // measurement_attribute: ecu_address
#line 733 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().EcuAddress(yystack_[0].value.as < uint64_t > ()); }
#line 3084 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 229: // measurement_attribute: ecu_address_extension
#line 734 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentMeasurement().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 3090 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 230: // measurement_attribute: error_mask
#line 735 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ErrorMask(yystack_[0].value.as < uint64_t > ()); }
#line 3096 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 231: // measurement_attribute: format
#line 736 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Format(yystack_[0].value.as < std::string > ()); }
#line 3102 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 232: // measurement_attribute: function_list
#line 737 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentMeasurement().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3108 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 233: // measurement_attribute: if_data
#line 738 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3114 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 234: // measurement_attribute: layout
#line 739 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentMeasurement().Layout(yystack_[0].value.as < A2lLayout > ()); }
#line 3120 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 235: // measurement_attribute: matrix_dim
#line 740 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 3126 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 236: // measurement_attribute: max_refresh
#line 741 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 3132 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 237: // measurement_attribute: model_link
#line 742 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 3138 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 238: // measurement_attribute: phys_unit
#line 743 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentMeasurement().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3144 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 239: // measurement_attribute: read_write
#line 744 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentMeasurement().ReadWrite(true); }
#line 3150 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 240: // measurement_attribute: ref_memory_segment
#line 745 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentMeasurement().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 3156 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 241: // measurement_attribute: symbol_link
#line 746 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentMeasurement().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 3162 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 242: // measurement_attribute: virtual
#line 747 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentMeasurement().Virtuals(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 3168 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 284: // module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE
#line 794 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
	auto& module = scanner.CurrentModule();
	module.Name(yystack_[4].value.as < std::string > ());
	module.Description(yystack_[3].value.as < std::string > ());
}
#line 3178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 287: // module_attribute: a2ml
#line 802 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 3184 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 288: // module_attribute: axis_pts
#line 803 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 3192 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // module_attribute: blob
#line 806 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 3200 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // module_attribute: characteristic
#line 809 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 3208 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // module_attribute: compu_method
#line 812 "D:/projects/a2llib/src/a2lparser.y"
                       {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
#line 3216 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // module_attribute: compu_tab
#line 815 "D:/projects/a2llib/src/a2lparser.y"
                    {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
#line 3224 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 293: // module_attribute: compu_vtab
#line 818 "D:/projects/a2llib/src/a2lparser.y"
                     {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
#line 3232 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 294: // module_attribute: compu_vtab_range
#line 821 "D:/projects/a2llib/src/a2lparser.y"
                           {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
#line 3240 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 295: // module_attribute: frame
#line 824 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
#line 3248 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 296: // module_attribute: function
#line 827 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
#line 3256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 297: // module_attribute: group
#line 830 "D:/projects/a2llib/src/a2lparser.y"
                {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
#line 3264 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 298: // module_attribute: if_data
#line 833 "D:/projects/a2llib/src/a2lparser.y"
                  {
                auto& module = scanner.CurrentModule();
                module.AddIfData(yystack_[0].value.as < std::string > ()); }
#line 3272 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 299: // module_attribute: instance
#line 836 "D:/projects/a2llib/src/a2lparser.y"
                   {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
#line 3280 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 300: // module_attribute: measurement
#line 839 "D:/projects/a2llib/src/a2lparser.y"
                      {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
#line 3288 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 313: // out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT
#line 855 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3294 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 314: // overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE
#line 857 "D:/projects/a2llib/src/a2lparser.y"
                                                                                     {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name(yystack_[4].value.as < std::string > ());
	overwrite.AxisNo(yystack_[3].value.as < uint64_t > ());
}
#line 3304 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 317: // overwrite_attribute: conversion
#line 864 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentOverwrite().Conversion(yystack_[0].value.as < std::string > ()); }
#line 3310 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 318: // overwrite_attribute: extended_limits
#line 865 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentOverwrite().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 3316 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 319: // overwrite_attribute: format
#line 866 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Format(yystack_[0].value.as < std::string > ()); }
#line 3322 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 320: // overwrite_attribute: input_quantity
#line 867 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentOverwrite().InputQuantity(yystack_[0].value.as < std::string > ()); }
#line 3328 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 321: // overwrite_attribute: limits
#line 868 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentOverwrite().Limits(yystack_[0].value.as < double > ()); }
#line 3334 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 322: // overwrite_attribute: monotony
#line 869 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentOverwrite().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 3340 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 323: // overwrite_attribute: phys_unit
#line 870 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentOverwrite().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 3346 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 324: // project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT
#line 872 "D:/projects/a2llib/src/a2lparser.y"
                                                                           {
	auto& project = file.Project();
	project.Name(yystack_[4].value.as < std::string > ());
	project.Description(yystack_[3].value.as < std::string > ());
}
#line 3356 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 328: // project_attribute: module
#line 880 "D:/projects/a2llib/src/a2lparser.y"
             {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    }
#line 3365 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 387: // ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC
#line 944 "D:/projects/a2llib/src/a2lparser.y"
                                                                                       { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3371 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 388: // ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP
#line 945 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3377 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 389: // ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT
#line 946 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3383 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 397: // sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION
#line 956 "D:/projects/a2llib/src/a2lparser.y"
                                                                     { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3389 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 398: // sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP
#line 957 "D:/projects/a2llib/src/a2lparser.y"
                                                            { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3395 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 483: // virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL
#line 1060 "D:/projects/a2llib/src/a2lparser.y"
                                                      { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 3401 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 484: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 1062 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 3407 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 485: // a2ml: A2ML
#line 1065 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3413 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 1066 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 3422 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 487: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 1071 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 3431 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // asap2_version: ASAP2_VERSION STRING
#line 1074 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 3439 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // address_type: ADDRESS_TYPE IDENT
#line 1079 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 3445 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 498: // annotation_label: ANNOTATION_LABEL STRING
#line 1087 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3451 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 499: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 1088 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3457 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // array_size: ARRAY_SIZE any_uint
#line 1089 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3463 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // ar_prototype_of: AR_PROTOTYPE_OF IDENT
#line 1090 "D:/projects/a2llib/src/a2lparser.y"
                                       {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3469 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 502: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 1091 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3475 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 509: // bit_mask: BIT_MASK any_uint
#line 1098 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3481 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 510: // byte_order: BYTE_ORDER IDENT
#line 1099 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 3487 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // calibration_access: CALIBRATION_ACCESS IDENT
#line 1100 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 3493 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // coeffs: COEFFS any_float any_float any_float any_float any_float any_float
#line 1102 "D:/projects/a2llib/src/a2lparser.y"
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
#line 3508 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 514: // coeffs_linear: COEFFS_LINEAR any_float any_float
#line 1112 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	std::vector<double> list;
	list.push_back(yystack_[1].value.as < double > ());
	list.push_back(yystack_[0].value.as < double > ());
        yylhs.value.as < std::vector<double> > () = list;
}
#line 3519 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 515: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 1118 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 516: // compu_tab_ref: COMPU_TAB_REF IDENT
#line 1119 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 518: // conversion: CONVERSION IDENT
#line 1121 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3537 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 520: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 1123 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 524: // default_value: DEFAULT_VALUE STRING
#line 1127 "D:/projects/a2llib/src/a2lparser.y"
                                    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3549 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 525: // default_value_numeric: DEFAULT_VALUE_NUMERIC any_float
#line 1128 "D:/projects/a2llib/src/a2lparser.y"
                                                       { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 526: // deposit: DEPOSIT IDENT
#line 1129 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 3561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 1131 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 529: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 1132 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 3573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 536: // ecu_address: ECU_ADDRESS any_uint
#line 1139 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 537: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 1140 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 3585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // encoding: ENCODING IDENT
#line 1142 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 3591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // error_mask: ERROR_MASK any_uint
#line 1144 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 542: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 1145 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 3603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 543: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 1146 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 3609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 1147 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 3615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 551: // format: FORMAT STRING
#line 1154 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 552: // formula_inv: FORMULA_INV STRING
#line 1155 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // frame_measurement: FRAME_MEASUREMENT ident_list
#line 1156 "D:/projects/a2llib/src/a2lparser.y"
                                                { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 3633 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 554: // function_version: FUNCTION_VERSION STRING
#line 1157 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3639 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 557: // if_data: IF_DATA
#line 1160 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3645 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 558: // input_quantity: INPUT_QUANTITY IDENT
#line 1161 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // layout: LAYOUT IDENT
#line 1162 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < A2lLayout > () = StringToLayout(yystack_[0].value.as < std::string > ()); }
#line 3657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 560: // left_shift: LEFT_SHIFT any_uint
#line 1163 "D:/projects/a2llib/src/a2lparser.y"
                                { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3663 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 561: // limits: LIMITS FLOAT any_float
#line 1164 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < double > () = yystack_[1].value.as < double > ();}
#line 3669 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 562: // matrix_dim: MATRIX_DIM uint_list
#line 1165 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 3675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 563: // max_grad: MAX_GRAD any_float
#line 1166 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3681 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1167 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 3687 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // model_link: MODEL_LINK STRING
#line 1168 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3693 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // monotony: MONOTONY IDENT
#line 1169 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 3699 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 574: // number: NUMBER any_uint
#line 1177 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3705 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 581: // phys_unit: PHYS_UNIT STRING
#line 1184 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3711 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 582: // proj_no: IDENT
#line 1185 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3717 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // proj_no: UINT
#line 1186 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 3723 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // project_no: PROJECT_NO proj_no
#line 1187 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3729 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 587: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1191 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3735 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 588: // ref_unit: REF_UNIT IDENT
#line 1192 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3741 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 590: // right_shift: RIGHT_SHIFT any_uint
#line 1194 "D:/projects/a2llib/src/a2lparser.y"
                                  { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3747 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 613: // status_string_ref: STATUS_STRING_REF IDENT
#line 1217 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3753 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 614: // step_size: STEP_SIZE any_float
#line 1218 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 3759 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // symbol_link: SYMBOL_LINK STRING any_int
#line 1220 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 3765 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 625: // version: A2L_VERSION STRING
#line 1229 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 3771 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 3775 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -841;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
     102,   150,    86,   114,  -841,  -841,  -841,  -841,   133,  -841,
     -13,   133,  -841,  -841,  -841,   144,   133,   180,  -841,   191,
     -25,  -841,  -841,   337,  -841,   192,   197,   131,  -841,  -841,
     272,  -841,    67,  -841,   179,   309,   174,  -841,  -841,  -841,
      69,  -841,  -841,  -841,  -841,  -841,   821,   198,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,   326,   355,   358,
     373,   394,   416,   420,   425,   428,   437,   443,   462,   463,
     464,   466,   468,   469,   472,   476,   477,   483,   485,   486,
    -841,  -841,   487,   488,   493,   498,   499,   503,   508,   512,
     513,   514,   515,   516,  -841,  -841,  -841,   517,   520,   521,
     522,   523,   525,   526,  -841,    65,   133,   133,   502,   528,
     529,   531,   133,   133,  -841,  -841,   532,   534,    39,   135,
    1016,   535,   540,   133,   541,   542,   470,   543,    61,   124,
     343,   547,   548,  -841,  -841,  -841,  -841,  -841,  -841,   551,
     133,   133,   552,   133,   133,  -841,   133,    78,   178,   133,
     554,   432,   133,   133,   133,   133,   133,   133,   133,   556,
     133,   557,   558,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,     1,   418,   133,   562,   567,
     573,   577,   341,   578,   133,   579,   580,   582,   584,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,   424,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,   586,   559,  -841,   592,   595,  -841,   597,   456,   412,
    -841,  -841,  -841,  -841,   600,   601,  -841,  -841,  -841,  -841,
     604,  -841,   605,   606,  -841,  -841,   335,  -841,   501,   518,
     609,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,   248,   519,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   133,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   611,   614,
     616,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   618,  -841,  -841,   620,   623,
     626,   627,   631,   632,   633,   639,   641,   644,   645,  -841,
    -841,  -841,  -841,  -841,   648,   651,   655,   657,   659,   665,
     671,   673,   674,   676,   678,   680,   681,   682,   686,   690,
     692,   693,   694,   695,   696,   698,   699,   701,   703,   704,
     705,   706,   711,   712,   133,   335,    90,   335,   621,    96,
    -841,  -841,  -841,  -841,   713,   285,   335,   387,   335,  -841,
     335,   335,  -841,  -841,  -841,  -841,   335,    46,   107,  -841,
     714,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,   716,   624,   335,   133,   133,   717,  -841,
     720,   722,   725,   729,   731,   133,  -841,  -841,  -841,  -841,
    -841,   732,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,   734,   739,   465,   740,  -841,  -841,   741,   335,   570,
     560,  -841,   743,  -841,  -841,  -841,  -841,  -841,    19,   303,
     290,  -841,   550,   746,   749,    51,   715,   750,   751,   341,
     133,   753,   754,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,   757,   123,   335,   141,   758,    74,   759,
     718,   761,  -841,  -841,   675,  -841,  -841,  -841,  -841,    89,
     742,   308,   354,   365,   372,   378,   388,   389,   397,   404,
    -841,    52,   667,   771,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
     335,  -841,   133,    33,   772,   774,   775,   776,   777,   778,
     779,   780,   133,  -841,  -841,   335,   335,   781,  -841,  -841,
     596,   786,   341,   335,  -841,  -841,  -841,  -841,   650,   599,
    -841,   789,    -2,  -841,  -841,   133,   792,  -841,  -841,  -841,
    -841,   133,  -841,   341,   335,   707,   747,   335,   335,   797,
     799,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   752,
     335,  -841,  -841,  -841,  -841,   755,  -841,  -841,  -841,  -841,
    -841,  -841,   716,   782,   783,   802,   805,  -841,  -841,  -841,
     807,   810,  -841,   756,   708,   709,   677,   669,   638,   719,
     679,   643,   819,  -841,  -841,   133,   335,   383,  -841,  -841,
    -841,   822,  -841,  -841,  -841,  -841,  -841,   824,  -841,  -841,
     335,   335,   335,   825,  -841,  -841,   341,   335,  -841,  -841,
     628,   634,   826,   830,  -841,  -841,  -841,   335,   833,  -841,
    -841,   335,   831,  -841,   335,   335,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,   809,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,   133,  -841,  -841,   794,
     793,  -841,   341,   836,  -841,   450,   335,  -841,  -841,   133,
     341,  -841,   405,  -841,  -841,  -841,  -841,   335,   773,  -841,
     760,   335,  -841,   295,  -841,  -841,   473,  -841,  -841,  -841,
      40,   133,   274,   660,  -841,  -841,  -841,  -841,   403,   649,
    -841,   341,   647,  -841,  -841,   318,   842,   839,  -841,   335,
     829,  -841,   564,    62,   735,   133,   133,  -841,   133,   133,
     851,   852,   854,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,   319,   744,  -841,
     133,  -841,  -841,  -841,   361,   835,   670,   856,   335,   133,
     335,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,   823,   687,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,    34,   341,  -841,   591,
      63,   820,   862,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,   785,   335,  -841,   733,   865,   875,   872,
     878,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   879,
     881,  -841,  -841,  -841,   409,   410,   700,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   884,  -841,  -841,   335,  -841,
    -841,  -841,   721,  -841,  -841,  -841,  -841,  -841,   341,   247,
     859,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,   880,  -841,   886,  -841,  -841,  -841,   335,  -841,  -841,
    -841,   335,  -841,    36,   413,  -841,   848,   341,   723,   724,
    -841,   889,  -841,  -841,   341,  -841,  -841,   419,  -841,  -841,
    -841,   855,   133,   133,  -841,  -841,  -841,  -841,  -841,   689,
    -841,    70,  -841,  -841,   892,  -841,   442,   787,   446,  -841,
    -841,  -841,  -841,   784,  -841,   133,   834,  -841,   691,  -841,
     335,  -841,  -841,   335,  -841,   710,    42,   871,   899,   900,
     335,   335,   335,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,   335,   335,  -841,   364,   133,   133,   827,
    -841,  -841,  -841,  -841
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
       0,     0,     0,     0,   454,   588,     0,     0,   388,    25,
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
    -841,    -8,  -198,  -175,  -802,  -841,  -841,  -841,  -841,  -841,
    -841,  -464,  -841,  -841,  -841,  -167,  -841,  -841,  -841,  -841,
      64,  -841,  -841,  -841,  -841,  -841,    68,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -736,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   885,  -841,
    -841,  -841,   745,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -459,   791,   800,   801,   806,   808,   811,   812,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -629,  -792,  -489,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -139,  -841,  -840,  -551,
    -493,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -492,  -841,
      66,  -841,    76,  -828,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -819,  -841,  -841,  -841,   -12,  -841,  -162,  -841,
    -741,  -841,  -841,  -541,  -841,  -491,  -490,  -838,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,    71,  -841,  -841,  -841,  -841,
    -841,  -841,  -797,  -841,  -841,  -823,    95,  -793,   328,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -824,  -841,  -488,     0,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   788
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,     8,   829,   486,   802,   735,  1136,   480,   481,   356,
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
      14,   376,   761,    16,   410,   371,   382,   569,    18,   570,
     565,   631,   632,   636,   637,   630,   639,   949,   585,   908,
     922,   960,   958,   660,   973,   887,   950,   611,   612,   613,
     614,   615,   616,   974,   871,   617,   618,   619,  1012,   739,
    1071,   911,   925,   171,   888,   629,   904,   919,   957,   398,
     600,   554,   959,   942,   999,   978,  1002,   172,   173,   174,
     175,   176,   177,   178,   338,   339,  1000,   489,   149,   150,
    1004,    34,    46,    47,  1093,  1001,   489,   489,   705,    25,
      35,   358,   359,   179,    48,   879,     9,   489,   489,  1026,
     865,  1035,   713,   714,   553,  1005,    26,  1003,   923,   559,
     560,  1029,   998,   180,   979,  1039,  1037,   554,   181,   938,
    1030,   604,   601,   554,     1,   715,   716,    10,   159,   160,
     399,   400,   676,   676,   165,   166,   685,   686,    11,  1129,
      15,  1041,  1036,   676,   676,   333,  1038,  1024,   195,   196,
     601,   712,     6,     7,   623,   699,    49,  1072,    35,   624,
      17,   197,   351,   352,   561,   354,   355,     5,   357,     6,
       7,   384,   499,   499,   387,   388,   389,   390,   391,   392,
     393,   661,   395,   687,   688,    49,    49,  1042,   689,   360,
      43,   372,   373,    44,    49,  1015,   740,    19,   662,   402,
    1073,  1057,   732,  1023,    20,   198,   412,   199,   200,    29,
     762,   182,   763,    30,  1074,   605,   340,   601,   700,   903,
     918,    36,   201,    49,   663,   202,   941,   203,   562,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,  1119,   204,  1125,   151,   980,
     152,  1043,   489,   489,    31,   661,   205,  1120,   374,    33,
     562,  1128,  1127,    41,    49,   880,  1123,   905,   920,   572,
     552,   573,   557,   669,   945,   812,   620,   909,   924,   850,
     690,   574,   851,   593,   953,   595,   597,   668,  1126,   620,
     583,   599,   723,  1117,   620,   589,    42,   206,   676,   101,
     207,   930,   931,   344,   345,   346,   608,   407,   408,   409,
     640,   208,   102,   873,   875,   881,   882,   626,   886,   375,
      20,    27,   633,   482,   483,   484,   485,   499,   499,   407,
     408,   409,   946,   947,   954,   955,   943,   961,   724,   856,
     620,   103,   179,   577,   104,   996,   989,   868,  1139,   725,
     932,   620,   482,   483,   484,   485,   726,   505,   620,   105,
     917,   680,   727,   656,   620,  1016,   799,   800,   857,   578,
     575,   576,   728,   729,   620,   620,   495,   579,   500,   897,
     106,   730,   898,   620,   554,   179,   895,   896,   731,   842,
     620,   620,   860,  1058,  1059,   620,   620,  1079,   374,   620,
     698,   933,   107,  1087,    49,   620,   108,   994,   995,   501,
     181,   109,   577,   624,   110,   580,  1027,  1028,  1033,  1034,
    1025,  1040,   581,   111,   856,   898,  1096,   179,   620,   112,
    1098,   899,   620,   832,   833,   860,   551,   702,   578,   707,
     861,   891,   892,   340,   756,   736,   579,  1014,   113,   862,
     114,   115,   116,   857,   117,   118,   853,   854,   119,   336,
     751,   752,   120,   121,   897,   770,   970,   898,   757,   122,
     554,   123,   124,    49,   126,   127,   900,   860,   641,   642,
     128,   582,   855,   861,   580,   129,   130,   649,   161,   771,
     131,   581,   774,   775,   856,   132,  1054,   179,   624,   133,
     134,   135,   136,   137,   141,   779,   489,   142,   143,   144,
     145,   490,   146,   147,   162,   163,   899,   164,   169,   900,
     170,   401,   331,   857,   578,   861,   332,   334,   335,   347,
     337,   858,   579,   348,   386,   349,   859,   350,   810,   353,
     385,   798,   394,   396,   397,   465,   491,   860,   966,   403,
     582,   417,   681,   374,   404,   806,   807,   808,  1067,    49,
     405,   900,   811,   623,   406,   411,   413,   414,   624,   415,
     580,   416,   817,   464,  1019,  1020,   819,   581,   467,   821,
     822,   468,  1086,   470,  1088,   471,   473,   474,   492,   472,
     476,   478,   841,   479,   493,   861,   498,   497,   506,   625,
     507,   502,   508,   967,   862,   509,   510,   621,   622,   511,
     558,   837,   512,   513,   738,   179,   577,   514,   515,   516,
     494,   554,   843,   927,   750,   517,   849,   518,   898,   495,
     519,   520,   913,   914,   521,   653,   582,   522,   860,   863,
     181,   523,   578,   524,   878,   525,   554,   767,   889,   577,
     579,   526,   968,   769,   964,   898,   969,   527,   934,   528,
     529,   496,   530,   952,   531,   860,   532,   533,   534,   970,
     856,   374,   535,   179,   933,   578,   536,    49,   537,   538,
     539,   540,   541,   579,   542,   543,   861,   544,   580,   545,
     546,   547,   548,  1106,  1107,   581,   970,   549,   550,   857,
     571,   610,   620,  1008,   643,  1010,   644,   797,   645,  1018,
      49,   646,   859,   861,   623,   647,   340,   648,   650,   624,
     651,   580,   862,   860,  1108,   652,   654,   655,   581,   657,
     659,   673,   674,   658,   179,   675,   678,   679,   677,   623,
     682,   683,  1021,   684,   624,   704,   708,  1032,   710,   900,
     625,  1109,   711,   720,   582,   709,   733,   734,   742,   181,
     743,   744,   745,   746,   747,   748,   749,   753,   825,  1047,
     754,   861,   755,   760,   898,  1110,  1111,   759,   768,   758,
     773,   840,   772,   776,   860,   777,   778,   582,   782,   783,
     781,   780,   784,   785,   786,   788,   790,   791,   792,   793,
    1064,   787,   789,   890,   795,   796,  1112,   813,   803,   794,
     804,   809,   815,  1062,   814,   970,   816,   818,   820,   824,
     827,   828,   831,   963,   844,   928,   893,   982,   983,   962,
     984,   985,   861,   981,    77,   340,   846,   965,   986,   987,
     988,  1006,  1007,   992,    78,   979,  1085,  1005,  1045,  1044,
      79,  1049,  1069,  1048,    80,    81,  1070,    82,    83,  1011,
    1046,  1050,   993,  1051,  1052,  1056,  1055,  1066,   900,  1060,
    1061,  1009,  1065,  1068,  1080,  1084,  1092,  1089,  1095,  1102,
    1063,  1097,  1101,  1130,  1099,  1131,  1132,   915,    28,   935,
    1082,   948,  1083,   379,  1143,   921,   956,  1031,    84,  1094,
      85,   884,   696,    86,     0,  1103,  1017,   225,  1104,     0,
      87,   276,     0,     0,     0,  1133,  1134,  1135,  1113,    88,
     277,   278,     0,    89,    90,     0,   279,     0,   280,     0,
       0,   281,   282,     0,     0,     0,     0,     0,  1137,  1138,
       0,  1140,     0,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,    95,    96,    97,    98,     0,     0,    99,     0,
     226,     0,     0,     0,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,     0,     0,  1090,  1091,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1100,   233,   234,
     235,   236,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,  1141,
    1142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,   249,     0,   250,     0,
     251,   252,   253,   254,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,   257,   258,   259,   260,   261,   262,     0,     0,   263,
     264,   265,   266,   267,     0,     0,   268,   269,   270,   271,
     272,   273,   274
  };

  const short
  A2lParser::yycheck_[] =
  {
       8,   168,     4,    11,   202,   167,   168,   471,    16,   473,
     469,   504,   504,   504,   504,   504,   504,   845,   477,   838,
     839,   845,   845,     4,   852,   827,   845,   491,   492,   493,
     494,   495,   496,   852,   826,   499,   500,   501,     4,     6,
       4,   838,   839,     4,     4,   504,   838,   839,   845,    48,
       4,    17,   845,   845,   894,   852,   894,    18,    19,    20,
      21,    22,    23,    24,     3,     4,   894,    25,     3,     4,
     894,     4,     3,     4,     4,   894,    25,    25,     4,   104,
      13,     3,     4,    44,    15,   826,     0,    25,    25,   929,
     826,   929,     3,     4,     4,    32,   121,   894,   839,     3,
       4,   929,   894,    64,    42,   929,   929,    17,    69,   845,
     929,     4,    66,    17,    12,    26,    27,     3,   126,   127,
     119,   120,    71,    71,   132,   133,     3,     4,    14,    87,
     143,    68,   929,    71,    71,   143,   929,   929,     3,     4,
      66,   605,     9,    10,   110,     4,   106,   111,    13,   115,
       6,    16,   160,   161,    58,   163,   164,     7,   166,     9,
      10,   169,   100,   100,   172,   173,   174,   175,   176,   177,
     178,   152,   180,    50,    51,   106,   106,   114,    55,   101,
       6,     3,     4,     9,   106,   926,   153,     7,   169,   197,
     154,   993,   140,   929,     3,    60,   204,    62,    63,     7,
     202,   162,   204,     6,   168,    98,   145,    66,    67,   838,
     839,   144,    77,   106,   195,    80,   845,    82,   184,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,  1105,   131,  1105,   203,   207,
     205,   208,    25,    25,   143,   152,   141,  1105,   100,     7,
     184,  1105,  1105,   104,   106,   826,  1105,   838,   839,     4,
     465,     6,   467,     3,   845,   759,     6,   838,   839,     4,
     177,   476,     7,   478,   845,   480,   481,     4,  1105,     6,
     477,   486,     4,  1105,     6,   477,     7,   182,    71,   121,
     185,     3,     4,   199,   200,   201,   488,     8,     9,    10,
     505,   196,     6,   826,   826,   826,   826,   504,   826,   161,
       3,     4,   504,     8,     9,    10,    11,   100,   100,     8,
       9,    10,   845,   845,   845,   845,   845,   845,     4,    41,
       6,     6,    44,    45,     6,     4,    47,   826,     4,     4,
      52,     6,     8,     9,    10,    11,     4,   385,     6,     6,
     839,   579,     4,   558,     6,   926,     3,     4,    70,    71,
       3,     4,     4,     4,     6,     6,   148,    79,   150,    81,
       6,     4,    84,     6,    17,    44,     3,     4,     4,     4,
       6,     6,    94,     4,     4,     6,     6,     4,   100,     6,
     595,   103,     6,     4,   106,     6,     6,   891,   892,   181,
      69,     6,    45,   115,     6,   117,   929,   929,   929,   929,
     929,   929,   124,     6,    41,    84,     4,    44,     6,     6,
       4,   133,     6,     3,     4,    94,   464,   596,    71,   598,
     142,   187,   188,   145,   662,   640,    79,   926,     6,   151,
       7,     7,     6,    70,     6,     6,     3,     4,     6,     9,
     655,   656,     6,     6,    81,   683,   125,    84,   663,     6,
      17,     6,     6,   106,     7,     7,   178,    94,   506,   507,
       7,   183,    29,   142,   117,     7,     7,   515,     6,   684,
       7,   124,   687,   688,    41,     7,   980,    44,   115,     7,
       7,     7,     7,     7,     7,   700,    25,     7,     7,     7,
       7,    30,     7,     7,     6,     6,   133,     6,     6,   178,
       6,   123,     7,    70,    71,   142,     6,     6,     6,   206,
       7,    78,    79,     6,   122,     7,    83,     6,   756,     7,
       6,   736,     6,     6,     6,     6,    65,    94,     4,     7,
     183,   147,   580,   100,     7,   750,   751,   752,  1042,   106,
       7,   178,   757,   110,     7,     7,     7,     7,   115,     7,
     117,     7,   767,     7,     3,     4,   771,   124,     6,   774,
     775,     6,  1066,     6,  1068,   149,     6,     6,   107,   197,
       6,     6,   810,     7,   113,   142,     7,    99,     7,   146,
       6,   102,     6,    59,   151,     7,     6,     3,     4,     6,
       9,   806,     6,     6,   642,    44,    45,     6,     6,     6,
     139,    17,   817,   841,   652,     6,   821,     6,    84,   148,
       6,     6,     3,     4,     6,   190,   183,     6,    94,   826,
      69,     6,    71,     6,   826,     6,    17,   675,   830,    45,
      79,     6,   108,   681,   849,    84,   112,     6,   845,     6,
       6,   180,     6,   845,     6,    94,     6,     6,     6,   125,
      41,   100,     6,    44,   103,    71,     6,   106,     6,     6,
       6,     6,     6,    79,     6,     6,   142,     6,   117,     6,
       6,     6,     6,     3,     4,   124,   125,     6,     6,    70,
       7,     7,     6,   898,     7,   900,     6,   735,     6,   927,
     106,     6,    83,   142,   110,     6,   145,     6,     6,   115,
       6,   117,   151,    94,    34,     6,     6,     6,   124,   179,
       7,   201,     6,   193,    44,     6,     6,     6,    43,   110,
       7,     7,   929,     6,   115,     7,     7,   929,     7,   178,
     146,    61,    97,    31,   183,    57,   109,     6,     6,    69,
       6,     6,     6,     6,     6,     6,     6,     6,   796,   964,
     194,   142,     6,     4,    84,    85,    86,   198,     6,   149,
      53,   809,    95,     6,    94,     6,    54,   183,    25,     7,
      28,    56,     7,     6,     4,   107,   139,   148,   180,   100,
    1018,    65,   113,   831,   181,     6,   116,   199,     6,   150,
       6,     6,     6,  1008,   200,   125,     6,     4,     7,    30,
      46,    48,     6,     4,    71,   198,   186,   855,   856,     7,
     858,   859,   142,   118,    33,   145,    96,    28,     7,     7,
       6,   191,     6,   119,    43,    42,  1064,    32,     6,    49,
      49,     6,  1047,   140,    53,    54,  1051,    56,    57,   192,
      95,     6,   890,    11,     6,     4,     7,     7,   178,   189,
       6,   899,    33,     7,    46,     6,   207,    42,     6,   208,
     179,   114,    68,    32,   120,     6,     6,   839,    23,   845,
     187,   845,   188,   168,    87,   839,   845,   929,    97,  1081,
      99,   826,   594,   102,    -1,  1100,   926,   139,  1103,    -1,
     109,   140,    -1,    -1,    -1,  1110,  1111,  1112,  1105,   118,
     140,   140,    -1,   122,   123,    -1,   140,    -1,   140,    -1,
      -1,   140,   140,    -1,    -1,    -1,    -1,    -1,  1133,  1134,
      -1,  1136,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
     189,   190,   191,   192,   193,   194,    -1,    -1,   197,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1072,  1073,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,
    1138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,   132,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,   163,
     164,   165,   166,   167,    -1,    -1,   170,   171,   172,   173,
     174,   175,   176
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
     211,   212,   220,   199,   200,     6,     6,   212,     4,   212,
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
       0,   341,   341,   342,   344,   345,   346,   348,   349,   350,
     351,   353,   354,   356,   357,   359,   360,   362,   363,   365,
     366,   368,   369,   373,   374,   376,   377,   379,   380,   382,
     384,   385,   387,   388,   389,   390,   391,   393,   395,   400,
     401,   403,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   431,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   467,   472,   473,   474,   475,   476,   478,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   497,
     498,   499,   501,   503,   504,   506,   513,   514,   515,   516,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   545,   554,   555,   556,   557,
     558,   559,   564,   565,   567,   576,   577,   578,   579,   581,
     590,   591,   592,   594,   602,   603,   604,   606,   608,   611,
     613,   614,   615,   617,   624,   625,   626,   627,   629,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   647,   648,   650,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   666,   671,   672,   674,   677,   682,   684,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   705,   706,   708,   710,   712,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   749,   751,   752,   754,   754,   755,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     768,   769,   770,   771,   772,   774,   775,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   794,   800,   801,   802,   803,   806,
     809,   812,   815,   818,   821,   824,   827,   830,   833,   836,
     839,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   855,   857,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   872,   877,   878,   879,   880,   885,
     886,   887,   888,   889,   890,   891,   892,   893,   894,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   944,   945,   946,
     948,   949,   950,   951,   952,   953,   954,   956,   957,   959,
     960,   961,   962,   963,   965,   966,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   979,   980,   981,   982,
     984,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,   997,   998,  1000,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1015,  1017,  1018,
    1019,  1020,  1021,  1022,  1024,  1025,  1026,  1027,  1028,  1029,
    1031,  1032,  1033,  1034,  1035,  1037,  1039,  1040,  1041,  1043,
    1044,  1045,  1046,  1047,  1049,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1060,  1061,  1065,  1066,  1071,  1074,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1100,  1101,  1102,  1112,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229
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
#line 5090 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1231 "D:/projects/a2llib/src/a2lparser.y"


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
