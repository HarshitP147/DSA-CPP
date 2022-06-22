#include <iostream>
using namespace std;

// using recursion
int binarySearch(int arr[],int x,int srt,int end){
	if(srt>end){
		return 0;
	}
	else{
		// int mid = (srt+end)/2;
		int mid = srt + (end-srt)/2;
		if(x==arr[mid]){
			return mid;
		}
		else if(x>arr[mid]){
			binarySearch(arr,x,mid+1,end);
		}
		else if(x<arr[mid]){
			binarySearch(arr,x,0,mid-1);
		}
		else{
			return 0;
		}
	}
}

int main(){
	// Binary Search Algorithm in C++
	// The array must be sorted before executing the binary search
	int len;
	cout << "Enter the length of the array:";cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";cin >> arr[i];
	}
	int ele,pos;
	cout << "Enter the element you are searching for:";cin >> ele;

	pos = binarySearch(arr,ele,0,len-1);
	if(pos==0){
		cout << "Element not found!" << endl;
	}
	else{
		cout << "Element found at position " << pos+1 << endl;
	}

	return 0;
}