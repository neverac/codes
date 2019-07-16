#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
ll yz[100000];
ll yzs[100000];
ll at[100000];

int yt = 0;
ll n, b;

const int MAX_N = 1000006;
bool isp[MAX_N];
int pt = 0;
ll pri[MAX_N];

int main()
{

	for (int i = 2; i < MAX_N; ++i)
	{
		if (!isp[i])
		{
			for (int j = i + i; j < MAX_N; j += i)
			{
				isp[j] = true;
			}
			pri[pt++] = i;
		}
	}



	scanf("%lld%lld", &n, &b);

	ll sqb = sqrt((double)b);

	for (int i = 0; pri[i] <= sqb; ++i)
	{
		const ll& cp = pri[i];
		if (!(b % cp))
		{
			yz[yt] = cp;
			while (!(b % cp))
			{
				b /= cp;
				++yzs[yt];
			}
			sqb = sqrt((double)b);
			++yt;
		}
	}
	if (b > 1)
	{
		yz[yt] = b;
		yzs[yt++] = 1;
	}

	ll ans = LLONG_MAX;


	for (int i = 0; i < yt; ++i)
	{
		const ll& cur = yz[i];
		ll _n = n;
		while (_n / cur)
		{
			at[i] += _n / cur;
			_n /= cur;
		}
		ans = min(ans, at[i] / yzs[i]);
	}


	printf("%lld\n", ans);


	return 0;
}
