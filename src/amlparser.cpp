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
#define yylex   amllex



#include "amlparser.hpp"


// Unqualified %code blocks.
#line 28 "D:/projects/a2llib/src/amlparser.y"

    #include <sstream>
    #include "amlscanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.amllex

#line 60 "D:/projects/a2llib/src/amlparser.cpp"


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
#if AMLDEBUG

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

#else // !AMLDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !AMLDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "D:/projects/a2llib/src/amlparser.y"
namespace a2l {
#line 134 "D:/projects/a2llib/src/amlparser.cpp"

  /// Build a parser object.
  AmlParser::AmlParser (a2l::AmlScanner &scanner_yyarg)
#if AMLDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  AmlParser::~AmlParser ()
  {}

  AmlParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  AmlParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.copy< a2l::AmlArrayList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_type: // data_type
        value.copy< a2l::AmlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< a2l::AmlDefinition > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< a2l::AmlDefinitionList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< a2l::AmlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.copy< a2l::AmlMember > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.copy< a2l::AmlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< std::pair<std::string, int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  AmlParser::symbol_kind_type
  AmlParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  AmlParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  AmlParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.move< a2l::AmlArrayList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_data_type: // data_type
        value.move< a2l::AmlDataType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< a2l::AmlDefinition > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< a2l::AmlDefinitionList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::AmlEnumerateList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.move< a2l::AmlMember > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::AmlMemberList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<std::string, int64_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  AmlParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  AmlParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  AmlParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  AmlParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  AmlParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  AmlParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  AmlParser::symbol_kind_type
  AmlParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  AmlParser::symbol_kind_type
  AmlParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  AmlParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  AmlParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  AmlParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  AmlParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  AmlParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  AmlParser::symbol_kind_type
  AmlParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  AmlParser::stack_symbol_type::stack_symbol_type ()
  {}

  AmlParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.YY_MOVE_OR_COPY< a2l::AmlArrayList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_type: // data_type
        value.YY_MOVE_OR_COPY< a2l::AmlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< a2l::AmlDefinition > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.YY_MOVE_OR_COPY< a2l::AmlDefinitionList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.YY_MOVE_OR_COPY< a2l::AmlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.YY_MOVE_OR_COPY< a2l::AmlMember > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.YY_MOVE_OR_COPY< a2l::AmlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.YY_MOVE_OR_COPY< std::pair<std::string, int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  AmlParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.move< a2l::AmlArrayList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_data_type: // data_type
        value.move< a2l::AmlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< a2l::AmlDefinition > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< a2l::AmlDefinitionList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::AmlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.move< a2l::AmlMember > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::AmlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<std::string, int64_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  AmlParser::stack_symbol_type&
  AmlParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.copy< a2l::AmlArrayList > (that.value);
        break;

      case symbol_kind::S_data_type: // data_type
        value.copy< a2l::AmlDataType > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< a2l::AmlDefinition > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< a2l::AmlDefinitionList > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< a2l::AmlEnumerateList > (that.value);
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.copy< a2l::AmlMember > (that.value);
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.copy< a2l::AmlMemberList > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< std::pair<std::string, int64_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  AmlParser::stack_symbol_type&
  AmlParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_array_specifier: // array_specifier
        value.move< a2l::AmlArrayList > (that.value);
        break;

      case symbol_kind::S_data_type: // data_type
        value.move< a2l::AmlDataType > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< a2l::AmlDefinition > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< a2l::AmlDefinitionList > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::AmlEnumerateList > (that.value);
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.move< a2l::AmlMember > (that.value);
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::AmlMemberList > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<std::string, int64_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        value.move< std::string > (that.value);
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
  AmlParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if AMLDEBUG
  template <typename Base>
  void
  AmlParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  AmlParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  AmlParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  AmlParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if AMLDEBUG
  std::ostream&
  AmlParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  AmlParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  AmlParser::debug_level_type
  AmlParser::debug_level () const
  {
    return yydebug_;
  }

  void
  AmlParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // AMLDEBUG

