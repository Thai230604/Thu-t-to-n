#include <bits/stdc++.h>

using namespace std;
vector<char> g = {'A', 'B', 'C', 'D'};
vector<string> n = {"Tung", "Cuc", "Truc", "Mai"};
int k = 4;
vector<string> kq(4);
vector<bool> d(4,0);
int c = 0;
void xuat(){
	for(int i = 0; i < 4 ; i++){
		cout << kq[i] << " ngoi ghe " << g[i] << endl;
	}
}
Try(int i){
	if(i == k){
		xuat();
		c++;
	}else{
		for(int j = 0; j < g.size(); j++){
			if(d[j] == 0){
				kq[i] = n[j];
				d[j] = 1;
				Try(i + 1);
				d[j] = 0;
			}
		}
	}
}

int main(){
	Try(0);
	cout << c;
	return 0;
}