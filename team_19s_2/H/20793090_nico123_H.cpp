#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;


const int MAX_N = (1 << 20) + 100;

bool is_prime[MAX_N];
int pris[MAX_N/10];
int pr = 0;
set<ll> st;
ll yzm[MAX_N/10];
ll kk[MAX_N/10];
int cnt[MAX_N/10];

int yzs;
ll ans;
void dfs(ll cur);

int main()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < MAX_N; i++)
	{
		if (is_prime[i])
		{
			pris[pr++] = i;
			for (int j = i + i; j < MAX_N; j += i)
			{
				is_prime[j] = false;
			}
		}
	}

	int T;
	scanf("%d", &T);


	while (T--)
	{
		ll x;
		yzs = 0;
		scanf("%lld", &x);

		ll tx = x;

		ll sqx = sqrt((double)x) + 1;

		for (int i = 0; pris[i] <= sqx; i++)
		{
			const int& cur = pris[i];
			if (!(x % cur))
			{
				yzm[yzs] = cur;
				while (!(x % cur))
				{
					++kk[yzs];
					x /= cur;
				}
				sqx = sqrt((double)x) + 1;
				++yzs;
			}
		}

		if (x > 1)
		{
			yzm[yzs] = x;
			kk[yzs++] = 1;
		}
		sort(yzm, yzm + yzs);
		yzs = unique(yzm, yzm + yzs) - yzm;
		
		ans = 0;
		st.clear();
		for (int i = 0; i < yzs; i++)
		{
			cnt[i] = 0;
		}
		dfs(1);
		printf("%lld\n", ans);

		for (int i = 0; i < yzs; i++)
		{
			kk[i] = 0;
		}
	}

	return 0;
}

void dfs(ll cur)
{
	if (st.find(cur) != st.end())
	{
		return;
	}
	else
	{
		st.insert(cur);
	}
	for (int i = 0; i < yzs; i++)
	{
		if (cnt[i] < kk[i])
		{
			++ans;
			++cnt[i];
			dfs(yzm[i] * cur);
			--cnt[i];
		}
	}
}
