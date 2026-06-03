#include "director.h"
#include "vacation.h" // Vacation 클래스 정의 포함
#include "packages.h" // Package1, 2, 3 클래스 정의 포함

// 정적 데이터 멤버 정의 및 초기화
Vacation* Director::vacation = nullptr; // C++11 이상 표준인 nullptr 권장 (0도 가능)

void Director::book(int packageType) {
    // 기존에 동적 할당된 메모리가 있다면 해제하여 누수 방지 (선택 사항이지만 안전함)
    if (vacation != nullptr) {
        delete vacation;
        vacation = nullptr;
    }

    if(packageType == 1) {
        vacation = new Package1();
    }
    else if(packageType == 2) {
        vacation = new Package2();
    }
    else if(packageType == 3) {
        vacation = new Package3();
    }
    else {
        return; // 1, 2, 3 이외의 숫자가 들어오면 함수 종료
    }

    cout << "This is information about your vacation:" << endl; // 실행 화면 한글/영어 매칭 확인 필요
    vacation->bookHotels();
    vacation->bookFlights();
    vacation->bookTours();
    cout << endl;
}