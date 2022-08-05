#include <iostream>
using namespace std;

int main(){
	int r1,c1;
	cout << "For matrix 1:" << endl;
	cout << "Enter rows for matrix 1:" ;
	cin >> r1;
	cout << "Enter columns for matrix 1:" ;
	cin >> c1;	
	int mat1[r1][c1];
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			printf("Enter element for (%d,%d):",i,j);
			cin >> mat1[i][j];
		}
		cout << endl;
	}	
	cout << endl;

	int r2=c1,c2; // r2 and c1 have to be the same to satisfy the condition to multiply
	cout << "For matrix 2:" << endl;
	cout << "Rows for matrix 2 has to be same as columns of matrix 1" << endl;
	cout << "Enter columns for matrix 2:" ;
	cin >> c2;
	int mat2[r2][c2];
	for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			printf("Enter element for (%d,%d):",i,j);
			cin >> mat2[i][j];
		}
		cout << endl;
	}
	cout << endl;


	int mat[r1][c2];
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			for(int k=0;k<c1;k++){
				mat[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}

	cout << "Resultant Matrix :" << endl;
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			cout << mat[i][j] << "\t" ;
		}
		cout << endl;
	}

	return 0;
}		