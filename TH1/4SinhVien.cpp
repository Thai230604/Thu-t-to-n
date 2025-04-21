#include <iostream>
#include <vector>
#include <string>

using namespace std;
void xuat(vector<string> a){
    for(string i : a){
        cout << i << " ";
    }
    cout << endl;
}
vector<string> l = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
int k = 4;
vector<int> check(l.size(), 0);
vector<string> kq;
int co = 0;
void Try(int i){

    if(i == k){
        xuat(kq);
        co += 1;
    }else{
        for(int j = 0; j < l.size(); j++){
            if(check[j] == 0){
                kq.push_back(l[j]);
                check[j] = 1;
                Try(i + 1);
                check[j] = 0;
                kq.pop_back();
            }
        }
    }
}
int main(){
    Try(0);
    cout << co;
    return 0;
}