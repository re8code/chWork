#include <iostream>
#include <algorithm> // sort
#define ERROR -1
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
bool CList<T>::IsEmpty() {return m_Length==0;}

template<typename T>
bool CList<T>::IsFull() {return m_Length==5;}

template<typename T>
void CList<T>::Add(T data) {
    if(IsFull()) {
        cout << "\tList is full." << endl;
        return;
    }
    for(int i=0; i<m_Length; i++) {
        if(m_Array[i] == data) {
            cout << "\t중복된 데이터가 존재합니다." << endl;
            return;
        }
    }
    // data add
    m_Array[m_Length++] = data;
    // sorting
    sort(m_Array, m_Array+m_Length);
}

template<typename T>
void CList<T>::Delete(T data) {
    if(IsEmpty()) {
        cout << "\tList is empty." << endl;
        return;
    }
    // find
    int index=ERROR;
    for(int i=0; i<m_Length; i++) {
        if(m_Array[i] == data) {index=i; break;}
    }
    if(index == ERROR) return;
    // delete
    for(int i=index; i<m_Length-1; i++)
        m_Array[i] = m_Array[i+1];
    m_Length--;
}

template<typename T>
void CList<T>::Print() {
    if(IsEmpty()) {
        cout << "\tList is empty." << endl;
        return;
    }
    cout << "\t Current List " << endl;
    cout << "\t";
    for(int i=0; i<m_Length; i++) cout << m_Array[i] << " ";
    cout << endl;
}

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