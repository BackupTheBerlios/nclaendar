/***************************************************************************
 *            evtTypes.h
 *
 *  Sun Dec 11 15:03:30 2005
 *  Copyright  2005  Ben
 *  eanvighy (at) libero.it
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
 
#ifndef _EVTTYPES_H
#define _EVTTYPES_H

#include <wx/wx.h>
#include <wx/event.h>
/*
// Maybe i will never use this class... 
class wxReturnStringEvent : public wxCommandEvent {
	const wxString daString;
public:
	wxReturnStringEvent (const wxString n_str = _T(""),
						 wxEventType commandType = wxEVT_NULL,
						 int id = 0)
						: wxCommandEvent (commandType,id) 
						, daString(n_str) { }
	wxReturnStringEvent (const wxReturnStringEvent& event)
						: wxCommandEvent(event) 
						, daString(event.GetString()) {}
	
	virtual wxEvent *Clone() const 
		{ return new wxReturnStringEvent(*this); }
	
	wxString GetDaString() const
		{ return daString; }
};*/

BEGIN_DECLARE_EVENT_TYPES()
	DECLARE_EVENT_TYPE(wxEVT_COMMAND_STRING_RETURNED, -1) 
END_DECLARE_EVENT_TYPES() 

/*typedef void (wxEvtHandler::*wxReturnStringEventFunction) 
				(wxReturnStringEvent&); */
/*
#define EVT_STRING_RETURNED(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( wxEVT_COMMAND_STRING_RETURNED, id, -1, \
    (wxObjectEventFunction) (wxEventFunction) (wxCommandEventFunction) \
    wxStaticCastEvent( wxReturnStringEventFunction, & fn ), (wxObject *) NULL ),
*/
#endif /* _EVTTYPES_H */
