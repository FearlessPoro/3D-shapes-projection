///-----------------------------------------------------------------
///
/// @file      Projekt1Frm.cpp
/// @author    justyna
/// Created:   2017-05-31 18:57:34
/// @section   DESCRIPTION
///            Projekt1Frm class implementation
///
///------------------------------------------------------------------

#include "Projekt1Frm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Projekt1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Projekt1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Projekt1Frm::OnClose)
	EVT_TIMER(ID_ZEGAR,Projekt1Frm::WxTimer1Timer)
	
	EVT_UPDATE_UI(ID_WXPANEL2,Projekt1Frm::WxPanel2UpdateUI)
	EVT_BUTTON(ID_START,Projekt1Frm::StartClick)
	
	EVT_COMMAND_SCROLL(WxScrollBar,Projekt1Frm::WxScrollBar2Scroll)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON3,Projekt1Frm::OSClick)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON2,Projekt1Frm::WxRadioButton5Click)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON1,Projekt1Frm::WxRadioButton4Click)
	EVT_BUTTON(ID_WXBUTTON1,Projekt1Frm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

Projekt1Frm::Projekt1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Projekt1Frm::~Projekt1Frm()
{
}

int noLevels = 5;

wxString f2String(float f, int num){
    wxString rezultat;
    if(num==0){
        rezultat=rezultat.Format("%f", f);   
    }
    else{
        wxString strFormat = wxString::Format("%%0.%df", num);
        rezultat = rezultat.Format(strFormat,f);
    }
    return rezultat;
}    

void Projekt1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	boxGlowny = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(boxGlowny);
	this->SetAutoLayout(true);

	boxMenu = new wxBoxSizer(wxVERTICAL);
	boxGlowny->Add(boxMenu, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* okienkoBryly_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Wczytywanie bry³y"));
	okienkoBryly = new wxStaticBoxSizer(okienkoBryly_StaticBoxObj, wxVERTICAL);
	boxMenu->Add(okienkoBryly, 0, wxALIGN_CENTER | wxALL, 5);

	wczytaj = new wxButton(this, ID_WXBUTTON1, _("wczytaj dane"), wxPoint(10, 20), wxSize(92, 20), 0, wxDefaultValidator, _("wczytaj"));
	wczytaj->SetForegroundColour(wxColour(_("BLACK")));
	wczytaj->SetBackgroundColour(wxColour(_("SKY BLUE")));
	wczytaj->SetFont(wxFont(7, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoBryly->Add(wczytaj, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* okienkoPlaszczyzny_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Kierunek p³aszczyzny"));
	okienkoPlaszczyzny = new wxStaticBoxSizer(okienkoPlaszczyzny_StaticBoxObj, wxVERTICAL);
	boxMenu->Add(okienkoPlaszczyzny, 0, wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	OX = new wxRadioButton(this, ID_WXRADIOBUTTON1, _("Oœ OX"), wxPoint(10, 20), wxSize(68, 10), 0, wxDefaultValidator, _("OX"));
	OX->SetValue(true);
	OX->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoPlaszczyzny->Add(OX, 0, wxALIGN_CENTER | wxALL, 5);

	OY = new wxRadioButton(this, ID_WXRADIOBUTTON2, _("Oœ OY"), wxPoint(10, 40), wxSize(68, 10), 0, wxDefaultValidator, _("OY"));
	OY->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoPlaszczyzny->Add(OY, 0, wxALIGN_CENTER | wxALL, 5);

	OZ = new wxRadioButton(this, ID_WXRADIOBUTTON3, _("Oœ OZ"), wxPoint(10, 60), wxSize(68, 11), 0, wxDefaultValidator, _("OZ"));
	OZ->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoPlaszczyzny->Add(OZ, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* okienkoPredkosci_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Wybór prêdkoœci"));
	okienkoPredkosci = new wxStaticBoxSizer(okienkoPredkosci_StaticBoxObj, wxVERTICAL);
	boxMenu->Add(okienkoPredkosci, 0, wxALIGN_CENTER | wxALL, 5);

	predkosc = new wxScrollBar(this, WxScrollBar, wxPoint(10, 20), wxSize(95, 13), wxSB_HORIZONTAL, wxDefaultValidator, _("predkosc"));
	predkosc->Enable(false);
	predkosc->SetBackgroundColour(wxColour(_("WHITE")));
	predkosc->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoPredkosci->Add(predkosc, 0, wxALIGN_CENTER | wxALL, 5);

	tekstPredkosc = new wxStaticText(this, ID_WXSTATICTEXT1, _("Wybrana predkosc: 1,0"), wxPoint(24, 51), wxDefaultSize, 0, _("tekstPredkosc"));
	tekstPredkosc->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	okienkoPredkosci->Add(tekstPredkosc, 0, wxALIGN_CENTER | wxALL, 5);

	Start = new wxButton(this, ID_START, _("Start"), wxPoint(25, 235), wxSize(75, 25), 0, wxDefaultValidator, _("Start"));
	Start->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	boxMenu->Add(Start, 0, wxALIGN_CENTER | wxALL, 5);

	boxPanele = new wxBoxSizer(wxHORIZONTAL);
	boxGlowny->Add(boxPanele, 0, wxALIGN_CENTER | wxALL, 5);

	panelLewy = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 5), wxSize(420, 540));
	panelLewy->SetBackgroundColour(wxColour(_("WHITE")));
	panelLewy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	boxPanele->Add(panelLewy, 0, wxALIGN_CENTER | wxALL, 5);

	panelPrawy = new wxPanel(this, ID_WXPANEL2, wxPoint(435, 5), wxSize(420, 540));
	panelPrawy->SetBackgroundColour(wxColour(_("WHITE")));
	panelPrawy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false));
	boxPanele->Add(panelPrawy, 0, wxALIGN_CENTER | wxALL, 5);

	zegar = new wxTimer();
	zegar->SetOwner(this, ID_ZEGAR);

	plik =  new wxFileDialog(this, _("Choose a file"), _("C:\\Users\\Wojte_000\\Desktop\\studiaa\\Semestr_4\\Grafika\\projekt\\grafikaProjekt"), _(""), _("*.*"), wxFD_OPEN);

	SetTitle(_("Projekt1"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	predkosc->Enable(true);
	predkosc->SetScrollbar(0, 1, 11, 1);
}

void Projekt1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void Projekt1Frm::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
/*    wxFileDialog openFileDialog(this, _("Open file"), "", "",
                       "XYZ files (*.dat)|*.dat", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL){
        return;     // the user changed idea...
    }

    //wxFFileInputStream instream(openFileDialog.GetPath());
    */
    Lista.clear();
    wxString filename;
    plik->SetWildcard("TXT files (*.txt)|*.txt");
    if(plik->ShowModal()==wxID_OK){
        //filename=plik->GetPath();
    
	std::ifstream Plik;
	Plik.open(plik->GetPath().ToAscii());
		
	double x,y,z,f;
	
		do
	{
		Plik>>x;
		Plik>>y;
		Plik>>z;
		Plik>>f;
		Wektor w1(x,y,z,f);
		
		Plik>>x;
		Plik>>y;
		Plik>>z;
		Plik>>f;
		Wektor w2(x,y,z,f);
		
		Plik>>x;
		Plik>>y;
		Plik>>z;
		Plik>>f;
		Wektor w3(x,y,z,f);
		
		Macierz M(w1,w2,w3);
		
		Lista.push_back(M);
		
	}while(!Plik.eof());
	
	Lista.pop_back();
	double max = -1.;
	for(unsigned i=0; i<Lista.size(); i++)
    {
     for(int j=0; j<3; j++)
     {
         for(int k=0; k<3; k++)
         {
            if(max < Lista[i].dane[j].dane[k])
                max  = Lista[i].dane[j].dane[k];    
         }    
     }   
    }
    int w,h;
    Proste.clear();
    panelLewy->GetSize(&w,&h);
    for(unsigned i=0; i<Lista.size(); i++)
    {
     for(int j=0; j<3; j++)
     {
         for(int k=0; k<3; k++)
         {
             Lista[i].dane[j].dane[k] /= max;
             Lista[i].dane[j].dane[k] -= 0.5;
             Lista[i].dane[j].dane[k] *= (w - 60.);
         }    
     }   
    }
  }
    //OBLICZANIE PARAMETROW PROSTYCH
    Wektor w1(0., 0., 0., 0);
    Wektor w2(0., 0., 0., 0);
    Wektor w3(0., 0., 0., 0);
    Macierz M(w1, w2, w3);
    for(unsigned i=0; i<Lista.size(); i++)
    {
     for(int j=0; j<3; j++)
     {
         if(Lista[i].dane[j].dane[3])
         {
            Proste.push_back(M);
            for(int k=0; k<3; k++)
            {
                Proste[Proste.size()-1].dane[k].dane[1] = Lista[i].dane[j].dane[k];
                Proste[Proste.size()-1].dane[k].dane[2] = Lista[i].dane[next(j)].dane[k];
                Proste[Proste.size()-1].dane[k].dane[0] = Proste[Proste.size()-1].dane[k].dane[2] -
                                                          Proste[Proste.size()-1].dane[k].dane[1];
            } 
         }   
     }   
    }    
}    


/*
 * WxPanel1UpdateUI
 */
void Projekt1Frm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
    Repaint();
 
 
}
void Projekt1Frm::Repaint()
{
 wxClientDC dc1(panelLewy);
 wxBufferedDC dc(&dc1);
 int w,h;
 
 panelLewy->GetSize(&w,&h);
 dc.SetBackground(wxBrush(*wxWHITE));
 dc.Clear();
 dc.SetDeviceOrigin( w / 2 , h / 2 );
 w/=2.0;
 h/=2.0;
 
 //osie
 dc.SetPen( wxPen(*wxBLUE));
 dc.DrawLine(-w +10 , w - 10, -w +10, -w +10);
 dc.DrawLine(-w +10 , w - 10, w -10, w-10);
 dc.DrawLine(-w +10, -w +10, -w +5, -w +20 );
 dc.DrawLine(-w +10, -w +10,  -w +15, -w +20  );
 dc.DrawLine(w -10, w-10, w -20, w-15 );
 dc.DrawLine(w -10, w-10, w -20 , w-5 );
 
 //OX z=0
 if(OX->GetValue())
 {
 dc.SetPen( wxPen(*wxBLACK));
 dc.DrawText(wxT("y"), -w +3, -w +25);
 dc.DrawText(wxT("x"), w -30, w-10);
 dc.SetPen( wxPen(*wxRED));
 
 //ZERUJEMY ZETY
 for(unsigned i=0; i<Lista.size(); i++)
 {
    for(int j=0; j<3; j++)
    { 
        if(Lista[i].dane[j].dane[3])
        {
                dc.DrawLine(Lista[i].dane[j].dane[0], Lista[i].dane[j].dane[1],
                            Lista[i].dane[next(j)].dane[0], Lista[i].dane[next(j)].dane[1]);
        }   
    }   
 }
}
//OX END

//OY x=0
if(OY->GetValue())
 {
 dc.SetPen( wxPen(*wxBLACK));
 dc.DrawText(wxT("z"), -w +3, -w +25);
 dc.DrawText(wxT("y"), w -30, w-10);
 dc.SetPen( wxPen(*wxRED));
  for(unsigned i=0; i<Lista.size(); i++)
 {
    for(int j=0; j<3; j++)
    { 
        if(Lista[i].dane[j].dane[3])
        {
                dc.DrawLine(Lista[i].dane[j].dane[1], Lista[i].dane[j].dane[2],
                            Lista[i].dane[next(j)].dane[1], Lista[i].dane[next(j)].dane[2]);
        }   
    }   
 }
  
 }
//OY END
//OZ y=0
if(OZ->GetValue())
 {
 dc.SetPen( wxPen(*wxBLACK));
 dc.DrawText(wxT("x"), -w +3, -w +25);
 dc.DrawText(wxT("z"), w -30, w-10);
 dc.SetPen( wxPen(*wxRED));
   for(unsigned i=0; i<Lista.size(); i++)
 {
    for(int j=0; j<3; j++)
    { 
        if(Lista[i].dane[j].dane[3])
        {
                dc.DrawLine(Lista[i].dane[j].dane[2], Lista[i].dane[j].dane[0],
                            Lista[i].dane[next(j)].dane[2], Lista[i].dane[next(j)].dane[0]);
        }   
    }   
 }
 
 
 }
//OZ END
double shift, position = -w+20 + shift;
//P³aszczyzna
if(timerFlag)
{
     dc.SetPen( wxPen(*wxGREEN));
     if(back)
     {
        shift = (predkosc->GetThumbPosition() +1) * ( clock() - time_start)/50 ;
        position = -w+20 + shift;
        dc.DrawLine(position, w - 25, position, -w +10); 
        if(position > w - 20)
        {   
            back = 0;
            time_start = clock();
        }
    } else
    {   
        shift = (predkosc->GetThumbPosition() +1) * ( clock() - time_start)/50 ;
        position = w - 20 - shift;
        dc.DrawLine(position, w - 25, position, -w +10);
        if(position < -w + 20 )
        {
          timerFlag = 0;
            zegar->Stop();
        }
    }
}
////////////////////Prawy panel:
    wxClientDC dc1p(panelPrawy);
    wxBufferedDC dcp(&dc1p);
    panelPrawy->GetSize(&w,&h);
    dcp.SetBackground(wxBrush(*wxWHITE));
    dcp.Clear();
    dcp.SetDeviceOrigin( w / 2 , h / 2 );
    w/=2.0;
    h/=2.0;
    
    dcp.SetPen( wxPen(*wxBLUE));
    dcp.DrawLine(-w +10 , w - 10, -w +10, -w +10);
    dcp.DrawLine(-w +10 , w - 10, w -10, w-10);
    dcp.DrawLine(-w +10, -w +10, -w +5, -w +20 );
    dcp.DrawLine(-w +10, -w +10,  -w +15, -w +20  );
    dcp.DrawLine(w -10, w-10, w -20, w-15 );
    dcp.DrawLine(w -10, w-10, w -20 , w-5 );
    char buffer[30];
    
    double x,y,z, diff, xp, yp, zp, value = 0.0001;
    x= position;
    diff=10;
//OX
if(OX->GetValue() && timerFlag)
{
 dcp.SetPen( wxPen(*wxBLACK));
 dcp.DrawText(wxT("y"), -w +3, -w +25);
 dcp.DrawText(wxT("z"), w -30, w-10);
 dcp.SetPen( wxPen(*wxRED));
    x = position;
    sprintf(buffer, "Aktualne x: %.3f", x);
    if(timerFlag)
        dcp.DrawText(buffer, -50, -h + 20 );
    for(unsigned i = 0; i < Proste.size(); i++)
    {

                if( std::min(Proste[i].dane[0].dane[1], Proste[i].dane[0].dane[2]) <= x
                 && std::max(Proste[i].dane[0].dane[1], Proste[i].dane[0].dane[2]) >= x)
                 {
                        diff = (x - Proste[i].dane[0].dane[1] )/Proste[i].dane[0].dane[0];
                        if( x  == Proste[i].dane[0].dane[1] && Proste[i].dane[0].dane[2] == x)
                        {
                             dcp.DrawLine(Proste[i].dane[1].dane[1], Proste[i].dane[2].dane[1],
                                          Proste[i].dane[1].dane[2], Proste[i].dane[2].dane[2]);  
                        }
                        else
                        {
                            yp = diff * (Proste[i].dane[1].dane[2] - Proste[i].dane[1].dane[1]) + Proste[i].dane[1].dane[1];
                            zp = diff * (Proste[i].dane[2].dane[2] - Proste[i].dane[2].dane[1]) + Proste[i].dane[2].dane[1];
                            dcp.DrawCircle(zp, yp, 2);   
                        }
                 }
    }
}



//OY
if(OY->GetValue() && timerFlag)
{
 dcp.SetPen( wxPen(*wxBLACK));
 dcp.DrawText(wxT("z"), -w +3, -w +25);
 dcp.DrawText(wxT("x"), w -30, w-10);
 dcp.SetPen( wxPen(*wxRED));
    y =position;

    sprintf(buffer, "Aktualne y: %.3f", y);
    if(timerFlag)
         dcp.DrawText(buffer, -50, -h + 20 );
    for(unsigned i = 0; i < Proste.size(); i++)
    {

                if( std::min(Proste[i].dane[1].dane[1], Proste[i].dane[1].dane[2]) <= y
                 && std::max(Proste[i].dane[1].dane[1], Proste[i].dane[1].dane[2]) >= y)
                 {
                        diff = (y - Proste[i].dane[1].dane[1] )/Proste[i].dane[1].dane[0];
                        if( y  == Proste[i].dane[1].dane[1] && Proste[i].dane[1].dane[2] == y)
                        {
                             dcp.DrawLine(Proste[i].dane[2].dane[2], Proste[i].dane[0].dane[2],
                                          Proste[i].dane[2].dane[1], Proste[i].dane[0].dane[1]);  
                        }
                        else
                        {
                            zp = diff * (Proste[i].dane[2].dane[2] - Proste[i].dane[2].dane[1]) + Proste[i].dane[2].dane[1];
                            xp = diff * (Proste[i].dane[0].dane[2] - Proste[i].dane[0].dane[1]) + Proste[i].dane[0].dane[1];
                            dcp.DrawCircle(xp, zp, 2);   
                        }
                 }
    }
}
    
//OZ
if(OZ->GetValue()  && timerFlag)
{
 dcp.SetPen( wxPen(*wxBLACK));
 dcp.DrawText(wxT("x"), -w +3, -w +25);
 dcp.DrawText(wxT("y"), w -30, w-10);
 dcp.SetPen( wxPen(*wxRED));
    z =  position;
    
    sprintf(buffer, "Aktualne z: %.3f", z);
    if(timerFlag)
        dcp.DrawText(buffer, -50, -h + 20 );
    for(unsigned i = 0; i < Proste.size(); i++)
    {
                if( std::min(Proste[i].dane[2].dane[1], Proste[i].dane[2].dane[2]) <= z
                 && std::max(Proste[i].dane[2].dane[1], Proste[i].dane[2].dane[2]) >= z)
                 {
                        diff = (z - Proste[i].dane[2].dane[1] )/Proste[i].dane[2].dane[0];
                        if( z  == Proste[i].dane[2].dane[1] && Proste[i].dane[2].dane[2] == z)
                        {
                             dcp.DrawLine(Proste[i].dane[0].dane[1], Proste[i].dane[1].dane[1],
                                          Proste[i].dane[0].dane[2], Proste[i].dane[1].dane[2]);  
                        }
                        else
                        {
                            xp = diff * (Proste[i].dane[0].dane[2] - Proste[i].dane[0].dane[1]) + Proste[i].dane[0].dane[1];
                            yp = diff * (Proste[i].dane[1].dane[2] - Proste[i].dane[1].dane[1]) + Proste[i].dane[1].dane[1];
                            dcp.DrawCircle(yp, xp, 2);   
                        }
                 }
    }
}





}

/*
 * WxPanel2UpdateUI
 */
void Projekt1Frm::WxPanel2UpdateUI(wxUpdateUIEvent& event)
{
	Repaint();
}

/*
 * WxRadioButton4Click
 */
void Projekt1Frm::WxRadioButton4Click(wxCommandEvent& event)
{
	Repaint();
}

/*
 * WxScrollBar2Scroll
 */
void Projekt1Frm::WxScrollBar2Scroll(wxScrollEvent& event)
{
	// insert your code here
	wxString nazwa = "Wybrana predkosc: ";
	noLevels = predkosc->GetThumbPosition() +1;
	nazwa = nazwa+f2String(noLevels,1);
	tekstPredkosc->SetLabel(nazwa);
}

/*
 * WxRadioButton5Click
 */
void Projekt1Frm::WxRadioButton5Click(wxCommandEvent& event)
{
	Repaint();
}

/*
 * OSClick
 */
void Projekt1Frm::OSClick(wxCommandEvent& event)
{
	Repaint();
}

/*
 * StartClick
 */
void Projekt1Frm::StartClick(wxCommandEvent& event)
{
	time_start = clock();
	timerFlag = 1;
	back =1;
	zegar->Start();
	Repaint();

}

/*
 * WxTimer1Timer
 */
void Projekt1Frm::WxTimer1Timer(wxTimerEvent& event)
{
	// insert your code here
	//	time_start = clock();
	//timerFlag = 1;
	//back =1;
	//Repaint();
}
