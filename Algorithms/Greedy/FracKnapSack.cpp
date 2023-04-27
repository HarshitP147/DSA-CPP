#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
	int profit;
	int weight;

	float ratio;

	Item(){}

	Item(int profit,int weight){
		this->profit = profit;
		this->weight = weight;

		ratio = ((float)profit/(float)weight);
	}
};

bool compareObjects(Item i1,Item i2){
	return i1.ratio > i2.ratio;
}

int selectObjects(Item arr[],int n,int W){
	sort(arr,arr+n,compareObjects); // sorting the items in profit/weight order

	int curWeight=0;
	double profit=0; 
	// variables that keep track of current weight and the profit obtained so far
	for(int i=0;i<n;i++){
		if(curWeight<W){
			// if the current weight is still less than the knapsack weight then we can add the object
			curWeight += arr[i].weight;
			profit += arr[i].profit;
		}
		else{
			// if it's more than the knapsack weight then we break down the object, add it and then stop our iteration
			profit += arr[i].profit+((double)W/(double)arr[i].weight);
			break;
		}
	}

	return profit;
}

int main(){
	// Greedy approach of the Knapsack problem in C++ 
	int W;
	cout << "Enter knapsack weight:";
	cin >> W;

	cout << endl;

	int n;
	cout << "Enter the number of objects:";
	cin >> n;

	Item arr[n];
	for(int i=0;i<n;i++){
		int weight,profit;
		cout << "Enter object weight:";
		cin >> weight;

		cout << "Enter object profit:";
		cin >> profit;

		Item temp(profit,weight);
		arr[i] = temp;
		cout << endl;
	}

	int maxProfit = selectObjects(arr,n,W);

	printf("Maximum profit obtained:%d\n",maxProfit);

	return 0;
}	
