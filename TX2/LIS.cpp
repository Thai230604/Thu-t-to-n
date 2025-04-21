#include <bits./stdc++.h>

using namespace std;

int demTong(int n){
	vector<int> d(n + 1, 0);
	d[0] = 1;
	for(int i = 1; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			d[j] += d[j - i];
		}
	}
	return d[n];
}
int main(){
	cout << demTong(6);
}