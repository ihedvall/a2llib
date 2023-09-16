/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <wx/propgrid/propgrid.h>
#include "a2ldocument.h"
namespace a2lgui {

class A2lPropertyGrid : public wxPropertyGrid {
 public:
  A2lPropertyGrid( wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxPG_DEFAULT_STYLE,
                 const wxString& name = wxASCII_STR(wxPropertyGridNameStr) );
  void SetDoc(A2lDocument* doc) { document_ = doc;  }
  void Redraw();
 private:
  A2lDocument* document_ = nullptr;

  void Redraw(const a2l::A2lFile& file);
  void Redraw(const a2l::Module& module);
  void Redraw(const a2l::A2lModPar& par);
  void DrawCategory( const a2l::A2lModPar& par);
  void Redraw(const a2l::A2lCalibrationMethod& method);
  void Redraw(const a2l::A2lMemoryLayout& layout);
  void Redraw(const a2l::A2lMemorySegment& segment);
  void Redraw(const a2l::AxisPts& axis);
};

}  // namespace a2lgui
