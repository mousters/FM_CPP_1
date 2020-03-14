#include <iostream>
using namespace std;
#include "Option.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "BinomialTree.h"

int main()
{
	cout << "Call section" << endl;
	double S0 = 100;
	double r = 0.05;
	double v = 0.3;
	double K = 100;
	double T = 1;

	int N = 1000;
	EuropeanCall c1(K, T);

	cout << "Call -- Price:  " << c1.Price(S0,r,v) << endl;
	EuropeanPut p1(K, T);

	cout << "Call -- Price: " << p1.Price(S0, r, v) << endl;
	
	BinomialTree t1(S0, r, v, T, N);
	cout << "Call -- Price: " << t1.Price(c1) << endl;

	cout << "Call -- Price: " << t1.Price(p1) << endl;

	return 0;
}