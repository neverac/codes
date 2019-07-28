#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 30;

bool mp[N][N];
int b[N], n, m;


int check(int pos) {
    for (int i = 0; i < pos; i++) {
        if (mp[i][pos] && b[i] == b[pos])
            return 0;
    }

    return 1;
}

int find(int pos) {

    if (!check(pos))
        return 0;

    if (pos == n - 1)
        return 1;

    for (int i = 0; i < 3; i++) {
        b[pos + 1] = i;
        if (find(pos + 1))
            return 1;
    }

    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            b[i] = 0;
            for (int j = 0; j < n; j++)
                mp[i][j] = false;
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            mp[u][v] = mp[v][u] = true;
        }
        if (find(0))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}