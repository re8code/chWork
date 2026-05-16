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
void swapRows(double** matrix, int n, int row1, int row2) {
    double* temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}
void performGaussianElimination(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        // Partial Pivoting: 현재 열에서 절대값이 가장 큰 행을 찾음
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }

        // 항상 가장 큰 피벗을 가진 행과 교환합니다.
        if (maxRow != i) {
            swapRows(matrix, n, i, maxRow);
        }

        if (std::abs(matrix[i][i]) < 1e-9) {
            std::cerr << "Error: Matrix is singular." << std::endl;
            return;
        }

        // 전진 소거 수행
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}
void backSubstitution(double** matrix, int n, double* solution) {
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
        
        // -0.0 오차 방지
        if (std::abs(solution[i]) < 1e-9) {
            solution[i] = 0.0;
        }
    }
}
void solveSystem(double** matrix, int n) {
    performGaussianElimination(matrix, n);
    
    // 소거 결과 출력 추가
    std::cout << "Gaussian Elimination result is:" << std::endl;
    printMatrix(matrix, n);
    
    double* solution = new double[n];
    backSubstitution(matrix, n, solution);

    std::cout << "The solution to the system of linear equations is:" << std::endl;
    // 소수점 자리수 고정 해제하여 정수는 소수점 없이, 실수는 6자리까지 출력되도록 설정
    std::cout << std::setprecision(6); 
    for(int i=0; i<n; i++) {
        std::cout << "x[" << i << "] = " << solution[i] << std::endl;
    }
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