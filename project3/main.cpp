//Nick Krisulevicz
//COSC 220 - Project 3: Binary Tree Display
//12/06/2021
//main.cpp

#include "project3_bstree.h"
#include <iostream>
using namespace std;

template <typename T>
void printout(stree<T> *tree){ //function to display the contents of each node in the binary tree
    stree<T> displaytree = *tree;
    typename stree<T>::iterator curr = displaytree.begin();
    while(curr != displaytree.end()){
        cout << *curr << " ";
        curr++;
    }
    cout << endl;
}

int main(){
    stree<int> *inttree = new stree<int>; //initialize and dynamically allocate the integer tree
    
    inttree->insert(10); //step 1: insert a bunch of integers into the tree
    inttree->insert(25);
    inttree->insert(26);
    inttree->insert(28);
    inttree->insert(29);
    inttree->insert(30);
    inttree->insert(35);
    inttree->insert(40);
    inttree->insert(50);
    inttree->insert(65);
    printout(inttree); //first print out of int tree
    
    inttree->insert(33); //step 2: insert a new node containing value of 33 into the tree
    printout(inttree); //print the int tree again

    inttree->erase(26); //step 3: erase node with value of 26 from int tree
    printout(inttree); //print the int tree again

    inttree->erase(35); //step 4: erase node with value of 35 from int tree
    printout(inttree); //print the int tree again

    inttree->erase(30); //step 5: erase node with value of 30 from int tree
    printout(inttree); //print the int tree again

    char arr[] = {'S', 'J', 'K', 'L', 'X', 'F', 'E', 'Z'}; //initialize an array of characters to be passed into the char tree
    stree<char> *chartree = new stree<char>(arr, arr + 8); //initialize the char tree with the contents of the char array
    printout(chartree); //print out the char tree for the first time

    chartree->insert('H'); //insert a node with value 'H' into the char tree
    printout(chartree); //print the char tree again

    chartree->erase('F'); //erase node with value 'F' from the char tree
    printout(chartree); //print the char tree again

    cout << endl; //testing the min functions for both trees
    cout << inttree->min() << endl;
    cout << chartree->min() << endl;

    return 0;
}

