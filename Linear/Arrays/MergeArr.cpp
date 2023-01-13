#include <iostream>
#include "./displayArray.h"
using namespace std;


int main(){
	// Algorithm to merge two arrays in C++
	int n1,n2;
	cout << "Enter the length of first array:";cin >> n1;
	int arr1[n1];
	for(int i=0;i<n1;i++){
		cout << "Enter element:";cin >> arr1[i];
	}
	cout << "First array created as:" << endl;
	displayArray(arr1,n1);
	cout << "\nEnter the length of second array:";cin >> n2;
	int arr2[n2];
	for(int i=0;i<n2;i++){
		cout << "Enter element:";cin >> arr2[i];
	}
	cout << "Second array created as:" << endl;
	displayArray(arr2,n2);

	int len = n1+n2;
	int arr[len];
	for(int i=0;i<n1;i++){
		arr[i]= arr1[i];
	}
	for(int j=0;j<n2;j++){
		arr[j+n1] = arr2[j];
	}
	cout << "Merged array created as:" << endl;
	displayArray(arr,len);
	return 0;
}