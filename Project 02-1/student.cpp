#include "student.h"
#include <iostream>

Student::Student(string studentName) : name(studentName) {}

string Student::getName() {
    return name;
}

Schedule Student::getSchedule() {
    return schedule;
}

void Student::print() {
    cout << "Student name: " << name << "\n";
    schedule.print();
}
