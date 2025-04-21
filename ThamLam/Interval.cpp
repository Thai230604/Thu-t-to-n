#include <bits/stdc++.h>

using namespace std;
void xuat(vector<bool> k){
	for(bool i : k){
		cout << i << " ";
	}
}
vector<bool> interval(vector<pair<float , float> > s){
	float last  = -1;
	vector<bool> kq (s.size() , 0);
	for(int i = 0; i < s.size() ; i++){
		if(s[i].first >= last){
			kq[i] = 1;
			last = s[i].second;
		}
	}
	return kq;
}
int main(){
	vector< pair<float , float > > k = { {8, 8.5} , {9, 11} , {10, 11.5}, {11, 12.5}, {12, 13}};
	xuat(interval(k));
	return 0;
}