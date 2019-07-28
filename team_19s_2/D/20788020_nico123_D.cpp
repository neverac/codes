#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int f[210][210],ans[50010];
int main()
{
	int n,m,i,u,v,j,k,mx;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d",&m);
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)f[i][j]=INF;
			f[i][i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			u++;v++;
			f[u][v]=f[v][u]=1;
		}
		for(i=1;i<=n;i++)f[i][i]=0;
		for(k=1;k<=n;k++)
	    {
	        for(i=1;i<=n;i++)
	        {
	            for(j=1;j<=n;j++)
	            {
	                if(f[i][j]>f[i][k]+f[k][j]&&i!=j&&j!=k&&i!=k)f[i][j]=f[j][i]=f[i][k]+f[k][j];
	            }
	        }
	    }
	    memset(ans,0,sizeof(ans));
	    mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j)
				{
					ans[f[i][j]]++;
					mx=max(mx,f[i][j]);
				}
			}
		}
		for(i=1;i<=mx;i++)
		{
			printf("%d %d\n",i,ans[i]);
		}
	}
	return 0;
}