/*
  Pointers.cpp
  COSC-220 Lab 9
  Based on a lab designed by Thomas Horseman

  Thomas Anastasio
  Created: April 8, 2001
  Current: March 20, 2003
*/

#include <iostream>
#include <stddef.h>     // for NULL definition

int main()
{
  using namespace std;

  int int1 = 1, int2 = 2, int3 = 3;
  double dub1 = 1.0, dub2 = 2.0, dub3 = 3.0;
  float flt1 = 1.0f;
  char chr1 = 'a', chr2 = 'b';

  //////////////////////////////////////////////////////////////////	
  // 1. Experiment with storage sizes and addresses of various data
  // types.
  //////////////////////////////////////////////////////////////////	
  //  A.  Add statements to print the addresses of each of the 9
  //  variables declared above and record the addresses. 
  //  B.  Add statements to print the sizes (in bytes) of each of the
  //  9 variables  (use the sizeof operator).
  //  C.  Add statements to print the sizes of the addresses of the 9
  //  variables (again, use the sizeof operator).
	
  //  Write your code here:

  //Part 1A: print out addresses for each variable
  cout << "The addresses for each of the variables: " << endl;
  cout << &int1 << endl;
  cout << &int2 << endl;
  cout << &int3 << endl;
  cout << &dub1 << endl;
  cout << &dub2 << endl;
  cout << &dub3 << endl;
  cout << &flt1 << endl;
  cout << &chr1 << endl;
  cout << &chr2 << endl;
  
  //Part 1B: print size of each variable
  cout << endl << "The size of each of the variables: " << endl;
  cout << sizeof(int1) << endl;
  cout << sizeof(int2) << endl;
  cout << sizeof(int3) << endl;
  cout << sizeof(dub1) << endl;
  cout << sizeof(dub2) << endl;
  cout << sizeof(dub3) << endl;
  cout << sizeof(flt1) << endl;
  cout << sizeof(chr1) << endl;
  cout << sizeof(chr2) << endl;

  //PArt 1C: print size of addresses for each variable
  cout << endl << "The size of each address of each of the variables: " << endl;
  cout << sizeof(&int1) << endl;
  cout << sizeof(&int2) << endl;
  cout << sizeof(&int3) << endl;
  cout << sizeof(&dub1) << endl;
  cout << sizeof(&dub2) << endl;
  cout << sizeof(&dub3) << endl;
  cout << sizeof(&flt1) << endl;
  cout << sizeof(&chr1) << endl;
  cout << sizeof(&chr2) << endl;

  cout << "-----------------------------------------" << endl << endl;

  // Record your results here:
  //  
  //  Variable  Size   Address   Address-Size
  //   int1	    4  0x7fffe606d9a0	 	 8
  //   int2	    4  0x7fffe606d9a4		 8
  //   int3	    4  0x7fffe606d9a8		 8
  //   dub1	    8  0x7fffe606d9b0		 8	
  //   dub2	    8  0x7fffe606d9b8		 8
  //   dub3	    8  0x7fffe606d9c0		 8
  //   flt1	    4  0x7fffe606d9ac		 8
  //   chr1	    1  ab?				       8
  //   chr2	    1  b?				         8


  // How many bytes of storage is allocated for each data type?  How
  // many bytes is allocated for each pointer (address). Notice that
  // the data types are not necessarily the same size, but the
  // pointers are.
  // 
  // Did the address of the char variables print as you expected?  If
  // not, why not?   You can force the printed output to be
  // interpreted as a pointer by coercing it (casting) to void* like
  // this:
  //    cout << (void *) &chr1;
  //
  // Run the program again, using the coercion for the char
  // pointers. Record your data.

  // Write your modified code here:

  cout << (void *) &chr1 << endl;
  cout << (void *) &chr2 << endl;


  cout << "-----------------------------------------" << endl << endl;


  // Record your results here:
  //  
  //  Variable  Size   Address   Address-Size
  //  chr1      1   0x7fffc42677ae    8
  //  chr2      1   0x7fffc42677af    8

  //////////////////////////////////////////////////////////////////	
  // 2. Experiment with pointer variables.
  //////////////////////////////////////////////////////////////////	
  //   A. Declare pointer vaiables intPtr1, intPtr2, intPtr3, dubPtr1,
  //   dubPtr2, dubPtr3, fltPtr1, chrPtr1, and chrPtr2 so that they
  //   can be used to point to the  appropriate variables.  Assign the
  //   address of the appropriate variable to them and print their
  //   values.  (The char pointers will have to be coerced as before
  //   for printing).

  //  Write your code here:
  
  int *intPtr1 = &int1;
  int *intPtr2 = &int2;
  int *intPtr3 = &int3;
  double *dubPtr1 = &dub1;
  double *dubPtr2 = &dub2;
  double *dubPtr3 = &dub3;
  float *fltPtr1 = &flt1;
  char *chrPtr1 = &chr1;
  char *chrPtr2 = &chr2;

  cout << intPtr1 << endl;
  cout << intPtr2 << endl;
  cout << intPtr3 << endl;
  cout << dubPtr1 << endl;
  cout << dubPtr2 << endl;
  cout << dubPtr3 << endl;
  cout << fltPtr1 << endl;
  cout << (void *) chrPtr1 << endl;
  cout << (void *) chrPtr2 << endl;
  

  
  cout << "-----------------------------------------" << endl << endl;

  //  Report your results here:
  // 
  //   Pointer  Printed
  //  Variable   Value
  //   intPtr1  0x7ffffbd338e8
  //   intPtr2  0x7ffffbd338ec
  //   intPtr3  0x7ffffbd338f0
  //   dubPtr1  0x7ffffbd338f8
  //   dubPtr2  0x7ffffbd33900
  //   dubPtr3  0x7ffffbd33908
  //   fltPtr1  0x7ffffbd338f4
  //   chrPtr1  0x7ffffbd338e6
  //   chrPtr2  0x7ffffbd338e7

  // How do the values of the pointers compare to the values of the
  // addresses you got in the previous experiment?

  // The addresses are the same for the pointers and for the variable with the address operator

  //////////////////////////////////////////////////////////////////	
  //  3. Experiments with NULL pointers and with dereferencing
  //////////////////////////////////////////////////////////////////	
  //   A. Assign NULL to fltPtr1, then print the value of fltPtr1.
  //   B. Accessing the storage locations through the relevant
  //   pointers, assign the following values and print them.
  //       int1  12
  //       int2  22
  //       dub1  10.1
  //       dub2  20.2
  //       flt1  30.3

  // Write your code here:
  /*
  fltPtr1 = NULL;
  cout << fltPtr1 << endl << endl;
	
  *intPtr1 = 12;
  *intPtr2 = 22;
  *dubPtr1 = 10.1;
  *dubPtr2 = 20.2;
  *fltPtr1 = 30.3;

  cout << *intPtr1 << endl;
  cout << *intPtr2 << endl;
  cout << *dubPtr1 << endl;
  cout << *dubPtr2 << endl;
  cout << *fltPtr1 << endl;
  */

  // Your program should have terminated with a run-time error.
  // What error was reported?
 
  // A segmentation fault occurred 
 
  // Why did it occur?
 
  // The segmentation fault occurred because the pointers were not dynamically allocated

  //   C.  Fix the problem and repeat.

  // Write your code here:
 
  intPtr1 = NULL;
  intPtr2 = NULL;
  dubPtr1 = NULL;
  dubPtr2 = NULL;
  fltPtr1 = NULL;

  int1 = 12;
  int2 = 22;
  dub1 = 10.1;
  dub2 = 20.2;
  flt1 = 30.3;

  intPtr1 = &int1;
  intPtr2 = &int2;
  dubPtr1 = &dub1;
  dubPtr2 = &dub2;
  fltPtr1 = &flt1;

  cout << *intPtr1 << endl;
  cout << *intPtr2 << endl;
  cout << *dubPtr1 << endl;
  cout << *dubPtr2 << endl;
  cout << *fltPtr1 << endl;


  cout << "-----------------------------------------" << endl << endl;

  //////////////////////////////////////////////////////////////////	
  //  4. Experiments with pointer arithmetic
  //////////////////////////////////////////////////////////////////	
  //    A.  Print the values of intPtr2, (intPtr2+1) and
  //    (intPtr2-1). Did you get what you expected? 

  // Write your code here:
  
  cout << intPtr2 << endl;
  cout << (intPtr2 + 1) << endl;
  cout << (intPtr2 - 1) << endl;
	

  // Write your explanation here:
 
  // The values output were not as expected. I knew the pointer arithmetic would have something to do with addresses.
  // I was expecting the hex value of the address to be incrememeted by 1, however, as I found out, it was incremented by 4, since that is how many bytes
  // are in storage for an int variable.
 


  //   B. Print the value of intPtr1.
  //   C. Use the increment operator to increment intPtr1. 
  //   D. Print the value of intPtr1 again.  
  //   E. Print the value of the memory location pointed to by
  //   intPtr1.  Explain what is happening.
	
  // Write your code here:

  cout << endl << intPtr1 << endl;
  cout << intPtr1++ << endl;
  cout << intPtr1 << endl;
  cout << *intPtr1 << endl;


  // Write your explanation here.
  // Printing the address of intPtr1 and then intPtr1++ was the same. This was unexpected. However, printing intPtr1 again in a separate line incremented
  // it by 4. This was an interesting turn of events.

  cout << "-----------------------------------------" << endl << endl;


  //////////////////////////////////////////////////////////////////	
  //  5. Experiments with dynamic allocation
  //////////////////////////////////////////////////////////////////	
  //   A.  Use the new operator to dynamically allocate an integer.
  //   B.  Assign the number 6000 to the new location.
  //   C.  Print the address of this new location.
  //   D.  Print the value stored in the new location.
  //   E.  Comment on the address of the new location compared to the
  //   addresses seen in part 2.

  //  Write your code here:
  
  int *lifealert = new int;
  *lifealert = 6000;
  cout << lifealert << endl;
  cout << *lifealert << endl << endl;
  
  //  Write your results and comments here:
  //  
  //  new location address = 0x777e3c9eec0
  //  contents of new location = 6000

  //  Comment:
  //  The address of this dynamically allocated variable is not located in the same place as the other variables, as is indicated by the difference in the address.

  //  F.  Use the new operator to allocate an array of size 10 of
  //  doubles.  Fill the array with 10.0,20.0,...100.0 and print the array.

  // Write your code here:
  
  double *dynarr = new double[10];
  for (int i = 0; i < 10; i++)
  {
	  dynarr[i] = (i + 1) * 10;
	  cout << dynarr[i] << endl;
  }

  delete lifealert;
  delete[] dynarr;

  return 0;
}
