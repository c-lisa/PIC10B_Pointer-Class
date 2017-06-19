/** @file Point2D.h
@brief Contains the class declarations for the Points2D class.
@author Lisa Chiang
@date February 9, 2015

Point2D allows the user to create 2D Points that can be shifted by user-inputted amounts. 
The user can also find which quadrant their point is in. Finally, you can print out the point. 
*/

#ifndef Point2D_h 
#define Point2D_h 

class Point2D {
public:
	Point2D();
	Point2D(double x1, double y2);
	//virtual ~Point2D(); //destructor

	//Mutators
	virtual void shift_by(double x_shift, double y_shift);
	
	//Accessors
	virtual int quadrant() const; 
	virtual void print() const;

private:
	double x;
	double y;
};

#endif
