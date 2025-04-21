#include <bits/stdc++.h>

using namespace std;

string front(string s){
	string a;
	for(char i : s){
		if(i == ' ') break;
		a.push_back(i);
	}
	return a;
}
vector<int> z(string x, string w){
	string s = w + "$" + x;
	int l = 0;
	int r = 0;
	int n = s.size();
	vector<int> k(n, 0);
	for(int i = 0; i < n; i++){
		if(i > r){
			l = i; r = i;
			while(r < n && s[r - l] == s[r]) r++;
			k[i] = r - l;
			r--;
		} else if(k[i - l] < r - i + 1){
			k[i] = k [i - l];
		}else{
			l = i;
			while(r < n && s[r - l] == s[r] ) r++;
			k[i] = r - l;
			r--;
		}
	}
	return k;
}
int duyet(char s, string w){
	for(int i = w.size() - 1; i>= 0; i--){
		if(s == w[i]) return i;
	}
	return -1;
}
void xoa(string &s, string w){
	int n = w.size();
	int i = n - 1;
	while( i < s.size()){
		int k = n - 1;
		while( k > -1 && w[k] == s[i]){
			i--;
			k--;
		}
		if(k < 0){
			s.erase(i+1, w.size());
			i++;
		}else{
			int x = duyet(s[i], w);
			if(x == -1) i+= n;
			else i+= n - x - 1;
		}
	}
}
int coun(string s, string w){
	vector<int> k = z(s, w);
	int c = 0;
	for(int i  : k){
		if(i == w.size()) c++;
	}
	return c;
}
int main(){
	string s = "thai la thai dep zai, thai so 1 the gioi";
	string w = front(s);
	cout << w << endl;
	cout <<  coun(s, w) << endl;
	xoa(s, w);
	cout << s;
}