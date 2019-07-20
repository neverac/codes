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
const int MAXN = 4e5+9, MAXM = 2e5+9;

int to[MAXN],f[MAXN],nxt[MAXN],tot;
void init(){ tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,vis[MAXN];
pii bfs(int s)
{
    queue<pii> Q;
    Q.push({s,1});
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    pii now;
    while (!Q.empty()) {
        now=Q.front(); Q.pop();
        int u=now.fi, t=now.se;
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i];
            if (!vis[v]) {
                vis[v]=1;
                Q.push({v,t+1});
            }
        }
    }
    return now;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        if (n==1) { puts("First"); continue; }
        init();
        REP(i,n-1) {
            int x,y; scanf("%d%d", &x,&y);
            add(x,y);
            add(y,x);
        }
        pii now=bfs(1);
        now=bfs(now.fi);
        int len=now.se;
        if (len%3==2) puts("Second");
        else puts("First");
    }

    return 0;
}




























