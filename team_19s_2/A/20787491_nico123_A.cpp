#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;
int A[MAX_N];
int B[MAX_N];

int dat[1 << 12], _n;
void init(const int n);
int query(const int& left, const int& right, const int k, const int begin, const int end);


int main()
{
	int n, d;

	while (~scanf("%d", &n))
	{
		if (!n)
		{
			break;
		}
		scanf("%d", &d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", A + i);
		}
		if (n <= 2)
		{
			printf("Y\n");
			continue;
		}
		memset(B, 0, sizeof(B));
		for (int i = 1; i < n; i++)
		{
			B[i - 1] = abs(A[i] - A[i - 1]);
		}
		init(n - 1);

		bool C = false;
		if (query(1, n - 2, 0, 0, _n) <= d)
		{
			printf("Y\n");
			continue;
		}
		if (query(0, n - 3, 0, 0, _n) <= d)
		{
			printf("Y\n");
			continue;
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (abs(A[i + 1] - A[i - 1]) <= 2 * d && query(0, i - 2, 0, 0, _n) <= d && query(i + 1, n - 2, 0, 0, _n) <= d)
			{
				C = true;
				break;
			}
		}
		if (C)
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}

	return 0;
}

void init(const int n)
{
	memset(dat, 0, sizeof(dat));
	_n = 1;
	while (_n < n)
	{
		_n <<= 1;
	}
	--_n;

	for (int i = 0; i < n; i++)
	{
		dat[_n + i] = B[i];
	}
	for (int i = _n - 1; i >= 0; i--)
	{
		dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
	}
}

int query(const int& left, const int& right, const int k, const int begin, const int end)
{
	if (left > right) return 0;

	if (left <= begin && end <= right)
	{
		return dat[k];
	}
	else if (left <= end && begin <= right)
	{
		int ls = query(left, right, (k << 1) + 1, begin, (begin + end) >> 1);
		int rs = query(left, right, (k << 1) + 2, ((begin + end) >> 1) + 1, end);
		return max(ls, rs);
	}
	return 0;
}
