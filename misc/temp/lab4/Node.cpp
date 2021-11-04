#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
  //constructor
  cout << "Input id number" << endl;  //input idnumber to stored
  cin >> idNumber;                    //take input
  cout << "Input first name" << endl; //input first name to be stored
  cin.ignore();
  cin.getline(firstName, 20);        //input firstname
  cout << "Input Last name" << endl; //input lastname to be stored
                                     // cin.ignore();
  cin.getline(lastName, 20);         //input lastname
}

void Node::printNode()
{

  cout << "The ID number is: " << idNumber << endl; //-> derefrences pointer and acts a the . between name function
  cout << "First Name,Last Name: ";
  for (int i = 0; i < 20; i++)
  {
    cout << firstName[i];
  }
  cout << ", ";
  for (int i = 0; i < 20; i++)
  {
    cout << lastName[i]; //(*newNode).lastname
  }
  cout << endl;
};