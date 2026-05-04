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
#define yylex   ccplex



#include "ccpdataparser.hpp"


// Unqualified %code blocks.
#line 38 "D:/projects/a2llib/src/ccp/ccpdataparser.y"

    #include <sstream>
    #include <limits>
    #include "ccpdatascanner.h"


    #undef yylex
    #define yylex scanner.ccplex

#line 58 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"


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
#if CCPDEBUG

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

#else // !CCPDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !CCPDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
namespace a2l { namespace ccp {
#line 132 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"

  /// Build a parser object.
  CcpDataParser::CcpDataParser (a2l::ccp::CcpDataScanner &scanner_yyarg)
#if CCPDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  CcpDataParser::~CcpDataParser ()
  {}

  CcpDataParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  CcpDataParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.copy< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_can_param: // can_param
        value.copy< CanParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.copy< ChecksumParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.copy< DefinedPages > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.copy< DpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_event_group: // event_group
        value.copy< EventGroup > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.copy< KpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.copy< QpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster: // raster
        value.copy< Raster > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.copy< SeedKey > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source: // source
        value.copy< Source > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.copy< TpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.copy< std::vector<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.copy< uint64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.copy< uint8_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  CcpDataParser::symbol_kind_type
  CcpDataParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  CcpDataParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  CcpDataParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.move< AddressMapping > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_can_param: // can_param
        value.move< CanParam > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.move< ChecksumParam > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.move< DefinedPages > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.move< DpBlob > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_event_group: // event_group
        value.move< EventGroup > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.move< KpBlob > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.move< QpBlob > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_raster: // raster
        value.move< Raster > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.move< SeedKey > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_source: // source
        value.move< Source > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.move< TpBlob > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.move< std::vector<uint8_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.move< uint8_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  CcpDataParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  CcpDataParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  CcpDataParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  CcpDataParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  CcpDataParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  CcpDataParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  CcpDataParser::symbol_kind_type
  CcpDataParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  CcpDataParser::symbol_kind_type
  CcpDataParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  CcpDataParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  CcpDataParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  CcpDataParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  CcpDataParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  CcpDataParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  CcpDataParser::symbol_kind_type
  CcpDataParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  CcpDataParser::stack_symbol_type::stack_symbol_type ()
  {}

  CcpDataParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.YY_MOVE_OR_COPY< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_can_param: // can_param
        value.YY_MOVE_OR_COPY< CanParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.YY_MOVE_OR_COPY< ChecksumParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.YY_MOVE_OR_COPY< DefinedPages > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.YY_MOVE_OR_COPY< DpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_event_group: // event_group
        value.YY_MOVE_OR_COPY< EventGroup > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.YY_MOVE_OR_COPY< KpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.YY_MOVE_OR_COPY< QpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster: // raster
        value.YY_MOVE_OR_COPY< Raster > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.YY_MOVE_OR_COPY< SeedKey > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source: // source
        value.YY_MOVE_OR_COPY< Source > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.YY_MOVE_OR_COPY< TpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.YY_MOVE_OR_COPY< std::vector<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.YY_MOVE_OR_COPY< uint64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.YY_MOVE_OR_COPY< uint8_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  CcpDataParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.move< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_can_param: // can_param
        value.move< CanParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.move< ChecksumParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.move< DefinedPages > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.move< DpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_event_group: // event_group
        value.move< EventGroup > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.move< KpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.move< QpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster: // raster
        value.move< Raster > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.move< SeedKey > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_source: // source
        value.move< Source > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.move< TpBlob > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.move< std::vector<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.move< uint8_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  CcpDataParser::stack_symbol_type&
  CcpDataParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.copy< AddressMapping > (that.value);
        break;

      case symbol_kind::S_can_param: // can_param
        value.copy< CanParam > (that.value);
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.copy< ChecksumParam > (that.value);
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.copy< DefinedPages > (that.value);
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.copy< DpBlob > (that.value);
        break;

