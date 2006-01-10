/***************************************************************************
 *            timeTypes.cpp
 *
 *  Tue Jan 10 19:04:22 2006
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
 
 
#ifndef _TIMETYPES_CPP
#define _TIMETYPES_CPP

#include "../include/timeTypes.h"


//------------------------------------------------------------------------------
//----------- _date_ -----------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _date_::_date_ () {
       month = year = day = 0;
}

inline _date_::_date_ (int n_year,int n_month,int n_day){
    year = n_year;
	month = n_month;
	day = n_day;
}
 
inline _date_::~_date_() {
       //bene nn fa niente
}

//--------------- Funzioni manipolazione ---------------------------------------

inline bool _date_::IsEmpty() const {
	return (!(year && month && day));
}

inline unsigned short int _date_::GetYear  () const {
	return year;
}

inline unsigned short int _date_::GetMonth () const {
	return month;
}

inline unsigned short int _date_::GetDay   () const {
	return day;
}



inline void _date_::SetYear  (const unsigned short int &n_year) {
	year = n_year;
}

inline void _date_::SetMonth (const unsigned short int &n_month) {
	month = n_month;
}

inline void _date_::SetDay   (const unsigned short int &n_day) {
	day = n_day;
}

inline _date_ & _date_::operator=  (const _date_ &obj2) {
	year = obj2.year;
	month = obj2.month;
	day = obj2.day;
	return *this;
}

inline wxString _date_::ToWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d/%02d/%04d"),day,month,year);
	return timeStamp;
}

inline _date_::operator _date_short () const {
	return _date_short (GetMonth(),GetDay());
}

//--------------- Funzioni di confronto ----------------------------------------


inline bool _date_::operator== (const _date_ &obj2) const {
       return ((year == obj2.year) && 
               (month == obj2.month) && 
               (day == obj2.day));
}

inline bool _date_::operator!= (const _date_ &obj2) const {
       return ((year != obj2.year) || 
               (month != obj2.month) || 
               (day != obj2.day));
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

inline bool _date_::operator<= (const _date_ &obj2) const {
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

inline bool _date_::operator>  (const _date_ &obj2) const {
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
//----------- _date_short ------------------------------------------------------

//--------------- Costruttori & Distruttori ------------------------------------

inline _date_short::_date_short () {
	month = day = 0;
}

//inline _date_short::~_date_short();

inline _date_short::_date_short	(unsigned short int n_month,unsigned short int n_day) {
	month = n_month;
	day = n_day;
}



//--------------- Funzioni manipolazione ---------------------------------------

inline bool _date_short::IsEmpty() const {
	return (month && day);
}

inline unsigned short int _date_short::GetMonth () const {
	return month;
}

inline unsigned short int _date_short::GetDay   () const {
	return day;
}

inline void _date_short::SetMonth (const unsigned short int &n_month) {
	month = n_month;
}

inline void _date_short::SetDay   (const unsigned short int &n_day) {
	day = n_day;
}

inline wxString _date_short::ToWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d:%02d"),month,day);
	return timeStamp;
}

inline bool _date_short::operator== (const _date_short &obj2) const {
	return ((month == obj2.month) && (day == obj2.day));
}

inline bool _date_short::operator== (const _date_ &obj2) const {
	return ((month == obj2.GetMonth()) && (day == obj2.GetDay()));
}

inline bool operator== (const _date_ &obj,const _date_short &obj2) {
	return ((obj.GetMonth() == obj2.month) && (obj.GetDay() == obj2.day));
}

inline bool operator<  (const _date_short &obj,const _date_short &obj2) {
	int result = (obj.month - obj2.month);
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

//inline bool _date_short::operator<= (const _date_short &obj2);

inline bool _date_short::operator>  (const _date_short &obj2) const {
	int result = (month - obj2.month);
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

inline _date_short & _date_short::operator=  (const _date_short &obj2) {
	month = obj2.month;
	day	= obj2.day;
	return *this;
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

inline wxString _time_::ToWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d:%02d"),hour,min);
	return timeStamp;
}

inline wxString _time_::GetHourInWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d"),hour);
	return timeStamp;
}

inline wxString _time_::GetMinInWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d"),min);
	return timeStamp;
}

inline long int _time_::GetCountSec() const {
	return (((hour * 60) + min) * 60);
}

inline _time_ & _time_::operator=  (const _time_ &obj2) {
	hour = obj2.hour;
	min = obj2.min;
	return *this;
}

inline long int _time_::operator- (const _time_ &obj2) const { //it's a try
	return (GetCountSec() - obj2.GetCountSec());
}

//--------------- Funzioni di confronto ----------------------------------------


inline bool _time_::operator== (const _time_ &obj2) const {
       return ((hour == obj2.hour) && 
               (min == obj2.min));
}

inline bool _time_::operator!= (const _time_ &obj2) const {
       return ((hour != obj2.hour) || 
               (min != obj2.min));
}

inline bool operator<  (const _time_ &obj,const _time_ &obj2) {
/*	int result = (obj.hour - obj2.hour);
	if (result) {
		return (result < 0);
	}
	result = (obj.min - obj2.min);
	if (result) {
		return (result < 0);
	}
	return false;*/
	
	if (obj.hour == obj2.hour) 
		return (obj.min < obj2.min);
	return (obj.hour < obj2.hour);
}

