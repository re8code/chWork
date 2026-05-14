#include <iostream>
using namespace std;

class Account {
private:
    string name;
    string id;
    int balance;
public:
    static int totalBalance;
    Account(): name(""), id(""), balance(0) {}
    ~Account() {
        totalBalance += balance;
    }

    void setID(string _id) {id = _id;}
    void setName(string _name) {name = _name;}
    void setBalance(int _bal) {balance = _bal;}
    string getID() {return id;}
};
int Account::totalBalance = 0;

int main() {
    int count=0;
    cout << "총 학생 수 입력: "; cin >> count;

    Account* acnt = new Account[count];

    string id, name; int bal;
    for(int i=0; i<count; i++) {
        cout << (i+1) << "번째 학생 계좌 입력 : 학번 : "; cin >> id;
        for(int j=0; j<i; j++) {
            if(id == acnt[j].getID()) exit(0);
        }

        acnt[i].setID(id);
        cout << "이름 : "; cin >> name;
        acnt[i].setName(name);
        cout << "잔액 : "; cin >> bal;
        acnt[i].setBalance(bal);
        cout << "===================================" << endl;
    }

    delete[] acnt;
    cout << "회수된 금액 : " << Account::totalBalance << endl;
}