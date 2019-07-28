#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N = 200009;

int p[MAX_N][2];

int main()
{
	memset(p, -1, sizeof(p));
	int N, x;
	scanf("%d", &N);
	int n2 = N << 1;

	for (int i = 0; i < n2; ++i)
	{
		scanf("%d", &x);
		if (~p[x][0])
		{
			p[x][1] = i;
		}
		else
		{
			p[x][0] = i;
		}
	}
	ll ans = 0;

	int p1 = 0, p2 = 0;
	for (int i = 1; i <= N; ++i)
	{
		int s1 = abs(p[i][0] - p1) + abs(p[i][1] - p2);
		int s2 = abs(p[i][1] - p1) + abs(p[i][0] - p2);
		ans += min(s1, s2);
		p1 = p[i][0];
		p2 = p[i][1];
	}
	printf("%lld\n", ans);

	return 0;
}