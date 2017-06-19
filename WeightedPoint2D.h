/** @file WeightedPoint2D.h
@brief Contains the class declarations for the WeightedPoints2D class.
@author Lisa Chiang
@date February 9, 2015

WeightedPoint2D allows the user to create 2D Points with weights. It has inherited all the functions
of the Point2D class. 
*/

#ifndef WeightedPoint2D_h
#define WeightedPoint2D_h

#include"Point2D.h" 

class WeightedPoint2D :public Point2D {
public:
	WeightedPoint2D();
	WeightedPoint2D(double init_x, double init_y, double init_weight);
	//~WeightedPoint2D(); //destructor

	//Accessors
	virtual void print() const;

private:
	double weight;
};

#endif

