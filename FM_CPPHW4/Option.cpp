#include "Option.h"
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;
//constructor
Option::Option(double K, double T): K_(K),T_(T) {}
//desctructor
Option::~Option(){}
//ordinary accessing and setting functions, not used in this
double Option::GetStrike() { return K_; }
double Option::GetMaturity() { return T_; }
void Option::SetStrike(double K) { K_ = K; }
void Option::SetMaturity(double T) { T_ = T; }


//functionality and implementation explanation for these functions
//are provided in the H file
double Option::cdf(double x)
{
	return 0.5*(1 + erf(x / sqrt(2)));
}
double Option::pdf(double x)
{
	return exp(-0.5*pow(x, 2)) / sqrt(2 * M_PI );
}

double Option::d1(double S0, double r, double v)
{
	return log(S0*exp(r*T_) / K_) / (v*sqrt(T_)) + (v*sqrt(T_) / 2);
}
double Option::d2(double S0, double r, double v)
{
	return log(S0*exp(r*T_) / K_) / (v*sqrt(T_)) - (v*sqrt(T_) / 2);
}