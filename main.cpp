#include <iostream>
using namespace std;

template <typename T>
class CList {
public:
    CList();
    ~CList();

    bool IsEmpty(); // list가 비어 있으면 1, 아니면 0
    bool IsFull();  // list가 꽉 차 있으면 1, 아니면 0

    void Add(T data); // list에 데이터 추가
    void Delete(T data); // list에 데이터 삭제
    void Print(); // list에 데이터 출력

private:
    T m_Array[5]; // 데이터를 저장할 공간
    int m_Length; // list에 있는 데이터 수
};

template<typename T>
CList<T>::CList() {m_Length=0;}

template<typename T>
CList<T>::~CList() {}

template<typename T>
void CList<T>::Add(T data) {m_Array[m_Length++] = data;}

int command() {
    int num;

    cout << "\n\t---- menu ----" << endl;
    cout << "\t1. 리스트 추가" << endl;
    cout << "\t2. 리스트 삭제" << endl;
    cout << "\t3. 리스트 출력" << endl;
    cout << "\t4. 프로그램 종료" << endl;
    cout << "\n\t입력 --> ";
    cin >> num;
    return num;
}
int main() {
    CList<int> list;
    int input;
    int com;
    while(1) {
        com = command();

        switch(com) {
        case 1: // 추가
            cout << "\n추가할 데이터 : ";
            cin >> input;
            list.Add(input);
            break;
        case 2: // 삭제
            cout << "\n삭제할 데이터 : ";
            cin >> input;
            list.Delete(input);
            break;
        case 3: // 출력
            list.Print();
            break;
        case 4: // 프로그램 종료
            cout << "\n\t프로그램을 종료합니다\n";
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}