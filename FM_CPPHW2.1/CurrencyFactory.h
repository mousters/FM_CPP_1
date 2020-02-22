#ifndef CurrencyFactory_H
#define CurrencyFactory_H
#include "Currencypp.h"
#include <iostream>
using namespace std;

enum CurrencyType { USD = 0, EUR = 1, GBP = 2, CAD = 3, AUD = 4, JPY = 5, RMB = 6 };
class CurrencyFactory
{
public:
	CurrencyFactory();
	Currency* GetCurrency(int currencyType);
	//destructor
	~CurrencyFactory();
private:
	Currency* currencies_[7];

};

#endif