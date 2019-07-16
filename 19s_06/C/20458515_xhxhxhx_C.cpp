#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <map>
using namespace std;

typedef long long ll;

const int MAX_N = 200005;

ll a[MAX_N];
ll b[MAX_N];
int anss[MAX_N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	map<ll, int> mp;

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", a + i);
		b[i] = a[i];
	}
	sort(b, b + n, greater<>());
	ll ans = 0;
	int t = m * k;

	for (int i = 0; i < t; ++i)
	{
		++mp[b[i]];
	}

	int tp = 0;
	for (int i = 1; i <= k; ++i)
	{
		for (int c = 0; c < m; ++tp)
		{
			if (mp.find(a[tp]) != mp.end())
			{
				if (!--mp[a[tp]]) mp.erase(a[tp]);
				++c;
				ans += a[tp];
			}
		}
		anss[i] = tp;
	}

	printf("%lld\n", ans);
	for (int i = 1; i < k; ++i)
	{
		printf("%d%c", anss[i], i + 1 == k ? '\n' : ' ');
	}


	return 0;
}
