/*
  vectorAux.cpp
  Implementations of template functions 
  Cosc-220   Lab 7

  Thomas Anastasio
  Created: February 25, 2003
  Current: March 13, 2003
*/


//////////   THIS CODE IS PROVIDED TO STUDENTS   /////////////


//#include "vectorAux.h"

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void removeDup(std::vector<T> & v)
{
	for(int i = 0; i < v.size(); i++){
		int j = seqVectSearch(v, i+1, v.size(), v[i]); //loop to find the duplicates
		if(j < v.size()){
			v.erase(v.begin() + j); //erase the duplicate if it is found
		}
	}
}


template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first, 
		       unsigned last, const T& target)
{
  ///  Complete the code.   Use the text's sequential search
  ///  algorithm for arrays as a model.
  unsigned s = first;
  while (s != last && v[s] != target) //conditional to search through the vector until target is found
	  s++;
	  if(s < last){
		  return s; //return s if target is found
	  }
 	  return last;           // return last if target not found
  
}

template <typename T>
void writeVector(const std::vector<T> & v)
{
  unsigned i;
  unsigned n = v.size();

  for (i = 0; i < n; i++)
    std::cout << v[i] << ' ';
  std::cout << std::endl;
}
