#include <bits/stdc++.h>

#define ll long long
#define INF 100000000;
const int maxn = 3600;
using namespace std;

int n, r1, c1, r2, c2, num1, num2, ans = INF;
char a[55][55];
bool vis[55][55];
int mx[4] = {0, 1, -1, 0}, my[4] = {1, 0, 0, -1};

struct node {
    int x;
    int y;

    node(int a, int b) : x(a), y(b) {}
};

vector<node> l1, l2;

void find(int x, int y, vector<node> &m) {
    for (int i = 0; i < 4; i++) {
        int posx = x + mx[i];
        int posy = y + my[i];
        if (posx < 1 || posx > n || posy < 1 || posy > n)
            continue;
        if (vis[posx][posy])
            continue;
        if (a[posx][posy] == '1')
            continue;
        vis[posx][posy] = true;
        m.push_back(node(posx, posy));
        find(posx, posy, m);
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    l1.push_back(node(r1, c1));
    l2.push_back(node(r2, c2));
    vis[r1][c1] = true;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    find(r1, c1, l1);
    if (vis[r2][c2]) {
        cout << 0 << endl;
    } else {
        vis[r2][c2] = true;
        find(r2, c2, l2);
        for (int i = 0; i < l1.size(); i++) {
            for (int j = 0; j < l2.size(); j++) {
                ans = min(ans, (l1[i].x - l2[j].x) * (l1[i].x - l2[j].x) + (l1[i].y - l2[j].y) * (l1[i].y - l2[j].y));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
