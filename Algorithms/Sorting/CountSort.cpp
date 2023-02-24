#include <iostream>
#include "displayArray.h"
using namespace std;


void countSort(int a[],int n){
	int k = a[0];
	for(int i=0;i<n;i++){
		if(k<a[i]){
			k = a[i];
		}
	}

	// k is the max num in the array.

	int c[k]; // this array will store the cummulative freq of each elements

	for(int i=0;i<k;i++){
		c[i] = 0;
	}

	// finding the frequency of each elements
	for(int i=0;i<n;i++){
		c[a[i]] += 1;
	}

	// getting the cummulative freq.
	for(int i=1;i<k;i++){
		c[i] += c[i-1];
	}


	// we have an auxiliary array 'b' that actually will store the sorted elements
	int b[n+1];

	// we scan the array backwards and add the sorted code
	for(int i=n-1;i>=0;i--){
		int ele = a[i];
		int countInd = c[ele];

		b[i] = ele;
		c[ele] -= 1; // decreasing the freq by one to avoid clashing for the same index while adding in the auxiliary array
	}

	// shifting back the elements one unit from auxiliary array to main array
	for(int i=0;i<n;i++){
		a[i] = b[i+1];
	}
	cout << endl;
}


int main(){
	// implementing count sort algorithm in C++
	int len;
	cout << "Enter the length of the array:";
	cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}

	cout << endl;

	cout << "Original array:" << endl;
	displayArray(arr,len);

	countSort(arr,len);

	cout << "Array after count sort:" << endl;
	displayArray(arr,len);


	return 0;
}