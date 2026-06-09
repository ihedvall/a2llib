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
#line 110 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   { scanner.AddSource(std::move(yystack_[0].value.as < Source > ())); }
#line 1167 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 7: // definition: raster
#line 111 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                 { scanner.AddRaster(std::move(yystack_[0].value.as < Raster > ())); }
#line 1173 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 8: // definition: event_group
#line 112 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                      { scanner.AddEventGroup(std::move(yystack_[0].value.as < EventGroup > ())); }
#line 1179 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 9: // definition: seed_key
#line 113 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   { scanner.SetSeedKey(std::move(yystack_[0].value.as < SeedKey > ())); }
#line 1185 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 10: // definition: checksum
#line 114 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   { scanner.SetChecksum(std::move(yystack_[0].value.as < std::string > ())); }
#line 1191 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 11: // definition: tp_blob
#line 115 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                  { scanner.SetTpBlob(std::move(yystack_[0].value.as < TpBlob > ())); }
#line 1197 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 12: // definition: addr_mapping
#line 116 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       { scanner.AddAddressMapping(std::move(yystack_[0].value.as < AddressMapping > ())); }
#line 1203 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 13: // definition: dp_blob
#line 117 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                  { scanner.SetDpBlob(std::move(yystack_[0].value.as < DpBlob > ())); }
#line 1209 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 14: // definition: kp_blob
#line 118 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                  { scanner.SetKpBlob(std::move(yystack_[0].value.as < KpBlob > ())); }
#line 1215 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 15: // source: BLOCK_BEGIN SOURCE STRING any_int any_int source_options BLOCK_END SOURCE
#line 122 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
          Source& source = scanner.GetSource();
          source.SetName(yystack_[5].value.as < std::string > ());
          source.SetScalingUnit(yystack_[4].value.as < int64_t > ());
          source.SetRate(yystack_[3].value.as < int64_t > ());

          yylhs.value.as < Source > () = std::move(source);
          source.Reset();
        }
#line 1229 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 18: // source_option: DISPLAY_IDENTIFIER ident_or_string
#line 135 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                                  {
          Source& source = scanner.GetSource();
          source.SetDisplayIdentifier(std::move(yystack_[0].value.as < std::string > ()));
        }
#line 1238 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 19: // source_option: qp_blob
#line 138 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    {
          Source& source = scanner.GetSource();
          source.SetQpBlob(std::move(yystack_[0].value.as < QpBlob > ()));
        }
#line 1247 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 20: // qp_blob: BLOCK_BEGIN QP_BLOB UINT qp_blob_options BLOCK_END QP_BLOB
#line 145 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetNumber(yystack_[3].value.as < uint64_t > ());
  	  yylhs.value.as < QpBlob > () = std::move(blob);
  	  blob.Reset();
        }
#line 1258 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 23: // qp_blob_option: LENGTH UINT
#line 155 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetLength(yystack_[0].value.as < uint64_t > ());
        }
#line 1267 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 24: // qp_blob_option: CAN_ID_VARIABLE
#line 158 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdVariable();
        }
#line 1276 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 25: // qp_blob_option: CAN_ID_FIXED UINT
#line 161 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdFixed(yystack_[0].value.as < uint64_t > ());
        }
#line 1285 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 26: // qp_blob_option: raster_value
#line 164 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddRaster(yystack_[0].value.as < uint8_t > ());
        }
#line 1294 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 27: // qp_blob_option: exclusive
#line 167 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                      {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddExclusive(yystack_[0].value.as < int64_t > ());
        }
#line 1303 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 28: // qp_blob_option: REDUCTION_ALLOWED
#line 170 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetReductionAllowed();
        }
#line 1312 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 29: // qp_blob_option: FIRST_PID UINT
#line 173 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetFirstPid(yystack_[0].value.as < uint64_t > ());
        }
#line 1321 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 30: // raster: BLOCK_BEGIN RASTER STRING STRING UINT any_int any_int exclusive_list BLOCK_END RASTER
#line 180 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                         {
          yylhs.value.as < Raster > ().SetName(yystack_[7].value.as < std::string > ());
          yylhs.value.as < Raster > ().SetShortName(yystack_[6].value.as < std::string > ());
          yylhs.value.as < Raster > ().SetNumber(yystack_[5].value.as < uint64_t > ());
          yylhs.value.as < Raster > ().SetPeriod(yystack_[4].value.as < int64_t > ());
          yylhs.value.as < Raster > ().SetSampleRate(yystack_[3].value.as < int64_t > ());
          yylhs.value.as < Raster > ().SetExclusiveList(yystack_[2].value.as < std::vector<uint8_t> > ());
        }
