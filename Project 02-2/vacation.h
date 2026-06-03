#ifndef VACATION_H
#define VACATION_H

#include <iostream>

// 모든 여행 패키지의 베이스가 되는 추상 클래스
class Vacation {
public:
    virtual ~Vacation() {} // 가상 소멸자 선언 (메모리 누수 방지)

    // 순수 가상 함수 (파생 클래스에서 반드시 구현해야 함)
    virtual void bookHotels() = 0;

    // 일반 가상 함수 (기본적으로 빈 구현을 제공하여 선택적 오버라이딩 허용)
    virtual void bookFlights() {}
    virtual void bookTours() {}
};

#endif