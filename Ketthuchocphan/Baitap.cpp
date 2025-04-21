#include <bits/stdc++.h>

using namespace std;

int vitri(char t, string p){
	for(int i = p.size() - 1; i>= 0; i--){
		if(t == p[i]) return i;
	}
	return -1;
}
bool boy(string p, string s){
	int v = p.size();
	int i = v - 1;
	int n = s.size();
	while(i < n){
		int k = v - 1;
		while(k > -1 && s[i] == p[k]){
			i--;
			k--;
		}
		if(k < 0){
			return true;
		}else{
			int x = vitri(s[i], p);
			if(x == -1){
				i += v;
			}else{
				i += v - x- 1;
			}
		}
	}
	return false;
}
vector<int> z_algo(string s){
	vector<int> z(s.size());
	int l = 0;
	int r = 0;
	for(int i = 1; i < s.size() ; i++){
		if(i > r){
			l = i;
			r = i;
			while(r < s.size() && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}else if(z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}else{
			l = i;
			while(r < s.size() && s[r - l] == s[r]) r++;
			z[i] = r - l;
			r--;
		}
	}
	return z;
}
int dem(string p, string t){
	int c = 0;
	string s = p + "$" + t;
	vector<int> z = z_algo(s);
	for(int i : z){
		if(i == p.size()){
			c++;
		}
	}
	return c;
}
int main(){
	string p = "232305";
	string t = "Pham Hong Thai 232306";
	cout << boy(p, t) << endl;
	cout << dem(p, t);
}