      case symbol_kind::S_event_group: // event_group
        value.copy< EventGroup > (that.value);
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.copy< KpBlob > (that.value);
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.copy< QpBlob > (that.value);
        break;

      case symbol_kind::S_raster: // raster
        value.copy< Raster > (that.value);
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.copy< SeedKey > (that.value);
        break;

      case symbol_kind::S_source: // source
        value.copy< Source > (that.value);
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.copy< TpBlob > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.copy< std::vector<uint8_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.copy< uint64_t > (that.value);
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.copy< uint8_t > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  CcpDataParser::stack_symbol_type&
  CcpDataParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.move< AddressMapping > (that.value);
        break;

      case symbol_kind::S_can_param: // can_param
        value.move< CanParam > (that.value);
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.move< ChecksumParam > (that.value);
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.move< DefinedPages > (that.value);
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.move< DpBlob > (that.value);
        break;

      case symbol_kind::S_event_group: // event_group
        value.move< EventGroup > (that.value);
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.move< KpBlob > (that.value);
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.move< QpBlob > (that.value);
        break;

      case symbol_kind::S_raster: // raster
        value.move< Raster > (that.value);
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.move< SeedKey > (that.value);
        break;

      case symbol_kind::S_source: // source
        value.move< Source > (that.value);
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.move< TpBlob > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.move< std::vector<uint8_t> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (that.value);
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.move< uint8_t > (that.value);
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
  CcpDataParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if CCPDEBUG
  template <typename Base>
  void
  CcpDataParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  CcpDataParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  CcpDataParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  CcpDataParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if CCPDEBUG
  std::ostream&
  CcpDataParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  CcpDataParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  CcpDataParser::debug_level_type
  CcpDataParser::debug_level () const
  {
    return yydebug_;
  }

  void
  CcpDataParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // CCPDEBUG

  CcpDataParser::state_type
  CcpDataParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  CcpDataParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  CcpDataParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  CcpDataParser::operator() ()
  {
    return parse ();
  }

  int
  CcpDataParser::parse ()
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
      case symbol_kind::S_addr_mapping: // addr_mapping
        yylhs.value.emplace< AddressMapping > ();
        break;

      case symbol_kind::S_can_param: // can_param
        yylhs.value.emplace< CanParam > ();
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        yylhs.value.emplace< ChecksumParam > ();
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        yylhs.value.emplace< DefinedPages > ();
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        yylhs.value.emplace< DpBlob > ();
        break;

      case symbol_kind::S_event_group: // event_group
        yylhs.value.emplace< EventGroup > ();
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        yylhs.value.emplace< KpBlob > ();
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        yylhs.value.emplace< QpBlob > ();
        break;

      case symbol_kind::S_raster: // raster
        yylhs.value.emplace< Raster > ();
        break;

      case symbol_kind::S_seed_key: // seed_key
        yylhs.value.emplace< SeedKey > ();
        break;

      case symbol_kind::S_source: // source
        yylhs.value.emplace< Source > ();
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        yylhs.value.emplace< TpBlob > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        yylhs.value.emplace< std::vector<uint8_t> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        yylhs.value.emplace< uint64_t > ();
        break;

      case symbol_kind::S_raster_value: // raster_value
        yylhs.value.emplace< uint8_t > ();
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
  case 6: // definition: source
#line 109 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   { scanner.AddSource(std::move(yystack_[0].value.as < Source > ())); }
#line 1167 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 15: // source: BLOCK_BEGIN SOURCE STRING any_int any_int source_options BLOCK_END SOURCE
#line 121 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
          Source& source = scanner.GetSource();
          source.SetName(yystack_[5].value.as < std::string > ());
          source.SetScalingUnit(yystack_[4].value.as < int64_t > ());
          source.SetRate(yystack_[3].value.as < int64_t > ());

