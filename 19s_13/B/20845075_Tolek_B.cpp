#include <bits/stdc++.h>

#define N 100005
using namespace std;
int op[N][2], n;
long long dp[N][2];//xiaoda or daxiao
long long DP(int x, int y) {
    if (dp[x][y] != -1)return dp[x][y];
    if (x == 1) return dp[x][y] = op[1][0] + op[1][1] - 2;
    if (y == 0) {
        return dp[x][y] = min(DP(x - 1, 0) + abs(op[x][0] - op[x - 1][0]) + abs(op[x][1] - op[x - 1][1]),
                              DP(x - 1, 1) + abs(op[x][0] - op[x - 1][1]) + abs(op[x][1] - op[x - 1][0])
        );
    } else {
        return dp[x][y] = min(DP(x - 1, 0) + abs(op[x][1] - op[x - 1][0]) + abs(op[x][0] - op[x - 1][1]),
                              DP(x - 1, 1) + abs(op[x][1] - op[x - 1][1]) + abs(op[x][0] - op[x - 1][0]));
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, x; i <= 2 * n; i++) {
        cin >> x;
        if (op[x][0] == 0)op[x][0] = i;
        else op[x][1] = i;
    }
    cout << min(DP(n, 0), DP(n, 1));
    return 0;
}