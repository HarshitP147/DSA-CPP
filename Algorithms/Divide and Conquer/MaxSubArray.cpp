#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxCrossSumArray(int arr[],int left,int mid,int right){
	int sum = 0; // setting the sum to 0

	int leftSum = INT_MIN;  
	for(int i=left;i<=mid;i++){
		sum += arr[i];
		if(sum>leftSum){
			leftSum = sum;
		}
	}

	// we keep the left and the right sums as the minimum value initially.
	// when the sum obtained so far is greater than the left or right sums then we replace that value with those sums

	int rightSum = INT_MIN;
	sum = 0;
	for(int i=mid;i<=right;i++){
		sum += arr[i];
		if(sum>rightSum){
			rightSum = sum;
		}
	}

	int crossSum = leftSum + rightSum - arr[mid];

	// at the end we return the maximum of the left,right and the cross sum of the arrays
	return max(crossSum,max(leftSum,rightSum));
}

int maxSumSubArray(int arr[],int left,int right){
	if(left==right){
		return arr[left];
	}
	else{
		int mid = (left+right)/2;

		int lss = maxSumSubArray(arr,left,mid);
		int css = maxCrossSumArray(arr,left,mid,right);
		int rss = maxSumSubArray(arr,mid+1,right);

		// find and return the maximum of the left,cross and right sum of sub arrays and get the desired output 
		return max(lss,max(css,rss));
	}
}

int main(){
	// maximum sub array problem in C++
	int len;
	cout << "Enter the length of the array:";
	cin >> len;

	int arr[len];
	for(int i=0;i<len;i++){
		cout << "Enter element:";
		cin >> arr[i];
	}

	int maxSum = maxSumSubArray(arr,0,len-1);

	printf("Maximum sum of the sub array obtained:%d\n",maxSum);

	return 0;
}
