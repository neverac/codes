#include<stdio.h>
#include<iostream>
using namespace std;
long long int ans[1000005],ans1[1000005];
typedef long long int ll;
int main()
{
	long long int i;
	int t;
	scanf("%d",&t);
	ans[1]=1;
	ans[2]=5;
	ans[3]=13;
	for(i=4;i<=1000000;i++)
	{
		ans[i]=ans[i-1]+2ll*i-1+i*(i-1ll)/2ll;//正三角
		ans1[i]=ans1[i-2]+(i-2ll)*(i-3ll)/2ll;//倒三角 
	}
	long long int n;
	while(t--)
	{
	   scanf("%lld",&n);
	   printf("%lld\n",ans[n]+ans1[n]);
	}	
	return 0;
} 