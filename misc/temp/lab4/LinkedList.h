#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
    private:
        Node * list;//points to node of linked list
        Node * createNode();//creates a node
        Node * searchLocation(int ID);//searches location for either deletion or insertion of a node

    public:
        LinkedList();//constructor allocate a LinkedList object with list set to NUL
        ~LinkedList();//destructor
        void insertNode();//create a node then insert into list at correct location
        void deleteNode(int ID);//ID is id to delete//then delete specified node based on ID number
        void printList();//display each students info within the list
        void searchNode();//check if there is a student with an ID in the list
};
#endif