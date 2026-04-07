#include <iostream>
using namespace std;

int main() {
    string address, city, area, street, building;

    cout << "시 : "; cin >> city;
    cout << "구 : "; cin >> area;
    cout << "로 : "; cin >> street;
    cout << "건물명 : "; cin >> building;
    address = city+area+street+building;
    cout << address;

    return 0;
}