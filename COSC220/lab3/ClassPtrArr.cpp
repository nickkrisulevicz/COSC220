/*
  ClassPtrArr.cpp
  Dynamically allocated array of pointers to ThreeDimPt objects.
  Lab 8, COSC-220 Spring 2003
  Created: April 7, 2001
  Current: March 26, 2003
*/

#include "ThreeDimPt.h"

#include <iostream>


/* GetNumbPts
 * Prompts for and returns an int value.
 * Enforces the value being positive.
 */
int GetNumbPts();

/* MakeThreeDimPtArray
 * Constructs an array of pointers to ThreeDimPt objects.
 * Each pointer points to a dynamically allocated ThreeDimPt object.
 * The array is of length size.
 * Returns a pointer to the first element of the array.
 */
ThreeDimPt ** MakeThreeDimPtArray(int size);


int main()
{
  int nPts = GetNumbPts();
  int i;
  ThreeDimPt ** ptr; 

  ptr = MakeThreeDimPtArray(nPts);

  // Assign values to the x, y, and z members of each ThreeDimPt 
  // object on the array as follows:
  //   x = i, y = 2 * i,  z = 3 * i

  // Write your code here.
  
  cout << "Enter a value to be multiplied for the array " << endl;
  cin >> i;

  for (int j = 0; j < nPts; j++){
	  ptr[j] = new ThreeDimPt;
  }

  for (int k = 0; k < nPts; k++){
	  *(ptr[k]) = ThreeDimPt(i, 2 * i, 3 * i);
  }

  for (int l = 0; l < nPts; l++){
	  for (int m = 0; m < nPts; m++){
		  cout << ptr[l][m].GetX() << " " << ptr[l][m].GetY() << " " << ptr[l][m].GetZ() << endl;
	  }
  }

  for (int n = 0; n < nPts; n++){
	  delete ptr[n];
  }

  delete[] ptr;
  return 0;
}

// Write your definition here
ThreeDimPt ** MakeThreeDimPtArray(int size)
{
   ThreeDimPt ** ptarr = new ThreeDimPt*[size];
   for (int i = 0; i < size; i++){
	   ptarr[i] = new ThreeDimPt;
   }
   for (int j = 0; j < size; j++){
	   *(ptarr[j]) = ThreeDimPt();
   }
   return ptarr;
}

int GetNumbPts()
{
  using namespace std;
  int n;

  cout << "How many points? ";
  cin >> n;

  while (n < 0)
    {
      cout << "Number can't be negative" << endl;
      cout << "How many points? ";
      cin >> n;
    }

  return n;
}



