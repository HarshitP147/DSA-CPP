#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int mcm(int i,int j,int d[]){
	if(i==j){
		return 0;
	}
	else{
		int minVal = INT_MAX;
		for(int k=i;k<j;k++){
			 int sum = mcm(i,k,d)+mcm(k+1,j,d)+d[i-1]*d[k]*d[j] ;
			 if(sum<minVal){
				 minVal = sum;
			 }
		}

		return minVal;
	}
}

int main(){
	// c[i,j] = min( c[i,k] + c[k+1,j] + d[i-1]*d[k]*d[j] ) i<=k<j
	int n;
	cout << "Enter the number of matrices:";
	cin >> n;
	cout << "The number of dimensions would be one more than the number of matrices." << endl;

	int d[++n];
	for(int i=0;i<n;i++){
		cout << "Enter dimension:";
		cin >> d[i];
	}
	
	int minCost = mcm(1,n-1,d);

	cout << "Minimum cost required:" << minCost << endl;

	return 0;
}

