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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 2e5+9;

int m,g[MAXN][MAXN],r[MAXN][MAXN];

int n,a[MAXN],d[MAXN][20];
void RMQ_init()
{
    REP(i,n) d[i][0] = a[i];
    for (int j = 1; (1<<j) < n; j++) {
        for (int i = 0; i+(1<<j)-1 < n; i++) {
            d[i][j] = min(d[i][j-1], d[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int L, int R)
{
    int k = 0;
    while ((1<<(k+1)) <= R-L+1) k++;
    return min(d[L][k], d[R-(1<<k)+1][k]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &m)==1) {
        FOR(i,1,m)FOR(j,1,m) scanf("%d", &g[i][j]);
        FOR(i,1,m) {
            r[i][m]=1;
            ROF(j,1,m-1) r[i][j]=g[i][j]==g[i][j+1]-1?r[i][j+1]+1:1;
        }
        int ans=1;
        FOR(j,1,m) {
            FOR(i,1,m) a[i-1]=r[i][j];
            n=m;
            RMQ_init();
            REP(i,m) {
                if (i-a[i]+1>=0) ans=max(ans,min(a[i],RMQ(i-a[i]+1,i)));
                else ans=max(ans,min(i+1,RMQ(0,i)));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
































