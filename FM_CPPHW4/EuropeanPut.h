#ifndef EuropeanPut_H
#define EuropeanPut_H
#include "Option.h"
#include <iostream>
#include <map>
using namespace std;
#define _USE_MATH_DEFINES
#include <cmath>


class EuropeanPut : public Option
{
public:
	//constructor
	EuropeanPut(double K, double T);
	//desctructor
	~EuropeanPut();
	//calculate put price: K*exp(-rT)*N(-d2)-S0*N(-d1)
	double Price(double S0, double r, double v) override;
	//delta: N(d1)-1
	double Delta(double S0, double r, double v) override;
	//gamma: N'(d1)/(S*v*sqrt(T))
	double Gamma(double S0, double r, double v) override;
};

#endif