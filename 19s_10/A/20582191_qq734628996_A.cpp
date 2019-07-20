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
const int MAXN = 1e3+9, MAXM = 2e5+9;

int m,n,vis[MAXN][MAXN];
char s[MAXN][MAXN];
const int r[]={0,0,1,-1};
const int c[]={1,-1,0,0};
#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
struct node { int x,y,t; };
int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node> Q;
    REP(i,m)REP(j,n) if (s[i][j]=='#') Q.push({i,j,0}), vis[i][j]=1;
    int ans=0;
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x,y=now.y,t=now.t;
        ans=max(ans,t);
        REP(i,4) {
            int xx=x+r[i], yy=y+c[i];
            if (vld(xx,yy) && !vis[xx][yy]) {
                vis[xx][yy]=1;
                Q.push({xx,yy,t+1});
            }
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>m>>n) {
        REP(i,m) scanf("%s", s[i]);
        cout<<bfs()<<endl;
    }

    return 0;
}





























