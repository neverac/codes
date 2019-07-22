#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n,i;
	long long int x,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		sum+=x;
	}
	printf("%lld\n",sum*sum);
	return 0;
}