#include <bits/stdc++.h>

#define ID(x, y) (x-1)*n+y
using namespace std;
char op[55][55];
int fa[2550], bx, by, ex, ey, n, vis[55][55];
const int X[] = {-1, 0, 1, 0}, Y[] = {0, 1, 0, -1};

vector<int> v1, v2;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2)fa[f1] = f2;
}

void DFS(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + X[i], yy = y + Y[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
            if (!vis[xx][yy] && op[xx][yy] == '0') {
                merge(ID(x, y), ID(xx, yy)), vis[xx][yy] = 1, DFS(xx, yy);
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> bx >> by >> ex >> ey;
    for (int i = 1; i <= n; i++)cin >> (op[i] + 1);
    for (int i = 1; i <= n * n; i++)fa[i] = i;
    vis[bx][by] = 1, DFS(bx, by);
    if (vis[ex][ey]) {
        cout << 0;
        return 0;
    }
    vis[ex][ey] = 1, DFS(ex, ey);
    for (int i = 1; i <= n * n; i++)if (find(i) == find(ID(bx, by)))v1.push_back(i);
    for (int i = 1; i <= n * n; i++)if (find(i) == find(ID(ex, ey)))v2.push_back(i);
    int ans = 0x7fffffff;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            int x1 = (v1[i] - 1) / n + 1, y1 = (v1[i] - 1) % n + 1;
            int x2 = (v2[j] - 1) / n + 1, y2 = (v2[j] - 1) % n + 1;
            ans = min(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }
    cout << ans;
    return 0;
}