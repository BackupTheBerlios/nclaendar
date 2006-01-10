/***************************************************************************
 *            searchDlgs.h
 *
 *  Sun Jan  8 22:08:50 2006
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
 
#ifndef _SEARCHDLGS_H
#define _SEARCHDLGS_H

#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/listctrl.h>
#include "../include/dataStrcts.h"
#include "../src/optTypes.cpp"

class searchDlg : public wxDialog {
	const wxEvtHandler * workThread;
	
	wxStaticText * stFrom, * stTo, * dblpoint;
	
	wxTextCtrl * searchString;
	
	wxButton * searchButton;
	
	wxCheckBox * appTitle, * recTitle, * appDescr, * recDescr;
	
	wxSpinCtrl * fromHour, * toHour, * fromMin, * toMin, * fromPrior, * toPrior;
	
	wxListView * visualResults;
	
	wxBoxSizer * searchSizer, * mainSizer;
	wxStaticBoxSizer * appSizer, * recSizer, * timeSizer, * priorSizer;
	wxGridSizer * prefsSizer;
	
	void DrawNewItems();
	
	DECLARE_EVENT_TABLE()
public:
	searchDlg(wxWindow *,const wxEvtHandler *);
	
	void OnButtSearch	(wxCommandEvent & event);
//	void OnSearchRes	( & event);
};

#endif /* _SEARCHDLGS_H */
