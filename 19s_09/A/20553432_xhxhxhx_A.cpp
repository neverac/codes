#include <iostream>
using namespace std;



int main()
{
	int T;
	int l, r;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &l, &r);
		printf("%d %d\n", r / 2, r & -2);
	}


	return 0;
}
