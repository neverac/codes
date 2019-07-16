#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL M[1050][1050];
LL sum[1050][1050];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &M[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (M[1][i] - M[1][i - 1] == 1)
            sum[1][i] = 1;
        if (M[i][1] - M[i - 1][1] == 1)
            sum[i][1] = 1;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (M[i][j] - M[i][j - 1] == 1 && M[i][j] - M[i - 1][j] == 1)
            {
                sum[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; i + k <= n && j + k <= n; k++)
            {
                if (sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j] != k * k)
                    break;
                ans = max(ans, k + 1);
            }
        }
    }
    cout << ans;
    return 0;
}