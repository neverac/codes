#include <iostream>
using namespace std;

typedef long long ll;

bool C[20];

int main()
{
	ll p, q;
	scanf("%lld%lld", &p, &q);

	p %= q;
	
	for (int i = 0; i < 10000; i++)
	{
		p *= 10;
		C[p / q] = true;
		p %= q;
	}

	for (int i = 0; i < 10; i++)
	{
		if (C[i])
			printf("%d", i);
	}
	return 0;
}