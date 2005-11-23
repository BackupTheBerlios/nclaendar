/***************************************************************************
 *            dataBlock.cpp
 *
 *  Wed Nov 23 23:28:24 2005
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
 
#ifndef _DATABLOCK_CPP
#define _DATABLOCK_CPP

#include "dataBlock.h"

//------------------------------------------------------------------------------
//----------- ContainerDati ----------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline containerDati::containerDati() : currProf(0) {
}

//--------------- Funzioni Utili -----------------------------------------------

inline void containerDati::obtainAppOfDay (appVec &ilVett,const _date_ &when) const {
	const regApp::const_iterator result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {//recupera gli appuntamenti del gg indicato
		giorno::const_iterator iter = (result->second.begin());
		const giorno::const_iterator fine = (result->second.end());
		const app_date nullo;
		ilVett.resize(result->second.size(),nullo);
		unsigned int cont = 0;
		while (iter != fine) {
			#ifndef SPERIM_SET_NOMAP
			ilVett[cont++] = pair< _time_ , wxString >(iter->first,iter->second);
			#else
			ilVett[cont++] = *iter;
			#endif
			iter++;
		}
	}
}

inline bool containerDati::addAppuntamento (const _date_ &when,const app_date &theDate) {
	const regApp::iterator result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {
		#ifndef SPERIM_SET_NOMAP
		//esiste un giorno vediamo se esiste un appuntamente x quell'ora.
		const giorno::const_iterator result2 = result->second.find(theDate.GetWhen());
		if (result2 != result->second.end()) 
			return false;		//se esiste giÃâ  l'appuntamento esco e segnalo
		const pair< giorno::const_iterator , bool > ret
			= result->second.insert( giorno::value_type( theDate.GetWhen(),
														 theDate.GetWhat() )); 
		#else
		const pair< giorno::const_iterator , bool > ret
			= result->second.insert(theDate);
		#endif
		return ret.second;
	} else {
		#ifndef SPERIM_SET_NOMAP
		giorno aux; //se nn esiste il giorno lo inserisco
		aux.insert(giorno::value_type(theDate.GetWhen(),theDate.GetWhat()));
		const pair< regApp::const_iterator , bool > ret
							= ilRegistro.insert(regApp::value_type(when,aux));
		#else
		giorno aux;
		aux.insert(theDate);
		const pair< regApp::const_iterator , bool > ret
			= ilRegistro.insert(regApp::value_type(when,aux));
		#endif
		return ret.second;
	}
}

#ifndef SPERIM_SET_NOMAP
inline void containerDati::modAppuntamento (const _date_ &when,const app_date &theDate) {
	ilRegistro[when][theDate.GetWhen()] = theDate.GetWhat();
}
#else
inline bool containerDati::modAppuntamento (const _date_ &when,const app_date &vecchio,
											const app_date &nuovo) {
	const giorno::iterator iter = ilRegistro[when].find(vecchio);
	if (iter != ilRegistro[when].end()) {
		const pair< giorno::const_iterator , bool > res 
			= ilRegistro[when].insert(nuovo);
		if (res.second) ilRegistro[when].erase(iter);
		return res.second;
	} return false;
}
#endif

#ifndef SPERIM_SET_NOMAP
inline wxString containerDati::obtainApp (const _date_ &day,const _time_ &time) {
	return ilRegistro[day][time];
}
#else
inline wxString containerDati::obtainApp (const _date_ &day,const _time_ &time) const {
	const regApp::const_iterator theDay = ilRegistro.find(day);
	giorno::const_iterator iter = theDay->second.begin();
	const giorno::const_iterator fine = theDay->second.end();
	while ((iter != fine) && (iter->GetWhen() == time)) 
		iter++;
	if (iter != fine) 
		return iter->GetWhat();
	return wxString("");
}
#endif

inline app_date containerDati::obtainApp (const _date_ &day,unsigned int num) const {
	const regApp::const_iterator result = ilRegistro.find(day);
	if (result != ilRegistro.end()) {
		giorno::const_iterator iter = result->second.begin();
		const giorno::const_iterator fine = result->second.end();
		while (num && (iter != fine)) {
			iter++;
			num--;
		}
		if (iter != fine) {
			#ifndef SPERIM_SET_NOMAP
			return app_date(iter->first,iter->second);
			#else
			return app_date(*iter);
			#endif
		}
	} return app_date();
}

inline bool containerDati::delAppuntamento	(const _date_ &when,const app_date &theDate) {
	const regApp::iterator iter = ilRegistro.find(when);
	if (iter != ilRegistro.end()) {
		#ifndef SPERIM_SET_NOMAP
		const giorno::iterator result2 = iter->second.find(theDate.GetWhen());
		if (result2 != iter->second.end()) {
			if (iter->second.size() > 1) {
				//esiston altri app... elimina solo questo
				iter->second.erase(result2);
			} else {
				//elimina tt il ramo se nn c sn altri app
				ilRegistro.erase(iter);
			}
			return true;
		}
		#else
		const giorno::iterator result2 = iter->second.find(theDate);
		if (result2 != iter->second.end()) {
			if (iter->second.size() > 1) {
				//esiston altri app... elimina solo questo
				iter->second.erase(result2);
			} else {
				//elimina tt il ramo se nn c sn altri app
				ilRegistro.erase(iter);
			}
			return true;
		}
		#endif
	}
	return false;
}

inline _profile_ containerDati::obtainProf (unsigned int num) const {
	regProf::const_iterator iter = iProfili.begin();
	const regProf::const_iterator fine = iProfili.end();
	if ((iter != iProfili.end()) && (num >= 0)) {
		while ((iter != fine) && (num)) {
			iter++;
			num--;
		}
		return *iter;
	} else {
		_profile_ ret;
		return ret;
	}
}

inline _profile_ containerDati::obtainProf(const wxString &who) const {
	regProf::const_iterator iter = iProfili.begin();
	const regProf::const_iterator fine = iProfili.end();
	while ((iter != fine) && (iter->GetNick() != who)) iter++;
	if (iter != fine) {
		return *iter;
	} return _profile_();
}

inline void containerDati::obtainProf(profVec &ilVett) const {
	ilVett.resize(iProfili.size(),_profile_());
	copy(iProfili.begin(),iProfili.end(),ilVett.begin());
}

inline bool containerDati::addProf(const _profile_ &n_prof) {
	const pair< regProf::const_iterator , bool > ret = iProfili.insert(n_prof);
	return ret.second;
}

inline bool containerDati::delProf(const wxString &del_nick) {
	regProf::iterator iter = iProfili.begin();
	const regProf::const_iterator fine = iProfili.end();
	while ((iter != fine) && (iter->GetNick() != del_nick)) iter++;
	if (iter != fine) {
		iProfili.erase(iter);
		return true;
	} return false;
}

inline bool containerDati::delProf(unsigned int pos) {
	regProf::iterator iter = iProfili.begin();
	const regProf::const_iterator fine = iProfili.end();
	while ((iter != fine) && pos) {
		pos--;
		iter++;
	}
	if (iter != fine) {
		iProfili.erase(iter);
		return true;
	} return false;
}

inline bool containerDati::delProf(const _profile_ &del_prof) {
	regProf::iterator iter = iProfili.find(del_prof);
	if (iter != iProfili.end()) {
		iProfili.erase(iter);
		return true;
	} return false;
}

inline bool containerDati::modProf(const _profile_ &vecchio,const _profile_ &sostit) {
	const regProf::iterator result = iProfili.find(vecchio);
	if (result != iProfili.end()) {
		//prima d tutto bisogna recuperare i riferimenti ai dati poi si puÃ² elim
		const pair< regProf::const_iterator , bool > ret = iProfili.insert(sostit);
		if (ret.second) iProfili.erase(result);
		return ret.second;
	} return false;
}

inline unsigned int containerDati::GetCurrProf () const {
	return currProf;
}

inline void containerDati::SetCurrProf(unsigned int nCurrProf) {
	currProf = nCurrProf;
}

inline bool containerDati::addRec	(const _date_short &when,const recurr_atom &what) {
	const regRecurr::iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {
		//esiste un giorno vediamo se esiste una ricorrenzauguale.
		const rec_day::const_iterator result2 = result->second.find(what);
		if (result2 != result->second.end()) 
			return false;		//se esiste giÃâ  l'appuntamento esco e segnalo
		const pair< rec_day::const_iterator , bool > ret
							= result->second.insert(what); 
		return ret.second;
	} else {
		rec_day aux; //se nn esiste il giorno lo inserisco
		aux.insert(what);
		const pair< regRecurr::const_iterator , bool > ret 
							= leRicorr.insert(regRecurr::value_type(when,aux));
		return ret.second;
	}
}

inline bool containerDati::delRec	(const _date_short &when,const recurr_atom &elim) {
	const regRecurr::iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {
		const rec_day::iterator result2 = result->second.find(elim);
		if (result2 != result->second.end()) {
			if (result->second.size() > 1) {
				//esiston altre ric... elimina solo questa
				result->second.erase(result2);
			} else {
				//elimina tt il ramo se nn c sn altre ric
				leRicorr.erase(result);
			} return true;
		}
	} return false;
}

inline bool containerDati::delRec	(const _date_short &when,unsigned int pos) {
	const regRecurr::iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {
		rec_day::iterator iter = result->second.begin();
		const rec_day::const_iterator fine = result->second.end();
		while ((iter != fine) && pos) {
			pos--;
			iter++;
		}
		if (iter != fine) {
			if (result->second.size() > 1) {
				//esiston altre ric... elimina solo questa
				result->second.erase(iter);
			} else {
				//elimina tt il ramo se nn c sn altre ric
				leRicorr.erase(result);
			} return true;
		}
	} return false;
}

inline bool containerDati::modRec	(const _date_short &when,
									 const recurr_atom &oldRec,
									 const recurr_atom &newRec) {
	const regRecurr::iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {
		const rec_day::iterator result2 = result->second.find(oldRec);
		if (result2 != result->second.end()) {
			result->second.erase(result2);
			result->second.insert(newRec);
			return true;
		}
	} return false;
}

inline void containerDati::obtainRecOfDay (recVec &ilVett,const _date_short &when) const {
	const regRecurr::const_iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {//recupera le ricorrenze del gg indicato
		rec_day::const_iterator iter = (result->second.begin());
		const rec_day::const_iterator fine = (result->second.end());
		const recurr_atom nullo;
		ilVett.resize(result->second.size(),nullo);
		unsigned int cont = 0;
		while (iter != fine) {
			ilVett[cont++] = *iter;
			iter++;
		}
	}
}

inline recurr_atom containerDati::obtRec (const _date_short &when,unsigned int pos) const {
	const regRecurr::const_iterator result = leRicorr.find(when);
	if (result != leRicorr.end()) {
		rec_day::iterator iter = result->second.begin();
		const rec_day::const_iterator fine = result->second.end();
		while ((iter != fine) && pos) {
			pos--;
			iter++;
		}
		if (iter != fine) {
			return *iter;
		}
	} return recurr_atom();
}

inline void containerDati::clearProf () {
	iProfili.clear();
}

inline void containerDati::clearApp () {
	ilRegistro.clear();
}

inline void containerDati::clearRec() {
	leRicorr.clear();
}

inline bool containerDati::profEmpty  () const {
	return iProfili.empty();
}

inline bool containerDati::appEmpty() const {
	return ilRegistro.empty();
}

inline bool containerDati::recEmpty() const {
	return leRicorr.empty();
}


#endif
