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
const int MAXN = 1e5+9, MAXM = 2e5+9;

int len;
char s[MAXN];
bool jdg()
{
    if (s[0]=='+' || s[0]=='*') return false;
    if (s[len-1]=='+' || s[len-1]=='*') return false;
    REP(i,len-1) if ((s[i]=='+' || s[i]=='*') && (s[i+1]=='+' || s[i+1]=='*')) return false;
    REP(i,len) if ((s[i]=='0' && (!i || s[i-1]=='+' || s[i-1]=='*'))) {
        if (i+1<len) {
            if (s[i+1]=='?') s[i+1]='+';
            else if (isdigit(s[i+1])) return false;
        }
    }
    REP(i,len) if (s[i]=='?') s[i]='1';
    if (s[0]=='+' || s[0]=='*') return false;
    if (s[len-1]=='+' || s[len-1]=='*') return false;
    REP(i,len-1) if ((s[i]=='+' || s[i]=='*') && (s[i+1]=='+' || s[i+1]=='*')) return false;
    REP(i,len) if ((s[i]=='0' && (!i || s[i-1]=='+' || s[i-1]=='*'))) {
        if (i+1<len) {
            if (s[i+1]=='?') s[i+1]='+';
            else if (isdigit(s[i+1])) return false;
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        len=strlen(s);
        if (jdg()) puts(s);
        else puts("IMPOSSIBLE");
    }

    return 0;
}



























