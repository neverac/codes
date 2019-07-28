#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZEN = 10000;
const int INF = 0x3f3f3f3f;
int N,D;
struct Link{int to,next,w;}link[SIZEN<<1],link1[SIZEN << 1];
int head[SIZEN] = {0},tot = 1,head1[SIZEN] = {0},tot1 = 0;
int x[SIZEN],y[SIZEN];
int sum[30] = {0},now = 0;
int S = 0,T = 0;
int id[30][30] = {0},idpeop[10100] = {0},idday[10100] = {0};
void add(int from,int to,int w){
	link[++tot].to = to;
	link[tot].w = w;
	link[tot].next = head[from];
	head[from] = tot;
	
}

int dis[SIZEN] = {0};
bool BFS(){
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;q.push(S);dis[S] = 0;
    while(!q.empty()){
        int D = q.front();q.pop();
        for(int i = head[D];i;i=link[i].next){
                if(!link[i].w || dis[link[i].to]!=INF)continue;
                dis[link[i].to] = dis[D]+1;
                q.push(link[i].to);
        }
    }return dis[T]!=INF;
}
int cur[SIZEN] = {0};
int DFS(int x,int mid){
    if(x ==T || !mid)return mid;
    int ans = 0,xx;
    for(int &i = cur[x];i;i=link[i].next){
            if(!link[i].w || dis[link[i].to]!=dis[x]+1)continue;
            xx = DFS(link[i].to,min(mid,link[i].w));
            if(!xx)continue;
            link[i].w -= xx;link[i^1].w += xx;
            ans += xx;mid -= xx;
            if(!mid)break;
    }
	return ans;
}
int dinic(){
    int ret = 0;
    while(BFS()){
      	memcpy(cur,head,sizeof cur);
	    ret += DFS(S,INF);
    }
    return ret;
}
int tmp[SIZEN] = {0},cnt = 0;
int main(){
//	freopen("data.txt","w",stdout);
	while(scanf("%d",&N),N){
		memset(head,0,sizeof head);
		memset(sum,0,sizeof sum);
		now = 0;
		tot = 1;
		scanf("%d",&D);
		T = 0;
		S = 0;
		for(int i = 1;i <= D;i++)idday[i] = ++T;
		for(int i = 1;i <= D;i++){
			for(int j = i;j <= D;j++){
				id[i][j] = ++T;
				add(S,T,0);
				tmp[T] = tot;
				add(T,S,0);
				for(int k = i;k <= j;k++){
					add(id[i][j],idday[k],INF);
					add(idday[k],id[i][j],0);
				}
			}
		}
		T++;
		for(int i = idday[1];i <= idday[D];i++){
			add(i,T,0);
			tmp[i] = tot;
			add(T,i,0);
		}
		int ans = 0;
		for(int i = 1;i <= N;i++){
			scanf("%d%d",&x[i],&y[i]);
			link[ tmp[  id[ x[i] ] [ y[i] ] ]  ].w++;
			ans += dinic();
			if(ans < i){
				if(i != 1)printf(" %d",i);
				else printf("%d",i);
				for(int j = idday[1];j <= idday[D];j++)link[tmp[j]].w++;
			}
		}
		printf("\n");
	}
	return 0;
}
/*
3 3 
1 1
1 1 
1 1 
3 3 
1 2 
2 3 
1 1 
3 3 
1 2 
1 2 
1 2 
10 10
1 1
1 1
1 1
1 1
2 2
2 2
2 2
2 2
2 2
2 2
*/