#line 1334 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 31: // event_group: BLOCK_BEGIN EVENT_GROUP STRING STRING raster_list BLOCK_END EVENT_GROUP
#line 191 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
          yylhs.value.as < EventGroup > ().SetName(yystack_[4].value.as < std::string > ());
          yylhs.value.as < EventGroup > ().SetShortName(yystack_[3].value.as < std::string > ());
          yylhs.value.as < EventGroup > ().SetRasterList(yystack_[2].value.as < std::vector<uint8_t> > ());
        }
#line 1344 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 32: // seed_key: BLOCK_BEGIN SEED_KEY STRING STRING STRING BLOCK_END SEED_KEY
#line 199 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          yylhs.value.as < SeedKey > ().SetCalDll(yystack_[4].value.as < std::string > ());
          yylhs.value.as < SeedKey > ().SetDaqDll(yystack_[3].value.as < std::string > ());
          yylhs.value.as < SeedKey > ().SetPgmDll(yystack_[2].value.as < std::string > ());
        }
#line 1354 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 33: // checksum: BLOCK_BEGIN CHECKSUM STRING BLOCK_END CHECKSUM
#line 207 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ()); }
#line 1360 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 34: // tp_blob: BLOCK_BEGIN TP_BLOB UINT UINT UINT UINT UINT UINT tp_blob_options BLOCK_END TP_BLOB
#line 211 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
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
#line 1377 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 37: // tp_blob_option: can_param
#line 227 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetCanParam(yystack_[0].value.as < CanParam > ());
        }
#line 1386 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 38: // tp_blob_option: BAUDRATE UINT
#line 230 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 1395 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 39: // tp_blob_option: SAMPLE_POINT UINT
#line 233 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 1404 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 40: // tp_blob_option: SAMPLE_RATE UINT
#line 236 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSampleRate(yystack_[0].value.as < uint64_t > ());
        }
#line 1413 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 41: // tp_blob_option: BTL_CYCLES UINT
#line 239 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 1422 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 42: // tp_blob_option: SJW UINT
#line 242 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                     {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 1431 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 43: // tp_blob_option: SYNC_EDGE IDENT
#line 245 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 1440 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 44: // tp_blob_option: SYNC_EDGE UINT
#line 248 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge(yystack_[0].value.as < uint64_t > ());
        }
#line 1449 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 45: // tp_blob_option: DAQ_MODE IDENT
#line 251 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetDaqMode(yystack_[0].value.as < std::string > ());
        }
#line 1458 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 46: // tp_blob_option: BYTES_ONLY
#line 254 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBytesOnly();
        }
#line 1467 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 47: // tp_blob_option: RESUME_SUPPORTED
#line 257 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetResumeSupported();
        }
#line 1476 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 48: // tp_blob_option: STORE_SUPPORTED
#line 260 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetStoreSupported();
        }
#line 1485 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 49: // tp_blob_option: CONSISTENCY IDENT
#line 263 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetConsistency(yystack_[0].value.as < std::string > ());
        }
#line 1494 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 50: // tp_blob_option: ADDRESS_EXTENSION IDENT
#line 266 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                    {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetAddressExtension(yystack_[0].value.as < std::string > ());
        }
#line 1503 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 51: // tp_blob_option: checksum_param
#line 269 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetChecksumParam(yystack_[0].value.as < ChecksumParam > ());
        }
#line 1512 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 52: // tp_blob_option: defined_pages
#line 272 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddDefinedPages(yystack_[0].value.as < DefinedPages > ());
        }
#line 1521 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 53: // tp_blob_option: OPTIONAL_CMD UINT
#line 275 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                              {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddOptionalCmd(yystack_[0].value.as < uint64_t > ());
        }
