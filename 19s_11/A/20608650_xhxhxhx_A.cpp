#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
const int MAX_N = 100080;
ll d[MAX_N];

int main()
{
	int n;
	scanf("%d", &n);
	ll s = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", d + i);
		s += d[i];
	}
	sort(d, d + n);

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += d[i] * s;
		s -= d[i];
		ans += d[i] * s;
	}
	printf("%lld\n", ans);

	return 0;
}
