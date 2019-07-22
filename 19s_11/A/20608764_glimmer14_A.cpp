#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll val[N];

bool comp(ll a, ll b)
{
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i ++)
        scanf("%lld", &val[i]), sum += val[i];
    sort(val, val + n, comp);
    ll ans = 0;
    for (int i = 0; i < n; i ++)
    {
        ans += sum * val[i];
        sum -= val[i];
        ans += sum * val[i];
    }
    printf("%lld\n", ans);
    
}