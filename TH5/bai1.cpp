#include <bits/stdc++.h>

using namespace std;

void xuat(vector<int>&d){
	for(int i : d){
		cout << i << " ";
	}
	cout << endl;
}
vector<int> changecoin(vector<int> &moneys , int n){
	vector<int> kq(moneys.size(), 0);
	int i = 0;
	while(n != 0 && i < moneys.size()){
		kq[i] = n/moneys[i];
		n = n%moneys[i];
		i++;
	}
	return kq;
}
int main(){
	vector<int> moneys = {2, 10, 5, 50, 20};
	int n = 68;
	sort(moneys.begin(), moneys.end(), greater<int>());
	vector<int> d = changecoin(moneys, n);
	xuat(d);
}