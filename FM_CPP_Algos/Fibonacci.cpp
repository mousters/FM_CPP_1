#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include "Fibonacci.h"
using namespace std;
//default constructor
Fibonacci::Fibonacci(): first_(0),second_(1),index(0),cnt_(0){}

Fibonacci::Fibonacci(int index) : first_(0), second_(1), index(index),cnt_(0){}
//destructors
Fibonacci::~Fibonacci(){}
//compute
void Fibonacci::compute_fib()
{
	for (int i = 0; i < index; i++)
	{
		Fibonacci::sum_and_print();
	}
}
void Fibonacci::set_first(int val) { first_ = val; }
void Fibonacci::set_second(int val) { second_ = val; }
void Fibonacci::set_index(int val) { index = val; }
void Fibonacci::sum_and_print()
{
	if (cnt_ == 0)
	{
		cout << 0 <<" ";
	}
	else if (cnt_ == 1)
	{
		cout << 1<<" ";
	}
	else
	{
		int temp = second_ + first_;
		cout << temp << "  ";
		Fibonacci::set_first(second_);
		Fibonacci::set_second(temp);
	}
	
	cnt_++;
}