#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int next, to;
} edge[2005];
queue<int> que;
int vis[1005][1005], op[1005][1005], head[1005], n, m, s, t, s1[1005], s2[1005];

inline void add(int x, int y) {
    static int cnt = 1;
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

int main() {
    memset(s1, -1, sizeof(s1)), memset(s2, -1, sizeof(s2));
    cin >> n >> m >> s >> t;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        op[x][y] = op[y][x] = 1;
        add(x, y), add(y, x);
    }
    que.push(s), s1[s] = 0;
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = head[f]; i; i = edge[i].next) {
            if (s1[edge[i].to] == -1) {
                s1[edge[i].to] = s1[f] + 1;
                que.push(edge[i].to);
            }
        }
    }
    que.push(t), s2[t] = 0;
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = head[f]; i; i = edge[i].next) {
            if (s2[edge[i].to] == -1) {
                s2[edge[i].to] = s2[f] + 1;
                que.push(edge[i].to);
            }
        }
    }
    int ans = 0, minn = s1[t];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (op[i][j])continue;
            if (s1[i] + 1 + s2[j] < minn || s1[j] + s2[i] + 1 < minn)continue;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}