#include <stdio.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
const ll mod = 998244353;
char s[N];

int main()
{
    ll n;
    scanf("%lld %s", &n, &s);

    ll l, r;
    for (l = 1; l < n; l ++)
        if (s[l] != s[0]) break;
    for (r = n - 2; r >= 0; r --)
        if (s[r] != s[n - 1]) break;

    ll ans = 0;
    if (s[0] == s[n - 1])
    {
        ans = (l + 1) * (n - r);
    }
    else
    {
        ans = (l + 1) + (n - r) - 1;
    }
    
    ans %= mod;
    printf("%lld\n", ans);
}