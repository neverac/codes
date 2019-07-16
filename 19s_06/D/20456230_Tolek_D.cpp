#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> x >> y >> z >> a >> b >> c;
    if (a < x) {
        cout << "NO";
        return 0;
    } else a -= x;
    if (a + b < y) {
        cout << "NO";
        return 0;
    }
    int n = a + b + c - y;
    if (n < z) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}