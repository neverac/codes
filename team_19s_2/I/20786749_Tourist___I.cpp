#include <bits/stdc++.h>

using namespace std;
struct Edge {
    int next, to;
} edge[500];
int head[50], cnt = 1, m, n, e, vis[50], be[50], sb;

inline void add(int x, int y) {
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

int f(int x) {
    for (int i = head[x]; i; i = edge[i].next) {
        if (vis[edge[i].to] != sb) {
            vis[edge[i].to] = sb;
            if (be[edge[i].to] == -1 || f(be[edge[i].to])) {
                be[edge[i].to] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    while (cin >> m) {
        if (m == 0)return 0;
        cin >> n >> e;
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(be, -1, sizeof(be)), cnt = 1;
        for (int i = 1, x, y; i <= e; i++) {
            cin >> x >> y;
            add(x, y);
        }
        int ans = 0;
        sb = 1;
        for (int i = 0; i < m; i++) {
            if (f(i))++ans;
            ++sb;
        }
        cout << ans << endl;
    }
}
