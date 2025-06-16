#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif

#include "gui.h"


IMPLEMENT_APP(KanjiApp);    



bool KanjiApp::OnInit() 
{
    wxInitAllImageHandlers();
    TextFrame* main = new TextFrame(wxT("&Kanji"), -1, -1, 800, 500);
    main->Show(true);
    main->SetClientSize(800, 500);
    
    return true;
}

TextFrame::TextFrame(const wxChar *title, int xpos, int ypos, int width, int height) : wxFrame((wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height)) 
{
    penX = 0;
    penY = 0;
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    mainPanel = new wxPanel(this);
    drawingPanel = new DrawingPanel(mainPanel, wxID_ANY, wxPoint(20, 20), wxSize(200, 200));

    undo = new wxButton(mainPanel, wxID_ANY, wxT("&undo"), wxPoint(500, 200));
    clear = new wxButton(mainPanel, wxID_ANY, wxT("&clear"), wxPoint(500, 300)); // Use dc.clear()
    for(int i = 0; i < NUMBER_MATCHES; i++) {
        topMatches[i] = new wxStaticText(mainPanel, wxID_ANY, wxT("&String"), wxPoint(100 + 50 * i, 400));
    } 

    setupSizers();
}

TextFrame::~TextFrame()
{
    mainPanel->Destroy();
}

void TextFrame::setupSizers() 
{
    mainSizer = new wxBoxSizer(wxVERTICAL);
    drawingSizer = new wxBoxSizer(wxHORIZONTAL);
    controlSizer = new wxBoxSizer(wxVERTICAL);
    matchesSizer = new wxBoxSizer(wxHORIZONTAL);

    //auto sizerFlags = wxSizerFlags().Border(wxALL, 25);
    auto sizerFlags = wxSizerFlags().Border(wxALL, 25).Expand();

    controlSizer->Add(undo, sizerFlags);
    controlSizer->Add(clear, sizerFlags);

    drawingSizer->Add(drawingPanel, sizerFlags);
    drawingSizer->Add(controlSizer, wxSizerFlags().Border(wxALL ^ wxBOTTOM, 25));

    for(int i = 0; i < NUMBER_MATCHES; i++) {
        matchesSizer->Add(topMatches[i], sizerFlags); 
    }

    mainSizer->Add(drawingSizer, sizerFlags);
    mainSizer->Add(matchesSizer, sizerFlags); 

    mainSizer->SetSizeHints(this);
    mainPanel->SetSizerAndFit(mainSizer);
    
}


void TextFrame::onPaint(wxPaintEvent& event)
{
    Refresh();
    //std::cerr << undo->();
}


