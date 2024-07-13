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
#define yylex   a2mllex



#include "a2mlparser.hpp"


// Unqualified %code blocks.
#line 26 "D:/projects/a2llib/src/a2mlparser.y"

    #include <sstream>
    #include "a2mlscanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.a2mllex

#line 60 "D:/projects/a2llib/src/a2mlparser.cpp"


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
#if A2MLDEBUG

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

#else // !A2MLDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !A2MLDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "D:/projects/a2llib/src/a2mlparser.y"
namespace a2l {
#line 134 "D:/projects/a2llib/src/a2mlparser.cpp"

  /// Build a parser object.
  A2mlParser::A2mlParser (a2l::A2mlScanner &scanner_yyarg)
#if A2MLDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  A2mlParser::~A2mlParser ()
  {}

  A2mlParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  A2mlParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.copy< a2l::A2mlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< a2l::A2mlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.copy< a2l::A2mlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.copy< a2l::A2mlObject > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< std::pair<int64_t, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  A2mlParser::symbol_kind_type
  A2mlParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  A2mlParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  A2mlParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.move< a2l::A2mlDataType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::A2mlEnumerateList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::A2mlMemberList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.move< a2l::A2mlObject > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<int64_t, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  A2mlParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  A2mlParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  A2mlParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  A2mlParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  A2mlParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  A2mlParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  A2mlParser::symbol_kind_type
  A2mlParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  A2mlParser::symbol_kind_type
  A2mlParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  A2mlParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  A2mlParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  A2mlParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  A2mlParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  A2mlParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  A2mlParser::symbol_kind_type
  A2mlParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  A2mlParser::stack_symbol_type::stack_symbol_type ()
  {}

  A2mlParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.YY_MOVE_OR_COPY< a2l::A2mlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.YY_MOVE_OR_COPY< a2l::A2mlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.YY_MOVE_OR_COPY< a2l::A2mlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.YY_MOVE_OR_COPY< a2l::A2mlObject > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.YY_MOVE_OR_COPY< std::pair<int64_t, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
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

  A2mlParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.move< a2l::A2mlDataType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::A2mlEnumerateList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::A2mlMemberList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.move< a2l::A2mlObject > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<int64_t, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  A2mlParser::stack_symbol_type&
  A2mlParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.copy< a2l::A2mlDataType > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< a2l::A2mlEnumerateList > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.copy< a2l::A2mlMemberList > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.copy< a2l::A2mlObject > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< std::pair<int64_t, std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  A2mlParser::stack_symbol_type&
  A2mlParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.move< a2l::A2mlDataType > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::A2mlEnumerateList > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::A2mlMemberList > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        value.move< a2l::A2mlObject > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<int64_t, std::string> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
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
  A2mlParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if A2MLDEBUG
  template <typename Base>
  void
  A2mlParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  A2mlParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  A2mlParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  A2mlParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if A2MLDEBUG
  std::ostream&
  A2mlParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  A2mlParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  A2mlParser::debug_level_type
  A2mlParser::debug_level () const
  {
    return yydebug_;
  }

  void
  A2mlParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // A2MLDEBUG

  A2mlParser::state_type
  A2mlParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  A2mlParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  A2mlParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  A2mlParser::operator() ()
  {
    return parse ();
  }

