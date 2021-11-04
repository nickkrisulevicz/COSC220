//Nick Krisulevicz
//COSC 220 - Lab 4
//10/26/2021
//node.cpp

#include "node.h"
#include <iostream>
using namespace std;

node::node(){ //constructor
	cout << "Enter ID number" << endl;
	cin >> idnumber; //assign value to idnumber
	cout << "Enter first name" << endl;
	cin.ignore();
	cin.getline(firstname, 20); //assign value to firstname
	cout << "Enter last name" << endl;
	cin.getline(lastname, 20); //assign value to lastname
}

void node::printnode(){
	for(int i = 0; i < 20; i++){ //loop to print array of characters to form first name
		cout << firstname[i];
	}
	cout << " ";
	for(int i = 0; i < 20; i++){ //loop to print array of characters to form last name
		cout << lastname[i];
	}
	cout << ", " << idnumber << endl; //print the id number and end the line
}
