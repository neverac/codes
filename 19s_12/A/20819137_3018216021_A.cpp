#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 1e5 + 77;

ll p, q;
ll ans;
bool vis[maxn * 100];
bool app[10];

void solve(ll n)
{
    n *= 10;
    app[n / q] = true;
    if (vis[n % q] || n % q == 0)
        return;
    vis[n % q] = true;
    solve(n % q);
}

int main()
{
    ios::sync_with_stdio(false);
    INIT(app, 0);
    cin >> p >> q;
    solve(p);
    for (int i = 0; i < 10; ++i)
    {
        if(app[i])
            cout << i;
    }
    cout << endl;
    return 0;
}