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
#line 17 "D:/projects/a2llib/src/a2lparser.y"

    #include <sstream>
    #include "a2lscanner.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.a2llex

#line 57 "D:/projects/a2llib/src/a2lparser.cpp"


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
#line 131 "D:/projects/a2llib/src/a2lparser.cpp"

  /// Build a parser object.
  A2lParser::A2lParser (a2l::A2lScanner &scanner_yyarg)
#if A2LDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
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

  A2lParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
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
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
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

#line 639 "D:/projects/a2llib/src/a2lparser.cpp"

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









  const short A2lParser::yypact_ninf_ = -838;

  const signed char A2lParser::yytable_ninf_ = -1;

  const short
  A2lParser::yypact_[] =
  {
     113,   207,    70,   201,  -838,  -838,  -838,  -838,   316,  -838,
     -59,  -838,   316,  -838,  -838,    87,  -838,   136,   177,     9,
    -838,  -838,   326,  -838,   188,   197,   126,  -838,  -838,   205,
    -838,    55,  -838,   169,   280,   108,  -838,  -838,  -838,    72,
    -838,  -838,  -838,  -838,  -838,   845,   155,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,   302,   330,   346,   349,
     352,   355,   376,   384,   391,   404,   415,   417,   315,   339,
     425,   429,   431,   442,   443,   444,   445,   446,   450,  -838,
    -838,   452,   455,   456,   464,   465,   466,   467,   469,   471,
     472,   477,   481,  -838,  -838,  -838,   482,   483,   487,   488,
     490,   491,   492,  -838,    69,   316,   316,   498,   500,   501,
     502,   316,   316,  -838,  -838,   503,   507,   815,   285,   985,
     509,   508,   316,   511,   520,   518,   521,    22,    84,   325,
     526,   527,  -838,  -838,  -838,  -838,  -838,  -838,   529,   316,
     316,   530,   316,   316,  -838,   316,    45,    58,   316,   532,
     418,   316,   316,   316,   316,   316,   316,   316,   533,   316,
     535,   537,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,    17,   422,   316,   541,   542,   543,
     544,   324,   545,   316,   546,   547,   548,   549,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,   413,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
     555,   538,  -838,   558,   561,  -838,   563,   424,   377,  -838,
    -838,  -838,  -838,   564,   565,  -838,  -838,  -838,  -838,   571,
    -838,   574,   576,  -838,  -838,   360,  -838,   362,   485,   578,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,   272,   480,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,   316,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,   582,   584,   585,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,   587,  -838,  -838,   589,   590,   592,
     593,   594,   595,   596,   599,   603,   606,   607,  -838,  -838,
    -838,  -838,  -838,   608,   611,   612,   614,   615,   616,   617,
     619,   620,   623,   625,   626,   627,   629,   630,   631,   633,
     634,   635,   636,   637,   643,   644,   645,   646,   650,   652,
     654,   656,   658,   316,   360,    73,   360,   621,    91,  -838,
    -838,  -838,  -838,   660,   115,   360,   441,   360,  -838,   360,
     360,  -838,  -838,  -838,  -838,    78,   360,    81,  -838,   663,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,   666,   451,   360,   316,   316,   667,  -838,   670,
     677,   678,   681,   682,   316,  -838,  -838,  -838,  -838,  -838,
     683,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
     685,   687,   505,   690,  -838,  -838,   691,   360,   494,   510,
    -838,   693,  -838,  -838,  -838,  -838,  -838,    14,   127,   135,
    -838,   497,   695,   696,    49,   661,   700,   701,   324,   316,
     704,   705,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,   707,   151,    60,   360,    79,   708,   657,   715,
    -838,  -838,   717,   628,  -838,  -838,  -838,  -838,   181,  -838,
     192,   216,   290,   301,   347,   369,   373,   374,   382,  -838,
      35,   632,   722,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,   360,
    -838,   316,    39,   723,   726,   727,   728,   730,   732,   734,
     736,   316,  -838,  -838,   360,   360,   737,  -838,  -838,   550,
     742,   324,   360,  -838,  -838,  -838,  -838,   600,   553,  -838,
     748,    11,  -838,  -838,   316,   747,  -838,  -838,  -838,  -838,
     316,  -838,   324,   360,   665,   702,   360,   360,   755,   757,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,   711,   360,  -838,
    -838,  -838,  -838,   712,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,   666,   739,   745,   764,   765,  -838,  -838,  -838,  -838,
      85,   709,   672,   664,   641,   638,   602,   673,   639,   610,
     777,  -838,  -838,   316,   360,   409,  -838,  -838,  -838,   788,
    -838,  -838,  -838,  -838,  -838,   789,  -838,  -838,   360,   360,
     360,   790,  -838,  -838,   324,   360,  -838,  -838,   588,   597,
     792,   795,  -838,  -838,  -838,   360,   800,  -838,  -838,   360,
     798,  -838,   360,   360,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,   779,   801,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,   316,  -838,  -838,   766,
     762,  -838,   324,   805,  -838,   411,   360,  -838,  -838,   316,
     324,  -838,   387,  -838,  -838,  -838,  -838,   360,   743,  -838,
    -838,   360,  -838,   146,  -838,  -838,  -838,   575,  -838,  -838,
      75,  -838,   316,   230,   642,  -838,  -838,  -838,  -838,   624,
     706,  -838,   324,   647,  -838,  -838,   675,    67,   360,   785,
    -838,   421,    -2,   713,   316,   316,  -838,   316,   316,   811,
     816,   821,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,   269,   703,  -838,   316,
    -838,  -838,  -838,   305,   808,   653,   824,   360,   316,   360,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,   799,   640,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,    37,   324,  -838,   340,    10,
     794,   840,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,   754,   849,  -838,  -838,   360,  -838,   720,   851,   855,
     852,   856,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
     857,   864,  -838,  -838,  -838,   390,   394,   680,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,   866,  -838,  -838,   360,
    -838,  -838,  -838,   694,  -838,  -838,  -838,  -838,  -838,   324,
      90,   837,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,   867,  -838,   869,  -838,  -838,  -838,  -838,   360,
    -838,  -838,  -838,   360,  -838,    23,   397,  -838,   831,   324,
     698,   692,  -838,   875,  -838,  -838,   324,  -838,  -838,   398,
    -838,  -838,  -838,   841,   316,   316,  -838,  -838,  -838,  -838,
    -838,   686,  -838,    76,  -838,  -838,   876,  -838,   401,   775,
     402,  -838,  -838,  -838,  -838,   770,  -838,   316,   828,  -838,
     684,  -838,   360,  -838,  -838,   360,  -838,   781,    61,   868,
     897,   898,   360,   360,   360,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,   360,   360,  -838,   282,   316,
     316,   818,  -838,  -838,  -838,  -838
  };

  const short
  A2lParser::yydefact_[] =
  {
       0,     0,     0,     0,     3,   491,   461,   462,     0,     1,
       0,     2,     0,     4,   490,     0,   489,     0,     0,     0,
     303,   304,     0,   301,     0,     0,     0,   302,   170,     0,
     300,     0,   261,     0,     0,     0,   171,   172,   173,     0,
     169,   628,   585,   586,   587,     0,     0,   488,   560,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   275,
     276,   277,   278,   262,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   263,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   452,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   242,   306,     0,     0,     0,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,   455,   456,   453,   457,   458,     0,     0,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   252,
     253,   243,   244,   246,   247,   248,   249,   250,   251,   254,
     255,   256,   257,   258,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,   615,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   356,   357,
     358,   359,   360,   351,   352,   353,   354,   355,   361,   362,
       0,     0,   393,     0,     0,   424,     0,     0,     0,   588,
     440,   438,   439,     0,     0,   486,   451,   625,   627,     0,
      63,     0,     0,   476,   478,   129,   140,     0,     0,     0,
     147,   148,   149,   146,   152,   153,   154,   155,   156,   150,
     151,     0,     0,   484,   600,   162,   163,   161,   165,   166,
     168,   164,   167,   176,     0,   227,   494,   495,   496,   497,
     498,   499,   500,   513,   526,   529,   601,     0,     0,     0,
     241,   492,   522,   524,   525,   538,   463,   464,   465,   541,
     543,   575,   583,   618,     0,   623,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,   549,
     550,   551,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
     484,   436,   484,     0,     0,     0,     0,     0,   111,   120,
     125,   467,   468,   469,   466,     0,     0,     0,     6,     0,
     484,   484,   484,   484,   484,   484,   144,   557,   484,   484,
     484,   159,   158,     0,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,     0,   533,   534,   535,   536,   537,
       0,   559,   570,   571,   572,   573,   574,   576,   578,   579,
     580,   581,   582,   592,   594,   595,   596,   597,   598,   599,
     602,   603,   604,   605,   606,   609,   610,   611,   612,   613,
       0,     0,     0,     0,   394,   395,     0,     0,     0,     0,
     520,     0,   428,   425,   426,   427,   429,     0,     0,   443,
     446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    64,    65,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,     0,     0,   484,   141,   142,   143,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   472,   589,   179,   177,   188,   178,   180,
     181,   182,   183,   184,   185,   186,   187,   189,   190,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   392,   493,     0,     0,     0,   423,   620,     0,
       0,     0,     0,   432,   433,   434,   435,     0,     0,   444,
       0,     0,   450,   487,     0,     0,    62,   514,   531,   540,
       0,   568,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   116,   113,   114,   115,   117,   118,     0,     0,   121,
     122,   123,   477,     0,   126,   127,   479,   128,   527,   481,
     139,   556,     0,     0,     0,     0,     7,    10,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   562,   565,     0,     0,   470,   223,   222,     0,
     506,   507,   508,   509,   510,     0,   553,   376,     0,     0,
       0,     0,   430,   591,     0,     0,   364,   484,     0,     0,
       0,     0,   447,   448,   449,     0,     0,   567,   619,     0,
       0,   110,     0,     0,   519,   616,   119,   528,   124,   482,
       5,   501,   502,     0,     0,    14,    15,   132,   174,   191,
     289,   363,   373,   157,   365,   374,     0,   473,   194,     0,
       0,    79,   220,     0,   511,     0,     0,   397,   411,     0,
       0,   622,     0,   442,   445,   624,   626,     0,     0,    81,
     136,     0,   517,     0,    12,   504,   291,     0,   470,    77,
       0,   471,     0,     0,     0,   377,   378,   379,   383,     0,
       0,   367,     0,     0,    35,   532,     0,     0,     0,     0,
     483,     0,     0,     0,     0,     0,   530,     0,     0,     0,
       0,     0,   197,   200,   208,   195,   218,   196,   198,   199,
     201,   202,   203,   204,   205,   206,   207,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    75,     0,   221,     0,
     484,   484,   375,     0,     0,     0,     0,     0,     0,     0,
     399,   398,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,   415,   412,   413,   414,   416,   417,
     418,   419,   420,   421,   422,     0,     0,   441,     0,     0,
       0,     0,   558,    83,    84,    82,    89,    96,    99,   109,
      85,    86,    87,    88,    90,    91,    92,    93,    94,    95,
      97,    98,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   137,   138,     0,    11,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,   297,   298,   299,
      57,   484,   193,   503,   512,   539,   544,   554,   584,   590,
       0,     0,    76,   219,   470,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,   391,     0,   396,   542,     0,
     577,   617,   410,     0,   368,   369,   370,   371,   372,     0,
       0,     0,    37,    36,    45,    38,    39,    40,    41,    42,
      43,    44,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     0,   484,     0,    80,   518,   135,   555,     0,
     290,   521,   561,     0,   569,     0,     0,   515,     0,   225,
       0,     0,   382,     0,   545,   366,     0,    34,   484,     0,
     484,   516,   564,     0,     0,     0,   607,    58,    59,    60,
      61,     0,    74,     0,   380,   381,     0,   608,     0,     0,
       0,    56,   563,   593,   459,     0,   226,     0,     0,   192,
       0,   224,     0,   133,   460,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    18,    27,    20,    21,
      22,    23,    24,    25,    26,    28,    29,    30,    31,    32,
      33,   474,    16,   505,   523,     0,     0,   566,     0,     0,
       0,     0,   475,   546,   547,   134
  };

  const short
  A2lParser::yypgoto_[] =
  {
    -838,  -838,  -838,  -166,  -838,  -838,  -838,  -838,  -838,  -838,
      62,  -838,  -838,  -838,  -838,  -838,    71,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -739,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,   885,
    -838,  -838,  -838,   746,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,    -3,
    -195,  -162,  -806,  -838,  -838,  -838,  -838,  -838,  -838,  -462,
    -838,  -838,  -838,  -838,  -838,  -464,   771,   773,   776,   778,
     782,   783,   786,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -540,  -793,  -490,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -230,
    -838,  -837,  -519,  -496,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -492,  -838,    63,  -838,    74,  -827,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -796,  -838,  -838,  -838,   -12,
    -838,  -164,  -838,  -731,  -838,  -838,  -728,  -838,  -489,  -487,
    -836,  -838,  -838,  -838,  -838,  -838,  -838,  -838,    82,  -838,
    -838,  -838,  -838,  -838,  -838,  -788,  -838,  -838,  -825,    93,
    -742,   331,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,  -838,
    -838,  -838,  -838,  -838,  -838,  -838,  -838,  -826,  -838,  -486,
      -7,  -838,  -838,  -838,  -838,  -838,  -838,  -838,   791
  };

  const short
  A2lParser::yydefgoto_[] =
  {
       0,     2,     3,   360,   608,   716,   717,   361,   720,   785,
     900,  1107,  1116,    49,   928,  1023,   863,  1055,  1077,    50,
     476,   583,   801,   991,   208,   735,    51,   846,   935,    52,
     593,   690,    53,   594,   699,    54,   596,   704,    55,   485,
     600,   362,   936,  1117,   691,   847,   963,    56,   487,   605,
      57,   166,   363,   376,    58,   167,   377,    20,    31,    36,
     364,    59,   503,   626,   365,   938,    60,   827,   865,   209,
     830,   739,   210,  1083,    61,   137,   182,    62,   138,   211,
      21,    39,    63,   366,   627,   851,   972,    11,    22,    23,
      64,   139,   274,   367,   340,   379,   562,   925,  1014,   368,
     380,    65,   805,   835,   836,   837,    66,   893,   998,    67,
     465,   554,    68,   839,   901,    69,   840,   915,    70,   468,
     563,    71,   567,   663,    72,   147,   341,   669,   152,   670,
     153,   671,   762,   154,    73,   124,   155,   866,   939,     8,
     831,   486,   802,   733,  1138,   479,   480,   355,   823,   502,
     474,    74,    13,     4,   212,   555,   183,   184,   185,   186,
     187,   188,   189,   718,   719,   868,   786,  1118,   282,   283,
     284,   285,   286,   287,   869,   190,   585,   992,   692,   693,
     943,   694,   565,   973,   213,  1120,   214,   215,   191,   601,
     701,   192,   871,   586,   288,   289,   290,   291,   292,   216,
     873,   587,   217,   905,   218,   875,   906,  1123,  1124,   293,
     294,   295,   296,   297,   298,   876,   964,   606,   369,   950,
     299,    75,   976,   633,  1078,   977,   634,  1126,   589,   590,
     978,   300,   301,   302,   303,   304,   219,   305,   909,   306,
     307,   308,   309,   310,   220,   882,    44,    37,   342,   637,
     884,   664,   311,  1079,   312,   313,   314,   315,   316,   317,
     382,   193,   318,   319,   320,   321,   322,  1080,   665,   323,
     324,   325,   326,   327,   328,   329,   696,   911,   221,   591,
     566,   222,   666,   223,   763,   156,   764,   157,    38
  };

  const short
  A2lParser::yytable_[] =
  {
      12,   375,   370,   381,   564,    14,   409,   630,   568,    16,
     569,   631,   584,   629,   635,   759,   636,   638,   659,   948,
     959,   957,   886,   488,   974,   337,   338,  1073,   610,   611,
     612,   613,   614,   615,   870,   488,   616,   617,   618,   628,
     980,  1013,  1006,   907,   921,   737,   903,   918,   357,   358,
     949,   910,   924,   941,   553,   975,  1000,  1003,   956,    33,
     488,   371,   372,   979,   697,   397,  1001,  1005,    34,   675,
       9,   961,   148,   149,   488,    45,    46,   552,  1042,   887,
    1095,   675,   598,   703,    15,   603,   488,    47,   864,   783,
     553,  1027,  1036,    17,   558,   559,   878,  1002,   498,   879,
     999,  1030,  1040,  1038,   958,  1004,   675,   937,   553,   922,
     498,   908,   923,    24,    42,   488,   784,    43,   952,   571,
     675,   572,   158,   159,  1043,     1,   599,   698,   164,   165,
      25,   667,  1031,   619,  1074,  1025,   398,   399,   668,   332,
    1037,   619,   711,    18,   599,   599,   359,   622,  1131,   560,
     849,    48,   623,   850,   684,   685,   350,   351,   373,   353,
     354,   675,   356,   962,    48,   383,   660,   339,   386,   387,
     388,   389,   390,   391,   392,   730,   394,  1075,    48,   604,
      19,    48,    48,   661,   712,   713,  1039,    48,  1059,  1024,
     498,  1076,   738,   401,  1016,    28,   721,  1017,   619,    35,
     411,   686,   687,    29,    10,   981,   688,   714,   715,   662,
       6,     7,    32,   760,     5,   761,     6,     7,  1044,   374,
     722,   561,   619,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    30,
    1121,  1127,   150,    40,   151,   561,   100,   406,   407,   408,
    1122,  1130,  1129,   343,   344,   345,  1141,    41,   194,   195,
     481,   482,   483,   484,   723,   812,   619,   488,    34,   902,
     917,   196,   551,   660,   556,   724,   940,   619,   101,   997,
     582,  1125,   588,   573,  1119,   592,   990,   595,   597,  1128,
     904,   919,   113,   607,   602,     6,     7,   944,   689,    19,
      26,   872,   406,   407,   408,   874,   102,   625,   880,   632,
     881,   885,   639,  1020,  1021,   197,   114,   198,   199,   178,
     945,   725,   103,   619,   946,   104,   942,   953,   105,   954,
     960,   106,   200,   867,   700,   201,   705,   202,   481,   482,
     483,   484,   498,   726,   180,   619,   916,   727,   728,   619,
     619,   504,   107,   679,   178,   576,   729,   488,   619,   897,
     108,   843,   489,   619,  1060,   655,   619,   109,  1061,   859,
     619,  1081,  1089,   619,   619,  1098,  1100,   619,   619,   180,
     110,   577,   799,   800,   833,   834,   203,   890,   891,   578,
     494,   111,   499,   112,   897,   967,   204,   490,   995,   996,
     971,   115,  1028,   702,   859,   116,  1029,   117,  1026,  1034,
     373,  1035,  1041,   932,   574,   575,    48,   860,   118,   119,
     120,   121,   122,   500,   620,   621,   123,   579,   553,   125,
     550,  1015,   126,   127,   580,   971,   754,   205,   553,   491,
     206,   128,   129,   130,   131,   492,   132,   734,   133,   134,
     968,   207,   860,   899,   135,   339,   576,   768,   136,   140,
     141,   861,   749,   750,   142,   143,   576,   144,   145,   146,
     755,   493,   640,   641,   160,   897,   161,   162,   163,   168,
     494,   648,   577,   169,   331,   859,   330,   333,   899,  1056,
     578,   769,   577,   581,   772,   773,   334,   335,   336,   969,
     578,   346,   347,   970,   348,   349,   777,   352,   384,   393,
     385,   395,   495,   396,   464,   400,   971,    48,   402,   403,
     404,   405,   410,   412,   413,   414,   415,    48,   579,   810,
     416,   622,   463,   860,   466,   580,   623,   467,   579,   469,
     472,   473,   798,   470,   471,   580,   680,   475,   852,   853,
     477,  1069,   501,   478,   496,   497,   806,   807,   808,   505,
     506,   507,   553,   811,   508,   509,   510,   624,   511,   512,
     513,   514,   515,   817,   854,   516,  1088,   819,  1090,   517,
     821,   822,   518,   519,   520,   842,   855,   521,   522,   178,
     523,   524,   525,   526,   581,   527,   528,   894,   895,   529,
     557,   530,   531,   532,   581,   533,   534,   535,   736,   536,
     537,   538,   539,   540,   838,   856,   577,   926,   748,   541,
     542,   543,   544,   857,   578,   844,   545,   858,   546,   848,
     547,   862,   548,   877,   549,   855,   888,   570,   178,   859,
     609,   765,   619,   656,   642,   373,   643,   767,   929,   930,
     933,    48,   951,   644,   645,   622,   965,   646,   647,   649,
     623,   650,   579,   651,   856,   652,   653,   654,   672,   580,
     658,   673,   674,   657,   676,   896,   677,   678,   897,   912,
     913,   681,   682,   683,   707,   706,   855,   860,   859,   178,
     576,   624,   708,   553,   709,   710,   861,   931,   732,   740,
     797,  1019,   741,   742,   743,  1009,   744,  1011,   745,   623,
     746,   731,   747,   751,   752,   856,   577,   855,   753,   756,
     178,   757,   758,   766,   578,   771,   896,   898,   581,   897,
     770,   774,  1022,   775,  1033,   776,   860,   779,   778,   859,
     780,   781,   782,   793,   787,   373,   856,   789,   932,   788,
     790,    48,   792,   796,  1108,  1109,   791,   813,   858,   794,
     623,   795,   579,   826,   803,   804,   809,   814,   815,   580,
     859,   816,   899,  1049,   818,   820,   841,   825,   898,   824,
     829,   832,   828,   966,   845,  1110,   622,   860,   987,   170,
     339,   623,   993,   988,  1066,   178,   861,   989,   892,   889,
    1008,   982,  1012,   171,   172,   173,   174,   175,   176,   177,
    1006,   980,  1111,  1045,  1007,   927,  1046,  1064,   860,  1047,
     180,   983,   984,   899,   985,   986,  1048,  1051,   581,   178,
    1050,  1052,  1054,  1053,  1057,   897,  1112,  1113,  1058,  1062,
    1067,  1087,  1063,  1065,  1068,   859,  1070,  1082,    76,   179,
    1085,  1086,  1097,  1091,   180,  1084,   994,  1071,    77,  1099,
    1101,  1072,  1104,  1094,    78,  1010,  1103,  1114,    79,    80,
    1132,    81,    82,  1133,  1134,  1145,   971,    27,   934,   947,
     275,   914,   276,   378,   920,   277,  1032,   278,  1018,  1096,
     883,   279,   280,   860,   695,   281,   339,     0,   955,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,  1115,    83,  1106,    84,     0,     0,    85,     0,     0,
    1135,  1136,  1137,     0,    86,     0,     0,     0,     0,   899,
       0,     0,     0,    87,     0,     0,     0,    88,    89,     0,
       0,     0,     0,  1139,  1140,     0,  1142,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    95,    96,    97,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1092,  1093,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   245,   246,   247,   248,     0,   249,     0,   250,
     251,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1143,  1144,   255,     0,
     256,   257,   258,   259,   260,   261,     0,     0,   262,   263,
     264,   265,   266,     0,     0,   267,   268,   269,   270,   271,
     272,   273
  };

  const short
  A2lParser::yycheck_[] =
  {
       3,   167,   166,   167,   468,     8,   201,   503,   470,    12,
     472,   503,   476,   503,   503,     4,   503,   503,     4,   846,
     846,   846,   828,    25,   851,     3,     4,     4,   490,   491,
     492,   493,   494,   495,   827,    25,   498,   499,   500,   503,
      42,     4,    32,   839,   840,     6,   839,   840,     3,     4,
     846,   839,   840,   846,    17,   851,   893,   893,   846,     4,
      25,     3,     4,   851,     4,    48,   893,   893,    13,    71,
       0,     4,     3,     4,    25,     3,     4,     4,    68,     4,
       4,    71,     4,     4,   143,     4,    25,    15,   827,     4,
      17,   928,   928,     6,     3,     4,   827,   893,   100,   827,
     893,   928,   928,   928,   846,   893,    71,   846,    17,   840,
     100,   839,   840,   104,     6,    25,    31,     9,   846,     4,
      71,     6,   125,   126,   114,    12,    66,    67,   131,   132,
     121,     4,   928,     6,   111,   928,   119,   120,     3,   142,
     928,     6,   604,     7,    66,    66,   101,   110,    87,    58,
       4,   106,   115,     7,     3,     4,   159,   160,   100,   162,
     163,    71,   165,    96,   106,   168,   152,   145,   171,   172,
     173,   174,   175,   176,   177,   140,   179,   154,   106,    98,
       3,   106,   106,   169,     3,     4,   928,   106,   994,   928,
     100,   168,   153,   196,   925,     7,     4,   925,     6,   144,
     203,    50,    51,     6,     3,   207,    55,    26,    27,   195,
       9,    10,     7,   202,     7,   204,     9,    10,   208,   161,
       4,   184,     6,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   143,
    1107,  1107,   203,   104,   205,   184,   121,     8,     9,    10,
    1107,  1107,  1107,   199,   200,   201,     4,     7,     3,     4,
       8,     9,    10,    11,     4,   757,     6,    25,    13,   839,
     840,    16,   464,   152,   466,     4,   846,     6,     6,     4,
     476,  1107,   476,   475,  1107,   477,    47,   479,   480,  1107,
     839,   840,     7,   487,   486,     9,    10,   846,   177,     3,
       4,   827,     8,     9,    10,   827,     6,   503,   827,   503,
     827,   827,   504,     3,     4,    60,     7,    62,    63,    44,
     846,     4,     6,     6,   846,     6,   846,   846,     6,   846,
     846,     6,    77,   827,   594,    80,   596,    82,     8,     9,
      10,    11,   100,     4,    69,     6,   840,     4,     4,     6,
       6,   384,     6,   578,    44,    45,     4,    25,     6,    84,
       6,     4,    30,     6,     4,   557,     6,     6,     4,    94,
       6,     4,     4,     6,     6,     4,     4,     6,     6,    69,
       6,    71,     3,     4,     3,     4,   131,   187,   188,    79,
     148,     6,   150,     6,    84,     4,   141,    65,   890,   891,
     125,     6,   928,   595,    94,     6,   928,     6,   928,   928,
     100,   928,   928,   103,     3,     4,   106,   142,     6,     6,
       6,     6,     6,   181,     3,     4,     6,   117,    17,     7,
     463,   925,     7,     7,   124,   125,   661,   182,    17,   107,
     185,     7,     7,     7,     7,   113,     7,   639,     7,     7,
      59,   196,   142,   178,     7,   145,    45,   682,     7,     7,
       7,   151,   654,   655,     7,     7,    45,     7,     7,     7,
     662,   139,   505,   506,     6,    84,     6,     6,     6,     6,
     148,   514,    71,     6,     6,    94,     7,     6,   178,   981,
      79,   683,    71,   183,   686,   687,     6,     9,     7,   108,
      79,   206,     6,   112,     7,     6,   698,     7,     6,     6,
     122,     6,   180,     6,     6,   123,   125,   106,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   106,   117,   754,
     147,   110,     7,   142,     6,   124,   115,     6,   117,     6,
       6,     6,   734,   149,   197,   124,   579,     6,     3,     4,
       6,  1043,   102,     7,    99,     7,   748,   749,   750,     7,
       6,     6,    17,   755,     7,     6,     6,   146,     6,     6,
       6,     6,     6,   765,    29,     6,  1068,   769,  1070,     6,
     772,   773,     6,     6,     6,   810,    41,     6,     6,    44,
       6,     6,     6,     6,   183,     6,     6,     3,     4,     6,
       9,     6,     6,     6,   183,     6,     6,     6,   641,     6,
       6,     6,     6,     6,   806,    70,    71,   842,   651,     6,
       6,     6,     6,    78,    79,   817,     6,    82,     6,   821,
       6,   827,     6,   827,     6,    41,   830,     7,    44,    94,
       7,   674,     6,   179,     7,   100,     6,   680,     3,     4,
     846,   106,   846,     6,     6,   110,   848,     6,     6,     6,
     115,     6,   117,     6,    70,   190,     6,     6,   201,   124,
       7,     6,     6,   193,    43,    81,     6,     6,    84,     3,
       4,     7,     7,     6,    57,     7,    41,   142,    94,    44,
      45,   146,     7,    17,     7,    97,   151,    52,     6,     6,
     733,   926,     6,     6,     6,   897,     6,   899,     6,   115,
       6,   109,     6,     6,   194,    70,    71,    41,     6,   149,
      44,   198,     4,     6,    79,    53,    81,   133,   183,    84,
      95,     6,   928,     6,   928,    54,   142,    28,    56,    94,
      25,     7,     7,   100,    65,   100,    70,   113,   103,   107,
     139,   106,   180,     6,     3,     4,   148,   199,    82,   150,
     115,   181,   117,   796,     6,     6,     6,   200,     6,   124,
      94,     6,   178,   965,     4,     7,   809,     6,   133,    30,
      48,     6,    46,    28,    71,    34,   110,   142,     7,     4,
     145,   115,   119,     7,  1019,    44,   151,     6,   186,   832,
       6,   118,   192,    18,    19,    20,    21,    22,    23,    24,
      32,    42,    61,    49,   191,   198,     6,  1009,   142,    95,
      69,   854,   855,   178,   857,   858,     7,     6,   183,    44,
     140,     6,     6,    11,     7,    84,    85,    86,     4,   189,
      33,  1066,     6,   179,     7,    94,     7,    46,    33,    64,
     188,     6,     6,    42,    69,   187,   889,  1049,    43,   114,
     120,  1053,   208,   207,    49,   898,    68,   116,    53,    54,
      32,    56,    57,     6,     6,    87,   125,    22,   846,   846,
     139,   840,   139,   167,   840,   139,   928,   139,   925,  1083,
     827,   139,   139,   142,   593,   139,   145,    -1,   846,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1102,  1107,    97,  1105,    99,    -1,    -1,   102,    -1,    -1,
    1112,  1113,  1114,    -1,   109,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,  1135,  1136,    -1,  1138,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,   189,   190,   191,   192,   193,   194,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1074,  1075,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,  1097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1139,  1140,   153,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,   163,   164,
     165,   166,   167,    -1,    -1,   170,   171,   172,   173,   174,
     175,   176
  };

  const short
  A2lParser::yystos_[] =
  {
       0,    12,   210,   211,   362,     7,     9,    10,   348,     0,
       3,   296,   348,   361,   348,   143,   348,     6,     7,     3,
     266,   289,   297,   298,   104,   121,     4,   298,     7,     6,
     143,   267,     7,     4,    13,   144,   268,   456,   497,   290,
     104,     7,     6,     9,   455,     3,     4,    15,   106,   222,
     228,   235,   238,   241,   244,   247,   256,   259,   263,   270,
     275,   283,   286,   291,   299,   310,   315,   318,   321,   324,
     327,   330,   333,   343,   360,   430,    33,    43,    49,    53,
      54,    56,    57,    97,    99,   102,   109,   118,   122,   123,
     147,   186,   189,   190,   191,   192,   193,   194,   197,   206,
     121,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     7,     7,     6,     6,     6,     6,     6,
       6,     6,     6,     6,   344,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   284,   287,   300,
       7,     7,     7,     7,     7,     7,     7,   334,     3,     4,
     203,   205,   337,   339,   342,   345,   494,   496,   348,   348,
       6,     6,     6,     6,   348,   348,   260,   264,     6,     6,
       4,    18,    19,    20,    21,    22,    23,    24,    44,    64,
      69,   162,   285,   365,   366,   367,   368,   369,   370,   371,
     384,   397,   400,   470,     3,     4,    16,    60,    62,    63,
      77,    80,    82,   131,   141,   182,   185,   196,   233,   278,
     281,   288,   363,   393,   395,   396,   408,   411,   413,   445,
     453,   487,   490,   492,   497,     4,    35,    36,    37,    38,
      39,    40,    72,    73,    74,    75,    76,    88,    89,    90,
      91,    92,    93,   105,   126,   127,   128,   129,   130,   132,
     134,   135,   136,   137,   138,   153,   155,   156,   157,   158,
     159,   160,   163,   164,   165,   166,   167,   170,   171,   172,
     173,   174,   175,   176,   301,   365,   366,   367,   368,   369,
     370,   371,   377,   378,   379,   380,   381,   382,   403,   404,
     405,   406,   407,   418,   419,   420,   421,   422,   423,   429,
     440,   441,   442,   443,   444,   446,   448,   449,   450,   451,
     452,   461,   463,   464,   465,   466,   467,   468,   471,   472,
     473,   474,   475,   478,   479,   480,   481,   482,   483,   484,
       7,     6,   348,     6,     6,     9,     7,     3,     4,   145,
     303,   335,   457,   199,   200,   201,   206,     6,     7,     6,
     348,   348,     7,   348,   348,   356,   348,     3,     4,   101,
     212,   216,   250,   261,   269,   273,   292,   302,   308,   427,
     430,     3,     4,   100,   161,   212,   262,   265,   302,   304,
     309,   430,   469,   348,     6,   122,   348,   348,   348,   348,
     348,   348,   348,     6,   348,     6,     6,    48,   119,   120,
     123,   348,     7,     7,     7,     7,     8,     9,    10,   349,
       7,   348,     7,     7,     7,     7,   147,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,     7,     6,   319,     6,     6,   328,     6,
     149,   197,     6,     6,   359,     6,   229,     6,     7,   354,
     355,     8,     9,    10,    11,   248,   350,   257,    25,    30,
      65,   107,   113,   139,   148,   180,    99,     7,   100,   150,
     181,   102,   358,   271,   348,     7,     6,     6,     7,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
     348,   350,     4,    17,   320,   364,   350,     9,     3,     4,
      58,   184,   305,   329,   364,   391,   489,   331,   358,   358,
       7,     4,     6,   350,     3,     4,    45,    71,    79,   117,
     124,   183,   212,   230,   364,   385,   402,   410,   430,   437,
     438,   488,   350,   239,   242,   350,   245,   350,     4,    66,
     249,   398,   350,     4,    98,   258,   426,   430,   213,     7,
     358,   358,   358,   358,   358,   358,   358,   358,   358,     6,
       3,     4,   110,   115,   146,   212,   272,   293,   364,   385,
     402,   410,   430,   432,   435,   437,   438,   458,   488,   350,
     348,   348,     7,     6,     6,     6,     6,     6,   348,     6,
       6,     6,   190,     6,     6,   350,   179,   193,     7,     4,
     152,   169,   195,   332,   460,   477,   491,     4,     3,   336,
     338,   340,   201,     6,     6,    71,    43,     6,     6,   349,
     348,     7,     7,     6,     3,     4,    50,    51,    55,   177,
     240,   253,   387,   388,   390,   460,   485,     4,    67,   243,
     398,   399,   350,     4,   246,   398,     7,    57,     7,     7,
      97,   358,     3,     4,    26,    27,   214,   215,   372,   373,
     217,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     140,   109,     6,   352,   350,   234,   348,     6,   153,   280,
       6,     6,     6,     6,     6,     6,     6,     6,   348,   350,
     350,     6,   194,     6,   349,   350,   149,   198,     4,     4,
     202,   204,   341,   493,   495,   348,     6,   348,   349,   350,
      95,    53,   350,   350,     6,     6,    54,   350,    56,    28,
      25,     7,     7,     4,    31,   218,   375,    65,   107,   113,
     139,   148,   180,   100,   150,   181,     6,   348,   350,     3,
       4,   231,   351,     6,     6,   311,   350,   350,   350,     6,
     349,   350,   358,   199,   200,     6,     6,   350,     4,   350,
       7,   350,   350,   357,    30,     6,   348,   276,    46,    48,
     279,   349,     6,     3,     4,   312,   313,   314,   350,   322,
     325,   348,   349,     4,   350,    71,   236,   254,   350,     4,
       7,   294,     3,     4,    29,    41,    70,    78,    82,    94,
     142,   151,   212,   225,   262,   277,   346,   364,   374,   383,
     384,   401,   402,   409,   410,   414,   424,   430,   432,   435,
     437,   438,   454,   458,   459,   488,   351,     4,   430,   348,
     187,   188,   186,   316,     3,     4,    81,    84,   133,   178,
     219,   323,   383,   384,   401,   412,   415,   424,   435,   447,
     454,   486,     3,     4,   225,   326,   364,   383,   384,   401,
     414,   424,   432,   435,   454,   306,   349,   198,   223,     3,
       4,    52,   103,   212,   219,   237,   251,   262,   274,   347,
     383,   384,   385,   389,   401,   402,   410,   412,   415,   424,
     428,   430,   435,   437,   438,   447,   454,   457,   459,   486,
     488,     4,    96,   255,   425,   350,    28,     4,    59,   108,
     112,   125,   295,   392,   415,   424,   431,   434,   439,   454,
      42,   207,   118,   348,   348,   348,   348,     7,     7,     6,
      47,   232,   386,   119,   348,   358,   358,     4,   317,   384,
     400,   415,   424,   439,   454,   486,    32,   191,     6,   350,
     348,   350,   192,     4,   307,   364,   432,   435,   489,   349,
       3,     4,   212,   224,   262,   384,   385,   400,   402,   410,
     415,   424,   428,   430,   437,   438,   439,   454,   457,   459,
     486,   488,    68,   114,   208,    49,     6,    95,     7,   350,
     140,     6,     6,    11,     6,   226,   358,     7,     4,   351,
       4,     4,   189,     6,   350,   179,   349,    33,     7,   358,
       7,   350,   350,     4,   111,   154,   168,   227,   433,   462,
     476,     4,    46,   282,   187,   188,     6,   349,   358,     4,
     358,    42,   348,   348,   207,     4,   430,     6,     4,   114,
       4,   120,   348,    68,   208,   350,   350,   220,     3,     4,
      34,    61,    85,    86,   116,   212,   221,   252,   376,   384,
     394,   400,   415,   416,   417,   424,   436,   439,   454,   457,
     486,    87,    32,     6,     6,   350,   350,   350,   353,   350,
     350,     4,   350,   348,   348,    87
  };

  const short
  A2lParser::yyr1_[] =
  {
       0,   209,   210,   211,   211,   212,   213,   213,   214,   214,
     214,   215,   216,   217,   217,   218,   219,   220,   220,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   222,   223,   223,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   225,   226,   226,   227,
     227,   227,   228,   229,   229,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   231,   232,   232,   233,   234,   234,
     235,   236,   236,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     238,   239,   239,   240,   240,   240,   240,   240,   240,   241,
     242,   242,   243,   243,   244,   245,   245,   246,   247,   248,
     248,   249,   250,   251,   252,   253,   254,   254,   255,   256,
     257,   257,   258,   258,   259,   260,   260,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   263,
     264,   264,   265,   265,   265,   265,   265,   265,   265,   266,
     267,   267,   268,   268,   269,   270,   271,   271,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   273,   274,   275,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   278,
     279,   279,   280,   280,   281,   282,   282,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   286,   287,   287,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     289,   290,   290,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   292,
     293,   294,   294,   295,   295,   295,   295,   295,   295,   295,
     296,   297,   297,   298,   298,   299,   300,   300,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   302,   303,   304,   305,   306,   306,   307,
     307,   307,   307,   308,   309,   310,   311,   311,   312,   312,
     313,   314,   315,   316,   316,   317,   317,   317,   317,   317,
     317,   317,   318,   319,   319,   320,   321,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     324,   325,   325,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   327,   328,   328,   329,   329,   329,   329,
     330,   331,   331,   332,   332,   332,   333,   334,   334,   335,
     335,   336,   337,   338,   338,   339,   340,   340,   341,   341,
     342,   343,   344,   344,   345,   345,   345,   345,   345,   346,
     347,   348,   348,   349,   349,   349,   350,   350,   350,   350,
     351,   351,   352,   352,   353,   353,   354,   354,   355,   355,
     356,   356,   357,   357,   358,   358,   359,   359,   360,   361,
     362,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497
  };

  const signed char
  A2lParser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     5,     0,     2,     1,     1,
       1,     5,     6,     0,     2,     1,    11,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    15,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     0,     2,     1,
       1,     1,     9,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     0,     1,     7,     0,     2,
      14,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      10,     0,     2,     1,     1,     1,     1,     1,     1,    10,
       0,     2,     1,     1,    10,     0,     2,     1,     9,     0,
       2,     1,     5,     6,     5,     6,     0,     2,     1,     9,
       0,     2,     1,     1,     7,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     2,     7,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     6,
       0,     2,     1,     1,     5,     9,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,    13,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     9,
       0,     2,     1,     1,    13,     0,     2,     6,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     0,     2,     1,     1,     1,     1,     1,     1,     1,
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
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     2,     0,     2,     0,     3,     0,     3,
       0,     4,     0,     2,     0,     2,     0,     3,     1,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     5,     5,     5,     5,
       5,     6,     2,     2,     2,     2,     7,     3,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     5,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     3,     4,     4,     2,     2,
       2,     2,     2,     5,     2,     2,     2,     2,     1,     3,
       1,     2,     2,     2,     3,     2,     2,     3,     2,     2,
       3,     3,     3,     3,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     2,     1,     1,
       2,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     2,     3,     3,     3,     3,     3,     1,     8,     3,
       3,     3,     3,     3,     1,     1,     2,     2,     2,     3,
       2,     3,     3,     2,     2,     2,     2,     2,     2
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
  "VIRTUAL", "VIRTUAL_CHARACTERISTIC", "$accept", "a2l_file",
  "file_version", "annotation", "annotation_attributes",
  "annotation_attribute", "annotation_text", "ar_component",
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
  "variant_coding_attribute", "virtual", "virtual_characteristic",
  "any_uint", "any_int", "any_float", "int_list", "uint_list",
  "float_list", "float_pair_list", "float_string_list", "float_range_list",
  "string_list", "ident_list", "key_value_list", "a2ml", "a2ml_version",
  "asap2_version", "addr_epk", "address_type", "alignment_byte",
  "alignment_float16_ieee", "alignment_float32_ieee",
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
       0,   254,   254,   256,   257,   259,   260,   261,   262,   263,
     264,   266,   268,   269,   270,   271,   273,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   293,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   317,   318,   319,   320,
     321,   322,   324,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   338,   339,   340,   342,   344,   345,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   388,
     389,   390,   391,   392,   394,   395,   396,   397,   399,   401,
     402,   403,   405,   407,   409,   411,   412,   413,   414,   416,
     417,   418,   419,   420,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   436,   437,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   450,
     451,   452,   453,   454,   456,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   475,   477,   479,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   507,
     509,   510,   512,   512,   513,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   582,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     595,   596,   597,   598,   599,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   660,   661,   662,   664,   665,   666,   667,
     668,   669,   670,   672,   673,   675,   676,   677,   678,   679,
     681,   682,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   695,   696,   697,   698,   700,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     716,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   731,   733,   734,   735,   736,   737,   738,
     740,   741,   742,   743,   744,   745,   747,   748,   749,   750,
     751,   753,   755,   756,   757,   759,   760,   761,   762,   763,
     765,   767,   768,   769,   770,   771,   772,   773,   774,   776,
     777,   779,   779,   780,   780,   780,   781,   781,   781,   781,
     783,   784,   786,   787,   789,   790,   792,   793,   795,   796,
     798,   799,   801,   802,   804,   805,   807,   808,   810,   811,
     812,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   907,   908,   909,   910,
     911,   912,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   946,   947,   948,   949
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
#line 1950 "D:/projects/a2llib/src/a2lparser.cpp"

#line 951 "D:/projects/a2llib/src/a2lparser.y"



void a2l::A2lParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Column: " << column
          << ", Near: " << near;
    scanner.LastError(error.str());
}
