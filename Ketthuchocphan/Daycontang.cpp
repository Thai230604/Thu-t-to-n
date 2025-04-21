#include <bits/stdc++.h>

using namespace std;

vector<int> day(vector<int> &a){
	vector<int> d(a.size(), 1);
	vector<int> p(a.size(), -1);
	for(int i = 1; i < a.size(); i++){
		for(int j = 0; j < i ; j++){
			if(a[j] < a[i] && d[i] < d[j] + 1){
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}
	auto it = max_element(d.begin(), d.end());
	int v = distance(d.begin(), it);
	vector<int> k;
	while(v != -1){
		k.push_back(a[v]);
		v = p[v];
	}
	reverse(k.begin(), k.end());
	return k;
}
int main(){
	vector<int> a = {2, 5, 6, 4, 7, 3, 8};
	vector<int> k = day(a);
	for(int i : k){
		cout << i << " ";
	}
}