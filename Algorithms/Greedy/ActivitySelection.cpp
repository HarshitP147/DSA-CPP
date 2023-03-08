#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity{
	int start;
	int finish;

	Activity(){}

	Activity(int start,int finish){
		this->start = start;
		this->finish = finish;
	}
};

// the job is to select most of the activities that do not overlap with each other and return them as the sub array
vector<Activity> greedyActivitySelector(Activity arr[],int n){
	vector<Activity> act;

	act.push_back(arr[0]);
	int k = 1;  // a variable that stores where the last element was added whenever the condition was satisfied
	for(int m=1;m<n;m++){
		if(arr[m].start>=arr[k].finish){
			// here we check whether the start time of the next activity is >= finishing time of last activity
			act.push_back(arr[m]);
			k = m;
		}
	}

	return act;
}


int main(){
	// this is the iterative version of the activity selection problem in C++
	int n;
	cout << "Enter the number of activities:";
	cin >> n;

	Activity arr[n];
	for(int i=0;i<n;i++){
		// assuming the user will always enter finish time value more than start time
		int s,f;
		cout << "Enter activity start time:";
		cin >> s;
		cout << "Enter activity finish time:";
		cin >> f;

		Activity temp(s,f);
		arr[i] = temp;

		cout << endl;
	}

	vector<Activity> act = greedyActivitySelector(arr,n);

	// displaying all the selected activities 1
	for(auto a:act){
		printf("Start:%d  Finish:%d\n",a.start,a.finish);
	}

	return 0;
}