  AmlParser::state_type
  AmlParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  AmlParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  AmlParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  AmlParser::operator() ()
  {
    return parse ();
  }

  int
  AmlParser::parse ()
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
      case symbol_kind::S_array_specifier: // array_specifier
        yylhs.value.emplace< a2l::AmlArrayList > ();
        break;

      case symbol_kind::S_data_type: // data_type
        yylhs.value.emplace< a2l::AmlDataType > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< a2l::AmlDefinition > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        yylhs.value.emplace< a2l::AmlDefinitionList > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        yylhs.value.emplace< a2l::AmlEnumerateList > ();
        break;

      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_predefined_type_name: // predefined_type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        yylhs.value.emplace< a2l::AmlMember > ();
        break;

      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        yylhs.value.emplace< a2l::AmlMemberList > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_array: // array
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        yylhs.value.emplace< std::pair<std::string, int64_t> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
      case symbol_kind::S_include_file: // include_file
        yylhs.value.emplace< std::string > ();
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
  case 3: // aml_section: A2ML_BEGIN A2ML declaration_list A2ML_END A2ML
#line 109 "D:/projects/a2llib/src/amlparser.y"
                                                     {
        scanner.DefinitionList(yystack_[2].value.as < a2l::AmlDefinitionList > ());
    }
#line 1059 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 4: // aml_section: A2ML_BEGIN A2ML include_file A2ML_END A2ML
#line 112 "D:/projects/a2llib/src/amlparser.y"
                                                {
             // Todo: Handle include file
    }
#line 1067 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 5: // declaration_list: %empty
#line 116 "D:/projects/a2llib/src/amlparser.y"
                         {}
#line 1073 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 6: // declaration_list: declaration
#line 117 "D:/projects/a2llib/src/amlparser.y"
                  {
        yylhs.value.as < a2l::AmlDefinitionList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlDefinition > ()));
    }
#line 1081 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 7: // declaration_list: declaration_list declaration
#line 120 "D:/projects/a2llib/src/amlparser.y"
                                   {
        yylhs.value.as < a2l::AmlDefinitionList > () = std::move(yystack_[1].value.as < a2l::AmlDefinitionList > ());
        yylhs.value.as < a2l::AmlDefinitionList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlDefinition > ()));
    }
#line 1090 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 8: // declaration: type_definition def_end
#line 125 "D:/projects/a2llib/src/amlparser.y"
                                     {
        yylhs.value.as < a2l::AmlDefinition > ().Set(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlDefinition > ().DefinitionType(AmlDefinitionType::TYPE_DEFINITION);
    }
#line 1099 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 9: // declaration: block_definition def_end
#line 129 "D:/projects/a2llib/src/amlparser.y"
                               {
        yylhs.value.as < a2l::AmlDefinition > ().Set(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlDefinition > ().DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
    }
#line 1108 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 10: // type_definition: type_name
#line 135 "D:/projects/a2llib/src/amlparser.y"
                           {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().DefinitionType(AmlDefinitionType::TYPE_DEFINITION);
    }
#line 1117 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 11: // type_name: predefined_type_name
#line 140 "D:/projects/a2llib/src/amlparser.y"
                                 {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::PREDEFINED);
    }
#line 1126 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 12: // type_name: struct_type_name
#line 144 "D:/projects/a2llib/src/amlparser.y"
                       {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::STRUCT);
    }
#line 1135 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 13: // type_name: taggedstruct_type_name
#line 148 "D:/projects/a2llib/src/amlparser.y"
                             {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_STRUCT);
    }
#line 1144 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 14: // type_name: taggedunion_type_name
#line 152 "D:/projects/a2llib/src/amlparser.y"
                            {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_UNION);
    }
#line 1153 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 15: // type_name: enum_type_name
#line 156 "D:/projects/a2llib/src/amlparser.y"
                      {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[0].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::ENUMERATE);
    }
#line 1162 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 16: // predefined_type_name: data_type array_specifier
#line 161 "D:/projects/a2llib/src/amlparser.y"
                                                {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::PREDEFINED);
        yylhs.value.as < a2l::AmlMember > ().DataType(yystack_[1].value.as < a2l::AmlDataType > ());
        yylhs.value.as < a2l::AmlMember > ().ArrayList(yystack_[0].value.as < a2l::AmlArrayList > ());
    }
