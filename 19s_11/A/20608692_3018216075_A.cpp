#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[100010];

int main() {
    ll n, sum = 0;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) {
        ans += (2 * sum - a[i]) * a[i];
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}