#include <bits/stdc++.h>

using namespace std;
int a[100];
int F(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	return F(n - 1) + F(n - 2);
}
int F2(int n){
	a[1] = 1;
	a[2] = 1;
	for(int i = 3; i <= n ; i++){
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}
int main(){
	cout << F2(45);
}