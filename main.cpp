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
void swapRows(double** matrix, int row1, int row2) {
    double* temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}
void performGaussianElimination(double** matrix, int n) {
/*  Gauss-Jordan Elimination
    if(matrix[0][0] == 0) swapRows(matrix, 0, 1);

    for(int r=0; r<3; r++) {
        // elementary row
        double v = matrix[r][r];
        for(int c=0; c<n+1; c++) matrix[r][c] /= v;

        // elimination
        for(int _r=0; _r<n; _r++) {
            if(_r == r) continue;

            v = matrix[_r][r]*(-1);
            for(int c=0; c<n+1; c++) matrix[_r][c] += v*matrix[r][c];
        }
    }
// */
// /*
    for(int i=0; i<n; i++) {
        // Partial Pivoting: 현재 열에서 절대값이 가장 큰 행을 찾음
        int maxRow = i;
        for(int k=i+1; k<n; k++) {
            if(std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // 항상 가장 큰 피벗을 가진 행과 교환합니다.
        if(maxRow != i) {
            swapRows(matrix, i, maxRow);
        }
        // forward elimination 수행
        for(int k=i+1; k<n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for(int j=i; j<n+1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
// */
    // correction
    for(int r=0; r<n; r++) {
        for(int c=0; c<n+1; c++){
            if(matrix[r][c] == 0) matrix[r][c] = 0;
            else if(std::abs(matrix[r][c]) < 1e-9) matrix[r][c] = 0;
        }
    }
    // 소거 결과 출력 추가
    std::cout << "Gaussian Elimination result is:" << std::endl;
    printMatrix(matrix, n);
}
void backSubstitution(double** matrix, int n, double* solution) {
    for(int i=n-1; i>=0; i--) {
        solution[i] = matrix[i][n];
        for(int j=i+1; j<n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];

        // -0.0 오차 방지
        if (std::abs(solution[i]) < 1e-6) {
            solution[i] = 0.0;
        }
    }
}
// ============================================================================
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