/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/splitter.h>

#include "a2lpropertygrid.h"
#include "a2ltextcontrol.h"
#include "axispointlist.h"
#include "calibrationmethodlist.h"
#include "memorylayoutlist.h"
#include "memorysegmentlist.h"
#include "bloblist.h"
#include "characteristiclist.h"
#include "compumethodlist.h"
#include "computablist.h"
#include "framelist.h"
#include "functionlist.h"
#include "grouplist.h"
#include "instancelist.h"
#include "measurementlist.h"
#include "recordlayoutlist.h"
#include "transformerlist.h"
#include "typedeflist.h"
#include "unitlist.h"
#include "userrightslist.h"

#include "a2ldocument.h"

namespace a2lgui {

class A2lRightPanel : public wxPanel {
  public:
    A2lRightPanel(wxWindow* parent);

    void SetDoc(A2lDocument* doc);
    [[nodiscard]] A2lDocument* GetDoc() const { return document_; };
    void Redraw();

  private:
    A2lDocument* document_ = nullptr;
    wxSplitterWindow* splitter_ = nullptr;

    A2lTextControl* text_view_ = nullptr;
    A2lPropertyGrid* property_view_ = nullptr;
    AxisPointList* axis_points_view_ = nullptr;
    CalibrationMethodList* cal_methods_view_ = nullptr;
    MemoryLayoutList* memory_layout_view_ = nullptr;
    MemorySegmentList* memory_segment_view_ = nullptr;
    BlobList* blob_view_ = nullptr;
    CharacteristicList* characteristic_view_ = nullptr;
    CompuMethodList* compu_method_view_ = nullptr;
    CompuTabList* compu_tab_view_ = nullptr;
    FrameList* frame_view_ = nullptr;
    FunctionList* function_view_ = nullptr;
    GroupList* group_view_ = nullptr;
    InstanceList* instance_view_ = nullptr;
    MeasurementList* measurement_view_ = nullptr;
    RecordLayoutList* record_layout_view_ = nullptr;
    TransformerList* transformer_view_ = nullptr;
    TypedefList* typedef_view_ = nullptr;
    UnitList* unit_view_ = nullptr;
    UserRightsList* user_rights_view_ = nullptr;

    void HideViews() const;
    void ShowList(wxWindow* left_window) const;
    void RedrawViews() const;
};
} // a2lgui
