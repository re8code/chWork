# include <iostream>
# include <vector>
using namespace std;

bool found_char(const char* s, char ch) {
    for(int i=0; i<strlen(s); i++)
        if(*(s+i) == ch) return true;
    return false;
}
// Q: 예시화면의 내용이 많이 틀림.
int main() {
    // 012345(6)
    const char* phrase = "this is a phrase";  // ch[]
                                    // phrase(\0)==NULL
    for(char ch='a'; ch<='z'; ch++) {// 'a' == 65, 'z' == 97
        cout << ch << " is ";
        if(!found_char(phrase, ch))
            cout << "NOT";
        cout << " in (" << phrase <<")" << endl;
    }
    return 0;
}