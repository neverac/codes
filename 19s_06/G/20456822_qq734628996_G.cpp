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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e2+9, MAXM = 3e3+9;

int n,a[MAXN],S[MAXN];
LL d[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        FOR(i,1,n) scanf("%d", &a[i]);
        FOR(i,1,n) S[i]=S[i-1]+a[i];
        FOR(len,1,n)FOR(i,1,n-len) {
            int j=i+len;
            d[i][j]=INF;
            FOR(k,i,j-1) d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+((S[k]-S[i-1])%100)*((S[j]-S[k])%100));
        }
        printf("%lld\n", d[1][n]);
    }

    return 0;
}

































