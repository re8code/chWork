#include "course.h"
#include <iostream>

Course::Course(const std::string& courseName, int courseUnits) 
    : name(courseName), units(courseUnits) {}

std::string Course::getName() const {
    return name;
}

Roster& Course::getRoster() {
    return roster; // 시퀀스 다이어그램의 getRoster() 대응 [cite: 40]
}

void Course::print() const {
    std::cout << "Course Name: " << name << "\n"; // 실행 결과 매칭 [cite: 74]
    std::cout << "Number of Units: " << units << "\n"; // 실행 결과 매칭 [cite: 75]
    roster.print(); // 내부 roster의 print() 호출 [cite: 45]
}