  int
  A2mlParser::parse ()
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
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        yylhs.value.emplace< a2l::A2mlDataType > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        yylhs.value.emplace< a2l::A2mlEnumerateList > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        yylhs.value.emplace< a2l::A2mlMemberList > ();
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
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
        yylhs.value.emplace< a2l::A2mlObject > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        yylhs.value.emplace< std::pair<int64_t, std::string> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
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
  case 3: // a2ml_block: A2ML_BEGIN A2ML declaration_list A2ML_END A2ML
#line 101 "D:/projects/a2llib/src/a2mlparser.y"
                                                     {
        scanner.BlockList(yystack_[2].value.as < a2l::A2mlMemberList > ());
    }
#line 968 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 4: // declaration_list: declaration
#line 105 "D:/projects/a2llib/src/a2mlparser.y"
                              {
        yylhs.value.as < a2l::A2mlMemberList > () = A2mlMemberList();
        yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 977 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 5: // declaration_list: declaration_list declaration
#line 109 "D:/projects/a2llib/src/a2mlparser.y"
                                   {
        yylhs.value.as < a2l::A2mlMemberList > () = yystack_[1].value.as < a2l::A2mlMemberList > ();
        yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 986 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 6: // declaration: type_definition DEF_END
#line 114 "D:/projects/a2llib/src/a2mlparser.y"
                                     { yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > (); }
#line 992 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 7: // declaration: block_definition DEF_END
#line 115 "D:/projects/a2llib/src/a2mlparser.y"
                               {  yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > (); }
#line 998 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 8: // type_definition: type_name
#line 117 "D:/projects/a2llib/src/a2mlparser.y"
                           { yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();}
#line 1004 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 9: // type_name: predefined_type_name
#line 119 "D:/projects/a2llib/src/a2mlparser.y"
                                 {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::PREDEFINED);
        yylhs.value.as < a2l::A2mlObject > ().DataType(yystack_[0].value.as < a2l::A2mlDataType > ());
    }
#line 1013 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 10: // type_name: struct_type_name
#line 123 "D:/projects/a2llib/src/a2mlparser.y"
                       {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();
    }
#line 1021 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 11: // type_name: taggedstruct_type_name
#line 126 "D:/projects/a2llib/src/a2mlparser.y"
                             {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();
    }
#line 1029 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 12: // type_name: taggedunion_type_name
#line 129 "D:/projects/a2llib/src/a2mlparser.y"
                            {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();
    }
#line 1037 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 13: // type_name: enum_type_name
#line 132 "D:/projects/a2llib/src/a2mlparser.y"
                      {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();
    }
#line 1045 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 14: // predefined_type_name: CHAR
#line 136 "D:/projects/a2llib/src/a2mlparser.y"
                           { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::CHAR;}
#line 1051 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 15: // predefined_type_name: INT
#line 137 "D:/projects/a2llib/src/a2mlparser.y"
          { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::INT;}
#line 1057 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 16: // predefined_type_name: LONG
#line 138 "D:/projects/a2llib/src/a2mlparser.y"
           { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::LONG;}
#line 1063 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 17: // predefined_type_name: INT64
#line 139 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::INT64;}
#line 1069 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 18: // predefined_type_name: UCHAR
#line 140 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::UCHAR;}
#line 1075 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 19: // predefined_type_name: UINT
#line 141 "D:/projects/a2llib/src/a2mlparser.y"
           { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::UINT;}
#line 1081 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 20: // predefined_type_name: UINT64
#line 142 "D:/projects/a2llib/src/a2mlparser.y"
             { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::UINT64;}
#line 1087 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 21: // predefined_type_name: ULONG
#line 143 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::ULONG;}
#line 1093 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 22: // predefined_type_name: DOUBLE
#line 144 "D:/projects/a2llib/src/a2mlparser.y"
             { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::DOUBLE;}
#line 1099 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 23: // predefined_type_name: FLOAT
#line 145 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::FLOAT;}
#line 1105 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 24: // predefined_type_name: TEXT_ARRAY
#line 146 "D:/projects/a2llib/src/a2mlparser.y"
                 { yylhs.value.as < a2l::A2mlDataType > () = A2mlDataType::TEXT_ARRAY;}
#line 1111 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 25: // block_definition: BLOCK tag member
#line 149 "D:/projects/a2llib/src/a2mlparser.y"
                                   {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::BLOCK);
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[1].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().MemberList().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1121 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 26: // block_definition: BLOCK tag MEM_BEGIN member MEM_END
#line 154 "D:/projects/a2llib/src/a2mlparser.y"
                                         {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::BLOCK);
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().MemberList().emplace_back(yystack_[1].value.as < a2l::A2mlObject > ());
    }
#line 1131 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 27: // enum_type_name: ENUM identifier BLOCK_BEGIN enumerator_list BLOCK_END
#line 161 "D:/projects/a2llib/src/a2mlparser.y"
                                                                       {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::ENUMERATE);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().EnumerateList(yystack_[1].value.as < a2l::A2mlEnumerateList > ());
    }
