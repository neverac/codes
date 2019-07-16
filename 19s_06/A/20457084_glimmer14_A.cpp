#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 10;
bool check[MAXN + 10];
ll phi[MAXN + 10];
ll prime[MAXN + 10];
ll tot; //素数的个数
void phi_and_prime_table(ll N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (ll i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (ll j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    // cout << tot << endl;
}

struct Node
{
    ll pri, num;
}temp;
vector<Node> dd;

ll solve(ll n, ll b)
{
    for (ll i = 0; i < 78499; i ++)
    {
        if (b % prime[i] == 0)
        {
            temp.pri = prime[i];
            temp.num = 0;
            while (b % prime[i] == 0)
            {
                temp.num ++;
                b /= prime[i];
            }
            dd.push_back(temp);
        }
        if (b == 1) break;
    }
    if (b != 1)
    {
        temp.pri = b;
        temp.num = 1;
        dd.push_back(temp);
    }

    ll ans = 1e18;
    ll l = dd.size();
    ll hhh;
    ll num;
    for (ll i = 0; i < l; i ++)
    {
        hhh = n;
        num = 0;
        // cout << dd[i].pri << endl;
        // cout << dd[i].num << endl;
        while (hhh > 1)
        {
            hhh /= dd[i].pri;
            num += hhh;
        }
        // cout << num << endl;
        ans = min(ans, num / dd[i].num);
        // cout << ans << endl;
    }
    return ans;
}

int main()
{
    phi_and_prime_table(1e6 + 3);
    ll n, b;
    cin >> n >> b;
    cout << solve(n, b) << endl;

}