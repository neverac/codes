#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,i;
int a[100005],b[100005],pos[100005],pos1[100005];

bool cmp(int a,int b)
{
	return b<a;
}

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a,a+n);
	int tmp=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		pos[tmp++]=i+1;
	}
	
	sort(a,a+n,cmp);
	
	int tmp1=0;
	for(i=0;i<n;i++)
	{
//		printf("%d ",a[i]);
		if(a[i]!=b[i])
		pos1[tmp1++]=i+1;
	}
	
	if(tmp==0||tmp1==0)
	{
		printf("Nothing to do here\n");
	}
	else
	if(tmp==2)
	{
		printf("Yes\n");
		printf("%d %d",pos[0],pos[1]);
	}
	else
	if(tmp1==2)
	{
		printf("Yes\n");
		printf("%d %d",pos1[0],pos1[1]);
	}
	else
	{
		printf("No hope\n");
	}
	return 0;
}