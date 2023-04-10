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

#include "NonPerishable.h"
#include "Error.h"
#include "Item.h"

using namespace std;

namespace sdds
{
	char NonPerishable::itemType()const
	{
		return 'N';
	}

	std::ostream& NonPerishable::write(std::ostream& cout) const
	{
		Item::write(cout);
		if (*this)
		{
			if (displayInt == POS_LIST)
			{
				std::cout << "    N / A   |";
			}
			else if (displayInt == POS_FORM)
			{
				std::cout << "=============^" << std::endl;;
			}
		}
		return cout;
	}
}
