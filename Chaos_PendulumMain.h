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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
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
        //*)

        //(*Identifiers(Chaos_PendulumFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Chaos_PendulumFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CHAOS_PENDULUMMAIN_H
