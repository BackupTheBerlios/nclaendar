/***************************************************************************
 *            timerTypes.h
 *
 *  Tue Mar 21 14:54:33 2006
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
 
#ifndef _TIMERTYPES_H
#define _TIMERTYPES_H

#include <wx/timer.h>
#include <wx/string.h>

struct timer_base {
	const unsigned int id;
	wxString theTitle;
	wxTimer theTimer;
	
	timer_base(const unsigned int);
};

struct timer_atom : timer_base {
	bool lastTime;
	
	timer_atom(const unsigned int);
};

struct command_timer : timer_base {
	wxString comm;
	
	command_timer(const unsigned int);
};

#endif /* _TIMERTYPES_H */
