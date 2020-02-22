#include "CurrencyFactory.h"
#include "Currency.h"
#include <sstream>
#include <iostream>
using namespace std;

CurrencyFactory::CurrencyFactory()
{
	/*
	change #4 freestore objects
	*/
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
//destructor
CurrencyFactory::~CurrencyFactory()
{
	/*
		change #5 delete free store objects to prevent memory leak
	*/
	for (int i = 0; i < 7; i++)
	{
		delete currencies_[i];
	}
}