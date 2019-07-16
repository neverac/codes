#include <bits/stdc++.h>

using namespace std;
int n, m, k, op[200005], op2[200005];
map<int, int> mmp;
long long ans = 0;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
        op2[i] = op[i];
    }
    sort(op + 1, op + n + 1);
    for (int i = n; i >= n - m * k + 1; i--) {
        if (mmp.count(op[i]) == 0)mmp[op[i]] = 1;
        else ++mmp[op[i]];
        ans += op[i];
    }
    cout << ans << endl;
    int now = 0, pp = 1;
    for (int i = 1; i <= n; i++) {
        if (mmp.count(op2[i]) != 0 && mmp[op2[i]] > 0) {
            ++now, mmp[op2[i]]--;
            if (now == m) {
                ++pp, cout << i << " ", now = 0;
                if (pp == k)return 0;
            }
        }
    }
    return 0;
}