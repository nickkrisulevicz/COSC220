//Nick Krisulevicz
//COSC 220 - Project 1
//booknode.cpp
//10/15/2021

#include "booknode.h"
#include <iostream>
#include <string>
using namespace std;

booknode::booknode(){ //constructor for booknode objects

    /*cout << "Enter the title of the book" << endl;
    cin >> booktitle;
    cout << "Enter the due date of the book" << endl;
    cin >> duedate;
    cout << "Is the lending of the book renewable? (Enter y/n)" << endl;
    cin >> renewable;
    nextbook = nullptr;*/

    bookhead = nullptr;
}

booknode::~booknode(){ //destructor for booknode objects
    booknode * bookptr;
    booknode * nextbooknode;

    bookptr = bookhead;

    while(bookptr != nullptr){ //while loop to traverse through list and delete all nodes
        nextbooknode = bookptr->nextbook;
        delete bookptr;
        bookptr = nextbooknode;
    }
}

void booknode::addbook(string t, string d, string r){
    booknode *newbook;
    booknode *bookptr;

    newbook = new booknode();

    newbook->booktitle = t; //assign values to the member variables
    newbook->duedate = d;
    newbook->renewable = r;
    newbook->nextbook = nullptr;

    if(!bookhead){
        bookhead = newbook; //if there is no head, make the first book inserted point to head
    }
    else{
        bookptr = bookhead; //if there are books in the list, point the new book to the last book
        while(bookptr->nextbook){
            bookptr = bookptr->nextbook; //while loop to proceed through the list until it finds the end
        }
        bookptr->nextbook = newbook; //insert the new book as the last book in the list
    }
}

void booknode::removebook(string bt){

    //search algorithm to compare bt to booktitle
    //if bt does not equal book title, iterate to the next node in the list
    //if bt does equal book title, remove that node, and point previous to currbook->next
   
    booknode * prevbook;
    booknode * bookptr;

    if(!bookhead){ //if list is empty, nothing will be deleted
        return;
    }
    
    if(bookhead->booktitle == bt){ //if the first booknode is the target one, it will be deleted
        bookptr = bookhead->nextbook; 
        delete bookhead;
        bookhead = bookptr;
    }
    else{ //if the target booknode is not the first one, then iterate through the list until the target node is found and delete it
        bookptr = bookhead;
        while(bookptr != nullptr && bookptr->booktitle != bt){ //while loop to proceed through list
            prevbook = bookptr;
            bookptr = bookptr->nextbook;
        }
        if(bookptr){
            prevbook->nextbook = bookptr->nextbook;
            delete bookptr; //bookptr is a temporary pointer to traverse through the list, so delete it at the end of the function
        }
        else{
		cout << "Book not found" << endl;
	    }
    }
}

void booknode::printbooklist(){
    booknode *bookptr;
    bookptr = bookhead;
    while(bookptr){ //iterate through list and print all books in the list
        cout << bookptr->booktitle << ", ";
        cout << bookptr->duedate << ", ";
        cout << bookptr->renewable << endl;
        bookptr = bookptr->nextbook;
    }
}

