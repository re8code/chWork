#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
    void setPoint(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
    Point operator-(const Point pt2) {
        int _x = (*this).x - pt2.x;
        int _y = (*this).y - pt2.y;
        Point result;
        result.setPoint(_x, _y);
        return result;
    }
    Point operator*(const Point pt2) {
        int _x = (*this).x * pt2.x;
        int _y = (*this).y * pt2.y;
        Point result;
        result.setPoint(_x, _y);
        return result;
    }
    double getLength() {
        return sqrt(x + y);
    }
};

int main() {
    int x1=0, y1=0, x2=0, y2=0;
    Point *pP1, *pP2, *pP3;

    cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
    cin  >> x1 >> y1;

    cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
    cin  >> x2 >> y2;

    pP1 = new Point(x1, y1);
    pP2 = new Point(x2, y2);
    pP3 = new Point();

    *pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

    cout << "두 좌표 사이의 길이는 " << pP3->getLength() << "입니다." << endl;

    return 0;
}