#include "Person.h"

Person::Person(string name, string email)
	: name_(name), email_(email)
{}

string Person::GetName()
{
	return name_;
}

string Person::GetEmail()
{
	return email_;
}
