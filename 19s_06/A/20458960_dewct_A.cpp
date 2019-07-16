#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map<LL, LL> m;
queue<LL> q;

LL cal(LL n, LL p)
{
    if (n < p)
        return 0;
    else
        return n / p + cal(n / p, p);
}

int main()
{
    LL n, b;
    cin >> n >> b;
    LL ls = sqrt(b);
    for (LL i = 2; i <= ls; i++)
    {
        if (b % i == 0)
        {
            LL lls = 0;
            while (b % i == 0)
            {
                b /= i;
                lls++;
            }
            m[i] = lls;
            q.push(i);
        }
    }
    if (b > 1)
        q.push(b), m[b]++;
    LL ans = 1e18;
    while (!q.empty())
    {
        LL u = q.front();
        q.pop();
        ans = min(ans, cal(n, u) / m[u]);
    }
    cout << ans;
    return 0;
}