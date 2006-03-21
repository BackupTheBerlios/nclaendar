/***************************************************************************
 *            hdStructsTypes.cpp
 *
 *  Tue Mar 21 15:52:11 2006
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
 
#ifndef _HDSTRUCTSTYPES_CPP
#define _HDSTRUCTSTYPES_CPP

#include "hdStructsTypes.h"


//------------------------------------------------------------------------------
//----- Data structures --------------------------------------------------------


//------------------------------------------------------------------------------
//----- prof_to_disk -----------------------------------------------------------

inline prof_to_disk::prof_to_disk () {
	nick[0] = name[0] = surname[0] = _T('\0');
	day = month = year = 0;
}

inline prof_to_disk::prof_to_disk (const _profile_ &theProf) {
	copyWxStrToWxCh(nick,MAX_PROF_FIELDS_DIM,theProf.GetNick());
	copyWxStrToWxCh(name,MAX_PROF_FIELDS_DIM,theProf.GetName());
	copyWxStrToWxCh(surname,MAX_PROF_FIELDS_DIM,theProf.GetSurname());
	const _date_ tempDate = theProf.GetBirth();
	day = tempDate.GetDay();
	month = tempDate.GetMonth();
	year = tempDate.GetYear();
}

inline void prof_to_disk::operator= (const _profile_ &theProf) {
	copyWxStrToWxCh(nick,MAX_PROF_FIELDS_DIM,theProf.GetNick());
	copyWxStrToWxCh(name,MAX_PROF_FIELDS_DIM,theProf.GetName());
	copyWxStrToWxCh(surname,MAX_PROF_FIELDS_DIM,theProf.GetSurname());
	const _date_ tempDate = theProf.GetBirth();
	day = tempDate.GetDay();
	month = tempDate.GetMonth();
	year = tempDate.GetYear();
}
/*
inline prof_to_disk::operator _profile_() const {
	
	return _profile_
}*/


//------------------------------------------------------------------------------
//----- app_to_disk ------------------------------------------------------------

inline void app_to_disk::operator= (const _date_ &theDate) {
	year = theDate.GetYear();
	month = theDate.GetMonth();
	day = theDate.GetDay();
}

inline void app_to_disk::operator= (const app_date &theApp) {
	hour = theApp.GetWhen().GetHour();
	min = theApp.GetWhen().GetMin();
	imp = theApp.IsImportant();
	copyWxStrToWxCh(body,1024,theApp.GetBody());
	copyWxStrToWxCh(title,24,theApp.GetTitle());
}

inline app_to_disk::operator app_date() const {
	return app_date(_time_(hour,min),title,imp,body);
}

inline app_to_disk::operator _date_() const {
	return _date_(year,month,day);
}

inline void app_to_disk_000107::operator= (const _date_ &theDate) {
	year = theDate.GetYear();
	month = theDate.GetMonth();
	day = theDate.GetDay();
}

inline void app_to_disk_000107::operator= (const app_date &theApp) {
	hour = theApp.GetWhen().GetHour();
	min = theApp.GetWhen().GetMin();
	imp = theApp.IsImportant();
	copyWxStrToWxCh(body,1024,theApp.GetBody());
	copyWxStrToWxCh(title,24,theApp.GetTitle());
	copyWxStrToWxCh(command,128,theApp.GetComm());
}

inline app_to_disk_000107::operator app_date() const {
	return app_date(_time_(hour,min),title,imp,body,command);
}

inline app_to_disk_000107::operator _date_() const {
	return _date_(year,month,day);
}


//------------------------------------------------------------------------------
//----- rec_to_disk ------------------------------------------------------------

inline void rec_to_disk::operator= (const _date_short &theDate) {
	month = theDate.GetMonth();
	day = theDate.GetDay();
}

inline void rec_to_disk::operator= (const recurr_atom &theRec) {
	priority = theRec.GetPriority();
	copyWxStrToWxCh(title,24,theRec.GetTitle());
	copyWxStrToWxCh(body,500,theRec.GetBody());
}

inline rec_to_disk::operator _date_short() const {
	return _date_short(month,day);
}

inline rec_to_disk::operator recurr_atom() const {
	return recurr_atom(priority,title,body);
}

//------------------------------------------------------------------------------
//----- data_to_disk -----------------------------------------------------------

#if defined( COMPATIBILITY_OLD_DATATOHD )
inline old_data_to_disk::old_data_to_disk() {
	logAct = impDayAlw = false;
	multiProf = true;
	defProf = 0;
}

inline old_data_to_disk::old_data_to_disk(const progData &theData) {
	logAct = theData.logAct;
	multiProf = theData.multiProf;
	impDayAlw = theData.impDayAlw;
	defProf = theData.defProf;
	year = theData.lastTimeOpened.GetYear();
	month = theData.lastTimeOpened.GetMonth();
	day = theData.lastTimeOpened.GetDay();
}

inline void old_data_to_disk::operator= (const progData &theData) {
	logAct = theData.logAct;
	multiProf = theData.multiProf;
	impDayAlw = theData.impDayAlw;
	defProf = theData.defProf;
	year = theData.lastTimeOpened.GetYear();
	month = theData.lastTimeOpened.GetMonth();
	day = theData.lastTimeOpened.GetDay();
}

inline old_data_to_disk::operator progData () const {
	progData converted;
	converted.logAct = logAct;
	converted.multiProf = multiProf;
	converted.impDayAlw = impDayAlw;
	converted.defProf = defProf;
	converted.lastTimeOpened.SetYear(year);
	converted.lastTimeOpened.SetMonth(month);
	converted.lastTimeOpened.SetDay(day);
	return converted;
}
#endif

inline data_to_disk::data_to_disk() {
	preferences = nclPREFS_MULTIPROF;
	defProf = 0;
}

inline data_to_disk::data_to_disk(const progData &theData) {
	preferences = ( theData.logAct ? nclPREFS_SAVE_EVENTSLOG : 0 ) |
					( theData.multiProf ? nclPREFS_MULTIPROF : 0 ) |
					( theData.impDayAlw ? nclPREFS_IMPTHINGS_EVER : 0 );
	defProf = theData.defProf;
	year = theData.lastTimeOpened.GetYear();
	month = theData.lastTimeOpened.GetMonth();
	day = theData.lastTimeOpened.GetDay();
}

inline void data_to_disk::operator= (const progData &theData) {
	preferences = ( theData.logAct ? nclPREFS_SAVE_EVENTSLOG : 0 ) |
					( theData.multiProf ? nclPREFS_MULTIPROF : 0 ) |
					( theData.impDayAlw ? nclPREFS_IMPTHINGS_EVER : 0 );
	defProf = theData.defProf;
	year = theData.lastTimeOpened.GetYear();
	month = theData.lastTimeOpened.GetMonth();
	day = theData.lastTimeOpened.GetDay();
}

inline data_to_disk::operator progData () const {
	progData converted;
	converted.logAct = preferences & nclPREFS_SAVE_EVENTSLOG;
	converted.multiProf = preferences & nclPREFS_MULTIPROF;
	converted.impDayAlw = preferences & nclPREFS_IMPTHINGS_EVER;
	converted.defProf = defProf;
	converted.lastTimeOpened.SetYear(year);
	converted.lastTimeOpened.SetMonth(month);
	converted.lastTimeOpened.SetDay(day);
	return converted;
}


#endif /* _HDSTRUCTSTYPES_CPP */
