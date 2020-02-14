#ifndef Stock_H
#define Stock_H
using namespace std;
#include <iostream>
#include <string>
class Stock
{
public:
	Stock();
	Stock(string symbol, double price);
	~Stock();
	string GetSymbol();
	double GetPrice();
	int buy_shares(double amount);
private:
	string symbol_;
	double price_;
};
#endif // !Stock_H
