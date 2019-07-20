#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL mod = 998244353;

char a[233333];

int main()
{
    int n;
    cin >> n;
    scanf("%s", a + 1);
    LL sum1 = 1, sum2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            sum1++;
        else
            break;
    }
    for (int i = n - 1; i >= 1; i--)
        if (a[i] == a[i + 1])
            sum2++;
        else
            break;
    LL ans = 1;
    if (a[1] != a[n])
        ans += sum1 + sum2;
    else
        ans += (((sum1 + 1) * (sum2 + 1)) - 1) % mod;
    ans %= mod;
    cout << ans;
    return 0;
}