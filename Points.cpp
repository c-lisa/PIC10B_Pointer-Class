/** @file Points.cpp
@brief Contains the class definitions for the Points class.
@author Lisa Chiang
@date February 24, 2015

The definitions for the destructor, push_back, and get_points functions for Point2D are here.
*/

#include <iostream>
#include <vector>
#include "Point2D.h"
#include "Points.h"
#include <algorithm>

/**@brief Points Destructor

Deletes all the pointers to the objects in the private vector points. 

@param No parameters.
@return No returns.
*/
Points::~Points()
{
	//assumes all points lie on heap
	for (auto& x : points)
	{
		delete x;
	}
}
/**@brief Points Push_back

Allows user to push_back pointers to different types of objects (Point2D, 
ColorPoint2D, WeightedPoint2D, etc.)

@param pt is the pointer to a Point2D object.
@return Returns true if object is successfully pushed back and false if pointer already exists or if pointer is NULL. 
*/
bool Points::push_back(Point2D* pt)
{
	for (auto& x : points)
	{
		if (pt == x) //check for matching address
		{
			return false;
		}
	}
	if (pt == nullptr) return false; //making sure pointing at something
	points.push_back(pt);
	return true;
}
/**@brief Accessing Points Vector

Allows user to access private vector of pointers. 

@param No parameters. 
@return Returns a vector of pointers.
*/
std::vector<Point2D*>& Points::get_points()
{
	return points;
}



