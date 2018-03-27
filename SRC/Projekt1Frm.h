///-----------------------------------------------------------------
///
/// @file      Projekt1Frm.h
/// @author    justyna
/// Created:   2017-05-31 18:57:34
/// @section   DESCRIPTION
///            Projekt1Frm class declaration
///
///------------------------------------------------------------------

#ifndef __PROJEKT1FRM_H__
#define __PROJEKT1FRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/timer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/scrolbar.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/sizer.h>
////Header Include End
#include "macierz.h"
#include<vector>
#include<fstream>
#include <wx/dcbuffer.h>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cmath>
////Dialog Style Start
#undef Projekt1Frm_STYLE
#define Projekt1Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Projekt1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Projekt1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Projekt1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Projekt1Frm_STYLE);
		virtual ~Projekt1Frm();
		void WxButton1Click(wxCommandEvent& event);
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void WxPanel2UpdateUI(wxUpdateUIEvent& event);
		void WxRadioButton4Click(wxCommandEvent& event);
		void WxScrollBar2Scroll(wxScrollEvent& event);
		void WxRadioButton5Click(wxCommandEvent& event);
		void OSClick(wxCommandEvent& event);
		void Repaint();
		void StartClick(wxCommandEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *plik;
		wxTimer *zegar;
		wxPanel *panelPrawy;
		wxPanel *panelLewy;
		wxBoxSizer *boxPanele;
		wxButton *Start;
		wxStaticText *tekstPredkosc;
		wxScrollBar *predkosc;
		wxStaticBoxSizer *okienkoPredkosci;
		wxRadioButton *OZ;
		wxRadioButton *OY;
		wxRadioButton *OX;
		wxStaticBoxSizer *okienkoPlaszczyzny;
		wxButton *wczytaj;
		wxStaticBoxSizer *okienkoBryly;
		wxBoxSizer *boxMenu;
		wxBoxSizer *boxGlowny;
		////GUI Control Declaration End
		std::vector<Macierz> Lista;
		std::vector< Macierz > Proste;
		clock_t time_start;
		bool timerFlag;
		bool back;
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_ZEGAR = 1056,
			ID_WXPANEL2 = 1054,
			ID_WXPANEL1 = 1053,
			ID_START = 1055,
			ID_WXSTATICTEXT1 = 1042,
			WxScrollBar = 1041,
			ID_WXRADIOBUTTON3 = 1038,
			ID_WXRADIOBUTTON2 = 1037,
			ID_WXRADIOBUTTON1 = 1036,
			ID_WXBUTTON1 = 1030,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
