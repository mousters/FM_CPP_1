#include "Babylonian.h"
#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//default constructor
Babylonian::Babylonian(): x_(0),S_(0),iter_(0){}
//constructor
Babylonian::Babylonian(int val)
{
	x_ = std::to_string(val).length()*100;
	S_ = val;
	iter_ = 5;
}
void Babylonian::set_iter(int val) { iter_ = val; }
void Babylonian::new_x()
{
	x_ = 0.5*(x_ + S_ / x_);
}
double Babylonian::estimate()
{
	for (int i = 0; i < iter_; i++)
	{
		Babylonian::new_x();
	}
	return x_;
}