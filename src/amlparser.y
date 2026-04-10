%require "3.2"
%language "c++"


%define api.prefix {aml}
%define api.namespace {a2l}
%define api.parser.class {AmlParser}


%code requires {
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/amlmember.h"
#include "a2l/amldefinition.h"
#include "a2l/amlsection.h"
namespace a2l {
class AmlScanner;
}

}

%parse-param { a2l::AmlScanner &scanner  }


%code  {
    #include <sstream>
    #include "amlscanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.amllex
}

%define api.value.type variant

%token A2ML_BEGIN
%token A2ML_END
%token A2ML
%token ARRAY_BEGIN
%token ARRAY_END
%token BLOCK
%token BLOCK_BEGIN
%token BLOCK_END
%token COMMA
%token CHAR
%token <int64_t> CONSTANT
%token DEF_END
%token DOUBLE
%token ENUM
%token EQUAL
%token <double> FLOAT
%token <std::string> IDENT
%token IF_DATA
%token INCLUDE
%token INT
%token INT64
%token LONG
%token MEM_BEGIN
%token MEM_END
%token <std::string> STRING
%token STRUCT
%token TAGGED_STRUCT
%token TAGGED_UNION
%token TEXT_ARRAY
%token UCHAR
%token UINT
%token UINT64
%token ULONG

%nterm <std::pair<std::string, int64_t>> enumerator
%nterm <int64_t> array
%nterm <a2l::AmlArrayList> array_specifier
%nterm <a2l::AmlEnumerateList> enumerator_list
%nterm <std::string> keyword
%nterm <a2l::AmlMember> predefined_type_name
%nterm<a2l::AmlDataType> data_type
%nterm <std::string> tag
%nterm <std::string> identifier
%nterm <std::string> include_file
%nterm <a2l::AmlMember> type_name
%nterm <a2l::AmlMember> type_definition
%nterm <a2l::AmlMember> block_definition
%nterm <a2l::AmlMember> enum_type_name
%nterm <a2l::AmlMember> struct_type_name
%nterm <a2l::AmlMember> member
%nterm <a2l::AmlMemberList> struct_member_list
%nterm <a2l::AmlMember> struct_member
%nterm <a2l::AmlMember> taggedstruct_type_name
%nterm <a2l::AmlMemberList> taggedstruct_member_list
%nterm <a2l::AmlMember> taggedstruct_member
%nterm <a2l::AmlMember> taggedstruct_definition
%nterm <a2l::AmlMember> taggedunion_type_name
%nterm <a2l::AmlMemberList> taggedunion_member_list
%nterm <a2l::AmlMember> taggedunion_member
%nterm <a2l::AmlDefinition> declaration
%nterm <a2l::AmlDefinitionList> declaration_list

%start aml_section

%%

aml_section:  %empty
    | A2ML_BEGIN A2ML declaration_list A2ML_END A2ML {
        scanner.DefinitionList($3);
    }
    | A2ML_BEGIN A2ML include_file A2ML_END A2ML{
             // Todo: Handle include file
    };

