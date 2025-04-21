#include <bits/stdc++.h>

using namespace std;

void xuat(vector<int> a){
	for(int i : a){
		cout << i << " ";
	}
	cout << endl;
}
void merge(vector<int> &arr, int l, int m, int r){
	vector<int> x(arr.begin() + l, arr.begin() + m + 1);
	vector<int> y(arr.begin() + m+ 1, arr.begin() + r + 1);
	int i = 0;
	int j = 0;
	int k = l;
	while(i < x.size() && j < y.size()){
		if(x[i] < y[j]){
			arr[k] = x[i];
			i++;
		}else{
			arr[k] = y[j];
			j++;
		}
		k++;
	}
	while( i < x.size()){
		arr[k] = x[i];
		i++;
		k++;
	}
	while( j < y.size()){
		arr[k] = y[j];
		j++;
		k++;
	}
}
void mergesort(vector<int> &arr, int l, int r){
	if( l >= r){
		return;
	}
	int m = (l + r)/2;
	mergesort(arr, l, m);
	mergesort(arr, m + 1, r);
	merge(arr, l, m, r);
}
void mergesort2(vector<int> &arr){
	
}
int main(){
	vector<int> arr = {2,5,1,6,8,4};
	mergesort(arr, 0, arr.size() - 1);
	xuat(arr);
	
}