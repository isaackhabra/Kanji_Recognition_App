#pragma once

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <wx/settings.h>
#include <vector>

class DrawingPanel : public wxWindow
{
    public:
        DrawingPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
        ~DrawingPanel();


    private:
        std::vector<std::vector<wxPoint2DDouble>> strokes;

        bool isDrawing;

        void bindControls();

        void render(wxClientDC& dc);
        void Paint();
        void onPaint(wxPaintEvent& event);
        void onLeftMouseClicked(wxMouseEvent& event);
        void onLeftMouseReleased(wxMouseEvent& event);    
        void onMouseHeld(wxMouseEvent& event);
        void onMouseLeave(wxMouseEvent &);
};