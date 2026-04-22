#include <iostream>
using namespace std;

int** buildTable(int n) {
    int** res = new int*[n];
    for(int i=0; i<n; i++)
        res[i] = new int[n];
    return res;
}
void make_identity_matrix(int** table, int n) {
    for(int i=0; i<n; i++)
        table[i][i] = 1;
}
void printTable(int** table, int n) {
    cout << "Output:" << endl;
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            cout << table[r][c] << '\t';
        cout << endl;
    }
}
int main() {
    int n=0;
    cout << "N을 입력하시오: ";
    cin >> n;
    if(n<1) {
        cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
        exit(EXIT_FAILURE);
    }

    int** table = buildTable(n);
    make_identity_matrix(table, n);
    printTable(table, n);

    for(int i=0; i<n; i++)
        delete[] table[i];
    delete[] table;

    return 0;
}