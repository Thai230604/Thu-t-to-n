#include <bits/stdc++.h>

using namespace std;
void xuat(vector<int> kq){
	for(int i : kq){
		cout << i << " ";
	}
}
vector<int> sotien(vector<int> moneys, int n){
	vector<int> kq(moneys.size(), 0);
	int i = 0;
	while( n != 0 && i < moneys.size()){
		kq[i] = n/moneys[i];
		n = n - data*moneys[i];
		i++;
	}
	return kq;
}
int main(){
	int n;
	cin>> n;
	vector<int> money = {1,5,10,25,100};
	sort(money.begin(), money.end(), greater<int>());
	vector<int> k = sotien(money, n);
	xuat(k);
	return 0;
	
}