          yylhs.value.as < Source > () = std::move(source);
          source.Reset();
        }
#line 1181 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 18: // source_option: DISPLAY_IDENTIFIER ident_or_string
#line 134 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                                  {
          Source& source = scanner.GetSource();
          source.SetDisplayIdentifier(std::move(yystack_[0].value.as < std::string > ()));
        }
#line 1190 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 19: // source_option: qp_blob
#line 137 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    {
          Source& source = scanner.GetSource();
          source.SetQpBlob(std::move(yystack_[0].value.as < QpBlob > ()));
        }
#line 1199 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 20: // qp_blob: BLOCK_BEGIN QP_BLOB UINT qp_blob_options BLOCK_END QP_BLOB
#line 144 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetNumber(yystack_[3].value.as < uint64_t > ());
  	  yylhs.value.as < QpBlob > () = std::move(blob);
  	  blob.Reset();
        }
#line 1210 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 23: // qp_blob_option: LENGTH UINT
#line 154 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetNumber(yystack_[0].value.as < uint64_t > ());
        }
#line 1219 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 24: // qp_blob_option: CAN_ID_VARIABLE
#line 157 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdVariable();
        }
#line 1228 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 25: // qp_blob_option: CAN_ID_FIXED UINT
#line 160 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdFixed(yystack_[0].value.as < uint64_t > ());
        }
#line 1237 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 26: // qp_blob_option: raster_value
#line 163 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddRaster(yystack_[0].value.as < uint8_t > ());
        }
#line 1246 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 27: // qp_blob_option: exclusive
#line 166 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                      {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddExclusive(yystack_[0].value.as < int64_t > ());
        }
#line 1255 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 28: // qp_blob_option: REDUCTION_ALLOWED
#line 169 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetReductionAllowed();
        }
#line 1264 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 29: // qp_blob_option: FIRST_PID UINT
#line 172 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetFirstPid(yystack_[0].value.as < uint64_t > ());
        }
#line 1273 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 30: // raster: BLOCK_BEGIN RASTER STRING STRING UINT any_int any_int exclusive_list BLOCK_END RASTER
#line 179 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
          yylhs.value.as < Raster > ().SetName(yystack_[7].value.as < std::string > ());
          yylhs.value.as < Raster > ().SetShortName(yystack_[6].value.as < std::string > ());
          yylhs.value.as < Raster > ().SetNumber(yystack_[5].value.as < uint64_t > ());
          yylhs.value.as < Raster > ().SetPeriod(yystack_[4].value.as < int64_t > ());
          yylhs.value.as < Raster > ().SetSampleRate(yystack_[3].value.as < int64_t > ());
          yylhs.value.as < Raster > ().SetExclusiveList(yystack_[2].value.as < std::vector<uint8_t> > ());
        }
#line 1286 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 31: // event_group: BLOCK_BEGIN EVENT_GROUP STRING STRING raster_list BLOCK_END EVENT_GROUP
#line 190 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
          yylhs.value.as < EventGroup > ().SetName(yystack_[4].value.as < std::string > ());
          yylhs.value.as < EventGroup > ().SetShortName(yystack_[3].value.as < std::string > ());
          yylhs.value.as < EventGroup > ().SetRasterList(yystack_[2].value.as < std::vector<uint8_t> > ());
        }
#line 1296 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 32: // seed_key: BLOCK_BEGIN SEED_KEY STRING STRING STRING BLOCK_END SEED_KEY
#line 198 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          yylhs.value.as < SeedKey > ().SetCalDll(yystack_[4].value.as < std::string > ());
          yylhs.value.as < SeedKey > ().SetDaqDll(yystack_[3].value.as < std::string > ());
          yylhs.value.as < SeedKey > ().SetPgmDll(yystack_[2].value.as < std::string > ());
        }