inline bool operator>  (const _time_ &obj,const _time_ &obj2) {
/*	int result = (obj.hour - obj2.hour);
	if (result) {
		return (result > 0);
	}
	result = (obj.min - obj2.min);
	if (result) {
		return (result > 0);
	}
	return false;*/
	
	if (obj.hour == obj2.hour) 
		return (obj.min > obj2.min);
	return (obj.hour > obj2.hour);
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

inline wxString _time_xtd::ToWxString() const {
	wxString timeStamp;
	timeStamp.Printf(_T("%02d:%02d:%02d"),hour,min,sec);
	return timeStamp;
}

inline long int _time_xtd::GetCountSec() const {
	return ((((hour * 60) + min) * 60) + sec);
}

inline _time_xtd & _time_xtd::operator=  (const _time_xtd &obj2) {
    hour = obj2.GetHour();
    min = obj2.GetMin();
	sec = obj2.GetSec();
	return *this;
}


//--------------- Funzioni di confronto ----------------------------------------

inline bool _time_xtd::operator== (const _time_xtd &obj2) const {
    return ((hour == obj2.hour) && 
    		(min == obj2.min) &&
			(sec == obj2.sec));
}

inline bool operator<  (const _time_xtd &obj,const _time_xtd &obj2) {
/*	int result = (obj.hour - obj2.hour);
	if (result) {
		return (result < 0);
	}
	result = (obj.min - obj2.min);
	if (result) {
		return (result < 0);
	}
	result = (obj.sec - obj2.sec);
	if (result) {
		return (result < 0);
	}
	return false;*/
	
	if (obj.hour == obj2.hour) {
		if (obj.min == obj2.min)
			return (obj.sec < obj2.sec);
		return (obj.min < obj2.min);
	}
	return (obj.hour < obj2.hour);
}

inline bool operator>  (const _time_xtd &obj,const _time_xtd &obj2) {
/*	int result = (obj.hour - obj2.hour);
	if (result) {
		return (result > 0);
	}
	result = (obj.min - obj2.min);
	if (result) {
		return (result > 0);
	}
	result = (obj.sec - obj2.sec);
	if (result) {
		return (result > 0);
	}
	return false;*/
	
	if (obj.hour == obj2.hour) {
		if (obj.min == obj2.min)
			return (obj.sec > obj2.sec);
		return (obj.min > obj2.min);
	}
	return (obj.hour > obj2.hour);
}

#endif /* _TIMETYPES_CPP */
