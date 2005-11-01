/***************************************************************************
 *            hdCtrl.cpp
 *
 *  Wed Oct 26 20:34:55 2005
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
 
#ifndef HDCTRL_CPP
#define HDCTRL_CPP

#include "hdCtrl.h"

inline bool InitHD() {
//	controlla se c'è la directory dei dati e al max creala!!!
	wxStandardPaths ilPath;
	wxString userDataDir = ilPath.GetUserDataDir();
	return (wxFileName::DirExists(userDataDir) 
			? true 
			: wxFileName::Mkdir(userDataDir));
}

//------------------------------------------------------------------------------
//----- Classe outHD -----------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------

inline outHD::outHD() {
	wxStandardPaths ilPath;
	path = ilPath.GetUserDataDir().c_str();
	path.append(_T("/"));
}


//---------------- Funzioni Utili ----------------------------------------------

inline bool outHD::saveProgData(const progData &datas) {
	string fileName = path;
	fileName.append(_T("nclaend.conf"));
	theOut.open(fileName.c_str(),ios::out | ios::binary);
	if (theOut.fail())  {
		theOut.clear();
		return false;
	}
	//processo il file e estraggo i dati!
	theOut.write(reinterpret_cast<const char *>(&datas),sizeof(datas));
	theOut.close();
	return true;
}

inline bool outHD::saveProfs(const profVec &iProf) {
	string fileName = path;
	fileName.append(_T("profiles.index"));
	theOut.open(fileName.c_str(),ios::out | ios::binary);
	if (theOut.fail()) {
		theOut.clear();
		return false;
	}
	profVec::const_iterator iter = iProf.begin();
	profVec::const_iterator fine = iProf.end();
	while (theOut && (iter != fine)) {
		theOut.write(reinterpret_cast<const char *>(&(*iter)),sizeof(*iter));
		iter++;
	}
	theOut.close();
	return true;
}

inline void outHD::saveLog(const wxString & theLog) {
	string fileName = path.c_str();
	fileName.append(_T("logDi"));
	fileName.append(_T(_date_::Today().ToStdString()));
	fileName.append(_T("-"));
	fileName.append(_T(_time_::Now().ToStdString()));
	fileName.append(_T(".txt"));
	int cont = 0;
	const int fineCont = (int) theLog.Len();
	theOut.open(fileName.c_str(),ios::out);
	if (theOut.fail()) {
		wxMessageDialog aboutDialog(NULL,wxString(_T(fileName.c_str())),
									wxString(_T("About this Project")),wxOK);
		aboutDialog.ShowModal();
		theOut.clear();
		return ;
	}
	while (cont < fineCont) {
		theOut << theLog[cont];
		cont++;
	}
	theOut.close();
}

//------------------------------------------------------------------------------
//----- Classe inHD ------------------------------------------------------------

//---------------- Costruttori & Distruttori -----------------------------------

inline inHD::inHD() {
	wxStandardPaths ilPath;
	path = ilPath.GetUserDataDir().c_str();
	path.append(_T("/"));
}

//---------------- Funzioni Utili ----------------------------------------------

inline bool inHD::loadProgData(progData &datas) {
	string fileName = path;
	fileName.append(_T("nclaend.conf"));
	theIn.open(fileName.c_str(),ios::in | ios::binary);
	if (theIn.fail())  {
		theIn.clear();
		return false;
	}	// || (theIn.size() != sizeof(datas))
	theIn.read(reinterpret_cast<char *>(&datas),sizeof(datas));
	//processo il file e estraggo i dati!
	theIn.close();
	return true;
}

inline bool inHD::loadProfs(containerDati &ilCont) {
	string fileName = path;
	fileName.append(_T("profiles.index"));
	theIn.open(fileName.c_str(),ios::in | ios::binary);
	if (theIn.fail())  {
		theIn.clear();
		return false;
	}
	_profile_ temp;
	theIn.read(reinterpret_cast<char *>(&temp),sizeof(temp));
	while (theIn && !theIn.eof()) {
		ilCont.aggProf(temp);
		theIn.read(reinterpret_cast<char *>(&temp),sizeof(temp));
	}
	theIn.close();
	return true;
}


#endif