#line 1306 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 33: // checksum: BLOCK_BEGIN CHECKSUM STRING BLOCK_END CHECKSUM
#line 206 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ()); }
#line 1312 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 34: // tp_blob: BLOCK_BEGIN TP_BLOB UINT UINT UINT UINT UINT UINT tp_blob_options BLOCK_END TP_BLOB
#line 210 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetVersion(yystack_[8].value.as < uint64_t > ());
          blob.SetBlobVersion(yystack_[7].value.as < uint64_t > ());
          blob.SetTransmitMessageId(yystack_[6].value.as < uint64_t > ());
          blob.SetReceiveMessageId(yystack_[5].value.as < uint64_t > ());
          blob.SetAddress(yystack_[4].value.as < uint64_t > ());
          blob.SetByteOrder(yystack_[3].value.as < uint64_t > ());

          yylhs.value.as < TpBlob > () = std::move(blob);
          blob.Reset();
        }
#line 1329 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 37: // tp_blob_option: can_param
#line 226 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetCanParam(yystack_[0].value.as < CanParam > ());
        }
#line 1338 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 38: // tp_blob_option: BAUDRATE UINT
#line 229 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 1347 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 39: // tp_blob_option: SAMPLE_POINT UINT
#line 232 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 1356 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 40: // tp_blob_option: SAMPLE_RATE UINT
#line 235 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSampleRate(yystack_[0].value.as < uint64_t > ());
        }
#line 1365 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 41: // tp_blob_option: BTL_CYCLES UINT
#line 238 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 1374 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 42: // tp_blob_option: SJW UINT
#line 241 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                     {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 1383 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 43: // tp_blob_option: SYNC_EDGE IDENT
#line 244 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 1392 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 44: // tp_blob_option: SYNC_EDGE UINT
#line 247 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge(yystack_[0].value.as < uint64_t > ());
        }
#line 1401 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 45: // tp_blob_option: DAQ_MODE IDENT
#line 250 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetDaqMode(yystack_[0].value.as < std::string > ());
        }
#line 1410 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 46: // tp_blob_option: BYTES_ONLY
#line 253 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBytesOnly();
        }
#line 1419 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 47: // tp_blob_option: RESUME_SUPPORTED
#line 256 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetResumeSupported();
        }
#line 1428 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 48: // tp_blob_option: STORE_SUPPORTED
#line 259 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetStoreSupported();
        }
#line 1437 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 49: // tp_blob_option: CONSISTENCY IDENT
#line 262 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetConsistency(yystack_[0].value.as < std::string > ());
        }
#line 1446 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 50: // tp_blob_option: ADDRESS_EXTENSION IDENT
#line 265 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                    {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetAddressExtension(yystack_[0].value.as < std::string > ());
        }
#line 1455 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 51: // tp_blob_option: checksum_param
#line 268 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetChecksumParam(yystack_[0].value.as < ChecksumParam > ());
        }
#line 1464 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 52: // tp_blob_option: defined_pages
#line 271 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddDefinedPages(yystack_[0].value.as < DefinedPages > ());
        }
#line 1473 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 53: // tp_blob_option: OPTIONAL_CMD UINT
#line 274 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddOptionalCmd(yystack_[0].value.as < uint64_t > ());
        }
#line 1482 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 54: // can_param: BLOCK_BEGIN CAN_PARAM UINT UINT UINT BLOCK_END CAN_PARAM
#line 281 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                               {
           yylhs.value.as < CanParam > ().SetFrequency(yystack_[4].value.as < uint64_t > ());
           yylhs.value.as < CanParam > ().SetBtr0(yystack_[3].value.as < uint64_t > ());
           yylhs.value.as < CanParam > ().SetBtr1(yystack_[2].value.as < uint64_t > ());
         }
#line 1492 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 55: // checksum_param: BLOCK_BEGIN CHECKSUM_PARAM UINT UINT checksum_calculation BLOCK_END CHECKSUM_PARAM
#line 289 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                         {
          yylhs.value.as < ChecksumParam > ().SetType(yystack_[4].value.as < uint64_t > ());
          yylhs.value.as < ChecksumParam > ().SetMaxBlockLength(yystack_[3].value.as < uint64_t > ());
          yylhs.value.as < ChecksumParam > ().SetCalculation(yystack_[2].value.as < std::string > ());
        }
