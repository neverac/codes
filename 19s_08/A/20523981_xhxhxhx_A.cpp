#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 1000006;

int A[MAX_N];
int B[MAX_N];
int tb[50];
int pre[6];

int main()
{
	int n, x;
	tb[8] = 1;
	tb[15] = 2;
	tb[16] = 3;
	tb[23] = 4;
	tb[42] = 5;

	scanf("%d", &n);
	memset(pre, -1, sizeof(pre));

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		x = tb[x];
		A[i] = x;
	}
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		const int& cur = A[i];
		B[i] = pre[cur];
		pre[cur] = i;
	}
	bool can = true;
	while (can)
	{
		for (int i = 1; i < 6; ++i)
		{
			while (pre[i] != -1 && pre[i] < pre[i - 1])
			{
				pre[i] = B[pre[i]];
			}
			if (pre[i] == -1)
			{
				can = false;
				break;
			}
		}

		int add = 6;
		for (int i = 1; i < 6; ++i)
		{
			if (pre[i] <= pre[i - 1])
			{
				add = 0;
			}
		}
		if (add)
		{
			ans += add;
			for (int i = 0; i < 6; ++i)
			{
				pre[i] = B[pre[i]];
			}
			if (pre[0] == -1)
			{
				break;
			}
		}
	}
	ans = n - ans;

	printf("%d\n", ans);

	return 0;
}