#include <iostream>
#include <vector>
#include <string>

using namespace std;
void xuat(vector<int> a){
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}
vector<int> s = {1,2,3};
int k = 2;
vector<bool> d(s.size(), 0);
vector<int> x(k, 0);
void Try(int i){
    if(i == k){
        xuat(x);
    }else{
        for(int j = 0 ; j < s.size(); j++){
            if(d[j] == 1){
                continue;
            }else{
                x[i] = s[j];
                d[j] = 1;
                Try(i + 1);
                d[j] = 0;
            }
        }
    }
}
int main(){
    Try(0);
    return  0;
}
