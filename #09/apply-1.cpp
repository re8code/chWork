#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

Matrix init_vector(int _r, int _c) {
    Matrix res(_r);

    srand(time(NULL));
    for(int r=0; r<_r; r++) {
        for(int c=0; c<_c; c++) {
            int v = rand()%19-9;
            res[r].push_back(v);
        }
    }
    return res;
}
int getMatrixValue(int _r, int _c, Matrix v1, Matrix v2) {
    int cnt = v2.size(), res=0;
    for(int i=0; i<cnt; i++) {
        res += v1[_r][i] * v2[i][_c];
    }
    return res;
}
Matrix multiple_vector(Matrix v1, Matrix v2) {
    int _r = v1.size(), _c = v2[0].size();
    Matrix res(_r, vector<int>(_c));

    for(int r=0; r<_r; r++) {
        for(int c=0; c<_c; c++)
            res[r][c] = getMatrixValue(r, c, v1, v2);
    }
    return res;
}
void print_vector(string title, Matrix v) {
    cout << title << " :" << endl;
    for(int r=0; r<v.size(); r++) {
        for(int c=0; c<v[r].size(); c++)
            cout << setw(5) << v[r][c];
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout << "A의 행, 열의 크기를 입력해주세요 : ";
    int r1, c1; cin >> r1 >> c1;
    cout << "B의 행, 열의 크기를 입력해주세요 : ";
    int r2, c2; cin >> r2 >> c2;

    if(r1<=0 || c1<=0 || r2<=0 || c2<=0) {
        cout << "행렬을 생성할 수 없습니다." << endl;
        return 0;
    }

    Matrix v1 = init_vector(r1, c1);
    Matrix v2 = init_vector(r2, c2);
    cout << endl;

    print_vector("A 행렬", v1);
    print_vector("B 행렬", v2);

    if(c1!=r2)
        cout << "두 행렬을 곱할 수 없습니다." << endl;
    else
        print_vector("AB 곱행렬", multiple_vector(v1, v2));

    return 0;
}