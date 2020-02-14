#include <iostream>
using namespace std;
#pragma once
#include "Fibonacci.h"
#include "Babylonian.h"
int main()
{
	cout << "First testing Fibonacci" << endl;
	Fibonacci fib(5);
	fib.set_index(10);
	fib.compute_fib();

	cout << "2nd testing Babylonian square root method for 2" << endl;
	Babylonian bab(100);
	bab.set_iter(10);
	double result1=bab.estimate();
	cout << result1 << endl;
	return 0;
}