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

// using the while loop
int binarySearch(int arr[],int len,int ele){
	int first =0 ,last= len-1;
	int pos = -1;
	

	while(first<=last){
		int mid = first + (last-first)/2;

		if(arr[mid]==ele){
			pos = mid;
			break;
		}
		else if(arr[mid]<ele){
			first = mid+1;
		}
		else if(arr[mid]>ele){
			last = mid-1;
		}
	}
	return pos;
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

	// comment out the appropriate function and execute the function accordingly
	pos = binarySearch(arr,ele,0,len-1);
	if(pos==0){
		cout << "Element not found!" << endl;
	}
	else{
		cout << "Element found at position " << pos+1 << endl;
	}

	return 0;
}