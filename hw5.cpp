/** @file main.cpp
@brief Creates and outputs different types of points.
@author Lisa Chiang
@date February 9, 2015

Allows the user to create different types of 2D points (Point2D, ColorPoint2D, WeightedPoint2D, etc.), 
stores the points in a vector, and then outputs these points onto the console. 
*/

#include<iostream>
#include<string>
#include<vector>
#include"Point2D.h"
#include"ColorPoint2D.h"
#include"WeightedPoint2D.h"
#include"Points.h"

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