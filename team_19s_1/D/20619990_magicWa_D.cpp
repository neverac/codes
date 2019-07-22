#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL num[233];

int main()
{
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        int lx, ly;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &lx, &ly), num[i] = lx + ly;
        sort(num + 1, num + n + 1);
        LL ans = 1, lsk = 0;
        for (int i = 1; i <= n; i++)
        {
            ans *= num[i];
            if (ans > m)
                break;
            lsk++;
        }
        printf("%d\n", lsk);
    }
    return 0;
}