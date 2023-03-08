#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	// Linear Search Algorithm in C++
	int len;
	cout << "Enter the length of the array:";
	cin >> len;

	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";cin >> arr[i];
	}

	int ele,pos=0,chk=0;
	cout << "Enter the element you are searching for:";cin >> ele;
	for(int i=0;i<len;i++){
		if(ele==arr[i]){
			pos=i;
			chk=1;
			break;
		}
	}
	if(chk){
		cout << "Element found at index " << pos << endl;
	}
	else{
		cout << "Element not found!" << endl;
	}
	return 0;
}
