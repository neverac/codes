#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;


typedef long long ll;

const int MAX_N = 1010000;


ll ps[MAX_N];
ll A[MAX_N];
ll hei[MAX_N];
ll d[MAX_N];
bool C(const ll mid);
ll n, r, k;

int main()
{

	scanf("%lld%lld%lld", &n, &r, &k);

	for (ll i = 0; i < n; ++i)
	{
		scanf("%llu", A + i);
	}
	for (ll i = 1; i <= n; ++i)
	{
		ps[i] = ps[i - 1] + A[i - 1];
	}

	for (ll i = 0; i < n; ++i)
	{
		hei[i] = ps[min(n, i + r + 1)] - ps[max(0ll, i - r)];
	}

	ll lb = 0, rb = LLONG_MAX;

	while (lb + 1 < rb)
	{
		ll mid = (lb + rb) >> 1;
		if (C(mid))
		{
			lb = mid;
		}
		else
		{
			rb = mid;
		}
	}
	printf("%lld\n", lb);
	return 0;
}

bool C(const ll mid)
{
	memset(d, 0, sizeof(d));
	ll tk = k, sd = 0;
	for (ll i = 0; i < n; ++i)
	{
		sd -= d[i];
		d[i] = 0;
		if (sd + hei[i] < mid)
		{
			ll m = mid - hei[i] - sd;
			sd += m;
			tk -= m;
			if (tk < 0)
			{
				return false;
			}
			d[i + r + r + 1] = m;
		}
	}
	return true;
}
