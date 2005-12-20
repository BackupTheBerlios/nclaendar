/***************************************************************************
 *            dataStrcts.h
 *
 *  Fri Dec 16 15:01:28 2005
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
 
#ifndef _DATASTRCTS_H
#define _DATASTRCTS_H

#include "../src/tipi.cpp"

//#define USE_REC_MULTISET
#define USE_WX_APPVEC
#define USE_WX_RECVEC
#define USE_WX_PRFVEC

#if defined(USE_WX_APPVEC) && defined(USE_WX_RECVEC) && defined(USE_WX_PRFVEC)
	#include <wx/dynarray.h>
#else
  #include <vector>
  #if defined(USE_WX_APPVEC) || defined(USE_WX_RECVEC) || defined(USE_WX_PRFVEC)
    #include <wx/dynarray.h>
  #endif
#endif //possibility to not even include <vector>

#include <map>
#include <set>
using namespace std;

//	strutture dati della STL
typedef set< app_date	 , less< app_date > > giorno;
typedef map< _date_ 	 , giorno ,		less< _date_ > > regApp;
typedef set< _profile_ 	 , less< _profile_ > > 	 regProf;
#ifndef USE_REC_MULTISET
	typedef set< recurr_atom , less< recurr_atom > > rec_day;
#else
	typedef multiset< recurr_atom , less< recurr_atom > > rec_day;
#endif
typedef map< _date_short , rec_day > 	regRecurr;

#ifndef USE_WX_APPVEC
	typedef vector< app_date > 	appVec;
#else
	WX_DECLARE_OBJARRAY(app_date, appVec);
#endif

#ifndef USE_WX_PRFVEC
	typedef vector< _profile_ > profVec;
#else
	WX_DECLARE_OBJARRAY(_profile_, profVec);
#endif

#ifndef USE_WX_RECVEC
	typedef vector< recurr_atom > recVec;
#else
	WX_DECLARE_OBJARRAY(recurr_atom, recVec);
#endif


#endif /* _DATASTRCTS_H */
