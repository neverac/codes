#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 1000;

ll x[MAX_N];

int main()
{
	int T, a, b;
	scanf("%d", &T);

	while (T--)
	{
		ll n, m;
		scanf("%lld%lld", &n, &m);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			x[i] = a + b;
		}
		sort(x, x + n);
		ll pp = 1;
		int ans;
		for (ans = 0; ans < n; ++ans)
		{
			pp *= x[ans];
			if (pp > m)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
