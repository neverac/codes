#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL t[1000050];

int main()
{
    for (LL i = 1; i <= 1e6; i++)
    {
        t[i] = t[i - 1] + i * (i + 1) / 2 + i * i / 4;
    }
    int T, n;
    cin >> T;
    while (T--)
    {
        scanf("%d", &n);
        printf("%lld\n", t[n]);
    }
    return 0;
}