#ifndef Babylonian_H
#define Babylonian_H
#include <iostream>
using namespace std;
class Babylonian
{
	//constructor
public:
	Babylonian();
	Babylonian(int val);
	void set_iter(int val);
	double estimate();
	void new_x();
private:
	double x_;
	double S_;
	int iter_;
};



#endif