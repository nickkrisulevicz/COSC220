//Nick Krisulevicz
//COSC 220 - Lab 4
//node.h
//10/12/2021

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class node{
    public:
        string firstname; //member variable for first name

        string lastname; //member variable for last name
    
        int idnumber; //member variable for id number, will be used for search funtions

        node * next; //pointer to next node in singly linked list

        node * head = nullptr; //initialze the head of the list to nullptr

        node(string fn, string ln, int idn); //constructor to assign values to the variables

        ~node(); //destructor for the list
        
        void printnode(); //function to print out the data stored in the nodes
};
#endif