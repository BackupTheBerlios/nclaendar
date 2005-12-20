/***************************************************************************
 *            dataStrcts.cpp
 *
 *  Tue Dec 20 17:08:18 2005
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
 

#ifndef _DATASTRCTS_CPP
#define _DATASTRCTS_CPP

#include "../include/dataStrcts.h"

#if defined(USE_WX_APPVEC) || defined(USE_WX_RECVEC) || defined(USE_WX_PRFVEC)
	#include <wx/arrimpl.cpp>
#endif

#ifdef USE_WX_APPVEC
	WX_DEFINE_OBJARRAY(appVec);
#endif

#ifdef USE_WX_PRFVEC
	WX_DEFINE_OBJARRAY(profVec);
#endif

#ifdef USE_WX_RECVEC
	WX_DEFINE_OBJARRAY(recVec);
#endif


#endif /* _DATASTRCTS_CPP */
