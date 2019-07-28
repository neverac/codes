#include <bits/stdc++.h>

#define ll long long
using namespace std;

int num[10];

int main() {
    ios::sync_with_stdio(false);
    int p, q;
    cin >> p >> q;
    for (int i = 0; i < q; i++) {
        p *= 10;
        int n = p / q;
        num[n] = 1;
        p %= q;
    }
    for (int i = 0; i < 10; i++) {
        if (num[i] == 1)
            cout << i;
    }
    cout << endl;
    return 0;
}