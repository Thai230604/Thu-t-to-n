#include <bits/stdc++.h>

using namespace std;

struct Job{
	string id;
	string start;
	float hour;
	Job( string i, string s, float h){
		id = i;
		start = s;
		hour = h;
	}
};
int c = 0;
void xuat(Job j){
	cout << "Id of Job: " << j.id << endl;
	cout << "Time to start: " << j.start << endl;
	cout << "Time of Job: " << j.hour << endl;
	cout << "----------------------------" << endl;
}
void hien(vector<Job> &kq, vector<string> &l){
	for(int i = 0; i < l.size(); i++){
		cout << l[i] << ": " << kq[i].id << endl;
	}
	cout << "------------------------------" << endl;
}
void A1(vector<Job> &j, int i){
	if(i == -1){
		return;
	}
	xuat(j[i]);
	A1(j, i -1);
}
int A2(vector<Job> &j, int l , int r){
	if(l == r){
		return (j[l].hour <= 0.5) ? 1 : 0;
	}
	int a = A2(j, l, (l + r)/2 );
	int b = A2(j, (l + r)/2 + 1, r);
	return a + b;
}
void A3(int i, int n, vector<Job> &j, vector<string> &l, vector<Job> &kq, vector<bool> &d){
	if(i == n){
		hien(kq, l);
		c++;
	}else{
		for(int x = 0 ; x< j.size(); x ++){
			if(d[x] == 0){
			kq.push_back(j[x]);
			d[x] = 1;
			A3(i + 1, n, j, l, kq, d);
			d[x] = 0;
			kq.pop_back();				
			}
		}
	}
}
int main(){
	int n = 6;
	Job j1 = Job("K01", "2h", 0.5);
	Job j2 = Job("K02", "3h", 0.3);
	Job j3 = Job("K03", "4h", 0.7);
	Job j4 = Job("K04", "1h", 0.8);
	Job j5 = Job("K05", "7h", 0.2);
	Job j6 = Job("K06", "8h", 0.9);
	vector<Job> j = {j1, j2, j3, j4, j5, j6};
	vector<string> l = {"Thai", "Tu", "Tao", "Ty", "Toan", "Tuan"};
	A1(j, j.size() - 1);
	cout << A2(j, 0, j.size() - 1);
	cout << endl;
	vector<Job> kq;
	vector<bool> d(n, 0);
	A3(0, n, j, l, kq, d);
	cout << c;
}