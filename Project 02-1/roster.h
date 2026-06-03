#ifndef ROSTER_H
#define ROSTER_H

#include <string>
using namespace std;

class Roster {
private:
    string students[300]; // 강좌당 최대 수강 가능 인원수: 300명 [cite: 61]
    int numStudents;

public:
    Roster();
    void addStudent(const std::string& studentName);
    void print() const;
};

#endif
