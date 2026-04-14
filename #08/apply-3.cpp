#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& v) {
    for(int i=0; i<v.size()/2; i++) {
        int temp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = temp;
    }
}
int main() {
    vector<int> v(10);
    for(int i=0; i<v.size(); i++) v[i] = i+1;

    cout << "기본 Vector 값:" << endl;
    for(int x : v) cout << x << " "; cout << endl;

    cout << "함수 실행 후 Vector 값:" << endl;
    reverse(v);
    for(int x : v) cout << x << " "; cout << endl;
}