#include <iostream>
using namespace std;

class Student {
private:
    string name;
    string dpt;
    int    id;
    vector<string> item;
    vector<char> grade;
public:
    Student() : name("default"), dpt("depart"), id(0) {}
    Student(string _name, int _id, string _dpt) {
        name = _name;
        dpt = _dpt;
        id  = _id;
    }
    void setName(string _name) {name = _name;}
    void setDpt(string _dpt) {dpt = _dpt;}
    void setID(int _id) {id = _id;}
    void print() {
        cout << name << ' ' << id << ' ' << dpt << endl;
    }
    void addGrade(string _item, char _grade) {
        item.push_back(_item);
        grade.push_back(_grade);
    }
    void printGrades() {
        for(int i=0; i<item.size(); i++) {
            cout << item[i] << ' ' << grade[i] << endl;
        }
        cout << "GPA : " << getGPA();
    }
    float getGPA() {
        int sum = 0;
        for(int i=0; i<grade.size(); i++) {
            if(grade[i] != 'F') sum += 'E'-grade[i];
        }
        return (float)sum/grade.size();
    }
    void getYear(int _y) {
        int y = _y - id/1000000;
        string res;
        switch(y) {
        case 0:  res="Freshmen(1학년)"; break;
        case 1:  res="Sophomore(2학년)"; break;
        case 2:  res="Junior(3학년)"; break;
        case 3:  res="Senior(4학년)"; break;
        default: res="About to graduate(5학년 이상)"; break;
        }
        cout << res << endl;
    }
};
int main() {
    Student Harry("Harry", 2017310973, "CS");
    Harry.print();
    Harry.getYear(2019);
    Harry.addGrade("programming", 'A');
    Harry.addGrade("Basic Circuit", 'B');
    Harry.printGrades();
    cout << "\n\n";

    Student Ron;
    Ron.print();
    cout << "\n";
    Ron.setName("Ron");
    Ron.setID(2014103959);
    Ron.setDpt("EE");
    Ron.print();
    Ron.getYear(2019);
    Ron.addGrade("Computer Architecture", 'B');
    Ron.addGrade("Maching Learning", 'B');
    Ron.addGrade("Computer Vision", 'C');
    Ron.printGrades();
    cout << "\n\n";

    return 0;
}