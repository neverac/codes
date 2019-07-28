#include<iostream>
#include<queue>

#define N 1005
using namespace std;
struct {
    int to, next, v;
} edge[1000 * 2];
int head[N], cnt = 0, n,n2, m, b, e,  ans = 0, deep[N];
queue<int> que;

inline void add(int x, int y, int z) {
    edge[cnt].to = y, edge[cnt].next = head[x], edge[cnt].v = z, head[x] = cnt++;
}

int DFS(int x, int limit) {
    if (limit == 0 || x == e)return limit;
    int f, flow = 0;
    for (int i = head[x]; ~i; i = edge[i].next) {
        if (deep[edge[i].to] == deep[x] + 1 && (f = DFS(edge[i].to, min(limit, edge[i].v)))) {
            edge[i].v -= f, edge[i ^ 1].v += f, flow += f, limit -= f;
            if (!limit)break;
        }
    }
    return flow;
}

bool BFS() {
    while (!que.empty())que.pop();
    for (int i = 1; i <= n; i++)deep[i] = n;
    deep[b] = 0, que.push(b);
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = head[f]; ~i; i = edge[i].next) {
            if (edge[i].v > 0 && deep[edge[i].to] == n) {
                deep[edge[i].to] = deep[f] + 1, que.push(edge[i].to);
                if (edge[i].to == e)return true;
            }
        }
    }
    return deep[e] != n;
}

int main() {
    while(cin >> n && n){
        cin >> n2 >> m;
        ans=0; b=1; e=n+n2+2; cnt=0;
        for (int i = 1; i <= e; i++)head[i] = -1;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            add(u+2, v+n+2, 1), add(v+n+2, u+2, 0);
        }
        for(int i=1;i<=n;i++) add(1,i+1,1), add(i+1,1,0);
        for(int i=1;i<=n2;i++) add(i+n+1,e,1), add(e,i+n+1,0);
        n=n+n2+2;
        while (BFS())ans += DFS(b, 0x7fffffff);
        cout << ans << endl;
    }
    return 0;
}