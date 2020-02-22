#include "check_account.h"
#include <sstream>
#include <iostream>
using namespace std;
#include <string>
//constructor
check_account::check_account() : name_(""), balance_(0) {}
check_account::check_account(string name, double amount)
{
	//check if the input is illegal
	if (amount < 0)
	{
		cout << "You have entered a negative initial deposit amount, an account with you name" <<
			" and zero balance is created instead" << endl;
		name_ = name;
		balance_ = 0;
	}
	name_ = name;
	balance_ = amount;


}
//destructor
check_account::~check_account(){}
//copy constructor 
//this is not really needed for the purpose of the required operation, but may be useful in 
//some situation
check_account::check_account(const check_account& ca) : 
	name_(ca.name_), balance_(ca.balance_) {}
//accessing function

double check_account::get_balance()
{
	return balance_;
}

//setting function
//deposit
//the double return type allows the client to check the balance right after they perform any action
double check_account::deposit(double amt)
{
	balance_ += amt;
	return balance_;
}
//withdraw
//the double return type allows the client to check the balance right after they perform any action
double check_account::withdraw(double amt)
{
	double withdraw_amt = 0;
	if (amt > balance_)
	{
		withdraw_amt = balance_;
		cout << "The withdraw amount exceed the current balance, only " << withdraw_amt << " is withdrawn and "
			<< "the balance is zero now" << endl;
		//set the balance to zero
		balance_ = 0;
	}
	//if the withdraw amount is smaller than or equal to the current balance:
	else
	{ 
		balance_ -= amt;
		cout << amt << " has been withdrawn from the account and the remaining balance is " << balance_ << endl;
	}
	return balance_;
}