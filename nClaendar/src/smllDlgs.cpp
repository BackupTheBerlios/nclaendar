/***************************************************************************
 *            smllDlgs.cpp
 *
 *  Fri Oct 21 19:42:27 2005
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
 
#ifndef SMLLDLGS_CPP
#define SMLLDLGS_CPP

#include "smllDlgs.h"


//------------------------------------------------------------------------------
//----- Classe chngStrApp ------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------
				
inline chngStrApp::chngStrApp	(wxWindow * parent,const wxString &strApp)
								: wxDialog (parent,-1,
											wxString(_T("Change description")),
											wxDefaultPosition,wxSize(350,120),
											wxDEFAULT_DIALOG_STYLE)
{
	what = new wxTextCtrl	(this,-1,strApp,
							 wxDefaultPosition,
							 wxDefaultSize,wxTE_MULTILINE);
	
	
//	Creo i Bottoni
	OkButt = new wxButton	(this,wxID_OK,wxString(_T("Ok")),
							 wxDefaultPosition,wxDefaultSize);
	
	CancButt = new wxButton	(this,wxID_CANCEL,wxString(_T("Cancel")),
							 wxDefaultPosition,wxDefaultSize);
	
//	Organizzazione dei sizer
    mainSizer = new wxBoxSizer	(wxVERTICAL);
	buttSizer = new wxBoxSizer	(wxHORIZONTAL);
	
	buttSizer->Add(OkButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(CancButt,0,wxALL | wxALIGN_CENTER,5);
    
	mainSizer->Add(what,1,wxALL | wxEXPAND,5);
	mainSizer->Add(buttSizer,0,wxEXPAND);
    
	SetAutoLayout(true);
	SetSizer(mainSizer);
}

//---------------- Funzioni Utili ----------------------------------------------

inline wxString chngStrApp::GetNewStrApp() const {
	return what->GetValue();
}


//------------------------------------------------------------------------------
//----- Classe chngStrApp ------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------

inline newApp::newApp	(wxWindow *parent)
						: wxDialog (parent,-1,
									wxString(_T("Insert a new Date")),
									wxDefaultPosition,
									wxSize(350,200),wxDEFAULT_DIALOG_STYLE)
{
	hour = new wxSpinCtrl	(this,-1,"",wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,23);
	min  = new wxSpinCtrl	(this,-1,"",wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,59);
	what = new wxTextCtrl	(this,-1,"",wxDefaultPosition,
							 wxDefaultSize,wxTE_MULTILINE);
	
	dblpoint = new wxStaticText	(this,-1,wxString(_T(":")),
								 wxDefaultPosition,wxSize(5,20));
	indTime  = new wxStaticText	(this,-1,wxString(_T("Time when it starts:")),
								 wxDefaultPosition,wxSize(125,20));
	
//	Creo i Bottoni
	OkButt = new wxButton	(this,wxID_OK,wxString(_T("Ok")),
							 wxDefaultPosition,wxDefaultSize);
	
	CancButt = new wxButton	(this,wxID_CANCEL,wxString(_T("Cancel")),
							 wxDefaultPosition,wxDefaultSize);
	
//	Organizzazione dei sizer
    mainSizer = new wxBoxSizer	(wxVERTICAL);
	buttSizer = new wxBoxSizer	(wxHORIZONTAL);
	timeSizer = new wxBoxSizer	(wxHORIZONTAL);
	
	timeSizer->Add(indTime,0,wxALL | wxALIGN_CENTER,5);
	timeSizer->Add(hour,0,wxALL | wxALIGN_CENTER,1);
	timeSizer->Add(dblpoint,0,wxALL | wxALIGN_CENTER,0);
	timeSizer->Add(min,0,wxALL | wxALIGN_CENTER,1);
	
	buttSizer->Add(OkButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(CancButt,0,wxALL | wxALIGN_CENTER,5);
    
	mainSizer->Add(timeSizer,0,wxALL | wxALIGN_CENTER,0);
	mainSizer->Add(what,1,wxALL | wxEXPAND,5);
	mainSizer->Add(buttSizer,0,wxEXPAND);
    
	SetAutoLayout(true);
	SetSizer(mainSizer);
}



//---------------- Funzioni Utili ----------------------------------------------

inline _time_ newApp::GetNewTimeApp() const {
	return _time_(hour->GetValue(),min->GetValue());
}

inline wxString newApp::GetNewStrApp() const {
	return what->GetValue();
}

#endif
