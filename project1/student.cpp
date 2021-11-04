//Nick Krisulevicz
//COSC 220 - Project 1
//student.cpp
//10/15/2021

#include "student.h"
#include "booknode.h"
#include <iostream>
#include <string>
using namespace std;

student::student(){
    head = nullptr; //constructor sets head to nullptr
}

student::~student(){
    student * nodeptr;
    student * nextnode;

    nodeptr = head;

    while(nodeptr != nullptr){ //while loop to traverse through list and delete all nodes
        nextnode = nodeptr->next;
        delete nodeptr; //destructor deletes the student nodes one by one
        nodeptr = nextnode;
    }
}

void student::addstudent(string fn, string ln, string yr, int idn){
    student * newstudent;
    newstudent = new student(); //dynamically allocate the new student node to fill with data before it is inserted

    newstudent->firstname = fn; //assign the values to the member variables
    newstudent->lastname = ln;
    newstudent->year = yr;
    newstudent->idnumber = idn;
    newstudent->next = nullptr; //initially set the prev and next pointers to nullptr before they get assigned their spot in the list
    newstudent->prev = nullptr;

    if(!head){ //conditional for if head does not exist, make this node the head
        head = newstudent;
    	return;
    }
    student * curr = head; //declare the current and previous cursor pointers to iterate through the list
    student * previous = head;
    while(curr->next){ //conditional for while there is a curr->next, iterate through the list
        previous = curr;
        curr = curr->next;
        if(newstudent->idnumber > previous->idnumber && newstudent->idnumber < curr->idnumber){ //if the idnumber is between current and previous, insert the node here
            newstudent->prev = previous;
            newstudent->next = curr;
            return;
        }
    }
    if(!curr->next){
        newstudent->prev = curr;
        curr->next = newstudent;
    }
}

void student::updatestudent(int idn){
    if(!head){ //if there are no students in the list, print out a message saying there are no students to update
        cout << "There is no student to update!" << endl;
        return;
    }

    string fn;
    string ln;
    string yr;

    cout << "Enter the first name" << endl;
    cin >> fn;
    cout << "Enter the last name" << endl;
    cin >> ln;
    cout << "Enter the student's year" << endl;
    cin >> yr;
    
    student * replacement; //declare a node to replace the student being updated
    replacement = new student();

    replacement->firstname = fn; //assign the values from the parameters into the student node
    replacement->lastname = ln;
    replacement->year = yr;
    replacement->idnumber = idn;
    replacement->next = nullptr;
    replacement->prev = nullptr;

    student * curr = head; //create the current and previous cursor pointers
    student * previous = head;

    if(head->idnumber == idn){ //if the head is the target node, replace the head with the updated node
        replacement->prev = nullptr;
        replacement->next = head->next;
        head = replacement;
        delete replacement;
        return;
    }
    while(curr->next){ //conditional statement to iterate through list of student nodes
        previous = curr;
        curr = curr->next;
        if(replacement->idnumber == curr->idnumber){ //conditional if the id number is equal to the id number in a node, replace the existing node with the updated one
            replacement->prev = previous;
            replacement->next = curr->next;
            curr = replacement; //assign the value of the replacement node into the old one
            delete replacement; //free memory where the temporary replacement node was
            return;
        }
    }
    if(!curr->next){
        cout << "End of list and student with this id number was not found" << endl; //print message if student node with matching id number is not found
    }
}

void student::deletestudent(int idn){
    student * previous;
    student * curr;

    if(!head){
        cout << "There are no nodes to delete" << endl; //print out message if there are no student nodes to delete
    }

    previous = head;
    curr = head;

    if(head->idnumber == idn){ //if the target node to delete is the head of the list, delete the head
        curr = head->next;
        previous = nullptr;
        delete head;
        head = curr;
    }
    else{ //if the target node is not the head, iterate through the list to find the target node
        curr = head;
        while(curr->next != nullptr && curr->idnumber != idn){
            previous = curr;
            curr = curr->next;
        }
        if(curr){ //delete the target node and set the pointers accordingly
            previous->next = curr->next;
            curr->next->prev = previous;
            delete curr;            
        }
    } 
}

void student::addbooks(int idn){
    student * previous;
    student * curr;
    string ti;
    string du;
    string re;

    cout << "Enter the book title" << endl;
    cin >> ti;
    cout << "Enter the due date" << endl;
    cin >> du;
    cout << "Enter if it is renewable (y/n)" << endl;
    cin >> re;

    if(!head){ //if there is no head, print a message saying that there is no student to add books to
        cout << "There is not student to add books to" << endl;
    	return;
    }

    previous = head;
    curr = head;

    if(head->idnumber == idn){ //if the head of the student list is the target one, add a book to this student
        head->listbooks.addbook(ti, du, re);
	return;
    }

    while(curr->next != nullptr || curr->idnumber == idn){ //if the head is not the target student, iterate through the list until the target is found
        previous = curr;
        curr = curr->next;
        if(curr->idnumber == idn){
            curr->listbooks.addbook(ti, du, re); //when the target is found, add a book to that student
	    return;
        }
    }
    if(!curr->next){ //print out message if the target student was not found
        cout << "End of list and student with this ID number was not found" << endl;
    }
}

void student:: removebooks(int idn){
    student * previous;
    student * curr;
    string ti;

    cout << "Enter the book title to be deleted" << endl;
    cin >> ti;

    if(!head){ //if there is no head, print a message saying that there is no student to add books to
        cout << "There is not student to remove books from" << endl;
    }

    previous = head;
    curr = head;

    if(head->idnumber == idn){ //if the head of the student list is the target one, delete a book from this student
        head->listbooks.removebook(ti);
    }

    while(head->next != nullptr && head->idnumber == idn){ //if the head is not the target student, iterate through the list until the target is found
        previous = curr;
        curr = curr->next;
        if(curr->idnumber == idn){
            curr->listbooks.removebook(ti); //when the target is found, delete the book from that student
        }
    }
    if(!curr->next){ //print out message if the target student was not found
        cout << "End of list and student with this ID number was not found" << endl;
    }
}

void student::printlist(){
    student * curr;
    student * previous;

    curr = head;

    while(curr){ //iterate through the whole list and print out the data for all the students
        cout << curr->firstname << " ";
        cout << curr->lastname << ", ";
        cout << curr->year << endl;
        cout << "Books rented: " << endl;
        curr->listbooks.printbooklist();
	if(!curr->next){
		break;
	}
	curr=curr->next;
    }
}
