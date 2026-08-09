%top {
    #include <cstdint>
    #include <cctype>
    #include <string>

}
%{
    #undef yyFlexLexer
    #define yyFlexLexer labelFlexLexer

    #include "labelscanner.h"
    #include "a2l/a2llogstream.h"
    #include "a2l/a2lhelper.h"

    #undef  YY_DECL
    #define YY_DECL int a2l::LabelScanner::labellex(a2l::LabelParser::value_type* yy_value)
    using token = a2l::LabelParser::token;
    using namespace a2l;

%}

%option prefix="label"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l:LabelScanner"
%option yylineno
%option noinput
%option nounput

nl              \r\n|\r|\n
ws              [ \t\f\v]+
line_text       [^\r\n\[\]]+

%%
%{
    yylval = yy_value;
%}

"[SETTINGS]" {
  return token::SETTINGS;
}

"[RAMCELL]"  {
  return token::RAMCELL;
}

"[LABEL]"    {
  return token::LABEL;
}

"[FUNCTION]" {
  return token::FUNCTION;
}

"[GROUP]"    {
  return token::GROUP;
}

{nl} {
    return token::EOL;
}

{ws}  {}

{line_text}  {
      std::string temp(yytext);
      A2lHelper::Trim(temp);
      auto split_list = A2lHelper::Split(temp,';');
      for (auto& split : split_list) {
        A2lHelper::Trim(split);
      }
      yylval->emplace(split_list);
      return token::LINE_TEXT;
}

<<EOF>> {
  return 0;
}

%%


