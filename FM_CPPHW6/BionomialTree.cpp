#include "BinomialTree.h"
#include <iostream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>


using std::cout;
using std::endl;

BinomialTree::BinomialTree(double S, double rate,
	double vol, double time, int steps)
	: S0_(S),
	r_(rate),
	v_(vol),
	T_(time),
	N_(steps)
{
	// Precalculations
	dt_ = T_ / N_;
	nu_ = r_ - 0.5*v_*v_;
	disc_ = exp(-r_ * dt_);
	sqrt_dt_ = sqrt(dt_);

	buildTree();
}

void BinomialTree::buildTree()
{
	// Step 1
	//Create/initialize the Tree

	//we have N+1 time steps, i.e. N+1 vectors for each time step
	//"resize" the container to make room for (N+1) vectors
	tree_.resize(N_ + 1);

	//the "i"th vector should have (i+1) Nodes where i is the time index
	for (long i = 0; i <= N_; i++)
	{
		tree_[i].resize(i + 1);
	}

	// Step 2
	//Populate stock prices
	//we access the first and second elements in a pair using first and second fields
	tree_[0][0].S = S0_;

	//i: is horizontal time index
	//we go from left to right

	for (int i = 1; i <= N_; i++)
	{
		//Eqn 6
		//St(D, t+dt) = St*exp((nu)dt - sigma*sqrt(dt)), 
		//where nu = r-0.5*sigma*sigma
		tree_[i][0].S = tree_[i - 1][0].S*exp(nu_*dt_ - v_ * sqrt_dt_);  //Eqn 6

		//SU / SD = exp(2 * v*sqrt(dt));
		//SU = SD * exp( j * 2 * v*sqrt(dt));  //where j=1 .. i
		double SU_SD_level = 2 * v_*sqrt_dt_;
		//j is vertical index
		for (int j = 1; j <= i; ++j)
		{
			tree_[i][j].S = tree_[i][0].S*exp(j* SU_SD_level);
		}
	}
}

double BinomialTree::Price(const Option &option)
{
	/*
	cout << "Stock Price" << endl;
	for (int i = 0; i <= N_; i++)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << tree_[i][j].S << endl;
		}

	}
	*/


	// Step 3
	//Calculate option payoffs at t=T
	//j is vertical index: goes from 0 to N because we have N+1 nodes
	//cout << "Rightmost level" << endl;
	for (int j = 0; j < N_ + 1; ++j)
	{
		tree_[N_][j].C = option.GetExpirationPayoff(tree_[N_][j].S);
		//cout << tree_[N_][j].C << endl;
	}

	// Step 4
	//Back propagation
	//ir is index i in reverse direction (we go from right to left)
	//cout << "each step" << endl;
	for (int ir = N_ - 1; ir >= 0; --ir)
	{
		//inner loop to populate option payoffs at each time index
		for (int j = 0; j <= ir; ++j)
		{
			//use Equation 8 to find the discounted expected payoff using 
			//two adjacent option prices
			double discountedExpectedPayoff = (0.5*tree_[ir + 1][j].C + 0.5*tree_[ir + 1][j + 1].C)*exp(-1 * r_*dt_);

			//We also need the stock price at the node for path dependant options.
			double St = tree_[ir][j].S;
			//find the payoff at the node. 
			tree_[ir][j].C = option.GetIntermediatePayoff(St, discountedExpectedPayoff);
			//cout << tree_[ir][j].C << endl;
		}
	}

	//return the option price
	return tree_[0][0].C;
}

