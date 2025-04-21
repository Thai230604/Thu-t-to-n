#include <bits/stdc++.h>

using namespace std;

struct Stock{
	float profit;
	float weight;
	float o;
	Stock( float p, float w){
		profit = p;
		weight = w;
		o = profit / weight;
	}
};
void xuat(Stock s){
	cout << "Loi nhuan: " << s.profit << endl;
	cout << "Can nang: " << s.weight << endl;
	cout << "Ty le: " << s.o << endl;
    cout << "------------------------" << endl;
}
void xuat1(vector<Stock> s){
	for(Stock &i : s){
		xuat(i);
	}
}
bool compare(Stock &a, Stock &b){
	return a.o > b.o;
}
float maxProfit(vector<Stock>& s, float k){
	float max_pro = 0;
	for(int i = 0; i < s.size(); i++){
		if(k >= s[i].weight){
			k = k - s[i].weight;
			max_pro += s[i].profit;
		}
	}
	return max_pro;
}
int main(){
	Stock s1 = Stock( 10, 2);
	Stock s2 = Stock( 5, 3);
	Stock s3 = Stock( 15, 5);
	Stock s4 = Stock( 7, 7);
	Stock s5 = Stock( 6, 1);
	Stock s6 = Stock( 18, 4);
	Stock s7 = Stock( 3, 1);
	vector<Stock> s = {s1, s2, s3, s4, s5, s6, s7};
	sort(s.begin(), s.end(), compare);
	xuat1(s);
	cout << maxProfit(s, 15);
	return 0;
}