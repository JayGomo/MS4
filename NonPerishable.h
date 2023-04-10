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
#ifndef SDDS_NONPERISH_H
#define SDDS_NONPERISH_H

#include "Date.h"
#include "Item.h"

namespace sdds
{
	class NonPerishable : public Item
	{
	protected:
		std::ostream& write(std::ostream&)const;
		char itemType()const;
	public:
	};
}
#endif
