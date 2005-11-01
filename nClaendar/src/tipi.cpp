#ifndef TIPI_CPP
#define TIPI_CPP

#include "tipi.h"

//------------------------------------------------------------------------------
//----------- _date_ -----------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _date_::_date_() {
       month = year = day = 0;
}

inline _date_::~_date_() {
       //bene nn fa niente
}

//--------------- Funzioni manipolazione ---------------------------------------

inline unsigned short int _date_::GetYear  () const {
       return year;
}

inline unsigned short int _date_::GetMonth () const {
       return month;
}

inline unsigned short int _date_::GetDay   () const {
       return day;
}



inline void _date_::setYear  (const unsigned short int &n_year) {
       year = n_year;
}

inline void _date_::setMonth (const unsigned short int &n_month) {
       month = n_month;
}

inline void _date_::setDay   (const unsigned short int &n_day) {
       day = n_day;
}

inline void _date_::operator=  (const _date_ &obj2) {
       year = obj2.year;
       month = obj2.month;
       day = obj2.day;
}

inline string _date_::ToStdString() const {
	string convertita = "";
	ostringstream out;
	out.fill('0');
	out.width(2);
	out << GetYear();
	out.width(1);
	out	<< '-';
	out.fill('0');
	out.width(2);
	out	<< GetMonth();
	out.width(1);
	out	<< '-';
	out.fill('0');
	out.width(2);
	out	<< GetDay();
	convertita = out.str();
	return convertita;
}

//--------------- Funzioni di confronto ----------------------------------------


inline bool _date_::operator== (const _date_ &obj2) {
       return ((year == obj2.year) && 
               (month == obj2.month) && 
               (day == obj2.day));
}

inline bool operator<  (const _date_ &obj,const _date_ &obj2) {
       int result = (obj.year - obj2.year);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (obj.month - obj2.month);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (obj.day - obj2.day);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       return false;
}

inline bool _date_::operator<= (const _date_ &obj2) {
       int result = (year - obj2.year);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (month - obj2.month);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (day - obj2.day);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       return true;
}

inline bool _date_::operator>  (const _date_ &obj2) {
       int result = (year - obj2.year);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       result = (month - obj2.month);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       result = (day - obj2.day);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       return false;
}

//------------------------------------------------------------------------------
//----------- _time_ -----------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _time_::_time_() {
       hour = min = 0;
}

inline _time_::_time_(int n_hour,int n_min) {
    hour = n_hour;
	min = n_min;
}


//inline _time_::~_time_() {
       //bene nn fa niente
//}

//--------------- Funzioni manipolazione ---------------------------------------

inline bool _time_::IsEmpty() const {
	return (!(hour && min));
}

inline unsigned short int _time_::GetHour  () const {
       return hour;
}

inline unsigned short int _time_::GetMin () const {
       return min;
}



inline void _time_::SetHour (const unsigned short int &n_hour) {
       hour = n_hour;
}

inline void _time_::SetMin  (const unsigned short int &n_min) {
       min = n_min;
}

inline string _time_::ToStdString() const { //rivedi x rendere + snello
	string convertita = "";
	ostringstream out;
	out.fill('0');
	out.width(2);
	out << GetHour();
	out.width(1);
	out	<< ':';
	out.fill('0');
	out.width(2);
	out	<< GetMin();
	convertita = out.str();
	return convertita;
}

inline void _time_::operator=  (const _time_ &obj2) {
       hour = obj2.hour;
       min = obj2.min;
}


//--------------- Funzioni di confronto ----------------------------------------


inline bool _time_::operator== (const _time_ &obj2) {
       return ((hour == obj2.hour) && 
               (min == obj2.min));
}

inline bool operator<  (const _time_ &obj,const _time_ &obj2) {
       int result = (obj.hour - obj2.hour);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (obj.min - obj2.min);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       return false;
}

inline bool operator>  (const _time_ &obj,const _time_ &obj2) {
       int result = (obj.hour - obj2.hour);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       result = (obj.min - obj2.min);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       return false;
}

//------------------------------------------------------------------------------
//----------- _time_xtd --------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _time_xtd::_time_xtd() {
       hour = min = sec = 0;
}


//--------------- Funzioni manipolazione ---------------------------------------

inline unsigned short int _time_xtd::GetSec  () const {
       return sec;
}

inline void _time_xtd::SetSec (const unsigned short int &n_sec) {
       sec = n_sec;
}

inline string _time_xtd::ToStdString() const { //rivedi x rendere + snello
	string convertita = "";
	ostringstream out;
	out.fill('0');
	out.width(2);
	out << GetHour();
	out.width(1);
	out	<< ':';
	out.fill('0');
	out.width(2);
	out	<< GetMin();
	out.width(1);
	out	<< ':';
	out.fill('0');
	out.width(2);
	out	<< GetSec();
	convertita = out.str();
	return convertita;
}

