#ifndef Checking_account_H
#define Checking_account_H
using namespace std;
#include <iostream>
#include <string>
class check_account
{
public:
	//default constructor
	check_account();
	//constructor that tkaes the name of the person and also the initial deposit amount
	check_account(string name,double amount);
	//destructor
	~check_account();
	//copy constructor
	check_account(const check_account& ca);
	//accessing function
	double get_balance();
	//setting function
	double deposit(double amt);
	double withdraw(double amt);
private:
	string name_;
	double balance_;

};



#endif