#line 1141 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 28: // enum_type_name: ENUM IDENT
#line 166 "D:/projects/a2llib/src/a2mlparser.y"
                 {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::ENUMERATE);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[0].value.as < std::string > ());
    }
#line 1150 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 29: // enumerator_list: enumerator
#line 171 "D:/projects/a2llib/src/a2mlparser.y"
                            {
        A2mlEnumerateList list;
        auto& enumerator = yystack_[0].value.as < std::pair<int64_t, std::string> > ();
        const auto itr = list.find(enumerator.first);
        if (itr == list.cend() ) {
            list.emplace(enumerator.first, enumerator.second);
        } else {
            // Change key
            auto key = list.rbegin()->first;
            ++key;
            list.emplace(key, enumerator.second);
        }
        yylhs.value.as < a2l::A2mlEnumerateList > () = list;
    }
#line 1169 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 30: // enumerator_list: enumerator_list enumerator
#line 185 "D:/projects/a2llib/src/a2mlparser.y"
                                 {
        auto& list = yystack_[1].value.as < a2l::A2mlEnumerateList > ();
        auto& enumerator = yystack_[0].value.as < std::pair<int64_t, std::string> > ();
        const auto itr = list.find(enumerator.first);
        if (itr == list.cend() ) {
            list.emplace(enumerator.first, enumerator.second);
        } else {
            // Change key
            auto key = list.rbegin()->first;
            ++key;
            list.emplace(key, enumerator.second);
        }
        yylhs.value.as < a2l::A2mlEnumerateList > () = list;
    }
#line 1188 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 31: // enumerator: keyword
#line 200 "D:/projects/a2llib/src/a2mlparser.y"
                    {
        yylhs.value.as < std::pair<int64_t, std::string> > ().first = 0;
        yylhs.value.as < std::pair<int64_t, std::string> > ().second = yystack_[0].value.as < std::string > ();
    }
#line 1197 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 32: // enumerator: keyword EQUAL CONSTANT
#line 204 "D:/projects/a2llib/src/a2mlparser.y"
                             {
        yylhs.value.as < std::pair<int64_t, std::string> > ().first = yystack_[0].value.as < int64_t > ();
        yylhs.value.as < std::pair<int64_t, std::string> > ().second = yystack_[2].value.as < std::string > ();
    }
#line 1206 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 33: // struct_type_name: STRUCT identifier BLOCK_BEGIN struct_member_list BLOCK_END
#line 209 "D:/projects/a2llib/src/a2mlparser.y"
                                                                             {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::STRUCT);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().MemberList(yystack_[1].value.as < a2l::A2mlMemberList > ());
    }
#line 1216 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 34: // struct_type_name: STRUCT IDENT
#line 214 "D:/projects/a2llib/src/a2mlparser.y"
                   {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::STRUCT);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[0].value.as < std::string > ());
    }
#line 1225 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 35: // struct_member_list: %empty
#line 219 "D:/projects/a2llib/src/a2mlparser.y"
                           {}
