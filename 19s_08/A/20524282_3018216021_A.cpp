#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 5e5 + 77;

ll N;
int a[maxn];
int cnt[50];//只用4 8 15 16 23 42
int ans;
int res;//统计出现了多少组4 8 15 16 23 42

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    INIT(a, 0);
    INIT(cnt, 0);
    res = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        if (a[i] == 4)
        {
            cnt[4]++;
        }
        else if (a[i] == 8 && cnt[4])
        {
            cnt[8]++;
            if(cnt[8] > cnt[4])
                cnt[8] = cnt[4];
        }
        else if (a[i] == 15 && cnt[4] && cnt[8])
        {
            cnt[15]++;
            if(cnt[15] > cnt[8])
                cnt[15] = cnt[8];
        }
        else if (a[i] == 16 && cnt[4] && cnt[8] && cnt[15])
        {
            cnt[16]++;
            if(cnt[16] > cnt[15])
                cnt[16] = cnt[15];
        }
        else if (a[i] == 23 && cnt[4] && cnt[8] && cnt[15] && cnt[16])
        {
            cnt[23]++;
            if(cnt[23] > cnt[16])
                cnt[23] = cnt[16];
        }
        else if (a[i] == 42 && cnt[4] && cnt[8] && cnt[15] && cnt[16] && cnt[23])
        {
            res++;
            cnt[4]--;
            cnt[8]--;
            cnt[15]--;
            cnt[16]--;
            cnt[23]--;
        }
    }
    ans = N - 6 * res;
    cout << ans << endl;
    return 0;
}