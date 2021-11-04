//Nick Krisulevicz
//COSC 220 - Lab 4
//10/26/2021
//labmain.cpp

#include "linkedlist.h"
#include "node.h"
#include <iostream>
using namespace std;

int main(){
	int userchoice = 0;
	linkedlist list;
	while(userchoice != 5){ //while loop to enable the program to run until user quits
		cout << "1. Insert a node" << endl;
		cout << "2. Delete a node" << endl;
		cout << "3. Print List" << endl;
		cout << "4. Search for a node" << endl;
		cout << "5. Quit the program" << endl;
		cout << "____________________" << endl;
		cin >> userchoice;

		if(userchoice == 1){ //if user inputs 1, insert a node
			list.insertnode();
		}
		else if(userchoice == 2){ //if user inputs 2, delete a node
			int delid = 0;
			cout << "Enter ID number of student to delete" << endl;
			cin.ignore();
			cin >> delid;
			list.deletenode(delid);
		}
		else if(userchoice == 3){ //if user inputs 3, print the whole list
			list.printlist();
		}
		else if(userchoice == 4){ //if user inputs 4, search a node
			list.searchnode();
		}
		else if(userchoice == 5){ //if user inputs 5, quit the program
			cout << "Goodbye!" << endl;
		}
		else{ //if user enters anything other than 1-5, print message saying invalid input
			cout << "Invalid input!" << endl;
		}
	}
}
