//Nick Krisulevicz
//COSC 220 - Lab 4
//linkedlist.h
//10/12/2021

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

class linkedlist{
    private:
	node list;

	void searchlocation(int id);
	    
	
    public:
        node * list = nullptr;

        linkedlist();

        ~linkedlist();

        void insertnode(string fn, string ln, int idn);

        void deletenode(int id);

        void searchnode(int id);

        void printlist();
};
#endif
