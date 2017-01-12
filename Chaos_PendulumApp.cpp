/***************************************************************
 * Name:      Chaos_PendulumApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mathew MacDougall ()
 * Created:   2016-12-24
 * Copyright: Mathew MacDougall ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Chaos_PendulumApp.h"

//(*AppHeaders
#include "Chaos_PendulumMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Chaos_PendulumApp);

bool Chaos_PendulumApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Chaos_PendulumFrame* Frame = new Chaos_PendulumFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
