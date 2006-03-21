/***************************************************************************
 *            timerTypes.cc
 *
 *  Tue Mar 21 14:55:10 2006
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
 

 
#ifndef _TIMERTYPES_CPP
#define _TIMERTYPES_CPP

#include "timerTypes.h"

//------------------------------------------------------------------------------
//----------- timer_base -------------------------------------------------------

//--------------- Construttors & Destruttors -----------------------------------

inline timer_base::timer_base (const unsigned int n_id) 
								: id(n_id) 
{
	
}


//------------------------------------------------------------------------------
//----------- timer_atom -------------------------------------------------------

//--------------- Construttors & Destruttors -----------------------------------

inline timer_atom::timer_atom (const unsigned int n_id) 
								: timer_base(n_id) 
{
	lastTime = false;
}


//------------------------------------------------------------------------------
//----------- timer_comm -------------------------------------------------------

//--------------- Construttors & Destruttors -----------------------------------

inline command_timer::command_timer (const unsigned int n_id) 
								: timer_base(n_id) 
{
	
}


#endif /* _TIMERTYPES_CPP */
