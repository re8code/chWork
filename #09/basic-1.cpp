#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

// 배열의 경우 주소값(시작주소, 끝주소)을 전달
// Q: for-loop, while-loop 모두 구성하여야 하나?
void print(int* begin, int* end) {
// /*    
    // 수업시간에 배운 주소값을 기준으로 for문 작성
    for (int* curr=begin; curr != end; curr++)
        cout << setw(4) << *curr;
//*/
/*
    // while문 구현 부분 - 수업시간에 배운 주소값을 기준으로 while문 작성
    int* curr = begin;
    while (curr != end) {
        cout << setw(4) << *curr;
        curr++;
    }
//*/
    cout << endl;
}
// (+, -) for pointer: 주소값을 증가/감소 (다음 변수 위치)
// Q: 산술 연산자 사용? or 증감 연산자 사용?
int main() {
    int list[3] = { 10, 20, 30 };
    // Q: 주소값 출력시 "0x" prefix 제거되어야 하나?
    cout << list << '\t' << *list << endl;
    cout << list+1 << '\t' << *(list+1) << endl;
    cout << list+2 << '\t' << *(list+2) << endl;

    int *begin = list;
    int* end = list + 3;
    print(begin, end);

    return 0;
}