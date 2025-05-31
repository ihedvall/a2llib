/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <sstream>
#include <filesystem>

#include <wx/msgdlg.h>

#include <util/logstream.h>

#include "a2ldocument.h"
#include "a2lexplorer.h"

using namespace util::log;
using namespace a2l;

namespace a2lgui {
wxIMPLEMENT_DYNAMIC_CLASS(A2lDocument, wxDocument) // NOLINT

wxBEGIN_EVENT_TABLE(A2lDocument, wxDocument) // NOLINT
wxEND_EVENT_TABLE()

bool A2lDocument::OnOpenDocument(const wxString &filename) {

  wxBusyCursor wait;
  file_.Filename(std::string(filename.mb_str(wxConvUTF8)));
  bool parse = file_.ParseFile();
  if (!parse) {
    LOG_ERROR() << "The file is invalid A2L file. Error: " << file_.LastError()
                << ", File: " << filename;
    std::ostringstream err;
    err << "File didn't parse correctly." << std::endl;
    err << "Error: " << file_.LastError() << std::endl;
    err << "File: " << filename << std::endl;
    wxMessageBox(wxString(err.str()),
                 wxString("Error Open File"),
                 wxOK | wxCENTRE | wxICON_ERROR);
    return false;
  }

  return parse && wxDocument::OnOpenDocument(filename);
}

} // namespace a2lgui