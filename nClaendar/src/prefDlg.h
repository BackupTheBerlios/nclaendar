/***************************************************************************
 *            prefDlg.h
 *
 *  Fri Oct 28 23:37:06 2005
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
 
#ifndef PREFDLG_H
#define PREFDLG_H

#include <wx/wx.h>
#include <wx/checkbox.h>
#include "../src/tipi.cpp"

class prefDial : public wxDialog {
	progData & dProg;
	
	wxCheckBox * checkLog;
	wxCheckBox * checkMultiProf;
	
	wxButton * okButt,* cancButt;
	
	wxBoxSizer * mainSizer;	// 1°livello
	wxBoxSizer * buttSizer;	// 2°livello
	
//	DECLARE_EVENT_TABLE()
public:
	prefDial(wxWindow * parent,progData & dp);
	
	void OnExit		(wxCommandEvent & event);
	
	void ApplyChng();
};

#endif
