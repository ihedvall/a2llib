%require "3.2"
%language "c++"


%define api.prefix {a2ml}
%define api.namespace {a2l}
%define api.parser.class {A2mlParser}


%code requires {
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/a2mlobject.h"

namespace a2l {
class A2mlScanner;
}

}

%parse-param { a2l::A2mlScanner &scanner  }


%code  {
    #include <sstream>
    #include "a2mlscanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.a2mllex
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
%token CHAR
%token <int64_t> CONSTANT
%token DEF_END
%token DOUBLE
%token ENUM
%token EQUAL
%token <double> FLOAT
%token <std::string> IDENT
%token IF_DATA
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

%nterm <std::pair<int64_t, std::string>> enumerator
%nterm <a2l::A2mlEnumerateList> enumerator_list
%nterm <std::string> identifier
%nterm <std::string> keyword
%nterm <a2l::A2mlDataType> predefined_type_name
%nterm <std::string> tag
%nterm <a2l::A2mlObject> type_name
%nterm <a2l::A2mlObject> type_definition
%nterm <a2l::A2mlObject> block_definition
%nterm <a2l::A2mlObject> enum_type_name
%nterm <a2l::A2mlObject> struct_type_name
%nterm <a2l::A2mlObject> member
%nterm <a2l::A2mlMemberList> struct_member_list
%nterm <a2l::A2mlObject> struct_member
%nterm <a2l::A2mlObject> taggedstruct_type_name
%nterm <a2l::A2mlMemberList> taggedstruct_member_list
%nterm <a2l::A2mlObject> taggedstruct_member
%nterm <a2l::A2mlObject> taggedstruct_definition
%nterm <a2l::A2mlObject> taggedunion_type_name
%nterm <a2l::A2mlMemberList> taggedunion_member_list
%nterm <a2l::A2mlObject> taggedunion_member
%nterm <a2l::A2mlObject> declaration
%nterm <a2l::A2mlMemberList> declaration_list

%start a2ml_block

%%

a2ml_block:  %empty
    | A2ML_BEGIN A2ML declaration_list A2ML_END A2ML {
        scanner.BlockList($3);
    };

declaration_list: declaration {
        $$ = A2mlMemberList();
        $$.emplace_back($1);
    }
    | declaration_list declaration {
        $$ = $1;
        $$.emplace_back($2);
    };

declaration: type_definition DEF_END { $$ = $1; }
    | block_definition DEF_END {  $$ = $1; };

type_definition: type_name { $$ = $1;};

type_name : predefined_type_name {
        $$ = A2mlObject(A2mlTypeName::PREDEFINED);
        $$.DataType($1);
    }
    | struct_type_name {
        $$ = $1;
    }
    | taggedstruct_type_name {
        $$ = $1;
    }
    | taggedunion_type_name {
        $$ = $1;
    }
    | enum_type_name  {
        $$ = $1;
    };

predefined_type_name: CHAR { $$ = A2mlDataType::CHAR;}
    | INT { $$ = A2mlDataType::INT;}
    | LONG { $$ = A2mlDataType::LONG;}
    | INT64 { $$ = A2mlDataType::INT64;}
    | UCHAR { $$ = A2mlDataType::UCHAR;}
    | UINT { $$ = A2mlDataType::UINT;}
    | UINT64 { $$ = A2mlDataType::UINT64;}
    | ULONG { $$ = A2mlDataType::ULONG;}
    | DOUBLE { $$ = A2mlDataType::DOUBLE;}
    | FLOAT { $$ = A2mlDataType::FLOAT;}
    | TEXT_ARRAY { $$ = A2mlDataType::TEXT_ARRAY;};


block_definition: BLOCK tag member {
        $$ = A2mlObject(A2mlTypeName::BLOCK);
        $$.Tag($2);
        $$.MemberList().emplace_back($3);
    }
    | BLOCK tag MEM_BEGIN member MEM_END {
        $$ = A2mlObject(A2mlTypeName::BLOCK);
        $$.Tag($2);
        $$.MemberList().emplace_back($4);
    };


enum_type_name : ENUM identifier BLOCK_BEGIN enumerator_list BLOCK_END {
        $$ = A2mlObject(A2mlTypeName::ENUMERATE);
        $$.Ident($2);
        $$.EnumerateList($4);
    }
    | ENUM IDENT {
        $$ = A2mlObject(A2mlTypeName::ENUMERATE);
        $$.Ident($2);
    };

enumerator_list: enumerator {
        A2mlEnumerateList list;
        auto& enumerator = $1;
        const auto itr = list.find(enumerator.first);
        if (itr == list.cend() ) {
            list.emplace(enumerator.first, enumerator.second);
        } else {
            // Change key
            auto key = list.rbegin()->first;
            ++key;
            list.emplace(key, enumerator.second);
        }
        $$ = list;
    }
    | enumerator_list enumerator {
        auto& list = $1;
        auto& enumerator = $2;
        const auto itr = list.find(enumerator.first);
        if (itr == list.cend() ) {
            list.emplace(enumerator.first, enumerator.second);
        } else {
            // Change key
            auto key = list.rbegin()->first;
            ++key;
            list.emplace(key, enumerator.second);
        }
        $$ = list;
    };

enumerator: keyword {
        $$.first = 0;
        $$.second = $1;
    }
    | keyword EQUAL CONSTANT {
        $$.first = $3;
        $$.second = $1;
    };

struct_type_name: STRUCT identifier BLOCK_BEGIN struct_member_list BLOCK_END {
        $$ = A2mlObject(A2mlTypeName::STRUCT);
        $$.Ident($2);
        $$.MemberList($4);
    }
    | STRUCT IDENT {
        $$ = A2mlObject(A2mlTypeName::STRUCT);
        $$.Ident($2);
    };

struct_member_list: %empty {}
    | struct_member_list struct_member {
        $$ = $1;
        $$.emplace_back($2);
    };

struct_member: member DEF_END {
        $$ = $1;
    }
    | MEM_BEGIN member MEM_END DEF_END {
        $$ = $2;
    };

member: type_name array_specifier {
    $$ = $1;
    // Todo Array specifier
};

array_specifier: %empty
    | array_specifier ARRAY_BEGIN CONSTANT ARRAY_END;

taggedstruct_type_name: TAGGED_STRUCT identifier BLOCK_BEGIN taggedstruct_member_list BLOCK_END {
        $$ = A2mlObject(A2mlTypeName::TAGGED_STRUCT);
        $$.Ident($2);
        $$.MemberList($4);
    }
    | TAGGED_STRUCT IDENT {
        $$ = A2mlObject(A2mlTypeName::TAGGED_STRUCT);
        $$.Ident($2);
    };

taggedstruct_member_list: taggedstruct_member {
       $$ = A2mlMemberList();
       $$.emplace_back($1);
    }
    | taggedstruct_member_list taggedstruct_member {
       $$ = $1;
       $$.emplace_back($2);
    };

taggedstruct_member: taggedstruct_definition DEF_END { $$ = $1; }
    | MEM_BEGIN taggedstruct_definition MEM_END DEF_END { $$ = $2; }
    | block_definition DEF_END {$$ = $1;}
    | MEM_BEGIN block_definition MEM_END DEF_END { $$ = $2;};

taggedstruct_definition: tag {
        $$ = A2mlObject(A2mlTypeName::UNKNOWN);
        $$.Tag($1);
    }
    | tag member {
        $$ = $2;
        $$.Tag($1);
    }
    | tag MEM_BEGIN member MEM_END {
        $$ = $3;
        $$.Tag($1);
    };

taggedunion_type_name: TAGGED_UNION identifier BLOCK_BEGIN taggedunion_member_list BLOCK_END {
        $$ = A2mlObject(A2mlTypeName::TAGGED_UNION);
        $$.Ident($2);
        $$.MemberList( $4);
    }
    | TAGGED_UNION IDENT {
        $$ = A2mlObject(A2mlTypeName::TAGGED_UNION);
        $$.Ident($2);
    };

taggedunion_member_list: taggedunion_member {
        $$ = A2mlMemberList();
        $$.emplace_back($1);
    }
    | taggedunion_member_list taggedunion_member {
        $$ = $1;
        $$.emplace_back($2);
    };

taggedunion_member: tag DEF_END {
        $$ = A2mlObject(A2mlTypeName::UNKNOWN);
        $$.Tag($1);
    }
    | tag member DEF_END {
        $$ = $2;
        $$.Tag($1);
    }
    | block_definition DEF_END {
        $$ = $1;
    };

keyword : STRING { $$ = $1; };

identifier: %empty {}
    | IDENT { $$ = $1; };

tag: STRING { $$ = $1; };

%%

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
