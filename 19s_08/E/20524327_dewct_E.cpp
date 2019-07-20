#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int num[233];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, sum1 = 0, sum2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            num[i] %= 3;
            if (!num[i])
                ans++;
            else if (num[i] == 1)
                sum1++;
            else if (num[i] == 2)
                sum2++;
        }
        if (sum1 <= sum2)
            ans += sum1, ans += (sum2 - sum1) / 3;
        else
            ans += sum2, ans += (sum1 - sum2) / 3;
        printf("%d\n", ans);
    }
    return 0;
}