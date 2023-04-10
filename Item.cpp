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
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>

#include "Item.h"
#include "Error.h"

using namespace std;

namespace sdds
{
	Item::Item()
	{
		setEmpty();
	}

	Item::Item(const Item& newItem)
	{
		*this = newItem;
	}

	Item& Item::operator=(const Item& newItem)
	{
		if (this != &newItem)
		{
			if ((newItem.name != nullptr) && (this != &newItem))
			{
				errorState.clear();
				if (name != nullptr)
				{
					decon();
				}

				name = new char[strlen(newItem.name) + 1];
				strcpy(name, newItem.name);
				strcpy(sku, newItem.sku);
				price = newItem.price;
				amount = newItem.amount;
				tax = newItem.tax;
				displayInt = newItem.displayInt;
				errorState = newItem.errorState;
			}
		}
		return *this;
	}

	void Item::setEmpty()
	{
		sku[0] = '\0';
		name = nullptr;
		price = 0.0;
		tax = false;
		amount = 0;
		displayInt = POS_LIST;
		errorState = ERROR_POS_EMPTY;
	}

	void Item::decon()
	{
		delete[] name;
		name = nullptr;
	}

	Item::~Item()
	{
		decon();
		errorState.decon();
	}

	bool Item::operator==(const char* newSKU)const
	{
		if ((strcmp(sku, newSKU)) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Item::operator>(const Item& newItem)const
	{
		if ((strcmp(name, newItem.name)) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Item::operator+=(int newInt)
	{
		int newQuant = amount + newInt;
		if (newQuant > MAX_STOCK_NUMBER)
		{
			amount = MAX_STOCK_NUMBER;
			errorState = ERROR_POS_QTY;
		}
		else
		{
			amount = newQuant;
		}
		return amount;
	}

	int Item::operator-=(int newInt)
	{
		int newQuant = amount - newInt;
		if (newQuant < 0)
		{
			amount = 0;
			errorState = ERROR_POS_STOCK;
		}
		else
		{
			amount = newQuant;
		}
		return amount;
	}

	Item::operator bool() const
	{
		if (errorState.operator bool() == true)
		{
			return false;
		}
		else
			return true;
	}

	double& operator+=(double& ls, const Item& rs)
	{
		ls = ls + (rs.quantity() * rs.cost());
		return ls;
	}

	Item& Item::displayType(int display)
	{
		if ((display == POS_FORM) || (display == POS_LIST))
		{
			displayInt = display;
		}
		return *this;
	}

	double Item::cost()const
	{
		double cost = price;
		if (tax == true)
		{
			cost *= (1 + TAX);
		}
		return cost;
	}

	int Item::quantity()const
	{
		return amount;
	}

	Item& Item::clear()
	{
		errorState.clear();
		return *this;
	}

	std::ostream& Item::write(std::ostream& cout) const
	{
		if (errorState)
		{
			errorState.display(cout);
		}
		else
		{
			std::string tname(name, std::min(static_cast<size_t>(20), strlen(name)));

			if (displayInt == POS_LIST)
			{
				double newDouble = cost() * quantity();
				double finalDouble = std::round(newDouble * std::pow(10, 3)) / std::pow(10, 3);
				cout <<
					std::setw(7) << std::left << std::setfill(' ') << sku << "|" <<
					std::setw(20) << std::left << std::setfill(' ') << tname << "|" <<
					std::setw(7) << std::right << std::setprecision(2) << std::fixed << price << "|" << " " << (tax ? "X " : "  ") << "|" <<
					std::setw(4) << std::right << std::setfill(' ') << quantity() << "|"
					<< std::setw(9) << std::setprecision(2) << finalDouble << "| " << std::left;
			}

			else if (displayInt == POS_FORM)
			{
				std::cout << std::left << std::setfill('=') << std::setw(13) << "" << "v" << std::endl;
				cout << "Name:        " << tname << std::endl;
				cout << "Sku:         " << sku << std::endl;
				cout << "Price:       " << std::setprecision(2) << std::fixed << price << std::endl;
				cout << "Price + tax: ";

				if (tax == true)
				{
					cout << cost() << std::endl;
				}
				else
				{
					cout << "N/A" << std::endl;
				}
				cout << "Stock Qty:   " << quantity() << std::endl;
			}

		}
		return cout;
	}

	std::istream& Item::read(std::istream& cin)
	{
		char newSku[200];
		string newName = "\0";
		double newPrice = 0;
		char newTax = '\0';
		int newQuantity = 0;

		bool valid = false;
		std::cout << "Sku" << std::endl;

		do//Receiving Sku and checking validity
		{
			std::cout << "> ";
			cin >> newSku;

			if ((strlen(newSku) <= MAX_SKU_LEN) && (strlen(newSku) > 0))
			{
				strncpy(sku, newSku, MAX_SKU_LEN);
				sku[MAX_SKU_LEN] = '\0';
				valid = true;
			}
			else
			{
				errorState = ERROR_POS_SKU;
				errorState.display() << std::endl;
			}
			std::cin.ignore(100, '\n');
		} while (!valid);

		valid = false;
		std::cout << "Name" << std::endl;

		do//Receiving name and checking validity
		{
			std::cout << "> ";
			getline(cin, newName, '\n');

			if (strlen(newName.c_str()) <= MAX_NAME_LEN)
			{
				if (name != nullptr)
				{
					decon();
				}

				name = new char[strlen(newName.c_str()) + 1];
				strcpy(name, newName.c_str());
				valid = true;
			}
			else
			{
				errorState = ERROR_POS_NAME;
				errorState.display() << std::endl;
			}
		} while (!valid);

		valid = false;
		std::cout << "Price" << std::endl;

		do//Receiving price and checking validity
		{
			std::cout << "> ";

			cin >> newPrice;

			if (newPrice > 0)
			{
				price = newPrice;
				valid = true;
			}
			else if ((cin.fail()) || (newPrice < 0))
			{
				errorState = ERROR_POS_PRICE;
				errorState.display() << std::endl;
			}
			std::cin.clear();
			std::cin.ignore(100, '\n');
		} while (!valid);

		valid = false;
		std::cout << "Taxed?" << std::endl << "(Y)es/(N)o: ";

		do//Receiving tax and checking validity
		{
			cin >> newTax;

			switch (newTax)
			{
			case 'y':
				tax = true;
				valid = true;
				break;
			case 'n':
				tax = false;
				valid = true;
				break;
			default:
				std::cout << "Only 'y' and 'n' are acceptable: ";
				errorState = ERROR_POS_TAX;
				break;
			}
			std::cin.clear();
			std::cin.ignore(100, '\n');
		} while (!valid);

		valid = false;
		std::cout << "Quantity" << std::endl;

		do//Receiving quantity and checking validity
		{
			std::cout << "> ";
			cin >> newQuantity;

			if ((newQuantity <= MAX_STOCK_NUMBER) && (newQuantity > 0))
			{
				amount = newQuantity;
				valid = true;
			}
			else
			{
				errorState = ERROR_POS_QTY;
				errorState.display() << std::endl;
			}
			std::cin.clear();
			std::cin.ignore(100, '\n');
		} while (!valid);

		clear();
		return cin;
	}

	std::ofstream& Item::save(std::ofstream& cout)const
	{
		if (errorState)
		{
			errorState.display(cout);
		}
		else
		{
			cout <<
				itemType() << ',' <<
				sku << ',' <<
				name << ',' <<
				std::setprecision(2) << std::fixed <<
				price << ',' <<
				(tax ? "1" : "0") << ',' <<
				amount;
		}
		return cout;
	}

	std::ifstream& Item::load(std::ifstream& cin)
	{
		char newSku[200];
		char newName[200];
		double newPrice = 0;
		char newTax = '\0';
		int newQuantity = 0;

		cin.getline(newSku, 100, ',');
		cin.getline(newName, 100, ',');

		cin >> newPrice;

		cin.clear();
		cin.ignore();

		cin >> newTax;

		cin.clear();
		cin.ignore();

		cin >> newQuantity;

		if (cin.fail() == false)//Reading file DID NOT fail
		{
			if ((strlen(newSku) > 0) && (newSku[0] == ' '))
			{
				return cin;
			}

			if (strlen(newSku) > MAX_SKU_LEN)
			{
				errorState = ERROR_POS_SKU;
				return cin;
			}

			if (strlen(newName) > MAX_NAME_LEN)
			{
				errorState = ERROR_POS_NAME;
				return cin;
			}

			if (newPrice <= 0)
			{
				errorState = ERROR_POS_PRICE;
				return cin;
			}

			if ((newTax != '1') && (newTax != '0'))
			{
				errorState = ERROR_POS_TAX;
				return cin;
			}

			if ((newQuantity <= 0) || (newQuantity > MAX_STOCK_NUMBER))
			{
				errorState = ERROR_POS_QTY;
				return cin;
			}

			clear();
			if (name != nullptr)
			{
				decon();
			}

			name = new char[strlen(newName) + 1];
			strcpy(name, newName);
			strcpy(sku, newSku);
			price = newPrice;
			tax = (newTax == '1');
			amount = newQuantity;
			errorState.display();
			return cin;
		}
		else
		{
			return cin;
		}
	}

	std::ostream& Item::bprint(std::ostream& cout)const
	{
		std::string newName(name, std::min(static_cast<size_t>(20), strlen(name)));

		cout << "| "
			<< std::left << std::setw(20) << std::setfill(' ') << newName << "|"
			<< std::right << std::setw(10) << std::fixed << std::setprecision(2) << cost() << " |"
			<< "  " << (tax ? "T  " : "   ") << "|" << endl;
		return cout;
	}
}
