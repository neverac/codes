#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
char s[N];
ll val[N];
ll dp[4][N];
const char ff[4] = {'h', 'a', 'r', 'd'};

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", &s);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &val[i]);
    
    for (int j = 1; j <= n; j ++)
        if (s[j - 1] == 'h')
            dp[0][j] = dp[0][j - 1] + val[j];
        else
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i < 4; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            
            if (s[j - 1] == ff[i])
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + val[j]);
            else dp[i][j] = dp[i][j - 1];
        }
    }
    printf("%lld\n", dp[3][n]);
}