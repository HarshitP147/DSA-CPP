#include <iostream>
using namespace std;

int main(){
    // C++ program to check whether a matrix is symmetric or not
    
    // symmetric matrx -> top right is same as bottom left
    int dim;
    cout << "Enter the dimensions of the matrix:";
	cin >> dim;
	int mat[dim][dim];
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			printf("Enter element for (%d,%d):",i,j);
			cin >> mat[i][j];
		}
		cout << endl;
	}	
	cout << endl;

	cout << "Matrix is as follows:" << endl;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			cout << mat[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	bool isSym = true;

	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(mat[i][j]!=mat[j][i]){
				isSym = false;
			}
		}
	}

	if(isSym){
		cout << "The entered matrix is symmetric matrix" << endl;
	} else{
		cout << "The entered matrix is not a symmetric matrix" << endl;
	}


}