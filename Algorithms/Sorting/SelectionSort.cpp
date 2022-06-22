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

void selection_sort(char flag,int arr[],int len){
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
		switch (flag){
			case 'a':
				if(arr[i]>arr[min_pos]){
					int temp = arr[min_pos];
					arr[min_pos] = arr[i];
					arr[i] = temp;
				}
				break;
			case 'd':
				if(arr[i]<arr[max_pos]){
					int temp = arr[max_pos];
					arr[max_pos] = arr[i];
					arr[i] = temp;
				}
				break;
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

	char f;
	cout << "Enter whether to sort in ascending order or descending order:";
	cin >> f;

	cout << "Array before selection sort:" << endl;
	dispArr(arr,len);

	selection_sort(f,arr,len);

	cout << "Array after selection sort:" << endl;
	dispArr(arr,len);
	

	return 0;
}