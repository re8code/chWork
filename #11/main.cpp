#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
    static int numCreatedObjects;
public:
    Point() : x(0), y(0) {
        numCreatedObjects++;
    }
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
    ~Point() {
        cout << "Destructed..." << endl;
    }

    void setXY(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
    int getX() const {return x;}
    int getY() const {return y;}

    // *this + pt2 -> ???
    Point operator+(Point& pt2) {
        (*this).x += pt2.x;
        (*this).y += pt2.y;
        return *this;
    }
    Point& operator=(Point& pt) {
        this->x = pt.x;
        this->y = pt.y;
        return *this;
    }
    static int getNumCreatedObject() {return numCreatedObjects;}
    friend void print(const Point& pt);
    friend ostream& operator<<(ostream& cout, Point& pt);
    friend class SpyPoint;
};

int Point::numCreatedObjects = 0;

void print(const Point& pt) {
    cout << pt.x << ", " << pt.y << endl;
}
ostream& operator<<(ostream& cout, Point& pt) {
    cout << pt.x << ", " << pt.y << endl;
    return cout;
}
int main() {
    Point pt1(1, 2);
    cout << "pt1 : ";
    print(pt1);
    cout << endl;

    // 포인터
    Point* pPt1 = &pt1;
    cout << "pt1 : ";
    cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;

    cout << "pt1 : ";
    cout << pPt1->getX() << ", " << pPt1->getY() << endl;
    cout << endl;

    Point* pPt2 = new Point;
    pPt2->setXY(10, 20);
    cout << "pt2 : ";
    cout << pPt2->getX() << ", " << pPt2->getY() << endl;
    cout << endl;

    delete pPt2;
}