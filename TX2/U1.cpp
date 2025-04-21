#include <bits/stdc++.h>

using namespace std;

int A(char t , string p){
	for(int i = p.size() - 1; i >= 0 ; i--){
		if(t == p[i]) return i;
	}
	return -1;
}
bool boyfer(string t , string p){
	int v = p.size();
	int i = v - 1;
	while(i < t.size()){
		int k = v - 1;
		while(k < t.size() && t[i] == p[k]){
			i--;
			k--;
		}
		if(k < 0){
			return true;
		}else{
			int x = A(t[i] , p);
			if(x == -1){
				i += v;
			}else{
				i += v - x- 1;
			}
		}
	}
	return false;
}
void xuathien(vector<string> &d, string a){
	vector<string> k;
	for(string i : d){
		if(boyfer(i, a)) k.push_back(i);
	}
	for(string i : k){
		cout << i << " ";
	}
	cout << endl;
}
vector<int> z_algo(string s){
	vector<int> z(s.size());
	int n = s.size();
	int l = 0;
	int r = 0;
	for(int i = 1; i < n ; i++){
		if(i > r){
			l = i;
			r = i;
			while(r < n && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}else{
			l = i;
			while(r < n && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}
	}
	return z;
}
int check(string t, string p){
	int c = 0;
	string s = p + "$" + t;
	vector<int> z = z_algo(s);
	for(int i = 0; i < z.size(); i++){
		if(z[i] == p.size()) c++;
	}
	return c;
}
void xaucon(vector<string> &d){
	string p = d[0];
	for(string i : d){
		if(check(i, p) > 0){
			cout << i << " " << check(i, p) << endl;
		}
	}
}
int main(){
	vector<string> d = {"child", "hello child", "child hi", "congtatulation", "child child"};
	xuathien(d, "child");
	xaucon(d);
}