#ifndef PACKAGES_H
#define PACKAGES_H

#include "vacation.h"

// Package1: Hotel과 Flight만 예약
class Package1 : public Vacation {
public:
    void bookHotels() override {
        cout << "Hotels are booked." << endl;
    }
    void bookFlights() override {
        cout << "Flights are booked." << endl;
    }
    // bookTours는 가상 함수 그대로.
};

// Package2: Hotel과 Tour만 예약
class Package2 : public Vacation {
public:
    void bookHotels() override {
        cout << "Hotels are booked." << endl;
    }
    void bookTours() override {
        cout << "Tours are booked." << endl;
    }
    // bookFlights는 가상 함수 그대로.
};

// Package3: Hotel, Flight, Tour 모두 예약
class Package3 : public Vacation {
public:
    void bookHotels() override {
        cout << "Hotels are booked." << endl;
    }
    void bookFlights() override {
        cout << "Flights are booked." << endl;
    }
    void bookTours() override {
        cout << "Tours are booked." << endl;
    }
};

#endif
