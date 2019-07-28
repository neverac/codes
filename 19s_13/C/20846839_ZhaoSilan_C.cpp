#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int ax[3000],ay[3000],bx[3000],by[3000],a[100][100],n;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool pd[100][100];
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(!pd[nx][ny]&&nx<=n&&nx>=1&&ny<=n&&ny>=1&&a[nx][ny]==0)
		{
			pd[nx][ny]=1;
			dfs(nx,ny);
		}
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	int x1,x2,y1,y2;
	char s[100];
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
	for(int j=1;j<=n;j++)
	{
		a[i][j]=s[j-1]-48;
	}
    }
	pd[x2][y2]=1;
	dfs(x2,y2);
	
	if(pd[x1][x2])
	{
		printf("0\n");
		return 0;
	}
	else
	{
		int tot=0;
	    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(pd[i][j])
		ax[tot]=i,ay[tot]=j,tot++;
		
		memset(pd,0,sizeof(pd));

		pd[x1][y1]=1;
		dfs(x1,y1);
		
//	for(int i=1;i<=n;i++)
//	{
//	for(int j=1;j<=n;j++)
//	printf("%d",pd[i][j]);
//	printf("\n");
//   }

		int tmp=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(pd[i][j])
		bx[tmp]=i,by[tmp]=j,tmp++;
		
		int ans=2147483647;
		for(int i=0;i<tot;i++)
		for(int j=0;j<tmp;j++)
		{
			int dis=(ax[i]-bx[j])*(ax[i]-bx[j])+(ay[i]-by[j])*(ay[i]-by[j]);
			ans=min(ans,dis);
		}
		printf("%d\n",ans);
	}
	return 0;
}