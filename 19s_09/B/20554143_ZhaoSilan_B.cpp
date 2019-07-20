#include<stdio.h>
#include<iostream>
using namespace std;
const long long int MOD=998244353;
struct node
{
	long long int cnt;
	char c;
}p[200005];

int main()
{
	long long int len;
	scanf("%lld\n",&len);
	char tmp=0,c;
	int tot=0;
	for(long long int i=0;i<len;i++)
	{
		scanf("%c",&c);
		if(c==tmp)
		{
			p[tot].cnt++;
		}
		else
		{
			tot++;
			p[tot].c=c;
			p[tot].cnt=1;
		}
		tmp=c;
	}

	if(tot==1)
	printf("%lld\n",((len+1)*len/2+1)%MOD);
	else
	if(tot==2)
	{
		printf("%lld\n",(p[1].cnt+p[2].cnt+1)%MOD);
	}
	else
	if(p[1].c!=p[tot].c)
	{
		printf("%lld\n",(p[1].cnt+p[tot].cnt+1)%MOD);
	}
	else
	{
		printf("%lld\n",(p[1].cnt+1)*(p[tot].cnt+1)%MOD);
	}
	return 0;
}