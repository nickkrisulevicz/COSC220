#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    int USR = 6;
    LinkedList List;
    while (USR != 5)
    {
        cout << "1. Insert a Node" << endl;
        cout << "2. Delete a Node" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Search for a Node" << endl;
        cout << "5. Quit program" << endl;
        cout << "________________________________" << endl;
        cout << "Input your choice." << endl;
        cin >> USR;
        if (USR < 1 || USR > 5){//user input error testing to make sure input if above  and below 6
        cout << "Wrong input, must be between 1-5\n";
        continue;

        }
        if (USR == 1)
        {
            List.insertNode();
        }
        else if (USR == 2)
        {
            int ID = 0;
            cout <<"Input id to delete"<<endl;
            cin.ignore();
            cin >> ID;
            List.deleteNode(ID);
        }
        else if (USR == 3)
        {
            List.printList();
        }
        else if (USR == 4)
        {
            List.searchNode();
        }
        else if (USR==5){
            cout << "You have quit the program."<<endl;
        List.~LinkedList();//destructor
    }
    }
}