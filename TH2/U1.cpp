#include <bits/stdc++.h>

using namespace std;
vector<char> kq;

void xuat(){
	for(char i : kq){
		cout << i << " ";
	}
	cout << endl;
}
void Try(int i , int k, vector<char> s){
	if(i == k){
		xuat();
	}else{
		for(char j : s){
			kq.push_back(j);
			Try(i + 1, k, s);
			kq.pop_back();
		}
	}
}

int main(){
	vector<char> S = {'0', '1'};
	vector<char> X = {'a', 'b'};
	int n = 3;
	Try(0, n, S);
	Try(0, 2, X);
}