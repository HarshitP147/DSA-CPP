#include <iostream>
#include <algorithm>
using namespace std;

struct Activity{
	int profit;
	int weight;
	
	Activity(){}

	Activity(int weight,int profit){
		this->weight = weight;
		this->profit = profit;
	}
};

/*
int selectObjects(int W,int n,int wt[],int pf){
	// creat a table/matrix where rows and cols represent increasing no. of max knapsack weights and no. of objects resp. 
	int tab[n+1][W+1];

	// we fill up the table in bottom-up manner
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 || j==0){
				// if i or j == 0 this means we have no objects to deal with -> no profit
				tab[i][j] = 0;
			}
			else if(
*/


int main(){
	// implementing 0/1 Knapsack problem in C++
	int W;
	cout << "Enter maximum knapsack weight:";
	cin >> W;
	
	int n;
	cout << "Enter number of objects:";
	cin >> n;

	Activity arr[n];
	for(int i=0;i<n;i++){
		int w,p;
		cout << "Enter object weight:";
		cin >> w;

		cout << "Enter object profit:";
		cin >> p;

		Activity temp(w,p);
		cout << endl;
	}


	return 0;
}