#line 1172 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 17: // predefined_type_name: MEM_BEGIN data_type array_specifier def_end MEM_END
#line 166 "D:/projects/a2llib/src/amlparser.y"
                                                          {
          yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::PREDEFINED);
          yylhs.value.as < a2l::AmlMember > ().DataType(yystack_[3].value.as < a2l::AmlDataType > ());
          yylhs.value.as < a2l::AmlMember > ().ArrayList(yystack_[2].value.as < a2l::AmlArrayList > ());
          yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1183 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 18: // data_type: CHAR
#line 174 "D:/projects/a2llib/src/amlparser.y"
                { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::CHAR; }
#line 1189 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 19: // data_type: INT
#line 175 "D:/projects/a2llib/src/amlparser.y"
          { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::INT;}
#line 1195 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 20: // data_type: LONG
#line 176 "D:/projects/a2llib/src/amlparser.y"
           { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::LONG;}
#line 1201 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 21: // data_type: INT64
#line 177 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::INT64;}
#line 1207 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 22: // data_type: UCHAR
#line 178 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::UCHAR;}
#line 1213 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 23: // data_type: UINT
#line 179 "D:/projects/a2llib/src/amlparser.y"
           { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::UINT;}
#line 1219 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 24: // data_type: UINT64
#line 180 "D:/projects/a2llib/src/amlparser.y"
             { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::UINT64;}
#line 1225 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 25: // data_type: ULONG
#line 181 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::ULONG;}
#line 1231 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 26: // data_type: DOUBLE
#line 182 "D:/projects/a2llib/src/amlparser.y"
             { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::DOUBLE;}
#line 1237 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 27: // data_type: FLOAT
#line 183 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::FLOAT;}
#line 1243 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 28: // data_type: TEXT_ARRAY
#line 184 "D:/projects/a2llib/src/amlparser.y"
                 { yylhs.value.as < a2l::AmlDataType > () = AmlDataType::TEXT_ARRAY;}
#line 1249 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 29: // block_definition: BLOCK tag member def_end
#line 187 "D:/projects/a2llib/src/amlparser.y"
                                           {
        yylhs.value.as < a2l::AmlMember > () = yystack_[1].value.as < a2l::AmlMember > ();
        yylhs.value.as < a2l::AmlMember > ().DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[2].value.as < std::string > ());
    }
#line 1259 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 30: // block_definition: BLOCK tag MEM_BEGIN member MEM_END
#line 192 "D:/projects/a2llib/src/amlparser.y"
                                         {
        yylhs.value.as < a2l::AmlMember > () = yystack_[1].value.as < a2l::AmlMember > ();
        yylhs.value.as < a2l::AmlMember > ().DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1270 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 31: // enum_type_name: ENUM identifier BLOCK_BEGIN enumerator_list BLOCK_END
#line 199 "D:/projects/a2llib/src/amlparser.y"
                                                                       {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::ENUMERATE);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().EnumerateList(yystack_[1].value.as < a2l::AmlEnumerateList > ());
    }
#line 1280 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 32: // enum_type_name: ENUM IDENT
#line 204 "D:/projects/a2llib/src/amlparser.y"
                 {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::ENUMERATE);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[0].value.as < std::string > ());
    }
#line 1289 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 33: // enumerator_list: enumerator
#line 209 "D:/projects/a2llib/src/amlparser.y"
                            {
       yylhs.value.as < a2l::AmlEnumerateList > ().emplace_back(std::move(yystack_[0].value.as < std::pair<std::string, int64_t> > ()));
    }
#line 1297 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 34: // enumerator_list: enumerator_list COMMA enumerator
#line 212 "D:/projects/a2llib/src/amlparser.y"
                                       {
        yylhs.value.as < a2l::AmlEnumerateList > () = std::move(yystack_[2].value.as < a2l::AmlEnumerateList > ());
        yylhs.value.as < a2l::AmlEnumerateList > ().emplace_back(std::move(yystack_[0].value.as < std::pair<std::string, int64_t> > ()));
    }
