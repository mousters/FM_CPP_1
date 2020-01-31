#pragma once

#ifndef Currency_H
#define Currency_H
#include <string>
#include <iostream>
using namespace std;

class Currency
{

public:
	// Constructors
	Currency();								// Default constructor

	//constructors with parameters
	Currency(string symbol, double rate);

	//copy constructor
	Currency(const Currency& cc);

	//destructors
	~Currency();

	//assignment operator
	Currency& operator=(const Currency& cc);

	// Accessing functions
	string GetSymbol();
	double GetExchangeRate();

	//setting functions
	void SetExchangeRate(double rate);
	
	//calculating functions
	//ouble ConvertToUSD(double amount);
	//conversion main
	double Convert( Currency foreign, double amount);
	double ConvertFromUSD(double amount);
	double ConvertToUSD(double amount);
	
private:
	string symbol_;
	double exchangeRate_;


};



#endif