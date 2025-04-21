#include <bits/stdc++.h>

using namespace std;

bool check(string s){
	int l = 0;
	int r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}
int main(){
	string s = "memeomem";
	cout << check(s);
}