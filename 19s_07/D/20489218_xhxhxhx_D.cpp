#include <iostream>
using namespace std;


const int MAX_N = 1005;

char ch[MAX_N];
bool a[MAX_N];

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		scanf(" \n%s", ch);
		int N = -1;
		while (ch[++N])
		{
			a[N] = ch[N] == '1';
		}
		int ans = N;
		for (int i = 0; i <= N; ++i)
		{
			int m = 0;
			for (int j = 0; j < i; ++j)
			{
				m += a[j];
			}
			for (int j = i; j < N; ++j)
			{
				m += !a[j];
			}
			if (m < ans)
			{
				ans = m;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
