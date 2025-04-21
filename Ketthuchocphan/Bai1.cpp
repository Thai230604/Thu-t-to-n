#include <bits/stdc++.h>

using namespace std;

struct Lop{
	string id;
	int num;
	int girl;
	Lop(string i, int n, int g){
		id = i;
		num = n;
		girl = g;
	}
};
int lay(vector<Lop> &l, int n){
	int c = 0;
	int m = 0;
	for(Lop &i : l){
		m += i.num;
		c++;
		if(m > n){
			break;
		}
	}
	return c;
}
vector<Lop> ghep(vector<Lop> &d, int h){
	vector<vector<int>> k(d.size() + 1, vector<int>(h + 1, 0));
	vector<Lop> a = d;
	a.insert(a.begin(), Lop(" ", 0, 0));
	for(int i = 1; i <= d.size(); i++){
		for(int j = 1; j <= h ; j++){
			k[i][j] = k[i - 1][j];
			if(j >= a[i].num && k[i][j] < k[i - 1][j - a[i].num] + a[i].girl){
				k[i][j] = k[i - 1][j - a[i].num] + a[i].girl;
			}
		}
	}
	int i = d.size();
	int j = h;
	vector<Lop> l;
	while(i > 0){
		if(j >= a[i].num && k[i][j] != k[i - 1][j]){
			l.push_back(a[i]);
			j -= a[i].num;
		}
		i--;
	}
	return l;
}
int vi(char t, string p){
	for(int i = p.size() - 1; i >= 0; i--){
		if(t == p[i]) return i;
	}
	return -1;
}
bool boy(string p, string t){
	int v = p.size();
	int i = v - 1;
	while(i < t.size()){
		int k = v - 1;
		while(k > -1 && t[i] == p[k]){
			i--;
			k--;
		}
		if(k < 0){
			return true;
		}else{
			int x = vi(t[i], p);
			if(x == -1){
				i += v;
			}else{
				i+= v - x -1;
			}
		}
	}
	return false;
}
bool chen(vector<Lop> &d, Lop &a, int l, int r){
	if(l > r){
		return false;
	}
	int m = (l + r)/2;
	if(d[m].id.compare(a.id) <= 0 && d[m+1].id.compare(a.id) > 0){
		return true;
	}
	if(d[m].id.compare(a.id)){
		return chen(d, a, l , m);
	}else{
		return chen(d, a, m + 1 , r);
	}
}
int main(){
	int n = 5;
	Lop l1 = Lop("AT01", 30, 15);
	Lop l2 = Lop("C02", 23, 15);
	Lop l3 = Lop("DT03", 20, 8);
	Lop l4 = Lop("H04", 15, 5);
	Lop l5 = Lop("K05", 7, 15);
	vector<Lop> d = {l1, l2, l3, l4, l5};
	Lop l6 = Lop("B01", 23, 12);
	cout << chen(d, l6, 0, d.size() - 1);
//	cout << lay(d, 52)<< endl;
//	vector<Lop> l = ghep(d, 30);
//	for(Lop &i : l){
//		cout << i.id << " ";
//	}
//	cout << endl;
//	for(Lop &i : d){
//		if(boy("IT", i.id)){
//			cout << i.id << " ";
//		}
//	}
}