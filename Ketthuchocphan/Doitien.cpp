#include <bits/stdc++.h>

using namespace std;

vector<int> change(vector<int> &c, int m){
	vector<int> d(m + 1, INT_MAX);
	vector<int> p(m + 1, -1);
	d[0] = 0;
	for(int i = 1; i <= m ; i++){
		for(int j = 0; j < c.size(); j++){
			if(c[j] <= i && d[i] > d[i - c[j]] + 1){
				d[i] = d[i - c[j]] + 1;
				p[i] = j;
			}
		}
	}
	vector<int> k(c.size(), 0);
	int j = m;
	while(j != 0){
		k[p[j]] += 1;
		j -= c[p[j]];
	}
	return k;
}
int main(){
	vector<int> coin = {1, 2, 5};
	int m = 11;
	vector<int> k =  change(coin, m);
	for(int i : k) {
		cout <<  i << " ";
	}
}