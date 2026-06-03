#ifndef PACKAGES_H
#define PACKAGES_H

#include "vacation.h"

// Package1: 호텔과 항공권만 예약
class Package1 : public Vacation {
public:
    void bookHotels() override {
        std::cout << "Hotels are booked." << std::endl;
    }
    void bookFlights() override {
        std::cout << "Flights are booked." << std::endl;
    }
    // bookTours는 빈 구현을 상속받으므로 선언하지 않아도 됨
};

// Package2: 호텔과 투어만 예약
class Package2 : public Vacation {
public:
    void bookHotels() override {
        std::cout << "Hotels are booked." << std::endl;
    }
    void bookTours() override {
        std::cout << "Tours are booked." << std::endl;
    }
    // bookFlights는 빈 구현을 상속받으므로 선언하지 않아도 됨
};

// Package3: 호텔, 항공권, 투어 모두 예약
class Package3 : public Vacation {
public:
    void bookHotels() override {
        std::cout << "Hotels are booked." << std::endl;
    }
    void bookFlights() override {
        std::cout << "Flights are booked." << std::endl;
    }
    void bookTours() override {
        std::cout << "Tours are booked." << std::endl;
    }
};

#endif