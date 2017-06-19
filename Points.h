/** @file Points.h
@brief Contains the class declarations for the Points class.
@author Lisa Chiang
@date February 24, 2015

Points allows the user to store pointers to different objects (Point2D, ColorPoint2D, WeightedPoint2D) and 
access them. 
*/

#ifndef Points_h
#define Points_h

#include"Point2D.h" 
#include <vector>

class Points{
public:
	//Destructor
	~Points(); 

	//Mutator
	bool push_back(Point2D* pt);
	
	//Accessor
	std::vector<Point2D*>& get_points(); //was returning by copy/value rather than reference

private:
	std::vector<Point2D*> points;
};

#endif
