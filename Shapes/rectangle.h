#pragma once
#include "shape.h"
#include <iostream>



class rectangle: public shape{
public:
	//constructors
	rectangle();
	rectangle(double x, double y);
	//accessories
	double getWidth() const;
	double getHeight() const;
	//overwriting
	void print() const;
	double area() const;
	double perimeter() const;
	~rectangle() { }
private:
	double width;
	double height;

};

rectangle::rectangle(){
	width = 1;
	height = 1;
}

rectangle::rectangle(double x, double y){
	if(x <= 0 ){
		throw runtime_error("Width cannot be less than or equal to 0");
	}else if( y <= 0){
		throw runtime_error("Length cannot be less than or equal to 0");
	}else{
		width = x;
		height = y;
	}
}

double rectangle::getWidth() const{
	return width;
}

double rectangle::getHeight() const{
	return height;
}

void rectangle::print() const{
	cout << "rectangle: width = " << width << ", height = " << height << endl;
}
double rectangle::area() const{
	return (width * height);
}
double rectangle::perimeter() const{
	return 2* (width + height);
}