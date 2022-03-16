#include <iostream>
using namespace std;

void dispArr(int arr[],int n){
	cout << '[';
	for(int i=0;i<n;++i){
		if(i==n-1){
			cout << arr[i] << ']' << endl;
		}
		else{
			cout << arr[i] << ',';
		}
	}
}

int main(){
	// implementing bubble sort algorithm in C++
	int len;
	cout << "Enter the length of the array to be created:";cin >> len;
	int arr[len];
	for(int i=0;i<len;++i){
		cout << "Enter element:";cin >> arr[i];
	}

	cout << "Array before sorting :" << endl;
	dispArr(arr,len);

	// sorting the array using bubble sort
	for(int i=0;i<len-1;++i){
		if(arr[i]>arr[i+1]){
			int temp = arr[i]; // temporary value for swapping 
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}

	cout << "Array after bubble sort:" << endl;
	dispArr(arr,len);
	return 0;
}