#include "check_account.h"
#include <sstream>
#include <iostream>
using namespace std;
#include <string>
int main()
{
	//The question description listed which person did what on each day
	//but date is not really relevant to the checking account
	//so I just perform each action by sequence
	//Jane opens an account with 1000$ on day 1
	check_account Jane("Jane", 1000);
	//Jane desposits 500 on day2
	Jane.deposit(500);
	double curr_balance = Jane.get_balance();
	//display the current balance in janes' account at the end of day2
	cout << "Jane's balance is currently : " << curr_balance << endl;
	//jane withdraws 250 on day3
	Jane.withdraw(250);
	curr_balance = Jane.get_balance();
	//display current balance in Jane's account at the end of day 3
	cout << "Jane's balance is currently : " << curr_balance << endl;
	
	/*
	 for debugging purpose
	check_account John("John",-100);
	John.deposit(100);
	John.deposit(200);
	John.withdraw(1000);
	cout << John.get_balance() << endl;
	*/
	return 0;
}