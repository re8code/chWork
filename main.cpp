#include <iostream>
using namespace std;

class Account {
private:
    string name;
    string id;
    int balance;
public:
    Account(string _n, string _id, int _bal) : name(_n), id(_id), balance(_bal) {}
};

int main() {
    Account acnt[3] = {
        Account("장윤호", "2014", 10000),
        Account("김유민", "2019", 0),
        Account("박진배", "2013", 5000),
    };
}