/** @file WeightedPoint2D.cpp
@brief Contains the class definitions for the WeightedPoint2D class.
@author Lisa Chiang
@date February 24, 2015

The definitions for the constructors and acccessor functions for WeightedPoint2D are here.
*/

#include <iostream>
#include "Point2D.h"
#include "WeightedPoint2D.h"

//Constructors
/**@brief WeightedPoint2D Default Constructor

Inherits x and y variables from Point2D class. Sets weight equal to 0.

@param No parameters.
@return No returns.
*/
WeightedPoint2D::WeightedPoint2D()
{
	weight = 0;
}
/**@brief WeightedPoint2D Constructor

Inherits x and y variables from Point2D class. Sets weight equal to user-inputted double value.

@param init_x is set to private variable x inherited from Point2D class.
@param init_y is set to private variable y inherited from Point2D class.
@param init_weight is set to private variable weight.
@return No returns.
*/
WeightedPoint2D::WeightedPoint2D(double init_x, double init_y, double init_weight) : Point2D(init_x, init_y), weight(init_weight)
{
	weight = init_weight;
}

/**@brief Print Function

Prints the x and y coordinates as well as the weight.

@param No parameters.
@return No returns.
*/
void WeightedPoint2D::print() const
{
	std::cout << weight;
	Point2D::print();
}

//Accessors
/**@brief Getting the weight

Allows user to access the private variable weight.

@param No parameters.
@return Returns private variable weight.
*/
double WeightedPoint2D::get_weight() const
{
	return weight; 
}
/**@brief Ranking the Point

All WeightedPoint2D points are ranked 3.

@param No parameters.
@return Returns 3 for WeightedPoint2D rank.
*/
int WeightedPoint2D::rank() const
{
	return 3; 
}

//Comparison Operator
/**@brief Overloading the < operator

Calculates the distance of both the implicit WeightedPoint2D object and object B.
The smaller distance to the origin is the smaller object. If distances are equal,
then the operator uses the weight to compare which weight is smaller. 

@param B is the WeightedPoint2D object being compared against the implicit object.
@return Returns true if implicit WeightedPoint2D object is less than object B and false otherwise.
*/
bool WeightedPoint2D::operator < (WeightedPoint2D B)
{
	//if distance of A to origin is < than distance of B to origin 
	if ((sqrt((getx() * getx()) + (gety()*gety()))) < (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		return true;
	}
	else if ((sqrt((getx() * getx()) + (gety()*gety()))) == (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		if (get_weight() < B.get_weight())
		{
			return true;
		}
		else return false;
	}
}