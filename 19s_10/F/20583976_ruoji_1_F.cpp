#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mp make_pair 
#define fir first 
#define sec second 
#define pii pair<int,int> 
priority_queue<pii,vector<pii>,greater<pii> > q; 
struct node
{
	int begin,end,next;
}edge[2010];
int cnt,Head[1010],dis[1010],dis1[1010],n;
void addedge(int bb,int ee)
{
	edge[++cnt].begin=bb;edge[cnt].end=ee;edge[cnt].next=Head[bb];Head[bb]=cnt;
}
void addedge1(int bb,int ee)
{
	addedge(bb,ee);addedge(ee,bb);
}
void dijkstra(int start) 
{ 
    int i,u,v; 
    while(!q.empty())q.pop();
	for(i=1;i<=n;i++)dis[i]=INF;dis[start]=0; 
    q.push(mp(dis[start],start)); 
    while(!q.empty()) 
    { 
        u=q.top().sec;q.pop(); 
        for(i=Head[u];i!=-1;i=edge[i].next) 
        { 
            v=edge[i].end; 
            if(dis[v]>dis[u]+1){dis[v]=dis[u]+1;q.push(mp(dis[v],v));} 
        } 
    } 
}

void dijkstra1(int start) 
{ 
    int i,u,v; 
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++)dis1[i]=INF;dis1[start]=0; 
    q.push(mp(dis1[start],start)); 
    while(!q.empty()) 
    { 
        u=q.top().sec;q.pop(); 
        for(i=Head[u];i!=-1;i=edge[i].next) 
        { 
            v=edge[i].end; 
            if(dis1[v]>dis1[u]+1){dis1[v]=dis1[u]+1;q.push(mp(dis1[v],v));} 
        } 
    } 
}
int main()
{
	int m,i,u,v,s,t,dd,ans=0LL,j;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	memset(Head,-1,sizeof(Head));cnt=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		addedge1(u,v);
	}
	
	dijkstra(s);
	dijkstra1(t);
	dd=dis[t];
	
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(dis[i]+1+dis1[j]>=dd&&dis1[i]+1+dis[j]>=dd)ans++;
		}
	}
	printf("%d",ans-m);
	return 0;
}