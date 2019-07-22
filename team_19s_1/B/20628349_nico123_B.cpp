#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N = 100008;
const ll modd = 1e9 + 7;
ll fact[MAX_N];
ll niyuan[MAX_N];

int B[MAX_N];

ll extgcd(ll a, ll b, ll& x, ll& y);
ll mod_inverse(ll a, ll m);
ll mod_fact(ll n, ll p, ll& e);
ll mod_comb(ll n, ll k);


struct P
{
	int l;
	int r;
	int num;
	bool operator< (const P& ri)const
	{
		return B[l] < B[ri.l] || B[l] == B[ri.l] && r < ri.r;
	}
};

P s[MAX_N];
ll ans[MAX_N];

int main()
{
	fact[0] = 1;
	const int BS = sqrt(MAX_N);
	for (ll i = 1; i < MAX_N; ++i)
	{
		fact[i] = fact[i - 1] * i % modd;
		B[i] = i / BS;
	}
	for (int i = 0; i < MAX_N; ++i)
	{
		niyuan[i] = mod_inverse(fact[i], modd);
	}


	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf("%d%d", &s[i].r, &s[i].l);
		//s[i].l = rand() * rand() % 100000;
		//s[i].r = s[i].l + ((rand() * rand() % (100000 - s[i].l)));
		s[i].num = i;
	}
	sort(s, s + T);

	int cl, cr = MAX_N;
	ll res = 1;
	for (int i = 0; i < T; ++i)
	{
		const P& cur = s[i];
		if (cr > s[i].r)
		{
			res = 1;
			cl = 0;
			cr = s[i].r;
		}
		while (cl > cur.l)
		{
			res = (res - mod_comb(cr, cl--)) % modd;
		}
		while (cr < cur.r)
		{
			res = ((res << 1) - (mod_comb(cr, cl))) % modd;
			++cr;
		}
		while (cl < cur.l)
		{
			res = (res + mod_comb(cr, ++cl)) % modd;
		}
		res %= modd;
		ans[cur.num] = res < 0 ? res + modd : res;
	}
	for (int i = 0; i < T; ++i)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}

ll extgcd(ll a, ll b, ll& x, ll& y)
{
	ll d = a;
	if (b)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}

ll mod_inverse(ll a, ll m)
{
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll mod_fact(ll n, ll p, ll& e)
{
	e = 0;
	if (n == 0)
	{
		return 1;
	}
	ll res = mod_fact(n / p, p, e);
	e += n / p;
	if (n / p % 2)
	{
		return res * (p - fact[n % p]) % p;
	}
	return res * fact[n % p] % p;
}

ll mod_comb(ll n, ll k)
{
	return fact[n] * niyuan[k] % modd * niyuan[n - k] % modd;
}
