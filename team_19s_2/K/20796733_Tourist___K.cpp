#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 30;
int n, m,G[maxn][maxn],c[maxn];

bool dfs(int x){
    for (int i=0;i<x;i++)
        if (G[i][x] && c[i] == c[x]) return false;

    if (x + 1 == n) return true;
    for (int j = 1;j<=3;j++){
        c[x+1] = j;
        if (dfs(x+1)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(G,0,sizeof(G));
        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;
            G[x][y] = G[y][x] = 1;
        }
        c[0] = 1;
        if (dfs(0)) cout << 'Y' << endl;else cout << 'N' << endl;

    }
}