#line 1306 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 35: // enumerator: keyword
#line 217 "D:/projects/a2llib/src/amlparser.y"
                    {
        yylhs.value.as < std::pair<std::string, int64_t> > ().first = std::move(yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::pair<std::string, int64_t> > ().second = 0;
    }
#line 1315 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 36: // enumerator: keyword EQUAL CONSTANT
#line 221 "D:/projects/a2llib/src/amlparser.y"
                             {
        yylhs.value.as < std::pair<std::string, int64_t> > ().first = std::move(yystack_[2].value.as < std::string > ());
        yylhs.value.as < std::pair<std::string, int64_t> > ().second = yystack_[0].value.as < int64_t > ();
    }
#line 1324 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 37: // struct_type_name: STRUCT identifier BLOCK_BEGIN struct_member_list BLOCK_END
#line 226 "D:/projects/a2llib/src/amlparser.y"
                                                                             {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::STRUCT);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().MemberList(yystack_[1].value.as < a2l::AmlMemberList > ());
    }
#line 1334 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 38: // struct_type_name: STRUCT identifier
#line 231 "D:/projects/a2llib/src/amlparser.y"
                        {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::STRUCT);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[0].value.as < std::string > ());
    }
#line 1343 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 39: // struct_member_list: %empty
#line 236 "D:/projects/a2llib/src/amlparser.y"
                           {}
#line 1349 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 40: // struct_member_list: struct_member
#line 237 "D:/projects/a2llib/src/amlparser.y"
                    { yylhs.value.as < a2l::AmlMemberList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlMember > ())); }
#line 1355 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 41: // struct_member_list: struct_member_list struct_member
#line 238 "D:/projects/a2llib/src/amlparser.y"
                                       {
        yylhs.value.as < a2l::AmlMemberList > () = std::move(yystack_[1].value.as < a2l::AmlMemberList > ());
        yylhs.value.as < a2l::AmlMemberList > ().emplace_back(yystack_[0].value.as < a2l::AmlMember > ());
    }
#line 1364 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 42: // struct_member: member def_end
#line 243 "D:/projects/a2llib/src/amlparser.y"
                              {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
    }
#line 1372 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 43: // struct_member: MEM_BEGIN member MEM_END
#line 246 "D:/projects/a2llib/src/amlparser.y"
                               {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1381 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 44: // struct_member: block_definition def_end
#line 250 "D:/projects/a2llib/src/amlparser.y"
                               {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
    }
#line 1389 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 45: // member: type_name array_specifier
#line 254 "D:/projects/a2llib/src/amlparser.y"
                                  {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().ArrayList(yystack_[0].value.as < a2l::AmlArrayList > ());
    }
#line 1398 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 46: // taggedstruct_type_name: TAGGED_STRUCT identifier BLOCK_BEGIN taggedstruct_member_list BLOCK_END
#line 259 "D:/projects/a2llib/src/amlparser.y"
                                                                                                {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_STRUCT);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().MemberList(yystack_[1].value.as < a2l::AmlMemberList > ());
     }
#line 1408 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 47: // taggedstruct_type_name: TAGGED_STRUCT IDENT
#line 264 "D:/projects/a2llib/src/amlparser.y"
                          {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_STRUCT);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[0].value.as < std::string > ());
    }
#line 1417 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 48: // taggedstruct_member_list: %empty
#line 269 "D:/projects/a2llib/src/amlparser.y"
                                 {}
#line 1423 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 49: // taggedstruct_member_list: taggedstruct_member
#line 270 "D:/projects/a2llib/src/amlparser.y"
                          {
       yylhs.value.as < a2l::AmlMemberList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlMember > ()));
    }
#line 1431 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 50: // taggedstruct_member_list: taggedstruct_member_list taggedstruct_member
#line 273 "D:/projects/a2llib/src/amlparser.y"
                                                   {
       yylhs.value.as < a2l::AmlMemberList > () = std::move(yystack_[1].value.as < a2l::AmlMemberList > ());
       yylhs.value.as < a2l::AmlMemberList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlMember > ()));
    }
