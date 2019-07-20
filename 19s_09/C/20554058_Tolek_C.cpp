#include <bits/stdc++.h>

#define MOD  998244353
using namespace std;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int pp = x * 180 / gcd(x, 180);
        int z = (pp / x - pp / 180);
        if (z == 0) {
            cout << -1 << endl;
            continue;
        }
        int k = 2 % z == 0 ? 2 / z : 2 / z + 1;
        cout << k * pp / x << endl;
    }
    return 0;
}