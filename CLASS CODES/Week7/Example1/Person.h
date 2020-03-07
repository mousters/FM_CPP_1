#pragma once

#include <string>
using std::string;

class Person
{
public:
	Person(string name, string email);
	string GetName();
	string GetEmail();

private:
	string name_;
	string email_;
};