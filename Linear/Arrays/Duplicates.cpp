#include <bits/stdc++.h>
#include "./displayArray.h"
using namespace std;


int main(){
    int len;
    cout << "Enter the length of the array:";
    cin >> len;
    int arr[len];
    for(int i=0;i<len;i++){
        cout << "Enter element:";
        cin >> arr[i];
    }

    vector<int> v;

    for(int i=0;i<len;i++){
        int count = 1;
        for(int j=i+1;j<len;j++){
            if(arr[i]==arr[j]){
                count++;
            }    
        }

        if(count>1){
            // cout << arr[i] << endl;
            v.push_back(arr[i]);
        }
    }   
    cout << endl;

    for(vector<int>::iterator itr = v.begin();itr!=v.end();itr++){
        // cout << *itr << endl;
        int i = 0,n = len,pos = 0;
        while(i<len){
            if(arr[i]==(*itr)){
                pos = i;
                break;
            }
            i++;
        }

        // now that we have the position of the element to be removed, we can start switching and swap each elements and then decrease the length of the array
        for(int i=pos;i<len;i++){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        len--;
    }

    displayArray(arr,len);

    cout << endl;

    return 0;
}   