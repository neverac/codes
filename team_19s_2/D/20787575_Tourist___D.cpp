#include <iostream>
#include <cstring>

const int maxn = 205;
using namespace std;
int n, m, G[maxn][maxn], M[300];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
//    cout << "fuck";
    while (n != 0) {
        cin >> m;
        memset(G, 0x3f, sizeof(G));
        memset(M, 0, sizeof(M));
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            x++,y++;
            G[x][y] = G[y][x] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (i != j && i != k && j != k) {
                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                    }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (G[i][j] < (0x3f3f3f3f-100 )) M[G[i][j]]++;

        for (int i = 1; i <= n; i++) {
//            cout << M[i]<<endl;
            if (M[i]) { cout << i << ' ' << M[i] << endl; }
        }
        cin >> n;
    }

}
