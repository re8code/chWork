#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    list<int> myList{1, 2, 3, 4};
    char command;
    int inputVal;
    bool finished = false;

    while(!finished) {
        cout << "I)nput, P)rint, L)ength, Q)uit>>";
        cin  >> command;

        switch(command) {
        case 'I': case 'i':
            cin >> inputVal;
            myList.push_back(inputVal); // ========================== 구현
            break;

        case 'P': case 'p': // ====================================== 구현
            for(auto e : myList) cout << e << '\t';
            cout << endl;
            break;

        case 'L': case 'l': // ====================================== 구현
            cout << "Number of items: " << myList.size() << endl;
            break;

        case 'E': case 'e': // ====================================== 구현
            myList.clear();
            break;

        case 'Q': case 'q':
            finished = true;
            cout << "Exit the program" << endl;
            break;

        default:
            cout << "Wrong command" << endl;
            break;
        }
    }
    return 0;
}