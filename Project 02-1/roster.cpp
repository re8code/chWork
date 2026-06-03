#include "roster.h"
#include <iostream>

Roster::Roster() : numStudents(0) {}

void Roster::addStudent(const string& studentName) {
    if (numStudents < 300) { // 제약 조건 체크 [cite: 61]
        students[numStudents++] = studentName;
    }
}

void Roster::print() const {
    cout << "List of Students\n"; // 실행 결과 매칭 [cite: 76]
    for (int i = 0; i < numStudents; ++i) {
        cout << students[i] << "\n";
    }
    cout << endl;
}