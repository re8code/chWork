#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class FileNotFoundException : public exception {
    string message;
public:
    FileNotFoundException(string _m) :
        message("File not found: " + _m) {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

vector<int> load_vector(string filename) {
    ifstream fin(filename);

    if (!fin) {
        throw FileNotFoundException(filename);  // 구현 1
    }

    vector<int> result;
    int num, value;
    fin >> num;
    for(int i=0; i<num; i++) {
        fin >> value;           // 구현 2
        result.push_back(value);
    }
    return result;
}

int main() {
    try {
        vector<int> v = load_vector("values.dat");  // 구현 3
        for(int elem : v)
            cout << elem << ' ';
        cout << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
