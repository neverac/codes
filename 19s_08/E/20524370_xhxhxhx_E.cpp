#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 106;



int cnt[5];

int main()
{
	int t, n, x;
	scanf("%d", &t);


	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));

		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			++cnt[x % 3];
		}
		if (cnt[1] > cnt[2])
		{
			swap(cnt[1], cnt[2]);
		}
		cnt[0] += cnt[1] + (cnt[2] - cnt[1]) / 3;
		printf("%d\n", cnt[0]);
	}
	return 0;
}