#include <bits/stdc++.h>

using namespace std;
int n, r;
long long k;
long long op[500005];
long long bj[500005];

bool solve(long long a) {
    long long p = k, pk = 0;
    memset(bj, 0, sizeof(bj));
    for (int i = 1; i <= n; i++) {
        pk += bj[i];
        if (op[i] + pk < a) {
            if (p >= a - op[i] - pk) {
                p -= a - op[i] - pk;
                bj[min(n + 1, i + 2 * r + 1)] -= a - op[i] - pk;
                pk += a - op[i] - pk;
            } else return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
        bj[max(1, i - r)] += op[i];
        bj[min(n + 1, i + r + 1)] -= op[i];
    }
    for (int i = 1; i <= n; i++)bj[i] += bj[i - 1], op[i] = bj[i];
    long long l = 0, r = static_cast<long long int>(1e18 + 5 * 1e14 + 1000);//[,)
    while (l < r) {
        if (r == l + 1) {
            cout << l;
            return 0;
        }
        long long mid = (l + r) / 2;
        if (solve(mid)) l = mid;
        else r = mid;
    }
    return 0;
}