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
	// Algorithm to delete an element from an array in C++
	int len;
	cout << "Enter the length of the array:";cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";cin >> arr[i];
	}	
	cout << "Array created as:" << endl;
	dispArr(arr,len);

	int pos;
	cout << "Enter the index of the element to be deleted:";cin >> pos;
	for(int i=pos;i<len;i++){
		arr[i] = arr[i+1];  // placing the elements on index before
	}
	len--;
	cout << "Element deleted as:" << endl;
	dispArr(arr,len);
	return 0;
}