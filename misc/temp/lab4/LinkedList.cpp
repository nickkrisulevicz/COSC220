#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{                   //constructor
    list = nullptr; //set list to nullptr
}

LinkedList::~LinkedList()
{                         //destructor
    Node *curr = nullptr; //curson to be used to
    if (list != nullptr)
    {                      //check to make sure list isnt empty
        curr = list->next; //next in list 2nd position
        //Node * prev = nullptr;
        while (curr != nullptr)
        {
            delete list; //delete list
            list = curr; //set list to current pos
            curr = curr->next;
        }
    }
}

Node *LinkedList::createNode()
{
    Node *newNode = new Node(); //creation of new node with allocation of space//calls node function for input
    newNode->next = nullptr;    //-> is same as (*newNode).next
    return newNode;             //returns newly created Node
}

Node *LinkedList::searchLocation(int ID)
{

    Node *Curr = list; //calls createNode function to create new node with name curr set to head of list
    Node *prev = Curr;
    if (list == nullptr)
    { //check to make sure lsit is not empty;
        cout << "This list is empty" << endl;
        return nullptr;
    }
    if (list->idNumber == ID)
    {
        return list;
    }
    Curr = Curr->next;
    while (Curr != nullptr)
    {

        if (Curr->idNumber == ID)
        { //if current id = ID
            return prev;
        }
        prev = Curr;
        Curr = Curr->next;
    }
    return nullptr;
}

void LinkedList::insertNode()
{
    Node *newNode = createNode(); //calls createNode function to create new node with name curr
    Node *curr = nullptr;         //cursor
                                  //Node * search = searchLocation(newNode->idNumber);
    curr = list;
    //test if list is empty
    if (curr == nullptr)
    {                   //if list is empty
        list = newNode; //list is empty set curr to first pos
        return;
    }

    else if (newNode->idNumber < curr->idNumber) //put id number at begining of the list
    {
        newNode->next = list; //set list to pos2
        list = newNode;       //set newnode to pos1
        return;               //return to prevent error with constant printouts
    }

    while (curr != nullptr) //
    {                       //stops before the end of the list and
        cout << "Inside while loop" << endl;

        if (curr->idNumber == newNode->idNumber) //duplication
        {
            cout << "This student is already within the current list" << endl;
            return;
        }
        else if (curr->idNumber > newNode->idNumber)
        {

            Node *search = searchLocation(curr->idNumber); //put between 2 values of list
            newNode->next = curr;                          //set node after newnode to node to be placed behind newnode
            search->next = newNode;                        //put newnode after search pos
            return;
        }

        else if (curr->next == nullptr) //place at end of the list// && curr->idNumber>
        {
            newNode->next = nullptr;
            curr->next = newNode;
            return;
        }
        curr = curr->next; //move curr to next pos in list
    }
    curr->next = newNode;
}

void LinkedList::deleteNode(int ID)
{
    Node *curr = list;
    Node *toDel = searchLocation(ID); //gives location of node before to delete
                                      //when deleting first location search location returns null because there is nothing before node1
                                      //& because it returns null then the program believes the number is not within the list
    cout << "before if statements" << endl;
    if (toDel == nullptr)
    {
        cout << "This student is currently not within the list" << endl;
        return;
    }
    if (list == toDel)
    {
        list = curr->next; //set head = to curr->next node
        delete toDel;
    }
    else if (list->idNumber == ID)
    { //delete front
        cout << " inside else if " << endl;
        curr = list->next;
        delete list; //delete header
        return;
    }
    else
    {
        cout << "before temp create in else" << endl;
        Node *Temp = toDel->next;
        cout << "after temp create" << endl;
        /*curr*/ toDel->next = Temp->next; //delete between two nodes
        delete Temp;
        return;
    }

} //end of delete funct

void LinkedList::printList()
{
    Node *curr = nullptr;
    curr = list;
    if (list == nullptr)
    {
        cout << "List is empty" << endl;
    }
    while (curr != nullptr)
    {                      //if curr is null stop print
        curr->printNode(); //print out current node
        curr = curr->next; //go to next node
    }
}

void LinkedList::searchNode()
{
    int Sid = 0;
    cout << "Input ID to search for: ";
    cin >> Sid;
    Node *isThere = searchLocation(Sid);
    cout << isThere << endl; //returns null if not within list else returns location before searched
    Node *Temp = isThere->next;
    if (isThere == nullptr)
    { //if null it is not within list
        cout << "Data is not within the list" << endl;
    }
    else
    {
        cout << "else statement" << endl;
        Temp->printNode(); //print searched for Node
    }
}