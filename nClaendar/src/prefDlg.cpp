/***************************************************************************
 *            prefDlg.cpp
 *
 *  Fri Oct 28 23:38:20 2005
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
 

#ifndef PREFDLG_CPP
#define PREFDLG_CPP

#include "prefDlg.h"


//------------------------------------------------------------------------------
//----------- prefDial ---------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline prefDial::prefDial	(wxWindow * parent,progData & dp) 
							: wxDialog(parent,-1,
									   wxString(_T("Options")),
									   wxDefaultPosition,wxSize(300,200),
									   wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
							, dProg(dp)
{
	checkLog = new wxCheckBox	(this,-1,_T("Save log on exit"),
								 wxDefaultPosition,wxDefaultSize);
	checkLog->SetValue(dp.logAct);
	
	okButt = new wxButton	(this,wxID_OK,wxString(_T("Ok")),
							 wxDefaultPosition,wxDefaultSize);
	cancButt = new wxButton	(this,wxID_CANCEL,wxString(_T("Cancel")),
							 wxDefaultPosition,wxDefaultSize);
	
    mainSizer = new wxBoxSizer	(wxVERTICAL);
	buttSizer = new wxBoxSizer	(wxHORIZONTAL);
	
	buttSizer->Add(cancButt,0,wxALL | wxALIGN_CENTER,5);
	buttSizer->Add(okButt,0,wxALL | wxALIGN_CENTER,5);
	
	mainSizer->Add(checkLog,0,wxALL,1);
	mainSizer->Add(buttSizer,0,wxEXPAND);
	
	SetAutoLayout(true);
	SetSizer(mainSizer);
}


//--------------- Funzioni Utili -----------------------------------------------

inline void prefDial::ApplyChng() {
	dProg.logAct = checkLog->GetValue();
}


#endif
