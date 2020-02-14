#include "CurrencyFactory.h"
#include "Currencypp.h"
#include <sstream>
#include <iostream>
using namespace std;
CurrencyFactory::CurrencyFactory()
{
	currencies_[USD] = new Currency("USD", 1.0);
	currencies_[EUR] = new Currency("USD", 0.9);
	currencies_[GBP] = new Currency("USD", 0.77);
	currencies_[CAD] = new Currency("USD", 1.31);
	currencies_[AUD] = new Currency("USD", 1.45);
	currencies_[JPY] = new Currency("USD", 109);
	currencies_[RMB] = new Currency("USD", 6.9);
}
Currency* CurrencyFactory::GetCurrency(int currencyType)
{
	return currencies_[currencyType];
}