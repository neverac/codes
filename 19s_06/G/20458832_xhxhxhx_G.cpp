#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

typedef long long ll;

const int MAX_N = 105;

ll dp[MAX_N][MAX_N];
ll col[MAX_N];
ll s[MAX_N];

int main()
{
	int T, n;

	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", col + i);
		}
		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; ++i)
		{
			s[i] = s[i - 1] + col[i];
		}

		for (int d = 1; d < n; ++d)
		{
			for (int i = 1; i + d <= n; ++i)
			{
				const int j = i + d;
				ll m = LLONG_MAX;
				for (int k = i; k < j; ++k)
				{
					if (dp[i][k] + dp[k + 1][j] + ((s[k] - s[i - 1]) % 100) * ((s[j] - s[k]) % 100) < m)
					{
						m = dp[i][k] + dp[k + 1][j] + ((s[k] - s[i - 1]) % 100) * ((s[j] - s[k]) % 100);
					}
				}
				dp[i][j] = m;
			}
		}

		printf("%lld\n", dp[1][n]);
	}

	return 0;
}
