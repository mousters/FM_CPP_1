#pragma once

#include "Person.h"

#include <string>
using std::string;

class Employee : public Person
{
public:
	Employee(string name, string email, string job);

	string GetJob();

private:
	string job_;
};