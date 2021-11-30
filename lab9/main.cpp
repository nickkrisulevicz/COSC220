//Nick Krisulevicz
//COSC 220 - Lab 9
//11/30/2021
//main.cpp

#include <iostream>
#include "dynClass.h"
using namespace std;

dynClass demo(dynClass one, dynClass two, int& m);

int main(){
	int num1 = 3;
	int num2 = 5;
	int num3 = 5;
	dynClass obj1(num1, num2);
	dynClass obj2(obj1);
	dynClass obj3(0, 0);
	obj3 = demo(obj1, obj2, num3);
	return 0;
}

dynClass demo(dynClass one, dynClass two, int& m){
	dynClass obj(m, m);
	return obj;
}
