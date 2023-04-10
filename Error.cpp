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
#include <sstream>
#include <fstream>
#include <cstring>
#include <ostream>
#include <iostream>

#include "Error.h"

using namespace std;

namespace sdds
{
	Error::Error()
	{
		errorMsg = nullptr;
	}

	Error::Error(const char* error)
	{
		if ((error != nullptr) && (error[0] != '\0'))
		{
			errorMsg = new char[strlen(error) + 1];
			strcpy(errorMsg, error);
		}
		else
		{
			errorMsg = nullptr;
		}
	}

	Error::Error(const Error& error)//Copy Constructor
	{
		if (this != &error)
		{
			errorMsg = nullptr;
			*this = error;
		}
		else
		{
			errorMsg = nullptr;
			std::cout << "Both Errors have the same address" << std::endl;
		}
	}

	Error::~Error()
	{
		//cout << "~ called" << endl;
		if ((errorMsg != nullptr) && (errorMsg[0] != '\0'))
		{
			//cout << errorMsg << endl;
			delete[] errorMsg;
			errorMsg = nullptr;
		}
		//cout << "~ complete" << endl;
	}

	void Error::decon()
	{
		delete[] errorMsg;
		errorMsg = nullptr;
	}

	Error::operator bool()const
	{
		if (errorMsg != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Error& Error::clear()
	{
		//cout << "Clear called" << endl;
		if (errorMsg != nullptr)
		{
			delete[] errorMsg;
			errorMsg = nullptr;
		}
		//cout << "Clear complete" << endl;
		return *this;
	}

	Error& Error::operator=(const char* errorString)
	{
		//cout << "op= called" << endl;
		if ((errorString != nullptr) && (errorString[0] != '\0'))
		{
			clear();//Clears array
			errorMsg = new char[strlen(errorString) + 1];//Create correct array size
			strcpy(errorMsg, errorString);//Copies over new array
		}
		//cout << "op= complete" << endl;
		return *this;
	}

	Error& Error::operator=(const Error& copy)//Copy Assignment
	{
		//cout << "op=2 called" << endl;
		if (this != &copy)
		{
			Error::clear();

			if ((copy.errorMsg != nullptr) && (copy.errorMsg[0] != '\0'))
			{
				errorMsg = new char[strlen(copy.errorMsg) + 1];
				strcpy(errorMsg, copy.errorMsg);
			}
		}
		//cout << "op=2 complete" << endl;
		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const Error& error)
	{
		return error.display(out);
	}

	std::ostream& Error::display(ostream& sout)const
	{
		if (operator bool() == true)
		{
			sout << errorMsg;
		}
		return sout;
	}
}
