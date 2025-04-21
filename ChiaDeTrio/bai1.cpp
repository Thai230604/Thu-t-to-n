#include <bits/stdc++.h>

using namespace std;


void xuat(vector<int> a){
	for(int i : a){
		cout <<  i << " ";
	}
	cout << endl;
}
void merge(vector<int> &a, int l, int mid, int r){
	vector<int> x (a.begin() + l, a.begin() + mid + 1);
	vector<int> y (a.begin() + mid + 1, a.begin() + r + 1);
	int i = 0;
	int j = 0;
	int k = l;
	while(i < x.size()  && j < y.size()){
		if(x[i] <= y[j]){
			a[k] = x[i];
			i++;
		}else{
			a[k] = y[j];
			j++;
		}
		k++;
	}
	while(i < x.size()){
		a[k] = x[i];
		i++;
		k++;
	}
	while(j < y.size()){
		a[k] = y[j];
		j++;
		k++;
	}	
}
void mergesort(vector<int>& a, int l, int r){
	if(l >= r){
		return;
	}
	int mid = (l + r)/2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	merge(a,l,mid , r);
}
int main(){
	vector<int> a = {38, 27, 43, 3, 9, 82, 10};
	mergesort(a, 0, a.size() - 1);
	xuat(a);
	return 0;
}