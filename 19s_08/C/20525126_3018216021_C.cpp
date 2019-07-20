#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100 + 7;

ll K, A, B;
ll ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> K >> A >> B;
    if (A >= B - 2 || K <= A)/*1.A==B+2时两种情况相等*/
    {                        /*2.K<=A时打开K次最优*/
        ans = K + 1;
    }
    else
    {
        K -= (A - 1);
        ans = A + (B - A) * (K / 2);
        if (K % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}