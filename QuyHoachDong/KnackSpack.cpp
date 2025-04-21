#include <bits/stdc++.h>

using namespace std;

int gia(vector<int> &w, vector<int> &v, int m){
	int n = w.size();
	vector<vector<int>> d (n + 1, vector<int>(m + 1, 0));
	w.insert(w.begin(), 0);
	v.insert(v.begin(), 0);
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			d[i][j] = d[i - 1][j];
			if(w[i] <= j){
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	return d[n][m];
}
int main(){
	vector<int> w = {10, 20, 30};
	vector<int> v = {60, 100, 120};
	int m = 50 ;
	cout << gia(w, v, m);
}