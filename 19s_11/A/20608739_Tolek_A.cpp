#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        s += x;
    }
    cout << s * s;
    return 0;
}