#include "registrar.h"

Registrar::Registrar() {}

void Registrar::enroll(Student& student, Course& course) {
    // 1. 강좌에서 명단을 받아와 학생 이름을 추가 [cite: 40, 41]
    course.getRoster().addStudent(student.getName());

    // 2. 학생에게서 시간표를 받아와 과목 이름을 추가 [cite: 42, 43]
    student.getSchedule().addCourse(course.getName());
}