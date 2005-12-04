/***************************************************************************
 *            ncal.h
 *
 *  Sun Oct  2 14:03:07 2005
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
 

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <wx/wx.h>
#include <wx/calctrl.h>
#include "../src/tipi.cpp"
#include "../src/dataBlock.cpp"
#include "../src/profMan.cpp"
#include "../src/smllDlgs.cpp"
#include "../src/hdCtrl.cpp"
#include "../src/prefDlg.cpp"

#define USE_LISTVIEW
#ifdef USE_LISTVIEW
	#include <wx/listctrl.h>
#endif

#ifdef USE_SPLASHSCREEN
	#include <wx/splash.h>
	#include <wx/image.h>
#endif

class nCal : public wxApp {
public:
	virtual bool OnInit();
};

class mainWnd : public wxFrame {
	wxTimer ilTimer;
	
	wxBoxSizer 	* bigSizer; //	1°liv
	wxBoxSizer 	* visSizer, * logSizer;	//	2°liv
	wxBoxSizer	* panSizer, * daySizer;	//	3°liv
	wxBoxSizer	* recSizer, * appSizer; //	4°liv
	
	wxTextCtrl 	* eventLog;
	wxListBox	* visualE20;
	unsigned int elSel;
	#ifndef USE_LISTVIEW
	wxListBox	* visualRec;
	#else
	wxListView	* visualRec;
	#endif
	unsigned int recSel;
	wxTextCtrl	* visProf;
	wxCalendarCtrl	* theCal;
	
//	Menu
	wxMenuBar 	* theBar;
	wxMenu 		* fileMenu, * editMenu, * prefMenu, * helpMenu;
	
//	Strutture Dati
	containerDati repository;
	_date_ daySel;
	
	progData theData; //il costruttore avrà i param standard
	
//	Funzioni d manipolazione
	void SalvaInfo();
	void RefreshProf();
	void RefreshApp();
	void RefreshRec();
	
	DECLARE_EVENT_TABLE()
public:
	mainWnd(int ,int ,int ,int ,const wxChar *);
	~mainWnd();
	
	void MessageLog	(const wxString &);
	void MessageLog	(const wxChar *);
	
//	Visual
	void MessVisual	(const wxString &,bool);
	void MessVisual	(const wxChar *,bool);
	
	#ifndef USE_LISTVIEW
	void RecVisual	(const wxString &,bool);
	void RecVisual	(const wxChar *,bool);
	#else
	void RecVisual	(const wxString &,const wxString &,bool imp = false);
	void RecVisual	(const wxChar *,const wxChar *,bool imp = false);
	#endif
	
	void ProfVisual (const _profile_ &);
	
//	Funzioni di manipolazione
	friend class profDial;
	
//	Events
	void OnClose	(wxCloseEvent 	& event);
	void OnTimerCC	(wxTimerEvent 	& event);
	
	void OnSaveInfo	(wxCommandEvent & event);
	void OnExit		(wxCommandEvent & event);
	void OnChngProf	(wxCommandEvent & event);
	void OnExport	(wxCommandEvent & event);
	void OnImport	(wxCommandEvent & event);
	
	void OnInsApp	(wxCommandEvent & event);
	void OnDelApp	(wxCommandEvent & event);
	void OnObtApp	(wxCommandEvent & event);
	void OnInsRec	(wxCommandEvent & event);
	void OnDelRec	(wxCommandEvent & event);
	void OnModRec	(wxCommandEvent & event);
	void OnObtStrA	(wxCommandEvent & event);
	void OnModApp	(wxCommandEvent & event);
	void OnSelApp	(wxCommandEvent & event);
	void OnDClicApp	(wxCommandEvent & event);
	#ifndef USE_LISTVIEW
	void OnSelRec	(wxCommandEvent & event);
	void OnDClicRec	(wxCommandEvent & event);
	#else
	void OnSelRec	(wxListEvent & event);
	#endif
	
	void OnModProf	(wxCommandEvent & event);
	void OnPrefs	(wxCommandEvent & event);
	
	void OnAbout	(wxCommandEvent & event);
	void OnHelp		(wxCommandEvent & event);
	
	void OnChngDay	(wxCalendarEvent & event);
	
//	manipolazione del calendario, o dell'oggetto.
};

enum {
	APPL_EXIT 	= 	wxID_HIGHEST + 1,
	APPL_ABOUT,
	APPL_HELP,
	APPL_INS_APP,
	APPL_DEL_APP,
	APPL_OBT_APP,
	APPL_MOD_APP,
	APPL_INS_REC,
	APPL_DEL_REC,
	APPL_MOD_REC,
	APPL_OBTSTRAPP,
	INFO_SAVE,
	APPL_EXPORT,
	APPL_IMPORT,
	APPL_C_PROF,
	APPL_PREFS,
	APPL_MODPROF,
	TIMER_CONTR_CAL,
	APPL_O_LISTB,
	APPL_O_LISTR,
	APPL_CALEND
};

static const wxChar * TITLE 	= _T("nClaendar");
static const wxChar * VERS 		= _T("0.1 early develop");
static const wxChar * AUTHOR1 	= _T("Ben");
static const wxChar * AUTHOR2 	= _T("Vighy");
static const wxChar * FILETYPES = _T("nClaendar Packages|*.ncl|"
									 "Zip files|*.zip|"
									 "All files|*.*");
