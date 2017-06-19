/** @file Point2D.cpp
@brief Contains the class definitions for the Point2D class.
@author Lisa Chiang
@date February 9, 2015

The definitions for the constructors, shift_by, quadrant, and print functions for Point2D are here. 
*/

#include <iostream>
#include "Point2D.h"

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
}
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
/**@brief Printing the Point

Prints the point's x and y coordinates. 

@param No parameters.
@return No returns.
*/
void Point2D::print() const
{
	std::cout << "(" << x << "," << y << ")";
}

//deconstructor? 
//Point2D::~Point2D()
//{
//	delete x;
//	delete y;
//}

