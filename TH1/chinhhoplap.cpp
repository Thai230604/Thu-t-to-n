#include <iostream>
#include <vector>
using namespace std;
void xuat(vector<int> a){
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}
vector<int> a = {1,2,3};
int k = 2;
vector<int> x(k, 0);
void Try(int i){
    if(i == k){ 
        xuat(x);
    }else{
        for(int j = 0; j < a.size(); j++){
            x[i] = a[j];
            Try(1+ i);
        }
    }
}
int main(){
    Try(0);
    return 0;
}

