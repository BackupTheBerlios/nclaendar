/***************************************************************************
 *            searchFuncs.cpp
 *
 *  Wed Jan 11 23:18:23 2006
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
 

#ifndef _SEARCHFUNCS_CPP
#define _SEARCHFUNCS_CPP

#include "../include/searchFuncs.h"



//------------------------------------------------------------------------------
//----- Class  searchCentral ---------------------------------------------------

//---------------- Construttors & Destruttors ----------------------------------

inline searchCentral::searchCentral	( wxWindow *parent , const int n_id ,
									  const containerDati &n_cont )
									: daCont( n_cont ) , id( n_id ) 
{
	daGUI = (wxEvtHandler *) parent;
	
}


//---------------- Handling Functions ------------------------------------------

inline void *searchCentral::Entry() {
	while ( !TestDestroy() ) Sleep( 333 );
	return NULL;
}


//---------------- Event Handling Functions ------------------------------------

inline void searchCentral::OnAskSearch (wxAskForFindEvent & event) {
}

#endif /* _SEARCHFUNCS_CPP */
