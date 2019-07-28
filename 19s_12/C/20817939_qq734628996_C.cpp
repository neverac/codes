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
const int MAXN = 1e6+9, MAXM = 1e5+9;

pii a[MAXN];
int vis[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int n,m;
    while (scanf("%d%d", &n,&m)==2) {
        REP(i,n)REP(j,m) {
            scanf("%d", &a[i*m+j].fi);
            a[i*m+j].se=i;
        }
        sort(a,a+n*m);
        int ans=INF;
        int i=0,j=0;
        memset(vis,0,sizeof(vis));
        int cnt=0;
        while (j<n*m) {
            if (cnt<n) {
                if (++vis[a[j++].se]==1) cnt++;
            }
            while (cnt==n) {
                ans=min(ans,a[j-1].fi-a[i].fi);
                if (--vis[a[i++].se]==0) cnt--;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}





































