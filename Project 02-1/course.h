#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "roster.h"

class Course {
private:
    string name;
    int units;
    Roster roster;

public:
    Course(string, int);
    string getName();
    Roster getRoster();
    void print();
};

#endif
