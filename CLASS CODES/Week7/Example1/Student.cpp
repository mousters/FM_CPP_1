#include "Student.h"

#include <iostream>
using std::cout;
using std::endl;

Student::Student(string name, string email, string major)
	: Person(name, email), 
	major_(major)
{
}

string Student::GetMajor()
{
	return major_;
}