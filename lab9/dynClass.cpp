//Nick Krisulevicz
//COSC 220 - Lab 9
//11/30/2021
//dynClass.cpp

#include "dynClass.h"
#include <iostream>
using namespace std;

dynClass::dynClass(int m1, int m2){
	member1 = m1;
	member2 = new int;
	*member2 = m2;
	cout << "Constructor: " << member1 << "/" << *member2 << endl;
}

dynClass::dynClass(const dynClass& obj){
	dynClass newobj(obj.member1, *obj.member2);
	cout << "Copy constructor: " << newobj.member1 << "/" << *newobj.member2 << endl;
}

dynClass::~dynClass(){
	delete member2;
	cout << "Destructor was called" << endl;
}

dynClass& dynClass::operator=(const dynClass& obj){
	int t1 = 0;
	int t2 = 0;
	dynClass newobj(t1, t2);
	newobj.member1 = t1;
	*newobj.member2 = t2;
	cout << "Assignment operator: " << newobj.member1 << "/" << *newobj.member2 << endl;
	return newobj;
}
