#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 50 + 7;

struct node
{
    int x;
    int y;
}stat[maxn*maxn], ed[maxn*maxn];
int cs, ce;

int n;
char mp[maxn][maxn];
int visit[maxn][maxn];//0 no visit, 1 水, 2 起点可达, 3 终点可达
int X0, Y0, X1, Y1;
ll ans;

void dfs(int a, int b, int tag)
{
    if (visit[a][b] || a < 1 || a > n || b < 1 || b > n)
        return;
    visit[a][b] = tag;
    dfs(a+1, b, tag);
    dfs(a-1, b, tag);
    dfs(a, b+1, tag);
    dfs(a, b-1, tag);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    INIT(visit, 0);
    cin >> X0 >> Y0;
    cin >> X1 >> Y1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '1')
                visit[i][j] = 1;//水
        }
    }
    dfs(X0, Y0, 2);
    if (visit[X1][Y1] == 2)
    {
        ans = 0;
    }
    else
    {
        dfs(X1, Y1, 3);
        cs = ce = 0;
        ans = maxn * maxn * 2;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (visit[i][j] == 2)
                {
                    stat[++cs].x = i;
                    stat[cs].y = j;
                }
                else if (visit[i][j] == 3)
                {
                    ed[++ce].x = i;
                    ed[ce].y = j;
                }
            }
        }
        for (int i = 1; i <= cs; ++i)
        {
            for (int j = 1; j <= ce; ++j)
            {
                ll res = (ll)(stat[i].x - ed[j].x) * (stat[i].x - ed[j].x) +
                        (ll)(stat[i].y - ed[j].y) * (stat[i].y - ed[j].y);
                ans = min(ans, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}