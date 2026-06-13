#ifndef VACATION_H
#define VACATION_H

#include <iostream>

class Vacation {
public:
    virtual void bookHotels() = 0; // 추상 함수 (순수 가상 함수)

    virtual void bookFlights() {};
    virtual void bookTours() {};
};

#endif
