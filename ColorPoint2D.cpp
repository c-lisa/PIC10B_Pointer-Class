/** @file ColorPoint2D.cpp
@brief Contains the class definitions for the ColorPoint2D class.
@author Lisa Chiang
@date February 9, 2015

The definitions for the constructors, is_blue, and print for ColorPoint2D are here.
*/

#include <iostream>
#include "Point2D.h"
#include "ColorPoint2D.h"
#include <string>

/**@brief ColorPoint2D Default Constructor

Inherits x and y variables from Point2D class. Sets color equal to empty string. 

@param No parameters.
@return No returns.
*/
ColorPoint2D::ColorPoint2D()
{
	color = "";
}
/**@brief ColorPoint2D Constructor

Inherits x and y variables from Point2D class. Sets color equal to user-inputted string name.

@param init_x is set to private variable x inherited from Point2D class.
@param init_y is set to private variable y inherited from Point2D class.
@param init_color is set to private variable color. 
@return No returns.
*/
ColorPoint2D::ColorPoint2D(double init_x, double init_y, std::string init_color) : Point2D(init_x, init_y), color(init_color)
{
	color = init_color;
}
/**@brief Print Function

Prints the x and y coordinates as well as the color. 

@param No parameters. 
@return No returns.
*/
void ColorPoint2D::print() const
{
	std::cout << color;
	Point2D::print();
}
/**@brief Is it Blue? 

Lets user know if the inputted color is blue. 

@param No parameters.
@return Returns true if color is blue and false if not blue. 
*/
bool ColorPoint2D::is_blue() const
{
	if (color == "blue" || color == "Blue")
	{
		return true;
	}
	else return false;
}

//Destructor? 
//ColorPoint2D::~ColorPoint2D()
//{
//	delete color; 
//}

