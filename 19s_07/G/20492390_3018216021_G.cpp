#include <bits/stdc++.h>
#define ll long long
#define INIT(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 1000 + 7;

int N;
struct node
{
    int num;
    int isFu;
}mp[maxn][maxn];

int ans;
int temp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    INIT(mp, 0);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> mp[i][j].num;
            mp[i][j].isFu = 1;
        }
    }
    ans = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            if (mp[i][j].num + 1 == mp[i][j+1].num &&
                mp[i][j].num + 1 == mp[i+1][j].num &&
                mp[i][j].num + 2 == mp[i+1][j+1].num)
            {
                mp[i][j].isFu++;
                ans = max(ans, mp[i][j].isFu);
            }
        }
    }
    N--;
    while(true)
    {
        temp = ans;
        for (int i = 1; i < N; ++i)
        {
            for (int j = 1; j < N; ++j)
            {
                if (mp[i][j].isFu == mp[i][j+1].isFu &&
                    mp[i][j].isFu == mp[i+1][j].isFu &&
                    mp[i][j].isFu == mp[i+1][j+1].isFu)
                {
                    mp[i][j].isFu++;
                    ans = max(ans, mp[i][j].isFu);
                }
            }
        }
        N--;
        if (temp == ans)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}