#include <iostream>
using namespace std;

const int MAX_N = 1005;

int A[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

bool C(const int& x, const int& y);
int _min(int a, const int& b, const int& c);

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", A[i] + j);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		dp[N][i] = dp[i][N] = 1;
	}

	for (int d = N - 1; d; --d)
	{
		for (int i = d; i; --i)
		{
			if (C(i, d))
			{
				dp[i][d] = _min(dp[i][d + 1], dp[i + 1][d], dp[i + 1][d + 1]) + 1;
			}
			else
			{
				dp[i][d] = 1;
			}
		}
		for (int j = d - 1; j; --j)
		{
			if (C(d, j))
			{
				dp[d][j] = _min(dp[d][j + 1], dp[d + 1][j], dp[d + 1][j + 1]) + 1;
			}
			else
			{
				dp[d][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (dp[i][j] > ans)
			{
				ans = dp[i][j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

bool C(const int& x, const int& y)
{
	return A[x][y] == A[x][y + 1] - 1
		&& A[x][y] == A[x + 1][y] - 1
		&& A[x][y] == A[x + 1][y + 1] - 2;
}

int _min(int a, const int& b, const int& c)
{
	if (b < a)
	{
		a = b;
	}
	if (c < a)
	{
		a = c;
	}
	return a;
}
