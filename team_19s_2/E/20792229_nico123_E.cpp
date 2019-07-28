#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int S,T,n,q[1050];
struct node
{
	int begin,end,value,next;
}edge[42010];
int cnt,Head[1050];
int dis[1050],cur[1050];
void addedge(int bb,int ee,int vv)
{
    edge[++cnt].begin=bb;edge[cnt].end=ee;edge[cnt].value=vv;edge[cnt].next=Head[bb];Head[bb]=cnt;
}
void addedge1(int bb,int ee,int vv)
{
    addedge(bb,ee,vv);addedge(ee,bb,0);
}
int BFS() 
{ 
    int head,tail,u,v,i; 
    head=0;tail=1;q[tail]=S; 
    memset(dis,-1,sizeof(dis));dis[S]=0; 
    while(head!=tail) 
    { 
        head++;if(head==1010)head=0; 
        u=q[head]; 
        for(i=Head[u];i!=-1;i=edge[i].next) 
        { 
            v=edge[i].end; 
            if(edge[i].value>0&&dis[v]<0) 
            { 
                dis[v]=dis[u]+1; 
                tail++;if(tail==1010)tail=0; 
                q[tail]=v; 
            } 
        } 
    } 
    if(dis[T]<=0)return 0; 
    else return 1; 
} 
int DFS(int u,int minflow) 
{ 
    int used=0,ans=0,i,v; 
    if(u==T)return minflow; 
    for(i=cur[u];i!=-1;i=edge[i].next) 
    { 
        v=edge[i].end; 
        if(edge[i].value>0&&dis[v]==dis[u]+1) 
        { 
            ans=minflow-used; 
            ans=DFS(v,min(ans,edge[i].value)); 
            edge[i].value-=ans; if(edge[i].value>0)cur[u]=i;
            edge[i^1].value+=ans; 
            used+=ans; 
            if(used==minflow)return minflow; 
        } 
    } 
    if(used==0)dis[u]=-1; 
    return used; 
} 
int Dinic() 
{ 
    int ans,i,maxflow=0; 
    while(BFS()){for(i=1;i<=n;i++)cur[i]=Head[i];ans=DFS(S,INF);if(ans==0)break;maxflow+=ans;} 
    return maxflow; 
} 
int main()
{
	int TT,m,K,i,u,v,ans;
	scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d %d %d %d %d",&n,&m,&S,&T,&K);
		memset(Head,-1,sizeof(Head));cnt=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			addedge1(u,v,1);
			addedge1(v,u,1);
		}
		ans=Dinic();
		if(K%3==0)K=K/3;
		else K=K/3+1;
		printf("%lld\n",1LL*ans*K);
	}
	return 0;
}