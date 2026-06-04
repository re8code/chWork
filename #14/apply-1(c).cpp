#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> list;

    // vector를 1~100 사이의 random한 크기로 만들고 채우는 코드 구현
    int size = rand()%100 + 1;
    for(int i=0; i<size; i++) {
        list.push_back(i);
    }

    int cnt = -1;
    while(1) {
        cnt++;
        try {list.at(cnt);}
        catch (exception& e) {
            cout << "현재 list는 " << list.size() << "의 크기를 가지고 있다" << endl;
            return 0;
        }
    }

    return 0;
}
