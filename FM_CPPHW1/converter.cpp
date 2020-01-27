#include <iostream>
using namespace std;
#include "currency_converter.h"
#include <map>
map<string, CurrencyType> m = { {"0",USD} , {"1",EUR} ,
{"2",GBP},{"3",CAD},{"4",AUD},{"5",JPY},{"6",RMB} };

int main()
{

	string check = "1";
	while (check != "0")
	{
		enum CurrencyType base_curr, foreign_curr;
		string base, foreign, amount;
		double base_amount, foreign_amount;

		cout << "Please enter the base currency" << endl;
		cout << "Available Currencies are: " << endl;
		cout << " USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 " << endl;
		cin >> base;
		cout << "Please enter the foreign currency in number" << endl;
		cin >> foreign;
		foreign_curr = m.at(foreign);
		cout << "Please enter the currency amount in base currency" << endl;
		cin >> amount;

		base_amount = stod(amount);
		base_curr = m.at(base);
		foreign_curr = m.at(foreign);
		foreign_amount = currency_convert(base_curr, foreign_curr, base_amount);

		cout << "amount in foreign currency: " << foreign_amount << endl;
		cout << "Do you wish to continue? Enter 0 to exit and anything else to continue" << endl;
		cin >> check;
	}
	return 0;
}