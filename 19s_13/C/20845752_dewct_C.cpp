#include <bits/stdc++.h>
using namespace std;

int sx, sy, tx, ty, cnt = 0, n;

int M[55][55];
int col[55][55];
char MM[55][55];
int lh[55][55];
int xx[5] = {0, 0, 0, 1, -1};
int yy[5] = {0, 1, -1, 0, 0};

struct qer
{
    int x, y;
};

queue<qer> q;

void bfs(int x, int y)
{
    while (!q.empty())
        q.pop();
    q.push((qer){x, y});
    col[x][y] = cnt;
    while (!q.empty())
    {
        qer u = q.front();
        q.pop();
        // cout << u.x << " " << u.y << endl;
        for (int i = 1; i <= 4; i++)
        {
            int lx = u.x + xx[i];
            int ly = u.y + yy[i];
            if (lx < 1 || lx > n || ly < 1 || ly > n || col[lx][ly])
                continue;
            if (M[lx][ly])
            {
                lh[u.x][u.y] = 1;
                continue;
            }
            col[lx][ly] = cnt;
            q.push((qer){lx, ly});
        }
    }
}

int main()
{
    cin >> n;
    cin >> sx >> sy >> tx >> ty;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", MM[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (MM[i][j] == '1')
                M[i][j] = 1;
            else if (MM[i][j] == '0')
                M[i][j] = 0;
        }
    }
    cnt++;
    bfs(sx, sy);
    if (!col[tx][ty])
    {
        cnt++;
        bfs(tx, ty);
    }
    int ans = 2147483640;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    if (lh[i][j] && lh[k][l] && col[i][j] != col[k][l] && col[i][j] == col[sx][sy] && col[k][l] == col[tx][ty])
                    {
                        ans = min(ans, (i - k) * (i - k) + (j - l) * (j - l));
                    }
                }
            }
        }
    }
    if (ans == 2147483640)
        ans = 0;
    cout << ans;
    return 0;
}