#line 1231 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 36: // struct_member_list: struct_member_list struct_member
#line 220 "D:/projects/a2llib/src/a2mlparser.y"
                                       {
        yylhs.value.as < a2l::A2mlMemberList > () = yystack_[1].value.as < a2l::A2mlMemberList > ();
        yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1240 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 37: // struct_member: member DEF_END
#line 225 "D:/projects/a2llib/src/a2mlparser.y"
                              {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();
    }
#line 1248 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 38: // struct_member: MEM_BEGIN member MEM_END DEF_END
#line 228 "D:/projects/a2llib/src/a2mlparser.y"
                                       {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[2].value.as < a2l::A2mlObject > ();
    }
#line 1256 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 39: // member: type_name array_specifier
#line 232 "D:/projects/a2llib/src/a2mlparser.y"
                                  {
    yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();
    // Todo Array specifier
}
#line 1265 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 42: // taggedstruct_type_name: TAGGED_STRUCT identifier BLOCK_BEGIN taggedstruct_member_list BLOCK_END
#line 240 "D:/projects/a2llib/src/a2mlparser.y"
                                                                                                {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::TAGGED_STRUCT);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().MemberList(yystack_[1].value.as < a2l::A2mlMemberList > ());
    }
#line 1275 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 43: // taggedstruct_type_name: TAGGED_STRUCT IDENT
#line 245 "D:/projects/a2llib/src/a2mlparser.y"
                          {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::TAGGED_STRUCT);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[0].value.as < std::string > ());
    }
#line 1284 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 44: // taggedstruct_member_list: taggedstruct_member
#line 250 "D:/projects/a2llib/src/a2mlparser.y"
                                              {
       yylhs.value.as < a2l::A2mlMemberList > () = A2mlMemberList();
       yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1293 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 45: // taggedstruct_member_list: taggedstruct_member_list taggedstruct_member
#line 254 "D:/projects/a2llib/src/a2mlparser.y"
                                                   {
       yylhs.value.as < a2l::A2mlMemberList > () = yystack_[1].value.as < a2l::A2mlMemberList > ();
       yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1302 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 46: // taggedstruct_member: taggedstruct_definition DEF_END
#line 259 "D:/projects/a2llib/src/a2mlparser.y"
                                                     { yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > (); }
#line 1308 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 47: // taggedstruct_member: MEM_BEGIN taggedstruct_definition MEM_END DEF_END
#line 260 "D:/projects/a2llib/src/a2mlparser.y"
                                                        { yylhs.value.as < a2l::A2mlObject > () = yystack_[2].value.as < a2l::A2mlObject > (); }
#line 1314 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 48: // taggedstruct_member: block_definition DEF_END
#line 261 "D:/projects/a2llib/src/a2mlparser.y"
                               {yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();}
#line 1320 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 49: // taggedstruct_member: MEM_BEGIN block_definition MEM_END DEF_END
#line 262 "D:/projects/a2llib/src/a2mlparser.y"
                                                 { yylhs.value.as < a2l::A2mlObject > () = yystack_[2].value.as < a2l::A2mlObject > ();}
#line 1326 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 50: // taggedstruct_definition: tag
#line 264 "D:/projects/a2llib/src/a2mlparser.y"
                             {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::UNKNOWN);
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[0].value.as < std::string > ());
    }
#line 1335 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 51: // taggedstruct_definition: tag member
#line 268 "D:/projects/a2llib/src/a2mlparser.y"
                 {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[0].value.as < a2l::A2mlObject > ();
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[1].value.as < std::string > ());
    }
#line 1344 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 52: // taggedstruct_definition: tag MEM_BEGIN member MEM_END
#line 272 "D:/projects/a2llib/src/a2mlparser.y"
                                   {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[3].value.as < std::string > ());
    }
#line 1353 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 53: // taggedunion_type_name: TAGGED_UNION identifier BLOCK_BEGIN taggedunion_member_list BLOCK_END
#line 277 "D:/projects/a2llib/src/a2mlparser.y"
                                                                                             {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::TAGGED_UNION);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[3].value.as < std::string > ());
        yylhs.value.as < a2l::A2mlObject > ().MemberList( yystack_[1].value.as < a2l::A2mlMemberList > ());
    }
