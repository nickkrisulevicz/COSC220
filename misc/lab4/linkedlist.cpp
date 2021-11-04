//Nick Krisulevicz
//COSC 220 - Lab 4
//10/26/2021
//linkedlist.cpp

#include "linkedlist.h"
#include "node.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist(){ //constructor
	list = nullptr; //initialize the head of the list to nullptr
}

linkedlist::~linkedlist(){ //destructor
	node * curr = nullptr; //initialize cursor pointer
	if(list != nullptr){ //conditional statement for if list is not equal to nullptr
		curr = list->next;
		while(curr != nullptr){ //loop to delete all the nodes if list is not nullptr
			delete list;
			list = curr;
			curr = curr->next;
		}
	}
}

node * linkedlist::createnode(){ //create node private function
	node * newnode = new node(); //dynamically allocate new node and fill it with data
	newnode->next = nullptr; //set the pointer to nullptr
	return newnode; //return the node so it can be inserted into the list
}

node * linkedlist::searchlocation(int id){ //searchlocation private function uses id parameter
	node * curr; //initialize the two cursor pointers to do the search
	node * prev;

	curr = list; //assign the starting values to the cursors before the search
	prev = curr;

	if(list == nullptr){ //if list is empty, print message saying it is empty
		cout << "There are no nodes to search" << endl;
		return nullptr;
	}

	if(list->idnumber == id){ //if the first node is the target node return the first node
		return list;
	}
	
	curr = curr->next; //set curr to the node it points next to

	while(curr != nullptr){ //if the target node is not the first one, search through the list
		if(curr->idnumber == id){
			return prev;
		}
		prev = curr;
		curr = curr->next;
	}
	return nullptr;
}

void linkedlist::insertnode(){ //member function to insert a node into the list
	node newnode = createnode(); //calls private create node function
	node * curr = nullptr; //declare the cursor pointer

	curr = list;

	if(curr == nullptr){ //if there is no head of the list, make the new node the head
		list = newnode;
		return;
	}

	else if(newnode->idnumber < curr->idnumber){ //if the id number comes first numerical order, make it the first node
		newnode->next = list;
		list = newnode;
		return;
	}

	while (curr != nullptr){ //if the new node needs to not be the first node, search through the list
		if(curr->idnumber == newnode->idnumber){ //condition for duplication
			cout << "This student is already in the list" << endl;
			return;
		}
		else if(curr->idnumber > newnode->idnumber){ //when the right location is found, insert the node
			node * search = searchlocation(curr->idnumber);
			newnode->next = curr;
			search->next = newnode;
			return;
		}

		else if(curr->next == nullptr){ //condition to place the node at the end of the list
			newnode->next = nullptr;
			curr->next = newnode;
			return;
		}
		curr = curr->next;
	}
	curr->next = newnode;
}

void linkedlist::deletenode(int id){ //member function to delete node
	node * curr = list; //initialize cursor nodes
	node * delnode = searchlocation(id); //node that uses private function search location

	if(delnode == nullptr){ //if there is no node with matching id number, print message saying it is not found
		cout << "Student not found" << endl;
		return;
	}
	if(list == delnode){ //if the target node is the only node, delete it
		list = curr->next;
		delete delnode;
	}
	else if(list->idnumber == id){ //if target node is the first node, delete the first node
		curr = list->next;
		delete list;
		return;
	}
	else{ //otherwise delete the node in the middle or end of the list
		node * tempnode = delnode->next;
		delnode->next = tempnode->next;
		delete tempnode;
		return;
	}
}

void linkedlist::searchnode(){ //member function to search a node in the list
	int searchid = 0;
	cout << "Enter ID of student to search" << endl;
	cin >> searchid;

	node * tempnode = searchlocation(searchid);
	cout << tempnode << endl; //--------------------------------------------------------//

	node * tempnode2 == tempnode->next;
	if(tempnode == nullptr){ //print message if the node is not found in the list
		cout << "This student is not in the list" << endl;
	}
	else{ //if node is found, print it
		tempnode2->printnode();
	}
}

void linkedlist::printlist(){ //member function to print the entire list
	node * curr = nullptr;
	curr = list;
	if(list == nullptr){ //if list is empty, print message saying there is no list
		cout << "There are no students in the list to print" << endl;
	}
	while(curr != nullptr){ //print nodes until the list reaches the end at nullptr
		curr->printnode();
		curr = curr->next;
	}
}
