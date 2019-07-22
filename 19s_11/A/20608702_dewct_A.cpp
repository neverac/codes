#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int num[233333];

int main()
{
    int n;
    LL sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    sort(num + 1, num + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (2 * sum - (LL)num[i]) * (LL)num[i];
        sum -= num[i];
    }
    cout << ans;
    return 0;
}