#pragma once
#include "Currency.h"
#include <sstream>
#include <iostream>
using namespace std;

//constructors
//default
Currency::Currency() :symbol_(""), exchangeRate_(0.0){}
//with paramters
Currency::Currency(string symbol, double rate) : symbol_(symbol), exchangeRate_(rate){}
//destructors
Currency::~Currency(){}
//copy constructors
Currency::Currency(const Currency& cc) : symbol_(cc.symbol_),exchangeRate_(cc.exchangeRate_){}
//assignment operator

Currency& Currency::operator=(const Currency& cc)
{
	symbol_ = cc.symbol_;
	exchangeRate_ = cc.exchangeRate_;
	return *this;
}



//accessing function
string Currency::GetSymbol()
{
	return symbol_;
}
double Currency::GetExchangeRate()
{
	return exchangeRate_;
}

//setting function
void Currency::SetExchangeRate(double rate)
{
	exchangeRate_ = rate;
}

//calculating functions
double Currency::ConvertFromUSD(double amount)
{
	return amount * exchangeRate_;
}
double Currency::ConvertToUSD(double amount)
{
	return amount / exchangeRate_;
}
double Currency::Convert(Currency foreign, double amount)
{
	return foreign.ConvertFromUSD(this->ConvertToUSD(amount));
}