#line 1440 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 51: // taggedstruct_member: taggedstruct_definition def_end
#line 278 "D:/projects/a2llib/src/amlparser.y"
                                                     {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
    }
#line 1448 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 52: // taggedstruct_member: MEM_BEGIN taggedstruct_definition MEM_END def_end
#line 281 "D:/projects/a2llib/src/amlparser.y"
                                                        {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[2].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1457 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 53: // taggedstruct_member: block_definition def_end
#line 285 "D:/projects/a2llib/src/amlparser.y"
                               {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
    }
#line 1465 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 54: // taggedstruct_member: MEM_BEGIN block_definition MEM_END def_end
#line 288 "D:/projects/a2llib/src/amlparser.y"
                                                  {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[2].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1474 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 55: // taggedstruct_definition: tag
#line 293 "D:/projects/a2llib/src/amlparser.y"
                             {
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[0].value.as < std::string > ());
    }
#line 1482 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 56: // taggedstruct_definition: tag member def_end
#line 296 "D:/projects/a2llib/src/amlparser.y"
                         {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[2].value.as < std::string > ());
    }
#line 1491 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 57: // taggedstruct_definition: tag MEM_BEGIN member MEM_END
#line 300 "D:/projects/a2llib/src/amlparser.y"
                                   {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().VectorType(true);
    }
#line 1501 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 58: // taggedunion_type_name: TAGGED_UNION identifier BLOCK_BEGIN taggedunion_member_list BLOCK_END
#line 306 "D:/projects/a2llib/src/amlparser.y"
                                                                                             {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_UNION);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::AmlMember > ().MemberList( yystack_[1].value.as < a2l::AmlMemberList > ());
    }
#line 1511 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 59: // taggedunion_type_name: TAGGED_UNION IDENT
#line 311 "D:/projects/a2llib/src/amlparser.y"
                         {
        yylhs.value.as < a2l::AmlMember > ().TypeName(AmlTypeName::TAGGED_UNION);
        yylhs.value.as < a2l::AmlMember > ().Identity(yystack_[0].value.as < std::string > ());
    }
#line 1520 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 60: // taggedunion_member_list: %empty
#line 316 "D:/projects/a2llib/src/amlparser.y"
                                {}
#line 1526 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 61: // taggedunion_member_list: taggedunion_member
#line 317 "D:/projects/a2llib/src/amlparser.y"
                         {
        yylhs.value.as < a2l::AmlMemberList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlMember > ()));
    }
#line 1534 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 62: // taggedunion_member_list: taggedunion_member_list taggedunion_member
#line 320 "D:/projects/a2llib/src/amlparser.y"
                                                 {
        yylhs.value.as < a2l::AmlMemberList > () = std::move(yystack_[1].value.as < a2l::AmlMemberList > ());
        yylhs.value.as < a2l::AmlMemberList > ().emplace_back(std::move(yystack_[0].value.as < a2l::AmlMember > ()));
    }
#line 1543 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 63: // taggedunion_member: tag member def_end
#line 325 "D:/projects/a2llib/src/amlparser.y"
                                       {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
        yylhs.value.as < a2l::AmlMember > ().Tag(std::move(yystack_[2].value.as < std::string > ()));
    }
#line 1552 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 64: // taggedunion_member: tag def_end
#line 329 "D:/projects/a2llib/src/amlparser.y"
                  {
        yylhs.value.as < a2l::AmlMember > ().Tag(yystack_[1].value.as < std::string > ());
    }
#line 1560 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 65: // taggedunion_member: block_definition def_end
#line 332 "D:/projects/a2llib/src/amlparser.y"
                               {
        yylhs.value.as < a2l::AmlMember > () = std::move(yystack_[1].value.as < a2l::AmlMember > ());
    }
#line 1568 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 66: // array_specifier: %empty
#line 336 "D:/projects/a2llib/src/amlparser.y"
                        {}
