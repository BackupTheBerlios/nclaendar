/***************************************************************************
 *            genericDiskOps.cpp
 *
 *  Tue Mar 21 15:45:22 2006
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
 
#ifndef _GENERICDISKOPS_CPP
#define _GENERICDISKOPS_CPP

#include "genericDiskOps.h"

inline bool InitHD() {
//	controlla se c'è la directory dei dati e al max creala!!!
	wxStandardPaths ilPath;
	const wxString userDataDir = ilPath.GetUserDataDir();
	return (wxFileName::DirExists(userDataDir) 
			? true 
			: wxFileName::Mkdir(userDataDir));
}

inline bool removeReposFile(const wxString &name) {
	wxStandardPaths ilPath;
	const wxString path = (ilPath.GetUserDataDir() + _T("/"));
	return wxRemoveFile(path + name);
}

inline bool copyWxStrToWxCh(wxChar *Ch,const unsigned int lung,
							const wxString &St) 
{
	const unsigned int lungStr = St.Len();
	unsigned int cont = 0;
	while ((cont < lung) && (cont < lungStr)) {
		Ch[cont] = St[cont];
		cont++;
	}
	Ch[cont] = '\0';
	return true;
}

inline unsigned short int getVersion(const wxString &daString) {
	unsigned long versionNum, majorSubVersionNum, minorSubVersionNum;
	wxString::Format(_T("%c%c"),daString[0],daString[1])
		.ToULong(&versionNum);
	wxString::Format(_T("%c%c"),daString[3],daString[4])
		.ToULong(&majorSubVersionNum);
	wxString::Format(_T("%c%c"),daString[6],daString[7])
		.ToULong(&minorSubVersionNum);
	return (versionNum * 10000 + majorSubVersionNum * 100 + minorSubVersionNum);
}


#endif /* _GENERICDISKOPS_CPP */
