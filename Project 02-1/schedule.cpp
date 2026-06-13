#include "schedule.h"
#include <iostream>

Schedule::Schedule() : numCourses(0) {}

void Schedule::addCourse(string courseName) {
    if(numCourses<10) {
        courses[numCourses++] = courseName;
    }
}

void Schedule::print() {
    cout << "List of Courses\n";
    for(int i=0; i<numCourses; ++i) {
        cout << courses[i] << "\n";
    }
    cout << endl;
}
