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
#ifndef SDDS_PERISH_H
#define SDDS_PERISH_H

#include "Item.h"
#include "Date.h"


namespace sdds
{
	class Perishable : public Item
	{
	protected:
		Date p_date;
	public:
		char itemType()const;
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&)const;
		std::ifstream& load(std::ifstream&);
		std::ofstream& save(std::ofstream&)const;
	};
}

#endif
