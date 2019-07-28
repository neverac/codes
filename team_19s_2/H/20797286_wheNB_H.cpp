#include <bits/stdc++.h>

#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100 + 7;
const int MAXN = 1e6 + 77;

int T;
ll n;
int factor[maxn][2];//0 factor, 1 count
ll cnt;
ll ans;
ll res;

int prime[MAXN + 1];

int getPrime()//得到小于等于MAXN的素数，prime[0]存放的是个数
{
    INIT(prime, 0);
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    return prime[0];
}

ll getFactors(ll x)
{
    cnt = 0;
    ll tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; ++i)
    {
        if (tmp % prime[i] == 0)
        {
            factor[cnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[cnt][1]++;
                tmp /= prime[i];
            }
            cnt++;
        }
    }
    if (tmp != 1)
    {
        factor[cnt][0] = tmp;
        factor[cnt++][1] = 1;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    getPrime();
    scanf("%d", &T);
    while (T--)
    {
        INIT(factor, 0);
        scanf("%lld", &n);
        ans = 0;

        getFactors(n);

        for (int i = 0; i < cnt; ++i)
        {
            res = factor[i][1];
            for (int j = 0; j < cnt; ++j)
            {
                if (i == j)
                    continue;
                res *= ((ll) factor[j][1] + 1);
            }
            ans += res;
        }
        printf("%lld\n", ans);
    }
    return 0;
}