#include <iostream>
#include <vector>
using namespace std;
void print(int** m, int nRow, int nCol) {
    for(int r=0; r<nRow; r++) {
        for(int c=0; c<nCol; c++)
            cout << m[r][c] << '\t';
        cout << endl;
    }
}
int main() {
    int nRow=2, nCol=2;
    int** matrix2;
    matrix2 = new int*[nRow]; // 동적배열 선언(행기준)
    for(int i=0; i<nRow; i++)
        matrix2[i] = new int[nCol]; // 동적배열 선언(열기준)

    matrix2[0][0] = 1; matrix2[0][1] = 2;
    matrix2[1][0] = 3; matrix2[1][1] = 4;

    print(matrix2, nRow, nCol);

    for(int i=0; i<nRow; i++)
        delete[] matrix2[i];
    delete[] matrix2;

    return 0;
}