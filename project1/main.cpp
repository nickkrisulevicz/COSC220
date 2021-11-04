//Nick Krisulevicz
//COSC 220 - Project 1
//main.cpp
//10/15/2021

#include "booknode.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    string fname;
    string lname;
    string studyear;
    int idnum;
    int searchid;

    int userchoice = 0;
    student studlist;
    while(userchoice != 7){
        cout << "Input:" << userchoice << endl;
	    cout << "Welcome to the student library database!" << endl;
        cout << "____________________" << endl;
        cout << "Please select and option below:" << endl << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Update an existing student's records" << endl;
        cout << "3. Delete a student's records" << endl;
        cout << "4. Check out a book for a student" << endl;
        cout << "5. Return a book from a student" << endl;
        cout << "6. Print out the list of students" << endl;
        cout << "7. Exit the program" << endl;
        cout << "____________________" << endl;

        cin >> userchoice;
        cout << "____________________" << endl;

        if(userchoice == 1){
            cout << "Enter the student's first name" << endl;
            cin >> fname;
            cout << "Enter the student's last name" << endl;
            cin >> lname;
            cout << "Enter the student's year of school" << endl;
            cin >> studyear;
            cout << "Enter the student's ID number" << endl;
            cin >> idnum;
            studlist.addstudent(fname, lname, studyear, idnum);
            cout << "____________________" << endl;
        }

        else if(userchoice == 2){
            cout << "Enter the ID number of the student to update" << endl;
            cin >> searchid;
            studlist.updatestudent(searchid);
            cout << "____________________" << endl;
        }

        else if(userchoice == 3){
            cout << "Enter the ID number of the student to remove" << endl;
            cin >> searchid;
            studlist.deletestudent(searchid);
            cout << "____________________" << endl;
        }

        else if(userchoice == 4){
            cout << "Enter the ID number of the student to check out a book" << endl;
            cin >> searchid;
            studlist.addbooks(searchid);
            cout << "____________________" << endl;
        }

        else if(userchoice == 5){
            cout << "Enter the ID number of the student to return a book" << endl;
            cin >> searchid;
            studlist.removebooks(searchid);
            cout << "____________________" << endl;
        }

        else if(userchoice == 6){
            studlist.printlist();
            cout << "____________________" << endl;
        }

        else if(userchoice == 7){
            cout << "Goodbye!" << endl;
            cout << "____________________" << endl;
        }

        else{
            cout << "Invalid input! Please enter one of the following menu choices." << endl;
            cout << "____________________" << endl;
        }
    }
    return 0;
}
