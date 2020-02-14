#include <iostream>
using namespace std;
#include "Currencypp.h"
#include "CurrencyFactory.h"
#include <map>

int main()
{
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
		
		Currency* base_curr = curr_fac.GetCurrency(base);
		Currency* foreign_curr= curr_fac.GetCurrency(foreign);

		foreign_amount = base_curr->Convert(*foreign_curr, base_amount);
		cout << "amount in foreign currency: " << foreign_amount << endl;

		//ask the user if they wants to continue
		cout << "Do you wish to continue? Enter 0 to exit and anything else to continue" << endl;
		std::cin >> check;
	}
	return 0;
}