#line 1363 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 54: // taggedunion_type_name: TAGGED_UNION IDENT
#line 282 "D:/projects/a2llib/src/a2mlparser.y"
                         {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::TAGGED_UNION);
        yylhs.value.as < a2l::A2mlObject > ().Ident(yystack_[0].value.as < std::string > ());
    }
#line 1372 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 55: // taggedunion_member_list: taggedunion_member
#line 287 "D:/projects/a2llib/src/a2mlparser.y"
                                            {
        yylhs.value.as < a2l::A2mlMemberList > () = A2mlMemberList();
        yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1381 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 56: // taggedunion_member_list: taggedunion_member_list taggedunion_member
#line 291 "D:/projects/a2llib/src/a2mlparser.y"
                                                 {
        yylhs.value.as < a2l::A2mlMemberList > () = yystack_[1].value.as < a2l::A2mlMemberList > ();
        yylhs.value.as < a2l::A2mlMemberList > ().emplace_back(yystack_[0].value.as < a2l::A2mlObject > ());
    }
#line 1390 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 57: // taggedunion_member: tag DEF_END
#line 296 "D:/projects/a2llib/src/a2mlparser.y"
                                {
        yylhs.value.as < a2l::A2mlObject > () = A2mlObject(A2mlTypeName::UNKNOWN);
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[1].value.as < std::string > ());
    }
#line 1399 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 58: // taggedunion_member: tag member DEF_END
#line 300 "D:/projects/a2llib/src/a2mlparser.y"
                         {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();
        yylhs.value.as < a2l::A2mlObject > ().Tag(yystack_[2].value.as < std::string > ());
    }
#line 1408 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 59: // taggedunion_member: block_definition DEF_END
#line 304 "D:/projects/a2llib/src/a2mlparser.y"
                               {
        yylhs.value.as < a2l::A2mlObject > () = yystack_[1].value.as < a2l::A2mlObject > ();
    }
#line 1416 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 60: // keyword: STRING
#line 308 "D:/projects/a2llib/src/a2mlparser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1422 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 61: // identifier: %empty
#line 310 "D:/projects/a2llib/src/a2mlparser.y"
                   {}
#line 1428 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 62: // identifier: IDENT
#line 311 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1434 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;

  case 63: // tag: STRING
