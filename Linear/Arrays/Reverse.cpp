#include <iostream>
#include "./displayArray.h"
using namespace std;


int main(){
	// reversing the same array
	int len;
	cout << "Enter the length of the array:";
	cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}

	cout << "Original array:" << endl;
	displayArray(arr,len);
	cout << endl;

	for(int i=0;i<len/2;i++){
		int x = len-i-1;
		int temp = arr[x];
		arr[x] = arr[i];
		arr[i] = temp; 
	}

	cout << "Reversed array:" << endl;
    displayArray(arr,len);
	cout << endl;


	return 0;
}