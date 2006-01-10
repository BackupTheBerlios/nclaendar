/***************************************************************************
 *            timeTypes.h
 *
 *  Tue Jan 10 19:01:18 2006
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
 
#ifndef _TIMETYPES_H
#define _TIMETYPES_H

#if defined( DEBUG_LEVEL_1 )
	#include <stdio.h>
#endif

#include <wx/string.h>
#include <time.h>

class _date_short;

class _date_ {
	unsigned short int year;
	unsigned short int month;
	unsigned short int day;
public:
	_date_ 	();
	~_date_ ();
	_date_	(int ,int ,int );
	
	bool IsEmpty() const;
	
	unsigned short int GetYear  () const;
	unsigned short int GetMonth () const;
	unsigned short int GetDay   () const;
	
	void SetYear  (const unsigned short int &n_year);
	void SetMonth (const unsigned short int &n_month);
	void SetDay   (const unsigned short int &n_day);
	
	wxString ToWxString() const;
	
	bool operator== (const _date_ &obj2) const;
	bool operator!= (const _date_ &obj2) const;
	friend bool operator<  (const _date_ &obj,const _date_ &obj2);
	bool operator<= (const _date_ &obj2) const;
	bool operator>  (const _date_ &obj2) const;
	
	_date_ & operator=  (const _date_ &obj2);
	operator _date_short() const;
	
	static _date_ Today() {
		const time_t temp = time(NULL);
		tm * currTime = localtime(&temp);
		_date_ oggi;
		oggi.SetYear(currTime->tm_year + 1900);
		oggi.SetMonth(currTime->tm_mon + 1);
		oggi.SetDay(currTime->tm_mday);
		return oggi;
	}
};

class _date_short {
	unsigned short int month;
	unsigned short int day;
public:
	_date_short ();
//	~_date_short();
	_date_short	(unsigned short int ,unsigned short int );
	
	bool IsEmpty() const;
	
	unsigned short int GetMonth () const;
	unsigned short int GetDay   () const;
	
	void SetMonth (const unsigned short int &n_month);
	void SetDay   (const unsigned short int &n_day);
	
	wxString ToWxString() const;
	
	bool operator== (const _date_short &obj2) const;
	bool operator== (const _date_ &obj2) const;
	friend bool operator== (const _date_ &obj,const _date_short &obj2);
	friend bool operator<  (const _date_short &obj,const _date_short &obj2);
	bool operator<= (const _date_short &obj2) const;
	bool operator>  (const _date_short &obj2) const;
	
	_date_short & operator=  (const _date_short &obj2);
};

class _time_ {
protected:
	unsigned short int hour;
	unsigned short int min;
public:
	_time_  ();
	_time_	(int ,int );
//	virtual ~_time_ ();  //serve virtual x poter essere derivabile, mahh!!!
	bool IsEmpty() const;
	
	unsigned short int GetHour() const;
	unsigned short int GetMin() const;
	
	void SetHour (const unsigned short int &n_Hour);
	void SetMin  (const unsigned short int &n_Min);
	
	virtual wxString ToWxString() const;
	wxString GetHourInWxString() const;
	wxString GetMinInWxString() const;
	virtual long int GetCountSec() const;
	
	virtual bool operator== (const _time_ &obj2) const;
	virtual bool operator!= (const _time_ &obj2) const;
	friend bool operator<   (const _time_ &obj,const _time_ &obj2);
	friend bool operator>   (const _time_ &obj,const _time_ &obj2);
	
	virtual long int operator- (const _time_ &obj2) const;
	
	virtual _time_ & operator=  (const _time_ &obj2);
	
	static _time_ Now() {
		const time_t temp = time(NULL);
		tm * currTime = localtime(&temp);
		_time_ ora;
		ora.SetHour(currTime->tm_hour);
		ora.SetMin(currTime->tm_min);
		return ora;
	}
};

class _time_xtd : public _time_ {
protected:
	unsigned short int sec;
public:
	_time_xtd();
	
	unsigned short int GetSec() const;
	void SetSec(const unsigned short int &n_sec);
	
	wxString ToWxString() const;
	virtual long int GetCountSec() const;
	
	virtual bool operator== (const _time_xtd &obj2) const;
	friend bool operator<   (const _time_xtd &obj,const _time_xtd &obj2);
	friend bool operator>   (const _time_xtd &obj,const _time_xtd &obj2);
      
	virtual _time_xtd & operator=  (const _time_xtd &obj2);
	
	static _time_xtd Now() {
		const time_t temp = time(NULL);
		tm * currTime = localtime(&temp);
		_time_xtd ora;
		ora.SetHour(currTime->tm_hour);
		ora.SetMin(currTime->tm_min);
		ora.SetSec(currTime->tm_sec);
		return ora;
	}
};


#endif /* _TIMETYPES_H */
