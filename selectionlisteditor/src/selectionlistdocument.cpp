/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "selectionlistdocument.h"

#include <util/stringutil.h>

#include <wx/config.h>
#include <wx/progdlg.h>

#include <filesystem>
#include <atomic>
#include <thread>
#include <chrono>


#include <a2l/a2llogstream.h>

#include "mainframe.h"
#include "selectionlisteditor.h"
#include "selectionlistframe.h"
#include "selectiongrid.h"
#include "windowid.h"

using namespace std::filesystem;
using namespace util::string;
using namespace std::chrono_literals;

namespace a2l {
wxIMPLEMENT_DYNAMIC_CLASS(SelectionListDocument, wxDocument)

wxBEGIN_EVENT_TABLE(SelectionListDocument, wxDocument)
EVT_MENU(kIdAttachA2l, SelectionListDocument::OnAttachA2l)
EVT_MENU(kIdAttachA2l, SelectionListDocument::OnAttachDbc)

wxEND_EVENT_TABLE()


const A2lFile* SelectionListDocument::GetA2lFile() const {
  return a2l_file_.get();
}

MainFrame* SelectionListDocument::GetMainFrame() {
  return dynamic_cast<MainFrame*>(wxGetApp().GetTopWindow());
}

SelectionGrid* SelectionListDocument::GetSelectionGrid() {
  if (MainFrame* main_frame = GetMainFrame(); main_frame != nullptr) {
    return main_frame->GetGrid();
  }
  return nullptr;
}

bool SelectionListDocument::OnNewDocument() {
  const bool new_doc = wxDocument::OnNewDocument( );
  if (!new_doc) {
    return false;
  }
  selection_list_ = {};
  if (SelectionGrid* grid = GetSelectionGrid(); grid != nullptr) {
    grid->SetSelectionList(&selection_list_);
  }
  Modify(true);
  UpdateAllViews();
  return true;
}

bool SelectionListDocument::DoSaveDocument(const wxString& filename) {
  if (!IsModified()) {
    return true;
  }
  selection_list_.SetFileName(filename.ToStdWstring());
  const bool save = selection_list_.SaveLabFile();
  if (save) {
    Modify(false);
  }
  return save;
}

void SelectionListDocument::AttachA2lFile(const std::wstring& filename) {
  wxString fname(filename);
  std::atomic<bool> a2l_ready = false;
  std::atomic<bool> a2l_parse = false;
  a2l_file_ = std::make_unique<A2lFile>();
  a2l_file_->Filename(filename);

  a2l_file_->AsynchParseFile([&] (bool parse) -> void {
      a2l_parse = parse;
      a2l_ready = true;;
    });

  {
    wxProgressDialog progress("Reading A2L File",
      "Analyzing File", 100, GetMainFrame(),
      wxPD_APP_MODAL | wxPD_APP_MODAL | wxPD_AUTO_HIDE | wxPD_ELAPSED_TIME );


    // Wait until ready
    for (size_t time = 0; time < 100'000; time += 500) {
      if (a2l_ready) {
        break;
      }
      int nof_lines = a2l_file_->NumberOfLines();
      int current_line = a2l_file_->LineNo();
      int value = 0;
      std::wostringstream message;
      if (nof_lines > 0) {
        value = (current_line * 100)/ nof_lines;
        message << "Line: " << current_line << "/" << nof_lines;
      } else {
        message << "Converting to UTF-8";
      }
      wxString msg(message.str());
      const bool cont = progress.Update(value, msg);
      if (!cont) {
        break;
      }
      std::this_thread::sleep_for(500ms);
    }
  }

  if (!a2l_ready) {
    wxMessageBox(wxT("Timeout occured when reading.\nFile: ") + fname,
      "Error (Timeout)", wxOK | wxICON_ERROR);
    return;
  }
  if (!a2l_parse) {
    A2L_ERROR() << "Error reading the A2L file. File: " << fname
                << ", Error: " << a2l_file_->LastError();
    wxMessageBox(wxT("Parser error. File: ") + filename,
      "Error (Parser)", wxOK | wxICON_ERROR);
    return;
  }
  selection_list_.AttachA2lFile(*a2l_file_);
  UpdateAllViews();
}

void SelectionListDocument::OnAttachA2l(wxCommandEvent& event) {
  constexpr std::string_view wildcard =
    "A2L Files (*.a2l)|*.a2l|All Files (*.*)|*.*";
  wxString file_path;
  if (auto* app_config = wxConfig::Get(); app_config != nullptr) {
    file_path = app_config->Read("/Path/A2l", "");
  }
  auto* main_frame = GetMainFrame();
  wxFileDialog dialog(main_frame, wxT("Select an A2L File "),
    file_path,{},wxString(wildcard),
    wxFD_OPEN | wxFD_FILE_MUST_EXIST);
  const int result = dialog.ShowModal();
  if (result == wxID_CANCEL) {
    return;
  }
  wxString filename = dialog.GetPath();
  try {
    const path fullname(filename.ToStdWstring());
    const path parent_path(fullname.parent_path());

    if (auto* app_config = wxConfig::Get(); app_config != nullptr) {
      app_config->Write("/Path/A2l", wxString(parent_path.wstring()));
    }

  } catch (std::exception& err) {
    A2L_ERROR() << "Invalid file path. File: " << filename
                << ", Error: " << err.what();
    wxMessageBox(wxT("Invalid Path\nMore information in the log file"),
      wxT("Error"), wxOK | wxICON_ERROR);
  }

  AttachA2lFile(filename.ToStdWstring());
}

void SelectionListDocument::OnAttachDbc(wxCommandEvent& event) {
    constexpr std::string_view wildcard =
    "DBC Files (*.dbc)|*.dbc|All Files (*.*)|*.*";
  wxString file_path;
  if (auto* app_config = wxConfig::Get(); app_config != nullptr) {
    file_path = app_config->Read("/Path/Dbc", "");
  }
  auto* main_frame = GetMainFrame();
  wxFileDialog dialog(main_frame, wxT("Select a DBC File "),
    file_path,{},wxString(wildcard),
    wxFD_OPEN | wxFD_FILE_MUST_EXIST);
  const int result = dialog.ShowModal();
  if (result == wxID_CANCEL) {
    return;
  }
  wxString filename = dialog.GetPath();
  try {
    const path fullname(filename.ToStdWstring());
    const path parent_path(fullname.parent_path());

    if (auto* app_config = wxConfig::Get(); app_config != nullptr) {
      app_config->Write("/Path/Dbc", wxString(parent_path.wstring()));
    }

  } catch (std::exception& err) {
    A2L_ERROR() << "Invalid file path. File: " << filename
                << ", Error: " << err.what();
    wxMessageBox(wxT("Invalid Path\nMore information in the log file"),
      wxT("Error"), wxOK | wxICON_ERROR);
  }
  /*
  std::atomic<bool> dbc_ready = false;
  std::atomic<bool> dbc_parse = false;

  a2l_file_ = std::make_unique<A2lFile>();
  a2l_file_->Filename(filename.ToStdWstring());
  a2l_file_->AsynchParseFile([&] (bool parse) -> void {
      a2l_parse = parse;
      a2l_ready = true;;
    });

  {
    wxProgressDialog progress("Reading A2L File",
      "Analyzing File", 100, main_frame,
      wxPD_APP_MODAL | wxPD_SMOOTH | wxPD_ELAPSED_TIME );


    // Wait until ready
    for (size_t time = 0; !a2l_ready && time < 100'000; time += 500) {
      int nof_lines = a2l_file_->NumberOfLines();
      int current_line = a2l_file_->LineNo();
      int value = 0;
      std::wostringstream message;
      if (nof_lines > 0) {
        value = (current_line * 100)/ nof_lines;
        message << "Line: " << current_line << "/" << nof_lines;
      } else {
        message << "Converting to UTF-8";
      }
      progress.Update(value, message.str());
      std::this_thread::sleep_for(500ms);
    }
  }

  if (!a2l_ready) {
    wxMessageBox(wxT("Timeout occured when reading.\nFile: ") + filename,
      "Error (Timeout)", wxOK | wxICON_ERROR);
    return;
  }
  if (!a2l_parse) {
    A2L_ERROR() << "Error reading the A2L file. File: " << filename
                << ", Error: " << a2l_file_->LastError();
    wxMessageBox(wxT("Parser error. File: ") + filename,
      "Error (Parser)", wxOK | wxICON_ERROR);
    return;
  }
  */

}

bool SelectionListDocument::DoOpenDocument(const wxString& filename) {
  selection_list_ = {};
  selection_list_.SetFileName(filename.ToStdWstring());
  const bool read = selection_list_.ReadLabFile();
  if (!read) {
    A2L_ERROR() << "Error reading the project. File: " << filename;
  } else {
    A2L_INFO() << "Opened the project. File: " << filename;
  }

  return read;
}

bool SelectionListDocument::OnCloseDocument() {
  if (IsModified() && !selection_list_.GetFileName().empty()) {
    wxString filename = selection_list_.GetFileName();
    const bool save = selection_list_.SaveLabFile();
    if (!save) {
      A2L_ERROR() << "Error saving project. File: " << filename;
    } else {
      A2L_INFO() << "Saved the project. File: " << filename;
    }
  }
  selection_list_ = {};
  if (SelectionGrid* grid = GetSelectionGrid(); grid != nullptr) {
    grid->SetSelectionList(nullptr);
  }
  Modify(false);

  const bool close = wxDocument::OnCloseDocument();
  // No views to update but the mainframes frame should be updated.
  if (auto* main_frame = GetMainFrame(); main_frame != nullptr) {
    if (auto* frame = main_frame->GetFrame(); frame != nullptr) {
      frame->Update();
    }
  }
  return close;
}

void SelectionListDocument::AddSelectionObject(SelectionObject object) {
  selection_list_.AddObject(std::move(object));
  if (SelectionGrid* grid = GetSelectionGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

void SelectionListDocument::DeleteSelectionObject(std::string name) {
  selection_list_.RemoveObject(std::move(name));
  if (SelectionGrid* grid = GetSelectionGrid(); grid != nullptr) {
    grid->Redraw();
    grid->Update();
  }
}

} // namespace bus