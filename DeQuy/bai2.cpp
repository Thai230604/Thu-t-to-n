#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void dem(vector<vector<int>> a,vector<vector<int>> &d, int ngang, int doc, int& count){
    if(ngang < 0 || doc < 0 || ngang >= a.size() || doc >= a[0].size() || a[ngang][doc] != 5 || d[ngang][doc] == 1 ){
        return ;
    }
    count += 1;
    d[ngang][doc] = 1;
    dem(a,d,ngang + 1, doc, count);
    dem(a,d,ngang - 1, doc, count);
    dem(a,d,ngang, doc + 1, count);
    dem(a,d,ngang, doc - 1, count);
}
int main(){
    vector<vector<int>> a = {{0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5},
                            {0,1,2,3,4,5,5,5,5,5,5,5}};
    vector<vector<int>> d(a.size(), vector<int>( a[0].size(), 0));
    int ngang = a.size();
    int doc = a[0].size();
    int count  = 0;
    for(int i = 0;  i < ngang; i++){
        for(int j = 0; j < doc; j++){
            if(a[i][j] == 5 && d[i][j] == 0){
                dem(a,d, i, j, count);
                break;
            }
        }
    }
    cout << count;
    return 0;
    
}   