#include <iostream>
using namespace std;
#include "Option.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "AmericanCall.h"
#include "AmericanPut.h"
#include "BinomialTree.h"
#include <algorithm>

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
	EuropeanPut p1(K, T);
	AmericanCall c2(K, T);
	AmericanPut p2(K, T);
	
	BinomialTree t1(S0, r, v, T, N);
	cout << "European Call -- Price: " << t1.Price(c1) << endl;

	cout << "European Put -- Price: " << t1.Price(p1) << endl;

	cout << "American Call -- Price: " << t1.Price(c2) << endl;

	cout << "American Put -- Price: " << t1.Price(p2) << endl;


	return 0;
}