#include <iostream>
using namespace std;
#pragma once
#include "Fibonacci.h"
#include "Babylonian.h"
#include "Sorter.h"
#include "Prime.h"


double Sorter::arr[] = { 64, 34, 25, 12, 22, 11, 90 };
int Sorter::n = 7;
int main()
{
	cout << "First testing Fibonacci" << endl;
	Fibonacci fib(5);
	fib.set_index(10);
	fib.compute_fib();
	cout << endl;

	cout << "2nd testing Babylonian square root method for 2" << endl;
	Babylonian bab(100);
	bab.set_iter(10);
	double result1=bab.estimate();
	cout << result1 << endl;

	cout << "3rd testing buble sort method" << endl;
	cout << "before sorting" << endl;
	Sorter::print_array();
	cout << endl;
	cout << "after sorting" << endl;
	Sorter::bubblesort();
	Sorter::print_array();
	cout << endl;
	
	cout << "testing prime" << endl;
	check_prime(25) ? cout << " true\n" :
		cout << " false\n";
	
	return 0;
}