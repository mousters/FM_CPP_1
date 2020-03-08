#include <iostream>
using namespace std;
#include "Option.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "MCPricer.h"

int main()
{
	MCPricer MC1;
	cout << "Call section" << endl;
	double S0 = 100;
	double r = 0.01;
	double v = 0.3;
	double K = 100;
	double T = 2;
	EuropeanCall c1(K, T);

	cout << "Call -- Price: (10000 iteration) " << MC1.Price(c1, S0, v, r, 10000) << endl;
	cout << "Call -- Price: (100000 iteration) " << MC1.Price(c1, S0, v, r, 100000) << endl;
	cout << "Call -- Price: (1000000 iteration) " << MC1.Price(c1, S0, v, r, 1000000) << endl;
	cout << "Put section" << endl;
	EuropeanPut p1(K, T);
	
	cout << "Put -- Price: (10000 iteration)" << MC1.Price(p1, S0, v, r, 10000) << endl;
	cout << "Put -- Price: (100000 iteration)" << MC1.Price(p1, S0, v, r, 100000) << endl;
	cout << "Put -- Price: (1000000 iteration)" << MC1.Price(p1, S0, v, r, 1000000) << endl;
	return 0;
}