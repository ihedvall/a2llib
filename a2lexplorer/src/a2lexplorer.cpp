/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <filesystem>
#include <codecvt>
#define BOOST_LOCALE_HIDE_AUTO_PTR
#include <boost/process.hpp>
#include <boost/filesystem.hpp>
#include <boost/locale.hpp>

#include <wx/wx.h>
#include <wx/docview.h>
#include <wx/config.h>
#include <wx/utils.h>

#include <util/logconfig.h>
#include <util/logstream.h>

#include "a2lexplorer.h"
#include "mainframe.h"
#include "a2ldocument.h"
#include "a2lview.h"
#include "windowid.h"

using namespace util::log;
using namespace a2l;

wxIMPLEMENT_APP(a2lgui::A2lExplorer);

namespace a2lgui {

wxBEGIN_EVENT_TABLE(A2lExplorer, wxApp)
  EVT_UPDATE_UI(kIdOpenLogFile,A2lExplorer::OnUpdateOpenLogFile)
  EVT_MENU(kIdOpenLogFile, A2lExplorer::OnOpenLogFile)
wxEND_EVENT_TABLE()

bool A2lExplorer::OnInit() {
  if (!wxApp::OnInit()) {
    return false;
  }

  // Setup correct localization when formatting date and times
  boost::locale::generator gen;
  std::locale::global(gen(""));

    // Setup system basic configuration
  SetVendorDisplayName("A2lLib");
  SetVendorName("A2lLib");
  SetAppName("A2lExplorer");
  SetAppDisplayName("A2L File Explorer");

  // Set up the log file.
  auto& log_config = LogConfig::Instance();
  log_config.Type(LogType::LogToFile);
  log_config.SubDir("a2llib/log");
  log_config.BaseName("a2lexplorer");
  log_config.CreateDefaultLogger();
  LOG_INFO() << "Log File created. Path: " << log_config.GetLogFile();

  notepad_ = util::log::FindNotepad();

  auto* app_config = wxConfig::Get();
  wxPoint start_pos;
  app_config->Read("/MainWin/X",&start_pos.x, wxDefaultPosition.x);
  app_config->Read("/MainWin/Y",&start_pos.y, wxDefaultPosition.x);
  wxSize start_size;
  app_config->Read("/MainWin/XWidth",&start_size.x, 1200);
  app_config->Read("/MainWin/YWidth",&start_size.y, 800);
  bool maximized = false;
  app_config->Read("/MainWin/Max",&maximized, maximized);

  auto* doc_manager = new wxDocManager;
  new wxDocTemplate(doc_manager, "A2L File","*.a2l","",
                                         "a2l","A2lExplorer","A2L Explorer",
                                         wxCLASSINFO(A2lDocument), wxCLASSINFO(A2lView));
  auto* frame = new MainFrame(GetAppDisplayName(), start_pos, start_size, maximized);

  frame->Show(true);

  return true;
}

int A2lExplorer::OnExit() {
  LOG_INFO() << "Closing application";
  auto* app_config = wxConfig::Get();
  auto* doc_manager = wxDocManager::GetDocumentManager();
  doc_manager->FileHistorySave(*app_config);
  delete doc_manager;
  LOG_INFO() << "Saved file history.";

  auto& log_config = LogConfig::Instance();
  log_config.DeleteLogChain();
  return wxApp::OnExit();
}

void A2lExplorer::OnOpenLogFile(wxCommandEvent& event) {
  auto& log_config = LogConfig::Instance();
  std::string logfile = log_config.GetLogFile();
  OpenFile(logfile);

}

void A2lExplorer::OnUpdateOpenLogFile(wxUpdateUIEvent &event) {
  if (notepad_.empty()) {
    event.Enable(false);
    return;
  }

  auto& log_config = LogConfig::Instance();
  std::string logfile = log_config.GetLogFile();
  try {
    std::filesystem::path p(logfile);
    const bool exist = std::filesystem::exists(p);
    event.Enable(exist);
  } catch (const std::exception&) {
    event.Enable(false);
  }
}


// utf8
void A2lExplorer::OpenFile(const std::string& filename) const {
  if (!notepad_.empty()) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    const auto utf16 = convert.from_bytes(filename);
    boost::process::spawn(notepad_, std::wstring(utf16.begin(), utf16.end()));
  }
}

} // end namespace a2lgui


