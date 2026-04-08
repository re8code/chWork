#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("merge.txt");

    ifstream fin;
    fin.open("text1.txt");

    string line;
    while(getline(fin, line)) {
        fout << line << endl;
    }
    fin.close();
    fout << endl;

    fin.open("text2.txt");
    while(getline(fin, line)) {
        fout << line << endl;
    }
    fin.close();
    fout.close();

    return 0;
}