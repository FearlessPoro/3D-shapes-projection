//---------------------------------------------------------------------------
//
// Name:        Projekt1App.h
// Author:      justyna
// Created:     2017-05-31 18:57:34
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROJEKT1FRMApp_h__
#define __PROJEKT1FRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Projekt1FrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