#line 1530 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 54: // can_param: BLOCK_BEGIN CAN_PARAM UINT UINT UINT BLOCK_END CAN_PARAM
#line 282 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                               {
           yylhs.value.as < CanParam > ().SetFrequency(yystack_[4].value.as < uint64_t > ());
           yylhs.value.as < CanParam > ().SetBtr0(yystack_[3].value.as < uint64_t > ());
           yylhs.value.as < CanParam > ().SetBtr1(yystack_[2].value.as < uint64_t > ());
         }
#line 1540 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 55: // checksum_param: BLOCK_BEGIN CHECKSUM_PARAM UINT UINT checksum_calculation BLOCK_END CHECKSUM_PARAM
#line 290 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                         {
          yylhs.value.as < ChecksumParam > ().SetType(yystack_[4].value.as < uint64_t > ());
          yylhs.value.as < ChecksumParam > ().SetMaxBlockLength(yystack_[3].value.as < uint64_t > ());
          yylhs.value.as < ChecksumParam > ().SetCalculation(yystack_[2].value.as < std::string > ());
        }
#line 1550 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 56: // checksum_calculation: %empty
#line 296 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < std::string > ().clear(); }
#line 1556 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 57: // checksum_calculation: CHECKSUM_CALCULATION IDENT
#line 297 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                     { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1562 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 58: // defined_pages: BLOCK_BEGIN DEFINED_PAGES UINT STRING UINT UINT UINT defined_pages_options BLOCK_END DEFINED_PAGES
#line 301 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
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
#line 1578 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 61: // defined_pages_option: RAM
#line 316 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRam();
        }
#line 1587 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 62: // defined_pages_option: ROM
#line 319 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRom();
        }
#line 1596 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 63: // defined_pages_option: FLASH
#line 322 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                  {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetFlash();
        }
#line 1605 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 64: // defined_pages_option: EEPROM
#line 325 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                   {
 	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetEeprom();
        }
#line 1614 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 65: // defined_pages_option: RAM_INIT_BY_ECU
#line 328 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByEcu();
        }
#line 1623 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 66: // defined_pages_option: RAM_INIT_BY_TOOL
#line 331 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByTool();
        }
#line 1632 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 67: // defined_pages_option: AUTO_FLASH_BACK
#line 334 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetAutoFlashBack();
        }
#line 1641 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 68: // defined_pages_option: FLASH_BACK
#line 337 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetFlashBack();
        }
#line 1650 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 69: // defined_pages_option: DEFAULT
#line 340 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetDefault();
        }
#line 1659 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 70: // addr_mapping: ADDR_MAPPING UINT UINT UINT
#line 345 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                          {
	  yylhs.value.as < AddressMapping > ().SetFromAddress(yystack_[2].value.as < uint64_t > ());
	  yylhs.value.as < AddressMapping > ().SetToAddress(yystack_[1].value.as < uint64_t > ());
	  yylhs.value.as < AddressMapping > ().SetLength(yystack_[0].value.as < uint64_t > ());
 	}
#line 1669 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 71: // addr_mapping: ADDRESS_MAPPING UINT UINT UINT
#line 349 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                           {
          yylhs.value.as < AddressMapping > ().SetFromAddress(yystack_[2].value.as < uint64_t > ());
          yylhs.value.as < AddressMapping > ().SetToAddress(yystack_[1].value.as < uint64_t > ());
          yylhs.value.as < AddressMapping > ().SetLength(yystack_[0].value.as < uint64_t > ());
       	}
#line 1679 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 72: // dp_blob: DP_BLOB UINT UINT UINT
#line 356 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                {
	  yylhs.value.as < DpBlob > ().SetAddressExtension(yystack_[2].value.as < uint64_t > ());
	  yylhs.value.as < DpBlob > ().SetBaseAddress(yystack_[1].value.as < uint64_t > ());
	  yylhs.value.as < DpBlob > ().SetNofBytes(yystack_[0].value.as < uint64_t > ());
	}
