%require "3.2"
%language "c++"


%define api.prefix {ifdata}
%define api.namespace {a2l}
%define api.parser.class {IfDataParser}


%code requires {
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/ifdataitem.h"

namespace a2l {
class IfDataScanner;
}

}

%parse-param { a2l::IfDataScanner &scanner  }


%code  {
    #include <sstream>
    #include "ifdatascanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.ifdatalex
}

%define api.value.type variant

%token IF_DATA_BEGIN
%token IF_DATA_END
%token <uint64_t> UINT
%token <uint64_t> HEX
%token <int64_t>  INT
%token <double>   FLOAT
%token <std::string> IDENT
%token IF_DATA
%token <std::string> STRING

%nterm <std::string> protocol
%nterm <std::vector<a2l::IfDataItem>> block_data_list
%nterm <a2l::IfDataItem> block_data
%nterm <std::string> item_value
%nterm <std::string> block_name
%nterm <std::vector<a2l::IfDataItem>> item_list

%start if_data_block

%%

if_data_block:  %empty
    | IF_DATA_BEGIN IF_DATA protocol block_data_list IF_DATA_END IF_DATA {
        scanner.Protocol($3);
        scanner.ItemList($4);
    };

protocol: IDENT;

block_data_list: %empty {}
    | block_data_list block_data {
        $$ = $1;
        $$.emplace_back($2);
    }
    | block_data_list item_value {
        $$ = $1;
        IfDataItem item;
        item.Value = $2;
        $$.emplace_back($2);
    };

block_data: IF_DATA_BEGIN block_name item_list IF_DATA_END block_name {
    IfDataItem block;
    block.BlockName = $2;
    block.ItemList = $3;
    $$ = block;
};

block_name: IDENT { $$ = $1; };

item_list: %empty {}
    | item_list block_data {
        $$ = $1;
        $$.emplace_back($2);
    }
    | item_list item_value {
        $$ = $1;
        IfDataItem item;
        item.Value = $2;
        $$.emplace_back($2);
    };

item_value: IDENT { $$ = $1; }
    | STRING { $$ = $1; }
    | HEX { $$ = std::to_string($1); }
    | UINT { $$ = std::to_string($1); }
    | INT { $$ = std::to_string($1); }
    | FLOAT { $$ = std::to_string($1); };


%%

void a2l::IfDataParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
