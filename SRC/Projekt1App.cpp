//---------------------------------------------------------------------------
//
// Name:        Projekt1App.cpp
// Author:      justyna
// Created:     2017-05-31 18:57:34
// Description: 
//
//---------------------------------------------------------------------------

#include "Projekt1App.h"
#include "Projekt1Frm.h"

IMPLEMENT_APP(Projekt1FrmApp)

bool Projekt1FrmApp::OnInit()
{
    Projekt1Frm* frame = new Projekt1Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Projekt1FrmApp::OnExit()
{
	return 0;
}
