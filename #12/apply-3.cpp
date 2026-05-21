#include <iostream>
using namespace std;

class Train {
public:
    Train() {}
    Train(int people) {mPeople = people;}
    ~Train() {}

    virtual int station(int takeOff, int takeOn) {
        mPeople -= takeOff;
        mPeople += takeOn;
        return 0;
    }
protected:
    int mPeople; // 사람 수
};
class Ktx: public Train {
public:
    Ktx() : Train(0) {}
    Ktx(int people) : Train(0) {}
    ~Ktx() {}
    // 기차에 사람이 타고 내리는 함수
    int station(int takeOff, int takeOn) {
        Train::station(takeOff, takeOn);
        if(mPeople < 0) {
            cout << "정원미달입니다" << endl;
            return -1;
        }
        else if(mPeople > 300) {
            cout << "정원초과입니다" << endl;
            return -1;
        }
        return 0;
    }
    int getPeople() {return mPeople;}
};

int main() {
    Ktx k;
    int off, on, maxPeople=0;
    for(int i=1; i<=5; i++) {
        cout << i << "번역: ";
        cin >> off >> on;
        if(k.station(off, on) < 0) exit(0);
        if(k.getPeople()>maxPeople) maxPeople=k.getPeople();
    }
    cout << "가장 많은 사람이 탑승 했을 때의 사람 수: " << maxPeople << endl;

    return 0;
}