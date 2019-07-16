#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int a[1005][1005],c[1005][1005],d[1005][1005],e[1005][1005],f[1005][1005],g[1005][1005];
int b[1005][1005];
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a[i][j]);
	}
	bool flag;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(a[i][j]+1==a[i+1][j]&&a[i][j]+1==a[i][j+1])
		b[i][j]=1;
		else
		if(a[i][j]+1==a[i+1][j])
		b[i][j]=2;
		else
		if(a[i][j]+1==a[i][j+1])
		b[i][j]=3;		
	}
//	for(i=1;i<=n;i++)
//	{
//	for(j=1;j<=n;j++)
//	printf("%d ",b[i][j]);
//    printf("\n");
//	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(b[i][j]==1)
		f[i][j]=f[i][j-1]+1;
		else
		f[i][j]=1;
		
		if(b[i][j]==1||b[i][j]==3)
		c[i][j]=c[i][j-1]+1;
		else
		c[i][j]=1;
	}//满足列之间的关系
//	printf("\n");
//	for(i=1;i<=n;i++)
//	{
//	for(j=1;j<=n;j++)
//	printf("%d ",f[i][j]);
//    printf("\n");
//	}
		
	for(j=1;j<=n;j++)
	for(i=1;i<=n;i++)
	{
		if(b[i][j]==1)
		g[i][j]=g[i-1][j]+1;
		else
		g[i][j]=1; 
		
		if(b[i][j]==1||b[i][j]==2)
		d[i][j]=d[i-1][j]+1;
		else
		d[i][j]=1;
	}//每一列的最大连续子段
//	 printf("\n");
//	 for(i=1;i<=n;i++)
//	{
//	for(j=1;j<=n;j++)
//	printf("%d ",g[i][j]);
//    printf("\n");
//	}
//	printf("\n");
	int ans=0;
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
		if(b[i][j])
		e[i][j]=min(min(e[i-1][j-1]+1,f[i][j]),g[i][j]);
		else
		e[i][j]=0;
//		printf("%d ",e[i][j]);
		ans=max(ans,min(min(e[i-1][j-1]+1,c[i][j-1]+1),d[i-1][j]+1));
	}
//	printf("\n");
   }
	printf("%d\n",ans);
	return 0;
}