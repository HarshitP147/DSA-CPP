#include <iostream>
using namespace std;

int main(){
    // program to find the transpose of a matrix
    // I'm taking a square matrix for this case
    int dim;
    cout << "Enter the dimensions of the matrix:";
    cin >> dim;

    int mat[dim][dim];

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout << "Enter element:";
            cin >> mat[i][j];
        }
        cout << endl;
    }

    cout << "Orignal matrix:" << endl;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // taking transopse within the same matrix
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim/2;j++){
            // swapping mat[i][j] and mat[j][i] 
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    cout << "Transposed matrix:" << endl;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }


    return 0;
}
