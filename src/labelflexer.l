%top {
    #include <cstdint>
    #include <cctype>
    #include <string>

}
%{

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
line_text       [^\r\n]+

%%
%{
    yylval = yy_value;
%}

{nl} {
    return token::EOL;
}

{line_text}  {
      std::string temp(yytext);
      A2lHelper::Trim(temp);
      if (temp.empty()) {
        return token::EOL;
      }
      if (temp == "[SETTINGS]") {
        return token::SETTINGS;
      }
      if (temp == "[RAMCELL]") {
        return token::RAMCELL;
      }
      if (temp == "[LABEL]") {
        return token::LABEL;
      }
      if (temp == "[FUNCTION]") {
        return token::FUNCTION;
      }
      if (temp == "[GROUP]") {
        return token::GROUP;
      }
      auto split_list = A2lHelper::Split(temp,';');
      for (auto& split : split_list) {
        A2lHelper::Trim(split);
      }
      yylval->emplace<std::vector<std::string>>(split_list);
      return token::LINE_TEXT;
}

<<EOF>> {
  return 0;
}

%%


