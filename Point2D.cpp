/** @file Point2D.cpp
@brief Contains the class definitions for the Point2D class.
@author Lisa Chiang
@date February 24, 2015

The definitions for the constructors and accessor functions for Point2D are here. 
*/

#include <iostream>
#include "Point2D.h"
#include <cmath>
#include "math.h"

//Constructors
/**@brief Point2D Default Constructor

Sets x and y both equal to 0. 

@param No parameters.
@return No returns. 
*/
Point2D::Point2D()
{
	x = 0;
	y = 0;
}
/**@brief Point2D Constructor

Sets private variable x and y to user-inputted doubles respectively. 

@param x1 is what x will be set to. 
@param y2 is what y will be set to. 
@return No returns. 
*/
Point2D::Point2D(double x1, double y2)
{
	x = x1;
	y = y2;
	
	//Calculates angle to the origin in a counterclockwise orientation
	angle = atan2(y, x); 
	
	//Shifts angles in quadrant 3 and 4 2pi
	if (angle < 0)
	{
		angle + 2*3.14; 
	}

}

//Mutators
/**@brief Shifting the Point

Shifts x and y by user-inputted double values respectively. 

@param x_shift is the amount of units x will be shifted. 
@param y_shift is the amount of units y will be shifted. 
@return No returns.
*/
void Point2D::shift_by(double x_shift, double y_shift)
{
	x += x_shift;
	y += y_shift;
}

//Accessors
/**@brief Finding the Quadrant

Finds the quadrant the Point2D object is in. If either 
x or y is on the x-axis or y-axis, the function returns 0 for quadrant. 

@param No parameters. 
@return Returns an int (0, 1, 2, 3, 4) that denotes what quadrant the point is in. 
*/
int Point2D::quadrant() const
{
	//If Quadrant 1 or 4
	if (x > 0)
	{
		//Quadrant 1
		if (y > 0)
		{
			return 1;
		}
		//Quadrant 4
		else if (y < 0)
		{
			return 4;
		}
		//On the line between Quadrant 1 and 4
		else if (y == 0)
		{
			return 0;
		}
	}
	//If Quadrant 2 or 3
	else if (x < 0)
	{
		//Quadrant 2
		if (y > 0)
		{
			return 2;
		}
		//Quadrant 3
		else if (y < 0)
		{
			return 3;
		}
		//In between Quadrant 2 and 3
		else if (y == 0)
		{
			return 0;
		}
	}
	//If x is on the x-axis
	else //x = 0
	{
		return 0;
	}
}
/**@brief Getting x

Allows user to access private variable x. 

@param No parameters.
@return Returns private variable x. 
*/
double Point2D::getx() const
{
	return x;
}
/**@brief Getting y

Allows user to access private variable y.

@param No parameters.
@return Returns private variable y.
*/
double Point2D::gety() const
{
	return y;
}
/**@brief Getting the angle

Allows user to access the angle of point (x,y).

@param No parameters.
@return Returns private variable angle. 
*/
double Point2D::get_angle() const
{
	return angle;
}
/**@brief Ranking the Point

All Point2D points are ranked 1. 

@param No parameters.
@return Returns 1 for Point2D rank.
*/
int Point2D::rank() const
{
	return 1;
}

/**@brief Printing the Point

Prints the point's x and y coordinates. 

@param No parameters.
@return No returns.
*/
void Point2D::print() const
{
	std::cout << "(" << x << "," << y << ")";
}

//Comparison Operator
/**@brief Overloading the < operator

Calculates the distance of both the implicit Point2D object and object B. 
The smaller distance to the origin is the smaller object. If distances are equal, 
then the operator uses the angle (angle to the origin in a counterclockwise orientation). 
The smaller angle is the smaller point. 

@param B is the Point2D object being compared against the implicit object.
@return Returns true if implicit Point2D object is less than object B and false otherwise. 
*/
bool Point2D::operator < (Point2D B)
{
	//if distance of A to origin is < than distance of B to origin 
	if ((sqrt((getx() * getx()) + (gety()*gety()))) < (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		return true; 
	}
	//if distance is equal, then look at angle to origin 
	else if ((sqrt((getx() * getx()) + (gety()*gety()))) == (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		//if angle of A is less than angle of B, then A is < B
		if (get_angle() < B.get_angle())
		{
			return true; 
		}
		else return false; 
	}
	else return false; 
}
