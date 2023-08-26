%top {
    #include <cstdint>
    #include <cctype>

}
%{
    #include "a2lscanner.h"
    #undef  YY_DECL
    #define YY_DECL int a2l::A2lScanner::a2llex(a2l::A2lParser::value_type* yy_value)
    using token = a2l::A2lParser::token;
%}

%option prefix="a2l"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l:A2lScanner"
%option yylineno
%option noinput
%option nounput


ws              [ \t\n\v\f\r]+
signed_number   [-+]?[0-9]+
unsigned_number [0-9]+
hexnumber       0x[0-9a-fA-F]+
float_val       [-+]?[0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?
ident           [a-zA-Z_]([\[\]()/_a-zA-Z0-9.-]*)?
string          (\"(\\.|[^\\"])*\")*
            /* \"([^\"\\]|(\\.))*\" */
nl              [\n\r]
keyword         [A-Z_0-9]+
a2l_include     ("/include")

%s PRI VERSION TIMESTAMP HOSTNAME APPNAME PROCID MSGID SD SDELEMENT SDPAR SDVALUE MSG
%%
%{
            yylval = yy_value;
%}


"ASAP2_VERSION"   { return token::ASAP2_VERSION; }
"A2ML_VERSION"    { return token::A2ML_VERSION;  }
"ADDR_EPK"        { return token::ADDR_EPK;  }
"ADDRESS_TYPE"    { return token::ADDRESS_TYPE; }
"ALIGNMENT_BYTE"  { return token::ALIGNMENT_BYTE; }
"ALIGNMENT_FLOAT16_IEEE"  { return token::ALIGNMENT_FLOAT16_IEEE; }
"ALIGNMENT_FLOAT32_IEEE"  { return token::ALIGNMENT_FLOAT32_IEEE; }
"ALIGNMENT_FLOAT64_IEEE"  { return token::ALIGNMENT_FLOAT64_IEEE; }
"ALIGNMENT_INT64"  { return token::ALIGNMENT_INT64; }
"ALIGNMENT_LONG"  { return token::ALIGNMENT_LONG; }
"ALIGNMENT_WORD"  { return token::ALIGNMENT_WORD; }
"ANNOTATION"      { return token::ANNOTATION; }
"ANNOTATION_LABEL"    { return token::ANNOTATION_LABEL; }
"ANNOTATION_ORIGIN"    { return token::ANNOTATION_ORIGIN; }
"ANNOTATION_TEXT"    { return token::ANNOTATION_TEXT; }
"ARRAY_SIZE"      { return token::ARRAY_SIZE; }
"AR_COMPONENT"    { return token::AR_COMPONENT; }
"AR_PROTOTYPE_OF"    { return token::AR_PROTOTYPE_OF; }
"AXIS_DESCR"      { return token::AXIS_DESCR; }
"AXIS_PTS"      { return token::AXIS_PTS; }
"AXIS_PTS_REF"    { return token::AXIS_PTS_REF; }
"AXIS_PTS_X"      { return token::AXIS_PTS_X; }
"AXIS_PTS_Y"      { return token::AXIS_PTS_Y; }
"AXIS_PTS_Z"      { return token::AXIS_PTS_Z; }
"AXIS_PTS_4"      { return token::AXIS_PTS_4; }
"AXIS_PTS_5"      { return token::AXIS_PTS_5; }
"AXIS_RESCALE_X"  { return token::AXIS_RESCALE_X; }
"BIT_MASK"        { return token::BIT_MASK; }
"BIT_OPERATION"   { return token::BIT_OPERATION; }
"BLOB"            { return token::BLOB; }
"BYTE_ORDER"      { return token::BYTE_ORDER; }
"CALIBRATION_ACCESS" { return token::CALIBRATION_ACCESS; }
"CALIBRATION_HANDLE" { return token::CALIBRATION_HANDLE; }
"CALIBRATION_HANDLE_TEXT" { return token::CALIBRATION_HANDLE_TEXT; }
"CALIBRATION_METHOD" { return token::CALIBRATION_METHOD; }
"CHARACTERISTIC"  { return token::CHARACTERISTIC; }
"COEFFS"          { return token::COEFFS; }
"COEFFS_LINEAR"   { return token::COEFFS_LINEAR; }
"COMPARISON_QUANTITY"   { return token::COMPARISON_QUANTITY; }
"COMPU_METHOD"    { return token::COMPU_METHOD; }
"COMPU_TAB"       { return token::COMPU_TAB; }
"COMPU_TAB_REF"   { return token::COMPU_TAB_REF; }
"COMPU_VTAB"      { return token::COMPU_VTAB; }
"COMPU_VTAB_RANGE"  { return token::COMPU_VTAB_RANGE; }
"CONSISTENT_EXCHANGE" { return token::CONSISTENT_EXCHANGE; }
"CONVERSION"      { return token::CONVERSION; }
"CPU_TYPE"        { return token::CPU_TYPE; }
"CURVE_AXIS_REF"      { return token::CURVE_AXIS_REF; }
"CUSTOMER"        { return token::CUSTOMER; }
"CUSTOMER_NO"     { return token::CUSTOMER_NO; }
"DATA_SIZE"       { return token::DATA_SIZE; }
"DEF_CHARACTERISTIC" { return token::DEF_CHARACTERISTIC; }
"DEFAULT_VALUE"   { return token::DEFAULT_VALUE; }
"DEFAULT_VALUE_NUMERIC"   { return token::DEFAULT_VALUE_NUMERIC; }
"DEPENDENT_CHARACTERISTIC"   { return token::DEPENDENT_CHARACTERISTIC; }
"DEPOSIT"         { return token::DEPOSIT; }
"DISCRETE"        { return token::DISCRETE; }
"DISPLAY_IDENTIFIER"   { return token::DISPLAY_IDENTIFIER; }
"DIST_OP_X"       { return token::DIST_OP_X; }
"DIST_OP_Y"       { return token::DIST_OP_Y; }
"DIST_OP_Z"       { return token::DIST_OP_Z; }
"DIST_OP_4"       { return token::DIST_OP_4; }
"DIST_OP_5"       { return token::DIST_OP_5; }
"ECU"             { return token::ECU; }
"ECU_ADDRESS"     { return token::ECU_ADDRESS; }
"ECU_ADDRESS_EXTENSION"   { return token::ECU_ADDRESS_EXTENSION; }
"ECU_CALIBRATION_OFFSET"  { return token::ECU_CALIBRATION_OFFSET; }
"ENCODING"        { return token::ENCODING; }
"EPK"             { return token::EPK; }
"ERROR_MASK"      { return token::ERROR_MASK; }
"EXTENDED_LIMITS" { return token::EXTENDED_LIMITS; }
"FIX_AXIS_PAR"    { return token::FIX_AXIS_PAR; }
"FIX_AXIS_PAR_DIST"  { return token::FIX_AXIS_PAR_DIST; }
"FIX_AXIS_PAR_LIST"  { return token::FIX_AXIS_PAR_LIST; }
"FIX_NO_AXIS_PTS_X"  { return token::FIX_NO_AXIS_PTS_X; }
"FIX_NO_AXIS_PTS_Y"  { return token::FIX_NO_AXIS_PTS_Y; }
"FIX_NO_AXIS_PTS_Z"  { return token::FIX_NO_AXIS_PTS_Z; }
"FIX_NO_AXIS_PTS_4"  { return token::FIX_NO_AXIS_PTS_4; }
"FIX_NO_AXIS_PTS_5"  { return token::FIX_NO_AXIS_PTS_5; }
"FNC_VALUES"      { return token::FNC_VALUES; }
"FORMAT"          { return token::FORMAT; }
"FORMULA"         { return token::FORMULA; }
"FORMULA_INV"     { return token::FORMULA_INV; }
"FRAME"           { return token::FRAME; }
"FRAME_MEASUREMENT"     { return token::FRAME_MEASUREMENT; }
"FUNCTION"        { return token::FUNCTION; }
"FUNCTION_LIST"   { return token::FUNCTION_LIST; }
"FUNCTION_VERSION"   { return token::FUNCTION_VERSION; }
"GROUP"           { return token::GROUP; }
"GUARD_RAILS"     { return token::GUARD_RAILS; }
"HEADER"          { return token::HEADER; }
"IDENTIFICATION"  { return token::IDENTIFICATION; }
"IN_MEASUREMENT"  { return token::IN_MEASUREMENT; }
"INPUT_QUANTITY"  { return token::INPUT_QUANTITY; }
"INSTANCE"        { return token::INSTANCE; }
"LAYOUT"          { return token::LAYOUT; }
"LEFT_SHIFT"      { return token::LEFT_SHIFT; }
"LIMITS"          { return token::LIMITS; }
"LOC_MEASUREMENT" { return token::LOC_MEASUREMENT; }
"MAP_LIST"        { return token::MAP_LIST; }
"MATRIX_DIM"      { return token::MATRIX_DIM; }
"MAX_GRAD"        { return token::MAX_GRAD; }
"MAX_REFRESH"     { return token::MAX_REFRESH; }
"MEASUREMENT"     { return token::MEASUREMENT; }
"MEMORY_LAYOUT"   { return token::MEMORY_LAYOUT; }
"MEMORY_SEGMENT"  { return token::MEMORY_SEGMENT; }
"MOD_COMMON"      { return token::MOD_COMMON;  }
"MOD_PAR"         { return token::MOD_PAR;  }
"MODEL_LINK"      { return token::MODEL_LINK; }
"MODULE"          { return token::MODULE;  }
"MONOTONY"        { return token::MONOTONY;  }
"NO_AXIS_PTS_X"   { return token::NO_AXIS_PTS_X; }
"NO_AXIS_PTS_Y"   { return token::NO_AXIS_PTS_Y; }
"NO_AXIS_PTS_Z"   { return token::NO_AXIS_PTS_Z; }
"NO_AXIS_PTS_4"   { return token::NO_AXIS_PTS_4; }
"NO_AXIS_PTS_5"   { return token::NO_AXIS_PTS_5; }
"NO_OF_INTERFACES" { return token::NO_OF_INTERFACES; }
"NO_RESCALE_X"    { return token::NO_RESCALE_X; }
"NUMBER"          { return token::NUMBER; }
"OFFSET_X"        { return token::OFFSET_X; }
"OFFSET_Y"        { return token::OFFSET_Y; }
"OFFSET_Z"        { return token::OFFSET_Z; }
"OFFSET_4"        { return token::OFFSET_4; }
"OFFSET_5"        { return token::OFFSET_5; }
"OUT_MEASUREMENT" { return token::OUT_MEASUREMENT; }
"OVERWRITE"       { return token::OVERWRITE; }
"PHONE_NO"        { return token::PHONE_NO; }
"PHYS_UNIT"       { return token::PHYS_UNIT; }
"PROJECT"         { return token::PROJECT; }
"PROJECT_NO"      { return token::PROJECT_NO; }
"READ_ONLY"       { return token::READ_ONLY; }
"READ_WRITE"      { return token::READ_WRITE; }
"RECORD_LAYOUT"   { return token::RECORD_LAYOUT; }
"REF_CHARACTERISTIC" { return token::REF_CHARACTERISTIC; }
"REF_GROUP"       { return token::REF_GROUP; }
"REF_MEASUREMENT" { return token::REF_MEASUREMENT; }
"REF_MEMORY_SEGMENT"  { return token::REF_MEMORY_SEGMENT; }
"REF_UNIT"        { return token::REF_UNIT; }
"RESERVED"        { return token::RESERVED; }
"RIGHT_SHIFT"     { return token::RIGHT_SHIFT; }
"RIP_ADDR_W"      { return token::RIP_ADDR_W; }
"RIP_ADDR_X"      { return token::RIP_ADDR_X; }
"RIP_ADDR_Y"      { return token::RIP_ADDR_Y; }
"RIP_ADDR_Z"      { return token::RIP_ADDR_Z; }
"RIP_ADDR_4"      { return token::RIP_ADDR_4; }
"RIP_ADDR_5"      { return token::RIP_ADDR_5; }
"ROOT"            { return token::ROOT; }
"S_REC_LAYOUT"    { return token::S_REC_LAYOUT; } /* Deprecated */
"SHIFT_OP_X"      { return token::SHIFT_OP_X; }
"SHIFT_OP_Y"      { return token::SHIFT_OP_Y; }
"SHIFT_OP_Z"      { return token::SHIFT_OP_Z; }
"SHIFT_OP_4"      { return token::SHIFT_OP_4; }
"SHIFT_OP_5"      { return token::SHIFT_OP_5; }
"SIGN_EXTEND"     { return token::SIGN_EXTEND; }
"SI_EXPONENTS"    { return token::SI_EXPONENTS; }
"SRC_ADDR_X"      { return token::SRC_ADDR_X; }
"SRC_ADDR_Y"      { return token::SRC_ADDR_Y; }
"SRC_ADDR_Z"      { return token::SRC_ADDR_Z; }
"SRC_ADDR_4"      { return token::SRC_ADDR_4; }
"SRC_ADDR_5"      { return token::SRC_ADDR_5; }
"STATIC_ADDRESS_OFFSETS"   { return token::STATIC_ADDRESS_OFFSETS; }
"STATIC_RECORD_LAYOUT"   { return token::STATIC_RECORD_LAYOUT; }
"STATUS_STRING_REF"   { return token::STATUS_STRING_REF; }
"STEP_SIZE"       { return token::STEP_SIZE; }
"STRUCTURE_COMPONENT"   { return token::STRUCTURE_COMPONENT; }
"SUB_FUNCTION"    { return token::SUB_FUNCTION; }
"SUB_GROUP"       { return token::SUB_GROUP; }
"SUPPLIER"        { return token::SUPPLIER; }
"SYMBOL_LINK"     { return token::SYMBOL_LINK; }
"SYMBOL_TYPE_LINK"   { return token::SYMBOL_TYPE_LINK; }
"SYSTEM_CONSTANT" { return token::SYSTEM_CONSTANT; }
"TRANSFORMER"     { return token::TRANSFORMER; }
"TRANSFORMER_IN_OBJECTS"   { return token::TRANSFORMER_IN_OBJECTS; }
"TRANSFORMER_OUT_OBJECTS"   { return token::TRANSFORMER_OUT_OBJECTS; }
"TYPEDEF_AXIS"    { return token::TYPEDEF_AXIS; }
"TYPEDEF_BLOB"    { return token::TYPEDEF_BLOB; }
"TYPEDEF_CHARACTERISTIC"    { return token::TYPEDEF_CHARACTERISTIC; }
"TYPEDEF_MEASUREMENT"    { return token::TYPEDEF_MEASUREMENT; }
"TYPEDEF_STRUCTURE"    { return token::TYPEDEF_STRUCTURE; }
"UNIT"            { return token::UNIT; }
"UNIT_CONVERSION" { return token::UNIT_CONVERSION; }
"USER"            { return token::USER; }
"USER_RIGHTS"     { return token::USER_RIGHTS; }
"VAR_ADDRESS"     { return token::VAR_ADDRESS; }
"VAR_CHARACTERISTIC"   { return token::VAR_CHARACTERISTIC; }
"VAR_CRITERION"   { return token::VAR_CRITERION; }
"VAR_FORBIDDEN_COMB"   { return token::VAR_FORBIDDEN_COMB; }
"VAR_MEASUREMENT" { return token::VAR_MEASUREMENT; }
"VAR_NAMING"      { return token::VAR_NAMING; }
"VAR_SELECTION_CHARACTERISTIC"   { return token::VAR_SELECTION_CHARACTERISTIC; }
"VAR_SEPARATOR"   { return token::VAR_SEPARATOR; }
"VARIANT_CODING"  { return token::VARIANT_CODING; }
"VERSION"         { return token::A2L_VERSION; }
"VIRTUAL"         { return token::VIRTUAL; }
"VIRTUAL_CHARACTERISTIC" { return token::VIRTUAL_CHARACTERISTIC; }

"/begin"{ws}"A2ML"  {
                        // Read in the format specification
                        if (yylval != nullptr) {
                            yylval->emplace(ReadA2ML());
                        }
                        return token::A2ML;
                     }

"/begin"{ws}"IF_DATA"  {
                        // Read in the if_data string
                        if (yylval != nullptr) {
                            yylval->emplace(ReadIfData());
                        }
                        return token::IF_DATA;
                       }
"IF_DATA"{ws}"{"  {
                 // Read in the if_data string until end of line
                 if(yylval != nullptr ) {
                    yylval->emplace(ReadIfDataMultiLine());
                 }
                 return token::IF_DATA;
            }
"IF_DATA"  {
                  // Read in the if_data string until end of line
                  if (yylval != nullptr) {
                    yylval->emplace(ReadIfDataSingleLine());
                  }
                  return token::IF_DATA;
             }
"FUNCTION"{ws}"{" { SkipUntil('}'); }

"/begin"         { return token::A2L_BEGIN; }
"/end"           { return token::A2L_END; }

a2l_include      { return token::A2L_INCLUDE; }



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


