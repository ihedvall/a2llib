%require "3.2"
%language "c++"

%define api.prefix {label}
%define api.namespace {a2l}
%define api.parser.class {LabelParser}


%code requires {
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <utility>

#include "a2l/selectionlist.h"

namespace a2l {
class LabelScanner;
class SelectionList;
}

}

%parse-param { a2l::LabelScanner &scanner  }
%parse-param { a2l::SelectionList &list  }

%code  {
    #include <sstream>
    #include "labelscanner.h"
    #include "a2l/selectionlist.h"
    #include "a2l/a2llogstream.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.labellex
}

%define api.value.type variant

%token EOL
%token FUNCTION
%token GROUP
%token LABEL
%token <std::vector<std::string>> LINE_TEXT;
%token RAMCELL
%token SETTINGS
%token VERSION

%start label_file
%%

label_file: lines;
lines: %empty
    | lines line;

line: EOL
  | settings_section EOL
  | ramcell_section EOL
  | label_section EOL
  | function_section EOL
  | group_section EOL
  | line_text EOL
  | line_text;

settings_section: SETTINGS {
  scanner.SetLabelState(LabelState::Settings);
};

ramcell_section: RAMCELL {
  scanner.SetLabelState(LabelState::Ramcell);
};

label_section: LABEL {
  scanner.SetLabelState(LabelState::Label);
};

function_section: FUNCTION {
  scanner.SetLabelState(LabelState::Function);
};

group_section: GROUP {
  scanner.SetLabelState(LabelState::Group);
};

line_text: LINE_TEXT {
    scanner.ParseLineText($1);
};

%%

void a2l::LabelParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
