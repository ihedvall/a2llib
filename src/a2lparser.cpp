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
#line 24 "D:/projects/a2llib/src/a2lparser.y"
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::vector<a2l::A2lRange> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.copy< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::vector<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::vector<std::pair<double, double>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::vector<std::pair<double, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.copy< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::vector<a2l::A2lRange> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.move< std::vector<double> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::vector<std::pair<double, double>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::vector<std::pair<double, std::string>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.YY_MOVE_OR_COPY< std::vector<a2l::A2lRange> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.YY_MOVE_OR_COPY< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.YY_MOVE_OR_COPY< std::vector<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<double, double>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<double, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.YY_MOVE_OR_COPY< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::vector<a2l::A2lRange> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.move< std::vector<double> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::vector<std::pair<double, double>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::vector<std::pair<double, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.copy< std::vector<a2l::A2lRange> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.copy< std::vector<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.copy< std::vector<int64_t> > (that.value);
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.copy< std::vector<std::pair<double, double>> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.copy< std::vector<std::pair<double, std::string>> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.copy< std::vector<std::pair<std::string, std::string>> > (that.value);
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.copy< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.copy< std::vector<uint64_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::vector<a2l::A2lRange> > (that.value);
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        value.move< std::vector<double> > (that.value);
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (that.value);
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::vector<std::pair<double, double>> > (that.value);
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::vector<std::pair<double, std::string>> > (that.value);
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        value.move< std::vector<std::pair<std::string, std::string>> > (that.value);
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        value.move< std::vector<std::string> > (that.value);
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_format: // format
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_version: // version
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        yylhs.value.emplace< std::vector<a2l::A2lRange> > ();
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
        yylhs.value.emplace< std::vector<double> > ();
        break;

      case symbol_kind::S_int_list: // int_list
        yylhs.value.emplace< std::vector<int64_t> > ();
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        yylhs.value.emplace< std::vector<std::pair<double, double>> > ();
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        yylhs.value.emplace< std::vector<std::pair<double, std::string>> > ();
        break;

      case symbol_kind::S_key_value_list: // key_value_list
        yylhs.value.emplace< std::vector<std::pair<std::string, std::string>> > ();
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_matrix_dim: // matrix_dim
        yylhs.value.emplace< std::vector<uint64_t> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_number: // number
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
#line 306 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 1561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 3: // any_uint: HEX
#line 307 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 1567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 4: // any_int: INT
#line 309 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 1573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 5: // any_int: UINT
#line 310 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1579 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 6: // any_int: HEX
#line 311 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1585 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 7: // any_float: FLOAT
#line 313 "D:/projects/a2llib/src/a2lparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1591 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 8: // any_float: INT
#line 314 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 1597 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 9: // any_float: UINT
#line 315 "D:/projects/a2llib/src/a2lparser.y"
               { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 1603 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 10: // any_float: HEX
#line 316 "D:/projects/a2llib/src/a2lparser.y"
              { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 1609 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 11: // int_list: %empty
#line 318 "D:/projects/a2llib/src/a2lparser.y"
                 {}
#line 1615 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 12: // int_list: int_list any_int
#line 319 "D:/projects/a2llib/src/a2lparser.y"
                     {yylhs.value.as < std::vector<int64_t> > () = yystack_[1].value.as < std::vector<int64_t> > (); yylhs.value.as < std::vector<int64_t> > ().emplace_back(yystack_[0].value.as < int64_t > ()); }
#line 1621 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 13: // uint_list: %empty
#line 321 "D:/projects/a2llib/src/a2lparser.y"
                  {}
#line 1627 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 14: // uint_list: uint_list any_uint
#line 322 "D:/projects/a2llib/src/a2lparser.y"
                       {yylhs.value.as < std::vector<uint64_t> > () = yystack_[1].value.as < std::vector<uint64_t> > (); yylhs.value.as < std::vector<uint64_t> > ().emplace_back(yystack_[0].value.as < uint64_t > ()); }
#line 1633 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 15: // float_list: %empty
#line 324 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 1639 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 16: // float_list: float_list any_float
#line 325 "D:/projects/a2llib/src/a2lparser.y"
                               {yylhs.value.as < std::vector<double> > () = yystack_[1].value.as < std::vector<double> > (); yylhs.value.as < std::vector<double> > ().emplace_back(yystack_[0].value.as < double > ()); }
#line 1645 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 17: // float_pair_list: %empty
#line 327 "D:/projects/a2llib/src/a2lparser.y"
                        {}
#line 1651 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 18: // float_pair_list: float_pair_list any_float any_float
#line 328 "D:/projects/a2llib/src/a2lparser.y"
                                              {yylhs.value.as < std::vector<std::pair<double, double>> > () = yystack_[2].value.as < std::vector<std::pair<double, double>> > (); yylhs.value.as < std::vector<std::pair<double, double>> > ().emplace_back(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 1657 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 19: // float_string_list: %empty
#line 330 "D:/projects/a2llib/src/a2lparser.y"
                          {}
#line 1663 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 20: // float_string_list: float_string_list any_float STRING
#line 331 "D:/projects/a2llib/src/a2lparser.y"
                                             {yylhs.value.as < std::vector<std::pair<double, std::string>> > () = yystack_[2].value.as < std::vector<std::pair<double, std::string>> > (); yylhs.value.as < std::vector<std::pair<double, std::string>> > ().emplace_back(yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); }
#line 1669 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 21: // float_range_list: %empty
#line 333 "D:/projects/a2llib/src/a2lparser.y"
                         {}
#line 1675 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 22: // float_range_list: float_range_list any_float any_float STRING
#line 334 "D:/projects/a2llib/src/a2lparser.y"
                                                      {
	yylhs.value.as < std::vector<a2l::A2lRange> > () = yystack_[3].value.as < std::vector<a2l::A2lRange> > ();
	yylhs.value.as < std::vector<a2l::A2lRange> > ().emplace_back(yystack_[2].value.as < double > (),yystack_[1].value.as < double > (),yystack_[0].value.as < std::string > ()); }
#line 1683 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 23: // string_list: %empty
#line 338 "D:/projects/a2llib/src/a2lparser.y"
                    {}
#line 1689 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 24: // string_list: string_list STRING
#line 339 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); }
#line 1695 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 25: // ident_list: %empty
#line 341 "D:/projects/a2llib/src/a2lparser.y"
                   {}
#line 1701 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 26: // ident_list: ident_list IDENT
#line 342 "D:/projects/a2llib/src/a2lparser.y"
                           {yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); yylhs.value.as < std::vector<std::string> > ().emplace_back(yystack_[0].value.as < std::string > ()); }
#line 1707 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 27: // key_value_list: %empty
#line 344 "D:/projects/a2llib/src/a2lparser.y"
                       {}
#line 1713 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 28: // key_value_list: key_value_list IDENT IDENT
#line 345 "D:/projects/a2llib/src/a2lparser.y"
                                     {yylhs.value.as < std::vector<std::pair<std::string, std::string>> > () = yystack_[2].value.as < std::vector<std::pair<std::string, std::string>> > (); yylhs.value.as < std::vector<std::pair<std::string, std::string>> > ().emplace_back(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ()); }
#line 1719 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 32: // annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION
#line 352 "D:/projects/a2llib/src/a2lparser.y"
                                                                          { yylhs.value.as < A2lAnnotation > () = yystack_[2].value.as < A2lAnnotation > ();}
#line 1725 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 33: // annotation_attributes: %empty
#line 353 "D:/projects/a2llib/src/a2lparser.y"
                              {}
#line 1731 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 34: // annotation_attributes: annotation_attributes annotation_label
#line 354 "D:/projects/a2llib/src/a2lparser.y"
                                              { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Label = yystack_[0].value.as < std::string > ();}
#line 1737 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 35: // annotation_attributes: annotation_attributes annotation_origin
#line 355 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Origin = yystack_[0].value.as < std::string > ();}
#line 1743 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 36: // annotation_attributes: annotation_attributes annotation_text
#line 356 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lAnnotation > () = yystack_[1].value.as < A2lAnnotation > (); yylhs.value.as < A2lAnnotation > ().Text = yystack_[0].value.as < std::vector<std::string> > ();}
#line 1749 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 37: // annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT
#line 358 "D:/projects/a2llib/src/a2lparser.y"
                                                                               {yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 1755 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 42: // axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float axis_descr_attributes A2L_END AXIS_DESCR
#line 366 "D:/projects/a2llib/src/a2lparser.y"
                                                 {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType(yystack_[8].value.as < std::string > ()));
	descr.InputQuantity(yystack_[7].value.as < std::string > ());
	descr.Conversion(yystack_[6].value.as < std::string > ());
	descr.MaxAxisPoints(yystack_[5].value.as < uint64_t > ());
	descr.LowerLimit(yystack_[4].value.as < double > ());
	descr.UpperLimit(yystack_[3].value.as < double > ());
	}
#line 1769 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 45: // axis_descr_attribute: annotation
#line 377 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentAxisDescr().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 1775 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 46: // axis_descr_attribute: axis_pts_ref
#line 378 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().AxisPtsRef(yystack_[0].value.as < std::string > ()); }
#line 1781 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 47: // axis_descr_attribute: byte_order
#line 379 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisDescr().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 1787 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 48: // axis_descr_attribute: curve_axis_ref
#line 380 "D:/projects/a2llib/src/a2lparser.y"
                         { scanner.CurrentAxisDescr().CurveAxisRef(yystack_[0].value.as < std::string > ()); }
#line 1793 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 49: // axis_descr_attribute: deposit
#line 381 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisDescr().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 1799 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 50: // axis_descr_attribute: extended_limits
#line 382 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisDescr().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 1805 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 51: // axis_descr_attribute: fix_axis_par
#line 383 "D:/projects/a2llib/src/a2lparser.y"
                       { scanner.CurrentAxisDescr().FixAxisPar(yystack_[0].value.as < A2lFixAxisPar > ()); }
#line 1811 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 52: // axis_descr_attribute: fix_axis_par_dist
#line 384 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParDist(yystack_[0].value.as < A2lFixAxisParDist > ()); }
#line 1817 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 53: // axis_descr_attribute: fix_axis_par_list
#line 385 "D:/projects/a2llib/src/a2lparser.y"
                            { scanner.CurrentAxisDescr().FixAxisParList(yystack_[0].value.as < std::vector<double> > ()); }
#line 1823 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 54: // axis_descr_attribute: format
#line 386 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisDescr().Format(yystack_[0].value.as < std::string > ()); }
#line 1829 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 55: // axis_descr_attribute: max_grad
#line 387 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().MaxGradient(yystack_[0].value.as < double > ()); }
#line 1835 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 56: // axis_descr_attribute: monotony
#line 388 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisDescr().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 1841 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 57: // axis_descr_attribute: phys_unit
#line 389 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 1847 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 58: // axis_descr_attribute: read_only
#line 390 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(true); }
#line 1853 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 59: // axis_descr_attribute: step_size
#line 391 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisDescr().ReadOnly(yystack_[0].value.as < double > ()); }
#line 1859 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 60: // axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float axis_pts_attributes A2L_END AXIS_PTS
#line 394 "D:/projects/a2llib/src/a2lparser.y"
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
#line 1877 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 63: // axis_pts_attribute: annotation
#line 409 "D:/projects/a2llib/src/a2lparser.y"
                               { scanner.CurrentAxisPts().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 1883 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 64: // axis_pts_attribute: byte_order
#line 410 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 1889 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 65: // axis_pts_attribute: calibration_access
#line 411 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 1895 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 66: // axis_pts_attribute: deposit
#line 412 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().Deposit(yystack_[0].value.as < A2lDeposit > ()); }
#line 1901 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 67: // axis_pts_attribute: display_identifier
#line 413 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1907 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 68: // axis_pts_attribute: ecu_address_extension
#line 414 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentAxisPts().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 1913 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 69: // axis_pts_attribute: extended_limits
#line 415 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentAxisPts().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 1919 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 70: // axis_pts_attribute: format
#line 416 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentAxisPts().Format(yystack_[0].value.as < std::string > ()); }
#line 1925 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 71: // axis_pts_attribute: function_list
#line 417 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentAxisPts().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 1931 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 72: // axis_pts_attribute: guard_rails
#line 418 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().GuardRails(true); }
#line 1937 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 73: // axis_pts_attribute: if_data
#line 419 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentAxisPts().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 1943 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 74: // axis_pts_attribute: max_refresh
#line 420 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentAxisPts().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 1949 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 75: // axis_pts_attribute: model_link
#line 421 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 1955 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 76: // axis_pts_attribute: monotony
#line 422 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentAxisPts().Monotony(yystack_[0].value.as < A2lMonotony > ()); }
#line 1961 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 77: // axis_pts_attribute: phys_unit
#line 423 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 1967 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 78: // axis_pts_attribute: read_only
#line 424 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().ReadOnly(true); }
#line 1973 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 79: // axis_pts_attribute: ref_memory_segment
#line 425 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentAxisPts().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 1979 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 80: // axis_pts_attribute: step_size
#line 426 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentAxisPts().StepSize(yystack_[0].value.as < double > ()); }
#line 1985 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 81: // axis_pts_attribute: symbol_link
#line 427 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentAxisPts().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 1991 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 88: // blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB
#line 436 "D:/projects/a2llib/src/a2lparser.y"
                                                                                 {
	auto& blob = scanner.CurrentBlob();
	blob.Name(yystack_[6].value.as < std::string > ());
	blob.Description(yystack_[5].value.as < std::string > ());
	blob.Address(yystack_[4].value.as < uint64_t > ());
	blob.Size(yystack_[3].value.as < uint64_t > ());
}
#line 2003 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 91: // blob_attribute: address_type
#line 445 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().AddressType(yystack_[0].value.as < A2lAddressType > ()); }
#line 2009 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 92: // blob_attribute: annotation
#line 446 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2015 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 93: // blob_attribute: calibration_access
#line 447 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2021 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 94: // blob_attribute: display_identifier
#line 448 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentBlob().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2027 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 95: // blob_attribute: ecu_address_extension
#line 449 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentBlob().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2033 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 96: // blob_attribute: if_data
#line 450 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentBlob().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2039 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 97: // blob_attribute: max_refresh
#line 451 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2045 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 98: // blob_attribute: model_link
#line 452 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentBlob().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2051 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 99: // blob_attribute: symbol_link
#line 453 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentBlob().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 2057 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 106: // characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC
#line 465 "D:/projects/a2llib/src/a2lparser.y"
                                                         {
	auto& object = scanner.CurrentCharacteristic();
	object.Name(yystack_[11].value.as < std::string > ());
	object.Description(yystack_[10].value.as < std::string > ());
	object.Type(StringToCharacteristicType(yystack_[9].value.as < std::string > ()));
	}
#line 2068 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 109: // characteristic_attribute: annotation
#line 473 "D:/projects/a2llib/src/a2lparser.y"
                                     { scanner.CurrentCharacteristic().AddAnnotation(yystack_[0].value.as < A2lAnnotation > ()); }
#line 2074 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 110: // characteristic_attribute: axis_descr
#line 474 "D:/projects/a2llib/src/a2lparser.y"
                     { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
#line 2082 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 111: // characteristic_attribute: bit_mask
#line 477 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().BitMask(yystack_[0].value.as < uint64_t > ()); }
#line 2088 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 112: // characteristic_attribute: byte_order
#line 478 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ByteOrder(yystack_[0].value.as < A2lByteOrder > ()); }
#line 2094 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 113: // characteristic_attribute: calibration_access
#line 479 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().CalibrationAccess(yystack_[0].value.as < A2lCalibrationAccess > ()); }
#line 2100 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 114: // characteristic_attribute: comparison_quantity
#line 480 "D:/projects/a2llib/src/a2lparser.y"
                              { scanner.CurrentCharacteristic().ComparisonQuantity(yystack_[0].value.as < std::string > ()); }
#line 2106 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 115: // characteristic_attribute: dependent_characteristic
#line 481 "D:/projects/a2llib/src/a2lparser.y"
                                   { scanner.CurrentCharacteristic().DependentCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 2112 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 116: // characteristic_attribute: discrete
#line 482 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Discrete(true); }
#line 2118 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 117: // characteristic_attribute: display_identifier
#line 483 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().DisplayIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2124 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 118: // characteristic_attribute: ecu_address_extension
#line 484 "D:/projects/a2llib/src/a2lparser.y"
                                { scanner.CurrentCharacteristic().EcuAddressExtension(yystack_[0].value.as < int64_t > ()); }
#line 2130 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 119: // characteristic_attribute: encoding
#line 485 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().Encoding(yystack_[0].value.as < A2lEncoding > ()); }
#line 2136 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 120: // characteristic_attribute: extended_limits
#line 486 "D:/projects/a2llib/src/a2lparser.y"
                          { scanner.CurrentCharacteristic().ExtendedLimits(yystack_[0].value.as < A2lExtendedLimits > ()); }
#line 2142 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 121: // characteristic_attribute: format
#line 487 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Format(yystack_[0].value.as < std::string > ()); }
#line 2148 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 122: // characteristic_attribute: function_list
#line 488 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentCharacteristic().FunctionList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2154 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 123: // characteristic_attribute: guard_rails
#line 489 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().GuardRails(true); }
#line 2160 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 124: // characteristic_attribute: if_data
#line 490 "D:/projects/a2llib/src/a2lparser.y"
                  { scanner.CurrentCharacteristic().AddIfData(yystack_[0].value.as < std::string > ()); }
#line 2166 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 125: // characteristic_attribute: map_list
#line 491 "D:/projects/a2llib/src/a2lparser.y"
                   { scanner.CurrentCharacteristic().MapList(yystack_[0].value.as < std::vector<std::string> > ()); }
#line 2172 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 126: // characteristic_attribute: matrix_dim
#line 492 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().MatrixDim(yystack_[0].value.as < std::vector<uint64_t> > ()); }
#line 2178 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 127: // characteristic_attribute: max_refresh
#line 493 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().MaxRefresh(yystack_[0].value.as < A2lMaxRefresh > ()); }
#line 2184 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 128: // characteristic_attribute: model_link
#line 494 "D:/projects/a2llib/src/a2lparser.y"
                     { scanner.CurrentCharacteristic().ModelLink(yystack_[0].value.as < std::string > ()); }
#line 2190 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 129: // characteristic_attribute: number
#line 495 "D:/projects/a2llib/src/a2lparser.y"
                 { scanner.CurrentCharacteristic().Number(yystack_[0].value.as < uint64_t > ()); }
#line 2196 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 130: // characteristic_attribute: phys_unit
#line 496 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().PhysUnit(yystack_[0].value.as < std::string > ()); }
#line 2202 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 131: // characteristic_attribute: read_only
#line 497 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().ReadOnly(true); }
#line 2208 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 132: // characteristic_attribute: ref_memory_segment
#line 498 "D:/projects/a2llib/src/a2lparser.y"
                             { scanner.CurrentCharacteristic().RefMemorySegment(yystack_[0].value.as < std::string > ()); }
#line 2214 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 133: // characteristic_attribute: step_size
#line 499 "D:/projects/a2llib/src/a2lparser.y"
                    { scanner.CurrentCharacteristic().StepSize(yystack_[0].value.as < double > ()); }
#line 2220 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 134: // characteristic_attribute: symbol_link
#line 500 "D:/projects/a2llib/src/a2lparser.y"
                      { scanner.CurrentCharacteristic().SymbolLink(yystack_[0].value.as < A2lSymbolLink > ()); }
#line 2226 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 135: // characteristic_attribute: virtual_characteristic
#line 501 "D:/projects/a2llib/src/a2lparser.y"
                                 { scanner.CurrentCharacteristic().VirtualCharacteristic(yystack_[0].value.as < A2lDependentCharacteristic > ()); }
#line 2232 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 159: // dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC
#line 533 "D:/projects/a2llib/src/a2lparser.y"
                                                    {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 2238 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 160: // fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST
#line 535 "D:/projects/a2llib/src/a2lparser.y"
                                                                                    { yylhs.value.as < std::vector<double> > () = yystack_[2].value.as < std::vector<double> > (); }
#line 2244 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 183: // function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
#line 562 "D:/projects/a2llib/src/a2lparser.y"
                                                                        { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2250 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 184: // function_list: FUNCTION_LIST ident_list
#line 563 "D:/projects/a2llib/src/a2lparser.y"
                                   { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 2256 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 195: // header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER
#line 576 "D:/projects/a2llib/src/a2lparser.y"
                                                                 {
	auto& header = file.Project().Header();
	header.Comment = yystack_[3].value.as < std::string > ();
}
#line 2265 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 198: // header_attribute: project_no
#line 584 "D:/projects/a2llib/src/a2lparser.y"
                             {
	auto& header = file.Project().Header();
	header.ProjectNo = yystack_[0].value.as < std::string > ();
}
#line 2274 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 199: // header_attribute: version
#line 587 "D:/projects/a2llib/src/a2lparser.y"
                  {
	auto& header = file.Project().Header();
	header.VersionNo = yystack_[0].value.as < std::string > ();
}
#line 2283 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 217: // loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT
#line 611 "D:/projects/a2llib/src/a2lparser.y"
                                                                              { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2289 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 218: // map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST
#line 613 "D:/projects/a2llib/src/a2lparser.y"
                                                         { yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();}
#line 2295 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 286: // module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE
#line 688 "D:/projects/a2llib/src/a2lparser.y"
                                                                       {
	auto& module = scanner.CurrentModule();
	module.Name(yystack_[4].value.as < std::string > ());
	module.Description(yystack_[3].value.as < std::string > ());
	auto& project = file.Project();
	project.AddModule(scanner.ReleaseModule());
}
#line 2307 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 289: // module_attribute: a2ml
#line 698 "D:/projects/a2llib/src/a2lparser.y"
                        { scanner.CurrentModule().A2ml(yystack_[0].value.as < std::string > ()); }
#line 2313 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 290: // module_attribute: axis_pts
#line 699 "D:/projects/a2llib/src/a2lparser.y"
                   {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
#line 2321 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 291: // module_attribute: blob
#line 702 "D:/projects/a2llib/src/a2lparser.y"
               {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
#line 2329 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 292: // module_attribute: characteristic
#line 705 "D:/projects/a2llib/src/a2lparser.y"
                         {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
#line 2337 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 486: // virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC
#line 927 "D:/projects/a2llib/src/a2lparser.y"
                                                  {yylhs.value.as < A2lDependentCharacteristic > () = {yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::vector<std::string> > ()}; }
#line 2343 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 487: // a2ml: A2ML
#line 930 "D:/projects/a2llib/src/a2lparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2349 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 488: // a2ml_version: A2ML_VERSION any_uint any_uint
#line 931 "D:/projects/a2llib/src/a2lparser.y"
                                             {
	file.A2mlVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2mlVersion().VersionNo = yystack_[0].value.as < uint64_t > ();
}
#line 2358 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 489: // asap2_version: ASAP2_VERSION any_uint any_uint
#line 936 "D:/projects/a2llib/src/a2lparser.y"
                                                {
	file.A2lVersion().VersionNo = yystack_[1].value.as < uint64_t > ();
	file.A2lVersion().UpgradeNo = yystack_[0].value.as < uint64_t > ();
}
#line 2367 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 490: // asap2_version: ASAP2_VERSION STRING
#line 939 "D:/projects/a2llib/src/a2lparser.y"
                         {
	file.A2lVersion().FromString(yystack_[0].value.as < std::string > ());
}
#line 2375 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 492: // address_type: ADDRESS_TYPE IDENT
#line 944 "D:/projects/a2llib/src/a2lparser.y"
                                 {yylhs.value.as < A2lAddressType > () = StringToAddressType(yystack_[0].value.as < std::string > ()); }
#line 2381 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 500: // annotation_label: ANNOTATION_LABEL STRING
#line 952 "D:/projects/a2llib/src/a2lparser.y"
                                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2387 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 501: // annotation_origin: ANNOTATION_ORIGIN STRING
#line 953 "D:/projects/a2llib/src/a2lparser.y"
                                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2393 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 504: // axis_pts_ref: AXIS_PTS_REF IDENT
#line 956 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2399 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 511: // bit_mask: BIT_MASK any_uint
#line 963 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2405 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 512: // byte_order: BYTE_ORDER IDENT
#line 964 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < A2lByteOrder > () = StringToByteOrder(yystack_[0].value.as < std::string > ()); }
#line 2411 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 513: // calibration_access: CALIBRATION_ACCESS IDENT
#line 965 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < A2lCalibrationAccess > () = StringToCalibrationAccess(yystack_[0].value.as < std::string > ()); }
#line 2417 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 517: // comparison_quantity: COMPARISON_QUANTITY IDENT
#line 969 "D:/projects/a2llib/src/a2lparser.y"
                                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2423 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 522: // curve_axis_ref: CURVE_AXIS_REF IDENT
#line 974 "D:/projects/a2llib/src/a2lparser.y"
                                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2429 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 528: // deposit: DEPOSIT IDENT
#line 980 "D:/projects/a2llib/src/a2lparser.y"
                       { yylhs.value.as < A2lDeposit > () = StringToDeposit(yystack_[0].value.as < std::string > ()); }
#line 2435 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 530: // display_identifier: DISPLAY_IDENTIFIER IDENT
#line 982 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2441 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 531: // display_identifier: A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER
#line 983 "D:/projects/a2llib/src/a2lparser.y"
                                                                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 2447 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 539: // ecu_address_extension: ECU_ADDRESS_EXTENSION any_int
#line 991 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 2453 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 541: // encoding: ENCODING IDENT
#line 993 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lEncoding > () = StringToEncoding(yystack_[0].value.as < std::string > ()); }
#line 2459 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 544: // extended_limits: EXTENDED_LIMITS any_float any_float
#line 996 "D:/projects/a2llib/src/a2lparser.y"
                                                     { yylhs.value.as < A2lExtendedLimits > () = A2lExtendedLimits(yystack_[1].value.as < double > (),yystack_[0].value.as < double > ()); }
#line 2465 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 545: // fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint
#line 997 "D:/projects/a2llib/src/a2lparser.y"
                                                        { yylhs.value.as < A2lFixAxisPar > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 2471 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 546: // fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint
#line 998 "D:/projects/a2llib/src/a2lparser.y"
                                                                  { yylhs.value.as < A2lFixAxisParDist > () = {yystack_[2].value.as < double > (), yystack_[1].value.as < double > (), yystack_[0].value.as < uint64_t > ()}; }
#line 2477 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 553: // format: FORMAT STRING
#line 1005 "D:/projects/a2llib/src/a2lparser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2483 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 559: // if_data: IF_DATA
#line 1011 "D:/projects/a2llib/src/a2lparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2489 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 564: // matrix_dim: MATRIX_DIM uint_list
#line 1016 "D:/projects/a2llib/src/a2lparser.y"
                                 { yylhs.value.as < std::vector<uint64_t> > () = yystack_[0].value.as < std::vector<uint64_t> > (); }
#line 2495 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 565: // max_grad: MAX_GRAD any_float
#line 1017 "D:/projects/a2llib/src/a2lparser.y"
                             { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2501 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 566: // max_refresh: MAX_REFRESH any_uint any_uint
#line 1018 "D:/projects/a2llib/src/a2lparser.y"
                                           { yylhs.value.as < A2lMaxRefresh > () = {yystack_[1].value.as < uint64_t > (),yystack_[0].value.as < uint64_t > ()}; }
#line 2507 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 567: // model_link: MODEL_LINK STRING
#line 1019 "D:/projects/a2llib/src/a2lparser.y"
                              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2513 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 568: // monotony: MONOTONY IDENT
#line 1020 "D:/projects/a2llib/src/a2lparser.y"
                         { yylhs.value.as < A2lMonotony > () = StringToMonotony(yystack_[0].value.as < std::string > ()); }
#line 2519 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 576: // number: NUMBER any_uint
#line 1028 "D:/projects/a2llib/src/a2lparser.y"
                        { yylhs.value.as < uint64_t > () = yystack_[0].value.as < uint64_t > (); }
#line 2525 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 583: // phys_unit: PHYS_UNIT STRING
#line 1035 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2531 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 584: // proj_no: IDENT
#line 1036 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 2537 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 585: // proj_no: UINT
#line 1037 "D:/projects/a2llib/src/a2lparser.y"
               {yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ());}
#line 2543 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 586: // project_no: PROJECT_NO proj_no
#line 1038 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 2549 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 589: // ref_memory_segment: REF_MEMORY_SEGMENT IDENT
#line 1042 "D:/projects/a2llib/src/a2lparser.y"
                                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2555 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 616: // step_size: STEP_SIZE any_float
#line 1069 "D:/projects/a2llib/src/a2lparser.y"
                               { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 2561 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 618: // symbol_link: SYMBOL_LINK STRING any_int
#line 1071 "D:/projects/a2llib/src/a2lparser.y"
                                        { yylhs.value.as < A2lSymbolLink > () = {yystack_[1].value.as < std::string > (),yystack_[0].value.as < int64_t > ()}; }
#line 2567 "D:/projects/a2llib/src/a2lparser.cpp"
    break;

  case 627: // version: A2L_VERSION STRING
#line 1080 "D:/projects/a2llib/src/a2lparser.y"
                            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 2573 "D:/projects/a2llib/src/a2lparser.cpp"
    break;


#line 2577 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -843;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
      50,   100,    84,   103,  -843,  -843,  -843,  -843,   290,  -843,
     -77,   290,  -843,  -843,  -843,    88,   290,   126,  -843,   139,
     -29,  -843,  -843,   109,  -843,   143,   151,   131,  -843,  -843,
     155,  -843,    43,  -843,   106,   280,   134,  -843,  -843,  -843,
      67,  -843,  -843,  -843,  -843,  -843,   850,   173,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,   306,   321,   336,
     350,   370,   415,   418,   422,   428,   432,   441,   452,   300,
     312,   453,   461,   463,   465,   466,   468,   469,   470,   471,
    -843,  -843,   472,   478,   484,   486,   494,   499,   501,   502,
     505,   506,   507,   508,  -843,  -843,  -843,   513,   517,   518,
     520,   521,   522,   523,  -843,    64,   290,   290,   528,   532,
     533,   536,   290,   290,  -843,  -843,   537,   538,   907,   135,
     985,   539,   545,   290,   546,   550,   377,   548,    56,   194,
     339,   551,   553,  -843,  -843,  -843,  -843,  -843,  -843,   556,
     290,   290,   557,   290,   290,  -843,   290,    73,   182,   290,
     559,   446,   290,   290,   290,   290,   290,   290,   290,   560,
     290,   563,   564,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,    17,   450,   290,   567,   568,
     569,   570,   388,   571,   290,   573,   574,   576,   577,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,   438,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,   581,   583,  -843,   584,   585,  -843,   587,   414,   398,
    -843,  -843,  -843,  -843,   594,   595,  -843,  -843,  -843,  -843,
     596,  -843,   599,   600,  -843,  -843,   356,  -843,   357,   510,
     604,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,    27,   512,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,   290,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   605,   609,
     610,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,   611,  -843,  -843,   616,   617,
     618,   621,   623,   624,   625,   626,   629,   630,   631,  -843,
    -843,  -843,  -843,  -843,   632,   634,   635,   639,   640,   641,
     642,   643,   644,   646,   647,   649,   650,   652,   653,   656,
     664,   665,   666,   669,   670,   671,   672,   674,   675,   676,
     678,   679,   680,   681,   290,   356,    87,   356,   619,    21,
    -843,  -843,  -843,  -843,   682,   117,   356,   301,   356,  -843,
     356,   356,  -843,  -843,  -843,  -843,   356,    60,    96,  -843,
     683,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   692,   299,   356,   290,   290,   690,  -843,
     693,   696,   697,   699,   700,   290,  -843,  -843,  -843,  -843,
    -843,   701,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,   702,   703,   498,   704,  -843,  -843,   705,   356,   534,
     519,  -843,   707,  -843,  -843,  -843,  -843,  -843,    19,   178,
      66,  -843,   514,   711,   712,    32,   677,   713,   715,   388,
     290,   716,   717,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   721,   156,   356,    79,   722,   112,   723,
     685,   724,  -843,  -843,   636,  -843,  -843,  -843,  -843,   347,
    -843,   212,   279,   291,   326,   341,   365,   379,   395,   396,
    -843,    14,   645,   728,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
     356,  -843,   290,    40,   732,   738,   742,   743,   744,   745,
     746,   747,   290,  -843,  -843,   356,   356,   749,  -843,  -843,
     562,   751,   388,   356,  -843,  -843,  -843,  -843,   614,   561,
    -843,   739,    69,  -843,  -843,   290,   752,  -843,  -843,  -843,
    -843,   290,  -843,   388,   356,   684,   714,   356,   356,   760,
     763,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   718,
     356,  -843,  -843,  -843,  -843,   720,  -843,  -843,  -843,  -843,
    -843,  -843,   692,   750,   755,   767,   770,  -843,  -843,  -843,
      59,   719,   686,   673,   648,   651,   602,   689,   633,   615,
     784,  -843,  -843,   290,   356,   358,  -843,  -843,  -843,   786,
    -843,  -843,  -843,  -843,  -843,   789,  -843,  -843,   356,   356,
     356,   794,  -843,  -843,   388,   356,  -843,  -843,   603,   607,
     797,   798,  -843,  -843,  -843,   356,   805,  -843,  -843,   356,
     803,  -843,   356,   356,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   781,   806,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,   290,  -843,  -843,   768,
     769,  -843,   388,   812,  -843,   400,   356,  -843,  -843,   290,
     388,  -843,   404,  -843,  -843,  -843,  -843,   356,   754,  -843,
    -843,   356,  -843,   196,  -843,  -843,  -843,   622,  -843,  -843,
    -843,    74,   290,   267,   654,  -843,  -843,  -843,  -843,   408,
     477,  -843,   388,   628,  -843,  -843,   416,    18,   356,   792,
    -843,   549,    63,   709,   290,   290,  -843,   290,   290,   821,
     822,   824,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,   313,   725,  -843,   290,
    -843,  -843,  -843,   348,   800,   657,   828,   356,   290,   356,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,   793,   659,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,    94,   388,  -843,   691,    76,
     788,   832,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,   748,   834,  -843,  -843,   356,  -843,   727,   833,   839,
     841,   848,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
     849,   851,  -843,  -843,  -843,   409,   425,   687,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,   852,  -843,  -843,   356,
    -843,  -843,  -843,   694,  -843,  -843,  -843,  -843,  -843,   388,
      49,   826,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,   853,  -843,   854,  -843,  -843,  -843,  -843,   356,
    -843,  -843,  -843,   356,  -843,   195,   429,  -843,   817,   388,
     688,   698,  -843,   858,  -843,  -843,   388,  -843,  -843,   440,
    -843,  -843,  -843,   823,   290,   290,  -843,  -843,  -843,  -843,
    -843,   661,  -843,    77,  -843,  -843,   864,  -843,   444,   757,
     447,  -843,  -843,  -843,  -843,   758,  -843,   290,   804,  -843,
     706,  -843,   356,  -843,  -843,   356,  -843,   737,   104,   845,
     874,   878,   356,   356,   356,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,   356,   356,  -843,   380,   290,
     290,   801,  -843,  -843,  -843,  -843
  };

  const short
  A2lParser::yydefact_[] =
  {
       0,     0,     0,     0,    30,   490,     2,     3,     0,     1,
       0,     0,    29,    31,   489,     0,     0,     0,   488,     0,
       0,   329,   330,     0,   327,     0,     0,     0,   328,   196,
       0,   326,     0,   287,     0,     0,     0,   197,   198,   199,
       0,   195,   627,   584,   585,   586,     0,     0,   487,   559,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     301,   302,   303,   304,   288,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   289,   300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   268,   332,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   481,   482,   479,   483,   484,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     278,   279,   269,   270,   272,   273,   274,   275,   276,   277,
     280,   281,   282,   283,   284,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   382,
     383,   384,   385,   386,   377,   378,   379,   380,   381,   387,
     388,     0,     0,   419,     0,     0,   450,     0,     0,     0,
     587,   466,   464,   465,     0,     0,    27,   477,   624,   626,
       0,    89,     0,     0,    17,    19,   155,   166,     0,     0,
       0,   173,   174,   175,   172,   178,   179,   180,   181,   182,
     176,   177,     0,     0,    25,   599,   188,   189,   187,   191,
     192,   194,   190,   193,   202,     0,   253,   493,   494,   495,
     496,   497,   498,   499,   512,   525,   528,   600,     0,     0,
       0,   267,   491,   521,   523,   524,   537,     4,     5,     6,
     540,   542,   574,   582,   617,     0,   622,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   547,
     548,   549,   550,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,    25,   462,    25,     0,     0,     0,     0,     0,   137,
     146,   151,     8,     9,    10,     7,     0,     0,     0,    33,
       0,    25,    25,    25,    25,    25,    25,   170,   556,    25,
      25,    25,   185,   184,     0,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,   532,   533,   534,   535,
     536,     0,   558,   569,   570,   571,   572,   573,   575,   577,
     578,   579,   580,   581,   591,   593,   594,   595,   596,   597,
     598,   601,   602,   603,   604,   605,   608,   609,   610,   611,
     612,     0,     0,     0,     0,   420,   421,     0,     0,     0,
       0,   519,     0,   454,   451,   452,   453,   455,     0,     0,
     469,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    90,    91,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   157,     0,    25,   167,   168,   169,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,    13,   588,   205,   203,   214,   204,
     206,   207,   208,   209,   210,   211,   212,   213,   215,   216,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   418,   492,     0,     0,     0,   449,   619,
       0,     0,     0,     0,   458,   459,   460,   461,     0,     0,
     470,     0,     0,   476,    28,     0,     0,    88,   513,   530,
     539,     0,   567,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   142,   139,   140,   141,   143,   144,    18,     0,
       0,   147,   148,   149,    20,     0,   152,   153,    22,   154,
     526,   165,   555,     0,     0,     0,     0,    36,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   561,   564,     0,     0,    11,   249,   248,     0,
     505,   506,   507,   508,   509,     0,   552,   402,     0,     0,
       0,     0,   456,   590,     0,     0,   390,    25,     0,     0,
       0,     0,   473,   474,   475,     0,     0,   566,   618,     0,
       0,   136,     0,     0,   518,   615,   145,   527,   150,    23,
      32,   500,   501,     0,     0,    40,    41,   158,   200,   217,
     315,   389,   399,   183,   391,   400,     0,    14,   220,     0,
       0,   105,   246,     0,   510,     0,     0,   423,   437,     0,
       0,   621,     0,   468,   471,   623,   625,     0,     0,   107,
     162,     0,   516,     0,    38,   503,   317,     0,    11,   103,
      12,     0,     0,     0,     0,   403,   404,   405,   409,     0,
       0,   393,     0,     0,    61,   531,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,   529,     0,     0,     0,
       0,     0,   223,   226,   234,   221,   244,   222,   224,   225,
     227,   228,   229,   230,   231,   232,   233,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   101,     0,   247,     0,
      25,    25,   401,     0,     0,     0,     0,     0,     0,     0,
     425,   424,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,     0,     0,   441,   438,   439,   440,   442,   443,
     444,   445,   446,   447,   448,     0,     0,   467,     0,     0,
       0,     0,   557,   109,   110,   108,   115,   122,   125,   135,
     111,   112,   113,   114,   116,   117,   118,   119,   120,   121,
     123,   124,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,   163,   164,     0,    37,     0,     0,     0,
       0,     0,   318,   319,   320,   321,   322,   323,   324,   325,
      83,    25,   219,   502,   511,   538,   543,   553,   583,   589,
       0,     0,   102,   245,    11,     0,     0,     0,   410,   411,
     412,   413,   414,   415,   416,   417,     0,   422,   541,     0,
     576,   616,   436,     0,   394,   395,   396,   397,   398,     0,
       0,     0,    63,    62,    71,    64,    65,    66,    67,    68,
      69,    70,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    25,     0,   106,   517,   161,   554,     0,
     316,   520,   560,     0,   568,     0,     0,   514,     0,   251,
       0,     0,   408,     0,   544,   392,     0,    60,    25,     0,
      25,   515,   563,     0,     0,     0,   606,    84,    85,    86,
      87,     0,   100,     0,   406,   407,     0,   607,     0,     0,
       0,    82,   562,   592,   485,     0,   252,     0,     0,   218,
       0,   250,     0,   159,   486,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,    45,    44,    53,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    56,    57,    58,
      59,    15,    42,   504,   522,     0,     0,   565,     0,     0,
       0,     0,    16,   545,   546,   160
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -843,    -8,  -200,  -152,  -802,  -843,  -843,  -843,  -843,  -843,
    -843,  -464,  -843,  -843,  -843,  -167,  -843,  -843,  -843,  -843,
    -843,    39,  -843,  -843,  -843,  -843,  -843,    47,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -747,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
     866,  -843,  -843,  -843,   726,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -459,   756,   762,   765,   772,   773,
     776,   777,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -560,  -806,  -498,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -133,  -843,
    -842,  -548,  -492,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -491,  -843,    45,  -843,    52,  -832,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -798,  -843,  -843,  -843,   -33,  -843,
    -163,  -843,  -712,  -843,  -843,  -550,  -843,  -489,  -488,  -839,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,    54,  -843,  -843,
    -843,  -843,  -843,  -843,  -796,  -843,  -843,  -826,    71,  -797,
     314,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -835,  -843,  -487,   -16,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,   771
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,     8,   830,   486,   802,   733,  1138,   480,   481,   356,
     823,   503,   475,     2,     3,   361,   609,   717,   362,   720,
     785,   900,  1107,  1116,    50,   928,  1023,   863,  1055,  1077,
      51,   477,   584,   801,   991,   209,   735,    52,   846,   935,
      53,   594,   691,    54,   596,   701,    55,   598,   706,    56,
     487,   602,   363,   936,  1117,   692,   847,   963,    57,   488,
     606,    58,   167,   364,   377,    59,   168,   378,    21,    32,
      37,   365,    60,   504,   627,   366,   938,    61,   827,   865,
     210,   831,   739,   211,  1083,    62,   138,   183,    63,   139,
     212,    22,    40,    64,   367,   628,   851,   972,    12,    23,
      24,    65,   140,   275,   368,   341,   380,   563,   925,  1014,
     369,   381,    66,   805,   835,   836,   837,    67,   893,   998,
      68,   466,   555,    69,   839,   901,    70,   840,   915,    71,
     469,   564,    72,   568,   664,    73,   148,   342,   670,   153,
     671,   154,   672,   762,   155,    74,   125,   156,   866,   939,
      75,    13,     4,   213,   556,   184,   185,   186,   187,   188,
     189,   190,   718,   719,   868,   786,  1118,   283,   284,   285,
     286,   287,   288,   869,   191,   586,   992,   693,   694,   943,
     695,   566,   973,   214,  1120,   215,   216,   192,   603,   703,
     193,   871,   587,   289,   290,   291,   292,   293,   217,   873,
     588,   218,   905,   219,   875,   906,  1123,  1124,   294,   295,
     296,   297,   298,   299,   876,   964,   607,   370,   950,   300,
      76,   976,   634,  1078,   977,   635,  1126,   590,   591,   978,
     301,   302,   303,   304,   305,   220,   306,   909,   307,   308,
     309,   310,   311,   221,   882,    45,    38,   343,   638,   884,
     665,   312,  1079,   313,   314,   315,   316,   317,   318,   383,
     194,   319,   320,   321,   322,   323,  1080,   666,   324,   325,
     326,   327,   328,   329,   330,   697,   911,   222,   592,   567,
     223,   667,   224,   763,   157,   764,   158,    39
  };

  const short
  A2lParser::yytable_[] =
  {
      14,   376,   410,    16,   371,   382,   630,   569,    18,   570,
     565,   959,   631,   632,   948,   636,   637,   639,   585,   974,
     957,   870,   961,   660,   559,   560,   886,   611,   612,   613,
     614,   615,   616,   903,   918,   617,   618,   619,   554,   489,
     941,   907,   921,   910,   924,   629,   737,    34,   949,   958,
     956,  1000,   489,   975,  1003,   979,    35,   489,  1005,   338,
     339,  1001,     1,   783,   600,   398,    15,   149,   150,   669,
      46,    47,   620,   759,   489,    25,   358,   359,   887,   561,
     864,  1095,    48,   699,     9,   676,  1027,   999,   489,  1036,
     784,   553,    26,  1040,    17,  1002,  1030,  1004,  1013,   937,
     604,   489,  1038,   676,   554,   980,    10,     5,  1006,     6,
       7,   554,    20,    27,   962,   878,   705,    11,   159,   160,
     676,   572,  1025,   573,   165,   166,   601,   499,   922,   489,
    1031,  1039,  1037,    19,   676,   333,   399,   400,   195,   196,
      43,   712,    20,    44,  1042,   601,   700,   676,    35,   499,
      29,   197,   351,   352,   730,   354,   355,    30,   357,   685,
     686,   384,    33,   499,   387,   388,   389,   390,   391,   392,
     393,   661,   395,    49,   360,   495,   499,   500,   601,    49,
      49,  1024,   668,    49,   620,   372,   373,    36,   662,   402,
    1043,  1131,  1059,   738,   605,   198,   412,   199,   200,  1073,
     849,   340,    49,   850,   623,   562,   687,   688,   501,   624,
      41,   689,   201,  1016,   663,   202,   721,   203,   620,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,  1121,   204,   151,  1127,   152,
     981,   760,  1130,   761,    31,  1122,   205,   879,   562,   902,
     917,  1129,   374,   722,  1044,   620,   940,    42,    49,   908,
     923,   904,   919,   812,   101,   723,   952,   620,   944,     6,
       7,  1119,   621,   622,   575,   576,  1074,   114,   661,  1125,
     583,  1128,   102,   552,   589,   557,   554,   206,   554,   115,
     207,   407,   408,   409,   574,   608,   593,   103,   595,   597,
     724,   208,   620,   690,   599,   872,   874,   626,   880,   881,
     885,   633,   104,   375,   577,   725,   577,   620,   942,  1075,
     713,   714,   997,   640,   945,   946,   105,   953,   954,   960,
     990,   799,   800,  1076,   482,   483,   484,   485,   867,   726,
     578,   620,   578,   715,   716,  1017,   106,   505,   579,   680,
     579,   916,   489,   727,  1141,   620,   336,   490,   482,   483,
     484,   485,   179,   344,   345,   346,   407,   408,   409,   728,
     729,   620,   620,   833,   834,    49,   656,    49,   843,   623,
     620,   894,   895,  1060,   624,   620,   580,   181,   580,   929,
     930,   107,   491,   581,   108,   581,   995,   996,   109,  1061,
    1026,   620,   897,  1081,   110,   620,  1028,  1029,   111,  1034,
    1035,  1041,   859,   698,  1089,   625,   620,   112,  1098,   855,
     620,  1100,   179,   620,   890,   891,   551,   855,   113,   116,
     179,   577,   754,   702,   492,   707,  1015,   117,   931,   118,
     493,   119,   120,   971,   121,   122,   123,   124,   856,   126,
     912,   913,   582,   768,   582,   127,   856,   578,   734,   896,
     860,   128,   897,   129,   554,   579,   494,   896,   641,   642,
     897,   130,   859,   749,   750,   495,   131,   649,   132,   133,
     859,   755,   134,   135,   136,   137,   374,  1056,   855,   932,
     141,   179,    49,   624,   142,   143,   899,   144,   145,   146,
     147,   624,   769,   580,   161,   772,   773,   496,   162,   163,
     581,   898,   164,   169,   170,   347,   331,   856,   777,   898,
     860,   332,   334,   967,   810,   337,   335,   348,   860,   858,
     349,   340,   350,   471,   353,   385,   394,   861,   386,   396,
     397,   859,   681,   401,   403,   404,   405,   406,   411,  1069,
     413,   414,   798,   415,   416,   417,   899,   623,   464,   465,
     467,   468,   624,   470,   899,   472,   806,   807,   808,   582,
     473,   474,   476,   811,  1088,   478,  1090,   479,   968,   497,
     842,   498,   506,   817,   502,   507,   508,   819,   509,   860,
     821,   822,   510,   511,   512,   852,   853,   513,   558,   514,
     515,   516,   517,   897,   736,   518,   519,   520,   521,   554,
     522,   523,   926,   859,   748,   524,   525,   526,   527,   528,
     529,   854,   530,   531,   838,   532,   533,   969,   534,   535,
     862,   970,   536,   855,   877,   844,   179,   765,   888,   848,
     537,   538,   539,   767,   971,   540,   541,   542,   543,   933,
     544,   545,   546,   951,   547,   548,   549,   550,   653,   571,
     610,   860,   856,   578,  1020,  1021,   965,   643,   620,   644,
     857,   579,   645,   646,   858,   647,   648,   650,   651,   652,
     654,   655,   658,   657,   659,   673,   859,   674,   675,   678,
     677,   679,   374,   682,   683,   797,  1019,   684,    49,   704,
     708,   710,   623,   711,   732,   179,   577,   624,   740,   580,
    1108,  1109,   709,   758,   741,  1009,   581,  1011,   742,   743,
     744,   745,   746,   747,   731,   751,   752,   753,   766,   757,
     181,  1022,   578,   756,   860,  1033,   774,   771,   625,   775,
     579,  1110,   776,   861,   781,   897,   778,   782,   779,   770,
     780,   179,   792,   794,   787,   859,   789,   790,   826,   793,
     796,   374,   803,   788,   932,   804,   795,    49,  1111,   791,
     809,   841,   813,   815,   816,   582,   181,   814,   580,   818,
     820,   824,   825,  1049,   828,   581,   971,   829,   832,  1066,
     966,   897,  1112,  1113,   889,   845,   927,   982,   987,   988,
     989,   859,  1006,   860,  1008,   980,   340,  1045,  1046,  1051,
     892,  1048,   861,  1047,   993,  1052,   983,   984,  1007,   985,
     986,  1012,  1053,  1114,  1054,  1058,  1057,  1064,  1063,  1067,
    1068,  1070,   971,  1082,  1086,  1091,  1087,  1050,  1094,   899,
    1097,  1099,  1103,  1065,   582,  1084,  1062,  1132,  1101,   860,
    1133,   994,   340,    77,  1134,   934,  1085,   914,  1145,    28,
    1010,   947,   920,    78,   379,  1032,   276,  1071,   883,    79,
     955,  1072,   277,    80,    81,   278,    82,    83,   696,  1018,
     225,   171,   279,   280,  1104,   899,   281,   282,     0,     0,
    1096,     0,     0,     0,     0,   172,   173,   174,   175,   176,
     177,   178,     0,     0,     0,     0,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,    84,     0,    85,
    1105,   179,    86,  1106,     0,     0,     0,     0,     0,    87,
    1135,  1136,  1137,     0,     0,     0,     0,     0,    88,     0,
       0,   180,    89,    90,     0,     0,   181,     0,     0,     0,
       0,     0,     0,  1139,  1140,     0,  1142,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,   230,   231,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,    93,
      94,    95,    96,    97,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   233,   234,   235,
     236,   237,     0,     0,     0,     0,  1092,  1093,     0,   182,
       0,     0,     0,   238,   239,   240,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,     0,
       0,  1143,  1144,     0,     0,     0,     0,     0,   256,     0,
     257,   258,   259,   260,   261,   262,     0,     0,   263,   264,
     265,   266,   267,     0,     0,   268,   269,   270,   271,   272,
     273,   274
  };

  const short
  A2lParser::yycheck_[] =
  {
       8,   168,   202,    11,   167,   168,   504,   471,    16,   473,
     469,   846,   504,   504,   846,   504,   504,   504,   477,   851,
     846,   827,     4,     4,     3,     4,   828,   491,   492,   493,
     494,   495,   496,   839,   840,   499,   500,   501,    17,    25,
     846,   839,   840,   839,   840,   504,     6,     4,   846,   846,
     846,   893,    25,   851,   893,   851,    13,    25,   893,     3,
       4,   893,    12,     4,     4,    48,   143,     3,     4,     3,
       3,     4,     6,     4,    25,   104,     3,     4,     4,    58,
     827,     4,    15,     4,     0,    71,   928,   893,    25,   928,
      31,     4,   121,   928,     6,   893,   928,   893,     4,   846,
       4,    25,   928,    71,    17,    42,     3,     7,    32,     9,
      10,    17,     3,     4,    96,   827,     4,    14,   126,   127,
      71,     4,   928,     6,   132,   133,    66,   100,   840,    25,
     928,   928,   928,     7,    71,   143,   119,   120,     3,     4,
       6,   605,     3,     9,    68,    66,    67,    71,    13,   100,
       7,    16,   160,   161,   140,   163,   164,     6,   166,     3,
       4,   169,     7,   100,   172,   173,   174,   175,   176,   177,
     178,   152,   180,   106,   101,   148,   100,   150,    66,   106,
     106,   928,     4,   106,     6,     3,     4,   144,   169,   197,
     114,    87,   994,   153,    98,    60,   204,    62,    63,     4,
       4,   145,   106,     7,   110,   184,    50,    51,   181,   115,
     104,    55,    77,   925,   195,    80,     4,    82,     6,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,  1107,   131,   203,  1107,   205,
     207,   202,  1107,   204,   143,  1107,   141,   827,   184,   839,
     840,  1107,   100,     4,   208,     6,   846,     7,   106,   839,
     840,   839,   840,   757,   121,     4,   846,     6,   846,     9,
      10,  1107,     3,     4,     3,     4,   111,     7,   152,  1107,
     477,  1107,     6,   465,   477,   467,    17,   182,    17,     7,
     185,     8,     9,    10,   476,   488,   478,     6,   480,   481,
       4,   196,     6,   177,   486,   827,   827,   504,   827,   827,
     827,   504,     6,   161,    45,     4,    45,     6,   846,   154,
       3,     4,     4,   505,   846,   846,     6,   846,   846,   846,
      47,     3,     4,   168,     8,     9,    10,    11,   827,     4,
      71,     6,    71,    26,    27,   925,     6,   385,    79,   579,
      79,   840,    25,     4,     4,     6,     9,    30,     8,     9,
      10,    11,    44,   199,   200,   201,     8,     9,    10,     4,
       4,     6,     6,     3,     4,   106,   558,   106,     4,   110,
       6,     3,     4,     4,   115,     6,   117,    69,   117,     3,
       4,     6,    65,   124,     6,   124,   890,   891,     6,     4,
     928,     6,    84,     4,     6,     6,   928,   928,     6,   928,
     928,   928,    94,   595,     4,   146,     6,     6,     4,    41,
       6,     4,    44,     6,   187,   188,   464,    41,     6,     6,
      44,    45,   662,   596,   107,   598,   925,     6,    52,     6,
     113,     6,     6,   125,     6,     6,     6,     6,    70,     7,
       3,     4,   183,   683,   183,     7,    70,    71,   640,    81,
     142,     7,    84,     7,    17,    79,   139,    81,   506,   507,
      84,     7,    94,   655,   656,   148,     7,   515,     7,     7,
      94,   663,     7,     7,     7,     7,   100,   981,    41,   103,
       7,    44,   106,   115,     7,     7,   178,     7,     7,     7,
       7,   115,   684,   117,     6,   687,   688,   180,     6,     6,
     124,   133,     6,     6,     6,   206,     7,    70,   700,   133,
     142,     6,     6,     4,   754,     7,     6,     6,   142,    82,
       7,   145,     6,   149,     7,     6,     6,   151,   122,     6,
       6,    94,   580,   123,     7,     7,     7,     7,     7,  1043,
       7,     7,   734,     7,     7,   147,   178,   110,     7,     6,
       6,     6,   115,     6,   178,   197,   748,   749,   750,   183,
       6,     6,     6,   755,  1068,     6,  1070,     7,    59,    99,
     810,     7,     7,   765,   102,     6,     6,   769,     7,   142,
     772,   773,     6,     6,     6,     3,     4,     6,     9,     6,
       6,     6,     6,    84,   642,     6,     6,     6,     6,    17,
       6,     6,   842,    94,   652,     6,     6,     6,     6,     6,
       6,    29,     6,     6,   806,     6,     6,   108,     6,     6,
     827,   112,     6,    41,   827,   817,    44,   675,   831,   821,
       6,     6,     6,   681,   125,     6,     6,     6,     6,   846,
       6,     6,     6,   846,     6,     6,     6,     6,   190,     7,
       7,   142,    70,    71,     3,     4,   848,     7,     6,     6,
      78,    79,     6,     6,    82,     6,     6,     6,     6,     6,
       6,     6,   193,   179,     7,   201,    94,     6,     6,     6,
      43,     6,   100,     7,     7,   733,   926,     6,   106,     7,
       7,     7,   110,    97,     6,    44,    45,   115,     6,   117,
       3,     4,    57,     4,     6,   897,   124,   899,     6,     6,
       6,     6,     6,     6,   109,     6,   194,     6,     6,   198,
      69,   928,    71,   149,   142,   928,     6,    53,   146,     6,
      79,    34,    54,   151,     7,    84,    56,     7,    28,    95,
      25,    44,   180,   150,    65,    94,   113,   139,   796,   100,
       6,   100,     6,   107,   103,     6,   181,   106,    61,   148,
       6,   809,   199,     6,     6,   183,    69,   200,   117,     4,
       7,    30,     6,   965,    46,   124,   125,    48,     6,  1019,
      28,    84,    85,    86,   832,    71,   198,   118,     7,     7,
       6,    94,    32,   142,     6,    42,   145,    49,     6,     6,
     186,     7,   151,    95,   119,     6,   854,   855,   191,   857,
     858,   192,    11,   116,     6,     4,     7,  1009,     6,    33,
       7,     7,   125,    46,     6,    42,  1066,   140,   207,   178,
       6,   114,    68,   179,   183,   187,   189,    32,   120,   142,
       6,   889,   145,    33,     6,   846,   188,   840,    87,    23,
     898,   846,   840,    43,   168,   928,   140,  1049,   827,    49,
     846,  1053,   140,    53,    54,   140,    56,    57,   594,   925,
     139,     4,   140,   140,   208,   178,   140,   140,    -1,    -1,
    1083,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1107,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    99,
    1102,    44,   102,  1105,    -1,    -1,    -1,    -1,    -1,   109,
    1112,  1113,  1114,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    64,   122,   123,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,  1135,  1136,    -1,  1138,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,   189,
     190,   191,   192,   193,   194,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,  1074,  1075,    -1,   162,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1139,  1140,    -1,    -1,    -1,    -1,    -1,   153,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,   163,   164,
     165,   166,   167,    -1,    -1,   170,   171,   172,   173,   174,
     175,   176
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   222,   223,   361,     7,     9,    10,   210,     0,
       3,    14,   307,   360,   210,   143,   210,     6,   210,     7,
       3,   277,   300,   308,   309,   104,   121,     4,   309,     7,
       6,   143,   278,     7,     4,    13,   144,   279,   455,   496,
     301,   104,     7,     6,     9,   454,     3,     4,    15,   106,
     233,   239,   246,   249,   252,   255,   258,   267,   270,   274,
     281,   286,   294,   297,   302,   310,   321,   326,   329,   332,
     335,   338,   341,   344,   354,   359,   429,    33,    43,    49,
      53,    54,    56,    57,    97,    99,   102,   109,   118,   122,
     123,   147,   186,   189,   190,   191,   192,   193,   194,   197,
     206,   121,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     7,     7,     6,     6,     6,     6,
       6,     6,     6,     6,     6,   355,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   295,   298,
     311,     7,     7,     7,     7,     7,     7,     7,   345,     3,
       4,   203,   205,   348,   350,   353,   356,   493,   495,   210,
     210,     6,     6,     6,     6,   210,   210,   271,   275,     6,
       6,     4,    18,    19,    20,    21,    22,    23,    24,    44,
      64,    69,   162,   296,   364,   365,   366,   367,   368,   369,
     370,   383,   396,   399,   469,     3,     4,    16,    60,    62,
      63,    77,    80,    82,   131,   141,   182,   185,   196,   244,
     289,   292,   299,   362,   392,   394,   395,   407,   410,   412,
     444,   452,   486,   489,   491,   496,     4,    35,    36,    37,
      38,    39,    40,    72,    73,    74,    75,    76,    88,    89,
      90,    91,    92,    93,   105,   126,   127,   128,   129,   130,
     132,   134,   135,   136,   137,   138,   153,   155,   156,   157,
     158,   159,   160,   163,   164,   165,   166,   167,   170,   171,
     172,   173,   174,   175,   176,   312,   364,   365,   366,   367,
     368,   369,   370,   376,   377,   378,   379,   380,   381,   402,
     403,   404,   405,   406,   417,   418,   419,   420,   421,   422,
     428,   439,   440,   441,   442,   443,   445,   447,   448,   449,
     450,   451,   460,   462,   463,   464,   465,   466,   467,   470,
     471,   472,   473,   474,   477,   478,   479,   480,   481,   482,
     483,     7,     6,   210,     6,     6,     9,     7,     3,     4,
     145,   314,   346,   456,   199,   200,   201,   206,     6,     7,
       6,   210,   210,     7,   210,   210,   218,   210,     3,     4,
     101,   224,   227,   261,   272,   280,   284,   303,   313,   319,
     426,   429,     3,     4,   100,   161,   224,   273,   276,   313,
     315,   320,   429,   468,   210,     6,   122,   210,   210,   210,
     210,   210,   210,   210,     6,   210,     6,     6,    48,   119,
     120,   123,   210,     7,     7,     7,     7,     8,     9,    10,
     211,     7,   210,     7,     7,     7,     7,   147,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,     7,     6,   330,     6,     6,   339,
       6,   149,   197,     6,     6,   221,     6,   240,     6,     7,
     216,   217,     8,     9,    10,    11,   212,   259,   268,    25,
      30,    65,   107,   113,   139,   148,   180,    99,     7,   100,
     150,   181,   102,   220,   282,   210,     7,     6,     6,     7,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   210,   212,     4,    17,   331,   363,   212,     9,     3,
       4,    58,   184,   316,   340,   363,   390,   488,   342,   220,
     220,     7,     4,     6,   212,     3,     4,    45,    71,    79,
     117,   124,   183,   224,   241,   363,   384,   401,   409,   429,
     436,   437,   487,   212,   250,   212,   253,   212,   256,   212,
       4,    66,   260,   397,     4,    98,   269,   425,   429,   225,
       7,   220,   220,   220,   220,   220,   220,   220,   220,   220,
       6,     3,     4,   110,   115,   146,   224,   283,   304,   363,
     384,   401,   409,   429,   431,   434,   436,   437,   457,   487,
     212,   210,   210,     7,     6,     6,     6,     6,     6,   210,
       6,     6,     6,   190,     6,     6,   212,   179,   193,     7,
       4,   152,   169,   195,   343,   459,   476,   490,     4,     3,
     347,   349,   351,   201,     6,     6,    71,    43,     6,     6,
     211,   210,     7,     7,     6,     3,     4,    50,    51,    55,
     177,   251,   264,   386,   387,   389,   459,   484,   212,     4,
      67,   254,   397,   398,     7,     4,   257,   397,     7,    57,
       7,    97,   220,     3,     4,    26,    27,   226,   371,   372,
     228,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     140,   109,     6,   214,   212,   245,   210,     6,   153,   291,
       6,     6,     6,     6,     6,     6,     6,     6,   210,   212,
     212,     6,   194,     6,   211,   212,   149,   198,     4,     4,
     202,   204,   352,   492,   494,   210,     6,   210,   211,   212,
      95,    53,   212,   212,     6,     6,    54,   212,    56,    28,
      25,     7,     7,     4,    31,   229,   374,    65,   107,   113,
     139,   148,   180,   100,   150,   181,     6,   210,   212,     3,
       4,   242,   213,     6,     6,   322,   212,   212,   212,     6,
     211,   212,   220,   199,   200,     6,     6,   212,     4,   212,
       7,   212,   212,   219,    30,     6,   210,   287,    46,    48,
     211,   290,     6,     3,     4,   323,   324,   325,   212,   333,
     336,   210,   211,     4,   212,    71,   247,   265,   212,     4,
       7,   305,     3,     4,    29,    41,    70,    78,    82,    94,
     142,   151,   224,   236,   273,   288,   357,   363,   373,   382,
     383,   400,   401,   408,   409,   413,   423,   429,   431,   434,
     436,   437,   453,   457,   458,   487,   213,     4,   429,   210,
     187,   188,   186,   327,     3,     4,    81,    84,   133,   178,
     230,   334,   382,   383,   400,   411,   414,   423,   434,   446,
     453,   485,     3,     4,   236,   337,   363,   382,   383,   400,
     413,   423,   431,   434,   453,   317,   211,   198,   234,     3,
       4,    52,   103,   224,   230,   248,   262,   273,   285,   358,
     382,   383,   384,   388,   400,   401,   409,   411,   414,   423,
     427,   429,   434,   436,   437,   446,   453,   456,   458,   485,
     487,     4,    96,   266,   424,   212,    28,     4,    59,   108,
     112,   125,   306,   391,   414,   423,   430,   433,   438,   453,
      42,   207,   118,   210,   210,   210,   210,     7,     7,     6,
      47,   243,   385,   119,   210,   220,   220,     4,   328,   383,
     399,   414,   423,   438,   453,   485,    32,   191,     6,   212,
     210,   212,   192,     4,   318,   363,   431,   434,   488,   211,
       3,     4,   224,   235,   273,   383,   384,   399,   401,   409,
     414,   423,   427,   429,   436,   437,   438,   453,   456,   458,
     485,   487,    68,   114,   208,    49,     6,    95,     7,   212,
     140,     6,     6,    11,     6,   237,   220,     7,     4,   213,
       4,     4,   189,     6,   212,   179,   211,    33,     7,   220,
       7,   212,   212,     4,   111,   154,   168,   238,   432,   461,
     475,     4,    46,   293,   187,   188,     6,   211,   220,     4,
     220,    42,   210,   210,   207,     4,   429,     6,     4,   114,
       4,   120,   210,    68,   208,   212,   212,   231,     3,     4,
      34,    61,    85,    86,   116,   224,   232,   263,   375,   383,
     393,   399,   414,   415,   416,   423,   435,   438,   453,   456,
     485,    87,    32,     6,     6,   212,   212,   212,   215,   212,
     212,     4,   212,   210,   210,    87
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   209,   210,   210,   211,   211,   211,   212,   212,   212,
     212,   213,   213,   214,   214,   215,   215,   216,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     223,   223,   224,   225,   225,   225,   225,   226,   227,   228,
     228,   229,   230,   231,   231,   232,   232,   232,   232,   232,
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
     263,   264,   265,   265,   266,   267,   268,   268,   269,   269,
     270,   271,   271,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   273,   273,   274,   275,   275,   276,   276,
     276,   276,   276,   276,   276,   277,   278,   278,   279,   279,
     280,   281,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   284,   285,   286,
     287,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   289,   290,   290,   291,   291,
     292,   293,   293,   294,   295,   295,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   297,   298,   298,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   300,   301,   301,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   304,   305,   305,   306,
     306,   306,   306,   306,   306,   306,   307,   308,   308,   309,
     309,   310,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     314,   315,   316,   317,   317,   318,   318,   318,   318,   319,
     320,   321,   322,   322,   323,   323,   324,   325,   326,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   329,   330,
     330,   331,   332,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   336,   336,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   338,
     339,   339,   340,   340,   340,   340,   341,   342,   342,   343,
     343,   343,   344,   345,   345,   346,   346,   347,   348,   349,
     349,   350,   351,   351,   352,   352,   353,   354,   355,   355,
     356,   356,   356,   356,   356,   357,   358,   359,   360,   361,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     0,     2,     0,     3,     0,
       3,     0,     4,     0,     2,     0,     2,     0,     3,     2,
       1,     2,     5,     0,     2,     2,     2,     5,     6,     0,
       2,     1,    11,     0,     2,     1,     1,     1,     1,     1,
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
      10,     0,     2,     1,     9,     0,     2,     1,     5,     6,
       5,     6,     0,     2,     1,     9,     0,     2,     1,     1,
       7,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     7,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     6,     0,     2,     1,     1,
       5,     9,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,    13,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     9,     0,     2,     1,     1,
      13,     0,     2,     6,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     2,     1,
       1,     6,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     8,     0,     2,     1,     1,     1,     1,     5,
       5,    12,     0,     2,     1,     1,     5,     5,    14,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     8,     0,
       2,     1,    13,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,    13,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     8,
       0,     2,     1,     1,     1,     1,     9,     0,     2,     1,
       1,     1,     6,     0,     2,     1,     1,     5,     7,     0,
       1,     7,     0,     2,     1,     1,     5,     5,     0,     2,
       1,     1,     1,     1,     1,     5,     6,     1,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     5,     5,     5,     5,     5,
       6,     2,     2,     2,     2,     7,     3,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     5,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     4,     2,     2,     2,
       2,     2,     5,     2,     2,     2,     2,     1,     3,     1,
       2,     2,     2,     3,     2,     2,     3,     2,     2,     3,
       3,     3,     3,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     2,     1,     1,     2,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     1,     8,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     3,     2,
       3,     3,     2,     2,     2,     2,     2,     2
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
  "ar_component_attributes", "ar_component_attribute", "axis_descr",
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
  "def_characteristic", "dependent_characteristic", "fix_axis_par_list",
  "formula", "formula_attributes", "formula_attribute", "frame",
  "frame_attributes", "frame_attribute", "function", "function_attributes",
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
       0,   306,   306,   307,   309,   310,   311,   313,   314,   315,
     316,   318,   319,   321,   322,   324,   325,   327,   328,   330,
     331,   333,   334,   338,   339,   341,   342,   344,   345,   347,
     349,   350,   352,   353,   354,   355,   356,   358,   360,   361,
     362,   363,   365,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     393,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   429,   430,   431,   432,   433,   434,   436,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     455,   456,   457,   459,   461,   462,   464,   471,   472,   473,
     474,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   513,   514,   515,   516,   517,
     519,   520,   521,   522,   524,   526,   527,   528,   530,   532,
     535,   537,   538,   539,   540,   542,   543,   544,   545,   546,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   562,   563,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   576,   581,   582,   584,   587,
     592,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   611,   613,   615,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   643,   645,   646,   648,   648,
     649,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   688,   696,   697,   698,
     699,   702,   705,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   731,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   744,   745,   746,   747,
     748,   750,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   809,
     810,   811,   813,   814,   815,   816,   817,   818,   819,   821,
     822,   824,   825,   826,   827,   828,   830,   831,   833,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   844,   845,
     846,   847,   849,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   865,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   876,   877,   878,   880,
     882,   883,   884,   885,   886,   887,   889,   890,   891,   892,
     893,   894,   896,   897,   898,   899,   900,   902,   904,   905,
     906,   908,   909,   910,   911,   912,   914,   916,   917,   918,
     919,   920,   921,   922,   923,   925,   926,   930,   931,   936,
     939,   943,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080
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
#line 3887 "D:/projects/a2llib/src/a2lparser.cpp"

#line 1082 "D:/projects/a2llib/src/a2lparser.y"


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
