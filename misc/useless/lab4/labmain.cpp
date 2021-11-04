//Nick Krisulevicz
//COSC 220 - Lab 4
//labmain.cpp
//10/12/2021

#include "node.h"
#include "linkedlist.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    string firstn;
    string lastn;
    int idnum;
    int searchid;

    int userchoice = 0;
    linkedlist linklist;

    while(userchoice != 5){
        cout << "Please select an option below" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Search a node" << endl;
        cout << "5. Quit the program" << endl << endl;

        cin >> userchoice;
	cout << "____________________" << endl;

        if(userchoice == 1){
            cout << endl << "Enter a first name" << endl;
            cin >> firstn;
            cout << "Enter a last name" << endl;
            cin >> lastn;
            cout << "Enter an ID number" << endl;
            cin >> idnum;
            
            linklist.insertnode(firstn, lastn, idnum);
	    cout << "____________________" << endl;
        }

        else if(userchoice == 2){
            cout << "Enter ID number of student to delete" << endl;
            cin >> searchid;
            linklist.deletenode(searchid);
	    cout << "____________________" << endl;
        }

        else if(userchoice == 3){
            linklist.printlist();
	    cout << "____________________" << endl;
        }

        else if(userchoice == 4){
            cout << "Enter the ID number of a student to search" << endl;
            cin >> searchid;
            linklist.searchnode(searchid);
	    cout << "____________________" << endl;
        }

        else if(userchoice == 5){
            cout << "Goodbye" << endl; 
	    cout << "____________________" << endl;
        }

        else{
            cout << "Invalid input" << endl;
	    cout << "____________________" << endl;
        }
    }

    return 0;
}
