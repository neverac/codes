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
const int MAXN = 1e5+9, MAXM = 2e5+9;

int n,a[MAXN],b[MAXN];
bool jdg(int* a)
{
    int cnt1=0,cnt2=0;
    REP(i,n-1) {
        cnt1+=(a[i]<a[i+1]);
        cnt2+=(a[i]>a[i+1]);
    }
    return !cnt1||!cnt2;
}
void solve()
{
    if (jdg(a)) {
        puts("Nothing to do here");
        return;
    }
    memcpy(b,a,sizeof(a));
    sort(b,b+n);
    int cnt1=0,cnt2=0;
    REP(i,n) cnt1+=(a[i]!=b[i]);
    if (cnt1==2) {
        puts("Yes");
        int cnt=0;
        REP(i,n) {
            if (a[i]!=b[i]) printf("%d%c", i+1,cnt++?'\n':' ');
        }
        return;
    }
    reverse(b,b+n);
    REP(i,n) cnt2+=(a[i]!=b[i]);
    if (cnt2==2) {
        puts("Yes");
        int cnt=0;
        REP(i,n) {
            if (a[i]!=b[i]) printf("%d%c", i+1,cnt++?'\n':' ');
        }
        return;
    }
    puts("No hope");
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        REP(i,n) scanf("%d", &a[i]);
        solve();
    }

    return 0;
}




























