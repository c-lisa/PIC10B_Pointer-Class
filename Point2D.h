/** @file Point2D.h
@brief Contains the class declarations for the Points2D class.
@author Lisa Chiang
@date February 24, 2015

Point2D allows the user to create 2D Points that can be shifted by user-inputted amounts. 
The user can also find which quadrant their point is in. Finally, you can print out the point. 
*/

#ifndef Point2D_h 
#define Point2D_h 

class Point2D {
public:
	//Constructors
	Point2D();
	Point2D(double x1, double y2);
	
	//Mutators
	virtual void shift_by(double x_shift, double y_shift);
	
	//Accessors
	virtual int quadrant() const;
	virtual double getx() const; 
	virtual double gety() const; 
	virtual double get_angle() const;
	virtual int rank() const;
	
	virtual void print() const;
	
	//Comparison Operator
	bool operator < (Point2D B); 
	
private:
	double x;
	double y;
	double angle; 
};

#endif
