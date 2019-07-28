#include <iostream>
using namespace std;



int main()
{
	int N, x;
	scanf("%d", &N);

	int a = 0, b = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		if (x < 0)
		{
			++a;
		}
		else if (x > 0)
		{
			++b;
		}
	}
	
	if (2 * a >= N)
	{
		printf("-2\n");
	}
	else if (2 * b >= N)
	{
		printf("2\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}