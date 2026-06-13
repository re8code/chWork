#include "roster.h"
#include <iostream>

Roster::Roster() : numStudents(0) {}

void Roster::addStudent(string studentName) {
    if(numStudents<300) {
        students[numStudents++] = studentName;
    }
}

void Roster::print() {
    cout << "List of Students\n";
    for(int i=0; i<numStudents; i++) {
        cout << students[i] << "\n";
    }
    cout << endl;
}
