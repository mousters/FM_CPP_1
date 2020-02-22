#ifndef Sorter_H
#define Sorter_H
#include <iostream>
using namespace std; 

class Sorter
{
public:
	Sorter();
	static void swap(double* a, double* b);
	static void bubblesort();
	static double arr[];
	static int n;
	static void print_array();
};



#endif