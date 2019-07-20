#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
struct node{
	int v,nxt;
}e[400005];
int head[200005],cnt=0;
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int vis[200005];
int ans=0;
int s;
void dfs(int x,int step)
{
	if(step>ans) ans=step,s=x;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v,step+1);
		}
	}
}
int main()
{
	cin >> n;
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	ans=0;
	for(int i=1;i<=n;i++)
	vis[i]=0;
	dfs(s,0);
	if(ans%3==1) printf("Second\n");
	else printf("First\n");
    return 0;
}