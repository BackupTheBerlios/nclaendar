/***************************************************************************
 *            config.h
 *
 *  Fri Feb 10 14:44:09 2006
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
 
#ifndef _CONFIG_H
#define _CONFIG_H

//----- File Handling ----------------------------------------------------------

//compatibility with versions from 0.1.6 and previous
#define COMPATIBILITY_OLD_DATATOHD

// now leave at 1... then i will fix it to be larger
#define COPY_BUFFER_SIZE 	1

// if you modify this you will loose all your data saved before.
#define MAX_PROF_FIELDS_DIM 12


//----- General Prefs ----------------------------------------------------------

#define USE_ALARMS_THREAD


//----- Event Types ------------------------------------------------------------

#define RESULT_EVENT_PARTICULAR


//----- Global Stuffs ----------------------------------------------------------

enum {
	APPL_EXPORT	= 	6000,
	APPL_IMPORT,
	APPL_INS_APP,
	APPL_DEL_APP,
	APPL_OBT_APP,
	APPL_MOD_APP,
	APPL_INS_REC,
	APPL_DEL_REC,
	APPL_MOD_REC,
	APPL_C_PROF,
	APPL_PREFS,
	APPL_MODPROF,
	TIMER_CONTR_CAL,
	APPL_O_LISTB,
	APPL_O_LISTR,
	APPL_CALEND,
	THREAD_IMP_THINGS,
	THREAD_ALARMS,
	THREAD_SEARCH,
	THREAD_FIND_DAYS
};

enum {
	nclPREFS_SAVE_EVENTSLOG	= 1,
	nclPREFS_MULTIPROF		= 2,
	nclPREFS_IMPTHINGS_EVER = 4,
};

#endif /* _CONFIG_H */
