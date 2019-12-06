// a4.cpp
 
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name: Si Jia (Kevin) He
// St.#: 301354679
// Email: sjhe@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;
struct command{
	char shapechar;
	double side;
	double length;
	double width;
	double radius;
	double area;
	double perimeter;
};

bool areacomparetobool( const shape* a, const shape* b);
bool perimetercomparetobool(const shape* a, const shape* b);
vector<string> readtxtdata(string fname);
void readfilecommand(vector<string> file);



int main(){

vector<string> file = readtxtdata("a4files.txt");
readfilecommand(file);




}
bool areacomparetobool( const shape* a, const shape* b){
	int num;
	num = a->shape::areacompare(*b);
	if (num == -1){
		return true;
	}
	return false;
	
}
bool perimetercomparetobool(const shape* a, const shape* b){
	int num;
	num = a->shape::perimetercompare(*b);
	if (num == -1){
		return true;
	}
	return false;
	
}


vector<string> readtxtdata(string fname){
	vector<string> txtdata;
	ifstream fin;
	fin.open(fname);
	if(fin.fail()){
		throw runtime_error("a4files.txt does not exist in this directory!");
	}
	while(!fin.eof()){
		string nextfile;
		if(fin >> nextfile){

			txtdata.push_back(nextfile);
		}else{
			fin.clear();
			fin.ignore(100,'\n');
		}//else
	}//while
	fin.close();
	return txtdata;
}

void readfilecommand(vector<string> file){
	ifstream fin;
	for(int i = 0; i < file.size(); i++){
		vector<shape*> result;
		fin.open(file[i]);
		if(fin.fail()){
			cout <<file[i] << " could not be opened" << endl << endl;
		}else{
			while(!fin.eof()){
				command nextcommand;
				if(fin >> nextcommand.shapechar){
					if(nextcommand.shapechar == 'c'){
						if(fin >> nextcommand.radius){
							shape* newcircle = new circle(nextcommand.radius);
							result.push_back(newcircle);
						}else{
							fin.clear();
							fin.ignore(100, '\n');
						}
					}else if(nextcommand.shapechar == 'r'){
						if(fin >> nextcommand.width >> nextcommand.length && nextcommand.width >= 0 && nextcommand.length >=0){
							shape* newrect = new rectangle(nextcommand.width,nextcommand.length);
							result.push_back(newrect);
						}else{
							fin.clear();
							fin.ignore(100, '\n');
						}
					}else if(nextcommand.shapechar == 't'){
						if(fin >> nextcommand.side && nextcommand.side >= 0){
							shape* newtri = new triangle(nextcommand.side);
							result.push_back(newtri);
						}else{
							fin.clear();
							fin.ignore(100, '\n');
						}
					}else{
						fin.clear();
						fin.ignore(100, '\n');
					}
				}else{
					fin.clear();
					fin.ignore(100, '\n');
				}//if command.shapes else
			}

			// fin.close();
			sort(result.begin(), result.end(), areacomparetobool);
			cout << file[i] << endl;
			for(shape* sh:result){
				cout << "area = " << sh->area() << " -- ";
				sh->print();
			}
			cout<< endl;
			sort(result.begin(), result.end(), perimetercomparetobool);
			for(shape* sh:result){
				cout << "perimeter = " << sh->perimeter() << " -- ";
				sh->print();
			}
			cout << endl;
			fin.close();
			for(int i = 0; i < result.size(); i++){
				delete result[i];
			}
	}
	}
}