#line 1574 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 67: // array_specifier: array
#line 337 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < a2l::AmlArrayList > ().push_back(yystack_[0].value.as < int64_t > ()); }
#line 1580 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 68: // array_specifier: array_specifier array
#line 338 "D:/projects/a2llib/src/amlparser.y"
                            {
        yylhs.value.as < a2l::AmlArrayList > () = std::move(yystack_[1].value.as < a2l::AmlArrayList > ());
        yylhs.value.as < a2l::AmlArrayList > ().push_back(yystack_[0].value.as < int64_t > ());
    }
#line 1589 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 69: // array: ARRAY_BEGIN CONSTANT ARRAY_END
#line 343 "D:/projects/a2llib/src/amlparser.y"
                                      { yylhs.value.as < int64_t > () = yystack_[1].value.as < int64_t > (); }
#line 1595 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 70: // keyword: STRING
#line 345 "D:/projects/a2llib/src/amlparser.y"
                 { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1601 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 71: // identifier: %empty
#line 347 "D:/projects/a2llib/src/amlparser.y"
                   {}
#line 1607 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 72: // identifier: IDENT
#line 348 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1613 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 73: // tag: STRING
#line 350 "D:/projects/a2llib/src/amlparser.y"
            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1619 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 74: // def_end: %empty
#line 352 "D:/projects/a2llib/src/amlparser.y"
                {}
#line 1625 "D:/projects/a2llib/src/amlparser.cpp"
    break;

  case 76: // include_file: INCLUDE STRING
#line 355 "D:/projects/a2llib/src/amlparser.y"
                             {
    yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
    }
#line 1633 "D:/projects/a2llib/src/amlparser.cpp"
    break;


#line 1637 "D:/projects/a2llib/src/amlparser.cpp"

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
  AmlParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if AMLDEBUG || 0
  const char *
  AmlParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if AMLDEBUG || 0









  const signed char AmlParser::yypact_ninf_ = -54;

  const signed char AmlParser::yytable_ninf_ = -73;

  const short
  AmlParser::yypact_[] =
  {
      13,    23,    45,   118,   -54,    19,   -54,   -54,    28,   -54,
      22,   -54,   -54,   -54,   294,    29,    31,    32,   -54,   -54,
     -54,   -54,   -54,    90,   -54,    38,   -54,   -54,    48,    38,
     -54,   -54,   -54,   -54,    51,   -54,   222,    53,    58,   -54,
      48,   -54,    59,    53,    61,    53,    62,    52,   -54,   -54,
     -54,    47,    48,   -54,   -54,    67,   246,    48,    38,    49,
      21,   174,    -2,    -3,   -54,    68,   -54,   -54,    48,    54,
      48,   -54,   -54,     3,   -54,    57,    55,   246,    38,   146,
     -54,    38,    -3,    38,    12,   -54,    38,   270,    38,     7,
     -54,   198,   -54,    21,   -54,   -54,    49,    64,   -54,    56,
     -54,   -54,   -54,   -54,    63,    73,   -54,   -54,   -54,   -54,
     246,    38,   -54,   -54,   -54,    38,   -54,   -54,   -54,   -54,
      38,    38,    74,   -54,   -54,   -54,   -54,   -54
  };

  const signed char
  AmlParser::yydefact_[] =
  {
       2,     0,     0,     5,     1,     0,    18,    26,    71,    27,
       0,    19,    21,    20,     0,    71,    71,    71,    28,    22,
      23,    24,    25,     0,     6,    74,    10,    11,    66,    74,
      15,    12,    13,    14,     0,    73,     0,    32,     0,    76,
      66,    72,    38,    47,     0,    59,     0,     0,     7,    75,
       8,     0,    16,    67,     9,     0,     0,    66,    74,     0,
      74,    39,    48,    60,     3,     0,    68,     4,    66,     0,
      45,    29,    70,     0,    33,    35,     0,     0,    74,     0,
      40,    74,     0,    74,     0,    49,    74,    55,    74,     0,
      61,    74,    69,    16,    30,    31,     0,     0,    17,     0,
      44,    37,    41,    42,     0,     0,    53,    46,    50,    51,
       0,    74,    65,    58,    62,    74,    64,    34,    36,    43,
      74,    74,     0,    56,    63,    54,    52,    57
  };

  const signed char
  AmlParser::yypgoto_[] =
  {
     -54,   -54,   -54,    60,   -54,     9,   -54,   -13,   -53,   -54,
     -54,   -17,   -54,   -54,    -1,   -18,   -54,   -54,     0,     5,
     -54,   -54,    -4,   -38,   -49,   -54,    25,     2,   -25,   -54
  };

  const signed char
  AmlParser::yydefgoto_[] =
  {
       0,     2,    23,    24,    25,    57,    27,    28,    29,    30,
      73,    74,    31,    79,    80,    81,    32,    84,    85,    86,
      33,    89,    90,    52,    53,    75,    38,    87,    76,    34
  };

  const signed char
  AmlParser::yytable_[] =
  {
      50,    40,    60,    66,    54,     5,     5,    36,    78,    83,
      88,    66,    26,    95,    96,     5,     1,   113,    58,    70,
       5,    66,   107,    82,    35,    35,    78,    51,     3,   104,
      93,    83,    26,    71,    35,    49,    88,    82,    69,    35,
      42,    44,    46,    68,    66,     4,    35,    37,    41,    39,
      43,    45,    49,   100,    51,    55,   103,    64,   106,    99,
      65,   109,   -72,   112,    68,    91,   116,    59,    61,   111,
      62,    63,    67,   115,    97,    92,    72,   118,   102,   117,
      94,    98,   119,    48,   108,   114,   123,   105,     0,   120,
     124,    91,   122,     0,    47,   125,   126,    68,     5,   121,
     127,     0,     6,     0,     0,     7,     8,     0,     9,     0,
       0,     0,    11,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,     5,     0,     0,     0,
       6,     0,     0,     7,     8,     0,     9,     0,     0,    10,
      11,    12,    13,    14,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     5,     0,   101,     0,     6,     0,
       0,     7,     8,     0,     9,     0,     0,     0,    11,    12,
      13,    77,     0,     0,    15,    16,    17,    18,    19,    20,
      21,    22,     5,     0,     0,     0,     6,     0,     0,     7,
       8,     0,     9,     0,     0,     0,    11,    12,    13,    77,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       6,     0,    49,     7,     8,     0,     9,     0,     0,     0,
      11,    12,    13,    14,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     6,     0,     0,     7,     8,     0,
       9,     0,     0,     0,    11,    12,    13,    56,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,     6,     0,
       0,     7,     8,     0,     9,     0,     0,     0,    11,    12,
      13,    14,     0,     0,    15,    16,    17,    18,    19,    20,
      21,    22,     6,     0,     0,     7,     8,     0,     9,     0,
       0,     0,    11,    12,    13,   110,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,     6,     0,     0,     7,
       0,     0,     9,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22
  };

  const signed char
  AmlParser::yycheck_[] =
  {
      25,    14,    40,    52,    29,     8,     8,     5,    61,    62,
      63,    60,     3,    10,    11,     8,     3,    10,    36,    57,
       8,    70,    10,    25,    27,    27,    79,     6,     5,    82,
      68,    84,    23,    58,    27,    14,    89,    25,    56,    27,
      15,    16,    17,    56,    93,     0,    27,    19,    19,    27,
      19,    19,    14,    78,     6,     4,    81,     5,    83,    77,
      13,    86,     9,    88,    77,    63,    91,     9,     9,    87,
       9,     9,     5,    91,    17,     7,    27,    13,    79,    96,
      26,    26,    26,    23,    84,    89,   111,    82,    -1,    26,
     115,    89,   110,    -1,     4,   120,   121,   110,     8,    26,
      26,    -1,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,     8,    -1,    10,    -1,    12,    -1,
      -1,    15,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      12,    -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    12,    -1,    -1,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    12,    -1,
      -1,    15,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    12,    -1,    -1,    15,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    12,    -1,    -1,    15,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35
  };

  const signed char
  AmlParser::yystos_[] =
  {
       0,     3,    37,     5,     0,     8,    12,    15,    16,    18,
      21,    22,    23,    24,    25,    28,    29,    30,    31,    32,
      33,    34,    35,    38,    39,    40,    41,    42,    43,    44,
      45,    48,    52,    56,    65,    27,    63,    19,    62,    27,
      43,    19,    62,    19,    62,    19,    62,     4,    39,    14,
      64,     6,    59,    60,    64,     4,    25,    41,    51,     9,
      59,     9,     9,     9,     5,    13,    60,     5,    43,    51,
      59,    64,    27,    46,    47,    61,    64,    25,    44,    49,
      50,    51,    25,    44,    53,    54,    55,    63,    44,    57,
      58,    63,     7,    59,    26,    10,    11,    17,    26,    51,
      64,    10,    50,    64,    44,    55,    64,    10,    54,    64,
      25,    51,    64,    10,    58,    51,    64,    47,    13,    26,
      26,    26,    51,    64,    64,    64,    64,    26
  };

  const signed char
  AmlParser::yyr1_[] =
  {
       0,    36,    37,    37,    37,    38,    38,    38,    39,    39,
      40,    41,    41,    41,    41,    41,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    59,    60,
      61,    62,    62,    63,    64,    64,    65
  };

  const signed char
  AmlParser::yyr2_[] =
  {
       0,     2,     0,     5,     5,     0,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     2,     1,     3,     1,     3,     5,     2,     0,
       1,     2,     2,     3,     2,     2,     5,     2,     0,     1,
       2,     2,     4,     2,     4,     1,     3,     4,     5,     2,
       0,     1,     2,     3,     2,     2,     0,     1,     2,     3,
       1,     0,     1,     1,     0,     1,     2
  };


#if AMLDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const AmlParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "A2ML_BEGIN",
  "A2ML_END", "A2ML", "ARRAY_BEGIN", "ARRAY_END", "BLOCK", "BLOCK_BEGIN",
  "BLOCK_END", "COMMA", "CHAR", "CONSTANT", "DEF_END", "DOUBLE", "ENUM",
  "EQUAL", "FLOAT", "IDENT", "IF_DATA", "INCLUDE", "INT", "INT64", "LONG",
  "MEM_BEGIN", "MEM_END", "STRING", "STRUCT", "TAGGED_STRUCT",
  "TAGGED_UNION", "TEXT_ARRAY", "UCHAR", "UINT", "UINT64", "ULONG",
  "$accept", "aml_section", "declaration_list", "declaration",
  "type_definition", "type_name", "predefined_type_name", "data_type",
  "block_definition", "enum_type_name", "enumerator_list", "enumerator",
  "struct_type_name", "struct_member_list", "struct_member", "member",
  "taggedstruct_type_name", "taggedstruct_member_list",
  "taggedstruct_member", "taggedstruct_definition",
  "taggedunion_type_name", "taggedunion_member_list", "taggedunion_member",
  "array_specifier", "array", "keyword", "identifier", "tag", "def_end",
  "include_file", YY_NULLPTR
  };
#endif


#if AMLDEBUG
  const short
  AmlParser::yyrline_[] =
  {
       0,   108,   108,   109,   112,   116,   117,   120,   125,   129,
     135,   140,   144,   148,   152,   156,   161,   166,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   187,
     192,   199,   204,   209,   212,   217,   221,   226,   231,   236,
     237,   238,   243,   246,   250,   254,   259,   264,   269,   270,
     273,   278,   281,   285,   288,   293,   296,   300,   306,   311,
     316,   317,   320,   325,   329,   332,   336,   337,   338,   343,
     345,   347,   348,   350,   352,   353,   355
  };

  void
  AmlParser::yy_stack_print_ () const
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
  AmlParser::yy_reduce_print_ (int yyrule) const
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
#endif // AMLDEBUG

  AmlParser::symbol_kind_type
  AmlParser::yytranslate_ (int t) YY_NOEXCEPT
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
      35
    };
    // Last valid token kind.
    const int code_max = 290;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/amlparser.y"
} // a2l
#line 2122 "D:/projects/a2llib/src/amlparser.cpp"

#line 359 "D:/projects/a2llib/src/amlparser.y"


void a2l::AmlParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
