#include "root_estimation.h"
#include <sstream>
#include <iostream>
using namespace std;
//the function
double func(double x)
{
	return x * x * x + x - 1;
}

double func_root()
{
	double x_0 = 0;
	double x_1 = 1;
	//either max iter reached or
	for (int i =0;i<max_iter;i++)
	{
		//or the difference is smaller than 0.0001
		//I can not find the function for the absolute value, so I square both side
		if ((x_1 - x_0)* (x_1 - x_0) < accuracy* accuracy)
		{
			break;
		}
		double temp_x = x_1 - (func(x_1) * (x_1 - x_0)) / (func(x_1) - func(x_0));
		x_0 = x_1;
		x_1 = temp_x;
		//cout << i <<"  "<<x_0 << "  " <<x_1 << "  " << endl;
	}
	return x_1;
}

int main()
{
	double ans = func_root();
	cout << "The estimation of the root of the given function is "<<ans << endl;
	return 0;
}