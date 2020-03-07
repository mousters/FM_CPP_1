#include "Option.h"
#include "MCPricer.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

//constructor
MCPricer::MCPricer(){}
MCPricer::~MCPricer(){}

double MCPricer::box_muller()
{
	double x = static_cast<double>( rand()) / RAND_MAX;
	double y = static_cast<double>( rand()) / RAND_MAX;
	double z = sqrt(-2.0*log(x)) * cos(2 * M_PI*y);
	if (z > 3 || z <-3)
	{
		z = 0;
	}
	return z;
}


double MCPricer::Price(const Option& opt, double StockPrice, double vol, double rate, unsigned long paths)
{
	double T = opt.GetMaturity();
	float sum = 0;
	double m1 = 0;
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned long int i = 0; i <paths;i++)
	{
		double z_i = box_muller();
		double ST_i = StockPrice * exp((rate - vol * vol / 2.0)*T + vol * z_i*sqrt(T));
		double payoff = max(opt.GetExpirationPayoff(ST_i),0.0);
		sum+= payoff;
	}
	cout << sum << endl;
	return (sum/paths);
}