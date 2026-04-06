#include <iostream>
using namespace std;

int main() {
    string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
    string search;
    string res = "";

    cout << "키워드 : "; cin >> search;

    int start=0, end=0, pos=0;
    while(pos != data.length()) {
        pos = data.find(',', start);
        if(pos==string::npos) pos=data.length();

        string word = data.substr(start, pos-start);
        if(word.find(search) != string::npos)
            res += (res=="" ? "" : ",") + word;
        start = pos+1;
    }
    cout <<  "검색결과 : " <<  res << endl;
}