#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1005;
int map[N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const int INF = 0x3f3f3f3f;

int h, w;

struct Node
{
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
};

int main()
{
    memset(map, INF, sizeof map);
    cin >> h >> w;
    char c;
    queue<Node> q;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> c;
            if (c == '#')
            {
                map[i][j] = 0;
                q.push(Node(i, j));
            }
        }
    for (int i = 1; i <= h; i++)
        map[i][0] = map[i][w + 1] = 0;
    for (int i = 1; i <= w; i++)
        map[0][i] = map[h + 1][i] = 0;

    Node now(0, 0), nn(0, 0);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            nn.x = now.x + dir[k][0];
            nn.y = now.y + dir[k][1];
            if (map[nn.x][nn.y] == INF)
            {
                map[nn.x][nn.y] = map[now.x][now.y] + 1;
                q.push(nn);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i ++)
        for (int j = 1; j <= w; j ++)
            if (map[i][j] > ans) ans = map[i][j];

    cout << ans << endl;
}