declaration_list: %empty {}
    | declaration {
        $$.emplace_back(std::move($1));
    }
    | declaration_list declaration {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

declaration: type_definition def_end {
        $$.Set($1);
        $$.DefinitionType(AmlDefinitionType::TYPE_DEFINITION);
    }
    | block_definition def_end {
        $$.Set($1);
        $$.DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
    };


type_definition: type_name {
        $$ = std::move($1);
        $$.DefinitionType(AmlDefinitionType::TYPE_DEFINITION);
    };

type_name : predefined_type_name {
        $$ = std::move($1);
        $$.TypeName(AmlTypeName::PREDEFINED);
    }
    | struct_type_name {
        $$ = std::move($1);
        $$.TypeName(AmlTypeName::STRUCT);
    }
    | taggedstruct_type_name {
        $$ = std::move($1);
        $$.TypeName(AmlTypeName::TAGGED_STRUCT);
    }
    | taggedunion_type_name {
        $$ = std::move($1);
        $$.TypeName(AmlTypeName::TAGGED_UNION);
    }
    | enum_type_name  {
        $$ = std::move($1);
        $$.TypeName(AmlTypeName::ENUMERATE);
    };

predefined_type_name: data_type array_specifier {
        $$.TypeName(AmlTypeName::PREDEFINED);
        $$.DataType($1);
        $$.ArrayList($2);
    }
    | MEM_BEGIN data_type array_specifier def_end MEM_END {
          $$.TypeName(AmlTypeName::PREDEFINED);
          $$.DataType($2);
          $$.ArrayList($3);
          $$.VectorType(true);
    };


data_type: CHAR { $$ = AmlDataType::CHAR; }
    | INT { $$ = AmlDataType::INT;}
    | LONG { $$ = AmlDataType::LONG;}
    | INT64 { $$ = AmlDataType::INT64;}
    | UCHAR { $$ = AmlDataType::UCHAR;}
    | UINT { $$ = AmlDataType::UINT;}
    | UINT64 { $$ = AmlDataType::UINT64;}
    | ULONG { $$ = AmlDataType::ULONG;}
    | DOUBLE { $$ = AmlDataType::DOUBLE;}
    | FLOAT { $$ = AmlDataType::FLOAT;}
    | TEXT_ARRAY { $$ = AmlDataType::TEXT_ARRAY;};


block_definition: BLOCK tag member def_end {
        $$ = $3;
        $$.DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
        $$.Tag($2);
    }
    | BLOCK tag MEM_BEGIN member MEM_END {
        $$ = $4;
        $$.DefinitionType(AmlDefinitionType::BLOCK_DEFINITION);
        $$.Tag($2);
        $$.VectorType(true);
    };

enum_type_name : ENUM identifier BLOCK_BEGIN enumerator_list BLOCK_END {
        $$.TypeName(AmlTypeName::ENUMERATE);
        $$.Identity($2);
        $$.EnumerateList($4);
    }
    | ENUM IDENT {
        $$.TypeName(AmlTypeName::ENUMERATE);
        $$.Identity($2);
    };

enumerator_list: enumerator {
       $$.emplace_back(std::move($1));
    }
    | enumerator_list COMMA enumerator {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

enumerator: keyword {
        $$.first = std::move($1);
        $$.second = 0;
    }
    | keyword EQUAL CONSTANT {
        $$.first = std::move($1);
        $$.second = $3;
    };

struct_type_name: STRUCT identifier BLOCK_BEGIN struct_member_list BLOCK_END {
        $$.TypeName(AmlTypeName::STRUCT);
        $$.Identity($2);
        $$.MemberList($4);
    }
    | STRUCT identifier {
        $$.TypeName(AmlTypeName::STRUCT);
        $$.Identity($2);
    };

struct_member_list: %empty {}
    | struct_member { $$.emplace_back(std::move($1)); }
    | struct_member_list struct_member {
        $$ = std::move($1);
        $$.emplace_back($2);
    };

struct_member: member def_end {
        $$ = std::move($1);
    }
    | MEM_BEGIN member MEM_END {
        $$ = std::move($2);
        $$.VectorType(true);
    }
    | block_definition def_end {
        $$ = std::move($1);
    };

member: type_name array_specifier {
        $$ = std::move($1);
        $$.ArrayList($2);
    };

taggedstruct_type_name: TAGGED_STRUCT identifier BLOCK_BEGIN taggedstruct_member_list BLOCK_END {
        $$.TypeName(AmlTypeName::TAGGED_STRUCT);
        $$.Identity($2);
        $$.MemberList($4);
     }
    | TAGGED_STRUCT IDENT {
        $$.TypeName(AmlTypeName::TAGGED_STRUCT);
        $$.Identity($2);
    };

taggedstruct_member_list: %empty {}
    | taggedstruct_member {
       $$.emplace_back(std::move($1));
    }
    | taggedstruct_member_list taggedstruct_member {
       $$ = std::move($1);
       $$.emplace_back(std::move($2));
    };

taggedstruct_member: taggedstruct_definition def_end {
        $$ = std::move($1);
    }
    | MEM_BEGIN taggedstruct_definition MEM_END def_end {
        $$ = std::move($2);
        $$.VectorType(true);
    }
    | block_definition def_end {
        $$ = std::move($1);
    }
    | MEM_BEGIN block_definition  MEM_END def_end {
        $$ = std::move($2);
        $$.VectorType(true);
    };

taggedstruct_definition: tag {
        $$.Tag($1);
    }
    | tag member def_end {
        $$ = std::move($2);
        $$.Tag($1);
    }
    | tag MEM_BEGIN member MEM_END {
        $$ = std::move($3);
        $$.Tag($1);
        $$.VectorType(true);
    };

taggedunion_type_name: TAGGED_UNION identifier BLOCK_BEGIN taggedunion_member_list BLOCK_END {
        $$.TypeName(AmlTypeName::TAGGED_UNION);
        $$.Identity($2);
        $$.MemberList( $4);
    }
    | TAGGED_UNION IDENT {
        $$.TypeName(AmlTypeName::TAGGED_UNION);
        $$.Identity($2);
    };

taggedunion_member_list: %empty {}
    | taggedunion_member {
        $$.emplace_back(std::move($1));
    }
    | taggedunion_member_list taggedunion_member {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

taggedunion_member: tag member def_end {
        $$ = std::move($2);
        $$.Tag(std::move($1));
    }
    | tag def_end {
        $$.Tag($1);
    }
    | block_definition def_end {
        $$ = std::move($1);
    };

array_specifier: %empty {}
    | array { $$.push_back($1); }
    | array_specifier array {
        $$ = std::move($1);
        $$.push_back($2);
    };

array: ARRAY_BEGIN CONSTANT ARRAY_END { $$ = $2; };

keyword : STRING { $$ = std::move($1); };

identifier: %empty {}
    | IDENT { $$ = std::move($1); }

tag: STRING { $$ = std::move($1); };

def_end: %empty {}
       | DEF_END;

include_file: INCLUDE STRING {
    $$ = std::move($2);
    };

%%

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
