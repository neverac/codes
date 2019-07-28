#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXM 20000+10
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;
struct MAXFLOW
{
    struct Edge{
        int from, to, cap, flow, next;
    };
    Edge edge[MAXM];
    int head[MAXN], edgenum;
    int cur[MAXN];
    void init(){
        edgenum = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v, int w)
    {
        Edge E1 = {u, v, w, 0, head[u]};
        edge[edgenum] = E1;
        head[u] = edgenum++;
        Edge E2 = {v, u, w, 0, head[v]};//注意反向弧 容量为w
        edge[edgenum] = E2;
        head[v] = edgenum++;
    }
    int dist[MAXN]; bool vis[MAXN];
    bool BFS(int s, int t)
    {
        queue<int> Q;
        memset(dist, -1, sizeof(dist));
        memset(vis, false, sizeof(vis));
        dist[s] = 0;
        Q.push(s);
        vis[s] = true;
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for(int i = head[u]; i != -1; i = edge[i].next)
            {
                Edge E = edge[i];
                if(!vis[E.to] && E.cap > E.flow)
                {
                    dist[E.to] = dist[u] + 1;
                    if(E.to == t) return true;
                    vis[E.to] = true;
                    Q.push(E.to);
                }
            }
        }
        return false;
    }
    int DFS(int x, int a, int t)
    {
        if(x == t || a == 0) return a;
        int flow = 0, f;
        for(int &i = cur[x]; i != -1; i = edge[i].next)
        {
            Edge &E = edge[i];
            if(dist[E.to] == dist[x] + 1 && (f = DFS(E.to, min(a, E.cap-E.flow), t)) > 0)
            {
                edge[i].flow += f;
                edge[i^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t)
    {
        int flow = 0;
        while(BFS(s, t))
        {
            memcpy(cur, head, sizeof(head));
            flow += DFS(s, INF, t);
        }
        return flow;
    }
};
MAXFLOW dinic;
 
int k = 1;
int S, T;
int N, M;
void solve()
{
	int W;
    scanf("%d%d",&N,&M);
    scanf("%d%d%d", &S, &T, &W);
    dinic.init();
    while(M--)
    {
        int a, b;
        scanf("%d%d", &a,&b);
        dinic.addEdge(a, b, 1);
    }
    if(W%3==0)
    printf("%d\n", W/3*dinic.Maxflow(S, T));
    else
    printf("%d\n", (W/3+1)*dinic.Maxflow(S, T));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
	{
        solve();
    }
    return 0;
}
