#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100 + 7;

int n;
int a[maxn];
int pos, neg;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            pos++;
        }
        else if (a[i] < 0)
        {
            neg++;
        }
    }
    if (pos >= ceil(n/2.0))
    {
        ans = 1;
    }
    else if (neg >= ceil(n/2.0))
    {
        ans = -1;
    }
    else
    {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}