#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	LL T,l,r;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&l,&r);
		printf("%lld %lld\n",l,l*2LL);
	}
	return 0;
}