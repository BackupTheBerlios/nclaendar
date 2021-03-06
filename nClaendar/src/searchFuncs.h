/***************************************************************************
 *            searchFuncs.h
 *
 *  Wed Jan 11 23:06:37 2006
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
 
#ifndef _SEARCHFUNCS_H
#define _SEARCHFUNCS_H

#include <wx/thread.h>
#include "evtTypes.h"
#include "../src/dataBlock.cpp"

class searchCentral : public wxThread , public wxEvtHandler {
	const containerDati & daCont;
	
	wxEvtHandler * daGUI;
	const int id;
	
	DECLARE_EVENT_TABLE()
public:
	searchCentral(wxWindow *,const int ,const containerDati &);
	
	void *Entry();
	
	void OnAskSearch (wxAskForFindEvent & event);
};

#endif /* _SEARCHFUNCS_H */
