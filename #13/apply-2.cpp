#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector> 
using namespace std;

int main() {
	srand(time(nullptr));

	vector<int> v1, v2;
	
	for(int i=0; i<10; i++) v1.push_back(rand()%11);
	for(int i=0; i<10; i++) v2.push_back(rand()%21);

    cout << "<vector 1>" << endl;
    for(auto it=v1.begin(); it!=v1.end(); it++) cout << *it << " ";
    cout << "\n<vector 2>" << endl;
    for(auto it=v2.begin(); it!=v2.end(); it++) cout << *it << " ";

    // 곱의 최댓값 & 최솟값
    int maxv=0, minv=1000;
    for(auto it1=v1.begin(); it1!=v1.end(); it1++) {
        for(auto it2=v2.begin(); it2!=v2.end(); it2++) {
            int value = (*it1)*(*it2);
            if(maxv<value) maxv=value;
            if(minv>value) minv=value;
        }
    }
    cout << endl << endl;
    cout << "최댓값 = " << maxv << endl;
    cout << "최솟값 = " << minv << endl;

    return 0;
}
