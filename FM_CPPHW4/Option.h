#ifndef Option_H
#define Option_H
#include <string>
#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <cmath>

class Option
{
public:
	//constructor
	Option(double K, double T);
	//destructor
	~Option();
	//ordinary accessing and setting functions, not used in this
	//these do not require any other modification, therefore not declared as virtual
	double GetStrike();
	double GetMaturity();
	void SetStrike(double K);
	void SetMaturity(double T);

	//all three these functions exist for both put and call
	//but have have different implementations
	//therefore decalred as virtual
	virtual double Price(double S0, double r, double v) = 0;
	virtual double Delta(double S0, double r, double v) = 0;
	virtual double Gamma(double S0, double r, double v) = 0;
protected:
	//d1 and d2 calculation provided in the slide
	//r is interest rate, v is volatility, all in percentage
	double d1(double S0, double r, double v);
	double d2(double S0, double r, double v);
	//cdf stands for N(x) in the formula
	double cdf(double x);
	//pdf stands for N'(x) in the formula, both provided in the slides
	double pdf(double x);
	//strike price
	double K_;
	//maturity
	double T_;
};



#endif