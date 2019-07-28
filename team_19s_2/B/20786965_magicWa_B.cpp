#include <bits/stdc++.h>
using namespace std;

int M[305][305];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int f, t, d;
        memset(M, 0, sizeof(M));
        for (int i = 1; i <= n * (n - 1) / 2; i++)
        {
            scanf("%d%d%d", &f, &t, &d);
            M[f][t] = d;
            M[t][f] = d;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    ans = max(ans, M[i][j] + M[i][k] + M[j][k]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}