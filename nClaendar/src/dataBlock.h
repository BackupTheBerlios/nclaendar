/***************************************************************************
 *            dataBlock.h
 *
 *  Wed Nov 23 23:26:03 2005
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
 
#ifndef _DATABLOCK_H
#define _DATABLOCK_H

#include "../src/tipi.cpp"

class containerDati {
	regApp ilRegistro;
	regProf iProfili;
	regRecurr leRicorr;
	
	unsigned int currProf;
public:
	containerDati();
	
//	funzioni di manipolazione delle ricorrenze
	bool addRec		(const _date_short &,const recurr_atom &);
	bool delRec		(const _date_short &,const recurr_atom &);
	bool delRec		(const _date_short &,unsigned int );
	bool modRec		(const _date_short &,const recurr_atom &,const recurr_atom &);
	void obtainRecOfDay	(recVec &,const _date_short&) const;
	recurr_atom obtRec	(const _date_short &,unsigned int ) const;
	
//	funzioni di manipolazione dei profili
	bool addProf	(const _profile_ &);
	bool delProf	(const wxString &);
	bool delProf	(unsigned int );
	bool delProf	(const _profile_ &);
	bool modProf	(const _profile_ &,const _profile_ &);
	void obtainProf	(profVec &ilVett) const;
	_profile_ obtainProf(unsigned int ) const;
	_profile_ obtainProf(const wxString &) const;
	unsigned int GetCurrProf	() const;
	void SetCurrProf(unsigned int );
	
//	funzioni x passare i dati alla struttura dati.
	bool delAppuntamento	(const _date_ &,const app_date &);
	bool addAppuntamento	(const _date_ &,const app_date &);
	bool modAppuntamento	(const _date_ &,const app_date &,const app_date &);
	void obtainAppOfDay		(appVec &ilVett,const _date_ &when) const;
	app_date obtainApp		(const _date_ &,unsigned int ) const;
	wxString obtainApp		(const _date_ &,const _time_ &) const;
	
	void clearProf	();
	bool profEmpty	() const;
	void clearApp	();
	bool appEmpty	() const;
	void clearRec	();
	bool recEmpty	() const;
//	algoritmi di ricerca
	
	friend class outHD;
};

#endif /* _DATABLOCK_H */
