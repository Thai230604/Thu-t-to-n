#include <bits/stdc++.h>

using namespace std;

void change(vector<int> &c, int m){
	int n = c.size();
	vector<int> dq(m + 1, INT_MAX);
	vector<int> unde(m + 1, -1);
	vector<int> k(n);
	dq[0] = 0;
	for(int i = 1; i <= m ; i++){
		for(int j = 0; j < n ; j++){
			if(c[j] <= i && dq[i] > dq[i - c[j]] + 1 ){
				dq[i] = dq[i - c[j]] + 1;
				unde[i] = j;
			}
		}
	}
	
	while(m > 0){
		int ind = unde[m];
		k[ind]++;
		m -= c[ind];
	}
	for(int i : k){
		cout << i << " ";
	}
}
int main(){
	vector<int> coins = {1,2,5};
	int m = 11;
	change(coins, m);
}