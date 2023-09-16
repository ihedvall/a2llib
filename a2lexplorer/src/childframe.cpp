/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include <sstream>
#include <filesystem>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <util/timestamp.h>
#include "childframe.h"
#include "a2ldocument.h"
#include "windowid.h"

using namespace a2l;

namespace {
#include "img/sub.xpm"
#include "img/tree_list.xpm"
// Bitmap index for the tree control (tree_list.bmp)

// Fake file positions which select a list of blocks
constexpr int64_t kHistoryPosition = -100;
constexpr int64_t kMeasurementPosition = -200;
constexpr int64_t kAttachmentPosition = -300;
constexpr int64_t kEventPosition = -400;
constexpr int64_t kHierarchyPosition = -500;
/*
class BlockAddress : public wxTreeItemData {
 public:
  explicit BlockAddress(int64_t block_address)
      : block_address_(block_address) {
  }

  [[nodiscard]] int64_t FilePosition() const {
    return block_address_;
  }

 private:
  int64_t block_address_ = 0;
};

wxString CreateBlockText(const mdf::detail::MdfBlock&block) {
  std::ostringstream block_string;
  block_string << block.BlockType();
  const auto comment = block.Comment();
  if (!comment.empty()) {
    block_string << " (" << comment << ")";
  }
  return wxString::FromUTF8(block_string.str());
}

int64_t GetBlockId(const wxTreeCtrl& list, const wxTreeItemId& item) {
  if (!item.IsOk()) {
    return -1;
  }
  const auto* data = dynamic_cast<const BlockAddress*>(list.GetItemData(item));
  return data != nullptr ? data->FilePosition() : -1;
}

wxTreeItemId FindId(const wxTreeCtrl& list, const wxTreeItemId &root, int64_t id) { //NOLINT
   for (auto item = root; item.IsOk(); item = list.GetNextSibling(item)) {
    if (GetBlockId(list, item) == id) {
      return item;
    }
    if (list.ItemHasChildren(item)) {
      wxTreeItemIdValue cookie;
      auto find = FindId(list, list.GetFirstChild(item, cookie), id);
      if (find.IsOk()) {
        return find;
      }
    }
  }
  return {};
}
*/

} // Empty namespace

namespace a2lgui {

wxBEGIN_EVENT_TABLE(ChildFrame, wxDocMDIChildFrame) // NOLINT(cert-err58-cpp)
  EVT_TREELIST_SELECTION_CHANGED(kIdLeftTree,ChildFrame::OnTreeSelected)
//        EVT_LIST_ITEM_ACTIVATED(kIdPropertyList, ChildFrame::OnListItemActivated)
//        EVT_TREE_ITEM_RIGHT_CLICK(kIdLeftTree, ChildFrame::OnTreeRightClick)
wxEND_EVENT_TABLE()

ChildFrame::ChildFrame(wxDocument *doc,
                     wxView *view,
                     wxMDIParentFrame *parent,
                     wxWindowID id,
                     const wxString& title)
    : wxDocMDIChildFrame(doc, view, parent, id, title, wxDefaultPosition, wxDefaultSize,
                         wxDEFAULT_FRAME_STYLE, wxASCII_STR(wxFrameNameStr)) {
#ifdef _WIN32
  wxIcon sub("SUB_ICON", wxBITMAP_TYPE_ICO_RESOURCE);
#else
  wxIcon sub {wxICON(sub)};
#endif
  SetIcon(sub);

  auto* main_panel = new wxPanel(this);

  splitter_ = new wxSplitterWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxCLIP_CHILDREN);

  left_ = new A2lTreeList(splitter_,kIdLeftTree);


  property_view_ = new A2lPropertyGrid(splitter_, kIdPropertyList,
                                       wxDefaultPosition, wxDefaultSize,
                                       wxPG_SPLITTER_AUTO_CENTER);

  splitter_->SplitVertically(left_, property_view_, -600);

  auto* main_sizer = new wxBoxSizer(wxVERTICAL);
  main_sizer->Add(splitter_, 1 , wxALL | wxGROW,0);
  main_panel->SetSizerAndFit(main_sizer);
}

void ChildFrame::Update() {
  auto* doc = GetDoc();
  if (doc == nullptr) {
    return;
  }
  auto& project = doc->GetProject();
  left_->Redraw(project);
  property_view_->SetDoc(doc);
  property_view_->Redraw();
}

A2lDocument *ChildFrame::GetDoc() {
  return wxDynamicCast(GetDocument(),A2lDocument ); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
}

void ChildFrame::OnTreeSelected(wxTreeListEvent& event) {
  auto* doc = GetDoc();
  if (doc == nullptr || left_ == nullptr || property_view_ == nullptr) {
    return;
  }
  auto item = event.GetItem();
  auto* data = left_->GetItemData(item);

  if (!item.IsOk() || data == nullptr) {
    doc->SetSelected(TreeItemType::UNKNOWN, nullptr);
  } else {
    auto* temp = dynamic_cast<A2lTreeItemData*>(data);
    if (temp == nullptr) {
      doc->SetSelected(TreeItemType::UNKNOWN, nullptr);
    } else {
      doc->SetSelected(temp->Type(), temp->Object());
    }
  }
  property_view_->Redraw();
}

}



