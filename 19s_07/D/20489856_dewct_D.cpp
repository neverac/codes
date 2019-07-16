#include <bits/stdc++.h>
using namespace std;

char a[2333];
int sum1[2333];
int sum2[2333];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        scanf("%s", a + 1);
        int len = strlen(a + 1);
        for (int i = 1; i <= len; i++)
        {
            sum1[i] = sum1[i - 1] + a[i] - '0';
        }
        int ans = 1e9;
        for (int i = len; i >= 1; i--)
        {
            sum2[i] = sum2[i + 1];
            if (a[i] == '0')
                sum2[i]++;
        }
        for (int i = 1; i <= len; i++)
        {
            ans = min(ans, sum1[i] + sum2[i]);
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}