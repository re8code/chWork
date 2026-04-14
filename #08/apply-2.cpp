#include <iostream>
#include <string>
using namespace std;

void changeValue(string* result) {
    cout << "Input> ";
    cin >> *result;
}
int main() {
    string str = "This is default value";
    cout << "기본값 출력> " << str << endl;

    changeValue(&str);
    cout << "변환된 값 출력> " << str << endl;
    return 0;
}
