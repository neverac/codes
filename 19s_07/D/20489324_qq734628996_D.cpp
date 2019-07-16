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

char s[MAXN];
int d[MAXN][MAXN];
int dp(int i, int j)
{
    if (i>=j) return 0;
    int& ans=d[i][j];
    if (ans!=INF) return ans;
    while (i<j && s[i]=='0') i++;
    while (i<j && s[j]=='1') j--;
    if (i<j) ans=min(dp(i+1,j),dp(i,j-1))+1;
    else ans=0;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", s+1);
        int n=strlen(s+1);
        memset(d,INF,sizeof(d));
        printf("%d\n", dp(1,n));
    }

    return 0;
}
