#line 313 "D:/projects/a2llib/src/a2mlparser.y"
            { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1440 "D:/projects/a2llib/src/a2mlparser.cpp"
    break;


#line 1444 "D:/projects/a2llib/src/a2mlparser.cpp"

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
  A2mlParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if A2MLDEBUG || 0
  const char *
  A2mlParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if A2MLDEBUG || 0









  const signed char A2mlParser::yypact_ninf_ = -45;

  const signed char A2mlParser::yytable_ninf_ = -63;

  const short
  A2mlParser::yypact_[] =
  {
       1,     5,     6,    49,   -45,   -16,   -45,   -45,    -2,   -45,
     -45,   -45,   -45,    13,    16,    17,   -45,   -45,   -45,   -45,
     -45,    22,   -45,    32,   -45,   -45,    34,   -45,   -45,   -45,
     -45,   -45,    96,    47,    50,    47,    52,    47,    56,    47,
      58,    53,   -45,   -45,   -45,   165,   -45,   -45,    43,   -45,
      15,    -3,   -45,    61,    80,   -45,    -7,   -45,    75,    73,
      -3,    76,     4,   -45,    79,   119,    84,     3,   -45,   142,
     -45,    86,   -45,   -45,    97,   -45,   165,   -45,    95,    88,
      90,   -45,   -45,   -45,   -45,   165,   -45,   -45,   -45,   -45,
     -45,   102,   113,   -45,   107,   -45,   108,   122,   114,   -45,
     -45,   124,   -45,   -45,   -45,   -45
  };

  const signed char
  A2mlParser::yydefact_[] =
  {
       2,     0,     0,     0,     1,     0,    14,    22,    61,    23,
      15,    17,    16,    61,    61,    61,    24,    18,    19,    20,
      21,     0,     4,     0,     8,     9,     0,    13,    10,    11,
      12,    63,     0,    28,     0,    34,     0,    43,     0,    54,
       0,     0,     5,     6,     7,     0,    40,    25,     0,    35,
       0,     0,     3,     0,    39,    60,     0,    29,    31,     0,
       0,     0,     0,    44,     0,    50,     0,     0,    55,     0,
      26,     0,    27,    30,     0,    33,     0,    36,     0,     0,
       0,    48,    42,    45,    46,     0,    51,    59,    53,    56,
      57,     0,     0,    32,     0,    37,     0,     0,     0,    58,
      41,     0,    49,    47,    52,    38
  };

  const signed char
  A2mlParser::yypgoto_[] =
  {
     -45,   -45,   -45,   111,   -45,    -1,   -45,   -43,   -45,   -45,
      87,   -45,   -45,   -45,   -44,   -45,   -45,   -45,    82,    94,
     -45,   -45,    91,   -45,    59,    -5
  };

  const signed char
  A2mlParser::yydefgoto_[] =
  {
       0,     2,    21,    22,    23,    46,    25,    26,    27,    56,
      57,    28,    59,    77,    47,    54,    29,    62,    63,    64,
      30,    67,    68,    58,    34,    65
  };

  const signed char
  A2mlParser::yytable_[] =
  {
      32,    53,    24,    72,     1,     5,     4,    61,    66,    31,
       3,     5,     5,    88,    82,    78,    33,    79,    55,    61,
      24,    86,    31,     5,    66,    91,    41,    60,    31,    31,
       5,    35,    94,     6,    37,    39,     7,     8,    60,     9,
      31,    98,    10,    11,    12,    43,    69,    44,    13,    14,
      15,    16,    17,    18,    19,    20,   -62,     5,    52,    48,
       6,    49,    69,     7,     8,    50,     9,    51,    55,    10,
      11,    12,    36,    38,    40,    13,    14,    15,    16,    17,
      18,    19,    20,    75,     6,    70,    71,     7,     8,    81,
       9,    74,    84,    10,    11,    12,    76,    87,    92,    13,
      14,    15,    16,    17,    18,    19,    20,     6,    95,    93,
       7,     8,    96,     9,    97,    99,    10,    11,    12,    45,
     100,   102,    13,    14,    15,    16,    17,    18,    19,    20,
       6,   101,    42,     7,     8,   103,     9,   105,   104,    10,
      11,    12,    85,    73,    83,    13,    14,    15,    16,    17,
      18,    19,    20,     6,    80,    90,     7,     8,    89,     9,
       0,     0,    10,    11,    12,     0,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,     6,     0,     0,     7,
       8,     0,     9,     0,     0,    10,    11,    12,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20
  };

  const signed char
  A2mlParser::yycheck_[] =
  {
       5,    45,     3,    10,     3,     8,     0,    50,    51,    25,
       5,     8,     8,    10,    10,    59,    18,    60,    25,    62,
      21,    65,    25,     8,    67,    69,     4,    23,    25,    25,
       8,    18,    76,    11,    18,    18,    14,    15,    23,    17,
      25,    85,    20,    21,    22,    13,    51,    13,    26,    27,
      28,    29,    30,    31,    32,    33,     9,     8,     5,     9,
      11,     9,    67,    14,    15,     9,    17,     9,    25,    20,
      21,    22,    13,    14,    15,    26,    27,    28,    29,    30,
      31,    32,    33,    10,    11,    24,     6,    14,    15,    13,
      17,    16,    13,    20,    21,    22,    23,    13,    12,    26,
      27,    28,    29,    30,    31,    32,    33,    11,    13,    12,
      14,    15,    24,    17,    24,    13,    20,    21,    22,    23,
       7,    13,    26,    27,    28,    29,    30,    31,    32,    33,
      11,    24,    21,    14,    15,    13,    17,    13,    24,    20,
      21,    22,    23,    56,    62,    26,    27,    28,    29,    30,
      31,    32,    33,    11,    60,    13,    14,    15,    67,    17,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33
  };

  const signed char
  A2mlParser::yystos_[] =
  {
       0,     3,    35,     5,     0,     8,    11,    14,    15,    17,
      20,    21,    22,    26,    27,    28,    29,    30,    31,    32,
      33,    36,    37,    38,    39,    40,    41,    42,    45,    50,
      54,    25,    59,    18,    58,    18,    58,    18,    58,    18,
      58,     4,    37,    13,    13,    23,    39,    48,     9,     9,
       9,     9,     5,    48,    49,    25,    43,    44,    57,    46,
      23,    41,    51,    52,    53,    59,    41,    55,    56,    59,
      24,     6,    10,    44,    16,    10,    23,    47,    48,    41,
      53,    13,    10,    52,    13,    23,    48,    13,    10,    56,
      13,    48,    12,    12,    48,    13,    24,    24,    48,    13,
       7,    24,    13,    13,    24,    13
  };

  const signed char
  A2mlParser::yyr1_[] =
  {
       0,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      39,    39,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      57,    58,    58,    59
  };

  const signed char
  A2mlParser::yyr2_[] =
  {
       0,     2,     0,     5,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     5,     2,     1,
       2,     1,     3,     5,     2,     0,     2,     2,     4,     2,
       0,     4,     5,     2,     1,     2,     2,     4,     2,     4,
       1,     2,     4,     5,     2,     1,     2,     2,     3,     2,
       1,     0,     1,     1
  };


#if A2MLDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const A2mlParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "A2ML_BEGIN",
  "A2ML_END", "A2ML", "ARRAY_BEGIN", "ARRAY_END", "BLOCK", "BLOCK_BEGIN",
  "BLOCK_END", "CHAR", "CONSTANT", "DEF_END", "DOUBLE", "ENUM", "EQUAL",
  "FLOAT", "IDENT", "IF_DATA", "INT", "INT64", "LONG", "MEM_BEGIN",
  "MEM_END", "STRING", "STRUCT", "TAGGED_STRUCT", "TAGGED_UNION",
  "TEXT_ARRAY", "UCHAR", "UINT", "UINT64", "ULONG", "$accept",
  "a2ml_block", "declaration_list", "declaration", "type_definition",
  "type_name", "predefined_type_name", "block_definition",
  "enum_type_name", "enumerator_list", "enumerator", "struct_type_name",
  "struct_member_list", "struct_member", "member", "array_specifier",
  "taggedstruct_type_name", "taggedstruct_member_list",
  "taggedstruct_member", "taggedstruct_definition",
  "taggedunion_type_name", "taggedunion_member_list", "taggedunion_member",
  "keyword", "identifier", "tag", YY_NULLPTR
  };
#endif


#if A2MLDEBUG
  const short
  A2mlParser::yyrline_[] =
  {
       0,   100,   100,   101,   105,   109,   114,   115,   117,   119,
     123,   126,   129,   132,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   149,   154,   161,   166,   171,
     185,   200,   204,   209,   214,   219,   220,   225,   228,   232,
     237,   238,   240,   245,   250,   254,   259,   260,   261,   262,
     264,   268,   272,   277,   282,   287,   291,   296,   300,   304,
     308,   310,   311,   313
  };

  void
  A2mlParser::yy_stack_print_ () const
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
  A2mlParser::yy_reduce_print_ (int yyrule) const
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
#endif // A2MLDEBUG

  A2mlParser::symbol_kind_type
  A2mlParser::yytranslate_ (int t) YY_NOEXCEPT
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    // Last valid token kind.
    const int code_max = 288;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/a2mlparser.y"
} // a2l
#line 1892 "D:/projects/a2llib/src/a2mlparser.cpp"

#line 315 "D:/projects/a2llib/src/a2mlparser.y"


void a2l::A2mlParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
