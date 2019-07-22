#include <bits/stdc++.h>

using namespace std;
#define L 16
int a[20][20], ans;
bool vis[L];

bool checkMatrix(int x, int y) {

    for (int i = x; i < x + 4; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < y + 4; j++)
            if (vis[a[i][j]]) return 0; else vis[a[i][j]] = 1;
    }

    for (int j = y; j < y + 4; j++) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < x + 4; i++)
            if (vis[a[i][j]]) return 0; else vis[a[i][j]] = 1;
    }

    return 1;
}

int M[4][4];

void rotate(int x, int y) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            M[i][j] = a[x + i][y + j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[x + i][y + j] = M[3-j][i];
}

void dfs(int x, int y, int cnt) {
//    cout << x << ' ' << y <<' '<< cnt << endl;
    if (cnt > ans) return;
    if (y == 4) {
        dfs(x + 1, 0, cnt);
        return;
    }
    if (x == 4) {
        if (cnt < ans) ans = cnt;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (checkMatrix(x * 4, y * 4))
            dfs(x, y + 1, cnt + i);
        rotate(x * 4, y * 4);
    }


}

void work() {
    for (int i = 0; i < 16; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 16; j++)
            a[i][j] = s[j] >= '0' && s[j] <= '9' ? s[j] - '0' : s[j] - 'A' + 10;
    }
    ans = 999;
   // cout <<
    dfs(0, 0, 0);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        work();
    }
    return 0;

//    for (int i = 0; i < 16; i++) {
//        for (int j = 0; j < 16; j++)
//            cout << a[i][j] << ' ';
//        cout << endl;
//    }
//    cout << endl;
//    rotate(0, 0);
//    for (int i = 0; i < 16; i++) {
//        for (int j = 0; j < 16; j++)
//            cout << a[i][j] << ' ';
//        cout << endl;
//    }
}