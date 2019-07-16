#include <bits/stdc++.h>

using namespace std;
int op[1005][1005], dp[1005][1005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> op[i][j], dp[i][j] = 1;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (op[i + 1][j] == op[i][j] + 1 && op[i][j + 1] == op[i][j] + 1 && op[i + 1][j + 1] == op[i][j] + 2) {
                dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}