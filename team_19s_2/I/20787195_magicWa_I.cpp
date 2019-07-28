#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e5+100;
const int inf =  1e9;

int n,m;

struct edge
{
	int u,v,flow,cap;
};
vector<edge> f;
vector<int> G[maxn];

bool vis[maxn];
int cur[maxn],d[maxn],S,T;

void add(int u,int v,int cap)
{
	f.push_back((edge){u,v,0,cap});
	f.push_back((edge){v,u,0,0});
	int m = f.size();
	G[u].push_back(m-2);
	G[v].push_back(m-1);
}

bool bfs()
{
	queue<int> Q;
	memset(vis,0,sizeof(vis));
	Q.push(S);
	d[S] = 0;vis[S] = 1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			edge& e = f[G[u][i]];
			if(!vis[e.v]&&e.cap>e.flow)
			{
				d[e.v] = d[u]+1;
				Q.push(e.v);
				vis[e.v] = true;
			}
		}
	}
	return vis[T];
}

int dfs(int u,int a)
{
	int flow = 0 , h;
	if(u==T||a==0) return a;
	for(int &i = cur[u];i<G[u].size();i++)
	{
		edge& e =f[G[u][i]];
		if(d[u]+1==d[e.v]&&(h = dfs(e.v, min(a,e.cap-e.flow)))>0 )
		{
			e.flow += h;
			f[G[u][i]^1].flow-=h;
			flow+=h;
			a-=h;
			if(a==0) break;
		}
	}
	return flow;
}
int Maxflow(int s,int t)
{
	int flow = 0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,inf);
		//cout<<flow<<" FLOW"<<endl;
	}
	return flow;
}
void clear()
{
	f.clear();
	for(int i=0;i<(n+m*2);i++) G[i].clear();
	memset(d,0,sizeof(d));
}

int k;
int x,y;
int main()
{
	while(cin>>m)
	{
		if(m==0) return 0;
		cin>>n>>k;
		S = n+m+1;T =n+m+2; 
		clear();
		for(int i=0;i<m;i++) add(S,i,1);
		for(int j=0;j<n;j++) add(j+m,T,1);
		for(int i=1;i<=k;i++)
		{
			cin>>x>>y;
			add(x,y+m,1);
		}
		int ans = Maxflow(S,T);
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 
3 
6 
0 0 
0 1 
1 0 
1 1 
1 2 
2 1 
4 
4 
7 
0 0 
0 2 
1 1 
1 3 
2 0 
2 2 
3 3 
0 
 */