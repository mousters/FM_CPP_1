#ifndef Fibonacci_H
#define Fibonacci_H
#include <iostream>
using namespace std;
class Fibonacci
{
public:
	Fibonacci(); // constructor
	Fibonacci(int index); // constructor with params
	~Fibonacci();
	void compute_fib();
	void sum_and_print();
	int index;
	//setter
	void set_first(int val);
	void set_second(int val);
	void set_index(int val);
private:
	int first_;
	int second_;
	int cnt_;
};

#endif
