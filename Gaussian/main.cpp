#include <iostream>
#include <iomanip>
#include <cmath>

// print the matrix, use a window size of 3 and right align
void printMatrix(double** matrix, int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n+1; c++) {
            std::cout << std::setw(3) << matrix[r][c];
        }
        std::cout << std::endl;
    }
}
// Swap two rows of a matrix
void swapRows(/*fill*/) {
    /*fill*/
}
void performGaussianElimination(double** matrix, int n) {
    /*fill*/
}
void backSubstitution(double** matrix, int n, double* solution) {
    /*fill*/
}
void solveSystem(double** matrix, int n) {
    performGaussianElimination(matrix, n);
    double* solution = new double[n];
    backSubstitution(matrix, n, solution);

    std::cout << "The solution to the system of linear equations is:" << std::endl;
    std::cout << std::setprecision(6);
    for(int i=0; i<n; i++) {
        std::cout << "x[" << i << "] = " << solution[i] << std::endl;
    }
    std::cout << std::endl;
    delete[] solution;
}
int main() {
    // create the augmented matrix
    int n=3; // size of the matrix
    double** A = new double*[n];
    for(int i=0; i<n; i++) {
        A[i] = new double[n+1];
    }

    // initialize the matrix with values (does not require row exchange)
    A[0][0] = 2; A[0][1] =  3; A[0][2] = -1; A[0][3] =  1;
    A[1][0] = 4; A[1][1] =  4; A[1][2] =  3; A[1][3] =  3;
    A[2][0] = 2; A[2][1] = -3; A[2][2] =  1; A[2][3] = -1;

    // print original matrix
    std::cout << "The original matrix (the last column is augmented) is:" << std::endl;
    printMatrix(A, n);

    // solve the system of linear equations
    solveSystem(A, n);

    // initialize the matrix with values (requires row exchange)
    A[0][0] = 0; A[0][1] =  3; A[0][2] = -1; A[0][3] =  1;
    A[1][0] = 4; A[1][1] =  4; A[1][2] =  3; A[1][3] =  3;
    A[2][0] = 2; A[2][1] = -3; A[2][2] =  1; A[2][3] = -1;

    // print original matrix
    std::cout << "The original matrix (the last column is augmented) is:" << std::endl;
    printMatrix(A, n);

    // solve the system of linear equations
    solveSystem(A, n);

    // free the memory used by the matrix
    for(int i=0; i<n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}