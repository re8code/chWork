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
    CStudent s1; // A
    s1.Display();

    CStudent s2(1999000000, "공지철", "연극영화과"); // B
    s2.Display();

    // C
    s1.setNumber(2006000000);
    s1.setName("민경훈");
    s1.setMajor("포스트모던");
    cout << "학번 :" << s1.getNumber() << endl;
    cout << "이름 :" << s1.getName() << endl;
    cout << "전공 :" << s1.getMajor() << endl;

    return 0;
}