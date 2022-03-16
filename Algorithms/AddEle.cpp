#include <iostream>
using namespace std;

void dispArr(int arr[],int n){
	cout << '{';
	for(int i=0;i<n;i++){
		if(i==n-1){
			cout << arr[i] << '}' << endl;
		}
		else{
			cout << arr[i] << ',';
		}
	}
}

int main(){
	// Algorithm to add an element in an array in C++ 
	int len;
	cout << "Enter the length of the array:";cin >> len;
	int arr[len];

	for(int i=0;i<len;i++){
		cout << "Enter element:";cin >> arr[i];
	}

	cout << "Array created as :" << endl;
	dispArr(arr,len);

	int ele,pos;
	cout << "Enter the element to be added:";cin >> ele;
	cout << "Enter the index of the new element:";cin >> pos;
	len++;
	for(int x=len-1;x>pos;x--){
		arr[x]=arr[x-1];  // shifting each element one index ahead
	}
	arr[pos] = ele;
	cout << "Element added as:" << endl;
	dispArr(arr,len);
	return 0;
}