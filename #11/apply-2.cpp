#include <iostream>
#define ERROR -1
using namespace std;

class Account {
private:
    string name;
    string id;
    int balance;
public:
    Account(string _n, string _id, int _bal) : name(_n), id(_id), balance(_bal) {}
    string getID() {return id;}
    int getBalance() {return balance;}

    Account& operator+(const int add) {
        this->balance += add;
        return *this;
    }
    Account& operator-(const int sub) {
        this->balance -= sub;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Account& ac) {
        os << "학번: " << ac.id << ", 이름: " << ac.name << ", 잔액: " << ac.balance << endl;
        return os;
    }
};

int main() {
    Account acnt[3] = {
        Account("장윤호", "2014", 10000),
        Account("김유민", "2019", 0),
        Account("박진배", "2013", 5000),
    };
    string id;

    while(true) {
        cout << "돈을 보낼 학생의 학번을 입력하세요: "; cin >> id;
        if(id == "종료") {
            cout << "종료합니다." << endl;
            break;
        }

        int f = ERROR; // from
        for(int i=0; i<3; i++) {
            if(id == acnt[i].getID()) {f=i; break;}
        }
        cout << "돈을 받을 학생의 학번을 입력하세요: "; cin >> id;
        int t = ERROR; // to
        for(int i=0; i<3; i++) {
            if(id == acnt[i].getID()) {t=i; break;}
        }
        int sendMoney = acnt[f].getBalance();

        // exception
        if(f == t) {
            cout << "보낼 학생과 받을 학생이 동일한 학번입니다." << endl;
            continue;
        }
        else if(f == ERROR || t == ERROR) {
            cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
            continue;
        }
        else if(sendMoney <= 0) {
            cout << "보내는 학생의 잔액이 부족합니다." << endl;
            continue;
        }


        acnt[f] = acnt[f]-sendMoney;
        acnt[t] = acnt[t]+sendMoney;
        cout << "보낸 학생의 잔액 => " << acnt[f];
        cout << "받은 학생의 잔액 => " << acnt[t];
    }
    // 프로그램 종료
    for(int i=0; i<3; i++) cout << acnt[i];
}