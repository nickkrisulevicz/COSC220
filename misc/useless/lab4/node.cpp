//Nick Krisulevicz
//COSC 220 - Lab 4
//node.cpp
//10/12/2021

#include "node.h"
#include <iostream>
#include <string>
using namespace std;

node::node(string fn, string ln, int idn){
    firstname = fn;
    lastname = ln;
    idnumber = idn;
    next = nullptr;
}

node::~node(){
    node * nodeptr;
    node * nextnode;

    nodeptr = head;

    while(nodeptr != nullptr){
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
    }
}

void node::printnode(){
    node * nodeptr;
    nodeptr = head;
    while(nodeptr){
        cout << nodeptr->lastname << ", ";
        cout << nodeptr->firstname << ", ";
        cout << nodeptr->idnumber << ", " << endl;
        nodeptr = nodeptr->next;
    }
}
