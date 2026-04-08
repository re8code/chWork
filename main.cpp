#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("text5.txt");

    string line;
    char res[1000] = {};
    int offset=0;

    while(getline(fin, line)) {
        strcpy(res+offset, line.c_str());
        res[offset+line.length()] = ' ';
        offset += line.length()+1;
    }
    fin.close();

    int len;
    cout << "length = "; cin >> len;

    ofstream fout("output.txt");
    string result = string(res);
    for(int i=0; i<result.length(); i++) {
        fout << result[i];
        if(i%len==len-1) fout << endl;
    }
    fout.close();

    return 0;
}