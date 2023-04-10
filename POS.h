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

#ifndef SDDS_POS_H
#define SDDS_POS_H

namespace sdds
{
	const float TAX = 0.13;
	const int MAX_SKU_LEN = 7;
	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2030;
	const int MAX_STOCK_NUMBER = 99;
	const int MAX_NO_ITEMS = 2000;
	const int MAX_NAME_LEN = 40;
	const int POS_LIST = 1;
	const int POS_FORM = 2;
	const char ERROR_POS_SKU[] = "SKU too long";
	const char ERROR_POS_NAME[] = "Item name too long";
	const char ERROR_POS_PRICE[] = "Invalid price value";
	const char ERROR_POS_TAX[] = "Invalid tax status";
	const char ERROR_POS_QTY[] = "Invalid quantity value";
	const char ERROR_POS_STOCK[] = "Item out of stock";
	const char ERROR_POS_EMPTY[] = "Invalid Empty Item";
}
#endif
