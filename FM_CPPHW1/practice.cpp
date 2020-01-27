#include <stdio.h>
#include <stdlib.h>	
#include <iostream>
#include <sstream>
using namespace std;


int main()
{
	int i = 10;
	int* ip = &i;
	int myarray[]{ 2, 3, 1, 14, 8 };
	cout << *ip << endl;
	return 0;
}