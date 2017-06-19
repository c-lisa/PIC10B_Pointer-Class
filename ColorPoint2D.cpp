/** @file ColorPoint2D.cpp
@brief Contains the class definitions for the ColorPoint2D class.
@author Lisa Chiang
@date February 24, 2015

The definitions for the constructors and accessor functions for ColorPoint2D are here.
*/

#include <iostream>
#include "Point2D.h"
#include "ColorPoint2D.h"
#include <string>

//Constructors
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

//Accessors
/**@brief Getting the color

Allows user to access the private variable, string color.

@param No parameters.
@return Returns private variable - string color.
*/
std::string ColorPoint2D::get_color() const
{
	return color; 
}
/**@brief Ranking the Point

All ColorPoint2D points are ranked 2.

@param No parameters.
@return Returns 2 for CoorPoint2D rank.
*/
int ColorPoint2D::rank() const
{
	return 2; 
}

//Comparison Operator
/**@brief Overloading the < operator

Calculates the distance of both the implicit ColorPoint2D object and object B.
The smaller distance to the origin is the smaller object. If distances are equal,
then the operator uses the lexicographic ordering of the string characters to determine which 
object is smaller. 

@param B is the ColorPoint2D object being compared against the implicit object.
@return Returns true if implicit ColorPoint2D object is less than object B and false otherwise.
*/
bool ColorPoint2D::operator < (ColorPoint2D B)
{
	//if distance of A to origin is < than distance of B to origin 
	if ((sqrt((getx() * getx()) + (gety()*gety()))) < (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		return true;
	}
	else if ((sqrt((getx() * getx()) + (gety()*gety()))) == (sqrt((B.getx() * B.getx()) + (B.gety() * B.gety()))))
	{
		if (get_color() < B.get_color())
		{
			return true; 
		}
		else return false; 
	}
}

