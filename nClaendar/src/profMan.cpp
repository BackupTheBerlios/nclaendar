/***************************************************************************
 *            profMan.cpp
 *
 *  Tue Oct 18 19:09:38 2005
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
 
#ifndef PROFMAN_CPP
#define PROFMAN_CPP

#include "profMan.h"



//------------------------------------------------------------------------------
//----- Classe profDial --------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------
				
inline profDial::profDial	(wxWindow * parent,containerDati & rep) 
							: wxDialog(parent,-1,
									   wxString(_T("Manage Profiles")),
									   wxDefaultPosition,wxSize(500,300),
									   wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
							, ilRep(rep)
							, elSelect(0) 
{
	
//	Creo il box dei profili
	listProf = new wxListBox	(this,P_M_LISTBOX,wxDefaultPosition,
								 wxDefaultSize,0,NULL,wxLB_SINGLE);
	
//	Inserisco gli utenti
//	listProf->Insert(wxString(_T("Utente 1")),0);
//	listProf->Insert(wxString(_T("Utente 2")),1);
//	listProf->Insert(wxString(_T("Utente 3")),2);
	Refr();
	
//	Creo glia tlri elementi della finestra
	linea = new wxStaticLine	(this,-1,wxDefaultPosition,wxSize(20,10));
	
	CloseButt = new wxButton	(this,P_M_CLOSE,wxString(_T("Close")),
								 wxDefaultPosition,wxSize(100,30));
	
//	Bottoni di manipolazione
	NProfButt =  new wxButton	(this,P_M_BUTT_NEW,wxString(_T("New Profile")),
								 wxDefaultPosition,wxSize(100,30));
    MProfButt =  new wxButton	(this,P_M_BUTT_MOD,wxString(_T("Modify Profile")),
								 wxDefaultPosition,wxSize(100,30));
    DProfButt =  new wxButton	(this,P_M_BUTT_DEL,wxString(_T("Delete Profile")),
								 wxDefaultPosition,wxSize(100,30));
	
//	Organizzazione dei sizer
    mainSizer = new wxBoxSizer	(wxHORIZONTAL);
	buttSizer = new wxBoxSizer	(wxVERTICAL);
    
    buttSizer->Add(CloseButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(linea,0,wxEXPAND,10);
	buttSizer->Add(NProfButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(MProfButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(DProfButt,0,wxALL | wxALIGN_CENTER,5);
    
	mainSizer->Add(listProf,1,wxEXPAND | wxALL,10);
	mainSizer->Add(buttSizer,0,wxEXPAND);
    
	SetAutoLayout(true);
	SetSizer(mainSizer);
}


//---------------- Funzioni manipolazione Eventi -------------------------------

inline void profDial::OnSelProf	(wxCommandEvent & event) {
	elSelect = listProf->GetSelection();
}

inline void profDial::OnDClicProf(wxCommandEvent & event) {
	elSelect = listProf->GetSelection();
	OnButtMod(event);
}

inline void profDial::OnExit	(wxCommandEvent & event) {
	Close(true);
}

inline void profDial::OnButtNew	(wxCommandEvent & event) {
	
}

inline void profDial::OnButtMod	(wxCommandEvent & event) {
	if (!listProf->IsEmpty()) {
		//modifica l'elemento riferito da elSelect
		Refr();
	}
}

inline void profDial::OnButtDel	(wxCommandEvent & event) {
	if (!listProf->IsEmpty()) {
		//elimina l'elemento riferito da elSelect
		Refr();
	}
}


//---------------- Funzioni di manipolazione -----------------------------------

inline void profDial::Refr	() {
	profVec iProf;
	ilRep.ottieniProf(iProf);
	profVec::const_iterator iter = iProf.begin();
	profVec::const_iterator fine = iProf.end();
	int count = 0;
	listProf->Clear();
	while (iter != fine) {
		listProf->Insert(wxString(_T(iter->GetNick().c_str())),count++);
		iter++;
	}
}



//------------------------------------------------------------------------------
//----- Classe profSwitch ------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------
				
inline profSwitch::profSwitch	(wxWindow * parent,const profVec & vectProf) 
								: wxDialog(parent,-1,
										   wxString(_T("Switch Profile")),
										   wxDefaultPosition,wxSize(500,300),
										   wxDEFAULT_DIALOG_STYLE | 
										   wxRESIZE_BORDER)
								, iProf(vectProf)
								, elSelect(0) 
{
//	Creo il box dei profili
	listProf = new wxListBox	(this,P_S_LISTBOX,wxDefaultPosition,
								 wxDefaultSize,0,NULL,wxLB_SINGLE);
	
//	Inserisco gli utenti
//	listProf->Insert(wxString(_T("Utente 1")),0);
//	listProf->Insert(wxString(_T("Utente 2")),1);
//	listProf->Insert(wxString(_T("Utente 3")),2);
	visualProfs();
	
//	Creo i Bottoni
	OkButt = new wxButton	(this,wxID_OK,wxString(_T("Ok")),
							 wxDefaultPosition,wxDefaultSize);
	
	CancButt = new wxButton	(this,wxID_CANCEL,wxString(_T("Cancel")),
							 wxDefaultPosition,wxDefaultSize);
	
	infoButt = new wxButton	(this,P_S_BUTT_INF,wxString(_T("Infos")),
							 wxDefaultPosition,wxDefaultSize);
	
//	Organizzazione dei sizer
    mainSizer = new wxBoxSizer	(wxVERTICAL);
	buttSizer = new wxBoxSizer	(wxHORIZONTAL);
	
	buttSizer->Add(OkButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(CancButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(infoButt,0,wxALL | wxALIGN_CENTER,5);
    
	mainSizer->Add(listProf,1,wxEXPAND | wxALL,10);
	mainSizer->Add(buttSizer,0,wxEXPAND);
    
	SetAutoLayout(true);
	SetSizer(mainSizer);
}


//---------------- Funzioni manipolazione Eventi -------------------------------

inline void profSwitch::OnSelProf	(wxCommandEvent & event) {
	elSelect = listProf->GetSelection();
}

inline void profSwitch::OnDClicProf	(wxCommandEvent & event) {
	elSelect = listProf->GetSelection();
	EndModal(wxID_OK);
}

inline void profSwitch::OnInfoButt	(wxCommandEvent & event) {
	if (!listProf->IsEmpty()) {
		_profile_ theOne = iProf[elSelect];
		wxString infos;
		infos.append(_T("infos about the profile you selected...."));
		wxMessageDialog theDial(this,infos,
            	        		_T("What about " + theOne.GetNick()),wxOK);
	}
}

//---------------- Funzioni manipolazione Oggetti ------------------------------

inline unsigned int profSwitch::GetElSel() {
	return elSelect;
}

inline void profSwitch::visualProfs() {
	profVec::const_iterator iter = iProf.begin();
	profVec::const_iterator fine = iProf.end();
	int count = 0;
	listProf->Clear();
	while (iter != fine) {
		listProf->Insert(wxString(_T(iter->GetNick().c_str())),count++);
		iter++;
	}
}

#endif
