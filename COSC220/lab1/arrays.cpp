//Nick Krisulevicz
//Lab 1
//09/07/2021

#include <iostream>
using namespace std;

const int SIZE = 5;

double mean(int arr[], int size)
{
double avg;
for(int i = 0; i < SIZE; i++)
{
avg += arr[i];
}
avg = avg / size;
return avg;
}

double mean2(int *arr, int size)
{
double avg;
for(int i = 0; i < SIZE; i++)
{
avg += *(arr + i);
}
avg = avg / size;
return avg;
}

int main()
{
int nums[SIZE];
for(int i = 0; i < SIZE; i++)
{
cout << "Enter an integer: " << endl;
cin >> nums[i];
}
cout << "Mean is: " << mean(nums, SIZE) << endl;
cout << "Mean 2 is: " << mean2(nums, SIZE) << endl;
return 0;
}
