//Nick Krisulevicz
//COSC 220 - Lab 9
//11/30/2021
//dynClass.h

#ifndef DYNCLASS_H
#define DYNCLASS_H
#include <iostream>
using namespace std;

class dynClass{
	public:
		dynClass(int m1, int m2); //constructor

		dynClass(const dynClass& obj); //copy constructor, pass by reference

		~dynClass(); //destructor

		dynClass& operator= (const dynClass & obj); //assignment operator overload
	private:
		int member1; //int member variable

		int * member2; //int pointer member variable
};
#endif
