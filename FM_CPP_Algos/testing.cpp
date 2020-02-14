#include <iostream>
using namespace std;
#pragma once
#include "Fibonacci.h"
#include "Babylonian.h"
#include "Sorter.h"
#include "Prime.h"
#include "Point.h"
#include "Circle.h"
#include "Stock.h"

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
	Babylonian bab(2);
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
	
	cout << "4th testing prime" << endl;
	check_prime(25) ? cout << " true\n" :
		cout << " false\n";
	
	cout << "5th testing circle" << endl;
	
	Circle cir;
	cir.Radius(2);
	cout << cir.ToString() << " has the area of " << cir.Area() << endl;
	
	cout << "6th test stock" << endl;
	Stock APPL("APPL", 800.2);
	Stock AMZ("AMZ", 900.12);
	cout << "I can buy this many apple shares with 10k " << APPL.buy_shares(10000) << endl;
	return 0;
}