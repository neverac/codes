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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 2e3+9, MAXM = 2e5+9;

int from[MAXN],to[MAXN],f[MAXN],nxt[MAXN],tot;
void init(){ tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v)
{
    from[tot]=u;
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,s,t,d1[MAXN],d2[MAXN],vis[MAXN][MAXN];
int dij(int s, int t, int* d)
{
    FOR(i,1,n) d[i]=INF;
    priority_queue<pii> pq;
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i];
            if (d[v]>d[u]+1) {
                d[v]=d[u]+1;
                pq.push({-d[v],v});
            }
        }
    }
    return d[t];
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d%d", &n,&m,&s,&t)==4) {
        memset(vis,0,sizeof(vis));
        init();
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            add(x,y);
            add(y,x);
        }
        int mi=dij(s,t,d1);
        dij(t,s,d2);
        int cnt=0;
        for (int i=0; i<tot; i+=2) {
            int u=from[i], v=to[i];
            vis[u][v]=vis[v][u]=1;
        }
        FOR(i,1,n)FOR(j,i+1,n) if (!vis[i][j]) {
            if (d1[i]+1+d2[j]<mi || d1[j]+1+d2[i]<mi) continue;
            else cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}





























