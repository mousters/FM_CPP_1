#include <iostream>
using namespace std;
#include "Currency.h"
#include <map>

//instead of switch, use map to quickly locate the symbol as well as exchange rate
map<int, string> m = {{0,"USD"} , {1,"EUR"} ,
{2,"GBP"},{3,"CAD"},{4,"AUD"},{5,"JPY"},{6,"RMB"} };
//exchange rate are completely self-picked
map<int, double> conv_rate = { {0,1} , {1,0.9} ,
		{2,0.77},{3,1.31},{4,1.45},{5,109},{6,6.9} };

int main()
{
	//testing the functionality of the class
	/*
	int c1, c2, amt;
	c1 = 5;
	c2 = 2;
	amt = 100;
	Currency base_curr(m.at(c1),0.0);
	Currency foreign_curr(m.at(c2), 0.0);
	Currency copy_curr;
	base_curr.SetExchangeRate(conv_rate.at(c1));
	foreign_curr.SetExchangeRate(conv_rate.at(c2));
	
	copy_curr = base_curr;
	if (amt / conv_rate.at(c1)*conv_rate.at(c2) == copy_curr.Convert(foreign_curr, amt))
	{
		cout << "basic functionality is passed" << endl;
	}
	*/

	//check if need to continue after each iteration
	string check = "1";
	while (check != "0")
	{
		//intialize variables
		int base, foreign;
		double base_amount, foreign_amount;
		//get the information for the base and foreign currency
		cout << "Please enter the base currency" << endl;
		cout << "Available Currencies are: " << endl;
		cout << " USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 " << endl;
		cin >> base;
		cout << "Please enter the foreign currency in number" << endl;
		cin >> foreign;
		cout << "Please enter the amount in base currency" << endl;
		cin >> base_amount;


		//create base and foreign currency based on the user input
		Currency base_curr(m.at(base), conv_rate.at(base));
		Currency foreign_curr(m.at(foreign), conv_rate.at(foreign));
		//calculate the conversion, from the base currency to foreign currency given amount
		foreign_amount = base_curr.Convert(foreign_curr, base_amount);
		cout << "amount in foreign currency: " << foreign_amount << endl;

		//ask the user if they wants to continue
		cout << "Do you wish to continue? Enter 0 to exit and anything else to continue" << endl;
		std::cin >> check;
	}
	return 0;
}