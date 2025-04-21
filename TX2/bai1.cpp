#include <bits/stdc++.h>

using namespace std;

struct Fan{
	string name;
	string color;
	float gia;
	Fan(string a, string b, float c){
		name = a;
		color = b;
		gia = c;
	}
};
bool com(Fan a, Fan b){
	return a.gia < b.gia;
}
pair<int, vector<Fan>> buy(vector<Fan> &d, float p){
	int c = 0;
	vector<Fan> k;
	for(int i = 0; i < d.size(); i++){
		if(d[i].gia <= p){
			p -= d[i].gia;
			c++;
			k.push_back(d[i]);
		}
	}
	return {c, k};
}
void hien(vector<Fan> &a){
	for(Fan i : a){
		cout << "Ten: " << i.name << endl;
		cout << "Mau: " << i.color << endl;
		cout << "Gia: " << i.gia << endl;
		cout << "-----------------------" << endl;
	}
}
int main(){
	Fan f1 = Fan("Honda", "Vang", 120000);
	Fan f2 = Fan("Toyota", "Do", 130000);
	Fan f3 = Fan("Sh", "Den", 350000);
	Fan f4 = Fan("Hynda", "Tim", 100000);
	Fan f5 = Fan("Mescedes", "Cam", 110000);
	vector<Fan> d = {f1, f2, f3, f4, f5};
	sort(d.begin(), d.end(), com);
	float p = 500000;
	auto it  = buy(d, p);
	cout << "So luong quat mua duoc la: " << it.first;
	if(it.first == 0 ){
		cout << "Ko mua duoc vat nao";
	}else{
		hien(it.second);
	}
}
