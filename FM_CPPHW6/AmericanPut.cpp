#include "Option.h"
#include "AmericanPut.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;
//constructor
AmericanPut::AmericanPut(double K, double T) :Option(K, T) {}
//destructor
AmericanPut::~AmericanPut() {}

double AmericanPut::Price(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double d_2 = this->d2(S0, r, v);
	double v_put = K_ * exp(-r * T_)* this->cdf(-d_2) - S0 * this->cdf(-d_1);
	return v_put;
}
double AmericanPut::Delta(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	return this->cdf(d_1) - 1;
}
double AmericanPut::Gamma(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double N_d = this->pdf(d_1);
	double gam = N_d / (S0*v*sqrt(T_));
	return gam;
}
double AmericanPut::GetExpirationPayoff(double ST) const
{
	return max(K_ - ST, 0.0);
}

double AmericanPut::GetIntermediatePayoff(double ST, double dist_Payoff) const
{
	return max(K_-ST, dist_Payoff);
	
}