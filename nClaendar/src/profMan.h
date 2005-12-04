/***************************************************************************
 *            profMan.h
 *
 *  Tue Oct 18 19:08:58 2005
 *  Copyright  2005  Ben
 *  eanvighy(at)libero.it
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
 
#ifndef PROFMAN_H
#define PROFMAN_H

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include "../src/tipi.cpp"
#include "../src/hdCtrl.cpp"

class profDial : public wxDialog {
	containerDati & ilRep;
	
	wxListBox * listProf;
	
	unsigned int elSelect;
	
	wxStaticLine * linea;
	wxButton * CloseButt;
	
//	Bottoni di gestione degli utenti
	wxButton * NProfButt;	//Button to create a new Profile
	wxButton * MProfButt;	//Button to modify a Profile
	wxButton * DProfButt;	//Button to delete a Profile
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	
//	Funzioni di manipolazione
	void Refr	();
	
	DECLARE_EVENT_TABLE()
public:
	profDial(wxWindow *,containerDati &);
	
	void OnSelProf	(wxCommandEvent & event);
	void OnDClicProf(wxCommandEvent & event);
	void OnExit		(wxCommandEvent & event);
	void OnButtNew	(wxCommandEvent & event);
	void OnButtMod	(wxCommandEvent & event);
	void OnButtDel	(wxCommandEvent & event);
};

class profSwitch : public wxDialog {
	const profVec &iProf;
	
	wxListBox * listProf;
	
	unsigned int elSelect;
	
	wxButton * OkButt;
	wxButton * CancButt;
	wxButton * infoButt;
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	
	void visualProfs();
	
	DECLARE_EVENT_TABLE()
public:
	profSwitch(wxWindow *,const profVec &);
	
	unsigned int GetElSel();
	
	void OnSelProf	(wxCommandEvent & event);
	void OnDClicProf(wxCommandEvent & event);
	void OnInfoButt	(wxCommandEvent & event);
};

class NMProf : public wxDialog {
	_profile_ & theProf;
	
	wxButton * OkButt;
	wxButton * CancButt;
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	wxBoxSizer * lblsSizer; // 2°livello
	wxStaticBoxSizer * persSizer; // 3°livello
	wxBoxSizer * nickSizer; // 4°livello
	wxBoxSizer * nameSizer; // 4°livello
	wxBoxSizer * surnSizer; // 4°livello
	
	wxTextCtrl * txtNick;
	wxStaticText * sTxtNick;
	wxTextCtrl * txtName;
	wxTextCtrl * txtSurname;
	
	wxStaticText * lblNick;
	wxStaticText * lblName;
	wxStaticText * lblSurname;
	
//	DECLARE_EVENT_TABLE()
public:
	NMProf(wxWindow *,_profile_ &);
	
	void ApplyChng();
};


enum {
	P_M_LISTBOX 	= 	wxID_HIGHEST + 1,
	P_M_CLOSE,
	P_M_BUTT_NEW,
	P_M_BUTT_MOD,
	P_M_BUTT_DEL,
	P_S_LISTBOX,
	P_S_BUTT_INF
};

static const wxChar * NPROF = _T("Nuovo Profilo");
static const wxChar * MPROF = _T("Modifica Profilo");

#endif
