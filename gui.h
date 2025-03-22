#ifndef KANJI_GUI
#define KANJI_GUI

#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <wx/settings.h>
#include <vector>
#include "drawingPanel.h"

const int NUMBER_MATCHES = 5;

class KanjiApp : public wxApp 
{
    public: 
        virtual bool OnInit() override;
};

class TextFrame : public wxFrame 
{
    public:
        TextFrame(const wxChar *title, int xpos, int ypos, int width, int height);
        ~TextFrame();

    private: 
        bool isDrawing = false;
        int penX; 
        int penY;
        
        wxPanel* mainPanel;
        DrawingPanel* drawingPanel;
        //wxPaintDC* paintDC;
        wxButton* undo;
        wxButton* clear;
        wxStaticText* topMatches[NUMBER_MATCHES];

        wxSizer* mainSizer;
        wxSizer* drawingSizer;
        wxSizer* controlSizer;
        wxSizer* matchesSizer;

        

        void setupSizers();
        void bindControls();

        void onPaint(wxPaintEvent& event); 
};



DECLARE_APP(KanjiApp)

#endif