#line 1689 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 73: // kp_blob: BLOCK_BEGIN KP_BLOB UINT UINT UINT raster_list BLOCK_END KP_BLOB
#line 364 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                           {
           yylhs.value.as < KpBlob > ().SetAddressExtension(yystack_[5].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetBaseAddress(yystack_[4].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetNofBytes(yystack_[3].value.as < uint64_t > ());
           yylhs.value.as < KpBlob > ().SetRaster(std::move(yystack_[2].value.as < std::vector<uint8_t> > ()));
         }
#line 1700 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 74: // kp_blob: KP_BLOB UINT UINT UINT raster_list
#line 369 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                                {
            yylhs.value.as < KpBlob > ().SetAddressExtension(yystack_[3].value.as < uint64_t > ());
            yylhs.value.as < KpBlob > ().SetBaseAddress(yystack_[2].value.as < uint64_t > ());
            yylhs.value.as < KpBlob > ().SetNofBytes(yystack_[1].value.as < uint64_t > ());
            yylhs.value.as < KpBlob > ().SetRaster(std::move(yystack_[0].value.as < std::vector<uint8_t> > ()));
         }
#line 1711 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 75: // exclusive_list: %empty
#line 376 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                       { yylhs.value.as < std::vector<uint8_t> > ().clear();}
#line 1717 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 76: // exclusive_list: exclusive_list exclusive
#line 377 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
	  yylhs.value.as < std::vector<uint8_t> > () = std::move(yystack_[1].value.as < std::vector<uint8_t> > ());
	  yylhs.value.as < std::vector<uint8_t> > ().push_back(static_cast<uint8_t>(yystack_[0].value.as < int64_t > ()));
	}
#line 1726 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 77: // exclusive: EXCLUSIVE any_int
#line 382 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > ();}
#line 1732 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 78: // raster_list: %empty
#line 384 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                    { yylhs.value.as < std::vector<uint8_t> > ().clear(); }
#line 1738 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 79: // raster_list: raster_list raster_value
#line 385 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                                   {
	  yylhs.value.as < std::vector<uint8_t> > () = std::move(yystack_[1].value.as < std::vector<uint8_t> > ());
	  yylhs.value.as < std::vector<uint8_t> > ().push_back(yystack_[0].value.as < uint8_t > ());
	}
#line 1747 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 80: // raster_value: RASTER UINT
#line 390 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                          {
          yylhs.value.as < uint8_t > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
        }
#line 1755 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 81: // raster_value: ECU_RASTER UINT
#line 392 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                            {
           yylhs.value.as < uint8_t > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
        }
#line 1763 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 82: // any_int: INT
#line 400 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 1769 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 83: // any_int: UINT
#line 401 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 1775 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 84: // ident_or_string: STRING
#line 403 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                        { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1781 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;

  case 85: // ident_or_string: IDENT
#line 404 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1787 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"
    break;


