#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum(int x){
    if(x < 10){
        return x;
    }
    return x%10 + sum(x/10);
}
int i = 0;

int le(vector<int> a, int i){
    if(i >= a.size()){
        return 0;
    }
    if(a[i]% 2 == 0){
        return le(a, i+1);
    }
    return a[i] + le(a, i+ 1);
}
int main(){
    cout << sum(2664) << endl;
    vector<int> a = {1,2,3,4,5,6,7};
    cout << le(a, 0);
}