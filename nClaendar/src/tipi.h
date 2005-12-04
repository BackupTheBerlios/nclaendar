/***************************************************************************
 *            tipi.h
 *
 *  Tue Oct 18 21:54:39 2005
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
 
#ifndef NCALTYPES_H
#define NCALTYPES_H

#include <wx/wx.h>
#include <vector>  //i'll start to use wxARRAY
#include <map>
#include <set>
#include <time.h>
using namespace std;

#ifndef NULL
	#define NULL 0
#endif

//needed the first(outHD), otherwise it would not be possible to save stuffs ;-D
#ifndef HDCTRL_H
class outHD;
class inHD;
#endif

//#define USE_REC_MULTISET

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
	
	void operator=  (const _date_ &obj2);
	operator _date_short();
	
	static _date_ Today() {
		const time_t temp = time(NULL);
		tm * currTime = gmtime(&temp);
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
	
	void operator=  (const _date_short &obj2);
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
	
	virtual bool operator== (const _time_ &obj2) const;
	virtual bool operator!= (const _time_ &obj2) const;
	friend bool operator<   (const _time_ &obj,const _time_ &obj2);
	friend bool operator>   (const _time_ &obj,const _time_ &obj2);
      
	virtual void operator=  (const _time_ &obj2);
	
	static _time_ Now() {
		const time_t temp = time(NULL);
		tm * currTime = gmtime(&temp);
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
	
	virtual bool operator== (const _time_xtd &obj2) const;
	friend bool operator<   (const _time_xtd &obj,const _time_xtd &obj2);
	friend bool operator>   (const _time_xtd &obj,const _time_xtd &obj2);
      
	virtual void operator=  (const _time_xtd &obj2);
	
	static _time_xtd Now() {
		const time_t temp = time(NULL);
		tm * currTime = gmtime(&temp);
		_time_xtd ora;
		ora.SetHour(currTime->tm_hour);
		ora.SetMin(currTime->tm_min);
		ora.SetSec(currTime->tm_sec);
		return ora;
	}
};

class app_date {
	_time_ when;
	wxString what;
	
	bool important;
public:
	app_date  ();
	app_date  (const app_date &);
	app_date  (const _time_ &,const wxString &,const bool n_imp = false);
	~app_date ();
	
	bool IsEmpty() const;
	
	wxString GetWhat () const;
	bool IsImportant() const;
	_time_ GetWhen () const;
	
	void SetWhat (const wxString &n_what);
	void SetImportance(const bool n_imp);
	void SetWhen (const _time_ &n_when);
	
	void operator=  (const app_date &obj2);
	
	friend bool operator<  (const app_date &,const app_date &);
	friend bool operator== (const app_date &,const app_date &);
	friend bool operator!= (const app_date &,const app_date &);
};

class _profile_ {
	wxString nick;
	wxString name;
	wxString surname;
	
	_date_ bornIn;
public:
	_profile_ ();
	
	bool IsEmpty();
	
	wxString GetNick() const;
	wxString GetName() const;
	wxString GetSurname() const;
	_date_ GetBirth() const;
	
	void SetNick(const wxString &);
	void SetName(const wxString &);
	void SetSurname(const wxString &);
	void SetBirth(const _date_ &);
	
	friend bool operator< (const _profile_ &,const _profile_ &);
	bool operator== (const _profile_ &) const;
	void operator= (const _profile_ &);
};

class recurr_atom {
	unsigned short int priority;
	wxString what;
public:
	recurr_atom();
	recurr_atom(const unsigned short int ,const wxString &);
	~recurr_atom();
	
	bool IsEmpty() const;
	
	unsigned short int GetPriority() const;
	wxString GetWhat() const;
	wxString GetPriorityInWxString() const;
	
	void SetPriority(const unsigned short int );
	void SetWhat(const wxString &);
	
	friend  bool operator<	(const recurr_atom &,const recurr_atom &);
	bool operator== (const recurr_atom &) const;
	void operator=  (const recurr_atom &);
};

struct progData {
	bool logAct,multiProf;
	int defProf;
	
	progData();
};

//	strutture dati della STL
typedef set< app_date	 , less< app_date > > giorno;
typedef map< _date_ 	 , giorno ,		less< _date_ > > regApp;
typedef set< _profile_ 	 , less< _profile_ > > 	 regProf;
#ifndef USE_REC_MULTISET
typedef set< recurr_atom , less< recurr_atom > > rec_day;
#else
typedef multiset< recurr_atom , less< recurr_atom > > rec_day;
#endif
typedef map< _date_short , rec_day > 	regRecurr;

typedef vector< app_date > 	appVec;
typedef vector< _profile_ > profVec;
typedef vector< recurr_atom > recVec;

#endif
