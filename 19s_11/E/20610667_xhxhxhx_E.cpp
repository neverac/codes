#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
const int MAX_N = 100080;
int d[MAX_N];

bool C();
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", d + i);
	}
	d[n] = -1;
	int ss = 0, sj = 0;
	for (int i = 1; i < n; ++i)
	{
		if (d[i] < d[i - 1])
		{
			++ss;
		}
		else if (d[i] > d[i - 1])
		{
			++sj;
		}
	}

	if (ss == 0 || sj == 0)
	{
		printf("Nothing to do here\n");
		return 0;
	}

	if (ss == 1)
	{
		int p;
		for (p = 1; p < n; ++p)
		{
			if (d[p] < d[p - 1])
			{
				break;
			}
		}
		int p2 = p - 1;
		while (d[p + 1] == d[p])
		{
			++p;
		}
		swap(d[p], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p2 + 1, p + 1);
			return 0;
		}
		else
		{
			swap(d[p], d[p2]);
		}
		p = p2 + 1;
		while (p2 > 0 && d[p2 - 1] == d[p2])
		{
			--p2;
		}
		swap(d[p], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p2 + 1, p + 1);
			return 0;
		}
		else
		{
			swap(d[p], d[p2]);
		}
	}
	if (ss == 2)
	{
		int p1 = -1, p2;
		for (int i = 1; i < n; ++i)
		{
			if (d[i] < d[i - 1])
			{
				if (p1 < 0)
				{
					p1 = i;
				}
				else
				{
					p2 = i;
				}
			}
		}
		--p1;
		swap(d[p1], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p1 + 1, p2 + 1);
			return 0;
		}
		else
		{
			swap(d[p1], d[p2]);
		}
	}
	if (sj == 1)
	{
		int p;
		for (p = 1; p < n; ++p)
		{
			if (d[p] > d[p - 1])
			{
				break;
			}
		}
		int p2 = p - 1;
		while (d[p + 1] == d[p])
		{
			++p;
		}
		swap(d[p], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p2 + 1, p + 1);
			return 0;
		}
		else
		{
			swap(d[p], d[p2]);
		}
		p = p2 + 1;
		while (p2 > 0 && d[p2 - 1] == d[p2])
		{
			--p2;
		}
		swap(d[p], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p2 + 1, p + 1);
			return 0;
		}
		else
		{
			swap(d[p], d[p2]);
		}
	}
	if (sj == 2)
	{
		int p1 = -1, p2;
		for (int i = 1; i < n; ++i)
		{
			if (d[i] > d[i - 1])
			{
				if (p1 < 0)
				{
					p1 = i;
				}
				else
				{
					p2 = i;
				}
			}
		}
		--p1;
		swap(d[p1], d[p2]);
		if (C())
		{
			printf("Yes\n%d %d\n", p1 + 1, p2 + 1);
			return 0;
		}
		else
		{
			swap(d[p1], d[p2]);
		}
	}

	printf("No hope\n");

	return 0;
}

bool C()
{
	int da = 0, xi = 0;
	for (int i = 1; i < n; ++i)
	{
		if (d[i] > d[i - 1])
		{
			++da;
		}
		else if (d[i] < d[i - 1])
		{
			++xi;
		}
	}
	return da == 0 || xi == 0;
}

/*

11
1 2 3 4 5 7 6 5 8 9 10

10
1 2 8 4 5 6 7 3 9 10

9
7 6 5 4 4 5 3 2 1

8
10 9 8 4 5 3 2 1

*/