#include "registrar.h"

Registrar::Registrar() {}

void Registrar::enroll(Student student, Course course) {
    // 과목에서는 학생 등록
    course.getRoster().addStudent(student.getName());
    // 학생에서는 과목 등록
    student.getSchedule().addCourse(course.getName());
}
