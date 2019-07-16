#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int a[MAXN][MAXN],b[MAXN][MAXN],h[MAXN][MAXN],l[MAXN][MAXN],s[MAXN][MAXN];
int Sum(int x,int y,int xx,int yy)
{
	return s[xx][yy]-s[x-1][yy]-s[xx][y-1]+s[x-1][y-1];
}
int main()
{
	int n,i,j,ll,rr,ans,mid,ans1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(i=0;i<=n;i++)a[0][i]=a[i][0]=-10;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!(a[i][j]==a[i-1][j]+1&&a[i][j]==a[i][j-1]+1))
			{
				b[i][j]=1;
			}
			if(!(a[i][j]==a[i][j-1]+1))h[i][j]=1;
			if(!(a[i][j]==a[i-1][j]+1))l[i][j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+b[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)h[i][j]+=h[i][j-1];
	}
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=n;i++)l[i][j]+=l[i-1][j];
	}
	
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)printf("%d ",h[i][j]);
		printf("\n");
	}*/
	
	ans1=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ll=1;rr=n;ans=0;
			while(ll<=rr)
			{
				mid=(ll+rr)/2;//mid=3;
				if(i+mid-1<=n&&j+mid-1<=n&&Sum(i+1,j+1,i+mid-1,j+mid-1)==0&&h[i][j+mid-1]-h[i][j]==0&&l[i+mid-1][j]-l[i][j]==0)
				{
					ans=mid;
					ll=mid+1;
				}
				else rr=mid-1;
			}
			ans1=max(ans1,ans);
		}
	}
	printf("%d",ans1);
	return 0;
}