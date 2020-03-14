#include "Option.h"
#include "AmericanCall.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
//constructor
AmericanCall::AmericanCall(double K, double T) :Option(K, T) {}
//desctructor
AmericanCall::~AmericanCall() {}

//functionality and implementation explanation for these functions
//are provided in the H file
double AmericanCall::Price(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double d_2 = this->d2(S0, r, v);
	double v_call = S0 * this->cdf(d_1) - K_ * exp(-r * T_)*this->cdf(d_2);
	return v_call;
}
double AmericanCall::Delta(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	return this->cdf(d_1);
}
double AmericanCall::Gamma(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double N_d = this->pdf(d_1);
	double gam = N_d / (S0*v*sqrt(T_));
	return gam;
}

double AmericanCall::GetExpirationPayoff(double ST) const
{
	return max(ST - K_, 0.0);
}

double AmericanCall::GetIntermediatePayoff(double ST, double dist_Payoff) const
{
	return max(ST - K_, dist_Payoff);
}