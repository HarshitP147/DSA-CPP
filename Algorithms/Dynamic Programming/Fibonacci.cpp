#include <iostream>
#include <map>
using namespace std;

#define ll long long int

map<int,int> fibC;
// the map will act as a 'cache' and will memoize the values of each fibonacci number without having to recompute the value again
// this makes the computation much faster than the normal recursion


// note that is one simple example to display memoization

ll fib(int n){
	ll res;
	// we check whether the fibonacci is present in map or not
 	if(fibC.find(n)==fibC.end()){  // not present
		ll f;
		if(n==0){
			f = 0;
		}
		else if(n==1){
			f = 1;
		}
		else{
			f = fib(n-1)+fib(n-2);
		}
		fibC[n] = f;
		res = f;
	}
	else{
		// present, so we simply allocate the value and return
		res = fibC[n];
	}

	return res;
}

int main(){
	int n;
	cout << "Enter a number to find it's fibonacci:";
	cin >> n;

	ll f = fib(n);
	cout << "Nth Fibonacci number entered is:" << f << endl;

	return 0;
}
