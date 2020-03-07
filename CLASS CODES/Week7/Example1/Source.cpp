#include "Student.h"
#include "Employee.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Student s1("joe1", "joe1@uchicago", "math");

	Employee e1("joe2", "joe2@uchicago", "teacher");

	cout << s1.GetMajor() << endl;

	cout << e1.GetJob() << endl;
}