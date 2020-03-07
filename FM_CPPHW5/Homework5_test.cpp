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
	cout << "Call -- Price: " << c1.Price(S0, r, v) <<
		", Delta: " << c1.Delta(S0, r, v) <<
		", Gamma: " << c1.Gamma(S0, r, v) << endl;
	cout << "Call -- Price: " << MC1.Price(c1, S0, v, r, 1000000) << endl;


	cout << "Put section" << endl;
	EuropeanPut p1(K, T);
	cout << "Put -- Price: " << p1.Price(S0, r, v) <<
		", Delta: " << p1.Delta(S0, r, v) <<
		", Gamma: " << p1.Gamma(S0, r, v) << endl;
	cout << "Put -- Price: " << MC1.Price(p1, S0, v, r, 1000000) << endl;
	return 0;
}