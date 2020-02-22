#include "Sorter.h"
#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//default constructor
Sorter::Sorter(){}
//constructor

void Sorter::swap(double *x,double *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void Sorter::bubblesort()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

}
void Sorter::print_array()
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " , ";
	}
}