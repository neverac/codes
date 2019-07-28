#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
//#include <bits/stdc++.h>
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
const int MAXN = 1e3+9, MAXM = 1e3+9;

int to[MAXM],f[MAXN],nxt[MAXM],tot;
void init()
{
    tot=0;
    memset(f,-1,sizeof(f));
}
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int linker[MAXN],used[MAXN],uN;
bool dfs(int u)
{
    for (int i=f[u]; ~i; i=nxt[i]) {
        int v=to[i];
        if (!used[v]) {
            used[v]=1;
            if (linker[v]==-1 || dfs(linker[v])) {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int ans=0;
    memset(linker,-1,sizeof(linker));
    FOR(i,1,uN) {
        memset(used,0,sizeof(used));
        if (dfs(i)) ans++;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int m,n,k;
    while (scanf("%d%d%d", &m,&n,&k)==3 && m) {
        init();
        uN=m;
        REP(i,k) {
            int x,y; scanf("%d%d", &x,&y);
            x++; y++;
            add(x,y+m), add(y+m,x);
        }
        printf("%d\n", hungary());
    }

    return 0;
}






































