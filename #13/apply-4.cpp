#include <iostream>
#include <vector>
#include <iomanip>
using namespace std; 

vector<vector<int>> make_MabangJin(int num) {
	vector<vector<int>> Mabang(num, vector<int>(num, 0));
	int row = 0; 
	int col = num/2;
	int n   = 1;

	while(n <= num*num) {
		Mabang[row][col] = n;
		n++;

		int r_n = (row-1+num) % num;
		int c_n = (col+1)     % num;

		if(Mabang[r_n][c_n] != 0){
			r_n = (row+1)%num;
			c_n = col;
		}

		row = r_n;
		col = c_n;
	}
	return Mabang;
}

void print(vector<vector<int>> mabang) {
	for(auto row : mabang) {
		for(int n : row) {
			cout << setw(4) << n; 
		}
		cout << endl; 
	}
}

int main() {
	int num = 0;
	cout << "홀수 숫자 하나 입력해 주세요 : ";
	cin >> num;
	vector<vector<int>> mabang = make_MabangJin(num);

	print(mabang);
	return 0; 
}
