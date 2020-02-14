#include "Prime.h"
#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool check_prime(int val)
{
	if (val < 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < val; i++)
		{
			if (val % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}