
#include "Point.h"
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

//default constructor
Point::Point()
{
	m_x = 0;
	m_y = 0;
}

//constructor with initialization
Point::Point(double x_input, double y_input)
{
	X(x_input);
	Y(y_input);
}
//copy constructor
Point::Point(const Point& pt)
{
	m_x = pt.m_x;
	m_y = pt.m_y;
}

//destructor
Point::~Point()
{
	//cout << "The destructor is called" << endl;
}

//accessing function
double Point::X() const
{
	return m_x;
}
double Point::Y() const
{
	return m_y;
}

//setting function
void Point::X(double x_input)
{
	m_x = x_input;
}
void Point::Y(double y_input)
{
	m_y = y_input;
}

//tostring function
string Point::ToString() const
{
	stringstream buffer;
	buffer << "Point(" << m_x << "," << m_y << ")" << endl;
	return buffer.str();
}

//distance function

//helper function
double Pythagoras(double x_1, double y_1, double x_2, double y_2)
{
	double distance;
	distance = std::sqrt(pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2));
	return distance;
}
double Point::Distance() const
{
	// Calculate the distance to the origin (0, 0).
	return Pythagoras(m_x, m_y, 0, 0);
}

double Point::Distance(const Point& p) const
{
	// Calculate the distance between two points.
	return Pythagoras(m_x, m_y, p.m_x, p.m_y);
}

//operators from homework 4
Point Point::operator -() const // Negate the coordinates.
{
	//create new object
	Point pt;
	//perform the operation
	pt.X(m_x * (-1));
	pt.Y(m_y * (-1));
	return pt;
}

Point Point::operator * (double factor) const // Scale the coordinates.
{
	//create new object
	Point pt;
	//perform the operation
	pt.X(m_x * factor);
	pt.Y(m_y * factor);
	return pt;
}
Point Point::operator + (const Point& p) const // Add coordinates.
{
	//create new object
	Point pt;
	double x_temp, y_temp;
	//perform operations
	x_temp = m_x + p.X();
	y_temp = m_y + p.Y();
	pt.X(x_temp);
	pt.Y(y_temp);
	return pt;
}
bool Point::operator == (const Point& p) const // Equally compare operator.
{
	//create new object
	Point pt;
	//perform operations
	bool temp = false;
	//if both coordinates are equal, make the boolean variable true, otherwise, remain false
	if (m_x == p.X() && m_y == p.Y())
	{
		temp = true;
	}
	//return the boolean variable whether two points have the same coordinates
	return temp;
}
Point& Point::operator = (const Point& source) // Assignment operator.
{
	m_x = source.X();
	m_y = source.Y();
	return *this;
}
Point& Point::operator *= (double factor) // Scale the coordinates & assign.
{
	m_x = m_x * factor;
	m_y = m_y * factor;
	return *this;
}
//osstream operator without calling ToString function
ostream& operator << (ostream& os, const Point& pt)
{
	// Print the point object
	os << "Point: (" << pt.m_x << "," << pt.m_y << ")";
	return os;
}