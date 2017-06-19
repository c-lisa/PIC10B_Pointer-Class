/** @file ColorPoint2D.h
@brief Contains the class declarations for the ColorPoints2D class.
@author Lisa Chiang
@date February 24, 2015

ColorPoint2D allows the user to create 2D Points with color names. It has inherited all the functions
of the Point2D class. The user can also tell if the color is blue. 
*/

#ifndef ColorPoint2D_h
#define ColorPoint2D_h

#include"Point2D.h" 
#include<string>

class ColorPoint2D :public Point2D {
public:
	//Constructors
	ColorPoint2D();
	ColorPoint2D(double init_x, double init_y, std::string init_color);
		
	virtual void print() const;
	virtual bool is_blue() const;
	
	//Accessors
	virtual std::string get_color() const; 
	virtual int rank() const;
	
	//Comparison Operator
	bool operator < (ColorPoint2D B);

private:
	std::string color;
};
#endif
