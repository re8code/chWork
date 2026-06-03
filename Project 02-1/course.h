#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "roster.h" // Roster 객체 포함 [cite: 11]

class Course {
private:
    string name; // C++ standard string [cite: 11]
    int units;
    Roster roster;

public:
    Course(const std::string& courseName, int courseUnits);
    string getName() const;
    Roster& getRoster(); // Registrar에서 내부 값을 변경할 수 있도록 참조(&) 리턴 [cite: 40]
    void print() const;
};

#endif