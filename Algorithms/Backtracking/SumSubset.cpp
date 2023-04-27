#include <iostream>
using namespace std;

void printSubset(int set[],int subset[],int n,int size,int sum){
	if(sum==0){
		for(int i=0;i<size;i++){
			cout << subset[i] << " ";
		}
		cout << endl;
		return;
	}
	if(n==0){
		return;
	}

	printSubset(set,subset,n-1,size,sum);

	subset[size] = set[n-1];

	printSubset(set,subset,n-1,size+1,sum-set[n-1]);
}

void findSet(int set[],int n,int sum){
	int subset[n]={};
	printSubset(set,subset,n,0,sum);
}

int main(){
	// The subset sum for fixed weight possibilies problem using backtracking in C++
	int n;
	cout << "Enter number of elements:";
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}
	cout << endl;

	int sum;
	cout << "Enter the sum amount required:";
	cin >> sum;

	cout << "Possibilies:" << endl;
	findSet(arr,n,sum);

	return 0;
}
