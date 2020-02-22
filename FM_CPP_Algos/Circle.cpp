
#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"
#include "Point.h"
#include <sstream>
#include <iostream>
using namespace std;

//default constructor
Circle::Circle()
{
	p_center = Point(0, 0);
	radius = 1;
}

//proper constructor
Circle::Circle(Point pt, double rad)
{
	p_center = pt;
	radius = rad;
}
//copy constructor
Circle::Circle(const Circle& cir)
{
	p_center = cir.p_center;
	radius = cir.radius;
}

//destructor
Circle::~Circle()
{

}

//selectors
//the function return what the function name suggest
double Circle::Radius() const
{
	return radius;
}
Point Circle::CenterPoint() const
{
	return p_center;
}
double Circle::Diameter() const
{
	return (radius * 2);
}

double Circle::Area() const
{
	return (radius * radius * M_PI);

}
double Circle::Circumference() const
{
	return (2 * radius * M_PI);

}

//modifiers
//change radius
void Circle::Radius(double r)
{
	radius = r;
}
//change center point
void Circle::CenterPoint(Point pt)
{
	p_center = pt;
}
string Circle::ToString() const
{
	stringstream buffer;
	buffer << "The Circle has the center point " << p_center.ToString() << " and radius " << radius << " ." << endl;
	return buffer.str();
}
//level 4 assignment operator
Circle& Circle::operator=(const Circle& source)
{
	p_center = source.CenterPoint();
	radius = source.Radius();
	return *this;
}
//level 4
//osstream operator without calling ToString function
ostream& operator << (ostream& os, const Circle& cir) // Send to ostream.
{
	// Print the point object
	os << "Circle: [ Central Point: " << cir.p_center << " and radius: " << cir.radius << "]" << endl;
	return os;
}

