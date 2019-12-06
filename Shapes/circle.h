//circle.h
#pragma once
#include "shape.h"
#include <iostream>



class circle: public shape{
public:
	//constructor
	circle();
	circle(double i);
	//assessories
	double getRadius() const;
	//overwritting
	~circle(){}
	double area() const;
	double perimeter() const;
	void print() const;
private:
	double radius;
	const double PI = 3.1415;

};//end of the class


circle::circle(){
	radius = 1;
}//defult constructor

circle::circle(double i){
	if ( i <= 0){
		throw runtime_error("Radius can't be negative!");
	}else{
		radius = i;
	}
}//constructor with setting

double circle::getRadius() const{
	return radius;
}
double circle::area() const {
	return (PI * radius * radius);
}
double circle::perimeter() const{
	return (2 * PI * radius);
}
void circle::print() const{
	cout << "circle: radius = " << radius << endl;
}