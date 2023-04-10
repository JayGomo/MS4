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
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>


namespace sdds
{
	class PosIO
	{
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual std::ofstream& save(std::ofstream&) const = 0;
		virtual std::ifstream& load(std::ifstream&) = 0;
		virtual ~PosIO();
	};

	std::ostream& operator<<(std::ostream&, const PosIO&);
	std::ofstream& operator<<(std::ofstream&, const PosIO&);
	std::istream& operator>>(std::istream&, PosIO&);
	std::ifstream& operator>>(std::ifstream&, PosIO&);
}
#endif
