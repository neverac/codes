#include <bits/stdc++.h>

using namespace std;
int op[1005], n, m;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1, x, y; i <= n; i++) {
            cin >> x >> y;
            op[i] = x + y;
        }
        sort(op + 1, op + n + 1);
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            if (1ll * ans * op[i] > m) {
                cout << i - 1 << endl;
                goto to;
            } else ans *= op[i];
        }
        cout << n << endl;
        to:;
    }
    return 0;
}