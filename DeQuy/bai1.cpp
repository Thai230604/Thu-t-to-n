#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> vec;
int d;
int check = 0;
int fibonaci(int n){
    if(n == 1 || n == 2){
        d =  1;
        check += 1;
    }else{
        d = fibonaci(n - 1) + fibonaci(n - 2);
    }
    
    if(find(vec.begin(), vec.end(), d) == vec.end() || (d == 1 && check <= 2) ){
        vec.push_back(d);
    }
    return d;
}
void xuat(vector<int> a){
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;
}
int sum(vector<int> a){
    int s  = 0;
    for(int i : a){
        s += i;
    }
    return s;
}
int main(){
    cout << fibonaci(6) << endl;
    xuat(vec);
    cout << sum(vec);
}