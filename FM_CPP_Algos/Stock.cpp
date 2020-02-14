#include "Stock.h"
#include <sstream>
#include <iostream>
using namespace std;

Stock::Stock(): symbol_("NA"),price_(0){}
Stock::Stock(string sy,double p): symbol_(sy),price_(p){}
Stock::~Stock(){}
double Stock::GetPrice() { return price_; }
string Stock::GetSymbol() { return symbol_; }
int Stock::buy_shares(double amt)
{
	int num_shares = static_cast<int>(amt / price_);
	return num_shares;
}