#ifndef EuropeanCall_H
#define EuropeanCall_H
#include "Option.h"
#include <iostream>
#include <map>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


class EuropeanCall : public Option
{
public:
	//constructor
	EuropeanCall(double K, double T);
	//destructor
	~EuropeanCall();
	//implement pure virtual functions, implementation provided by the slide
	//calculate the price: S0*N(d1)-K*exp(-rT)N(d2)
	double Price(double S0, double r, double v) override;
	//calculate the delta of call: N(d1)
	double Delta(double S0, double r, double v) override;
	//gamma: N'(d1)/(S*v*sqrt(T))
	double Gamma(double S0, double r, double v) override;

	double GetExpirationPayoff(double ST) const override;
	double GetIntermediatePayoff(double St, double discountedExpectedPayoff) const override;
};

#endif