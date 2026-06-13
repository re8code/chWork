#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "schedule.h"

class Student {
private:
    string name;
    Schedule schedule;

public:
    Student(string);
    string getName();
    Schedule getSchedule();
    void print();
};

#endif
