#include <iostream>
using namespace std;

class CStudent {
private:
    int num;
    string nam, maj;

public:
    CStudent(): num(2018000000), nam("홍길동"), maj("컴퓨터공학과") {}
    CStudent(int _num, string _nam, string _maj) {
        num = _num; nam = _nam; maj = _maj;
    }

    void setNumber(int _num)   {num = _num;}
    void setName(string _nam)  {nam = _nam;}
    void setMajor(string _maj) {maj = _maj;}

    int    getNumber() {return num;}
    string getName()   {return nam;}
    string getMajor()  {return maj;}

    void Display() {
        cout << "학번 :" << num << endl;
        cout << "이름 :" << nam << endl;
        cout << "전공 :" << maj << endl << endl;
    }
};
int main() {
    CStudent s[3];
    int inputNumber;
    string inputName, inputMajor;
    int length=0;

    while(1) {
        cout << length+1 << "번째 학생 입력" << endl;
        cout << "학번 : "; cin >> inputNumber;
        cout << "이름 : "; cin >> inputName;
        cout << "전공 : "; cin >> inputMajor;

        bool isExist = false;
        for(int i=0; i<length; i++) {
            if(inputNumber == s[i].getNumber()) {
                isExist = true;
                break;
            }
        }
        if(isExist) {
            cout << "#중복된 학번이 존재합니다" << endl << endl;
        }
        else {
            s[length].setNumber(inputNumber);
            s[length].setName(inputName);
            s[length].setMajor(inputMajor);
            length++;
            cout << "#입력 완료" << endl << endl;
        }
        if(length==3) {
            cout << "----모든입력이 완료되었습니다----" << endl;
            break;
        }
    }
    for(int i=0; i<length; i++) {
        s[i].Display();
    }

    return 0;
}