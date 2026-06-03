#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "schedule.h" // Schedule 객체 포함 [cite: 11]

class Student {
private:
    string name; // C++ standard string [cite: 11]
    Schedule schedule;

public:
    Student(const std::string& studentName);
    string getName() const;
    Schedule& getSchedule(); // Registrar에서 내부 값을 변경할 수 있도록 참조(&) 리턴 [cite: 42]
    void print() const;
};

#endif