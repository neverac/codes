#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map<int, int> p1, p2;

int main()
{
    int n, ls;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &ls);
        if (!p1[ls])
            p1[ls] = i;
        else
            p2[ls] = i;
    }
    p1[0] = 1, p2[0] = 1;
    int x1 = 1, x2 = 1;
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(p1[i] - p1[i - 1]);
        ans += abs(p2[i] - p2[i - 1]);
    }
    cout << ans;
    return 0;
}