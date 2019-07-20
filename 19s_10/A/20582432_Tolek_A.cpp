#include <bits/stdc++.h>

using namespace std;
int n, m;
char op[1005][1005];
bool vis[1005][1005];
int dp[1005][1005];
const int X[] = {-1, 0, 1, 0}, Y[] = {0, 1, 0, -1};

struct Node {
    int x, y;

    Node(int a, int b) : x(a), y(b) {}
};

queue<Node> que;

int main() {
    ios::sync_with_stdio(false), memset(dp, 127, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> (op[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (op[i][j] == '#') {
                for (int p = 0; p < 4; p++) {
                    int xx = i + X[p], yy = j + Y[p];
                    if (op[xx][yy] == '.' && !vis[xx][yy])vis[xx][yy] = true, dp[xx][yy] = 1, que.push(Node(xx, yy));
                }
            }
        }
    }
    while (!que.empty()) {
        Node s = que.front();
        que.pop(), vis[s.x][s.y] = false;
        for (int i = 0; i < 4; i++) {
            int xx = s.x + X[i], yy = s.y + Y[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m)continue;
            if (op[xx][yy] == '.' && dp[xx][yy] > dp[s.x][s.y] + 1) {
                dp[xx][yy] = dp[s.x][s.y] + 1;
                if (!vis[xx][yy])que.push(Node(xx, yy)), vis[xx][yy] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (op[i][j] == '.')ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}