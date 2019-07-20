#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 5e5 + 77;
const ll mod = 998244353;

int T;
int ang;
int ans;

inline ll gcd(ll a, ll b)
{
    ll x;
    while (b != 0)
    {
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> ang;
        ans = 0;
        for (int i = 3; i <= mod; ++i)
        {
            if (gcd(i, 180) == 1)/*任意正多边形能表示的角度都是最小角度的整数倍*/
                continue;/*所以i与180互素时，不可能表示出整数角度*/
            if ((i-2)*180 < i*ang)
                continue;
            if ((ang * i) % 180 == 0)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}