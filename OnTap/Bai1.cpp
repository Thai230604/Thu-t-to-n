#include <bits/stdc++.h>

using namespace std;

struct Flight{
	string id;
	float price;
	int seat;
	Flight(string i, float p, int s){
		id = i;
		price = p;
		seat = s;
	}
};
vector<Flight> kq;
int c = 0;
void xuat(Flight f){
	cout << "Ma id: " << f.id << endl;
	cout << "Price: "  << f.price << endl;
	cout << "Seat: " << f.seat << endl;
	cout  << "--------------------" << endl;
}
void hien(){
	for(Flight i : kq){
		xuat(i);
	}
	cout << endl;
}
void search(vector<Flight> f, int i){
	if(i == f.size()){
		return;
	}
	if(f[i].price >= 700000){
		xuat(f[i]);
	}
	search(f, i + 1);
}
Flight timMin(vector<Flight> f, int l, int r){
	if(l >= r){
		return f[l];
	}
	int m = (l + r)/2;
	Flight a = timMin(f, l, m);
	Flight b = timMin(f, m + 1, r);
	return (a.price < b.price) ? a: b;
}
void Try(int i, int k, int start, vector<Flight> &f){
	if(i == k){
		hien();
		c++;
	}else{
		for(int j = start; j < f.size(); j ++){
			kq.push_back(f[j]);
			Try(i + 1, k, j + 1, f);
			kq.pop_back();		
		}
	}
}
int main(){
	int n = 7;
	Flight f1 = Flight("VN01", 200000, 12);
	Flight f2 = Flight("VN01", 300000, 12);
	Flight f3 = Flight("VN01", 500000, 12);
	Flight f4 = Flight("VN01", 150000, 12);
	Flight f5 = Flight("VN01", 700000, 12);
	Flight f6 = Flight("VN01", 800000, 12);
	Flight f7 = Flight("VN01", 900000, 12);
	vector<Flight> f = {f1, f2, f3, f4, f5, f6 ,f7};
	search(f, 0);
	cout << "Flight is lowest price: " << endl;
	xuat(timMin(f, 0, f.size() - 1));
	cout << "How to chose 4 in 7" << endl;
	Try(0, 4, 0, f);
	cout << c;
}