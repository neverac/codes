#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map<int, int> used;

int num[233333];
int px[233333];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        px[i] = num[i];
    }
    sort(px + 1, px + n + 1);
    LL ans = 0;
    for (int i = 1; i <= m * k; i++)
    {
        ans += (LL)px[n - i + 1];
        used[px[n - i + 1]]++;
    }
    printf("%lld\n", ans);
    int ls = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (used[num[i]])
        {
            ls++;
            used[num[i]]--;
        }
        if (ls == m && cnt < k - 1)
        {
            cnt++;
            printf("%d ", i);
            ls = 0;
        }
    }
    return 0;
}