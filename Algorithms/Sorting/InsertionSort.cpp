#include <iostream>
#include "displayArray.h"
using namespace std;


void insertionSort(int arr[],int len){
    int tempEle;
    for(int i=1;i<=len;i++){
        tempEle = arr[i];
        int j = i;
        while(arr[j-1]>tempEle && j>=1){
            arr[j] = arr[--j];
        }
        arr[j] = tempEle;
    }
}

int main(){
    // implementing insertion sort algorithm in C++

    int len;
    cout << "Enter the length of the array:";
    cin >> len;

    int arr[len];

    for(int i=0;i<len;i++){
        cout << "Enter element:";
        cin >> arr[i];
    }

    cout << "Array before insertion sort:" << endl;
    displayArray(arr,len);

    
    insertionSort(arr,len);

    cout << "Array after insertion sort:" << endl;
    displayArray(arr,len);
    


    return 0;
}