#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 100 + 7;

int T, N;
int a;
int cnt[3];/*统计0, 1, 2的出现次数*/
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> N;
        ans = 0;
        INIT(cnt, 0);
        for (int i = 0; i < N; ++i)
        {
            cin >> a;
            a %= 3;
            cnt[a]++;
        }
        if (cnt[1] == cnt[2])
        {
            ans = cnt[0] + cnt[1];
        }
        else if (cnt[1] > cnt[2])
        {
            ans = cnt[0] + cnt[2] + (cnt[1] - cnt[2]) / 3;
        }
        else
        {
            ans = cnt[0] + cnt[1] + (cnt[2] - cnt[1]) / 3;
        }
        cout << ans << endl;
    }
    return 0;
}