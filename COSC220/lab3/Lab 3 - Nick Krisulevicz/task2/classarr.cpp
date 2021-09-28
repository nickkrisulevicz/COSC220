/*
  ClassArr.cpp
  Dynamically allocated array of ThreeDimPt objects.
  Lab 10, COSC-220
  Created: April 7, 2001
  Current: November 5, 2001
*/

#include "threedimpt.h"

#include <iostream>


/* GetNumbPts
 * Prompts for and returns an int value.
 * Enforces the value being positive.
 */
int GetNumbPts();

/* MakeThreeDimPtArray
 * Constructs an array of ThreeDimPt objects.
 * Array is of length size.
 * Returns a pointer to the first element of the 
 * array.
 */
ThreeDimPt * MakeThreeDimPtArray(int size);

int main()
{
  int nPts = GetNumbPts();
  int i;

  ThreeDimPt * ptArr;  // array of ThreeDimPt objects

  ptArr = MakeThreeDimPtArray(nPts);

  // Set the x, y, and z values of each ThreeDimPt in the
  // array as x = i,  y = 2 * i,  z = 3 * i;
  //
  // Write your code here:

  cout << "Enter a value for the elements of the array to be multiplied by: " << endl;
  cin >> i;

  int x = i;
  int y = 2 * i;
  int z = 3 * i;

  for(int i = 0; i < nPts; i++){
	  ptArr[i].SetX(x);
	  ptArr[i].SetY(y);
	  ptArr[i].SetZ(z);
  }

  // Print the array.
  // 
  // Write your code here:

  for(int j = 0; j < nPts; j++)
	  cout << ptArr[j] << endl;

  delete[] ptArr;
  return 0;
}


// Uncomment and define the function.
ThreeDimPt * MakeThreeDimPtArray(int size)
{
	ThreeDimPt *threedimarray = new ThreeDimPt [size];
	for(int i = 0; i < size; i++)
		threedimarray[i] = ThreeDimPt();
	return threedimarray;
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
