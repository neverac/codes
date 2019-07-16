#include <bits/stdc++.h>

using namespace std;
int op[150], n;
int sum[150], dp[150][150];

int DP(int l, int r) {
    if (l == r)return 0;
    if (dp[l][r] != -1)return dp[l][r];
    dp[l][r] = 1 << 29;
    for (int i = l; i < r; i++)
        dp[l][r] = min(DP(l, i) + DP(i + 1, r) + ((sum[i] - sum[l - 1] + 100) % 100) * ((sum[r] - sum[i] + 100) % 100),
                       dp[l][r]);
    return dp[l][r];
}

int main() {
    while (cin >> n) {
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)cin >> op[i];
        sum[1] = op[1];
        for (int i = 2; i <= n; i++)sum[i] = (sum[i - 1] + op[i]) % 100;
        cout << DP(1, n) << endl;
    }
    return 0;
}