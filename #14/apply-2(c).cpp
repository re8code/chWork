#include <iostream>
#include <fstream>
#include <vector>
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

class CStudent {
private:
    string m_Name;
    int m_Number;
    string m_Major;
public:
    CStudent() {}
    ~CStudent() {}
    void setAll(string _name, int _num, string _maj) {
        m_Name = _name;
        m_Number = _num;
        m_Major = _maj;
    }
    void Display() {
        cout << "이름: " << m_Name << endl;
        cout << "학번: " << m_Number << endl;
        cout << "전공: " << m_Major << endl << endl;
    }
};

vector<CStudent> read_file(string& filename) {
    ifstream ifs(filename);
    if(!ifs.is_open()) {
        throw FileNotFoundException(filename);
    }

    int count;
    ifs >> count;

    vector<CStudent> students;
    for(int i=0; i<count; i++) {
        string name, major;
        int number;
        ifs >> name >> number >> major;

        CStudent s;
        s.setAll(name, number, major);
        students.push_back(s);
    }

    ifs.close();
    return students;
}

int main() {
    string str;
    cout << "파일 이름 : ";
    cin >> str;

    try {
        vector<CStudent> numbers = read_file(str);
        for(CStudent value : numbers)
            value.Display();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
