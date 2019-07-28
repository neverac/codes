#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000003;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 1e3+9;

struct dinic {
    const static LL inf=0x3f3f3f3f3f3f3f3f;
    struct edge {
        int from,to;
        LL cap,flow;
    };
    int n,m,s,t;
    vector<edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN],cur[MAXN];
    void init(int n) {
        this->n=n;
        edges.clear();
        FOR(i,0,n) G[i].clear();
    }
    void add(int from, int to, LL cap) {
        edges.pb({from,to,cap,0});
        edges.pb({to,from,0,0});
        m=SZ(edges);
        G[from].pb(m-2);
        G[to].pb(m-1);
    }
    bool bfs() {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s); d[s]=0; vis[s]=1;
        while (!Q.empty()) {
            int u=Q.front(); Q.pop();
            REP(i,SZ(G[u])) {
                edge& e=edges[G[u][i]];
                if (!vis[e.to] && e.cap>e.flow) {
                    vis[e.to]=1;
                    d[e.to]=d[u]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    LL dfs(int u, LL a) {
        if (u==t || !a) return a;
        LL flow=0, f;
        for (int& i=cur[u]; i<SZ(G[u]); i++) {
            edge& e=edges[G[u][i]];
            if (d[e.to]==d[u]+1 && (f=dfs(e.to,min(a,e.cap-e.flow)))>0) {
                e.flow+=f;
                edges[G[u][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (!a) break;
            }
        }
        return flow;
    }
    LL maxflow(int s, int t) {
        this->s=s, this->t=t;
        LL flow=0;
        while (bfs()) {
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,inf);
        }
        return flow;
    }
} solve;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        int n,m,s,t,k; scanf("%d%d%d%d%d", &n,&m,&s,&t,&k);
        solve.init(n+1);
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            solve.add(x,y,1);
            solve.add(y,x,1);
        }
        LL ans=solve.maxflow(s,t);
        ans=((LL)ceil(k/3.0))*ans;
        printf("%lld\n", ans);
    }

    return 0;
}






































