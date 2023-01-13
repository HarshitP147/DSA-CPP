#include <iostream>
using namespace std;


int main(){
    // C++ program to find the largest and smallest elements in each row and column of a matrix
	int dim = 3;
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

	cout << endl;
	for(int i=0;i<dim;i++){
		int minC = mat[0][i];	
		int minR = mat[i][0];
		for(int j=0;j<dim;j++){
			if(mat[j][i]<minC){
				minC = mat[j][i];
			}
			if(mat[i][j]<minR){
				minR = mat[i][j];
			}
		}
		printf("Smallest value in col %d : %d\n",i+1,minC);
		printf("Smallest value in row %d : %d\n",i+1,minR);
	}



	return 0;
}