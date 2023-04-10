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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include "Error.h"


namespace sdds
{
	class Date
	{
		int		m_year;
		int		m_month;
		int		m_day;
		int		m_hour;
		int		m_minute;
		bool	m_noTime;
		Error	d_error;

	public:
		Date();
		Date(int, int, int);
		Date(int, int, int, int);
		Date(int, int, int, int, int);
		void validate();
		void getSystemDate(int&, int&, int&, int&, int&, bool);
		int daysOfMonth(int, int);
		bool operator==(const Date&)const;
		bool operator!=(const Date&)const;
		bool operator<(const Date&)const;
		bool operator>(const Date&)const;
		bool operator<=(const Date&)const;
		bool operator>=(const Date&)const;
		Date& dateOnly(bool);
		operator bool()const;
		const Error& error()const;
		void output(std::ostream& sout = std::cout)const;
		std::istream& input(std::istream&);
	};
	std::ostream& operator<<(std::ostream&, const Date&);
	std::istream& operator>>(std::istream&, Date&);
}
#endif
