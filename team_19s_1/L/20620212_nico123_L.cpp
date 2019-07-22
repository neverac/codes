#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;


int main()
{
	int T, n;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);
		int a, b;
		scanf("%d", &a);

		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		for (int i = 2; i < n; ++i)
		{
			scanf("%d", &b);
		}
		scanf("%d", &b);

		printf("%d\n", (int)sqrt(a > b ? a - b : b - a));
	}
	return 0;
}
