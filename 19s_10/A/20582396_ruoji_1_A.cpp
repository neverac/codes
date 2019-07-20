#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
struct node
{
	int x,y,dis;
};
queue<node> q;
int fx[6]={-1,1,0,0};
int fy[6]={0,0,-1,1};
char s[1010][1010];
int a[1010][1010];
bool vis[1010][1010];
int main()
{
	int n,m,i,j,xx,yy,xx1,yy1,ans,dd;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)scanf("\n%s",s[i]+1);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)a[i][j]=INF;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(vis[i][j]==false&&s[i][j]=='#')
			{
				q.push((node){i,j,0});
				vis[i][j]=true;
				a[i][j]=0;
			}
		}
	}
	
	while(!q.empty())
	{
		node T=q.front();q.pop();
		xx=T.x;yy=T.y;//dd=T.dis;
		vis[xx][yy]=false;
		for(i=0;i<=3;i++)
		{
			xx1=xx+fx[i];
			yy1=yy+fy[i];
			if(a[xx1][yy1]>a[xx][yy]+1)
			{
				a[xx1][yy1]=a[xx][yy]+1;
				if(vis[xx1][yy1]==false)
				{
					vis[xx1][yy1]=true;
					q.push((node){xx1,yy1,a[xx1][yy1]});
				}
			}
		}
	}
	
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)ans=max(ans,a[i][j]);
	}
	printf("%d",ans);
	return 0;
}