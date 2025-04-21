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
vector<int> a = {0, 1};
int k = 3;
vector<int> x;
void Try(int i){
    if(i == k){
        xuat(x);
    }else{
        for(int j = 0; j < a.size(); j++){
            x.push_back(a[j]);
            Try(i + 1);
            x.pop_back();
        }
    }
}
int main(){
    Try(0);
    return 0;
}

