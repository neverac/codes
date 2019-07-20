#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 200009;

char ch[MAX_N];

int main()
{
	int len;
	scanf("%d \n%s", &len, ch);

	int p1 = 0;
	char mm = ch[0];
	for (; ch[p1] == mm; ++p1);

	if (p1 == len)
	{
		printf("%lld\n", ((ll)len * (len + 1) / 2) % 998244353);
		return 0;
	}

	int p2 = len - 1;
	char mr = ch[p2];
	for (; ch[p2] == mr; --p2);

	int mid = p2 - p1 + 1;
	p2 = len - 1 - p2;

	if (mm == mr)
	{
		printf("%lld\n", ((ll)(p1 + 1) * (p2 + 1)) % 998244353);
	}
	else
	{
		printf("%lld\n", ((ll)(p1 + p2 + 1)) % 998244353);
	}

	return 0;
}
