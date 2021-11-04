//Nick Krisulevicz
//COSC 220 - Lab 4
//main.cpp
//10/26/2021

#include "node.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	string fn;
	string ln;
	int id;
	int searchid;
	node students;

	int userchoice = 0;
	while(userchoice != 5){
		cout << "Previous input: " << userchoice << endl << endl;
		cout << "Welcome to the student database" << endl;
		cout << "1. Insert a node" << endl;
		cout << "2. Delete a node" << endl;
		cout << "3. Search for a node" << endl;
		cout << "4. Print list" << endl;
		cout << "5. Quit program" << endl << "____________________" << endl;
		cin >> userchoice;

		if(userchoice == 1){
			cout << "Enter first name" << endl;
			cin >> fn;
			cout << "Enter last name" << endl;
			cin >> ln;
			cout << "Enter ID number" << endl;
			cin >> id;
			students.insertnode(fn, ln ,id);
			cout << "____________________" << endl;
		}
		else if(userchoice == 2){
			cout << "Enter a student's ID number to delete" << endl;
			cin >> searchid;
			students.deletenode(searchid);
			cout << "____________________" << endl;
		}
		else if(userchoice == 3){
			cout << "Enter a student's ID number to search" << endl;
			cin >> searchid;
			students.searchnode(searchid);
			cout << "____________________" << endl;
		}
		else if(userchoice == 4){
			students.printlist();
			cout << "____________________" << endl;
		}
		else if(userchoice == 5){
			cout << "Goodbye!" << endl;
		}
		else{
			cout << "Invalid input" << endl;
		}
	}
return 0;
}