#line 1791 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"

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









  const signed char CcpDataParser::yypact_ninf_ = -53;

  const signed char CcpDataParser::yytable_ninf_ = -1;

  const short
  CcpDataParser::yypact_[] =
  {
      -4,   -38,    60,    24,   -53,   -53,    34,    51,    29,    72,
      73,   -22,    75,    76,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,    77,    78,    79,    80,    82,
      81,    83,    85,    87,    91,    92,    93,    94,    69,    90,
      96,    95,    97,    37,    98,    99,   101,   -53,   -53,    84,
     -53,   103,   105,   102,   -53,   -53,    37,   106,   -53,   -53,
     -53,    -3,   -53,    37,   100,   -53,   108,   -28,    65,   109,
     110,   -53,     6,    37,    61,    -1,   111,   -53,   -53,   -53,
      86,   -53,   -53,    74,    59,    66,   -53,   -53,   116,   -53,
     -14,   117,   -53,   -53,   -53,   -53,   -53,    88,    37,   -53,
     -53,    -9,   -53,   -53,    35,   114,   119,     3,    63,   121,
     -53,   118,   122,   123,   -53,   125,   127,   128,   -53,    56,
     -53,   -53,   -53,   -53,    89,   129,   -53,   131,   132,   -53,
     -53,   -53,   -53,   -53,   -53,   134,   135,   136,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   137,   138,   139,   140,   120,   142,   133,   141,
     143,   146,   124,   -53,   126,   149,   -53,   -53,   -53,    19,
     -53,   130,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53
  };

  const signed char
  CcpDataParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     4,     0,     3,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,     0,
      78,     0,     0,     0,    83,    82,     0,     0,    72,    78,
      33,     0,    78,     0,     0,    16,     0,    74,     0,     0,
       0,    79,     0,     0,     0,     0,     0,    31,    81,    80,
       0,    75,    32,     0,     0,     0,    17,    19,     0,    73,
       0,     0,    15,    85,    84,    18,    35,     0,     0,    76,
      21,     0,    30,    77,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,    47,     0,     0,     0,    48,     0,
      36,    37,    51,    52,     0,     0,    24,     0,     0,    28,
      22,    27,    26,    50,    38,     0,     0,     0,    34,    41,
      49,    45,    53,    39,    40,    42,    44,    43,    20,    25,
      29,    23,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,    57,     0,     0,    54,    55,    59,     0,
      67,     0,    69,    64,    63,    68,    61,    65,    66,    62,
      60,    58
  };

  const signed char
  CcpDataParser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,    38,   -35,
      49,   -52,   -53
  };

  const unsigned char
  CcpDataParser::yydefgoto_[] =
  {
       0,     2,     6,     7,    14,    15,    75,    86,    87,   104,
     130,    16,    17,    18,    19,    20,   101,   120,   121,   122,
     160,   123,   169,   180,    21,    22,    23,    90,    99,    61,
      71,    56,    95
  };

  const unsigned char
  CcpDataParser::yytable_[] =
  {
     105,    27,     3,    97,    65,    69,   106,   107,   108,   109,
     110,    73,     1,    28,    68,    83,    84,   111,   112,    29,
      70,    81,    98,    80,    67,   135,    30,    72,   136,    85,
      69,   137,    31,   170,   113,    32,   171,     5,    33,    69,
      54,   114,    55,   115,   116,    70,   103,   117,   172,   118,
     119,     8,   124,   173,    70,   125,   126,   174,   175,   146,
       4,     9,    10,   147,   176,   177,   178,    11,    69,    24,
     179,    98,   127,    93,    94,    25,    26,   128,    34,    35,
      36,    37,    12,    70,   129,    40,    49,    38,    39,    41,
      44,    42,    13,    43,    45,    46,    47,    48,    50,    51,
      77,    57,    58,    52,    59,    53,    62,    60,    63,    66,
      64,    76,    78,    79,    88,    82,    92,    74,    91,    96,
     100,   133,   134,   138,   139,   140,   142,    89,   143,   141,
     144,   145,   149,   148,   150,   151,   102,   152,   153,   154,
     155,   156,   131,   158,   159,   161,   166,   157,   163,   165,
     162,   167,   168,   132,     0,     0,     0,     0,   181,     0,
     164
  };

  const signed char
  CcpDataParser::yycheck_[] =
  {
       9,    23,    40,    17,    56,    33,    15,    16,    17,    18,
      19,    63,    16,    35,    17,    16,    17,    26,    27,    41,
      48,    73,    36,    17,    59,    22,    48,    62,    25,    30,
      33,    28,    54,    14,    43,    57,    17,    13,    60,    33,
       3,    50,     5,    52,    53,    48,    98,    56,    29,    58,
      59,    17,    17,    34,    48,    20,    21,    38,    39,     3,
       0,    10,    11,     7,    45,    46,    47,    16,    33,    40,
      51,    36,    37,     7,     8,     3,     3,    42,     3,     3,
       3,     3,    31,    48,    49,     3,    17,     8,     8,     8,
       3,     8,    41,     8,     3,     3,     3,     3,     8,     3,
      35,     3,     3,     8,     3,     8,     3,    23,     3,     3,
       8,     3,     3,     3,     3,    54,    57,    17,    44,     3,
       3,     7,     3,    60,     3,     7,     3,    41,     3,     7,
       3,     3,     3,    44,     3,     3,    48,     3,     3,     3,
       3,     3,   104,     3,    24,     3,    22,     8,     7,     3,
      17,    25,     3,   104,    -1,    -1,    -1,    -1,    28,    -1,
      17
  };

  const signed char
  CcpDataParser::yystos_[] =
  {
       0,    16,    62,    40,     0,    13,    63,    64,    17,    10,
      11,    16,    31,    41,    65,    66,    72,    73,    74,    75,
      76,    85,    86,    87,    40,     3,     3,    23,    35,    41,
      48,    54,    57,    60,     3,     3,     3,     3,     8,     8,
       3,     8,     8,     8,     3,     3,     3,     3,     3,    17,
       8,     3,     8,     8,     3,     5,    92,     3,     3,     3,
      23,    90,     3,     3,     8,    92,     3,    90,    17,    33,
      48,    91,    90,    92,    17,    67,     3,    35,     3,     3,
      17,    92,    54,    16,    17,    30,    68,    69,     3,    41,
      88,    44,    57,     7,     8,    93,     3,    17,    36,    89,
       3,    77,    48,    92,    70,     9,    15,    16,    17,    18,
      19,    26,    27,    43,    50,    52,    53,    56,    58,    59,
      78,    79,    80,    82,    17,    20,    21,    37,    42,    49,
      71,    89,    91,     7,     3,    22,    25,    28,    60,     3,
       7,     7,     3,     3,     3,     3,     3,     7,    44,     3,
       3,     3,     3,     3,     3,     3,     3,     8,     3,    24,
      81,     3,    17,     7,    17,     3,    22,    25,     3,    83,
      14,    17,    29,    34,    38,    39,    45,    46,    47,    51,
      84,    28
  };

  const signed char
  CcpDataParser::yyr1_[] =
  {
       0,    61,    62,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      72,    73,    74,    75,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    80,    81,    81,    82,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    93
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
       4,     4,     4,     8,     5,     0,     2,     2,     0,     2,
       2,     2,     1,     1,     1,     1
  };


