#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main()
{
	int T,n,m,i,j,k,ans,u,v,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		m=n*(n-1)/2;
		for(j=1;j<=m;j++)
		{
			scanf("%d %d %d",&u,&v,&w);
			a[v][u]=a[u][v]=w;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(i!=j&&i!=k&&j!=k)
					{
						ans=max(ans,a[i][j]+a[i][k]+a[j][k]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}