#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;


int main()
{
	ll K, A, B;

	scanf("%lld%lld%lld", &K, &A, &B);

	ll ans = 1;

	if (B - A > 2)// 如果应该交换
	{
		if (A - 1 < K)// 如果可以达到交换
		{
			K -= A - 1;
			ans = A;
			ans += (K / 2) * (B - A);
			ans += K & 1;
			printf("%lld\n", ans);
		}
		else// 如果只能增加
		{
			printf("%lld\n", ans + K);
		}
	}
	else
	{
		printf("%lld\n", ans + K);
	}


	return 0;
}