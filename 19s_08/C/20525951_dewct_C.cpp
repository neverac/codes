#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL k, a, b;
    cin >> k >> a >> b;
    LL ans = 1;
    if (a >= b - 1 || k <= a - 1)
        ans = k + 1;
    else
    {
        k -= a - 1;
        ans += a - 1;
        LL ls = k / 2;
        ans += ls * (b - a);
        if (k % 2)
            ans++;
    }
    cout << ans;
    return 0;
}
// 48518828946040168 48518828981938099 48518828981938099