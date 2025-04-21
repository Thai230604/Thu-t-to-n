#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> c = {'a', 'b'}; 
int k = 2;
string s = "";

void Try(int i){
    if(i == k){
        cout << s << endl;
    }else{
        for(char j : c){
            s.push_back(j);
            Try(i + 1);
            s.pop_back();
        }
    }
}






int main(){
    Try(0);
    return 0;
}