#include <bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
int n,m,s,t,k;
struct node{
	int v,w,nxt,k;
}e[210000];
int cnt=-1;
int head[10015],cur[10015],d[10015];
void add(int u,int v,int w,int k)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].k=k;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfs(int u,int a)
{
	if(u==t) return a;
	int a1=0,a2;
	for(int& i=cur[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(d[v]==d[u]+1&&e[i].k>e[i].w)
		{
			a2=dfs(v,min(a,e[i].k-e[i].w));
			a-=a2;
			e[i].w+=a2;
			a1+=a2;
			e[i^1].w-=a2;
			if(!a)
			break;
		}
	}
	if(!a1) d[u]=-1;
	return a1;
}
bool bfs()
{
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].v;
			if(d[v]==-1&&e[i].k>e[i].w)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[t]!=-1;
}
int dinic()
{
	int m=0;
	while(bfs())
	{
		for(int i=1;i<=n;i++)
		cur[i]=head[i];
		m+=dfs(s,inf);
	}
	return m;
}
int main()
{
	int q;
	int a,b;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
		memset(e,0,sizeof(e));
		cnt=-1;
		memset(head,-1,sizeof(head));
		k = ceil(k * 1.0 / 3);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b,0,k);
			add(b,a,0,k);
		}
		cout << dinic() << endl;
	}
	return 0;	 
}