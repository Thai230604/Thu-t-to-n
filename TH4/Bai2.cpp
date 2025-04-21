#include <bits/stdc++.h>

using namespace std;

vector<char> s = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int k = 4;
vector<char> kq;
int c = 0;
void xuat(){
	for(char i : kq){
		cout << i << " ";
	}
	cout << endl;
}
void Try(int i, int start){
	if(i == k){
		xuat();
		c++;
		return;
	}else{
		for(int j = start; j < s.size(); j++){
			kq.push_back(s[j]);
			Try(i + 1, j+1);
			kq.pop_back();
		}
	}
}
int main(){
	Try(0, 0);
	cout << c;
	return 0;
}