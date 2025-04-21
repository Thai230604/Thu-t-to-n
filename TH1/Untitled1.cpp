#include<bits/stdc++.h>

using namespace std;

void search(vector<vector<int>>& a,vector<vector<int>>& d, int i , int j, int root, int& count){
	if(i < 1 || j < 1 || i > a.size() || j > a[0].size() || d[i-1][j-1] == 1 || a[i-1][j-1] != root){
		return;
}
	d[i-1][j-1] = 1;
	count ++;
	search(a,d,i + 1, j , root, count);
	search(a,d,i - 1, j , root , count);
	search(a,d,i, j + 1, root, count);
	search(a,d,i, j  - 1, root, count);
}
int main(){
	int n = 5;
	int m = 5;
	vector<vector<int>> a = 	{{1,2,3,4,4}, {1,2,3,4,4}, {1,2,3,4,4}, {1,2,3,4,4}, {1,2,3,4,4}};
	vector<vector<int>> d(n, vector<int>(m, 0));
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1; j <= n ; j++){
			int count  = 0;
			if(d[i-1][j-1] == 0){
				search(a, d, i, j, a[i-1][j-1], count);
				cout << "Mien lien thong " << a[i-1][j-1] << " co " << count << endl;
			}
		}
	}
	
}