//Nick Krisulevicz
//COSC 220 - Lab 4
//10/26/2021
//linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
using namespace std;

class linkedlist{
	private:
		node * list; //pointer to the head of the list

		node * createnode(); //creates a node object

		node * searchlocation(int id); //utility fucntion to search location of a node
	public:
		linkedlist(); //constructor
		
		~linkedlist(); //destructor

		void insertnode(); //member function to insert a node into the list

		void deletenode(int id); //member function to delete a node from the list

		void searchnode(); //member function to print a single node that is searched for

		void printlist(); //member function to print the entire list
};
#endif
