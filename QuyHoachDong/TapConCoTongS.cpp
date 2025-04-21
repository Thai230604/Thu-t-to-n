#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> kq(5, vector<bool>(10, 0));

bool checkSum(vector<int> &d){
	kq[0][0] = 1;
	for(int i = 1; i <= 4 ; i++){
		for(int j = 0; j <= 9 ; j++){
			kq[i][j] = kq[i - 1][j];
			if(j >= d[i]){
				kq[i][j] = kq[i][j - d[i]];
			}
		}
	}
	return kq[4][9];
}
void xuat(){
	for(int i = 0; i <= 4 ; i++){
		for(int j = 0 ; i <= 9 ; j++){
			cout << kq[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	vector<int> d = {0,2,5,3,1};
	cout << checkSum(d);
	xuat();
}