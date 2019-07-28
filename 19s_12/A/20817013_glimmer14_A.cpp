#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
const int N = 1e6 + 5;
bool vis[N];
bool cnt[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, q;
    cin >> p >> q;
    while (!vis[p] && p != 0)
    {
        vis[p] = true;
        p *= 10;
        cnt[p / q] = true;
        // cout << p / q << endl;
        p %= q;
    }
    for (int i = 0; i <= 9; i ++)
        if (cnt[i]) cout << i;
    cout << endl;
}