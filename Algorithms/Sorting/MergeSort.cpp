#include <iostream>
#include "./displayArray.h"
using namespace std;


void merge(int arr[],int mid,int left,int right){
	// get the size of the two arrays
	int n1 = mid - left + 1;
	int n2 = right - mid ;

	int arr1[n1],arr2[n2];

	for(int i=0;i<n1;i++){
		arr1[i] = arr[left+i];
	}

	for(int j=0;j<n2;j++){
		arr2[j] = arr[j+mid+1];
	}

	// now merge the two arrays accordingly to sort the function
	int i=0,j=0,k=left;
	while(i!=n1 && j!=n2){
		if(arr1[i]<arr2[j]){
			arr[k] = arr1[i++];
		} 
		else{
			arr[k] = arr2[j++];
		}
		k++;
	}

	// incase some elements are remaining in the arrays
	while(i<n1){
		arr[k++] = arr1[i++];
	}

	while(j<n2){
		arr[k++] = arr2[j++];
	}	
}


void mergeSort(int arr[],int left,int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);

		merge(arr,mid,left,right);  // now merge the two arrays
	}
}


int main(){
	// implementing merge sort algorithm in C++
	int len;
	cout << "Enter the length of the array:";
	cin >> len;
	int arr[len];

	for(int i=0;i<len;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}
	cout << endl;

	cout << "Array before merge sort:" << endl;
	displayArray(arr,len);

	mergeSort(arr,0,len);

	cout << "Array after merge sort:" << endl;
	displayArray(arr,len);


	return 0;
}