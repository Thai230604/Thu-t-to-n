#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> caitui(vector<int> &w, vector<int> &v, int m){
	vector<vector<int>> d(w.size() + 1, vector<int>(m + 1, 0));
	vector<int> a = w;
	vector<int> b = v;
	a.insert(a.begin(), 0);
	b.insert(b.begin(), 0);
	for(int i = 1; i <= w.size(); i++){
		for(int j = 1; j <= m ; j++){
			d[i][j] = d[i-1][j];
			if(j >= a[i] && d[i][j] < d[i-1][j- a[i]] + b[i]){
				d[i][j] = d[i-1][j- a[i]] + b[i];
			}
		}
	}
	int j = m;
	int i = w.size();
	vector<pair<int, int>> k;
	while(i >= 1){
		if(j >= a[i] && d[i][j] != d[i-1][j]){
			k.push_back({a[i], b[i]});
			j -= a[i];
		}
		i--;
	}
	reverse(k.begin(), k.end());
	return k;
}
int main(){
	vector<int> w = {12, 16, 2, 18};
	vector<int> v = {23, 45, 25, 100};
	int m = 30;
	vector<pair<int, int>> k = caitui(w, v, m);
	for(auto &it : k){
		cout << it.first << " " << it.second << endl;
	}
}