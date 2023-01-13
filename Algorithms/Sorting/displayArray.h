#include <iostream>

void displayArray(int arr[],int len){
	std::cout << "{";
	for(int i=0;i<len-1;i++){
		std::cout << arr[i] << ",";
	}
	std::cout << arr[len-1] << "}" << std::endl;
}