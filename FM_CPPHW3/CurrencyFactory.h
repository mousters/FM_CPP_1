#ifndef CurrencyFactory_H
#define CurrencyFactory_H
#include "Currency.h"
#include <iostream>
using namespace std;

/*
Change #2: relocate Currency object creation to a class
(CurrencyFactory)
*/
enum CurrencyType { USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 };
class CurrencyFactory
{
public:
	CurrencyFactory();
	Currency* GetCurrency(int currencyType);
	//destructor
	~CurrencyFactory();
private:
	/*
	change #2, new currencyfactory constructor
	*/
	Currency* currencies_[7];

};

#endif