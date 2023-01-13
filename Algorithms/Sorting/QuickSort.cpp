#include <iostream>
#include "./displayArray.h"
using namespace std;


#define MAX_ELE 2147483647  // this is for int

void swap(int &x,int &y){
	int temp = x;
	x = y;
	y = temp;
}


int partition(int arr[],int left,int right){
	int pivot = arr[left];

	int i = left,j = right;

	while(i<j){
		while(arr[i]<=pivot){
			i++;
		}

		while(arr[j]>pivot){
			j--;
		}

		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[left],arr[j]);

	return j;  // return the index of the pivot element
}


void quickSort(int arr[],int left,int right){
	if(left<right){
		int pivotPos = partition(arr,left,right);  // get the pivot index and split the array into half

		// implement the sort for both the halves of the array
		quickSort(arr,left,pivotPos);
		quickSort(arr,pivotPos+1,right);
	}
}


int main(){
	// implementing quick sort algorithm in C++
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

	len++;
	arr[len-1] = MAX_ELE;
	quickSort(arr,0,len-1);
	len--;

	cout << "Array after quick sort:" << endl;
	displayArray(arr,len);




	return 0;
}