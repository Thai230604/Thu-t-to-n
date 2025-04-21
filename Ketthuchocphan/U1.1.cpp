#include <bits/stdc++.h>

using namespace std;

float sum(vector<float> &a, int l, int r){
	if(l == r){
		return a[l];
	}
	int m = (r + l)/2;
	float c = sum(a, l, m);
	float b = sum(a, m + 1, r);
	return c + b;
}
int main(){
	int n = 10;
	vector<float> a = {1.2, 2.5, 2.8, 3.4, 6.7, 8.9, 7.4, 4.9, 6.3, 2.9};
	cout << sum(a, 0, a.size() - 1);
}