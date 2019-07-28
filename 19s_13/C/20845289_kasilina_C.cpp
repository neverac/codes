#include <bits/stdc++.h>
using namespace std;
char mp[55][55];
int sx,sy,ex,ey;
int vis[2][55][55];
int n;
int tox[]={1,0,0,-1};
int toy[]={0,1,-1,0};
void dfs(int x,int y,int k)
{
	vis[k][x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+tox[i];
		int yy=y+toy[i];
		if(xx<=n&&xx>0&&yy<=n&&yy>0)
		{
			if(mp[xx][yy]=='0'&&!vis[k][xx][yy])
			{
				dfs(xx,yy,k);
			}
		}
	} 
}
int main()
{
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
	}
	dfs(sx,sy,0);
	dfs(ex,ey,1);
	long long op=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[0][i][j])
			{
				for(int k=1;k<=n;k++)
				{
					for(int l=1;l<=n;l++)
					{
						if(vis[1][k][l])
						{
							op=min(op,(long long)((i-k)*(i-k)+(j-l)*(j-l)));
						}
					}
				}
			}
		}
	}
	cout << op << endl;
    return 0;
}