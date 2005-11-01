/***************************************************************************
 *            ncal.cpp
 *
 *  Sun Oct  2 14:26:51 2005
 *  Copyright  2005  Ben
 *  Email eanvighy(at)libero.it
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include "ncal.h"


DECLARE_APP(nCal)
IMPLEMENT_APP(nCal)


//------------------------------------------------------------------------------
//----- Tabelle degli Eventi ---------------------------------------------------

//---------------- Classe nCal -------------------------------------------------

BEGIN_EVENT_TABLE(mainWnd,wxFrame)
	EVT_CLOSE	(mainWnd::OnClose	)
	EVT_TIMER	(TIMER_CONTR_CAL	,mainWnd::OnTimerCC	)
	EVT_MENU	(INFO_SAVE			,mainWnd::OnSaveInfo)
	EVT_MENU	(APPL_EXIT			,mainWnd::OnExit	)
	EVT_MENU	(APPL_ABOUT			,mainWnd::OnAbout	)
	EVT_MENU	(APPL_HELP			,mainWnd::OnHelp	)
	EVT_MENU	(APPL_INS_APP		,mainWnd::OnInsApp	)
	EVT_MENU	(APPL_DEL_APP		,mainWnd::OnDelApp	)
	EVT_MENU	(APPL_OBT_APP		,mainWnd::OnObtApp	)
	EVT_MENU	(APPL_MODSTRAPP		,mainWnd::OnModStrA	)
	EVT_MENU	(APPL_OBTSTRAPP		,mainWnd::OnObtStrA	)
	EVT_MENU	(APPL_MODPROF		,mainWnd::OnModProf	)
	EVT_MENU	(APPL_C_PROF		,mainWnd::OnChngProf)
	EVT_MENU	(APPL_PREFS			,mainWnd::OnPrefs	)
	EVT_LISTBOX		(APPL_O_LISTB	,mainWnd::OnSelApp	)
	EVT_LISTBOX_DCLICK (APPL_O_LISTB,mainWnd::OnDClicApp)
	EVT_CALENDAR(APPL_CALEND		,mainWnd::OnChngDay )
END_EVENT_TABLE()

//---------------- Classe profDial ---------------------------------------------

BEGIN_EVENT_TABLE (profDial	,wxDialog	)
	EVT_LISTBOX		(P_M_LISTBOX	,profDial::OnSelProf	)
	EVT_LISTBOX_DCLICK	(P_M_LISTBOX,profDial::OnDClicProf	)
	EVT_BUTTON		(P_M_CLOSE		,profDial::OnExit		)
	EVT_BUTTON		(P_M_BUTT_NEW	,profDial::OnButtNew	)
	EVT_BUTTON		(P_M_BUTT_MOD	,profDial::OnButtMod	)
	EVT_BUTTON		(P_M_BUTT_DEL	,profDial::OnButtDel	)
END_EVENT_TABLE()

//---------------- Classe profSwitch -------------------------------------------

BEGIN_EVENT_TABLE (profSwitch	,wxDialog	)
	EVT_LISTBOX		(P_S_LISTBOX	,profSwitch::OnSelProf	)
	EVT_LISTBOX_DCLICK	(P_S_LISTBOX,profSwitch::OnDClicProf)
	EVT_BUTTON		(P_S_BUTT_INF	,profSwitch::OnInfoButt	)
END_EVENT_TABLE()




//------------------------------------------------------------------------------
//----- Classe nCal ------------------------------------------------------------

inline bool nCal::OnInit() {
	mainWnd * ilFrame = new mainWnd (60,60,600,600,TITLE);
	ilFrame->Show(true);
	SetTopWindow(ilFrame);
	return true;
} //aggiungere gestione del file d configurazione con controlli sulla comp



//------------------------------------------------------------------------------
//----- Classe MainWnd ---------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------

inline mainWnd::mainWnd(int xpos,int ypos,int width,
					 	int height,const wxChar *title) 
						: wxFrame ((wxFrame *) NULL,
								   -1, title,
								   wxPoint(xpos,ypos),
								   wxSize(width,height))
						, ilTimer (this,TIMER_CONTR_CAL)
						,elSel(0)
{
	daySel = _date_::Today();
	
	eventLog = new wxTextCtrl  (this,-1,wxString(_T("")),
								wxDefaultPosition,
								wxSize(50,75),
								wxTE_MULTILINE | wxTE_READONLY);
	
	if (!InitHD()) MessageLog(_T("problemi nel creare la cartella dei dati"));
	inHD apri;
	apri.loadProgData(theData);
	if (!apri.loadProgData(theData)) 
		MessageLog(_T("errore nell'apertura del file di configurazione, "
					  "uso le impostazioni standard"));
	if (!apri.loadProfs(repository))
		MessageLog(_T("errore nell'apertura del file dei profili, "
					  "verificare che non sia danneggiato"));
	
//	Inizializzazione Menu
	fileMenu = new wxMenu;
	fileMenu->Append(APPL_C_PROF,_T("&Change Profile.."),
					 _T("Switch to another Profile"));
	fileMenu->AppendSeparator();
	fileMenu->Append(APPL_IMPORT,_T("&Import.."),_T("Import from a file"));
	fileMenu->Append(APPL_EXPORT,_T("&Export.."),_T("Exports these infos"));
	fileMenu->AppendSeparator();
	fileMenu->Append(INFO_SAVE,_T("&Save"),_T("Save the newest infos"));
	fileMenu->AppendSeparator();
	fileMenu->Append(APPL_EXIT,_T("E&xit"),_T("Stop Wastin' Time!"));
	
	editMenu = new wxMenu; //inserimento e modifica degli appuntamenti..
	editMenu->Append(APPL_INS_APP,_T("&New Element"),_T("Creates a new Element"));
	editMenu->Append(APPL_DEL_APP,_T("&Delete Element"),_T("Deletes an Element"));
	editMenu->Append(APPL_OBT_APP,_T("&Refresh"),_T("Refreshes this day"));
	
	prefMenu = new wxMenu;
	prefMenu->Append(APPL_MODPROF,_T("Manage &Profiles.."),
					 _T("Manage your profiles"));
//	prefMenu->Append(PROVA_WORK_DIR,_T("&Working Directory.."),
//					 _T("Change the workdir"));
	prefMenu->AppendSeparator();
	prefMenu->Append(APPL_PREFS,_T("&Options..."),
					 _T("Change settings of the program"));
	
	helpMenu = new wxMenu;
	helpMenu->Append(APPL_ABOUT,_T("&About.."),_T("Who's the maker?"));
	helpMenu->AppendSeparator();
	helpMenu->Append(APPL_HELP,_T("&Help"),_T("Do you need help?"));
	
	theBar = new wxMenuBar;
	theBar->Append(fileMenu,_T("&File"));
	theBar->Append(editMenu,_T("&Edit"));
	theBar->Append(prefMenu,_T("&Preferences"));
	theBar->Append(helpMenu,_T("&Help"));
	SetMenuBar(theBar);
	CreateStatusBar(3);
	
	bigSizer = new wxBoxSizer (wxVERTICAL);//area principale
	visSizer = new wxBoxSizer (wxHORIZONTAL);//area d lavoro
	logSizer = new wxBoxSizer (wxVERTICAL);//area d log
	panSizer = new wxBoxSizer (wxVERTICAL);//area del pannello
	
	visualE20 = new wxListBox  (this,APPL_O_LISTB,wxDefaultPosition,
								wxDefaultSize,0,NULL,wxLB_SINGLE);
								
	visProf = new wxTextCtrl   (this,-1,wxString(_T("")),
								wxDefaultPosition,
								wxSize(100,50),
								wxTE_MULTILINE | wxTE_READONLY);
	
	theCal = new wxCalendarCtrl(this,APPL_CALEND,wxDefaultDateTime,
								wxDefaultPosition,wxDefaultSize,
								wxCAL_SHOW_HOLIDAYS | wxCAL_MONDAY_FIRST);
	
//	agg un visualizzatore delle informazioni del profilo all'area del pannello
	
	visSizer->Add(visualE20,1,wxEXPAND | wxALL,1);
	panSizer->Add(visProf,1,wxEXPAND | wxALL,1);
	panSizer->Add(theCal,0,wxEXPAND | wxALL,1);
	visSizer->Add(panSizer,0,wxEXPAND);	//agg il pannello al sizer dell'area d lavoro
	logSizer->Add(eventLog,1,wxEXPAND | wxALL,1);
	
	bigSizer->Add(visSizer,1,wxEXPAND);//opzione 1 x adattarlo a tt la finestra
	bigSizer->Add(logSizer,0,wxEXPAND);//l'opzione 0 serve x nn farlo espandere
	
	SetAutoLayout(true);
	SetSizer(bigSizer);
	
	_profile_ test;
	test.SetNick(_T("Test User"));
	test.SetNome(_T("Name User"));
	test.SetCognome(_T("Surname User"));
	ProfVisual(test);
	
//	bigSizer->Fit(this); //ridimensionano il frame alle dim degli obj contenuti
//	bigSizer->SetSizeHints(this);
	
//	Timer!!
	ilTimer.Start(10000);
	
	MessageLog(_T("----------------------------------"));
	MessageLog(_T("Initialization complete"));
	MessageLog(_T("----------------------------------"));
}

inline mainWnd::~mainWnd() {
	//nope
}

//---------------- Funzioni manipolazione Eventi -------------------------------

inline void mainWnd::OnTimerCC	(wxTimerEvent 	& event) {
	MessageLog(_T("Bella sturia il timer funziona"));
	SalvaInfo();
}

inline void mainWnd::OnClose	(wxCloseEvent 	& event) {
	//chiudo!?
	outHD salvataggio;
	salvataggio.saveProgData(theData);
	profVec tempSalv;
	repository.ottieniProf(tempSalv);
	salvataggio.saveProfs(tempSalv);
	if (theData.logAct)
		salvataggio.saveLog(eventLog->GetValue());
	SalvaInfo(); //salvo automaticamente...
	Destroy();
}

inline void mainWnd::OnSaveInfo	(wxCommandEvent & event) {
	SalvaInfo();
}

inline void mainWnd::OnExit		(wxCommandEvent & event) {
	Close(true);
}

inline void mainWnd::OnAbout	(wxCommandEvent & event) {
	wxString about;
	about.append(_T("-> This is \""));
	about.append(TITLE);
	about.append(_T("\" version \""));
	about.append(VERS);
	about.append(_T("\" <-\n\n"));
	about.append(_T(
	"This program is free software; you can redistribute it and/or modify "
	"it under the terms of the GNU General Public License as published by "
	"the Free Software Foundation; either version 2 of the License, or "
	"(at your option) any later version.\n\n"
	"This program is distributed in the hope that it will be useful, "
	"but WITHOUT ANY WARRANTY; without even the implied warranty of "
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
	"GNU General Public License for more details.\n\n"
	"Who wanted this project to be what it is and worked for it is "));
	about.append(AUTHOR1);
	about.append(_T(" also known as "));
	about.append(AUTHOR2);
	wxMessageDialog aboutDialog(this,about,_T("About this Project"),wxOK);
	aboutDialog.ShowModal();
	MessageLog(_T("Visualizzata la fienstra About"));
}

inline void mainWnd::OnHelp		(wxCommandEvent & event) {
	MessageLog(_T("Visualizzato l'Help"));
	//dialog help
}

inline void mainWnd::OnInsApp	(wxCommandEvent & event) {
	//finestra x l'immissione dei dati!!!
	MessageLog(_T("Lanciato l'inserimento di un nuovo appuntamento"));
	newApp theDial(this);
	if (theDial.ShowModal() == wxID_OK) {
		
		_time_ quando = theDial.GetNewTimeApp();
		string tempStr = (theDial.GetNewStrApp().c_str());
		
		if (quando.IsEmpty() && tempStr.empty()) {
			MessageLog(_T("errore nell'ins dell'app"));
			return;
		}
		
		unsigned int count = tempStr.find("\n");
		while (count < string::npos) {
			tempStr.replace(count,1,"\n\t\t");
			count = tempStr.find("\n",++count);
		}
		
		app_date appu;
		appu.SetWhen(quando);
		appu.SetWhat(tempStr);
		
		if (!repository.aggAppuntamento(daySel,appu)) 
			MessageLog(_T("problema nell'inserimento dell'app"));
		OnObtApp(event);	//refresh del quadro
	}
}

inline void mainWnd::OnDelApp	(wxCommandEvent & event) {
	MessageLog(_T("Lanciata l'eliminazione di un nuovo appuntamento"));
	app_date temp = repository.obtainApp(daySel,elSel);
	wxMessageDialog theDial(this,_T("Do you want to destroy this date"),
            	        		_T("Eliminate Date"),wxNO | wxYES);
	if (theDial.ShowModal() == wxID_YES) {
		if (!temp.IsEmpty()) {
			repository.elimAppuntamento(daySel,temp);
			OnObtApp(event);	//refresh del quadro
		} else {
			MessageLog(_T("Nessun elemento presente. Impossibile eliminare"));
		}
	}
}

inline void mainWnd::OnObtApp	(wxCommandEvent & event) {
	MessageLog(_T("Lanciato l'aggiornamento degli appuntamenti"));
	appVec gliApp;
	repository.ottieniAppDelGg(gliApp,daySel);
	visualE20->Clear();
	appVec::const_iterator iter = gliApp.begin();
	appVec::const_iterator fine = gliApp.end();
	while (iter != fine) {
		MessVisual(_T("- " + (iter->GetWhen()).ToStdString() 
				   + "  -  " + (iter->GetWhat())));
		iter++;
	}
	if (elSel < gliApp.size()) visualE20->SetSelection(elSel);
	else {
		elSel = gliApp.size() - 1;
		visualE20->SetSelection(elSel);
	}
}

inline void mainWnd::OnObtStrA	(wxCommandEvent & event) {
}

inline void mainWnd::OnModStrA	(wxCommandEvent & event) {
	MessageLog(_T("Lanciata la modifica dell'appuntamento selezionato"));
	app_date temp = repository.obtainApp(daySel,elSel);
//	visualizza la finestra d modifica... e eventuale modifica
	string elimTab = temp.GetWhat();
	unsigned int elimCount = elimTab.find("\t");
	while (elimCount < string::npos) {
		elimTab.replace(elimCount,1,"");
		elimCount = elimTab.find("\t",elimCount);
	}
	chngStrApp theDial	(this,wxString(elimTab.c_str()));
	if (theDial.ShowModal() == wxID_OK) {
		string tempStr = (theDial.GetNewStrApp().c_str());
		unsigned int count = tempStr.find("\n");
		while (count < string::npos) {
			tempStr.replace(count,1,"\n\t\t");
			count = tempStr.find("\n",++count);
		}
		temp.SetWhat(tempStr);
	//	se modifica allora salva
		repository.modAppuntamento(daySel,temp);
		OnObtApp(event);
	}
}

inline void mainWnd::OnModProf	(wxCommandEvent & event) {
	MessageLog(_T("Lanciata la modifica del profilo"));
	//crea un vero e proprio gestore dei profili... cn accesso al path dei dati 
	//e verifica i prof esistenti. ogni file dei profili conterrà poi un indice 
	//degli appuntamenti o dei file indice degli appuntamenti.
	profDial theDial(this,repository);
	theDial.ShowModal();
}

inline void mainWnd::OnChngProf	(wxCommandEvent & event) {
	MessageLog(_T("Lanciato il cambio del profilo"));
	profVec iProf;
	repository.ottieniProf(iProf);
	profSwitch theDial(this,iProf);
	if (theDial.ShowModal() == wxID_OK) {
		_profile_ scelto = repository.ottieniProf(theDial.GetElSel());//nope
	}
}

inline void mainWnd::OnSelApp	(wxCommandEvent & event) {
	elSel = visualE20->GetSelection();
}

inline void mainWnd::OnDClicApp	(wxCommandEvent & event) {
	elSel = visualE20->GetSelection();
	OnModStrA(event);
}

inline void mainWnd::OnChngDay	(wxCalendarEvent & event) {
	wxDateTime temp = theCal->GetDate();
	daySel.setYear(temp.GetYear());
	daySel.setMonth(temp.GetMonth()+1);
	daySel.setDay(temp.GetDay());
	MessageLog(_T("cambiato Giorno di cui visualizzare gli appuntamenti"));
	OnObtApp(event);
}

inline void mainWnd::OnPrefs	(wxCommandEvent & event) {
	prefDial theDial(this,theData);
	if (theDial.ShowModal() == wxID_OK) theDial.ApplyChng();
}


//---------------- Funzioni manipolazione Oggetti ------------------------------

inline void mainWnd::MessageLog(const string & mess) {
	#ifdef WIN32
	wxString transizione = (_time_xtd::Now()).ToStdString().c_str();
	wxString tans2 = mess.c_str();
	*eventLog << "(" << transizione << ") " << tans2 << "\n";
    #else
    *eventLog << "(" << (_time_xtd::Now()).ToStdString() << ") " << mess << "\n";
    #endif
}

inline void mainWnd::MessageLog(const wxString & mess) {
	#ifdef WIN32
	wxString transizione = (_time_xtd::Now()).ToStdString().c_str();
	*eventLog << "(" << transizione << ") " << mess << "\n";
    #else
    *eventLog << "(" << (_time_xtd::Now()).ToStdString() << ") " << mess << "\n";
    #endif
}

inline void mainWnd::MessageLog(const wxChar * mess) {
	#ifdef WIN32
	wxString transizione = (_time_xtd::Now()).ToStdString().c_str();
	*eventLog << "(" << transizione << ") " << mess << "\n";
    #else
    *eventLog << "(" << (_time_xtd::Now()).ToStdString() << ") " << mess << "\n";
    #endif
}

inline void mainWnd::MessVisual	(const string & mess) {
	int pos = visualE20->GetCount();
	visualE20->Insert(wxString(mess.c_str()),pos);
}

inline void mainWnd::MessVisual	(const wxString & mess) {
	int pos = visualE20->GetCount();
	visualE20->Insert(mess,pos);
}

inline void mainWnd::MessVisual	(const wxChar * mess) {
	int pos = visualE20->GetCount();
	visualE20->Insert(mess,pos);
}

inline void mainWnd::ProfVisual	(const _profile_ &theProf) {
	visProf->Clear();
	*visProf << "\nNickname:\n  " << theProf.GetNick().c_str() << "\n";
	*visProf << "\nName:\n  " << theProf.GetNome().c_str() << "\n";
	*visProf << "\nSurname:\n  " << theProf.GetCognome().c_str() << "\n";
}

inline void mainWnd::SalvaInfo() {
	//nope nn ancora implementato
	MessageLog(_T("Salvati i dati"));
}

inline void mainWnd::RefreshProf() {
	//nope nn ancora implementato
	MessageLog(_T("Ri-freshato il profilo"));
}
