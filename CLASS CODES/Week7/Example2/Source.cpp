#include "Derived1.h"


int main()
{
	Base1* bp = new Derived1();
	bp->Fun3();

	Derived1* dp = new Derived1();
	dp->Fun3();
	
}