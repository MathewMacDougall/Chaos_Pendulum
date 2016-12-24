/***************************************************************
 * Name:      Chaos_PendulumMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mathew MacDougall ()
 * Created:   2016-12-24
 * Copyright: Mathew MacDougall ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Chaos_PendulumMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Chaos_PendulumFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Chaos_PendulumFrame)
const long Chaos_PendulumFrame::ID_PANEL2 = wxNewId();
const long Chaos_PendulumFrame::ID_BUTTON1 = wxNewId();
const long Chaos_PendulumFrame::ID_BUTTON2 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT1 = wxNewId();
const long Chaos_PendulumFrame::ID_TEXTCTRL1 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT2 = wxNewId();
const long Chaos_PendulumFrame::ID_TEXTCTRL2 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT3 = wxNewId();
const long Chaos_PendulumFrame::ID_TEXTCTRL3 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT7 = wxNewId();
const long Chaos_PendulumFrame::ID_TEXTCTRL5 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT4 = wxNewId();
const long Chaos_PendulumFrame::ID_TEXTCTRL4 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT5 = wxNewId();
const long Chaos_PendulumFrame::ID_COLOURPICKERCTRL1 = wxNewId();
const long Chaos_PendulumFrame::ID_STATICTEXT6 = wxNewId();
const long Chaos_PendulumFrame::ID_COLOURPICKERCTRL2 = wxNewId();
const long Chaos_PendulumFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long Chaos_PendulumFrame::ID_PANEL1 = wxNewId();
const long Chaos_PendulumFrame::idMenuQuit = wxNewId();
const long Chaos_PendulumFrame::idMenuAbout = wxNewId();
const long Chaos_PendulumFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Chaos_PendulumFrame,wxFrame)
    //(*EventTable(Chaos_PendulumFrame)
    //*)
END_EVENT_TABLE()

Chaos_PendulumFrame::Chaos_PendulumFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Chaos_PendulumFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    backgroundPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    renderPanel = new wxPanel(backgroundPanel, ID_PANEL2, wxDefaultPosition, wxSize(300,-1), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    renderPanel->SetBackgroundColour(wxColour(114,0,0));
    BoxSizer3->Add(renderPanel, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, backgroundPanel, _("Properties"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableCol(1);
    Button1 = new wxButton(backgroundPanel, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(backgroundPanel, ID_BUTTON2, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 1, wxALL|wxEXPAND, 5);
    StaticText1 = new wxStaticText(backgroundPanel, ID_STATICTEXT1, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(backgroundPanel, ID_TEXTCTRL1, _("1.0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(backgroundPanel, ID_STATICTEXT2, _("Gravity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(backgroundPanel, ID_TEXTCTRL2, _("9.81"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(backgroundPanel, ID_STATICTEXT3, _("Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(backgroundPanel, ID_TEXTCTRL3, _("N/A"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxEXPAND, 5);
    StaticText7 = new wxStaticText(backgroundPanel, ID_STATICTEXT7, _("Angle (rad)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(backgroundPanel, ID_TEXTCTRL5, _("N/A"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer1->Add(TextCtrl5, 1, wxALL|wxEXPAND, 5);
    StaticText4 = new wxStaticText(backgroundPanel, ID_STATICTEXT4, _("Mass"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(backgroundPanel, ID_TEXTCTRL4, _("N/A"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer1->Add(TextCtrl4, 1, wxALL|wxEXPAND, 5);
    StaticText5 = new wxStaticText(backgroundPanel, ID_STATICTEXT5, _("Rod Color"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl1 = new wxColourPickerCtrl(backgroundPanel, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    FlexGridSizer1->Add(ColourPickerCtrl1, 1, wxALL|wxEXPAND, 5);
    StaticText6 = new wxStaticText(backgroundPanel, ID_STATICTEXT6, _("Mass Color"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl2 = new wxColourPickerCtrl(backgroundPanel, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
    FlexGridSizer1->Add(ColourPickerCtrl2, 1, wxALL|wxEXPAND, 5);
    ToggleButton1 = new wxToggleButton(backgroundPanel, ID_TOGGLEBUTTON1, _("Trail"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    ToggleButton1->SetValue(true);
    FlexGridSizer1->Add(ToggleButton1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
    backgroundPanel->SetSizer(BoxSizer2);
    BoxSizer2->Fit(backgroundPanel);
    BoxSizer2->SetSizeHints(backgroundPanel);
    BoxSizer1->Add(backgroundPanel, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chaos_PendulumFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chaos_PendulumFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Chaos_PendulumFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Chaos_PendulumFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Chaos_PendulumFrame::OnClose);
    //*)
}

Chaos_PendulumFrame::~Chaos_PendulumFrame()
{
    //(*Destroy(Chaos_PendulumFrame)
    //*)
}

void Chaos_PendulumFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Chaos_PendulumFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Chaos_PendulumFrame::OnClose(wxCloseEvent& event)
{
    Close();
}

void Chaos_PendulumFrame::OnButton1Click(wxCommandEvent& event)
{
    //TODO start the simulation with the given properties
}

void Chaos_PendulumFrame::OnButton2Click(wxCommandEvent& event)
{
    //Stop teh simulation if running, otherwise reset the simulation
}
