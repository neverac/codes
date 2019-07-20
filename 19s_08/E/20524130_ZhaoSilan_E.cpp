#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int a[10];
int main()
{
	int i,t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		int ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x%3==0)
			ans++;
			else
			a[x%3]++;
		}
		int t=min(a[1],a[2]);
		int t1=(a[1]-t)/3;
		int t2=(a[2]-t)/3;
		printf("%d\n",ans+t+t1+t2);
	}
	return 0;
}