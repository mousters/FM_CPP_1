#pragma once

#include <vector>
#include "Option.h"

using std::vector;

//a node is used to store a stock price and an option price
struct Node
{
	double S;
	double C;
};

class BinomialTree
{
public:
	BinomialTree(double S, double rate,
		double vol, double time, int steps);

	double Price(const Option& option);

private:
	void buildTree();

	// Member variables
	double S0_;
	double r_;
	double q_;
	double v_;
	double T_;
	int N_;

	// Member variables to store pre-calculations
	double nu_;
	double disc_;
	double dt_;
	double sqrt_dt_;

	// Tree data structure
	//nodes belong to a given time index (i.e. vertical nodes in the tree)
	//we use a vector to store them
	using NodesAtTimeStep = vector<Node>;

	//tree is a collection of vertial nodes
	//we use a vector to store them
	using Tree = vector<NodesAtTimeStep>;

	Tree tree_;
};
