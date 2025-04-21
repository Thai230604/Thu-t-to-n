#include <bits/stdc++.h>

using namespace std;

void pintLis(vector<int> &arr){
	vector<int> dp(arr.size(), 1);
	vector<int> parent(arr.size(), -1);

	for(int i = 1; i < arr.size(); i++){
		for(int j = 0 ; j < i; j++){
			if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
	}
	auto it = max_element(dp.begin(), dp.end());
	int end = distance(dp.begin(), it);
	vector<int> k ;
	while(end != -1){
		k.push_back(arr[end]);
		end = parent[end];
	}
	reverse(k.begin(), k.end());
	for(int i  : k){
		cout << i << " ";
	}
}
int main(){
	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	pintLis(arr);
}