#include <iostream>
#include <fstream>
using namespace std;

int num[100];
void swap(int s, int e) {
    int t = num[s];
    num[s] = num[e];
    num[e] = t;
}
int main() {
    // Mix
    for(int i=0; i<100; i++) num[i] = i; // 인덱스 구성

    srand(time(NULL));
    int e = 100;
    while(e>0) {
        // 비중복 랜덤 재구성 진행
        int s = rand()%e;
        swap(s, (e--)-1);
    }

    // Result
    ofstream fout("temp.txt");
    for(int i=0; i<100; i++) {
        fout << num[i] << ' ';
        if(i%10 == 9) fout << endl;
    }
    fout.close();

    return 0;
}