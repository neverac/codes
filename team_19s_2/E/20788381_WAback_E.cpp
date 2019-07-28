#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define INF 0x7fffffff

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

#define MAXN 10010

int N,M,S,T,K;

struct EdgeNode{
    int next,to,cap;
}edge[1000010];
int head[MAXN],cnt=1;
inline void AddEdge(int u,int v,int w) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v; edge[cnt].cap=w;}
inline void InsertEdge(int u,int v,int w) {/*printf("<%d,%d>%d\n",u,v,w);*/ AddEdge(u,v,w); AddEdge(v,u,0);}
 
int h[MAXN],cur[MAXN];
queue<int>q;
inline bool Bfs()
{
    for (int i=1; i<=N; i++) h[i]=-1;
    q.push(S); h[S]=0;
    while (!q.empty()) {
        int now=q.front(); q.pop();
        for (int i=head[now]; i; i=edge[i].next)
            if (edge[i].cap && h[edge[i].to]==-1)
                h[edge[i].to]=h[now]+1,q.push(edge[i].to);
    }
    return h[T]!=-1;
}
  
inline int Dfs(int now,int low)
{
    if (now==T) return low;
    int w,used=0;
    for (int i=cur[now]; i; i=edge[i].next)
        if (edge[i].cap && h[edge[i].to]==h[now]+1) {
            int w=Dfs(edge[i].to,min(low-used,edge[i].cap));
            edge[i].cap-=w; edge[i^1].cap+=w; used+=w;
            if (used==low) return used;
            if (edge[i].cap) cur[now]=i;
        }
    if (!used) h[now]=-1;
    return used;
}
  
inline int Dinic()
{
    int re=0;
    while (Bfs()) {
        for (int i=1; i<=N; i++) cur[i]=head[i];
        re+=Dfs(S,INF);
    }
    return re;
}

int main(){
	int cas=read();
	while (cas--){
		N=read(),M=read(),S=read(),T=read(),K=read();
		cnt=1;
		for (int i=1; i<=N; i++) head[i]=0;
		
		for (int i=1; i<=M; i++){
			int u=read(),v=read();
			InsertEdge(u,v,1);
			InsertEdge(v,u,1);
		}	
		int ans=Dinic();
		int t;
		if (K%3==0) t=K/3;
		else t=K/3+1;
		printf("%lld\n",1LL*t*ans);
	}
	return 0;
}

/*
2
5 7 1 3 10
1 2
2 3
1 4
4 3
1 5
5 3
2 4
5 7 1 3 10
1 2
2 3
1 4
4 3
1 5
5 3
2 4
*/
	