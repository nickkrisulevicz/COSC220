//Nick Krisulevicz
//COSC 220 - Project 1
//student.h
//10//15/2021

#ifndef STUDENT_H
#define STUDENT_H
#include "booknode.h"
#include <iostream>
#include <string>
using namespace std;

class student{ //class for the student objects
    public:
        string firstname; //member variable for first name

        string lastname; //member variable for last name

        string year; //member variable fir student's year

        int idnumber; //member variable for student id number

        booknode listbooks; //member object of booknode class for the list of books the student has rented

        student * head = nullptr; //initialize the head of the list to nullptr

        student * next; //pointer to next node in the doubly linked list

        student * prev; //pointer to previous node in the doubly linked list

        student(); //constructor for the list

        ~student(); //destructor for the list

        void addstudent(string fn, string ln, string yr, int idn); //member function to add a student node to the list

        void updatestudent(int idn); //member function to search for and update an existing student node

        void deletestudent(int idn); //member function to search for and delete a student node

        void addbooks(int idn); //member function that adds list of book nodes to student node with corresponding id number

        void removebooks(int idn); //member function to that removes books from a student node with corrresponding id number

        void printlist(); //member function to print all of the student nodes in the list
};
#endif
