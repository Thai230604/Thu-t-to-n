#include <bits/stdc++.h>

using namespace std;

vector<bool> col (8, 0);
vector<bool> chinh(15, 0);
vector<bool> phu(15, 0);
vector<int> kq;

void xuat(){
	for(int i : kq){
		cout << i << " " ;
	}
	cout << endl;
}

void Try(int i){
	if(i == 8){
		xuat();
	}else{
		for(int j = 0 ; j < 8; j++){
			if(col[j] == 0 && chinh[i + j] == 0 && phu[ i - j + 7] == 0){
				kq.push_back(j);
				col[j] = 1;
				chinh[i + j] = 1;
				phu[i - j + 7] = 1;
				Try(i + 1);
				kq.pop_back();
				col[j] = 0;
				chinh[i + j] = 0;
				phu[i - j + 7] = 0;
			}
		}
	}
}
int main(){
	Try(0);
}