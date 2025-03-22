#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif

#include "gui.h"
#include "drawingPanel.h"



DrawingPanel::DrawingPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxWindow(parent, id, pos, size)
{
    isDrawing = false;

    bindControls();
}

DrawingPanel::~DrawingPanel()
{

}

void DrawingPanel::bindControls()
{
    Bind(wxEVT_PAINT, &DrawingPanel::onPaint, this);
    Bind(wxEVT_LEFT_DOWN, &DrawingPanel::onLeftMouseClicked, this);
    Bind(wxEVT_LEFT_UP, &DrawingPanel::onLeftMouseReleased, this);
    Bind(wxEVT_MOTION, &DrawingPanel::onMouseHeld, this);
    Bind(wxEVT_LEAVE_WINDOW, &DrawingPanel::onMouseLeave, this);
    
}

void DrawingPanel::onPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.DrawRectangle(GetClientSize());
    render(dc);
}

void DrawingPanel::Paint()
{
    wxClientDC dc = wxClientDC(this);
    render(dc);
}

void DrawingPanel::render(wxClientDC& dc)
{
    for(const auto &p : strokes)
    {
        if(p.size() > 1)
        {
            wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
            if(gc)
            {
                gc->SetPen(*wxBLACK_PEN);
                gc->StrokeLines(p.size(), p.data());   
                delete gc;
            }
        }
        
    }
    //if((strokes.end()-1)->begin() > (strokes.end()-1)->end() - 2) return;
    //dc.DrawLine(*((strokes.end()-1)->end() - 1), (strokes.end()-1)->end() - 2);

}

void DrawingPanel::onLeftMouseReleased(wxMouseEvent& event)
{
    isDrawing = false;
}


void DrawingPanel::onLeftMouseClicked(wxMouseEvent& evt)
{
    isDrawing = true;
    strokes.push_back({});
}

void DrawingPanel::onMouseHeld(wxMouseEvent& event)
{   
    if(isDrawing)
    {
        (strokes.end()-1)->push_back(wxPoint2DDouble(wxPoint(event.GetX(), event.GetY())));
        Refresh();
        std::cerr << strokes.size() << std::endl;
    }

}   

void DrawingPanel::onMouseLeave(wxMouseEvent &)
{
    isDrawing = false;
}
