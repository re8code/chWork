#include <iostream>
using namespace std;

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int main() {
    int a = 10, b = 20;
    cout << a << ", " << b << endl;
    swap(&a, &b);
    cout << a << ", " << b << endl;
    return 0;
}