#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{int to,next,flow;};
node a[300007];int q[10007];int n,m,s,t,tot,maxflow,LLL,T;
int low[10007],pre[10007];
void add(int x,int y)
{++tot;a[q[x]].next=tot;q[x]=tot;a[tot].to=y;a[tot].flow=1;a[tot].next=0;
++tot;a[q[y]].next=tot;q[y]=tot;a[tot].to=x;a[tot].flow=0;a[tot].next=0;}
bool bfs()
{queue<int>que;bool v[10007]={0};
v[s]=1;low[s]=0x3f3f3f3f;que.push(s);
while(!que.empty())
{int u=que.front();
que.pop();
for(int i=a[u].next;i!=0;i=a[i].next)
{if(a[i].flow!=0&&v[a[i].to]==0)
{v[a[i].to]=1;pre[a[i].to]=i;
que.push(a[i].to);
low[a[i].to]=min(low[u],a[i].flow);}}}
return v[t];
}
void update()
{maxflow+=low[t];
int x=t;
while(x!=s)
{int i=pre[x];
a[i].flow-=low[t];
a[1^i].flow+=low[t];
x=a[1^i].to;}
}
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
memset(low,0,sizeof(low));
memset(pre,0,sizeof(pre));
tot=0;maxflow=0;
cin>>n>>m>>s>>t>>LLL;
for(int i=1;i<=n;++i)q[i]=i;
if(n%2==1)tot=n;
else tot=n+1;
for(int i=1;i<=m;++i)
{int x,y;scanf("%d%d",&x,&y);
add(x,y);add(y,x);}
while(bfs())update();
cout<<maxflow*((LLL-1)/3+1)<<endl;

}
return 0;
}