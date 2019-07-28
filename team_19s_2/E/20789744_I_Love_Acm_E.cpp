#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int v,w,next;
}g[200100];
//存储边
//next为上一个边的序号（若只有一条则为0）
int head[200100];
//每个出去的点的最后一个边的序号
int cnt,kk;
#define inf 0x7fffffff

void add(int u,int v,int w)//加点
{
	g[cnt].v=v;
	g[cnt].w=w;
	g[cnt].next=head[u];
	head[u]=cnt;
	cnt++;

}

int n,m,x,y,z;
int ans,flow;
int dis[200100];
queue<int> q;
int S,T;

void init()//初始化
{
	memset(head,-1,sizeof(head));
    memset(g,0,sizeof(g));
    cnt=0;
    memset(dis,-1,sizeof(dis));
    while(!q.empty()) q.pop();
    ans=0;
}
int bfs()//广搜给图分层
{
	memset(dis,-1,sizeof(dis));
	while(!q.empty()) q.pop();
	dis[S]=0;
	q.push(S);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (int i=head[u];i!=-1;i=g[i].next){
			int v=g[i].v;
			if (dis[v]==-1&&g[i].w>0){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[T]!=-1;
}

int dfs(int u,int exp)//深搜找增广路
{
	if (u==T) return exp;
	int flow=0,tmp=0;
	for (int i=head[u];i!=-1;i=g[i].next){
		int v=g[i].v;
		if ((dis[v]==(dis[u]+1))&&(g[i].w>0)){
			tmp=dfs(v,min(exp,g[i].w));
			if (tmp==0) continue;

			exp-=tmp;
			flow+=tmp;

			g[i].w-=tmp;
			g[i^1].w+=tmp;

		if (!exp) break;
		}
	}
	return flow;
}

int main()
{
	int te;
	cin>>te;
	while (te--){
	cin>>n>>m>>S>>T>>kk;
	init();
	for (int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v,1);
		add(v,u,1);
		//add(v,u,0);
	}
	while (bfs())
		ans+=dfs(S,inf);
    //cout<<ans<<endl;
	cout<<(kk+2)/3*ans<<endl;
	}
	return 0;
}
