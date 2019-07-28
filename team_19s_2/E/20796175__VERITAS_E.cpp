#include<bits/stdc++.h>
#include<queue>

#define N 10005
using namespace std;
struct {
    int to, next, v;
} edge[50000 * 2];
int head[N], cnt = 0, n, m, b, e,  ans = 0, deep[N], dis[N];
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

bool BFS() {//用于分层
    while (!que.empty())que.pop();
    for (int i = 1; i <= n; i++)deep[i] = n;//全部初始化为n
    deep[b] = 0, que.push(b);//源点入队，深度为0
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = head[f]; ~i; i = edge[i].next) {
            if (edge[i].v > 0 && deep[edge[i].to] == n) {
                deep[edge[i].to] = deep[f] + 1, que.push(edge[i].to);
                if (edge[i].to == e)return true;//汇点找到，返回true
            }
        }
    }
    return deep[e] != n;
}

int main() {
    int test, rong,u,v;
    cin >> test;
    while(test--){
        cin >> n >> m >> b >> e >> rong;
        ans = 0; cnt=0;
        memset(head,-1,sizeof(head));
        int w=(rong+2)/3;
        for(int i=1;i<=m;i++){
            cin >> u >> v;
            add(u,v,w);
            add(v,u,w);
        }
        while (BFS())ans += DFS(b, 0x7fffffff);
        cout << ans << endl;
    }
    return 0;
}
