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

void bubble_sort(int arr[],int n){
	for(int i=0;i<n-1;++i){
		for(int j=i;j<n;j++){
				if(arr[i]>arr[j]){
					int temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
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

	bubble_sort(arr,len);

	cout << "Array after bubble sort:" << endl;
	dispArr(arr,len);


	return 0;
}