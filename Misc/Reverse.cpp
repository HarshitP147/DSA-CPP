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
	dispArr(arr,len);
	cout << endl;

	for(int i=0;i<len/2;i++){
		int x = len-i-1;
		int temp = arr[x];
		arr[x] = arr[i];
		arr[i] = temp; 
	}

	cout << "Reversed array:" << endl;
    dispArr(arr,len);
	cout << endl;


	return 0;
}