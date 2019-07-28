#include <bits/stdc++.h>

#define inf (1<<29)
using namespace std;
struct Edge {
    int next, to, v;
} edge[100005 << 2];
int head[1005], cnt = 0, n, m, s, t, k, dep[1005], cur[1005];
queue<int> que;

inline void add(int x, int y) {
    edge[cnt].to = y, edge[cnt].next = head[x], edge[cnt].v = 1, head[x] = cnt++;
    edge[cnt].to = x, edge[cnt].next = head[y], edge[cnt].v = 0, head[y] = cnt++;
}

int BFS() {
    while (!que.empty())que.pop();
    for (int i = 1; i <= n; i++)dep[i] = inf, cur[i] = head[i];
    dep[s] = 1, que.push(s);
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        if (f == t)return 1;
        for (int i = head[f]; ~i; i = edge[i].next) {
            if (edge[i].v > 0 && dep[edge[i].to] == inf) {
                dep[edge[i].to] = dep[f] + 1;
                que.push(edge[i].to);
            }
        }
    }
    return 0;
}

int DFS(int x, int limit) {
    if (x == t || limit == 0)return limit;
    int p, flow = 0;
    for (int i = cur[x]; ~i; i = edge[i].next) {
        cur[x] = i;
        if (dep[edge[i].to] == dep[x] + 1 && (p = DFS(edge[i].to, min(limit, edge[i].v)))) {
            edge[i].v -= p, edge[i ^ 1].v += p, limit -= p, flow += p;
            if (limit == 0)break;
        }
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> s >> t >> k;
        cnt = 0, memset(head, -1, sizeof(head));
        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;
            add(x, y), add(y, x);
        }
        int ans = 0;
        while (BFS())ans += DFS(s, inf);
        if (k % 3 == 0)k = k / 3;
        else k = k / 3 + 1;
        cout << ans * k << endl;
    }
    return 0;
}
