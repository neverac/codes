#include <bits/stdc++.h>
using namespace std;

struct qer
{
    int x, y;
};

queue<qer> q;

int n, m;
int ans = 0;
char M[1050][1050];
int xx[5] = {0, 0, 0, 1, -1};
int yy[5] = {0, 1, -1, 0, 0};
bool used[1050][1050];
int d[1050][1050];

void bfs()
{
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (M[i][j] == '#')
                q.push((qer){i, j}), used[i][j] = 1, d[i][j] = 0;
        }
    }
    while (!q.empty())
    {
        qer u = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++)
        {
            int lx = u.x + xx[i];
            int ly = u.y + yy[i];
            if (lx < 1 || lx > n || ly < 1 || ly > m || used[lx][ly])
                continue;
            q.push((qer){lx, ly});
            used[lx][ly] = 1;
            d[lx][ly] = min(d[lx][ly], d[u.x][u.y] + 1);
            ans = max(ans, d[lx][ly]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", M[i] + 1);
    }
    bfs();
    cout << ans;
    return 0;
}