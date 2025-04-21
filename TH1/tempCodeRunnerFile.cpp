#include <iostream>
#include <vector>

using namespace std;

void xuat(vector<int> a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> s = {1, 2, 3};
int k = 2;
vector<int> x(k, 0);

void Try(int i) {
    if (i == k) {
        xuat(x);
    } else {
        for (int j = x[i - 1] + 1; j <= s.size() - k + i; j++) {
            x[i] = j;
            Try(i + 1);
        }
    }
}

int main() {
    Try(0);
    return 0;
}
