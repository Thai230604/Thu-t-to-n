#include <bits/stdc++.h>

using namespace std;

int pow(int a, int n){
	if(n == 1){
		return a;
	}
	if(n % 2 == 0){
		return pow(a, n/2) * pow(a, n/2);
	}else{
		return a * pow(a, n/2) * pow(a, n/2);
	}
}
int s = 0;
int le(vector<int> a, int l, int r){
	if(l >= r){
		if(a[l] % 2 != 0){
			s++;
			return a[l];
		}else{
			return 0;
		}
	}
	int c = le(a, l , (r + l)/2);
	int b = le(a, (r + l)/2+ 1, r);
	return c + b;	
}

int main(){
	cout << pow( 2, 10) << endl;
	vector<int> a = {1,2,3,4,5,6,7,1};
	cout << le(a, 0, a.size() - 1) << endl;
	cout << s;
}