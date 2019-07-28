#include <bits/stdc++.h>

using namespace std;
map<long long, long long> mmp;

long long DP(long long x) {
    if (x == 1)return 0;
    if (mmp.count(x) == 1)return mmp[x];
    long long dp = 0;
    long long tmp = x;
    for (int i = 2; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            dp += 1 + DP(tmp / i);
            while (x % i == 0)x /= i;
        }
    }
    if (x != 1)dp += 1 + DP(tmp / x);
    mmp[tmp] = 0;
    return dp;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long s;
        mmp.clear();
        cin >> s;
        cout << DP(s) << endl;
    }
    return 0;
}