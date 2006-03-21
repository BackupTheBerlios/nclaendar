/***************************************************************************
 *            hdStructsTypes.h
 *
 *  Tue Mar 21 15:49:02 2006
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
 
#ifndef _HDSTRUCTSTYPES_H
#define _HDSTRUCTSTYPES_H

#include "config.h"
#include "dataBlock.cpp"
#include "optTypes.cpp"
#include "genericDiskOps.cpp"

struct prof_to_disk {
	wxChar nick[MAX_PROF_FIELDS_DIM];
	wxChar name[MAX_PROF_FIELDS_DIM];
	wxChar surname[MAX_PROF_FIELDS_DIM];
	unsigned short int day,month,year;
	
	prof_to_disk ();
	prof_to_disk (const _profile_ &);
	void operator= (const _profile_ &);
//	operator _profile_() const;
};

struct app_to_disk {
	int year,month,day;
	int hour,min;
	bool imp;
	wxChar title[24];
	wxChar body[1024];
	
	void operator= (const _date_ &);
	void operator= (const app_date &);
	operator app_date() const;
	operator _date_() const;
};

struct app_to_disk_000107 {
	int year,month,day;
	int hour,min;
	bool imp;
	wxChar title[24];
	wxChar body[1024];
	wxChar command[128];
	
	void operator= (const _date_ &);
	void operator= (const app_date &);
	operator app_date() const;
	operator _date_() const;
};

struct rec_to_disk {
	int month,day;
	int priority;
	wxChar title[24];
	wxChar body[500];
	
	void operator= (const _date_short &);
	void operator= (const recurr_atom &);
	operator _date_short() const;
	operator recurr_atom() const;
};

#if defined( COMPATIBILITY_OLD_DATATOHD )
struct old_data_to_disk {
	bool logAct,multiProf,impDayAlw;
	int defProf;
	int year,month,day;
	
	old_data_to_disk ();
	old_data_to_disk (const progData &);
	void operator= (const progData &);
	operator progData() const;
};
#endif

struct data_to_disk {
	unsigned int preferences;
	int defProf;
	int year,month,day;
	
	data_to_disk ();
	data_to_disk (const progData &);
	void operator= (const progData &);
	operator progData() const;
};


#endif /* _HDSTRUCTSTYPES_H */