#line 1502 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 56: // checksum_calculation: %empty
#line 295 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < std::string > ().clear(); }
#line 1508 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 57: // checksum_calculation: CHECKSUM_CALCULATION IDENT
#line 296 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1514 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 58: // defined_pages: BLOCK_BEGIN DEFINED_PAGES UINT STRING UINT UINT UINT defined_pages_options BLOCK_END DEFINED_PAGES
#line 300 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                       {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetNumber(yystack_[7].value.as < uint64_t > ());
	  page.SetName(std::move(yystack_[6].value.as < std::string > ()));
	  page.SetAddressExtension(yystack_[5].value.as < uint64_t > ());
	  page.SetBaseAddress(yystack_[4].value.as < uint64_t > ());
	  page.SetLength(yystack_[3].value.as < uint64_t > ());

	  yylhs.value.as < DefinedPages > () = std::move(page);
	  page.Reset();
        }
#line 1530 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 61: // defined_pages_option: RAM
#line 315 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRam();
        }
#line 1539 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 62: // defined_pages_option: ROM
#line 318 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRom();
        }
#line 1548 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 63: // defined_pages_option: FLASH
#line 321 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                  {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetFlash();
        }
#line 1557 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 64: // defined_pages_option: EEPROM
#line 324 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   {
 	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetEeprom();
        }
#line 1566 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 65: // defined_pages_option: RAM_INIT_BY_ECU
#line 327 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByEcu();
        }
#line 1575 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 66: // defined_pages_option: RAM_INIT_BY_TOOL
#line 330 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByTool();
        }
#line 1584 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 67: // defined_pages_option: AUTO_FLASH_BACK
#line 333 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetAutoFlashBack();
        }
#line 1593 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 68: // defined_pages_option: FLASH_BACK
#line 336 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetFlashBack();
        }
#line 1602 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 69: // defined_pages_option: DEFAULT
#line 339 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetDefault();
        }
#line 1611 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 70: // addr_mapping: ADDR_MAPPING UINT UINT UINT
#line 344 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                          {
	  yylhs.value.as < AddressMapping > ().SetFromAddress(yystack_[2].value.as < uint64_t > ());
	  yylhs.value.as < AddressMapping > ().SetToAddress(yystack_[1].value.as < uint64_t > ());
	  yylhs.value.as < AddressMapping > ().SetLength(yystack_[0].value.as < uint64_t > ());
 	}
#line 1621 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 71: // dp_blob: DP_BLOB UINT UINT UINT
#line 351 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                {
	  yylhs.value.as < DpBlob > ().SetAddressExtension(yystack_[2].value.as < uint64_t > ());
	  yylhs.value.as < DpBlob > ().SetBaseAddress(yystack_[1].value.as < uint64_t > ());
	  yylhs.value.as < DpBlob > ().SetNofBytes(yystack_[0].value.as < uint64_t > ());
	}
#line 1631 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 72: // kp_blob: BLOCK_BEGIN KP_BLOB UINT UINT UINT raster_list BLOCK_END KP_BLOB
#line 359 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
           yylhs.value.as < KpBlob > ().SetAddressExtension(yystack_[5].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetBaseAddress(yystack_[4].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetNofBytes(yystack_[3].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetRaster(std::move(yystack_[2].value.as < std::vector<uint8_t> > ()));
         }
#line 1642 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 73: // exclusive_list: %empty
#line 366 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       { yylhs.value.as < std::vector<uint8_t> > ().clear();}
#line 1648 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 74: // exclusive_list: exclusive_list exclusive
#line 367 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
	  yylhs.value.as < std::vector<uint8_t> > () = std::move(yystack_[1].value.as < std::vector<uint8_t> > ());
	  yylhs.value.as < std::vector<uint8_t> > ().push_back(static_cast<uint8_t>(yystack_[0].value.as < int64_t > ()));
	}
#line 1657 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 75: // exclusive: EXCLUSIVE any_int
#line 372 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > ();}
#line 1663 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 76: // raster_list: %empty
#line 374 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    { yylhs.value.as < std::vector<uint8_t> > ().clear(); }
#line 1669 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 77: // raster_list: raster_list raster_value
#line 375 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
	  yylhs.value.as < std::vector<uint8_t> > () = std::move(yystack_[1].value.as < std::vector<uint8_t> > ());
	  yylhs.value.as < std::vector<uint8_t> > ().push_back(yystack_[0].value.as < uint8_t > ());
	}
