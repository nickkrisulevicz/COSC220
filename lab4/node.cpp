//Nick Krisulevicz
//COSC 220 - Lab 4
//node.cpp
//10/26/2021

#include"node.h"
#include <iostream>
#include <string>
using namespace std;

node::node(){ //constructor
	head = nullptr; //initialize the head to nullptr
}

node::~node(){ //destructor
	node * nodeptr;
	node * nextnode;
	nodeptr = head;

	while(nodeptr != nullptr){ //iterate through the list and delete every node once the program is done
		nextnode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextnode;
	}
}

void node::insertnode(string f, string l, int id){ //insert function
	node * newnode; //declare the new node
	node * nodeptr; //declare the cursor pointers
	node * prev;

	prev = nullptr;
	newnode = new node; //dynamically allocate the new node
	newnode->firstname = f; //assign the new node variable data from the parameters
	newnode->lastname = l;
	newnode->idnumber = id;
	newnode->next = nullptr;

	if(!head){ //if there is no head, make new node the head
		head = newnode;
		newnode->next = nullptr;
	}
	else{ //if there is no head, search the list until you find the spot to put the new node
		nodeptr = head;
		prev = nullptr;
		while(nodeptr != nullptr && nodeptr->idnumber < id){
			prev = nodeptr;
			nodeptr = nodeptr->next;
		}
		if(prev == nullptr){ //if the new node is the first one, make it the new head
			head = newnode;
			newnode->next = nodeptr;
		}
		else{ //otherwise insert the new node after the previous one when target is found
			prev->next = newnode;
			newnode->next = nodeptr;
		}
	}
}

void node::deletenode(int id){ //delete function
	node * nodeptr;//declare the pointer nodes
	node * prev;

	if(!head){ //if there is no head, print a message saying there is nothing to delete
		cout << "There are no nodes to delete" << endl;
		return;
	}

	if(head->idnumber == id){ //if the target node to delete is the head, delete the head
		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}
	else{ //if the target node is not the first one, search through the list until it is found
		nodeptr = head;
		while(nodeptr != nullptr && nodeptr->idnumber != id){
			prev = nodeptr;
			nodeptr = nodeptr->next;
		}
		if(nodeptr){ //when the target node is found, delete it
			prev->next = nodeptr->next;
			delete nodeptr;
		}
	}
}

void node::searchnode(int id){ //search function
	node * prev; //declare cursor pointers
	node * nodeptr;

	if(!head){ //if there is no head, print a message saying there are no nodes to search
		cout << "There are no nodes to search" << endl;
		return;
	}

	if(head->idnumber == id){ //if the target node is the head, print the data in the head
		cout << head->firstname << " ";
		cout << head->lastname << ", ";
		cout << head->idnumber << endl;
	}
	else{ //if not, search through the list until the target node is found
		nodeptr = head;
		while (nodeptr != nullptr && nodeptr->idnumber != id){ //iterate through the list
			prev = nodeptr;
			nodeptr = nodeptr->next;
		}
		if(nodeptr){ //when the target node is reached, print its data
			cout << nodeptr->firstname << " ";
			cout << nodeptr->lastname << ", ";
			cout << nodeptr->idnumber << endl;
		}
		else{ //if teh target node is not found, print a message saying it was not found
			cout << "Student with this id number not found" << endl;
		}
	}
}

void node::printlist(){ //print list function
	node * nodeptr;
	nodeptr = head;
	while(nodeptr){
		cout << nodeptr->firstname << " ";
		cout << nodeptr->lastname << ", ";
		cout << nodeptr->idnumber << endl;
		nodeptr = nodeptr->next;
	}
}

