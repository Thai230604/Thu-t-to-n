#include <bits/stdc++.h>

using namespace std;
int dem(int n){
	vector<int> k(n + 1, 0);
	k[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			k[j] = k[j] + k[j - i];
		}
	}
	return k[n];
}
int main(){
	int n = 4;
	cout << dem(n);
}