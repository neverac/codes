#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 1000 + 7;

int H, W;
char mp[maxn][maxn];
int ans = 0;
int stk[maxn * maxn][2];
int wat[maxn * maxn][2];
int tail, p;

void bfs()
{
    while (tail)
    {
        p = 0;
        for (int i = 0; i < tail; ++i)
        {
            if (stk[i][0] - 1 >= 1 && mp[stk[i][0] - 1][stk[i][1]] == '.')
            {
                mp[stk[i][0] - 1][stk[i][1]] = '#';
                wat[p][0] = stk[i][0] - 1;
                wat[p][1] = stk[i][1];
                p++;
            }
            if (stk[i][0] - 1 <= H && mp[stk[i][0] + 1][stk[i][1]] == '.')
            {
                mp[stk[i][0] + 1][stk[i][1]] = '#';
                wat[p][0] = stk[i][0] + 1;
                wat[p][1] = stk[i][1];
                p++;
            }
            if (stk[i][1] - 1 >= 1 && mp[stk[i][0]][stk[i][1] - 1] == '.')
            {
                mp[stk[i][0]][stk[i][1] - 1] = '#';
                wat[p][0] = stk[i][0];
                wat[p][1] = stk[i][1] - 1;
                p++;
            }
            if (stk[i][1] - 1 <= W && mp[stk[i][0]][stk[i][1] + 1] == '.')
            {
                mp[stk[i][0]][stk[i][1] + 1] = '#';
                wat[p][0] = stk[i][0];
                wat[p][1] = stk[i][1] + 1;
                p++;
            }
        }
        tail = p;
        if (p)
        {
            ans++;
            for (int i = 0; i < p; ++i)
            {
                stk[i][0] = wat[i][0];
                stk[i][1] = wat[i][1];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> H >> W;
    for (int i = 0; i <= H+1; ++i)
    {
        for (int j = 0; j <= W+1; ++j)
        {
            mp[i][j] = '#';
        }
    }
    tail = 0;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '#')
            {
                stk[tail][0] = i;
                stk[tail][1] = j;
                tail++;
            }
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}