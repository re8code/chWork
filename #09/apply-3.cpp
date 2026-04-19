#include <iostream>
using namespace std;

bool check_array(int* ar, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++)
            if(ar[i] == ar[j]) return true;
    }
    return false;
}
int main() {
    while(1) {
        cout << "Please enter a number: ";
        int n; cin >> n;
        if(n < 2) {
            cout << "Wrong number!!!" << endl;
            return 0;
        }

        int size = n/2;
        cout << "Size of random array: " << size << endl;

        int* arr = new int[size];
        for(int i=0; i<size; i++)
            arr[i] = rand()%n + 1;


        cout << "[ Array ]" << endl;
        for(int i=0; i<size; i++) cout << arr[i] << " ";
        cout << endl;

        string nothing = check_array(arr, size) ? "" : "not ";
        cout << "Duplicates " << nothing << "found.\n" << endl;
    }
}