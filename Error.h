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
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H

#include <iostream>

namespace sdds
{
	class Error
	{
		char* errorMsg;
	public:
		Error();
		Error(const char*);
		Error(const Error&);
		~Error();
		void decon();
		operator bool()const;
		Error& clear();
		Error& operator=(const Error&);
		Error& operator=(const char*);
		std::ostream& display(std::ostream& sout = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& sout, const Error&);
}
#endif
