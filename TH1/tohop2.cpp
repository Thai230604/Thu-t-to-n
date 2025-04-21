#include <iostream>
#include <vector>

using namespace std;

void xuat(vector<int> a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> a = {1,2,3,4,5,6,7,8};
vector<int> x;
int k = 3;
int c = 0;
void Try(int i, int start) {
    if (i == k) {
        xuat(x);
        c++;
        return;
    }
    for (int j = start; j < a.size(); j++) {
        x.push_back(a[j]);
        Try(i + 1, j + 1);
        x.pop_back();
    }
}

int main() {
    Try(0, 0);
    cout << c;
    return 0;
}