inline void _time_xtd::operator=  (const _time_xtd &obj2) {
    hour = obj2.GetHour();
    min = obj2.GetMin();
	sec = obj2.GetSec();
}


//--------------- Funzioni di confronto ----------------------------------------

inline bool _time_xtd::operator== (const _time_xtd &obj2) {
    return ((hour == obj2.hour) && 
    		(min == obj2.min) &&
			(sec == obj2.sec));
}

inline bool operator<  (const _time_xtd &obj,const _time_xtd &obj2) {
       int result = (obj.hour - obj2.hour);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (obj.min - obj2.min);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       result = (obj.sec - obj2.sec);
       if (result) {
              if (result > 0) return false;
              return true;
       }
       return false;
}

inline bool operator>  (const _time_xtd &obj,const _time_xtd &obj2) {
       int result = (obj.hour - obj2.hour);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       result = (obj.min - obj2.min);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       result = (obj.sec - obj2.sec);
       if (result) {
              if (result < 0) return false;
              return true;
       }
       return false;
}




//------------------------------------------------------------------------------
//----------- app_date ---------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline app_date::app_date () {
	//nope
}

#ifndef USE_WX_NATIV
inline app_date::app_date (const _time_ &n_when,const string &n_what) {
	when = n_when;
	what = n_what;
}
#else
inline app_date::app_date (const _time_ &n_when,const wxString &n_what) {
	when = n_when;
	what = n_what;
}
#endif

inline app_date::~app_date () {
	//nope;
}


//--------------- Funzioni manipolazione ---------------------------------------

inline bool app_date::IsEmpty() const {
	return (when.IsEmpty() && what.empty());
}

inline _time_ app_date::GetWhen	() const {
	return when;
}

inline string app_date::GetWhat	() const {
	return what;
}

inline void app_date::SetWhen	(const _time_ &n_when){
	when = n_when;
}

inline void app_date::SetWhat	(const string &n_what){
	what = n_what;
}

inline void app_date::operator= (const app_date & obj2) {
	when = obj2.GetWhen();
	what = obj2.GetWhat();
}

inline void app_date::operator= (const pair< _time_ , string > &obj2) {
	when = obj2.first;
	what = obj2.second;
}

//------------------------------------------------------------------------------
//----------- _profile_ ----------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _profile_::_profile_() {
	nome = cognome = nick = "";
}


//--------------- Funzioni Utili -----------------------------------------------

	
#ifndef USE_WX_NATIV
inline string 	_profile_::GetNick		() const {
	return nick;
}

inline string 	_profile_::GetNome		() const {
	return nome;
}

inline string 	_profile_::GetCognome	() const {
	return cognome;
}
#else
inline wxString _profile_::GetNick		() const {
	return nick;
}

inline wxString _profile_::GetNome		() const {
	return nome;
}

inline wxString _profile_::GetCognome	() const {
	return cognome;
}
#endif

#ifndef USE_WX_NATIV
inline void 	_profile_::SetNick		(const string &n_nick) {
	nick = n_nick;
}

inline void 	_profile_::SetNome		(const string &n_nome) {
	nome = n_nome;
}

inline void 	_profile_::SetCognome	(const string &n_cognome) {
	cognome = n_cognome;
}
#else
inline void 	_profile_::SetNick		(const wxString &n_nick) {
	nick = n_nick;
}

inline void 	_profile_::SetNome		(const wxString &n_nome) {
	nome = n_nome;
}

inline void 	_profile_::SetCognome	(const wxString &n_cognome) {
	cognome = n_cognome;
}
#endif

#ifndef USE_WX_NATIV
inline bool operator< (const _profile_ &obj,const _profile_ &obj2) {
/*	return ((obj.cognome < obj2.cognome) ||
			((obj.cognome == obj2.cognome) && 
			 (obj.nome < obj2.nome)));*/
	return (obj.nick < obj2.nick);
}

inline bool _profile_::operator== (const _profile_ &obj2) {
	return ((nick == obj2.nick) || 
			((nome == obj2.nome) && (cognome == obj2.cognome)));
}

inline void _profile_::operator= (const _profile_ &obj2) {
	nick 	= obj2.nick;
	nome 	= obj2.nome;
	cognome = obj2.cognome;
}
#endif


//------------------------------------------------------------------------------
//----------- ContainerDati ----------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------




