#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;


int main() {
    ll k, a, b;
    ll ans = 0;

    cin >> k >> a >> b;

    if (a >= b - 2) {
        ans = 1 + k;
    } else {
        if (k < a + 1) {
            ans = 1 + k;
        } else {
            k -= a + 1;
            ans = b;
            if (k % 2 == 0)
                ans += (b - a) * k / 2;
            else
                ans += (b - a) * (k - 1) / 2 + 1;
        }

    }

    cout << ans << endl;
    return 0;
}