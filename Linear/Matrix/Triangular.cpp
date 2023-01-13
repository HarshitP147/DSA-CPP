#include <iostream>
using namespace std;


int main(){
    // Program to check whether a matrix is triangular or not
    // a triangular matrix means either upper half or the lower half of a matrix is zero
    // diagonal is not considered



	int dim
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

	cout << "Matrix is as follows:" << endl;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			cout << mat[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;


	bool isLowerTriangular = true;
	bool isUpperTriangular = true;

	for(int i=0;i<dim;i++){
		for(int j=0;j<i;j++){
			if(mat[i][j]!=0){
				isLowerTriangular = false;
			}
		}
	}

	for(int i=0;i<dim;i++){
		for(int j=i+1;j<dim;j++){
			if(mat[i][j]!=0){
				isUpperTriangular = false;
			}
		}
	}

	if(isUpperTriangular || isLowerTriangular){
		cout << "The matrix is a triangular matrix" << endl;
	} else{
		cout << "This matrix is not a triangular matrix" << endl;
	}


	return 0;
}	