//--------------- Funzioni Utili -----------------------------------------------
/*
inline appVec &containerDati::ottieniAppDelGg (const _date_ &when) {
	regApp::const_iterator result;
	result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {//recupera gli appuntamenti del gg indicato
		giorno::const_iterator iter = (result->second.begin());
		giorno::const_iterator fine = (result->second.end());
		app_date nullo;
		stoGG.resize(result->second.size(),nullo);
		int cont = 0;
		while (iter != fine) {
			stoGG[cont] = pair< _time_ , string >(iter->first,iter->second);
			cont++;
			iter++;
		}
	} 
	return stoGG;
}
*/
inline void containerDati::ottieniAppDelGg (appVec &ilVett,const _date_ &when) {
	regApp::const_iterator result;
	result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {//recupera gli appuntamenti del gg indicato
		giorno::const_iterator iter = (result->second.begin());
		giorno::const_iterator fine = (result->second.end());
		app_date nullo;
		ilVett.resize(result->second.size(),nullo);
		int cont = 0;
		while (iter != fine) {
			ilVett[cont] = pair< _time_ , string >(iter->first,iter->second);
			cont++;
			iter++;
		}
	}
}

inline bool containerDati::aggAppuntamento (const _date_ &when,const app_date &theDate) {
	regApp::iterator result;
	result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {
		//esiste un giorno vediamo se esiste un appuntamente x quell'ora.
		giorno::const_iterator result2;
		result2 = result->second.find(theDate.GetWhen());
		if (result2 != result->second.end()) 
			return false;		//se esiste giÃ  l'appuntamento esco e segnalo
		pair< giorno::const_iterator , bool > ret;
		ret = result->second.insert( giorno::value_type( theDate.GetWhen(),
												   theDate.GetWhat() )); 
		return ret.second;
	} else {
		giorno aux; //se nn esiste il giorno lo inserisco
		aux.insert(giorno::value_type(theDate.GetWhen(),theDate.GetWhat()));
		pair< regApp::const_iterator , bool > ret;
		ret = ilRegistro.insert(regApp::value_type(when,aux));
		return ret.second;
	}
}

inline void containerDati::modAppuntamento	(const _date_ &when,const app_date &theDate) {
	ilRegistro[when][theDate.GetWhen()] = theDate.GetWhat();
}

inline string containerDati::obtainApp		(const _date_ &day,const _time_ &time) {
	return ilRegistro[day][time];
}

inline app_date containerDati::obtainApp		(const _date_ &day,int num) {
	if (ilRegistro.find(day) != ilRegistro.end()) {
		giorno::const_iterator iter = ilRegistro[day].begin();
		while (num) {
			iter++;
			num--;
		}
		return app_date(iter->first,iter->second);
	} else {
		return app_date();
	}
}

inline bool containerDati::elimAppuntamento	(const _date_ &when,const app_date &theDate) {
	regApp::iterator result;
	result = ilRegistro.find(when);
	if (result != ilRegistro.end()) {
		giorno::iterator result2;
		result2 = result->second.find(theDate.GetWhen());
		if (result2 != result->second.end()) {
			if (result->second.size() > 1) {
				//esiston altri app... elimina solo questo
				result->second.erase(result2);
			} else {
				//elimina tt il ramo se nn c sn altri app
				ilRegistro.erase(result);
			}
			return true;
		}
	}
	return false;
}

inline _profile_ containerDati::ottieniProf(unsigned int num) {
	regProf::const_iterator iter = iProfili.begin();
	regProf::const_iterator fine = iProfili.end();
	if (iter != iProfili.end()) {
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

inline void containerDati::ottieniProf(profVec &ilVett) {
	ilVett.resize(iProfili.size(),_profile_());
	copy(iProfili.begin(),iProfili.end(),ilVett.begin());
}

inline bool containerDati::aggProf(const _profile_ &n_prof) {
	pair< regProf::const_iterator , bool > ret = iProfili.insert(n_prof);
	return ret.second;
}

inline bool containerDati::delProf(const string &del_nick) {
	regProf::iterator iter = iProfili.begin();
	regProf::const_iterator fine = iProfili.end();
	while ((iter != fine) && (iter->GetNick() != del_nick)) iter++;
	if (iter != fine) {
		iProfili.erase(iter);
		return true;
	} return false;
}

inline bool containerDati::delProf(unsigned int pos) {//finisci
	regProf::iterator iter = iProfili.begin();
	regProf::const_iterator fine = iProfili.end();
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
	regProf::iterator iter = iProfili.find(vecchio);
	if (iter != iProfili.end()) {
		iProfili.erase(iter);
		pair< regProf::const_iterator , bool > ret = iProfili.insert(sostit);
		return ret.second;
	} return false;
}

inline void containerDati::pulisciProf() {
	iProfili.clear();
}

inline bool containerDati::profEmpty() const {
	return iProfili.empty();
}


//------------------------------------------------------------------------------
//----------- ProgData ---------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline progData::progData() {
	logAct = false;
}





//------------------------------------------------------------------------------
//--------- Classi comaprative e di Hash ---------------------------------------

#ifdef PROVA_WXHASHMAP

inline bool compDate::operator()(const _date_ &obj,const _date_ &obj2) {
	return (obj == obj2);
}

inline bool compTime::operator()(const _time_ &obj,const _time_ &obj2) {
	return (obj == obj2);
}
#endif

#endif
