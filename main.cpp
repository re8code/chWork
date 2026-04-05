#include <iostream>
#include <string>   //string객체 사용
#include <fstream>  //ifstream ofstream
#include <iomanip>  // setw
using namespace std;

int main() {
    ofstream fout;
    fout.open("example.txt");

    string s2 = "Objective Oriented Programming";
    fout << s2 << endl;
    fout << "Random Variables" << endl;
    fout << "Linear Algebra" << endl;
    fout.close();

    ifstream fin;
    string s1;
    fin.open("example.txt");
    if(!fin) {
        cout << "Error, no such file exists" << endl;
        exit(100);
    }
    while(getline(fin, s1)) {
        cout << s1 << endl;
    }
    fin.close();
    // getline()에 의한 내부 읽기 포인터를 초기화시키기 위해서
    // file input stream을 다시 연결해서 사용함.
    fin.open("example.txt");
    // while(getline(fin, s1, ' ')) {
    //     cout << s1 << endl;
    // }
    while(1) {
        fin >> s1;
        if(fin.eof()) break;

        cout << s1 << endl;
    }
    fin.close();
    
    return 0;
}