/***************************************************************
 * Name:      Chaos_PendulumMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mathew MacDougall ()
 * Created:   2016-12-24
 * Copyright: Mathew MacDougall ()
 * License:
 **************************************************************/

#ifndef CHAOS_PENDULUMMAIN_H
#define CHAOS_PENDULUMMAIN_H

//(*Headers(Chaos_PendulumFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/clrpicker.h>
#include <wx/textctrl.h>
//*)

class Chaos_PendulumFrame: public wxFrame
{
    public:

        Chaos_PendulumFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Chaos_PendulumFrame();

    private:

        //(*Handlers(Chaos_PendulumFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Chaos_PendulumFrame)
        static const long ID_PANEL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT5;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_STATICTEXT6;
        static const long ID_COLOURPICKERCTRL2;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Chaos_PendulumFrame)
        wxToggleButton* ToggleButton1;
        wxTextCtrl* TextCtrl3;
        wxStatusBar* StatusBar1;
        wxColourPickerCtrl* ColourPickerCtrl2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxTextCtrl* TextCtrl5;
        wxStaticText* StaticText3;
        wxStaticText* StaticText7;
        wxTextCtrl* TextCtrl1;
        wxPanel* backgroundPanel;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl2;
        wxPanel* renderPanel;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CHAOS_PENDULUMMAIN_H
