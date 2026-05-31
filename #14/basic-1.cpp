#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{ 1, 2, 3, 4 };

    int index;
    cin >> index;

    try {
        cout << v.at(index) << endl;
    }
    catch (exception& e) {
        cout << "invalid vector<T> subscript" << endl; // e.what()
        cout << "인덱스 에러" << endl;
    }

    cout << "[Program is running]" << endl;
    return 0;
}
