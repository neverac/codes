#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 1000 + 7;

ll n;
ll sum;
ll a;


int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        sum += a;
    }
    cout << sum * sum << endl;
    return 0;
}