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
const int MAXN = 2e5+9, MAXM = 3e3+9;

int n,m,k,a[MAXN],r[MAXN],vis[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&m,&k)==3) {
        REP(i,n) scanf("%d", &a[i]), r[i]=i;
        sort(r,r+n,[](const int i, const int j){
             return a[i]>a[j];
        });
        memset(vis,0,sizeof(vis));
        LL ans=0;
        REP(i,m*k) ans+=a[r[i]], vis[r[i]]=1;
        printf("%lld\n", ans);
        int cnt=0;
        REP(i,n) {
            if (vis[i]) cnt++;
            if (cnt==m) {
                cnt=0;
                printf("%d", i+1);
                if (--k>1) printf(" ");
                else {
                    puts("");
                    break;
                }
            }
        }
    }

    return 0;
}

































