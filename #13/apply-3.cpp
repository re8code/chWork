#include <iostream>
#include <string>
using namespace std; 

int main() {
    while (1) {
        string word = "";
        string rev_word = "";

		cout << "문자열 하나를 입력해주세요 : ";
		cin >> word;

		if (word == "q" || word == "Q") {
			break;
		}

        auto reverse = [](string str) {
            string res = "";
            for(int i=str.length()-1; i>=0; i--) res += str[i];
            return res;
        }; 


        // 단어 역순 구성
        rev_word = reverse(word);
		cout << "입력하신 문자열의 역순 : " << rev_word << endl;;
		
		if (word == rev_word)
			cout << "이 문자는 회문입니다." << endl << endl;
		else
			cout << "이 문자는 회문이 아닙니다." << endl << endl;
	}
	return 0;
}
