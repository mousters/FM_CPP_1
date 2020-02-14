
#ifndef Circle_H
#define Circle_HPP
#include "Point.h"
#include <iostream>
using namespace std;

class Circle
{
private:
	Point p_center;
	double radius;
public:
	// Constructors
	Circle();								// Default constructor
	Circle(Point c, double r);		// Initialize with two points

	//copy constructor
	Circle(const Circle& cir);

	//destructors
	~Circle();

	//accessing function (selector)
	double Radius() const;		//get the radius of the circle
	Point CenterPoint() const;	//get the center point of the circle
	double Diameter() const;   //get the diameter of the circle 
	double Area() const;   // get the area of the circle
	double Circumference() const; //get the circumference of the circle 


	//setting fucntion (modifier)
	void Radius(double r);    //modify the radius
	void CenterPoint(Point pt);    // set the center point of the circle

	//to string function
	string ToString() const;


	//level 4 assignement operator
	Circle& operator=(const Circle& source);

	//osstream operator without calling ToString function
	friend ostream& operator << (ostream& os, const Circle& cir); // Send to ostream.
};


#endif