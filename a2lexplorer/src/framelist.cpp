/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "framelist.h"

#include <wx/wx.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2l/module.h"
#include "a2l/frame.h"
#include "windowid.h"

using namespace a2l;
namespace a2lgui {

wxBEGIN_EVENT_TABLE(FrameList, wxListView)
  EVT_LIST_ITEM_SELECTED(kIdFrameListView, FrameList::OnItemSelected)
wxEND_EVENT_TABLE()

FrameList::FrameList(wxWindow *parent)
: wxListView(parent, kIdFrameListView, wxDefaultPosition, wxDefaultSize,
    wxLC_REPORT | wxLC_SINGLE_SEL | wxLC_VIRTUAL) {

  InsertColumn(0, "Name", wxLIST_FORMAT_LEFT, 300);
  InsertColumn(1, "Description",wxLIST_FORMAT_LEFT, 200);
}

void FrameList::Redraw() {
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  long selected = GetFirstSelected();
  if (selected < 0) {
    selected = 0;
  }
  doc->SetSelectedIndex(selected);
  DeleteAllItems();
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (object == nullptr) {
    return;
  }

  switch (type) {
    case TreeItemType::FRAME_LIST: {
      if (auto* module = static_cast<Module*>(object); module != nullptr) {
        const auto& frame_list = module->Frames();
        SetItemCount(static_cast<long>(frame_list.size()));
        if (selected >= 0 && selected < frame_list.size()) {
          Select(selected);
          EnsureVisible(selected);
        }
      }
      break;
    }

    default:
      break;

  }
}

wxString FrameList::OnGetItemText(long item, long column) const {
  wxString text;
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return text;
  }
  // ReSharper disable once CppDFAUnreachableCode
  const TreeItemType type = doc->SelectedType();
  void* object = doc->SelectedObject();
  if (type != TreeItemType::FRAME_LIST || object == nullptr) {
    return text;
  }
  auto* module = static_cast<Module*>(object);
  if (module == nullptr) {
    return text;
  }
  const Frame* frame = module->GetFrame(item);
  if (frame == nullptr) {
    return text;
  }
  switch (column) {
    case 0:
      text = wxString::FromUTF8(frame->Name());
      break;

    case 1:
      text = wxString::FromUTF8(frame->Description());
      break;

    default:
      break;
    }
  return text;
}

void FrameList::OnItemSelected(wxListEvent &event) {
  const long index = event.GetIndex();
  A2lDocument* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  doc->SetSelectedIndex(index);
  RedrawPropertyGrid();
}

void FrameList::RedrawPropertyGrid() const {
  auto* splitter = dynamic_cast<wxSplitterWindow*>(GetParent());
  if (splitter == nullptr) {
    return;
  }
  auto* property_view = dynamic_cast<A2lPropertyGrid*>(splitter->GetWindow2());
  if (property_view == nullptr) {
    return;
  }
  property_view->Redraw();
}

} // a2lgui