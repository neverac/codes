#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5+100;
int n,m,s,t,x,y;
vector<int> f[maxn];
queue<int> Q1,Q2;
int distS[maxn],distT[maxn];
bool vis[maxn];
bool check[1005][1005];
void bfs()
{
	Q1.push(s);
	memset(vis,0,sizeof(vis));
	vis[s] = true;
	while(!Q1.empty())
	{
		int u=Q1.front();
		Q1.pop();
		for(int i=0;i<f[u].size();i++)
		{
			int v=f[u][i];
			if(!vis[v])
			{
				vis[v]=true;
				Q1.push(v);
				distS[v] = distS[u]+1;
			}
		}
	}
}
void bfs1()
{
	Q2.push(t);
	memset(vis,0,sizeof(vis));
	vis[t] = true;
	while(!Q2.empty())
	{
		int u=Q2.front();
		Q2.pop();
		for(int i=0;i<f[u].size();i++)
		{
			int v=f[u][i];
			if(!vis[v])
			{
				vis[v]=true;
				Q2.push(v);
				distT[v] = distT[u]+1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
		check[x][y] =true;check[y][x] =true;
	}
	bfs();bfs1();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(check[i][j]) continue;
			if(distS[i]+distT[j]+1>=distS[t]&&distS[j]+distT[i]+1>=distS[t]){
				//cout<<distS[i]<<" "<<distT[j]<<endl;
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}