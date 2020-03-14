#include "Option.h"
#include "EuropeanCall.h"
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
//constructor
EuropeanCall::EuropeanCall(double K, double T) :Option(K, T) {}
//desctructor
EuropeanCall::~EuropeanCall() {}

//functionality and implementation explanation for these functions
//are provided in the H file
double EuropeanCall::Price(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double d_2 = this->d2(S0, r, v);
	double v_call = S0 * this->cdf(d_1) - K_ * exp(-r * T_)*this->cdf(d_2);
	return v_call;
}
double EuropeanCall::Delta(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	return this->cdf(d_1);
}
double EuropeanCall::Gamma(double S0, double r, double v)
{
	double d_1 = this->d1(S0, r, v);
	double N_d = this->pdf(d_1);
	double gam = N_d / (S0*v*sqrt(T_));
	return gam;
}

double EuropeanCall::GetExpirationPayoff(double ST) const
{
	return max(ST - K_,0.0);
}
double EuropeanCall::GetIntermediatePayoff(double ST,double dist_Payoff) const
{
	return max(ST - K_,dist_Payoff);
}