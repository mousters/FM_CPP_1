#pragma once
#include "Person.h"

#include <string>
using std::string;

class Student : public Person
{
public:
	Student(string name, string email, string major);

	string GetMajor();

private:	
	string major_;
};
