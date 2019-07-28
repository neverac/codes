#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 1e5 + 77;

int n;
ll a[maxn<<1];
ll dp[maxn];
ll ans;
ll res1, res2;
int loc[maxn][3];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    INIT(a, 0);
    INIT(dp, 0);
    INIT(loc, 0);
    for (int i = 1; i <= n * 2; ++i)
    {
        cin >> a[i];
        loc[a[i]][++loc[a[i]][0]] = i;//记录出现位置
    }
    for (int i = 2; i <= n; ++i)
    {
        res1 = abs(loc[i][1] - loc[i-1][1]) + abs(loc[i][2] - loc[i-1][2]);
        res2 = abs(loc[i][1] - loc[i-1][2]) + abs(loc[i][2] - loc[i-1][1]);
        dp[i] = dp[i-1] + min(res1, res2);
    }
    ans = dp[n] + loc[1][1] + loc[1][2] - 2;
    cout << ans << endl;
    return 0;
}