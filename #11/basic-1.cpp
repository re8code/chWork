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
    Point(int _x, int _y) {// 1)
        x = _x; y = _y;
        numCreatedObjects++;
    }
    ~Point() {
        cout << "Destructed..." << endl;
    }
    void setXY(int _x, int _y) {// 2)
        this->x = _x;
        this->y = _y;
    }
    int getX() const {return x;}
    int getY() const {return y;}
    Point operator+(Point& pt2) {// 3)
        return Point(this->x + pt2.x, this->y + pt2.y);
    }
    Point& operator=(Point& pt) {// 4)
        this->x = pt.x;
        this->y = pt.y;
        return *this;
    }
    static int getNumCreatedObject() {return numCreatedObjects;}
    friend void print(const Point& pt);
    friend ostream& operator<<(ostream& cout, Point& pt);
    friend class SpyPoint;
};

int Point::numCreatedObjects = 0; // 5)

// =================================================================== Page 2
void print(const Point& pt) {// 6)
    cout << pt.x << ", " << pt.y << endl;
}
ostream& operator<<(ostream& cout, Point& pt) {// 7)
    cout << pt.x << ", " << pt.y << endl;
    return cout;
}
class SpyPoint { // 8)
public:
    void hack_all_info(const Point& p) {
        cout << "Hacked by SpyPoint" << endl;
        cout << "x: " << p.x << endl;
        cout << "y: " << p.y << endl;
        cout << "numCreateObj.: " << Point::numCreatedObjects << endl;
    }
};
int main() {
    Point pt1(1, 2);
    cout << "pt1 : ";
    print(pt1);
    cout << endl;

    // 포인터
    Point* pPt1 = &pt1;
    cout << "pt1 : ";
    cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl; // 9)

    cout << "pt1 : ";
    cout << pPt1->getX() << ", " << pPt1->getY() << endl; // 10)
    cout << endl;

    Point* pPt2 = new Point; // 11)
    pPt2->setXY(10, 20);
    cout << "pt2 : ";
    cout << pPt2->getX() << ", " << pPt2->getY() << endl; // 12)
    cout << endl;

// =================================================================== Page 3
    delete pPt2; // 13)

    cout << "pt1 NumCreatedObject : ";
    cout << pt1.getNumCreatedObject() << endl; // 14)

    // 15)
    Point pt2(10, 20);
    Point pt3(30, 40);
    Point pt4 = pt2 + pt3;

    cout << "pt2 : ";
    cout << pt2 << endl;
    cout << "pt3 : ";
    cout << pt3 << endl;
    cout << "pt4 : ";
    cout << pt4 << endl;

    cout << "pt1 NumCreatedObject : ";
    cout << pt1.getNumCreatedObject() << endl << endl;

    // object array
    Point* ptAry = new Point[5];
    cout << "pt2 NumCreatedObject : ";
    cout << pt2.getNumCreatedObject() << endl;
    cout << endl;

    // ptAry 메모리 해제
    delete[] ptAry;
    cout << endl;

    // friend class
    SpyPoint spy;
    cout << "pt1 info" << endl;
    spy.hack_all_info(pt1);

    cout << "pt4 info" << endl;
    spy.hack_all_info(pt4);
}