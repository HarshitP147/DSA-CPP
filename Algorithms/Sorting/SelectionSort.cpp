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
	// implementing selection sort algorithm in C++
	int len;
	cout << "Enter the length of the array to be created:";cin >> len;
	int arr[len];
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}