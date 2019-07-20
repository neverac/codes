#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 1 << 18;


struct P
{
	int v;
	bool f;
}dat[MAX_N];
int _n;
void init(const int v);
void update(const int& left, const int& right, const int& x, int k, const int begin, const int end);
void push_mark(const int k);
int query(const int& left, const int& right, const int k, const int begin, const int end);

int lb[MAX_N], rb[MAX_N], q[MAX_N];

int main()
{
	int n, m;

	scanf("%d%d", &n, &m);

	init(n + 1);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", lb + i, rb + i, q + i);
		update(lb[i], rb[i], q[i], 0, 0, _n);
	}
	for (int i = 0; i < m; ++i)
	{
		int s = query(lb[i], rb[i], 0, 0, _n);
		if ((s & q[i]) != s)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
	{
		printf("%d%c", query(i, i, 0, 0, _n), i == n ? '\n' : ' ');
	}

	return 0;
}

void init(const int v)
{
	_n = 1;
	while (_n < v)
	{
		_n <<= 1;
	}
	--_n;
}

void update(const int& left, const int& right, const int& x, int k, const int begin, const int end)
{
	if (left <= begin && end <= right)
	{
		dat[k].v |= x;
		dat[k].f = true;
		while (k)
		{
			k = (k - 1) >> 1;
			dat[k].v = dat[(k << 1) + 1].v & dat[(k << 1) + 2].v;
		}
	}
	else if (left <= end && begin <= right)
	{
		push_mark(k);
		return update(left, right, x, (k << 1) + 1, begin, (begin + end) >> 1),
			update(left, right, x, (k << 1) + 2, ((begin + end) >> 1) + 1, end);
	}
}

void push_mark(const int k)
{
	if (k < _n && dat[k].f)
	{
		P& ls = dat[(k << 1) + 1];
		P& rs = dat[(k << 1) + 2];
		ls.f = rs.f = true;
		ls.v |= dat[k].v;
		rs.v |= dat[k].v;
	}
	dat[k].f = false;
}

int query(const int& left, const int& right, const int k, const int begin, const int end)
{
	if (left <= begin && end <= right)
	{
		return dat[k].v;
	}
	else if (left <= end && begin <= right)
	{
		push_mark(k);
		return query(left, right, (k << 1) + 1, begin, (begin + end) >> 1) & query(left, right, (k << 1) + 2, ((begin + end) >> 1) + 1, end);
	}
	else return -1;
}