#line 1678 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 78: // raster_value: RASTER UINT
#line 380 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          { yylhs.value.as < uint8_t > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1684 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 79: // any_int: INT
#line 382 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 1690 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 80: // any_int: UINT
#line 383 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1696 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 81: // ident_or_string: STRING
#line 385 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1702 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 82: // ident_or_string: IDENT
#line 386 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1708 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;


#line 1712 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"

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
  CcpDataParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if CCPDEBUG || 0
  const char *
  CcpDataParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if CCPDEBUG || 0









  const signed char CcpDataParser::yypact_ninf_ = -38;

  const signed char CcpDataParser::yytable_ninf_ = -1;

  const short
  CcpDataParser::yypact_[] =
  {
     -11,   -27,    24,     9,   -38,   -38,    13,     0,    -3,    37,
      22,    40,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,    43,    46,    48,    56,    52,    54,    55,
      64,    68,    72,    60,    70,    76,    73,    74,    33,    80,
      81,   -38,    63,   -38,    83,    86,    82,   -38,   -38,    33,
      88,   -38,   -38,   -15,   -38,    33,    78,   -38,    89,    62,
      93,   -38,   -13,    33,    45,    -2,    95,   -38,   -38,    65,
     -38,   -38,    59,    47,    44,   -38,   -38,   100,   -38,   -14,
     102,   -38,   -38,   -38,   -38,   -38,    61,    33,   -38,   -38,
      -9,   -38,   -38,    53,    99,   105,     1,    51,   107,   -38,
     104,   106,   109,   -38,   111,   112,   113,   -38,    16,   -38,
     -38,   -38,   -38,    75,   115,   -38,   116,   117,   -38,   -38,
     -38,   -38,   -38,   -38,   118,   119,   120,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   121,   122,   123,   124,   103,   125,   114,   126,   127,
     129,   108,   -38,   110,   132,   -38,   -38,   -38,    21,   -38,
     128,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38
  };

  const signed char
  CcpDataParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     4,     0,     3,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    76,     0,     0,     0,    80,    79,     0,
       0,    71,    33,     0,    76,     0,     0,    16,     0,     0,
       0,    77,     0,     0,     0,     0,     0,    31,    78,     0,
      73,    32,     0,     0,     0,    17,    19,     0,    72,     0,
       0,    15,    82,    81,    18,    35,     0,     0,    74,    21,
       0,    30,    75,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,    47,     0,     0,     0,    48,     0,    36,
      37,    51,    52,     0,     0,    24,     0,     0,    28,    22,
      27,    26,    50,    38,     0,     0,     0,    34,    41,    49,
      45,    53,    39,    40,    42,    44,    43,    20,    25,    29,
      23,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,    57,     0,     0,    54,    55,    59,     0,    67,
       0,    69,    64,    63,    68,    61,    65,    66,    62,    60,
      58
  };

  const signed char
  CcpDataParser::yypgoto_[] =
  {
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,    49,    84,
      57,   -37,   -38
  };

  const unsigned char
  CcpDataParser::yydefgoto_[] =
  {
       0,     2,     6,     7,    12,    13,    65,    75,    76,    93,
     119,    14,    15,    16,    17,    18,    90,   109,   110,   111,
     149,   112,   158,   169,    19,    20,    21,    79,    88,    53,
      61,    49,    84
  };

  const unsigned char
  CcpDataParser::yytable_[] =
  {
      94,    59,    86,    69,     1,    95,    96,    97,    98,    99,
       9,     3,    57,    72,    73,    10,   100,   101,    63,   135,
      87,     5,   124,   136,     4,   125,    70,    74,   126,     8,
      11,    60,   102,    60,   159,    22,    47,   160,    48,   103,
      23,   104,   105,    31,    24,   106,    32,   107,   108,   161,
      92,    82,    83,   162,    33,    25,    34,   163,   164,    35,
      36,    26,    37,    38,   165,   166,   167,    39,    27,   113,
     168,    40,   114,   115,    28,    41,    42,    29,    43,    44,
      30,    45,    46,    50,    51,    52,    54,    87,   116,    55,
      56,    58,    66,   117,    64,    67,    68,    71,    77,    60,
     118,    80,    81,    85,    78,    89,   122,    91,   123,   127,
     128,   129,   131,   130,   132,   133,   134,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   148,   147,   150,   155,
     151,   146,   154,   152,   156,   157,     0,     0,    62,     0,
       0,     0,   120,   153,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,     0,   170
  };

  const signed char
  CcpDataParser::yycheck_[] =
  {
       9,    16,    16,    16,    15,    14,    15,    16,    17,    18,
      10,    38,    49,    15,    16,    15,    25,    26,    55,     3,
      34,    12,    21,     7,     0,    24,    63,    29,    27,    16,
      30,    46,    41,    46,    13,    38,     3,    16,     5,    48,
       3,    50,    51,     3,    22,    54,     3,    56,    57,    28,
      87,     7,     8,    32,     8,    33,     8,    36,    37,     3,
       8,    39,     8,     8,    43,    44,    45,     3,    46,    16,
      49,     3,    19,    20,    52,     3,    16,    55,     8,     3,
      58,     8,     8,     3,     3,    22,     3,    34,    35,     3,
       8,     3,     3,    40,    16,    33,     3,    52,     3,    46,
      47,    42,    55,     3,    39,     3,     7,    46,     3,    58,
       3,     7,     3,     7,     3,     3,     3,    42,     3,     3,
       3,     3,     3,     3,     3,     3,    23,     3,     3,    21,
      16,     8,     3,     7,    24,     3,    -1,    -1,    54,    -1,
      -1,    -1,    93,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    27
  };

  const signed char
  CcpDataParser::yystos_[] =
  {
       0,    15,    60,    38,     0,    12,    61,    62,    16,    10,
      15,    30,    63,    64,    70,    71,    72,    73,    74,    83,
      84,    85,    38,     3,    22,    33,    39,    46,    52,    55,
      58,     3,     3,     8,     8,     3,     8,     8,     8,     3,
       3,     3,    16,     8,     3,     8,     8,     3,     5,    90,
       3,     3,    22,    88,     3,     3,     8,    90,     3,    16,
      46,    89,    88,    90,    16,    65,     3,    33,     3,    16,
      90,    52,    15,    16,    29,    66,    67,     3,    39,    86,
      42,    55,     7,     8,    91,     3,    16,    34,    87,     3,
      75,    46,    90,    68,     9,    14,    15,    16,    17,    18,
      25,    26,    41,    48,    50,    51,    54,    56,    57,    76,
      77,    78,    80,    16,    19,    20,    35,    40,    47,    69,
      87,    89,     7,     3,    21,    24,    27,    58,     3,     7,
       7,     3,     3,     3,     3,     3,     7,    42,     3,     3,
       3,     3,     3,     3,     3,     3,     8,     3,    23,    79,
       3,    16,     7,    16,     3,    21,    24,     3,    81,    13,
      16,    28,    32,    36,    37,    43,    44,    45,    49,    82,
      27
  };

  const signed char
  CcpDataParser::yyr1_[] =
  {
       0,    59,    60,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    65,    65,    66,    66,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      70,    71,    72,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    78,    79,    79,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    84,    85,    86,    86,    87,    88,    88,    89,    90,
      90,    91,    91
  };

  const signed char
  CcpDataParser::yyr2_[] =
  {
       0,     2,     5,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     0,     2,     2,     1,
       6,     0,     2,     2,     1,     2,     1,     1,     1,     2,
      10,     7,     7,     5,    11,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     1,     1,     2,     7,     7,     0,     2,    10,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     8,     0,     2,     2,     0,     2,     2,     1,
       1,     1,     1
  };


