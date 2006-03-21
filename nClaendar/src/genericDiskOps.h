/***************************************************************************
 *            genericDiskOps.h
 *
 *  Tue Mar 21 15:44:26 2006
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
 
#ifndef _GENERICDISKOPS_H
#define _GENERICDISKOPS_H

#include <wx/string.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/wfstream.h>

bool InitHD();
bool removeReposFile(const wxString &);
bool copyWxStrToWxCh(wxChar *,const unsigned int,const wxString &);
unsigned short int getVersion(const wxString &);

namespace files_ext {
	static const wxChar *	data_ext = _T(".data");
};

#endif /* _GENERICDISKOPS_H */
