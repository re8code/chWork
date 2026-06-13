#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "student.h"
#include "course.h"

class Registrar {
public:
    Registrar();
    void enroll(Student, Course);
};

#endif
