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
const int MAXN = 2e5+9, MAXM = 2e5+9;

int n;
char s[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%s", &n,s)==2) {
        int l=1, r=n-2;
        while (s[l]==s[l-1]) l++;
        while (s[r]==s[r+1]) r--;
        LL ans;
        if (s[0]!=s[n-1]) {
            ans=1+l+n-1-r;
        } else {
            if (n==2) ans=3;
            else ans=(LL)(l+1)*(n-r);
        }
        printf("%lld\n", ans%MOD);
    }

    return 0;
}






























