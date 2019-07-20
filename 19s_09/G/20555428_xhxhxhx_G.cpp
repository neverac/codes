#include <iostream>
using namespace std;

typedef long long ll;

const ll MAX_N = 1000007;
ll dp[MAX_N];
ll dp2[MAX_N];

int main()
{
	ll m = 0;
	for (ll i = 1; i < MAX_N; ++i)
	{
		dp[i] = dp[i - 1] + i * (i + 1) / 2;
		dp2[i] = dp2[i - 1] + (i & 1 ? (i / 2 + 1) * (i / 2) : (i / 2 + 1) * (i / 2) - (i / 2));
	}
	int T, N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%lld\n", dp[N] + dp2[N]);
	}
	return 0;
}