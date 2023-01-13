#include <iostream>
using namespace std;

int main(){
    // Program to print the portions of a matrix in a triangular format
    // considering only square matrices for this code

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

	cout << "Matrix is as follows:" << endl;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			cout << mat[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	char choice;
	cout << "Printing triangle of the matrix" << endl;
	cout << "Enter one of the four choices below:" << endl;
	cout << "1 -> Top triangle" << endl;
	cout << "2 -> Bottom triangle" << endl;
	cout << "3 -> Right triangle" << endl;
	cout << "4 -> Left triangle" << endl;
	cout << "Enter choice:";
	cin >> choice;

	cout << endl;
	switch (choice){
		case '1':
			cout << "Printing top triangle" << endl;
			for(int i=0;i<dim;i++){
				for(int k=0;k<i;k++){
					cout << '\t';
				}
				for(int j=i;j<dim-i;j++){	
					cout << mat[i][j] << '\t';
				}
				for(int k=dim-i;k<dim;k++){
					cout << '\t';
				}
				cout << endl;
			}	
			break;
		case '2':
			cout << "Printing bottom triangle" << endl;
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					cout << mat[i][j] << '\t';
				}
			}
					
			break;
		case '3':
			cout << "Printing right triangle" << endl;
			for(int i=0;i<dim;i++){
				for(int k=0;k<i;k++){
					cout << '\t';
				}
				for(int j=i;j<dim;j++){
					cout << mat[i][j] << '\t';
				}
				cout << endl;
			}
			break;
		case '4':
			cout << "Printing left triangle" << endl;
			for(int i=0;i<dim;i++){
				for(int j=0;j<=i;j++){
					cout << mat[i][j] << '\t';
				}
				cout << endl;
			}
			break;
	}



    return 0;
}