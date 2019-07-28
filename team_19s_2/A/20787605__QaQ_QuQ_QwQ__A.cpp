#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[1005];
int main()
{
	int n,d,cnt;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&d);
		bool flag=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		int pos1=-1,pos2=-1,cnt=0;
		for(int i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1])<=d)
			continue;
			
			cnt++; 
			if(pos1==-1)
			pos1=i;
			else
			if(pos2==-1)
			{
				pos2=i;
			}
		}
		
		if(cnt>2)
		flag=1;
		else
		if(pos1!=-1&&pos2!=-1)
		{
			if(pos2!=pos1+1)
			flag=1;
			else
			{
				if(abs(a[pos1-1]-a[pos1+1])<=2*d)
				flag=0;
				else
				flag=1;
			}
		}
		else
		if(pos1!=-1)
		{
			if(pos1==2||pos1==n)
			flag=0;
			else
			if(abs(a[pos1-1]-a[pos1+1])<=2*d||abs(a[pos1]-a[pos1-2])<=2*d)
			flag=0;
			else
			flag=1;
		}
		else flag=0;
		
		if(flag)
		printf("N\n");
		else
		printf("Y\n");
	}
	return 0;
}