#if CCPDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const CcpDataParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "UINT", "HEX", "INT",
  "FLOAT", "IDENT", "STRING", "ADDRESS_EXTENSION", "ADDR_MAPPING",
  "ADDRESS_MAPPING", "ALTERNATING", "ASAP1B_CCP", "AUTO_FLASH_BACK",
  "BAUDRATE", "BLOCK_BEGIN", "BLOCK_END", "BTL_CYCLES", "BYTES_ONLY",
  "CAN_ID_FIXED", "CAN_ID_VARIABLE", "CAN_PARAM", "CHECKSUM",
  "CHECKSUM_CALCULATION", "CHECKSUM_PARAM", "CONSISTENCY", "DAQ_MODE",
  "DEFINED_PAGES", "DEFAULT", "DISPLAY_IDENTIFIER", "DP_BLOB",
  "DP_BLOB_VERSION", "ECU_RASTER", "EEPROM", "EVENT_GROUP", "EXCLUSIVE",
  "FIRST_PID", "FLASH", "FLASH_BACK", "IF_DATA", "KP_BLOB", "LENGTH",
  "OPTIONAL_CMD", "QP_BLOB", "RAM", "RAM_INIT_BY_ECU", "RAM_INIT_BY_TOOL",
  "RASTER", "REDUCTION_ALLOWED", "RESUME_SUPPORTED", "ROM", "SAMPLE_POINT",
  "SAMPLE_RATE", "SEED_KEY", "SINGLE", "SJW", "SOURCE", "STORE_SUPPORTED",
  "SYNC_EDGE", "TP_BLOB", "$accept", "ccp_data_block", "if_data",
  "definitions", "definition", "source", "source_options", "source_option",
  "qp_blob", "qp_blob_options", "qp_blob_option", "raster", "event_group",
  "seed_key", "checksum", "tp_blob", "tp_blob_options", "tp_blob_option",
  "can_param", "checksum_param", "checksum_calculation", "defined_pages",
  "defined_pages_options", "defined_pages_option", "addr_mapping",
  "dp_blob", "kp_blob", "exclusive_list", "exclusive", "raster_list",
  "raster_value", "any_int", "ident_or_string", YY_NULLPTR
  };
#endif


#if CCPDEBUG
  const short
  CcpDataParser::yyrline_[] =
  {
       0,   101,   101,   105,   107,   108,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   120,   132,   133,   135,   138,
     143,   152,   153,   155,   158,   161,   164,   167,   170,   173,
     178,   189,   197,   205,   209,   224,   225,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   260,   263,
     266,   269,   272,   275,   280,   288,   296,   297,   299,   313,
     314,   316,   319,   322,   325,   328,   331,   334,   337,   340,
     345,   349,   356,   362,   369,   376,   377,   382,   384,   385,
     390,   392,   400,   401,   403,   404
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
      55,    56,    57,    58,    59,    60
    };
    // Last valid token kind.
    const int code_max = 315;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
} } // a2l::ccp
#line 2274 "D:/projects/a2llib/src/ccp/ccpdataparser.cpp"

#line 406 "D:/projects/a2llib/src/ccp/ccpdataparser.y"


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
