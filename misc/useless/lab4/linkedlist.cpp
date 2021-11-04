//Nick Krisulevicz
//COSC 220 - Lab 4
//linkedlist.cpp
//10/12/2021

#include "linkedlist.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

linkedlist::linkedlist(){
    list = nullptr;
}

linkedlist::~linkedlist(){
    node * nodeptr;
    node * nextnode;
    nodeptr = list;
    while(list != nullptr){
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
    }
}

void linkedlist::appendnode(node * appnode){
    node * newnode;
    node * nodeptr;
    

    
    newnode->firstname = appnode->firstname;
    newnode->lastname = appnode->lastname;
    newnode->idnumber = appnode->idnumber;
    newnode->next = appnode->next;

    if(!list){
        list = newnode;
    }
    else{
        nodeptr = newnode;
        while(nodeptr->next){
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newnode;
    }
}

void linkedlist::insertnode(string fn, string ln, int idn){
    node * prev;
    node * nodeptr;
    node * newnode;
    newnode = new node(fn, ln, idn);

    prev = nullptr;
    /*	
    newnode->firstname = insnode->firstname;
    newnode->lastname = insnode->lastname;
    newnode->idnumber = insnode->idnumber;
    newnode->next = insnode->next;
    */
    newnode->firstname = fn;
    newnode->lastname = ln;
    newnode->idnumber = idn;

    if(!list){
        list = newnode;
        newnode->next = nullptr;
    }
    else{
        nodeptr = list;
        prev = nullptr;
        while(nodeptr != nullptr && nodeptr->idnumber < newnode->idnumber){
            prev = nodeptr;
            nodeptr = nodeptr->next;    
        }
        if(prev == nullptr){
            list = newnode;
            newnode->next = nodeptr;
        }
        else{
            prev->next = newnode;
            newnode = nodeptr;
        }
    }
}

void linkedlist::deletenode(int id){
    node * prev;
    node * nodeptr;
    if(!list){
        return;
    }
    
    if(list->idnumber == id){
        nodeptr = list->next;
        delete list;
        list = nodeptr;
    }
    else{
        nodeptr = list;
        while(nodeptr != nullptr && nodeptr->idnumber != id){
            prev = nodeptr;
            nodeptr = nodeptr->next;
        }
        if(nodeptr){
            prev->next = nodeptr->next;
            delete nodeptr;
        }
        else{
            cout << "ID number not found" << endl;
        }
    }
}

void linkedlist::searchnode(int id){
    node * prev;
    node * nodeptr;
    if (!list){
    	    return;
    }

    if(list->idnumber == id){
        cout << list->lastname << ", ";
        cout << list->firstname << ", ";
        cout << list->idnumber << endl;
    }
    else{
        nodeptr = list;
        while(nodeptr != nullptr && nodeptr->idnumber != id){
            prev = nodeptr;
            nodeptr = nodeptr->next;
        }
        if(nodeptr->idnumber == id){
            cout << nodeptr->lastname << ", ";
            cout << nodeptr->firstname << ", ";
            cout << nodeptr->idnumber << endl;
        }
        else{
            cout << "ID number not found" << endl;
        }
    }
}

void linkedlist::printlist(){
    node * nodeptr;
    nodeptr = list;
    while(nodeptr){
        cout << nodeptr->lastname << ", ";
        cout << nodeptr->firstname << ", ";
        cout << nodeptr->idnumber << endl;
        nodeptr = nodeptr->next;
    }
}
