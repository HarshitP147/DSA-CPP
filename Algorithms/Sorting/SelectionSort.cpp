#include <iostream>
#include "displayArray.h"
using namespace std;


void selectionSort(int arr[],int len){
	for(int i=0;i<len-1;i++){
		int min = arr[i],max=arr[i],min_pos=i,max_pos=i;
		for(int j=i+1;j<len;j++){
			// now iterating through the entire array and find the smallest
			if(arr[j]<min){
				min=arr[j];
				min_pos = j;
			}
			if(arr[j]>max){
				max = arr[j];
				max_pos=  j;
			}
		}
		// now accessing element and swapping
			if(arr[i]>arr[min_pos]){
				int temp = arr[min_pos];
				arr[min_pos] = arr[i];
				arr[i] = temp;
			}
	}
}

int main(){
	// implementing selection sort algorithm in C++
	int len;
	cout << "Enter the length of the array to be created:";cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}

	cout << "Array before selection sort:" << endl;
	displayArray(arr,len);

	selectionSort(arr,len);

	cout << "Array after selection sort:" << endl;
	displayArray(arr,len);
	

	return 0;
}