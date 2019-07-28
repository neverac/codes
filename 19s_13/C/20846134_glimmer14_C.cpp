#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 55;
char ma[N][N];
int step[N][N];
const int INF = 0x3f3f3f3f;
typedef pair<int, int> point;
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

vector<point> v1, v2;
int r1, c1, r2, c2;
bool bfs(int sr, int sc, int er, int ec, vector<point> &v)
{
    step[sr][sc] = 0;
    queue<point> q;
    q.push(point(sr, sc));
    point p;
    bool flag;
    int x, y;

    while (!q.empty())
    {
        p = q.front(); q.pop();
        flag = false;
        for (int i = 0; i < 4; i ++)
        {
            x = p.first + dir[i][0], y = p.second + dir[i][1];
            if (ma[x][y] == '1')
            {
                flag = true;
                continue;
            }
            if (step[x][y] <= step[p.first][p.second] + 1) continue;
            if (x == er && y == ec) return true;
            step[x][y] = step[p.first][p.second] + 1;
            q.push(point(x, y));
        }
        if (flag) v.push_back(p);
    }
    return false;
}

inline int dis(point x, point y)
{
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}
int solve()
{
    int ans = INF;
    vector<point>::iterator it1, it2;
    for (it1 = v1.begin(); it1 != v1.end(); it1++)
        for (it2 = v2.begin(); it2 != v2.end(); it2++)
            ans = min(ans, dis(*it1, *it2));
    // for (point i : v1)
    //     for (point j : v2)
    //     {
    //         ans = min(ans, dis(i, j));
    //     }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = 1; i <= n; i ++)
        for (int j = 1;j <= n; j ++)
            cin >> ma[i][j];
    for (int i = 1; i <= n; i ++)
        ma[0][i] = ma[n + 1][i] = ma[i][0] = ma[i][n + 1] = '1';
    memset(step, INF, sizeof step);
    if (bfs(r1, c1, r2, c2, v1) || bfs(r2, c2, r1, c1, v2))
        cout << 0 << endl;
    else cout << solve() << endl;
}