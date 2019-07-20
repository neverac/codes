#include <iostream>
using namespace std;

typedef long long ll;


int main()
{
	int T, ang;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &ang);
		if (ang == 179)
		{
			printf("360\n");
			continue;
		}
		int tr;
		for (tr = 3; tr <= 180; ++tr)
		{
			double x = 180.0 / tr;

			if (abs(ang / x - (int)(ang / x)) < 1e-10 && ang / x <= (tr - 2) + 1e-10)
			{
				printf("%d\n", tr);
				break;
			}
		}
		if (tr == 181)
		{
			printf("-1\n");
		}
	}


	return 0;
}
