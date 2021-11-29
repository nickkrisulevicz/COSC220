//Nick Krisulevicz
//COSC 220 - Lab 8
//11/23/2021

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

void printvector(vector<int> const& vec); //utility functions to save time
void resetvector(vector<int>& vec);

void bubblesort(vector<int>& vec); //bubble sort function

void insertionsort(vector<int>& vec); //insertion sort function

void merge(vector<int>& vec, int f, int m, int l); //merge sort functions
void mergesort(vector<int>& vec, int f, int l);

int partition(vector<int>& vec, int s, int e); //quicksort functions
void quicksort(vector<int>& vec, int s, int e);

void selectionsort(vector<int>& vec); //selection sort function

int getmax(vector<int>& vec); //radix sort functions
void countsort(vector<int>& vec, int exp);
void radixsort(vector<int>& vec);

void heapify(vector<int>& vec, int s, int i); //heap sort functions
void heapsort(vector<int>& vec);

//----------------------------------------------------------------------------------------------------
int main(){
	cout << "Quick test for each sorting alrogithm using ten special numbers" << endl << endl;
	vector<int> vec = {682, 96, 49, 500, 1499, 106, 860, 173, 966, 914};
	cout << "Unsorted vector" << endl;
	printvector(vec);
	cout << endl;

	cout << "Bubble sort"<< endl;
	bubblesort(vec);
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Insertion sort" << endl;
	insertionsort(vec);
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Merge sort" << endl;
	mergesort(vec, 0, (vec.size() - 1));
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Quick sort" << endl;
	quicksort(vec, 0, (vec.size() - 1));
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Selection sort" << endl;
	selectionsort(vec);
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Radix sort" << endl;
	radixsort(vec);
	printvector(vec);
	resetvector(vec);
	cout << endl;

	cout << "Heap sort" << endl;
	heapsort(vec);
	printvector(vec);
	resetvector(vec);
	cout << endl;

	vector<int> vec10(10);
	vector<int> vec20(20);
	vector<int> vec30(30);
	vector<int> vec40(40);
	vector<int> vec50(50);
	vector<int> vec100(100);
	vector<int> vec500(500);
	vector<int> vec1000(1000);
	vector<int> vec5000(5000);
	vector<int> vec10000(10000);
	vector<int> vec100000(100000);
	vector<int> vec500000(500000);
	
	for(int i = 0; i < vec10.size(); i++){
		vec10[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec20.size(); i++){
		vec20[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec30.size(); i++){
		vec30[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec40.size(); i++){
		vec40[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec50.size(); i++){
		vec50[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec100.size(); i++){
		vec100[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec500.size(); i++){
		vec500[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec1000.size(); i++){
		vec1000[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec5000.size(); i++){
		vec5000[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec10000.size(); i++){
		vec10000[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec100000.size(); i++){
		vec100000[i] = (rand() % 500000 + 1);
	}
	for(int i = 0; i < vec500000.size(); i++){
		vec500000[i] = (rand() % 500000 + 1);
	}

	return 0;
}
//----------------------------------------------------------------------------------------------------

void printvector(vector<int> const& vec){
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

void resetvector(vector<int>& vec){
	vec[0] = 682;
	vec[1] = 96;
	vec[2] = 49;
	vec[3] = 500;
	vec[4] = 1499;
	vec[5] = 106;
	vec[6] = 860;
	vec[7] = 173;
	vec[8] = 966;
	vec[9] = 914;
}

void bubblesort(vector<int>& vec){
	int temp;
	for (int i = 0; i < vec.size(); i++){
		for (int j = i + 1; j < vec.size(); j++){
			if(vec[j] < vec[i]){			
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}

void insertionsort(vector<int>& vec){
	for(size_t j = 1; j < vec.size(); j++){
		int k = vec[j];
		int i = j - 1;
		while(i >= 0 && vec[i] > k){
			vec[i + 1] = vec[i];
			i--;
		}
		vec[i + 1] = k;
	}
}

void merge(vector<int>& vec, int f, int m, int l){
	vector<int> temp;
	int i = f;
	int j = m + 1;
	while(i <= m && j <= l){
		if(vec[i] <= vec[j]){
			temp.push_back(vec[i]);
			++i;
		}
		else{
			temp.push_back(vec[j]);
			++j;
		}
	}
	while(i <= m){
		temp.push_back(vec[i]);
		++i;
	}
	while(j <= l){
		temp.push_back(vec[j]);
		++j;
	}
	for(int i = f; i <= l; i++){
		vec[i] = temp[i - f];
	}
}

void mergesort(vector<int>& vec, int f, int l){
	if (f < l){
		int m = (f + l) / 2;
		mergesort(vec, f, m);
		mergesort(vec, m + 1, l);
		merge(vec, f, m, l);
	}
}

int partition(vector<int>& vec, int s, int e){
	int p = e;
	int j = s;
	int temp;
	for(int i = s; i < e; i++){
		if(vec[i] < vec[p]){
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			++j;
		}
	}
	temp = vec[j];
	vec[j] = vec[p];
	vec[p] = temp;
	return j;
}

void quicksort(vector<int>& vec, int s, int e){
	if(s < e){
		int m = partition(vec, s, e);
		quicksort(vec, s, (m - 1));
		quicksort(vec, (m + 1), e);
	}
}

void selectionsort(vector<int>& vec){
	int temp;
	int s = 0;
	while(s < vec.size()){
		int m = s;
		for(int i = s + 1; i < vec.size(); i++){
			if(vec[i] < vec[m]){
				m = i;
			}
		}
		temp = vec[s];
		vec[s] = vec[m];
		vec[m] = temp;
		s++;
	}

}

int getmax(vector<int>& vec){
	int max = vec[0];
	for(int i = 1; i < vec.size(); i++){
		if(vec[i] > max){
			max = vec[i];
		}
	}
	return max;
}

void countsort(vector<int>& vec, int exp){
	vector<int> o(exp);
	int i;
	int arr[10] = {0};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> c(arr, arr + n);
	for(i = 0; i < vec.size(); i++){
		c[(vec[i] / exp) % c.size()]++;
	}
	for(i = 1; i < c.size(); i++){
		c[i] += c[i - 1];
	}
	for(i = (vec.size() - 1); i >= 0; i--){
		o[c[(vec[i] / exp) % 10] - 1] = vec[i];
		c[(vec[i] / exp) % 10]--;
	}
	for(i = 0; i < vec.size(); i++){
		vec[i] = o[i];
	}
}

void radixsort(vector<int>& vec){
	int m = getmax(vec);
	for(int exp = 1; m / exp > 0; exp *= 10){
		countsort(vec, exp);
	}
}

void heapify(vector<int>& vec, int s, int i){
	int m = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < s && vec[l] > vec[m]){
		m = l;
	}
	if(r < s && vec[r] > vec[m]){
		m = r;
	}
	if(m != i){
		int temp = vec[i];
		vec[i] = vec[m];
		vec[m] = temp;
		heapify(vec, s, m);
	}
}

void heapsort(vector<int>& vec){
	int s = vec.size();
	for(int i = (s / 2) - 1; i >= 0; i--){
		heapify(vec, s, i);
	}
	for(int i = s - 1; i >= 0; i--){
		int temp = vec[0];
		vec[0] = vec[i];
		vec[i] = temp;
		heapify(vec, i, 0);
	}
}
