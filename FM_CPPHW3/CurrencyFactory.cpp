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
	/*
	change #2, new currencyfactory constructor
	*/
	currencies_[0] = new Currency("USD", 1.0);
	currencies_[1] = new Currency("USD", 0.9);
	currencies_[2] = new Currency("USD", 0.77);
	currencies_[3] = new Currency("USD", 1.31);
	currencies_[4] = new Currency("USD", 1.45);
	currencies_[5] = new Currency("USD", 109);
	currencies_[6] = new Currency("USD", 6.9);
}
Currency* CurrencyFactory::GetCurrency(int currency_num)
{
	auto iter = currencies_.find(currency_num);
	if (iter == currencies_.end())
	{
		throw std::runtime_error("Currency Not Found");
	}
	//return currencies_[currency_num];
	return iter->second;
}
//destructor
CurrencyFactory::~CurrencyFactory()
{
	/*
		change #5 delete free store objects to prevent memory leak
	*/
	for (auto iter=currencies_.begin();iter!=currencies_.end();++iter)
	{
		delete iter->second;
	}
}