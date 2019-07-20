#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
	LL K,A,B;
	scanf("%lld %lld %lld",&K,&A,&B);
	K++;
	if(B-A<2LL)printf("%lld",K);
	else
	{
		if((K-A)%2LL==0LL)
		{
			printf("%lld",A+(((K-A)/2LL)*(B-A)));
		}
		else
		{
			printf("%lld",A+(((K-A)/2LL)*(B-A))+1LL);
		}
	}
	return 0;
}