#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "student.h"
#include "course.h"

class Registrar {
public:
    Registrar();
    void enroll(Student& student, Course& course); // main에서 호출하는 상호작용 함수 [cite: 34]
};

#endif