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

#include "Perishable.h"
#include "Error.h"
#include "Item.h"
#include "Date.h"
#include "PosIO.h"

#include <fstream>

using namespace std;

namespace sdds
{
	char Perishable::itemType()const
	{
		return 'P';
	}

	std::istream& Perishable::read(std::istream& cin)
	{
		Item::read(cin);

		if ((!cout.fail()) && (cin))
		{
			Date newDate;
			newDate.dateOnly(true);
			std::cout << "Expiry date (YYYY/MM/DD)" << std::endl;
			std::cout << "> ";
			newDate.input(cin);

			if (newDate)
			{
				p_date = newDate;
			}
			else
			{
				errorState = newDate.error();
			}
		}
		return cin;
	}

	std::ostream& Perishable::write(std::ostream& cout)const
	{
		Item::write(cout);

		if (!cout.fail())
		{
			if (displayInt == POS_LIST)
			{
				cout << " " << p_date << " |";
			}
			else if (displayInt == POS_FORM)
			{
				cout << "Expiry date: ";
				cout << p_date << std::endl;
				cout << "=============^" << std::endl;
			}
		}
		return cout;
	}

	std::ifstream& Perishable::load(std::ifstream& cin)
	{
		Item::load(cin);

		if ((!cin.fail()) && cin)
		{
			Date temp;
			temp.dateOnly(true);
			cin.clear();
			cin.ignore();
			cin >> temp;

			if (temp)
			{
				p_date = temp;
			}
			else
			{
				errorState = temp.error();
			}
		}

		return cin;
	}

	std::ofstream& Perishable::save(std::ofstream& coutf)const
	{
		Item::save(coutf);

		if (!coutf.fail())
		{
			coutf << "," << p_date;
		}
		return coutf;
	}
}
