#ifndef KANJI_GUI
#define KANJI_GUI

#include <wx/wx.h>

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

    

};



DECLARE_APP(KanjiApp)

#endif