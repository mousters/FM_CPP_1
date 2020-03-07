#ifndef MCPricer_H
#define MCPricer_H
#include <iostream>
using namespace std;
#include "Option.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


class MCPricer
{
public:
	//constructor
	MCPricer();
	//destructor
	~MCPricer();
	//pricer
	double Price(const Option& opt, double StockPrice, double vol, double rate, unsigned long paths);
private:
	double box_muller();
};

#endif