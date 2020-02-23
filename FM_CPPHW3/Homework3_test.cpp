#include <iostream>
using namespace std;
#include "Currency.h"
#include "CurrencyFactory.h"
#include <map>

int main()
{
	cout << "Implemented Changes" << endl;
	cout << "change #2, new currencyfactory constructor" << endl;
	cout<<"change #4 freestore objects"<<endl;
	cout<<"change #5 delete free store objects to prevent memory leak"<<endl;
	cout << "change #6 use a std::map to store currency objects" << endl;
	cout << "change #7 Using exceptions in currency converter" << endl;
	cout << endl;
	CurrencyFactory curr_fac;
	string check = "1";
	while (check != "0")
	{
		//intialize variables
		int base, foreign;
		double base_amount, foreign_amount;
		//get the information for the base and foreign currency
		cout << "Please enter base currency" << endl;
		cout << "Available Currencies are: " << endl;
		cout << " USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 " << endl;
		cin >> base;
		cout << "Please enter the foreign currency in number" << endl;
		cin >> foreign;
		cout << "Please enter the amount in base currency" << endl;
		cin >> base_amount;
		try
		{
			Currency* base_curr = curr_fac.GetCurrency(base);
			Currency* foreign_curr = curr_fac.GetCurrency(foreign);

			foreign_amount = base_curr->Convert(*foreign_curr, base_amount);
			cout << "amount in foreign currency: " << foreign_amount << endl;

		}
		catch (const std::runtime_error& e)
		{
			cout << "ERROR: Currency Not Found" << endl;
		}
		//ask the user if they wants to continue
		cout << "Do you wish to continue? Enter 0 to exit and anything else to continue" << endl;
		std::cin >> check;
	}
	return 0;
}