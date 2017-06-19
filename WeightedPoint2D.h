/** @file WeightedPoint2D.h
@brief Contains the class declarations for the WeightedPoints2D class.
@author Lisa Chiang
@date February 24, 2015

WeightedPoint2D allows the user to create 2D Points with weights. It has inherited all the functions
of the Point2D class. 
*/

#ifndef WeightedPoint2D_h
#define WeightedPoint2D_h

class WeightedPoint2D :public Point2D {
public:
	//Constructors
	WeightedPoint2D();
	WeightedPoint2D(double init_x, double init_y, double init_weight);
	
	virtual void print() const;

	//Accessors
	virtual double get_weight() const; 
	virtual int rank() const; 

	//Comparison Operator
	bool operator < (WeightedPoint2D B); 
	
private:
	double weight;
};

#endif

