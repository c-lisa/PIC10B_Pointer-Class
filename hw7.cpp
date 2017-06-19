/** @file main.cpp
@brief Creates and outputs different types of points.
@author Lisa Chiang
@date February 24, 2015

Allows the user to create different types of 2D points (Point2D, ColorPoint2D, WeightedPoint2D, etc.), 
stores the points in a vector, and then outputs these points onto the console in ascending order. 
*/

#include<iostream>
#include<string>
#include<vector>
#include"Point2D.h"
#include"ColorPoint2D.h"
#include"WeightedPoint2D.h"
#include"Points.h"
#include <algorithm>

//non-member function declaration for comparison - used in sort function
bool comparison(Point2D* p1, Point2D*p2); 

int main() {
	std::cout << "Welcome to the Point Printer! You can create three different kinds of points: " << std::endl << std::endl;
	std::cout << "1. Point2D, e.g., (2,6.5)" << std::endl; 
	std::cout << "2. ColorPoint2D, e.g., blue(-4.5,3.5)" << std::endl;
	std::cout << "3. WeightedPoint2D, e.g., .12(3.6,8.7)" << std::endl << std::endl;
	std::cout << "Enter 0 when you are finished." << std::endl << std::endl;

	Points pointers; 
	int selection; int counter = 0; 
	
	//Storing the different types of points into a vector
	do
	{
		std::cout << "Selection: ";
		std::cin >> selection;
				
		if (selection == 1)
		{
			double x, y; 
			std::cout << "x = "; 
				std::cin >> x; 
			std::cout << "y = "; 
				std::cin >> y; 
				std::cin.ignore();
			
			pointers.push_back(new Point2D(x, y));
			
			++counter; 
		}
		else if (selection == 2)
		{
			double x, y; 
			std::string color; 
			std::cout << "x = ";
				std::cin >> x; 
			std::cout << "y = ";
				std::cin >> y; 
				std::cin.ignore(); 
			std::cout << "color = "; 
				std::getline(std::cin, color); 
			
			pointers.push_back(new ColorPoint2D(x, y, color));

			++counter;
		}
		else if (selection == 3)
		{
			double x, y;
			double weight; 

			std::cout << "x = ";
				std::cin >> x;
			std::cout << "y = "; 
				std::cin >> y;
				std::cin.ignore();
			std::cout << "weight = "; 
				std::cin >> weight;

			pointers.push_back(new WeightedPoint2D(x, y, weight));

			++counter;
		}
	} while (selection != 0); 

	//Sorting pointers
	std::sort(pointers.get_points().begin(), pointers.get_points().end(), comparison);

	//Outputting vector contents to console 
	std::cout << "\nYour points are" << std::endl << std::endl; 
	for (size_t i = 0; i < counter; i++)
	{
		std::cout << i+1 << ":";  
		pointers.get_points()[i] -> print(); 
		std::cout << std::endl; 
	}
	std::cout << std::endl;

	return 0; 
}

/**@brief Comparing Pointer Objects

Compares two Point2D pointers and returns true if the object p1 is pointing to is less than
the object p2 is pointing to. The function uses the rank member function to first 
determine whether the two objects are of the same type. The following is the ranking of 
objects: Point2D < ColorPoint2D < WeightedPoint2D. 

If the two pointers point to the same object, then the overloaded member function 
operators (<) are called to compare the two objects. 

@param p1 is a Point2D pointer to an object in the pointers vector
@param p2 is a Point2D pointer to an object in the pointers vector
@return Returns true if p1 is greater than p2 and false otherwise
*/
bool comparison(Point2D* p1, Point2D*p2)
{
	//get rank #s of pointers
	int r1 = p1 -> rank(); 
	int r2 = p2 -> rank(); 

	//if the ranks aren't equal aka they are pointing to different things
	if (r1 != r2)
	{
		//return true if r1 is smaller and false if otherwise
		return r1 < r2; 
	}
	//if both Point2D
	else if (r1 == 1 && r2 == 1)
	{
		//call overloaded < function for Point2D
		return *p1 < *p2; 
	}
	//if both ColorPoint2D
	else if (r1 == 2 && r2 == 2)
	{
		//p1 is point2D pointer but it points to a ColorPoint2D
		//here we're converting it to colorpoint2D pointer 
		ColorPoint2D* p1c = dynamic_cast<ColorPoint2D*>(p1); 
		ColorPoint2D* p2c = dynamic_cast<ColorPoint2D*>(p2); 
		return *p1c < *p2c; 
	}
	//if both WeightedPoint2D
	else if (r1 == 3 && r2 == 3)
	{
		//p1 is point2D pointer but it points to a WeightedPoint2D
		//here we're converting it to WeightedPoint2D pointer 
		WeightedPoint2D* w1c = dynamic_cast<WeightedPoint2D*>(p1); 
		WeightedPoint2D* w2c = dynamic_cast<WeightedPoint2D*>(p2); 
		return *w1c < *w2c; 
	}
}