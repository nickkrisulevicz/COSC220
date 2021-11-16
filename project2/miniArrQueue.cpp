//Nick Krisulevicz
//Teammate: John Meyers
//COSC 220 - Project 2
//11/12/2021
//miniArrQueue.cpp

#include "miniArrQueue.h"
#include <iostream>

using namespace std;

template<class DataType>
miniArrQueue<DataType>::miniArrQueue(){ //constructor that initializes queue with default values
	capacity = 100;
	arr = new DataType[capacity];
	front = 0;
	rear = 1;
}

template<class DataType>
miniArrQueue<DataType>::miniArrQueue(const miniArrQueue & e){ //copy constructor which initializes a new queue with the original values in a new reference location
	arr = new DataType[e.capacity];
	capacity = e.capacity;
	front = e.front;
	rear = e.rear;
	for (int i = 0; i < e.rear; i++){
		enqueue(e.arr[i]); //deep copy
	}
}

template<class DataType>
miniArrQueue<DataType>::~miniArrQueue(){ //destructor
	delete [] arr;
}

template <class DataType>
int miniArrQueue<DataType>::size() const{
	return rear + 1; //function to return the size of the queue
}

template <class DataType>
bool miniArrQueue<DataType>::isEmpty() const{ //function used to return whether or not the queue is empty
	bool status;
	if(front == -1){
		status = true;
	}
	else{
		status = false;
	}
	return status;
}

template <class DataType>
void miniArrQueue<DataType>::enqueue(const DataType& e){ //function to enqueue an item, inserts a new item at the rear of the queue
	if(rear > capacity){
		std::cout << "Full" << std::endl;
		return;
	}else{
		arr[rear] = e;
		rear++;
	}
	return;
}

template <class DataType>
void miniArrQueue<DataType>::dequeue(){ //function to dequeue an item from the queue, removes an item from the front of the queue
	if (isEmpty() == true){
		cout << "Queue is empty, nothing to dequeue" << endl;
	}
	else{
		front = (front + 1) % capacity;
		front++;
	}
}

template <class DataType>
const DataType& miniArrQueue<DataType>::printFront(){ //function to print the front element in the queue, without deleting it
	if (isEmpty() == true){
		cout << "Queue is Empty" << endl;
		return arr[front++];
	}
	else{
		cout << arr[front];
		return arr[front++];
	}
}

template <class DataType>
void miniArrQueue<DataType>::printQueue(){ //function to print all the items in the queue in their order
	if(front == rear){
		std::cout << "Queue is Empty" << std::endl;
		return;
	}else{
		std::cout << "Queue: ";
		for(int i = 0; i < rear; i++){
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		return;
	}
}


template <class DataType>
miniArrQueue<DataType>& miniArrQueue<DataType>::operator=(const miniArrQueue<DataType>& rhs){ //operator overload function to allow assignment of queue objects
	if(this == &rhs){
		return *this;
	}
	delete[] arr;
	arr = new DataType[rhs.capacity];
	capacity = rhs.capacity;
	front = -1;
	rear = -1;
	for(int i = 0; i < rhs.rear; i++){
		enqueue(rhs.arr[i]);
	}
	return *this;
}
