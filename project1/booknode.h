//Nick Krisulevicz
//COSC 220 - Project 1
//booknode.h
//10/15/2021

#ifndef BOOKNODE_H
#define BOOKNODE_H
#include <iostream>
#include <string>
using namespace std;

class booknode{ //class for the book objects to go in the list in the student objects
    public:
        string booktitle; //member variable with the title of the book

        string duedate; //member variable with the due date of the book

        string renewable; //member variable to specify if the book is renewable or not
        
        booknode * nextbook; //pointer to next book in the list

        booknode * bookhead = nullptr; //pointer to head of list

        booknode(); //constructor for the book list

        ~booknode(); //destructor for the book list

        void addbook(string t, string d, string r); //add a book to the list of books the student has

        void removebook(string bt); //remove a book to the list of books the student has

        void printbooklist(); // function to print the list of books

        friend class student; //sets the student class as a friend class so it can access the member function of the book class
};
#endif