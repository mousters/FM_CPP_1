#include <iostream>
using namespace std;
#include "Option.h"
#include "EuropeanCall.h"
int main()
{
	cout << "Call section" << endl;
	double S0 = 100;
	double r = 0.05;
	double v = 0.3;
	double K = 100;
	double T = 1;
	EuropeanCall c1(K, T);
	/*
	c1.SetMaturity(2);
	c1.SetStrike(150);
	cout << c1.GetMaturity() << " " << c1.GetStrike() << endl;*/

	cout <<"Call -- Price: "<< c1.Price(S0, r, v) <<
	", Delta: "<<c1.Delta(S0, r, v) <<
	", Gamma: "<< c1.Gamma(S0, r, v) << endl;
	cout << "Put section" << endl;
	S0 = 120;
	r = 0.1;
	v = 0.4;
	K = 120;
	T = 2;
	EuropeanCall p1(K, T);
	cout << "Put -- Price: " << p1.Price(S0, r, v) <<
		", Delta: " << p1.Delta(S0, r, v) <<
		", Gamma: " << p1.Gamma(S0, r, v) << endl;


	return 0;
}