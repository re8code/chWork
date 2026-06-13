#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <string>
#include <iostream>
#include <cassert>

// 전방 선언 (Forward Declaration)을 통해 Vacation 클래스의 존재를 알림
class Vacation;

using namespace std;

class Director {
  public:
    static Vacation* vacation;
    static void book(int type); 
};
#endif
