#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
char s[1105][1105];
bool vis[1105][1105],vis1[1005][1005];
int n,m,ans;

int X[10]={0,-1,1,0},Y[10]={1,0,0,-1};

queue<int> Q;

int bfs()
{
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		int y = Q.front();
		Q.pop();
		int step = Q.front();
		Q.pop();
		ans++;
		if(ans==n*m)
		{
			return step;
		}
		for(int i=0;i<4;i++)
		{
			int xx = x+X[i];
			int yy = y+Y[i];
			if(xx<=n&&xx>=1&&yy<=m&&yy>=1)
			{
				if(!vis[xx][yy])
				{
					vis[xx][yy] =true;
					Q.push(xx);Q.push(yy);
					Q.push(step+1);
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#'){
				Q.push(i);Q.push(j);vis[i][j]=true;
				Q.push(0);
			}
		}
	}
	cout<<bfs()<<endl;
	return 0;
}
