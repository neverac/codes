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
const int MAXN = 5e3+9, MAXM = 3e3+9;

int n,a[MAXN],l[MAXN],r[MAXN],d[MAXN][MAXN][2];
int dp(int i, int j, int k)
{
    if (i>=j) return 0;
    int& ans=d[i][j][k];
    if (ans!=INF) return ans;
    if (!k) {
        if (a[j]!=a[i]) ans=min(dp(r[i],j,0),dp(r[i],j,1))+1;
        else ans=min(dp(r[i],j,0)+1,dp(r[i],j,1));
    } else {
        ans=min(dp(i,l[j],0)+(a[i]!=a[j]),dp(i,l[j],1)+1);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        memset(d,INF,sizeof(d));
        FOR(i,1,n) scanf("%d", &a[i]);
        a[0]=a[n+1]=-1;
        FOR(i,1,n) l[i]=a[i]==a[i-1]?l[i-1]:i-1;
        ROF(i,1,n) r[i]=a[i]==a[i+1]?r[i+1]:i+1;
        printf("%d\n", min(dp(1,n,0),dp(1,n,1)));
    }

    return 0;
}
































