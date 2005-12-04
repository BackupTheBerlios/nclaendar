/***************************************************************************
 *            hdCtrl.h
 *
 *  Wed Oct 26 20:15:25 2005
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
 
#ifndef HDCTRL_H
#define HDCTRL_H

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/wfstream.h>
#include <wx/zipstrm.h>
#include "../src/tipi.cpp"
#include "../src/dataBlock.cpp"

// now leave at 1... then i will fix it to be larger
#define COPY_BUFFER_SIZE 	1

// if you modify this you will loose all your data saved before.
#define MAX_PROF_FIELDS_DIM 12

bool InitHD();
bool removeReposFile(const wxString &);
bool copyWxStrToWxCh(wxChar *,const unsigned int,const wxString &);


struct prof_to_disk {
	wxChar nick[MAX_PROF_FIELDS_DIM];
	wxChar name[MAX_PROF_FIELDS_DIM];
	wxChar surname[MAX_PROF_FIELDS_DIM];
	
	prof_to_disk ();
	prof_to_disk (const _profile_ &);
	void operator= (const _profile_ &);
};

struct app_to_disk {
	int year,month,day;
	int hour,min;
	wxChar descr[1024];
	
	void operator= (const _date_ &);
	void operator= (const app_date &);
};

struct rec_to_disk {
	int month,day;
	int priority;
	wxChar descr[500];
	
	void operator= (const _date_short &);
	void operator= (const recurr_atom &);
};


class outHD {
	const wxStandardPaths ilPath;
	const wxString path;
public:
	outHD();
	
	bool saveProfs	 (const profVec &);
	bool saveData	 (const wxString &who,const containerDati &repos);
	
	bool exportData	 (const wxString &where,const _profile_ &);
	
	bool saveProgData(const progData &);
	
	void saveLog	 (const wxString &);
};

class inHD {
	const wxStandardPaths ilPath;
	const wxString path;
public:
	inHD();
	
	bool loadProfs	 (containerDati &);
	bool loadData	 (const wxString &who,containerDati &repos);
	
	bool importData	 (const wxString &file,containerDati &repos);
	
	bool loadProgData(progData &);
};

static const wxChar 	sep 	= wxFileName::GetPathSeparator();
static const wxChar *	app_ext = _T(".app");
static const wxChar *	rec_ext = _T(".rec");

#endif
