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

void Try(int i, int k, vector<int> s, vector<bool> d){
	if(i == k){
		xuat();
		c++;
	}else{
		for(int j = 0 ; j < s.size(); j++){
			if(d[j] == 0){
				kq.push_back(s[j]);
				d[j] = 1;
				Try(i + 1, k, s, d);
				kq.pop_back();
				d[j] = 0;
			}
		}
	}
}
int main(){
	int n = 6;
	vector<int> s= {1,2,3,4,5,6};
	vector<bool> d(n, 0);
	Try(0, n, s,d );
	cout << c;
}