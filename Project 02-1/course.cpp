#include "course.h"
#include <iostream>

Course::Course(string courseName, int courseUnits)
    : name(courseName), units(courseUnits) {}

string Course::getName() {
    return name;
}

Roster Course::getRoster() {
    return roster;
}

void Course::print() {
    cout << "Course Name: " << name << "\n";
    cout << "Number of Units: " << units << "\n";
    roster.print();
}
