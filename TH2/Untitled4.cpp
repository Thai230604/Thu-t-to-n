#include <bits/stdc++.h>

using namespace std;
vector<int> kq;
int c = 0;
void xuat(){
	for(int i : kq){
		cout << i << " ";
	}
	cout << endl;
}
void Try(int i, int start, int k, vector<int> s){
	if(i == k){
		xuat();
		c++;
	}else{
		for(int j = start; j < s.size(); j++){
			kq.push_back(s[j]);
			Try(i + 1, j + 1, k, s);
			kq.pop_back();
		}
	}
}

int main(){
	int n = 6;
	int k = 3;
	vector<int> s = {1,2,3,4,5,6};
	Try(0, 0, k, s);
	cout << c;
}