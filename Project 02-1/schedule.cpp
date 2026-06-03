#include "schedule.h"
#include <iostream>

Schedule::Schedule() : numCourses(0) {}

void Schedule::addCourse(const string& courseName) {
    if (numCourses < 10) { // 제약 조건 체크 [cite: 61]
        courses[numCourses++] = courseName;
    }
}

void Schedule::print() const {
    cout << "List of Courses\n"; // 실행 결과 매칭 [cite: 64]
    for (int i = 0; i < numCourses; ++i) {
        std::cout << courses[i] << "\n";
    }
    cout << endl;
}