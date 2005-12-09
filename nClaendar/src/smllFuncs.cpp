/***************************************************************************
 *            smllFuncs.cpp
 *
 *  Fri Dec  9 16:06:36 2005
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
 
 
#ifndef _SMLLFUNCS_CPP
#define _SMLLFUNCS_CPP

#include "../include/smllFuncs.h"


//------------------------------------------------------------------------------
//----- Classe firsTimeToday ---------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------


inline firsTimeToday::firsTimeToday (const containerDati &n_cont) 
	: daCont(n_cont) 
{
	
}

inline void *firsTimeToday::Entry() {
	const _date_ oggi = _date_::Today();
	wxString what = _T("Today there are these important things: \n");
	appVec allApps;
	daCont.obtainAppOfDay(allApps,oggi);
//	appVec impApps;
	appVec::const_iterator iterApp = allApps.begin();
	const appVec::const_iterator fineApp = allApps.end();
	while (iterApp != fineApp) {
		if (iterApp->IsImportant()) 
//			impApps.push_back(*iterApp);
			what.append((*iterApp).HeaderInWxString() + _T("\n"));
		iterApp++;
	}
	recVec allRecs;
	daCont.obtainRecOfDay(allRecs,(_date_short)oggi);
//	recVec impRecs;
	recVec::const_iterator iterRec = allRecs.begin();
	const recVec::const_iterator fineRec = allRecs.end();
	while (iterRec != fineRec) {
		if (iterRec->GetPriority() < 4) 
//			impRecs.push_back(*iterRec);
			what.append((*iterRec).HeaderInWxString() + _T("\n"));
		iterRec++;
	}
	
	return NULL;
}




#endif /* _SMLLFUNCS_CPP */
