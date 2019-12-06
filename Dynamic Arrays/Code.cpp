#include "a1.h"
#include <iostream>
 
using namespace std;
 
int_array make_intarray(int cap);
int_array make_intarray(int cap, int value);
void deallocate(int_array& iarr);
void print(const int_array& iarr);
double pct_used(const int_array& iarr);
int get(const int_array& iarr, int i);
bool set(int_array& iarr, int i, int value);
void append(int_array& iarr, int value);
void prepend(int_array& iarr, int value);
bool operator==(const int_array& iarr1, const int_array& iarr2);

int main() {
  cout << "Assignment 1" << endl;
int_array arr = make_intarray(5,2);
print(arr);
int_array arr1 = make_intarray(5,2);
if (set(arr, 2, 3)){
	cout << "yep" << endl;
}
print(arr);
cout << pct_used(arr)<< endl << get(arr, 2) << endl
<<"capacity before " << arr.capacity << endl
<< "size before " << arr.size << endl;
append(arr, 4);
append(arr, 5);
cout << "capacity after " << arr.capacity << endl
<< "size after " << arr.size << endl;
print(arr);
prepend(arr,7);
prepend(arr,8);
print(arr);
if(operator==(arr, arr1)){
	cout << "same" << endl;
}
deallocate(arr);
deallocate(arr1);

}

//Question 1
int_array make_intarray(int cap){
	int_array make;
	make.capacity = cap;
	make.size = 0;
	make.arr = new int[make.capacity];
return make;
}// make int array

//Question 2
int_array make_intarray(int cap, int value){
	int_array make;
	make.capacity = cap;
	make.size = cap;
	make.arr = new int[make.capacity];
	for(int i = 0; i < make.size; i++){
		*(make.arr + i) = value;
	}
return make;
}// make  int array with fill

//Question 3
void deallocate(int_array& iarr){
	delete[] iarr.arr;
	iarr.arr = nullptr;
}//deallocate

//question 4
void print(const int_array& iarr){
	cout << "{";
	for(int i = 0; i < iarr.size; i++){
		if( i != (iarr.size - 1)){
			cout << *(iarr.arr + i) << ",";
		}else cout << *(iarr.arr + i);
	}
	cout << "}" << endl;

}//print

//question 5
double pct_used(const int_array& iarr){
	double size = static_cast<double>(iarr.size);
	double cap = static_cast<double> (iarr.capacity);
	return (size/cap);
}//pct used

//question 6
int get(const int_array& iarr, int i){
	return *(iarr.arr + i);
}//get

//question 7
bool set(int_array& iarr, int i, int value){
	if( i < 0 || i > (iarr.size - 1)){
		return false;
	}else {
		*(iarr.arr + i) = value;
		return true;
	}
}// set

//question 8
void append(int_array& iarr, int value){
	if (iarr.size == iarr.capacity){
		int* original = iarr.arr;
		iarr.capacity = 2 * iarr.capacity;
		iarr.arr = new int[iarr.capacity];
		for(int i = 0; i < (iarr.size); i++){
			*(iarr.arr + i) = *(original + i);
		}
		delete[] original;
		original = nullptr;
	}
	iarr.arr[iarr.size] = value;
	iarr.size++;
}

//question 9
void prepend(int_array& iarr, int value){
	if (iarr.size == iarr.capacity){
		int* original = iarr.arr;
		iarr.capacity = 2 * iarr.capacity;
		iarr.arr = new int[iarr.capacity];
		for(int i = 0; i < (iarr.size); i++){
			*(iarr.arr + i) = *(original + i);
		}
		delete[] original;
		original = nullptr;
	}
	for(int i = iarr.size; i > 0; i--){
		*(iarr.arr + i) = *(iarr.arr + i - 1);
	}
	*(iarr.arr) = value;
	iarr.size++;
}//prepend

//question 10
 bool operator==(const int_array& iarr1, const int_array& iarr2){
 	if( iarr1.size == iarr2.size){
 		for(int i = 0; i < iarr1.size; i++){
 			if(*(iarr1.arr) == *(iarr2.arr)){

 			}else{
 				return false;
 			}
 		}
 		return true;
 	}
 	return false;
 }
