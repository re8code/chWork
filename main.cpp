#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double d1 = 1.23456789;
    cout << d1 << endl;

    cout.width(10);
    cout.precision(3);
    cout << d1 << endl;

    char ch1;
    char ch2;

    cin >> ch1;
    cout << "(" << ch1 << ")" << endl;
    cin.ignore();

    cin.unsetf(ios::skipws); // default 값인 white space 제외 기능을 해제.
    cin >> ch2;
    cout << "(" << ch2 << ")" << endl;
}