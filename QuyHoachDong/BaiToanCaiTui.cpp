#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kq(5, vector<int>(7, 0));
struct Pack{
	int weight;
	int value;
	Pack() : weight(0) , value(0) {}
	Pack(int w, int v) : weight(w) , value(v) {}
};

int steal(vector<Pack> &d){
	for(int i = 1 ; i <= 4 ; i++){
		for(int j = 1; j <= 6 ; j ++){
			kq[i][j] = kq[i - 1][j];
			if(j >= d[i].weight){
				kq[i][j] = max(kq[i][j], kq[i - 1][j - d[i].weight] + d[i].value);
			}
		}
	}
	return kq[4][6];
}
void xuat(){
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0; j < 7 ; j++){
			cout << kq[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	vector<Pack> d(5);
	Pack p1 = Pack(2 , 3);
	Pack p2 = Pack(1 , 3);
	Pack p3 = Pack(4 , 4);
	Pack p4 = Pack(3 , 2);
	d[0] = Pack();
	d[1] = p1;
	d[2] = p2;
	d[3] = p3;
	d[4] = p4;
	cout << steal(d) << endl;
	xuat();
}