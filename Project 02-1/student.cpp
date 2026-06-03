#include "student.h"
#include <iostream>

Student::Student(const std::string& studentName) : name(studentName) {}

string Student::getName() const {
    return name;
}

Schedule& Student::getSchedule() {
    return schedule; // 시퀀스 다이어그램의 getSchedule() 대응 [cite: 42]
}

void Student::print() const {
    cout << "Student name: " << name << "\n"; // 실행 결과 매칭 [cite: 63]
    schedule.print(); // 내부 schedule의 print() 호출 [cite: 44, 54]
}