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


#include <iostream>
#include <fstream>
#include "PosIO.h"

using namespace std;

namespace sdds
{
	std::ostream& operator<<(std::ostream& cout, const PosIO& PosIO)
	{
		return PosIO.write(cout);
	}

	std::ofstream& operator<<(std::ofstream& cout, const PosIO& PosIO)
	{
		return PosIO.save(cout);
	}

	std::istream& operator>>(std::istream& cin, PosIO& PosIO)
	{
		PosIO.read(cin);
		return cin;
	}

	std::ifstream& operator>>(std::ifstream& cin, PosIO& PosIO)
	{
		PosIO.load(cin);
		return cin;
	}

	PosIO::~PosIO()
	{

	}
}



//
//#include <iostream>
//#include <fstream>
//#include "PosIO.h"
//
//using namespace std;
//
//namespace sdds
//{
//	std::ostream& operator<<(std::ostream& cout, const PosIO& PosIO)
//	{
//		return PosIO.write(cout);
//	}
//
//	std::ofstream& operator<<(std::ofstream& cout, const PosIO& PosIO)
//	{
//		return PosIO.save(cout);
//	}
//
//	std::istream& operator>>(std::istream& cin, PosIO& PosIO)
//	{
//		PosIO.read(cin);
//		return cin;
//	}
//
//	std::ifstream& operator>>(std::ifstream& cin, PosIO& PosIO)
//	{
//		PosIO.load(cin);
//		return cin;
//	}
//
//	PosIO::~PosIO()
//	{
//
//	}
//}
