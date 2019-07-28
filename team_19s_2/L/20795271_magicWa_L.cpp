#include <bits/stdc++.h>
using namespace std;

char a[233333];
int dp[233333];
int fail[233333];

void init(int l, int r)
{
    fail[1] = 0;
    for (int i = 2; i <= r; i++)
    {
        int p = fail[i - 1];
        while (p && a[i + l - 1] != a[p + 1 + l - 1])
            p = fail[p];
        if (a[i + l - 1] == a[p + 1 + l - 1])
            p++;
        fail[i] = p;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        scanf("%s", a + 1);
        int len = strlen(a + 1);
        for (int i = 1; i <= len; i++)
        {
            init(i, len - i + 1);
            for (int j = i; j <= len; j++)
            {
                int ls = j - i + 1 - fail[j - i + 1];
                // cout << ": " << ls << endl;
                if ((j - i + 1) % ls == 0)
                    dp[j] = min(dp[j], dp[i - 1] + ls);
                else
                    dp[j] = min(dp[j], dp[i - 1] + j - i + 1);
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}