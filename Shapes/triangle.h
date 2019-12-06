#pragma once
#include <iostream>
#include "shape.h"



class triangle: public shape{
public:
	//constructor
	triangle();
	triangle(double length);
	//assessory
	double getSide() const;
	//overridding
	~triangle(){}
	void print() const;
	double area() const;
	double perimeter() const;


private:
	double side;
};

triangle::triangle(){
	side = 1;
}

triangle::triangle(double length){
	if (length <= 0){
		throw runtime_error("The side cannot be less than or equal to 0");
	}else{
		side = length;
	}
}

double triangle::getSide() const{
	return side;
}

void triangle::print() const{
	cout << "triangle: side = " << side <<endl;
}
double triangle::area() const{
	return (( sqrt(3) / 4 ) * side * side);
}
double triangle::perimeter() const{
	return (3 * side);
}