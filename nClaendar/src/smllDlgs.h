/***************************************************************************
 *            smllDlgs.h
 *
 *  Fri Oct 21 19:27:25 2005
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
 

#ifndef SMLLDLGS_H
#define SMLLDLGS_H

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include "../src/tipi.cpp"
#include "../src/dataBlock.cpp"

class newApp : public wxDialog {
	wxStaticText * dblpoint;
	wxStaticText * indTime;
	wxStaticLine * linea;
	
	wxSpinCtrl * hour;
	wxSpinCtrl * min;
	wxCheckBox * imp;
	wxTextCtrl * what;
	
	wxButton * OkButt;
	wxButton * CancButt;
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	wxBoxSizer * timeSizer;	// 2°livello
public:
	newApp(wxWindow *);
	newApp(wxWindow *,const app_date &);
	
	_time_ 	 GetNewTimeApp() const;
	wxString GetNewStrApp() const;
	bool 	GetNewImpApp() const;
	app_date  GetNewApp() const;
};

class newRec : public wxDialog {
	wxStaticText * indPriority;
	
	wxSpinCtrl * prior;
	wxTextCtrl * what;
	
	wxButton * OkButt;
	wxButton * CancButt;
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	wxBoxSizer * timeSizer;	// 2°livello
public:
	newRec(wxWindow *);
	newRec(wxWindow *,const recurr_atom &);
	
	unsigned short int GetNewPriorRec() const;
	wxString GetNewStrRec() const;
};

class firsTimeToday : public wxThread {
	const containerDati & daCont;
	
	wxWindow * parent;
public:
	firsTimeToday(wxWindow *,const containerDati &);
	
	void *Entry();
};

#endif
