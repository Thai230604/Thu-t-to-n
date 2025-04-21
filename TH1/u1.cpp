#include<bits/stdc++.h>

using namespace std;
int d;
vector<int> a;
int c = 0;
int f(int n){
	if(n == 1 || n == 2){
		d = 1;
		c ++;
	}else{
		d = f(n - 1) + f(n - 2);
	}
	if(find(a.begin(), a.end(), d) == a.end() || (d == 1 && c <= 2)){
		a.push_back(d);
	}
	return d;
}
void xuat(){
	for(int i : a){
		cout << i << " ";
	}
	cout << endl;
}
int main(){
	cout << f(5) << endl;
	xuat();
}