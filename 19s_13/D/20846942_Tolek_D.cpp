#include <bits/stdc++.h>

using namespace std;
int n, m;
int op[500], minn[500];
int maxn = 0;

inline int ID(int x, int y) {
    if (x + y <= n)return x + y;
    return (x + y) % n;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)minn[i] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        ++op[a], minn[a] = min(minn[a], b < a ? n + b - a : b - a);
    }
    for (int i = 1; i <= n; i++)maxn = max(maxn, op[i]);
    for (int i = 1; i <= n; i++) {
        int ans = (maxn - 1) * n, ss = 0, tim = 0;
        for (int j = 0; j < n; j++) {
            if (op[ID(i, j)] == maxn)ss = max(ss, tim + minn[ID(i, j)]);
            else if (op[ID(i, j)] == maxn - 1 && j != 0 && maxn != 1)
                ss = max(ss, minn[ID(i, j)] - (i < ID(i, j) ? n + i - ID(i, j) : i - ID(i, j)));
            ++tim;
        }
        cout << ans + ss << " ";
    }
    return 0;
}