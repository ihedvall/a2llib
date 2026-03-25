/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <sstream>
#include <filesystem>
#include <atomic>
#include <thread>
#include <chrono>

#include <util/logstream.h>

#include <wx/progdlg.h>

#include "a2ldocument.h"
#include "a2lexplorer.h"

using namespace util::log;
using namespace a2l;
using namespace std::chrono_literals;

namespace a2lgui {
wxIMPLEMENT_DYNAMIC_CLASS(A2lDocument, wxDocument) // NOLINT

wxBEGIN_EVENT_TABLE(A2lDocument, wxDocument) // NOLINT
wxEND_EVENT_TABLE()

bool A2lDocument::OnOpenDocument(const wxString &filename) {
  file_.Filename(std::string(filename.mb_str(wxConvUTF8)));
  std::atomic<bool> parse_done = false;
  bool parse_result = false;
  file_.AsynchParseFile([&](bool result)-> void {
    parse_result = result;
    parse_done = true;
  });
  wxProgressDialog progress_dialog( "Parsing Input File", "Converting to UTF8", 100,
    GetDocumentWindow(), wxPD_APP_MODAL | wxPD_AUTO_HIDE);
  progress_dialog.Show(true);


  while (!parse_done) {
    const int line = file_.LineNo();
    const int number_of_lines = file_.NumberOfLines();
    const int progress = file_.ProgressInfo();
    if (line == 0) {
      progress_dialog.Update(0, "Converting to UTF8 characters");
    } else {
      std::ostringstream info;
      info << " Paring Line: " << line << " (" << number_of_lines << ")";
      progress_dialog.Update(progress < 100 ? progress : 99, info.str());
    }
    std::this_thread::sleep_for(250ms);
  }
  // There is an annoying 100 procent manual close button involved
  progress_dialog.Update(99, "Parser Ready. Creating Display.");
  //progress_dialog.Update(100, "Ready. Creating Display.");

  if (!parse_result) {
    LOG_ERROR() << "The file is invalid A2L file. Error: " << file_.LastError()
                << ", File: " << filename;
    std::ostringstream err;
    err << "The file didn't parse correctly." << std::endl;
    err << "Error: " << file_.LastError() << std::endl;
    err << "File: " << filename << std::endl;
    wxMessageBox(wxString(err.str()),
                 wxString("Error Open File"),
                 wxOK | wxCENTRE | wxICON_ERROR);
    wxGetApp().OpenFileEx(filename.ToStdString(), file_.LineNo());
    return false;
  }

  return wxDocument::OnOpenDocument(filename);
}

std::string A2lDocument::AddressToString(uint64_t address) {
  std::ostringstream temp;
  temp << address << " (0x" << std::hex << std::uppercase
       << address << ")";
  return temp.str();
}


} // namespace a2lgui