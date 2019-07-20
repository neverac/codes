#include <bits/stdc++.h>

using namespace std;
long long k, a, b;

int main() {
    cin >> k >> a >> b;
    if (a >= b)cout << k + 1;
    else {
        if (k + 1 <= a)cout << k + 1;
        else {
            if (b - a <= 2)cout << k + 1;
            else {
                cout << (k - (a - 1)) / 2 * (b - a) + a + ((k - a + 1) % 2);
            }
        }
    }
    return 0;
}