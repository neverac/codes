#include <bits/stdc++.h>

using namespace std;
int op[150], num[3];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, ans = 0;
        cin >> n;
        num[0] = num[1] = num[2] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> op[i];
            op[i] %= 3;
            num[op[i]]++;
        }
        ans += num[0];
        ans += min(num[1], num[2]);
        int minn = min(num[1], num[2]);
        num[1] -= minn;
        num[2] -= minn;
        cout << ans + num[1] / 3 + num[2] / 3 << endl;
    }
    return 0;
}