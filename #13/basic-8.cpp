#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    for(int& elem : v1) {
        cout << elem << "\t";
    }
    cout << endl;

    for_each(v1.begin(), v1.end(), [](int x){cout << x << "\t";});
    cout << endl;

    for_each(v1.begin(), v1.end(), [](int& x){x++;});
    for_each(v1.begin(), v1.end(), [](int x){cout << x << "\t";});
    cout << endl;

    int a=10;
    for_each(v1.begin(), v1.end(), [a](int& x){x+=a;});
    for_each(v1.begin(), v1.end(), [](int x){cout << x << "\t";});
    cout << endl;

    vector<int> v2(v1.size());
    copy(v1.begin()+1, v1.end()-1, v2.begin()+2);
    for_each(v2.begin(), v2.end(), [](int x){cout << x << "\t";});
    cout << endl;

    transform(v1.begin(), v1.end(), v2.begin(), [](int x){return x*x;});
    for_each(v2.begin(), v2.end(), [](int x){cout << x << "\t";});
    cout << endl;

    return 0;
}