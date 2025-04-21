#include <iostream>
#include <vector>

using namespace std;

void xuat(vector<int> a) {
    for (int i =  1 ; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> s = {1, 2, 3};
int k = 2;
vector<int> x(1, 0);
int n = s.size();
void Try(int i) {
    if (i == k + 1) { 
        xuat(x);
    } else {
        for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
            x.push_back(j);
            Try(i + 1);
            x.pop_back();
        }
    }
}

int main() {
    Try(1);
    return 0;
}
