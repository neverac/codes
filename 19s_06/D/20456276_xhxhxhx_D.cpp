#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
	int x, y, z;// 需求
	int a, b, c;// 有的

	scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);

	a -= x;
	if (a >= 0)
	{
		y -= a;
		b -= y;
		if (b >= 0)
		{
			z -= b + c;
			if (z <= 0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		printf("NO\n");
	}

	

	return 0;
}