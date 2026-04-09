#include <iostream>
using namespace std;

void square(int* v) {
    int value = *v;
    *v = value * value;
}
int main() {
    int val;
    cout << "input> "; cin >> val;

    square(&val);
    cout << "제곱값> " << val << endl;
}