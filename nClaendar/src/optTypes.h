/***************************************************************************
 *            optTypes.h
 *
 *  Tue Jan 10 19:54:47 2006
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
 
#ifndef _OPTTYPES_H
#define _OPTTYPES_H

#include "../src/timeTypes.cpp"

struct progData {
	bool logAct,multiProf,impDayAlw;
	int defProf;
	_date_ lastTimeOpened;
	
	progData();
	progData & operator=  (const progData &);
};

struct searchOptions {
	bool appTit,appDes,recTit,recDes;
	
	unsigned short int fromHour,fromMin,fromPrior,toHour,toMin,toPrior;
};

#endif /* _OPTTYPES_H */
