#include <bits/stdc++.h>

using namespace std;

vector<int> a = {-2,-2,-1,-1,1,1,2,2};
vector<int> b = {-1,1,-2,2,-2,2,-1,1};
void xuat(vector<vector<int>> d){
	for(int i = 0; i < d.size(); i++){
		for(int j = 0; j < d[0].size(); j++){
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}
void Try(int count , int n, int x, int y, vector<vector<int>>& d){
	if(count == n*n){
		xuat(d);
		exit(0);
	}else{
		for(int i = 0 ; i < a.size(); i++){
			if(!(x < 0 || y < 0 || x >=  d.size() || y >= d[0].size() || d[x][y] != 0)){
				count++;
			    d[x][y] = count;
			    int u = x + a[i];
				int v = y + b[i];
				Try(count, n , u,v,d);
				count--;
	        	d[x][y] = 0;
			}
		
	}
	
}

}
int main(){
	int n = 5;
	vector<vector<int>> d(n, vector<int>(n));
	Try(0, n, 0, 0, d);
	
	
}