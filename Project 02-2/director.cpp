#include "director.h"
#include "vacation.h" // Vacation 클래스 정의 포함
#include "packages.h" // Package1, 2, 3 클래스 정의 포함

// 정적 데이터 멤버 정의 및 초기화
Vacation* Director::vacation = 0;

// 클라이언트가 호출할 정적 멤버 함수 정의
void Director::book(int packageType) {
    if(packageType==1) {
        vacation = new Package1();
    }
    else if(packageType==2) {
        vacation = new Package2();
    }
    else if(packageType==3) {
        vacation = new Package3();
    }
    else {
        // packageType 1, 2, 3가 아닌 경우는 그냥 종료. main.cpp 에서는 루프 종료.
        return;
    }

    cout << "This is information about your vacation:" << endl; // 실행화면 내용으로 수정
    vacation->bookHotels();
    vacation->bookFlights();
    vacation->bookTours();
    cout << endl;
}
