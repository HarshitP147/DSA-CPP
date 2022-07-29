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

void insertion_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int temp = arr[i]; // a temp value to replace the elements
        int j = i-1;
        while(arr[j]>temp){
            // incase we find the bigger value than temp then override it with the bigger value
            arr[j+1] = temp;
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    // implementing insertion sort in c++

    int len;
    cout << "Enter the length of the array:";
    cin >> len;

    len++;

    int arr[len];
    arr[0] = -32767;
    // taking the first element (outside the required limits) as the smallest int for sorting and comparing purposes

    for(int i=1;i<len;i++){
        cout << "Enter element:";
        cin >> arr[i];
    }

    cout << "Array before insertion sort:" << endl;
    dispArr(arr,len);

    
    insertion_sort(arr,len);

    cout << "Array after insertion sort:" << endl;
    dispArr(arr,len);
    


    return 0;
}