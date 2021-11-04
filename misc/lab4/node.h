//Nick Krisulevicz
//COSC 220 - Lab 4
//10/26/2021
//node.h

#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class node{
	public:
		char firstname[20]; //array of characters to store the first name

		char lastname[20]; //array of characters to store the last name

		int idnumber; //id number, will be passed as a parameter and used to search nodes

		node * next; //pointer to next node

		node(); //constructor

		void printnode(); //member function to print nodes
};
#endif
