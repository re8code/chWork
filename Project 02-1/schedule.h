#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule {
private:
    string courses[10]; // 한 학생의 최대 수강 가능 과목수: 10 [cite: 61]
    int numCourses;

public:
    Schedule();
    void addCourse(const string& courseName);
    void print() const;
};

#endif
