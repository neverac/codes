#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define LL long long
#define INF 0x7fffffff
#define P 998244353

inline LL read(){
    LL x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int N,M,S,T;
#define MAXN 100010
    struct EdgeNode{
        int next,to,dis,from;
    }edge[MAXN<<1];
    int head[MAXN],cnt;
 
    inline void AddEdge(int u,int v,int w) {cnt++; edge[cnt].next=head[u]; head[u]=cnt; edge[cnt].to=v; edge[cnt].from=u; edge[cnt].dis=w;}
    inline void InsertEdge(int u,int v,int w) {AddEdge(u,v,w); AddEdge(v,u,w);}
 
    #define Pa pair<int,int>
    #define MP make_pair
    #define INF 0x7fffffff
    priority_queue<Pa,vector<Pa>,greater<Pa> >q;
    int dist[MAXN],dist1[MAXN];
    inline void Dijkstra(int s)
    {
        for (int i=1; i<=N; i++) dist[i]=INF;
        q.push(MP(0,s)); dist[s]=0;
        while (!q.empty()) {
            int dis=q.top().first;
            int now=q.top().second;
            q.pop();
            if (dis>dist[now]) continue;
            for (int i=head[now]; i;i=edge[i].next) {
                if (dist[edge[i].to]>dis+edge[i].dis) {
                    dist[edge[i].to]=dis+edge[i].dis;
                    q.push(MP(dist[edge[i].to],edge[i].to));
                }
            }
        }
    }
    inline void Dijkstra2(int s)
    {
        for (int i=1; i<=N; i++) dist1[i]=INF;
        q.push(MP(0,s)); dist1[s]=0;
        while (!q.empty()) {
            int dis=q.top().first;
            int now=q.top().second;
            q.pop();
            if (dis>dist1[now]) continue;
            for (int i=head[now]; i;i=edge[i].next) {
                if (dist1[edge[i].to]>dis+edge[i].dis) {
                    dist1[edge[i].to]=dis+edge[i].dis;
                    q.push(MP(dist1[edge[i].to],edge[i].to));
                }
            }
        }
    }

int mp[1010][1010];
int main(){
	N=read(),M=read(),S=read(),T=read();
	for (int i=1; i<=M; i++){
		int u=read(),v=read();
		InsertEdge(u,v,1);
		mp[u][v]=mp[v][u]=1;
	}
	Dijkstra(S);
	Dijkstra2(T);

	// for (int i=1; i<=N; i++) printf("%d ",dist[i]); puts("");
	// for (int i=1; i<=N; i++) printf("%d ",dist1[i]); puts("");

	int ans=0;
	for (int i=1; i<=N; i++){
		for (int j=i+1; j<=N; j++){
			if (mp[i][j]) continue;
			if (dist[i]+1+dist1[j]<dist[T] || dist[j]+1+dist1[i]<dist[T]) continue;
			// printf("%d %d\n",i,j);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}