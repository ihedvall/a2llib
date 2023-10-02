%top {
    #include <cstdint>
    #include <cctype>

}
%{
    #include "a2mlscanner.h"
    #undef  YY_DECL
    #define YY_DECL int a2l::A2mlScanner::a2mllex(a2l::A2mlParser::value_type* yy_value)
    using token = a2l::A2mlParser::token;
%}

%option prefix="a2ml"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l:A2mlScanner"
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
text_array      ("char[")[0-9]+("]")

%s PRI VERSION TIMESTAMP HOSTNAME APPNAME PROCID MSGID SD SDELEMENT SDPAR SDVALUE MSG
%%
%{
            yylval = yy_value;
%}


"A2ML"           { return token::A2ML; }

"/begin"         { return token::A2ML_BEGIN; }
"/end"           { return token::A2ML_END; }
{text_array}     { return token::TEXT_ARRAY; }

"("              { return token::MEM_BEGIN; }
")*"             { return token::MEM_END; }
") *"            { return token::MEM_END; }

"block"          {
                 //   Push(A2mlTypeName::BLOCK);
                    return token::BLOCK;
                 }
"taggedunion"    {
                 //   Push(A2mlTypeName::TAGGED_UNION);
                    return token::TAGGED_UNION;
                 }
"taggedstruct"   {
                 //   Push(A2mlTypeName::TAGGED_STRUCT);
                    return token::TAGGED_STRUCT;
                 }
"{"              { return token::BLOCK_BEGIN; }
"}"              { return token::BLOCK_END; }

"["              { return token::ARRAY_BEGIN; }
"]"              { return token::ARRAY_END; }
";"              { return token::DEF_END; }
"="              { return token::EQUAL; }
"struct"         {
                 //   Push(A2mlTypeName::STRUCT);
                    return token::STRUCT;
                 }
"char"           { return token::CHAR; }
"int"            { return token::INT; }
"long"           { return token::LONG; }
"int64"          { return token::INT64; }
"uchar"          { return token::UCHAR; }
"uint"           { return token::UINT; }
"uint64"         { return token::UINT64; }
"ulong"          { return token::ULONG; }
"double"         { return token::DOUBLE; }
"float"          { return token::FLOAT; }
"enum"           {
//                    Push(A2mlTypeName::ENUMERATE);
                    return token::ENUM;
                 }



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

{signed_number}  {
                     int64_t temp = 0;
                     try {
                       temp = std::stoll(yytext);
                     } catch (const std::exception& ) {

                     }
                     yylval->emplace(temp);
                     return token::CONSTANT;
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

		yylval->emplace(static_cast<int64_t>(address));
	    return token::CONSTANT;
    }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { } /* Multi line comments */
"//".*                                    { /* Single line comment  */ }
{ws}             {}
.                {}
%%

