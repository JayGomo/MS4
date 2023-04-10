/*
*****************************************************************************
 <assessment name example: Milestone 4 - #Ms4>
Full Name : Jason Gomez
Student ID#: 050003136
Email : jgomez15@myseneca.ca
Section : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation. ChatGPT used for general
formatting, function clarification and other minor assistances.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	
#include <ostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include"Error.h"
#include"Date.h"
#include"POS.h"

using namespace std;
namespace sdds
{
	void Date::validate()
	{
		if ((m_year < MIN_YEAR) || (m_year > MAX_YEAR))
		{
			d_error = "Invalid Year";
			return;
		}
		if ((m_month < 1) || (m_month > 12))
		{
			d_error = "Invalid Month";
			return;
		}
		if ((m_day < 1) || (m_day > daysOfMonth(m_year, m_month)))
		{
			d_error = "Invalid Day";
			return;
		}
		if ((m_hour < 0) || (m_hour > 23))
		{
			d_error = "Invalid Hour";
			return;
		}
		if ((m_minute < 0) || (m_minute > 59))
		{
			d_error = "Invlid Minute";
			return;
		}
		d_error.clear();
	}

	void Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		day = lt.tm_mday;
		mon = lt.tm_mon + 1;
		year = lt.tm_year + 1900;
		if (dateOnly)
		{
			hour = min = 0;
		}
		else
		{
			hour = lt.tm_hour;
			min = lt.tm_min;
		}
	}

	int Date::daysOfMonth(int year, int month)
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = month >= 1 && month <= 12 ? month : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date()
	{
		m_noTime = false;
		d_error.clear();
		getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_noTime);
	}

	Date::Date(int t_year, int t_month, int t_day)
	{
		m_year = t_year;
		m_month = t_month;
		m_day = t_day;
		m_hour = 0;
		m_minute = 0;
		m_noTime = true;
		d_error.clear();
		validate();
	}

	Date::Date(int t_year, int t_month, int t_day, int t_hour)
	{
		m_year = t_year;
		m_month = t_month;
		m_day = t_day;
		m_hour = t_hour;
		m_minute = 0;
		m_noTime = false;
		d_error.clear();
		validate();
	}

	Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute)
	{
		m_year = t_year;
		m_month = t_month;
		m_day = t_day;
		m_hour = t_hour;
		m_minute = t_minute;
		m_noTime = false;
		d_error.clear();
		validate();
	}

	bool Date::operator==(const Date& comp)const
	{
		if ((m_year == comp.m_year) && (m_month == comp.m_month) && (m_day == comp.m_day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator!=(const Date& comp)const
	{
		if (*this == comp)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool Date::operator<(const Date& comp)const
	{
		if (m_year < comp.m_year)
		{
			return true;
		}
		else if ((m_year == comp.m_year) && (m_month < comp.m_month))
		{
			return true;
		}
		else if ((m_year == comp.m_year) && (m_month == comp.m_month) && (m_day < comp.m_day))
		{
			return true;
		}
		return false;
	}

	bool Date::operator>(const Date& comp)const
	{
		if (m_year > comp.m_year)
		{
			return true;
		}
		else if ((m_year == comp.m_year) && (m_month > comp.m_month))
		{
			return true;
		}
		else if ((m_year == comp.m_year) && (m_month == comp.m_month) && (m_day > comp.m_day))
		{
			return true;
		}
		return false;
	}

	bool Date::operator<=(const Date& comp)const
	{
		if ((*this < comp) || (*this == comp))
		{
			return true;
		}
		return false;
	}

	bool Date::operator>=(const Date& comp)const
	{
		if ((*this > comp) || (*this == comp))
		{
			return true;
		}
		return false;
	}

	Date& Date::dateOnly(bool confirm)
	{
		m_noTime = confirm;
		if (m_noTime == true)
		{
			m_hour = 0;
			m_minute = 0;
		}
		return *this;
	}

	Date::operator bool() const
	{
		if (d_error == true)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	const sdds::Error& Date::error()const
	{
		return d_error;
	}

	void Date::output(std::ostream& sout)const
	{
		if (!Date::operator bool())
		{
			sout << d_error << "(";
		}

		if (m_noTime == true)
		{
			sout << m_year << "/";
			sout.width(2);
			sout.fill('0');
			sout << std::right << m_month << "/";
			sout.width(2);
			sout.fill('0');
			sout << m_day << std::left;
		}
		else
		{
			sout << m_year << "/";
			sout.width(2);
			sout.fill('0');
			sout << m_month << "/";
			sout.width(2);
			sout.fill('0');
			sout << m_day;
			sout << ", ";
			sout.width(2);
			sout.fill('0');
			sout << m_hour << ":";
			sout.width(2);
			sout.fill('0');
			sout << m_minute;
		}

		if (!Date::operator bool())
		{
			sout << ")";
		}
	}

	std::istream& Date::input(std::istream& sin = std::cin)
	{
		char cma;

		d_error.clear();

		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_minute = 0;

		if (!(sin >> m_year))
		{
			d_error = "Cannot read year entry";
			return sin;
		}

		sin >> cma;
		if (!(sin >> m_month))
		{
			d_error = "Cannot read month entry";
			return sin;
		}

		sin >> cma;
		if (!(sin >> m_day))
		{
			d_error = "Cannot read day entry";
			return sin;
		}

		if (sin.peek() == '\n')
		{
			m_noTime = true;
			validate();
			return sin;
		}

		sin >> cma;

		if (!(sin >> m_hour))
		{
			d_error = "Cannot read hour entry";
			return sin;
		}

		sin >> cma;

		if (!(sin >> m_minute))
		{
			d_error = "Cannot read minute entry";
			return sin;
		}

		m_noTime = false;
		validate();

		return sin;
	}

	std::ostream& operator<<(std::ostream& sout, const Date& date)
	{
		date.output(sout);
		return sout;
	}

	std::istream& operator>>(std::istream& sin, Date& date)
	{
		return date.input(sin);
	}
}
