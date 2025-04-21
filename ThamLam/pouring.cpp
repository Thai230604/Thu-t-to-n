#include <bits/stdc++.h>

using namespace std;

int pouring(vector<int> bottles, int n){
	int i = 0;
	int c = 0;
	while(n >= bottles[i] && i < bottles.size()){
		if(n > bottles[i]){
			n = n - bottles[i];
			c++;
		}
		i++;
	}
	return c;
}

int main(){
	vector<int> arr = {8,5,4,3,2};
	sort(arr.begin(), arr.end());
	cout << pouring(arr, 10);
    return 0;
}