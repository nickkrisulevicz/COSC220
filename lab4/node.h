//Nick Krisulevicz
//COSC 220 - Lab 4
//node.h
//10/26/2021

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class node{
	public:
		string firstname; //member variable to store the first name

		string lastname; //member variable to store the last name

		int idnumber; //member variable to store the id number

		node * next; //pointer to the next node

		node * head = nullptr; //pointer to the first node in the list
		
		node(); //constructor to assign values into the node

		~node(); //destructor

		void insertnode(string f, string l, int id); //member function to insert a new node in the list

		void deletenode(int id); //member function to delete a node from the list

		void searchnode(int id); //member function to print out a node searched for

		void printlist(); //member function to print out all nodes in the list
};

#endif
