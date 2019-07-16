#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int x,pos;
}a[200005];

bool cmp(node a,node b)
{
	return a.x>b.x;
}

bool cmp2(node a,node b)
{
	return a.pos<b.pos;
}

int main()
{
	int n,m,k,i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].pos=i;
	}
	int tt=k*m; 
	sort(a+1,a+n+1,cmp);
	

	long long int ans=0;
	for(i=1;i<=tt;i++)
	ans+=a[i].x;
	printf("%lld\n",ans);
//	for(i=1;i<=tt;i++)
//	{
//		printf("%d %d\n",a[i].x,a[i].pos);
//	//	a[i].pos=i;
//	}
	sort(a+1,a+tt+1,cmp2);
    
//	for(i=1;i<=tt;i++)
//	printf("%d %d\n",a[i].x,a[i].pos);
	
	for(i=m;i<tt;i+=m)
	printf("%d ",a[i].pos);
	
	return 0;
	
}