//Nick Krisulevicz
//Teammate: John Meyers
//COSC 220 - Project 2
//11/12/2021
//miniArrStack.cpp

#include "miniArrStack.h"
#include <iostream>
using namespace std;

template<class DataType>
miniArrStack<DataType>::miniArrStack(int cap){ //constructor which initializes a stack given a capacity passed in
	capacity = cap;
	arr = new DataType[capacity];
	top = capacity - 1;
}

template<class DataType>
miniArrStack<DataType>::miniArrStack(){ //default constructor
	arr = new DataType[100];
	capacity = 100;
	top = 0;
}

template<class DataType>
miniArrStack<DataType>::miniArrStack(const miniArrStack & e){ //copy contructor
	arr = new DataType[e.capacity];
	capacity = e.capacity;
	top = -1;
	for(int i = 0; i < e.top; i++){
		push(e.arr[i]);
	}
}

template<class DataType>
miniArrStack<DataType>::~miniArrStack(){ //destructor
	delete [] arr;
}

template <class DataType>
int miniArrStack<DataType>::size() const{ //function to get the size of the stack
	int index = 0;
	index = top + 1;
	return index;
}

template <class DataType>
bool miniArrStack<DataType>::isEmpty() const{ //function to determine whether or not the stack is empty
	bool status;
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}

template <class DataType>
const DataType& miniArrStack<DataType>::printTop(){ //function to print the top element of the stack, without deleting it
	if(isEmpty() == true){
		cout << "Stack is empty" << endl;
		return arr[top];
	}
	else{
		cout << arr[top];
		return arr[top];
	}
}

template <class DataType>
void miniArrStack<DataType>::push(const DataType& e){ //function to insert an item on the top of the stack
	if(top == capacity){
		cout << "Stack is full" << endl;
	}
	else{
		top++;
		arr[top] = e;
	}
}

template <class DataType>
void miniArrStack<DataType>::pop(){ //function to remove the top item from the stack
	if(isEmpty()){
		cout << "Stack is empty, nothing to pop" << endl;
	}
	else{
		top--;
	}
}

template <class DataType>
void miniArrStack<DataType>::printStack() const{ //function to print all items in the stack in order
	int index = top;
	if(isEmpty() == true){
		cout << "Stack is empty, nothing to print" << endl;
	}
	else{	
		while(index != 0){
			cout << arr[index] << endl;
			index --;
		}
	}
}

template <class DataType>
miniArrStack<DataType>& miniArrStack<DataType>::operator= (const miniArrStack<DataType>& rhs){ //operator overload to allow assignment of class objects
	delete[] this->arr;
	capacity = rhs.capacity;
	top = rhs.top;
	this->arr = new DataType[capacity];
	for(int i = 0; i < capacity; i++){
		this->arr[i] = rhs.arr[i];
	}
	return *this;
}

template<class DataType>
void miniArrStack<DataType>::enlarge(){ //private function to allow the capacity of the stack array to increase if needed
	capacity *= 2;
	DataType* chestpain = new DataType[capacity];
	for (int i = 0; i < capacity; i++){
		chestpain[i] = arr[i];
	}
	delete [] arr;
	arr = chestpain;
}
