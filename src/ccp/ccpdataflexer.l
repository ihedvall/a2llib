%top {
    #include <cstdint>
    #include <cctype>
}
%{
    #include "ccpdatascanner.h"
    #undef  YY_DECL
    #define YY_DECL int a2l::ccp::CcpDataScanner::ccplex(a2l::ccp::CcpDataParser::value_type* yy_value)
    using token = a2l::ccp::CcpDataParser::token;
%}

%option prefix="ccp"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l::ccp::CcpDataScanner"
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


"/begin"         { return token::BLOCK_BEGIN; }
"/end"           { return token::BLOCK_END; }

"ADDRESS_EXTENSION" { return token::ADDRESS_EXTENSION;}
"ADDR_MAPPING"      { return token::ADDR_MAPPING;}

"ALTERNATING"    { return token::ALTERNATING;}
"ASAP1B_CCP"     { return token::ASAP1B_CCP;}
"AUTO_FLASH_BACK" { return token::AUTO_FLASH_BACK;}
"BAUDRATE"  { return token::BAUDRATE;}
"BTL_CYCLES" { return token::BTL_CYCLES;}
"BYTES_ONLY" { return token::BYTES_ONLY;}
"CAN_ID_FIXED"   { return token::CAN_ID_FIXED;}
"CAN_ID_VARIABLE" { return token::CAN_ID_VARIABLE;}
"CAN_PARAM"  { return token::CAN_PARAM;}
"CHECKSUM"       { return token::CHECKSUM;}
"CHECKSUM_CALCULATION" { return token::CHECKSUM_CALCULATION;}
"CHECKSUM_PARAM" { return token::CHECKSUM_PARAM;}
"CONSISTENCY" { return token::CONSISTENCY;}
"DAQ_MODE"       { return token::DAQ_MODE;}
"DEFINED_PAGES"  { return token::DEFINED_PAGES;}
"DEFAULT"        { return token::DEFAULT;}
"DISPLAY_IDENTIFIER" { return token::DISPLAY_IDENTIFIER;}
"DP_BLOB"        { return token::DP_BLOB;}
"EEPROM"         { return token::EEPROM;}
"EVENT_GROUP"    { return token::EVENT_GROUP;}
"EXCLUSIVE"      { return token::EXCLUSIVE;}
"FIRST_PID"   { return token::FIRST_PID;}
"FLASH"         { return token::FLASH;}
"FLASH_BACK"    { return token::FLASH_BACK;}
"IF_DATA"        { return token::IF_DATA;}
"KP_BLOB"   { return token::KP_BLOB;}
"LENGTH"         { return token::LENGTH;}
"OPTIONAL_CMD"    { return token::OPTIONAL_CMD;}
"QP_BLOB"        { return token::QP_BLOB;}
"RAM" { return token::RAM;}
"RAM_INIT_BY_ECU" { return token::RAM_INIT_BY_ECU;}
"RAM_INIT_BY_TOOL" { return token::RAM_INIT_BY_TOOL;}
"RASTER"         { return token::RASTER;}
"REDUCTION_ALLOWED" { return token::REDUCTION_ALLOWED;}
"RESUME_SUPPORTED" { return token::RESUME_SUPPORTED;}
"ROM" { return token::ROM;}
"SAMPLE_POINT"    { return token::SAMPLE_POINT;}
"SAMPLE_RATE"     { return token::SAMPLE_RATE;}
"SEED_KEY" { return token::SEED_KEY;}
"SJW"         { return token::SJW;}
"SOURCE"         { return token::SOURCE;}
"STORE_SUPPORTED" { return token::STORE_SUPPORTED;}
"SYNC_EDGE"       { return token::SYNC_EDGE;}
"TP_BLOB" { return token::TP_BLOB;}


{ident}          {
                   if (yylval != nullptr) {
                     std::string temp(yytext);
                     yylval->emplace<std::string>(temp);
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
                   yylval->emplace<std::string>(temp);
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

		yylval->emplace<uint64_t>(address);
	    return token::UINT;
    }
 {unsigned_number}  {
                    uint64_t temp = 0;
                    try {
                      temp = std::stoull(yytext);
                    } catch (const std::exception& ) {

                    }
                    yylval->emplace<uint64_t>(temp);
                    return token::UINT;
                  }
 {signed_number}  {
                     int64_t temp = 0;
                     try {
                       temp = std::stoll(yytext);
                     } catch (const std::exception& ) {

                     }
                     yylval->emplace<int64_t>(temp);
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