#if CCPDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const CcpDataParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "UINT", "HEX", "INT",
  "FLOAT", "IDENT", "STRING", "ADDRESS_EXTENSION", "ADDR_MAPPING",
  "ALTERNATING", "ASAP1B_CCP", "AUTO_FLASH_BACK", "BAUDRATE",
  "BLOCK_BEGIN", "BLOCK_END", "BTL_CYCLES", "BYTES_ONLY", "CAN_ID_FIXED",
  "CAN_ID_VARIABLE", "CAN_PARAM", "CHECKSUM", "CHECKSUM_CALCULATION",
  "CHECKSUM_PARAM", "CONSISTENCY", "DAQ_MODE", "DEFINED_PAGES", "DEFAULT",
  "DISPLAY_IDENTIFIER", "DP_BLOB", "DP_BLOB_VERSION", "EEPROM",
  "EVENT_GROUP", "EXCLUSIVE", "FIRST_PID", "FLASH", "FLASH_BACK",
  "IF_DATA", "KP_BLOB", "LENGTH", "OPTIONAL_CMD", "QP_BLOB", "RAM",
  "RAM_INIT_BY_ECU", "RAM_INIT_BY_TOOL", "RASTER", "REDUCTION_ALLOWED",
  "RESUME_SUPPORTED", "ROM", "SAMPLE_POINT", "SAMPLE_RATE", "SEED_KEY",
  "SINGLE", "SJW", "SOURCE", "STORE_SUPPORTED", "SYNC_EDGE", "TP_BLOB",
  "$accept", "ccp_data_block", "if_data", "definitions", "definition",
  "source", "source_options", "source_option", "qp_blob",
  "qp_blob_options", "qp_blob_option", "raster", "event_group", "seed_key",
  "checksum", "tp_blob", "tp_blob_options", "tp_blob_option", "can_param",
  "checksum_param", "checksum_calculation", "defined_pages",
  "defined_pages_options", "defined_pages_option", "addr_mapping",
  "dp_blob", "kp_blob", "exclusive_list", "exclusive", "raster_list",
  "raster_value", "any_int", "ident_or_string", YY_NULLPTR
  };
#endif


#if CCPDEBUG
  const short
  CcpDataParser::yyrline_[] =
  {
       0,   100,   100,   104,   106,   107,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   119,   131,   132,   134,   137,
     142,   151,   152,   154,   157,   160,   163,   166,   169,   172,
     177,   188,   196,   204,   208,   223,   224,   226,   229,   232,
     235,   238,   241,   244,   247,   250,   253,   256,   259,   262,
     265,   268,   271,   274,   279,   287,   295,   296,   298,   312,
     313,   315,   318,   321,   324,   327,   330,   333,   336,   339,
     344,   351,   357,   366,   367,   372,   374,   375,   380,   382,
     383,   385,   386
  };

  void
  CcpDataParser::yy_stack_print_ () const
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
  CcpDataParser::yy_reduce_print_ (int yyrule) const
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
#endif // CCPDEBUG

  CcpDataParser::symbol_kind_type
  CcpDataParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      55,    56,    57,    58
    };
    // Last valid token kind.
    const int code_max = 313;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
} } // a2l::ccp
#line 2190 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"

#line 388 "D:/projects/a2llib/src/ccp/ccpdataparser.y"


void a2l::ccp::CcpDataParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
