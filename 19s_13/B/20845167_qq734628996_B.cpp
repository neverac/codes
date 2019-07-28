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
const int MAXN = 2e5+9, MAXM = 1e5+9;

int n;
pii a[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        n*=2;
        REP(i,n) scanf("%d", &a[i].fi), a[i].se=i;
        sort(a,a+n);
        LL ans=0;
        int i=0, j=0;
        for (int k=0; k<n; k+=2) {
            int x1=a[k].se, x2=a[k+1].se;
            ans+=min(abs(x1-i)+abs(x2-j), abs(x1-j)+abs(x2-i));
            i=x1, j=x2;
        }
        printf("%lld\n", ans);
    }

    return 0;
}




































