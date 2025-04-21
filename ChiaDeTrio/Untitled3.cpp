#include <bits/stdc++.h>

using namespace std;

struct Truck{
	int bienso;
	int taitrong;
	Truck(int b, int t){
		bienso = b;
		taitrong = t; 
	}
};
Truck lonnhat(vector<Truck> d, int l, int r){
	if(l >= r){
		return d[l];
	}
	Truck a = lonnhat(d, l, (r+l)/2);
	Truck b = lonnhat(d, (r+l)/2 + 1, r);
	if(a.taitrong >= b.taitrong){
		return a;
	}else{
		return b;
	}
}
void merge(vector<Truck>& d, int l, int m, int r){
	vector<Truck> x(d.begin() + l, d.begin() + m + 1);
	vector<Truck> y(d.begin() + m + 1, d.begin() + r + 1);
	int i = 0;
	int j = 0;
	int k = l;
	while( i < x.size() && j < y.size()){
		if(x[i].taitrong < y[j].taitrong){
			d[k] = x[i];
			i++;
		}else{
			d[k] = y[j];
			j++;
		}
		k++;
	}
	while( i < x.size()){
		d[k] = x[i];
		i++;
		k++;
	}
	while( j < y.size()){
		d[k] = y[j];
		j++;
		k++;
	}
}
void mergesort(vector<Truck>& d, int l, int r){
	if(l >= r){
		return ;
	}
	int m = (l+r)/2;
	mergesort(d, l , m);
	mergesort(d, m + 1, r);
	merge(d, l, m, r);
}
void xuat(vector<Truck> a){
	for(Truck i : a){
		cout << i.bienso << " " << i.taitrong << " " << endl;
	}
}
void chen(vector<Truck>& d, int l, int r, Truck z){
	if(l >= r){
		return;
	}
	int m = (l + r)/2;
	if(z.taitrong >= d[d.size() - 1].taitrong){
		d.push_back(z);
		return;
	}
 	if (z.taitrong <= d[m].taitrong && (m == 0 || z.taitrong >= d[m - 1].taitrong)) {
        d.insert(d.begin() + m, z);
        return;
    }

	if(z.taitrong < d[m].taitrong){
		chen(d, l, m, z);
	}else{
		chen(d, m + 1, r , z);
	}
}
int main(){
	Truck t1 = Truck(100, 200);
	Truck t2 = Truck(200, 300);
	Truck t3 = Truck(400, 500);
	Truck t4 = Truck(100, 400);
	Truck t5 = Truck(600, 700);
	Truck t6 = Truck(400, 800);
	Truck t7 = Truck(100, 200);
	vector<Truck> l = {t1, t2, t3, t4, t5, t6, t7};
	Truck k = lonnhat(l, 0, l.size() - 1);
	cout << k.bienso << " " << k.taitrong << endl;
	cout << "--------------------------------------"<< endl;
	mergesort(l, 0, l.size() - 1);
	xuat(l);
	cout << "--------------------------------------"<< endl;
	Truck z = Truck(100, 900);
	chen(l, 0, l.size() - 1, z);
	xuat(l);
	
	
}