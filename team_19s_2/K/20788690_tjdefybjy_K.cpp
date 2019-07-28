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
const int MAXN = 1e2+9, MAXM = 1e3+9;

int to[MAXN],nxt[MAXN],f[MAXN],tot;
void init(){ tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,vis[MAXN];
bool check(int u)
{
    for (int i=f[u]; ~i; i=nxt[i]) {
        int v=to[i];
        if (vis[v]==vis[u]) return false;
    }
    return true;
}
bool dfs(int i)
{
    if (i==n) return true;
    REP(j,3) {
        vis[i]=j;
        if (check(i) && dfs(i+1)) return true;
    }
    vis[i]=-1;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);
        init();
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            add(x,y);
            add(y,x);
        }
        memset(vis,-1,sizeof(vis));
        puts(dfs(0)?"Y":"N");
    }

    return 0;
}




































