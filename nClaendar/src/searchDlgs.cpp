/***************************************************************************
 *            searchDlgs.cpp
 *
 *  Sun Jan  8 22:11:59 2006
 *  Copyright  2006  Ben
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
 
 
#ifndef _SEARCHDLGS_CPP
#define _SEARCHDLGS_CPP

#include "../include/searchDlgs.h"


//------------------------------------------------------------------------------
//----------- searchDlg --------------------------------------------------------

//--------------- Construttors & Destruttors -----------------------------------

inline searchDlg::searchDlg	(wxWindow *parent,const wxEvtHandler *n_wThread) 
							: wxDialog (parent,-1,_T("Search through the data"),
									wxDefaultPosition,wxDefaultSize,
									wxDEFAULT_DIALOG_STYLE |  wxRESIZE_BORDER)
							, workThread( n_wThread )
{
	searchButton = new wxButton  (this,wxID_FIND,_T("Search"));
	
	searchString = new wxTextCtrl(this,-1,_T(""));
	
	appTitle	= new wxCheckBox (this,-1,_T("Title"));
	recTitle	= new wxCheckBox (this,-1,_T("Title"));
	appDescr	= new wxCheckBox (this,-1,_T("Description"));
	recDescr	= new wxCheckBox (this,-1,_T("Description"));
	
	stFrom	 = new wxStaticText	(this,-1,_T("From: "));
	stTo	 = new wxStaticText	(this,-1,_T(" To: "));
	dblpoint = new wxStaticText	(this,-1,_T(":"));
	
	fromHour  = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,23);
	fromMin   = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,59);
	fromPrior = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,10);
	toHour    = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,23);
	toMin     = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,59);
	toPrior   = new wxSpinCtrl (this,-1,_T(""),wxDefaultPosition,wxSize(40,20),
							 wxSP_ARROW_KEYS,0,10);
	
	visualResults = new wxListView (this,wxID_VIEW_LIST,wxDefaultPosition,
								wxDefaultSize,wxLC_REPORT | wxLC_SINGLE_SEL);
	
    mainSizer	= new wxBoxSizer (wxVERTICAL);
	searchSizer	= new wxBoxSizer (wxHORIZONTAL);
	appSizer 	= new wxStaticBoxSizer (wxVERTICAL,this,_T("Appointments"));
	recSizer	= new wxStaticBoxSizer (wxVERTICAL,this,_T("Recurrencies"));
	timeSizer	= new wxStaticBoxSizer (wxHORIZONTAL,this,_T("Time of the "
															"Appintment"));
	priorSizer	= new wxStaticBoxSizer (wxHORIZONTAL,this,_T("Priority of the "
															"recurrency"));
	prefsSizer	= new wxGridSizer (2,2,0,0);
	
	searchSizer->Add(searchButton,0,wxALIGN_LEFT);
	searchSizer->Add(searchString,0,wxEXPAND | wxALL);
	
	appSizer->Add(appTitle	,0,wxALIGN_LEFT);
	appSizer->Add(appDescr	,0,wxALIGN_LEFT);
	
	recSizer->Add(recTitle	,0,wxALIGN_LEFT);
	recSizer->Add(recDescr	,0,wxALIGN_LEFT);
	
	timeSizer->Add(stFrom	,0,wxALIGN_LEFT);
	timeSizer->Add(fromHour	,0,wxALIGN_LEFT);
	timeSizer->Add(dblpoint	,0,wxALIGN_LEFT);
	timeSizer->Add(fromMin	,0,wxALIGN_LEFT);
	timeSizer->Add(stTo		,0,wxALIGN_LEFT);
	timeSizer->Add(toHour	,0,wxALIGN_LEFT);
	timeSizer->Add(dblpoint	,0,wxALIGN_LEFT);
	timeSizer->Add(toMin	,0,wxALIGN_LEFT);
	
	priorSizer->Add(stFrom	,0,wxALIGN_LEFT);
	priorSizer->Add(fromPrior,0,wxALIGN_LEFT);
	priorSizer->Add(stTo	,0,wxALIGN_LEFT);
	priorSizer->Add(toPrior	,0,wxALIGN_LEFT);
	
	prefsSizer->Add(appSizer);
	prefsSizer->Add(recSizer);
	prefsSizer->Add(timeSizer);
	prefsSizer->Add(priorSizer);
	
	mainSizer->Add(searchSizer	,0,wxEXPAND | wxALL,5);
	mainSizer->Add(prefsSizer	,0,wxEXPAND | wxALL,5);
	mainSizer->Add(visualResults,1,wxEXPAND| wxALL,5);
	
	SetAutoLayout(true);
	SetSizer(mainSizer);
	
	mainSizer->Fit(this); //ridimensionano il frame alle dim degli obj contenuti
	mainSizer->SetSizeHints(this);
}


inline void searchDlg::OnButtSearch	(wxCommandEvent & event) {
	searchOptions theOptions;
	
	theOptions.appTit = appTitle->GetValue();
	theOptions.appDes = appDescr->GetValue();
	theOptions.recTit = recTitle->GetValue();
	theOptions.recDes = recDescr->GetValue();
	
	theOptions.fromHour	= fromHour	->GetValue();
	theOptions.fromMin	= fromMin	->GetValue();
	theOptions.fromPrior= fromPrior	->GetValue();
	theOptions.toHour	= toHour	->GetValue();
	theOptions.toMin	= toMin		->GetValue();
	theOptions.toPrior	= toPrior	->GetValue();
	
//	workThread->AddPendingEvent( );
}

#endif /* _SEARCHDLGS_CPP */
