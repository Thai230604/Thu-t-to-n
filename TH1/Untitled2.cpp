#include <bits/stdc++.h>

using namespace std;
int sum(int n){
	if(n < 10){
		return n;
	}
	return n%10 + sum(n/10);
}
int le(vector<int> a, int i){
	if(i == a.size()) return 0;
	if(a[i] % 2 == 0){
		return le(a, i+1);
	}
	return a[i] + le(a, i+1);
}
int ucln(int a, int b){
	if(a%b == 0){
		return b;
	}
	return ucln(b, a%b);
}
int ucln2(int a, int b){
	while(a%b != 0){
		int temp = a;
		a = b;
		b = temp%a;
	}
	return b;
}
void thap(int n, char a, char b, char c){
	if(n == 1){
		cout << "chuyen 1 dia tu " << a << " sang " << c << endl;
		return;
	}
	thap(n - 1, a , c , b);
	thap(1, a, b, c);
	thap(n - 1, b ,a, c);
}
void thap2(int n, char a, char b, char c){
	vector<char> cot = {a, b, c};
	pair<int , vector<char>> dat = {n, cot};
	vector<pair<int , vector<char>>> q;
	q.push_back(dat);
	while(!q.empty()){
		pair<int , vector<char>> data = q.back();
		q.pop_back();
		if(data.first == 1){
			cout << "chuyen 1 dia tu " << data.second[0] << " sang " << data.second[2] << endl;
			continue;
		}
		vector<char> m1 = {data.second[1], data.second[0], data.second[2]};
		pair<int , vector<char>> m = {data.first - 1, m1 };
		q.push_back(m);
		
		vector<char> n1 = {data.second[0], data.second[1], data.second[2]};
		pair<int , vector<char>> n = {1, n1 };
		q.push_back(n);
		
		vector<char> v1 = {data.second[0], data.second[2], data.second[1]};
		pair<int , vector<char>> v = {data.first - 1, v1 };
		q.push_back(v);
		
	}
	
}
int main(){
//	cout << sum(1263)<< endl;
//	vector<int> a = {1,2,3};
//	cout << le(a, 0) << endl;
//	cout << ucln2(48,18) << endl;
	thap2(3, 'A', 'B', 'C');
	return 0;
}