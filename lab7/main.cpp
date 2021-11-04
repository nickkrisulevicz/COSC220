//Nick Krisulevicz
//COSC 220 - Lab 7
//11/02/2021
//main.cpp

#include <iostream>
#include <ctime>
using namespace std;

int linearrecursion(int target, int term1, int term2); //function to produce the fibonacci sequence using linear recursion

int recursivesearch(int arr[], int first, int last, int target); //function to search for an element in an array using binary recursion

int iterativesearch(int arr[], int n, int target); //function to search for an element in an array using iteration

int main(){
	int x = 50;
	int t1 = 0;
	int t2 = 1;

	cout << "Fibonacci sequence with linear recursion" << endl;
	cout << linearrecursion(x, t1, t2); //call the recursive function to print the fibonacci sequence
	cout << endl;
	
	cout << "____________________" << endl << endl;

	cout << "Search an element in the array using iterative recursion" << endl;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	for(int i = 0; i < 15; i++){
		cout << array[i] << " "; //print the array
	}
	cout << endl;

	int choice;
	cout << "Enter a number to check if it is in the array" << endl;
	cin >> choice; //user inputs number to search for in the array

	int arrsize = sizeof(array) / sizeof(array[0]);
	int index = iterativesearch(array, arrsize, choice); //call the iterative recursive function to search through the array

	if(index != -1){
		cout << "Your number choice was found " << choice << endl; //if number is found, print a message saying it was found
	}
	else{
		cout << "The element was not in the array" << endl; //if number is not found, print a message saying it was not found
	}
	
	cout << "____________________" << endl << endl;
	
	cout << "Search an element in the array using binary recursion" << endl; 
	for(int j = 0; j < 15; j++){
		cout << array[j] << " "; //print the array
	}
	cout << endl;

	cout << "Enter an element to check if it is in the array" << endl;
	cin >> choice; //user inputs number to search for in the array

	int arrsize2 = sizeof(array) / sizeof(array[0]);

	int first = 0;
	int last = arrsize2 - 1;
	int index2 = recursivesearch(array, first, last, choice); //call the binary recursive function to search for the number in the array

	if(index2 != -1){
		cout << "Element found in the array " << choice << endl; //if the number was found, print a  message saying it was found
	}
	else{
		cout << "Element not found in the array" << endl << endl; //if the number was not found, print a message saying it was not found
	}

	return 0;
}

int linearrecursion(int target, int term1, int term2){ //fibonacci sequence function definition
	cout << term1 << " ";
	if(target == 0){
		return term1 + term2; //return 0 and 1 for the first two numbers in the sequence
	}
	else{
		return linearrecursion(target - 1, term2, term1 + term2); //return the addition of the two numbers for the rest of the fibonacci sequence
	}	
}

int recursivesearch(int arr[], int first, int last, int target){ //binary recursive search function definition
	if(first > last){
		return -1;
	}
	int mid = (first + last) / 2;
	if (target == arr[mid]){
		return mid; //if the target number is mid, return mid
	}
	else if(target < arr[mid]){
		return recursivesearch(arr, first, mid - 1, target); //if the target number is greater than mid, call recursive function to recurse through array and return target when it is found
	}
	else{
		return recursivesearch(arr, mid + 1, last, target); //if the target number is less than mid, call the recursive function to recurse through array and return target when it is found
	}
}

int iterativesearch(int arr[], int n, int target){
	int first = 0;
	int last = n - 1;
	while(first <= last){ //while loop to iterate through array until the end
		int mid = (first + last) / 2;
		if(target == arr[mid]){
			return mid; //if target number is mid, return mid
		}
		else if(target < arr[mid]){
			last = mid-1; //if target number is less than mid, iterate until first equals last
		}
		else{
			first = mid + 1; //if target number is greater than mid, iterate until first equals last
		}
	}
	return -1; //return -1 if target is not found
}

