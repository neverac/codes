#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#define LL long long
using namespace std;

const int maxn = 3e5+100;

int n;
char s[105][1005];
int x,y,X,Y;
queue<int> Q;
int xx[5]={0,1,-1,0},yy[5] ={1,0,0,-1};
bool vis[1005][1005];
struct node
{
	int x,y;
};
node T[1001000],F[1001010];
int tot1,tot2;
void bfs1(int x,int y)
{
	Q.push(x);
	Q.push(y);
	vis[x][y]= true;
	while(!Q.empty())
	{
		int u = Q.front();Q.pop();
		int v = Q.front();Q.pop();
		T[++tot1].x=u;T[tot1].y=v; 
		for(int i=0;i<4;i++)
		{
			int U = u + xx[i];
			int V = v + yy[i];
			if(!vis[U][V]&&s[U][V]=='0')
			{
				vis[U][V] = true;
				Q.push(U);Q.push(V);
			}
		}
	}
}
void bfs2(int x,int y)
{
	Q.push(x);
	Q.push(y);
	vis[x][y]= true;
	while(!Q.empty())
	{
		int u = Q.front();Q.pop();
		int v = Q.front();Q.pop();
		F[++tot2].x=u;F[tot2].y=v; 
		for(int i=0;i<4;i++)
		{
			int U = u + xx[i];
			int V = v + yy[i];
			if(!vis[U][V]&&s[U][V]=='0')
			{
				vis[U][V] = true;
				Q.push(U);Q.push(V);
			}
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	scanf("%d",&n);
	scanf("%d%d%d%d",&x,&y,&X,&Y);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	bfs1(x,y);
	bfs2(X,Y);
	int ans = 1e9;
	for(int i=1;i<=tot1;i++)
	{
		for(int j=1;j<=tot2;j++)
		{
			ans= min(ans,(T[i].x-F[j].x)*(T[i].x-F[j].x) + (T[i].y-F[j].y)*(T[i].y-F[j].y));
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
1 3
3 1
010
100
000
 */