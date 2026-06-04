#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class FileNotFoundException : public exception {
    string message;
public:
    FileNotFoundException(const string& fname) :
        message("File \"" + fname + "\" not found") {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

int main() {
    srand(time(0));

    // 0~100 랜덤 10x10 행렬 생성 및 temp.txt 저장
    ofstream ofs;
    ofs.open("temp.txt");
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(j>0) ofs << " ";
            ofs << rand() % 101;
        }
        ofs << "\n";
    }
    ofs.close();

    // 파일 이름 입력
    string filename;
    cout << "파일 이름 : ";
    cin >> filename;

    // 파일 읽기 → 2차원 vector에 저장
    vector<vector<int>> matrix;
    try {
        ifstream ifs(filename);
        if(!ifs.is_open()) {
            throw FileNotFoundException(filename);
        }
        for(int i=0; i<10; i++) {
            vector<int> row;
            for(int j=0; j<10; j++) {
                int val;
                ifs >> val;
                row.push_back(val);
            }
            matrix.push_back(row);
        }
        ifs.close();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
        return 0;
    }

    // 출력 크기 입력
    int r, c;
    cout << "출력할 행의 크기 : "; cin >> r;
    cout << "출력할 열의 크기 : "; cin >> c;

    // NxN 부분 출력 → 범위 초과 시 at()이 예외 발생
    try {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout << matrix.at(i).at(j) << " ";
            }
            cout << "\n";
        }
    }
    catch (exception& e) {
        cout << "\ninvalid vector<T> subscript" << '\n';
    }

    return 0;
}
