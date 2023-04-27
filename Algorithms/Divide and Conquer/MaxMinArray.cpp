#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinArray(int arr[],int left,int right){
	if(left==right){
		// array has only element
		return arr[left];
	}
	else if(left<right){
		int mid = (left+right)/2;  
		// find the mid of the array and compare the left-max and right-max from the sub array

		int lmin = findMinArray(arr,left,mid);
		int rmin = findMinArray(arr,mid+1,right);

		return min(lmin,rmin);
	}
	else{
		return INT_MAX;  // return INT_MAX in case any of the case fails 
	}
}

int findMaxArray(int arr[],int left,int right){
	if(left==right){
		// array has only element
		return arr[left];
	}
	else if(left<right){
		int mid = (left+right)/2;  
		// find the mid of the array and compare the left-max and right-max from the sub array

		int lmax = findMaxArray(arr,left,mid);
		int rmax = findMaxArray(arr,mid+1,right);

		return max(lmax,rmax);
	}
	else{
		return INT_MIN;  // return INT_MIN in case any of the case fails 
	}
}

int main(){
	int n;
	cout << "Enter the length of the array:";
	cin >> n;

	int arr[n];
	for(int i=0;i<n;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}
	
	int arrMax = findMaxArray(arr,0,n-1);
	int arrMin = findMinArray(arr,0,n-1);

	cout << "Maximum element of the array:" << arrMax << endl;
	cout << "Minimum element of the array:" << arrMin << endl;

	return 0;
}
