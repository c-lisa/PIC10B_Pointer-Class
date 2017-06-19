/** @file Points.h
@brief Contains the class declarations for the Points class.
@author Lisa Chiang
@date February 9, 2015

Points allows the user to store pointers to different objects (Point2D, ColorPoint2D, WeightedPoint2D) and 
access them. 
*/

#ifndef Points_h
#define Points_h

#include"Point2D.h" 
#include <vector>

class Points {
public:
	~Points(); //destructor

	//Mutator
	bool push_back(Point2D* pt);
	
	//Accessor
	std::vector<Point2D*> get_points();

private:
	std::vector<Point2D*> points;
};

#endif
