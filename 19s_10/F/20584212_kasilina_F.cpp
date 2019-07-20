#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s,t;
int mp[1005][1005];
int d1[1005],d2[1005];
struct node{
	int d,id;
	friend bool operator<(node a,node b)
	{
		return a.d>b.d;
	}
};
int vis[1005];
void dj(int s,int d[])
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	d[i]=inf;
	d[s]=0;
	priority_queue<node>q;
	node p;
	p.d=0;
	p.id=s;
	q.push(p);
	while(!q.empty())
	{
		p=q.top();
		q.pop();
		if(vis[p.id]) continue;
		vis[p.id]=1;
		for(int i=1;i<=n;i++)
		{
			if(mp[p.id][i]&&d[i]>d[p.id]+1)
			{
				d[i]=d[p.id]+1;
				node a;
				a.d=d[i];
				a.id=i;
				q.push(a);
			}
		}
	}
}
int main()
{
	int v,u;
	cin >> n >> m >> s >> t;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=mp[v][u]=1;
	}
	dj(s,d1);
	dj(t,d2);
	int op=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(d1[i]+d2[j]+1>=d1[t]&&d1[j]+d2[i]+1>=d1[t])
			op++;
		}
	}
	printf("%d\n",op-m);
    return 0;
}