#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL read(){
	LL x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int n,ans[100100],m;
#define MAXN 100100
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
    int dist[MAXN];
    inline void dijkstra(int S)
    {
        for (int i=1; i<=n; i++) dist[i]=INF;
        q.push(MP(0,S)); dist[S]=0;
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
        return;
}

int main(){
	while (1){
		scanf("%d",&n);
		if (!n) break;
		scanf("%d",&m);
		cnt=1;
		for (int i=1; i<=n; i++) head[i]=0;
		for (int i=1; i<=n; i++) ans[i]=0;
		
		for (int i=1; i<=m; i++){
			int u,v; scanf("%d%d",&u,&v); u++,v++;
			InsertEdge(u,v,1);	
		}
		
		for (int i=1; i<=n; i++){
			dijkstra(i);
			//printf("%d\n",i);
			for (int j=1; j<=n; j++){
				if (i==j) continue;
				ans[dist[j]]++;
			}
		}
		for (int i=1; i<=n; i++)
			if (ans[i]) printf("%d %d\n",i,ans[i]);
	}
	return 0;
}

/*
3
3
0 1
1 2
2 0
5
5
0 1
1 2
1 3
2 4
3 4
0
*/
	