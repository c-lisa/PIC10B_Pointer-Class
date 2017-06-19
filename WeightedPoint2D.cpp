/** @file WeightedPoint2D.cpp
@brief Contains the class definitions for the WeightedPoint2D class.
@author Lisa Chiang
@date February 9, 2015

The definitions for the constructors and print function for WeightedPoint2D are here.
*/

#include <iostream>
#include "Point2D.h"
#include "WeightedPoint2D.h"

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


//Destructor? 
//WeightedPoint2D::~WeightedPoint2D()
//{
//	delete weight; 
//}
