#include <bits/stdc++.h>
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
const int MAXN = 1e3+9, MAXM = 1e6+9;

int n,sx,sy,tx,ty,vis[MAXN][MAXN];
char s[MAXN][MAXN];
const int r[]={0,0,1,-1};
const int c[]={1,-1,0,0};
inline bool vld(int i, int j){ return 1<=i&&i<=n&&1<=j&&j<=n; }
void dfs(int x, int y, int ind) {
    vis[x][y]=ind;
    REP(i,4) {
        int xx=x+r[i], yy=y+c[i];
        if (vld(xx,yy) && !vis[xx][yy] && s[xx][yy]=='0') {
            dfs(xx,yy,ind);
        }
    }
}
int to[MAXM],dis[MAXM],nxt[MAXM],f[MAXN],tot;
void init() {
    tot=0;
    memset(f,-1,sizeof(f));
}
void add(int u, int v, int w) {
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int d[MAXN];
int dij(int s, int t) {
    memset(d,INF,sizeof(d));
    priority_queue<pii> pq;
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        if (u==t) return d[u];
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i], w=dis[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({-d[v],v});
            }
        }
    }
    return -1;
}
vector<pii> V[MAXN];
inline int sqr(int x){ return x*x; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d%d%d", &n,&sx,&sy,&tx,&ty)==5) {
        FOR(i,1,n) scanf("%s", s[i]+1);
        memset(vis,0,sizeof(vis));
        int cnt=0;
        FOR(i,1,n)FOR(j,1,n) if (!vis[i][j] && s[i][j]=='0') dfs(i,j,++cnt);

        FOR(i,1,cnt) V[i].clear();
        FOR(i,1,n)FOR(j,1,n) if (s[i][j]=='0') V[vis[i][j]].pb({i,j});
        int ma=INF;
        for (auto& i:V[vis[sx][sy]]) {
            for (auto& j:V[vis[tx][ty]]) {
                ma=min(ma,sqr(i.fi-j.fi)+sqr(i.se-j.se));
            }
        }
        printf("%d\n", ma);
    }

    return 0;
}




































