#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	double m_x;	// X coordinate
	double m_y;	// Y coordinate

public:
	//original functions and datas from level 3 hoemwork
		// Constructors
	Point();								// Default constructor
	Point(double xval, double yval);		// Initialize with x and y value

	//copy constructor
	Point(const Point& pt);

	//destructors
	~Point();

	// Accessing functions
	double X() const;					// The x-coordinate
	double Y() const;					// The y-coordinate

	//setting functions
	void X(double x_input);
	void Y(double y_input);

	//tostring function
	string ToString() const;

	//distance function
	double Distance() const; // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p) const; // Calculate the distance between two points.

//operators from level 4 homework

	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	Point& operator = (const Point& source); // Assignment operator.
	Point& operator *= (double factor); // Scale the coordinates & assign.

	//osstream operator without calling ToString function
	friend ostream& operator << (ostream& os, const Point& p); // Send to ostream.

};


#endif