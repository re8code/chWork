#include <iostream>
#include <functional>
using namespace std;

int evaluate2(function<int(int,int)> f, int x, int y) {
    return f(x, y);
}

int main() {
    int a=10, b=20;

    cout << evaluate2([a](int x, int y){return a+x+y;}, 2, 3) << endl; // 구현

    cout << [&a](int x){a=20; return a*x;}(10) << endl; // ============== 구현
    cout << "a: " << a << endl;

    return 0;
}