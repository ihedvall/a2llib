%top {
    #include <cstdint>
    #include <cctype>

}
%{
    #include "ifdatascanner.h"
    #undef  YY_DECL
    #define YY_DECL int a2l::IfDataScanner::ifdatalex(a2l::IfDataParser::value_type* yy_value)
    using token = a2l::IfDataParser::token;
%}

%option prefix="ifdata"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l:IfDataScanner"
%option yylineno
%option noinput
%option nounput


ws              [ \t\n\v\f\r]+
signed_number   [-+]?[0-9]+
unsigned_number [0-9]+
hexnumber       0x[0-9a-fA-F]+
float_val       [-+]?[0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?
ident           [a-zA-Z_]([_a-zA-Z0-9.-]*)?
string          (\"(\\.|[^\\"])*\")*
            /* \"([^\"\\]|(\\.))*\" */
nl              [\n\r]
keyword         [A-Z_0-9]+


%%
%{
            yylval = yy_value;
%}

"/begin"         { return token::IF_DATA_BEGIN; }
"/end"           { return token::IF_DATA_END; }
"IF_DATA"        { return token::IF_DATA; }
{ident}          {
                   const std::string temp(yytext);
                   if (yylval != nullptr) {
                     yylval->emplace(temp);
                   }
                   return token::IDENT;
                 }

{string}         {
                   const size_t len = strlen(yytext);
                   std::string temp;
                   if (len > 2) {
                     temp = yytext + 1;
                     temp.pop_back();
                   }
                   yylval->emplace(temp);
                   return token::STRING;
                 }

{hexnumber}      {
		uint64_t address = 0;
		for ( size_t index = 0; yytext[ index ] != '\0'; ++index ) {
			if ( index < 2 ) continue;
			const char token = yytext[index];
			switch ( token ) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				address *= 16;
				address += token - '0';
				break;

			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				address *= 16;
				address += token - 'A' + 10;
				break;

			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				address *= 16;
				address += token - 'a' + 10;
				break;

			default:
				break;
			}
		}

		yylval->emplace(address);
	    return token::HEX;
    }
 {unsigned_number}  {
                    uint64_t temp = 0;
                    try {
                      temp = std::stoull(yytext);
                    } catch (const std::exception& ) {

                    }
                    yylval->emplace(temp);
                    return token::UINT;
                  }
 {signed_number}  {
                     int64_t temp = 0;
                     try {
                       temp = std::stoll(yytext);
                     } catch (const std::exception& ) {

                     }
                     yylval->emplace(temp);
                     return token::INT;
                   }
{float_val}     {
                   double temp = 0.0;
                   try {
                     temp = std::stod(yytext);
                   } catch (const std::exception&) {

                   }
                   yylval->emplace<double>(temp);
                   return token::FLOAT;
                 }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { } /* Multi line comments */
"//".*                                    { /* Single line comment  */ }
{ws}             {}
.                {}
%%

