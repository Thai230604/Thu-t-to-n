#include <bits/stdc++.h>

using namespace std;

int duyet(char t, string p){
	for(int  i = p.size() - 1; i >= 0; i--){
		if(p[i] == t) return i;
	}
	return -1;
}
int position(string t, string p){
	int n = p.size();
	int i = n -1;
	while(i < t.size()){
		int k = n -1;
		while( k > -1 && t[i] == p[k]){
			i--;
			k--;
		}
		if( k < 0){
			return i + 1;
		}else{
			int x = duyet(t[i], p);
			if(x == -1){
				i += n;
			}else{
				i += n - x - 1;
			}
		}
		
	}
	return -1;
}
string thay(string q, string t, string p){
	int n = p.size();
	int i = n -1;
	int m = t.size() + q.size()  - p.size();
	while(i < t.size()){
		int k = n -1;
		while( k > -1 && t[i] == p[k]){
			i--;
			k--;
		}
		if( k < 0){
			t.replace(i + 1, p.size(), q);
			i+= q.size() - 1;
		}else{
			int x = duyet(t[i], p);
			if(x == -1){
				i += n;
			}else{
				i += n - x - 1;
			}
		}
		
	}
	return t;
}
int main(){
	string t = "2eu8e10008wue89";
	string p = "1000";
	string q = "mot nghin dong";
	cout << position(t, p) << endl;
	cout << thay(q, t, p);
}