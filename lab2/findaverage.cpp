//Nick Krisulevicz
//Lab 2, part 2, findaverage function
//09/14/2021

#include <iostream>
using namespace std;

void findAverage(int arr[][10], int x, float average[10])
{
for(int i = 0; i < 10; i++)
{
	for (int j = 0; j < x; j++)
	{
		average[i] += arr[i][j];
	}
}
for(int k = 0; k < 10; k++)
{
	average[k] /= x;
	cout << "Average is: " << average[k] << endl;
}
}

int main()
{
int rows;
float average[10];
cout << "Enter amount of rows for the array: " << endl;
cin >> rows;

int array[rows][10];
for(int i = 0; i < 10; i++)
{
	for (int j = 0; j < rows; j++)
	{
		cout << "Enter element in array: ";
		cin >> array[i][j];
		cout << endl;
	}
}

findAverage(array, rows, average);

return 0;
}
