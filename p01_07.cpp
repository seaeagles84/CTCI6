#include <iostream>
using namespace std;

//Note: do not try to use int **ppmatrix... it does not work....
void PrintMatrix(int ppmatrix[][3], int length)
{
    for (int row = 0; row < length; row++) {
        for (int col = 0; col < length; col++) {
            cout << ppmatrix[row][col] << "\t";
        }
        cout << endl;
    }
}

void RotateMatrix(int ppmatrix[][3], int length)
{
    int temp = 0;
    for (int layer = 0; layer < length/2; layer++) {
        int first = layer; // for each layer, first index 
        int last = length - layer - 1; // for each layer last index 
        for (int i = first; i < last; i++) { //not includes last! key point! (only N-1 over N)
            temp = ppmatrix[first][i]; //top
            ppmatrix[first][i] = ppmatrix[last -(i-first)][first]; //left to top
            ppmatrix[last -(i-first)][first] = ppmatrix[last][last - (i-first)]; //bottom to left
            ppmatrix[last][last - (i-first)] = ppmatrix[i][last];
            ppmatrix[i][last] = temp;
        }
    } 
}

int main() {
    int matrix[3][3] {{1, 2, 3} , {4, 5, 6}, {7, 8, 9}}; //row 0/1/2
    
    PrintMatrix(matrix, 3);
    RotateMatrix(matrix, 3);
    PrintMatrix(matrix, 3);
	return 0;
}
