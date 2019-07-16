#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <queue>
#include <algorithm>
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
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e2+9, MAXM = 2e5+9;

int m,n,k,x1,_y1,x2,y2,b[11],c[11],vis[MAXN][MAXN][33];
char s[MAXN][MAXN];
struct node {
    int x,y,t,st;
};
const int rr[]={0,1,0,-1};
const int cc[]={1,0,-1,0};
#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
int bfs()
{
    queue<node> Q;
    int st=0;
    REP(i,k) if (b[i]==x1 && c[i]==_y1) st|=(1<<i);
    Q.push({x1,_y1,0,st});
    vis[x1][_y1][st]=1;
    while (!Q.empty()) {
        node now=Q.front(); Q.pop();
        int x=now.x, y=now.y, t=now.t, st=now.st;
        if (x==x2 && y==y2) return t;
        REP(i,4) {
            int xx=x+rr[i], yy=y+cc[i];
            if (vld(xx,yy) && s[xx][yy]!='#') {
                if (s[xx][yy]=='.') {
                    int nst=st;
                    REP(j,k) if (xx==b[j] && yy==c[j]) nst|=(1<<j);
                    if (!vis[xx][yy][nst]) {
                        vis[xx][yy][nst]=1;
                        Q.push({xx,yy,t+1,nst});
                    }
                } else {
                    if (st>>(s[xx][yy]-'A')&1) {
                        int nst=st^(1<<(s[xx][yy]-'A'));
                        REP(j,k) if (xx==b[j] && yy==c[j]) nst|=(1<<j);
                        if (!vis[xx][yy][nst]) {
                            vis[xx][yy][nst]=1;
                            Q.push({xx,yy,t+1,nst});
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin>>m>>n>>k>>x1>>_y1>>x2>>y2) {
        memset(vis,0,sizeof(vis));
        REP(i,m) scanf("%s", s[i]);
        REP(i,k) scanf("%d%d", &b[i],&c[i]);
        printf("%d\n", bfs());
    }

    return 0;
}
































