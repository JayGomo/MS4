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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "PosIO.h"
#include "POS.h"
#include "Error.h"
#include <ostream>

namespace sdds
{
	class Item : public PosIO
	{
	private:
		char	sku[MAX_SKU_LEN + 1];
		char* name;
		double	price;
		bool	tax;
		int		amount;
	protected:
		int displayInt;
		Error errorState;
	public:
		Item(); //Default Constructor
		Item(const Item&); //Copy Constructor
		Item& operator=(const Item& other);
		~Item();

		void setEmpty();
		void decon();

		bool operator==(const char*)const;
		bool operator>(const Item&)const;
		int operator+=(int);
		int operator-=(int);

		operator bool()const;

		Item& displayType(int);
		double cost()const;
		int quantity()const;
		Item& clear();

		virtual char itemType() const = 0;

		std::ostream& write(std::ostream&)const;
		std::istream& read(std::istream&);
		std::ofstream& save(std::ofstream&)const;
		std::ifstream& load(std::ifstream&);
		std::ostream& bprint(std::ostream&)const;
	};
	double& operator+=(double&, const Item&);
}
#endif
