/***************************************************************************
 *            optTypes.cpp
 *
 *  Tue Jan 10 19:55:53 2006
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
 

 
#ifndef _OPTTYPES_CPP
#define _OPTTYPES_CPP

#include "../include/optTypes.h"


//------------------------------------------------------------------------------
//----------- ProgData ---------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline progData::progData() {
	logAct = impDayAlw = false;
	multiProf = true;
	defProf = 0;
}

	
//--------------- Funzioni Utili -----------------------------------------------

inline progData & progData::operator=  (const progData &n_Data) {
	logAct = n_Data.logAct;
	multiProf = n_Data.multiProf;
	defProf = n_Data.defProf;
	lastTimeOpened = n_Data.lastTimeOpened;
	impDayAlw = n_Data.impDayAlw;
	return *this;
}

//------------------------------------------------------------------------------
//----------- searchOptions ----------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------





#endif /* _OPTTYPES_CPP */
